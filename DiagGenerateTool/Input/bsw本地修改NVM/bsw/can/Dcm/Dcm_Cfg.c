/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2016. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
*  File Name         :  Dcm_Cfg.c                                            *
*  Module Short Name :  DiagMgr                                              *
*  VOBName           :                                                       *
*  Author            : msavariy                                              *
*  Description       : This file contains the Diagnostics request and        *
*                       response handling functionlities.                    *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  GHS                                                    *
* Target Hardware  :                                                         *
*                                                                            *
******************************************************************************/
#ifndef DCM_CFG_C_
#define DCM_CFG_C_

/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "Dcm.h"
#include "Dcm_Cfg.h"
//#include "DcmExt.c"
#include "Dcm_Dsp.h"
#include "SchM_Dcm.h"
#include "Dem_Dcm.h"
#include "Dcm_Cfg_Generate.h"

/*****************************************************************************
*                                 Type Declarations                          *
******************************************************************************/

/*****************************************************************************
*                                Globally  accessed Variable Declarations    *
*----------------------------------------------------------------------------*
* Declaration shall be followed by a comment that gives the following info.  *
* about the variable.                                                        *
* purpose, critical section, unit, and resolution                            *
******************************************************************************/

const Dcm_DsdSidTabServiceIdType Dcm_DsdSidTabServiceId[DcmNumOfSIDSupported+1] = 
{
   	DcmNumOfSIDSupported,
    0x10,	 /* DiagnosticSessionControl service 		*/
    0x11,	 /* EcuReset service 						*/
    0x22,	 /* ReadDataByIdentifier service 			*/
    0x2E,	 /* WriteDataByIdentifier service 			*/
    0x2F,	 /* InputOutputControlByIdentifier service 	*/
    0x31,	 /* RoutineControl service 					*/
    0x3E,	 /* TesterPresent service 					*/
	0x27,    /* SecurityAccess service 					*/
	0x28,	 /* Communication Control service 		  	*/
	0x14,    /* Clear DiagnosticInformation Service	  	*/
	0x19,	 /* Communication Control service 		  	*/
	0x85	 /* ReadDTCInformation Service  		  	*/
	#if(DCM_DEM_LOG_DTC_EXT != FALSE)
	,0x30   /*Log the DTC from CAN*/
	#endif
};
const Dcm_DsdSidTabServiceInfoType Dcm_DsdSidTabServiceInfo[DcmNumOfSIDSupported] =
{
/*DcmDsdSidTabFnc, Props, Length, State_Ref */
	{Dcm_10ServiceProcess ,0x03 ,0x02 ,0x00},
	{Dcm_11ServiceProcess ,0x03 ,0x02 ,0x00},
	{Dcm_22ServiceProcess ,0x00 ,0x03 ,0x00}, 
	{Dcm_2EServiceProcess ,0x00 ,0x03 ,0x01},
	{Dcm_2FServiceProcess ,0x00 ,0x04 ,0x01},
	{Dcm_31ServiceProcess ,0x01 ,0x04 ,0x05},
	{Dcm_3EServiceProcess ,0x03 ,0x02 ,0x00},
	{Dcm_27ServiceProcess ,0x01 ,0x02 ,0x07},
	{Dcm_28ServiceProcess ,0x03 ,0x03 ,0x08},
	{Dcm_14ServiceProcess ,0x02 ,0x04 ,0x00},
	{Dcm_19ServiceProcess ,0x03 ,0x02 ,0x00},
	{Dcm_85ServiceProcess ,0x03 ,0x02 ,0x0B}
	#if(DCM_DEM_LOG_DTC_EXT != FALSE)
	,{Dcm_30ServiceProcess ,0x00 ,0x00 ,0x00}   /*Log the DTC from CAN*/
	#endif
};


const Dcm_DsdStateRefType Dcm_DsdStateRef[DcmDsdNumOfStateRef] =
{
	/*
	{
		Session, 
		Security
	}
	*/
	{
		((1 << (EOL_SESSION - 1)) | (1 << (EXTENDED_SESSION - 1)) | (1 << (PROGRAMMING_SESSION - 1)) | (1 << (DEFAULT_SESSION - 1))), 
		((1 << DCM_SECURITY_LEVEL2) | (1 << DCM_SECURITY_LEVEL1) | (1 << DCM_SECURITY_LOCKED))
	},	/*for 10 service*//*0*/
	{
		((1 << (EOL_SESSION - 1)) | (1 << (EXTENDED_SESSION - 1)) | (1 << (PROGRAMMING_SESSION - 1)) | (1 << (DEFAULT_SESSION - 1))), 
		((1 << DCM_SECURITY_LEVEL2) | (1 << DCM_SECURITY_LEVEL1) | (1 << DCM_SECURITY_LOCKED))
	}, /*for 11 service*//*1*/
	{
		((1 << (EXTENDED_SESSION - 1)) | (1 << (PROGRAMMING_SESSION - 1)) | (1 << (DEFAULT_SESSION - 1))), 
		((1 << DCM_SECURITY_LEVEL2) | (1 << DCM_SECURITY_LEVEL1) | (1 << DCM_SECURITY_LOCKED))
	}, /*for 22 service*//*2*/
	{
		(1 << (EXTENDED_SESSION - 1)), 
		(1 << DCM_SECURITY_LEVEL1)
	}, /* for 2E*//*3*/
	{
		(1 << (EXTENDED_SESSION - 1)), 
		(1 << DCM_SECURITY_LEVEL1)
	}, /* for 2F service*//*4*/
	{
		((1 << (EOL_SESSION - 1)) | (1 << (EXTENDED_SESSION - 1))),  
		((1 << DCM_SECURITY_LEVEL2) | (1 << DCM_SECURITY_LEVEL1))
	}, /* for 31 service*//*5*/
	{
		((1 << (EOL_SESSION - 1)) | (1 << (EXTENDED_SESSION - 1)) | (1 << (PROGRAMMING_SESSION - 1)) | (1 << (DEFAULT_SESSION - 1))), 
		((1 << DCM_SECURITY_LEVEL2) | (1 << DCM_SECURITY_LEVEL1))
	}, /*for 3E service*//*6*/
	{
		((1 << (EOL_SESSION - 1)) | (1 << (EXTENDED_SESSION - 1))), 
		((1 << DCM_SECURITY_LEVEL2) | (1 << DCM_SECURITY_LEVEL1) | (1 << DCM_SECURITY_LOCKED))
	}, /* for 27 service*//*7*/
	{
		((1 << (EOL_SESSION - 1)) | (1 << (EXTENDED_SESSION - 1))),
		((1 << DCM_SECURITY_LEVEL2) | (1 << DCM_SECURITY_LEVEL1) | (1 << DCM_SECURITY_LOCKED))
	}, /* for 28 service*//*8*/
	{
		((1 << (EOL_SESSION - 1)) | (1 << (EXTENDED_SESSION - 1)) | (1 << (PROGRAMMING_SESSION - 1)) | (1 << (DEFAULT_SESSION - 1))), 
		((1 << DCM_SECURITY_LEVEL2) | (1 << DCM_SECURITY_LEVEL1) | (1 << DCM_SECURITY_LOCKED))
	},	/*for 14 service*//*9*/
	{
		((1 << (EOL_SESSION - 1)) | (1 << (EXTENDED_SESSION - 1)) | (1 << (PROGRAMMING_SESSION - 1)) | (1 << (DEFAULT_SESSION - 1))), 
		((1 << DCM_SECURITY_LEVEL2) | (1 << DCM_SECURITY_LEVEL1) | (1 << DCM_SECURITY_LOCKED))
	},	/*for 19 service*//*10*/
	{	
		((1 << (EOL_SESSION - 1)) | (1 << (EXTENDED_SESSION - 1))), 
		((1 << DCM_SECURITY_LEVEL2) | (1 << DCM_SECURITY_LEVEL1) | (1 << DCM_SECURITY_LOCKED))
	},/*for 85 service*//*11*/
	{
		0x02, 
		0x05
	},/* for FBL 27 service*//*12*/
	{
		((1 << (EOL_SESSION - 1)) | (1 << (EXTENDED_SESSION - 1))), 
		((1 << DCM_SECURITY_LEVEL2) | (1 << DCM_SECURITY_LEVEL1) | (1 << DCM_SECURITY_LOCKED))
	},/* for EOL 27 service*//*13*/
	{
		(1 << (EOL_SESSION - 1)), 
		((1 << DCM_SECURITY_LEVEL2) | (1 << DCM_SECURITY_LEVEL1) | (1 << DCM_SECURITY_LOCKED))
	},/* for EOL 22 Read DID*//*14*/
	{
		(1 << (EOL_SESSION - 1)), 
		(1 << DCM_SECURITY_LEVEL1)
	},/* for EOL 2E Write DID*//*15*/
	{
		(1 << (EOL_SESSION - 1)), 
		(1 << DCM_SECURITY_LEVEL1) 
	}/* for EOL 2F IO*//*16*/
};

const Dcm_DsdSubService10Type Dcm_DsdSubService10[NO_OF_SUPPORTTED_SESSIONS] =
{
	/*SubServiceFnc   		State_Ref	SubServiceId*/
	{Dcm_01DefaultProcess,	0x00, 		DEFAULT_SESSION},
	{Dcm_02PgmProcess,		0x00,		PROGRAMMING_SESSION},
	{Dcm_03ExtnDiagProcess, 0x00,		EXTENDED_SESSION},
	{Dcm_04EOLDiagProcess,  0x00, 		EOL_SESSION}
};

const Dcm_DsdSessionInfoType Dcm_DsdSessionInfo[NO_OF_SUPPORTTED_SESSIONS] =
{
/*P2, P2STAR, SESSION VALUE*/
    {50, 500, 0x01},
    {50, 500, 0x02},
    {50, 500, 0x03},
    {50, 500, 0x04}
};


const Dcm_DspDidIdentifierTableType Dcm_DspDidIdentifierTable[DcmNumOfDIDSupported+1] = 
{
	DcmNumOfDIDSupported,
	DCM_TABLE_SUPPORTED_DID
};

const Dcm_DspDidInfoType Dcm_DspDidInfo[DcmNumOfDIDSupported] = 
{
	/* Length, OpInfoRef, Operations */
	DCM_TABLE_DID_INFO
};

const Dcm_DspDidOpInfoType Dcm_DspDidOpInfo[DcmDspNumOfDidOpInfo] = 
{
	/* State_Ref, SignalInfo_Ref, CallTypes */
	DCM_TABLE_DID_OPERATION_INFO
};

const DcmDidConditionProcessFnc Dcm_DspDidConditionProcess[DcmNumOfDIDSupported] = 
{
	Dcm_FFFF_Read_NOConditionProcess                  , 	/* DID: 0xA1A1	 22       	PartNumberAlphaCode          */
	Dcm_FFFF_Read_NOConditionProcess                  , 	/* DID: 0xF1B1	 22       	SystemName                   */
};

const Dcm_DspDidSignalInfoType Dcm_DspDidSignalInfo[DcmDspNumOfDidSignalInfo] =
{
/*  OpFunc, FunClass;*/
    {0, 0x01}
};
const DidOpFuncType DidOpFunc[DidNumOfOpFunc] =
{
	DI_DID_DIAG_ACTION
};


const Dcm_DspRidIdentifierTableType Dcm_DspRidIdentifierTable[DcmNumOfRIDSupported+1] = 
{
	DcmNumOfRIDSupported,
	DCM_TABLE_SUPPORTED_RID
};
	
const Dcm_DspRidInfoType Dcm_DspRidInfo[DcmNumOfRIDSupported] = 
{
/* SignalInfo_Ref, State_Ref, Operation */
	DCM_TABLE_RID_INFO

};
	
const Dcm_DspRidSignalInfoType Dcm_DspRidSignalInfo[DcmDspNumOfRidSignalInfo] =
{
/* RidOpFunc_Ref, Req_Length, Resp_Length, OpType */
	DCM_TABLE_RID_SIGNAL_INFO
}; 

const RidOpFuncType RidOpFunc[RidNumOfOpFunc] =
{
	DI_RID_DIAG_ACTION
};
const Dcm_DsdSubService27Type Dcm_DsdSubService27[No_of_security_level*2] = 
{
/* SubServiceFnc, SubServiceId, Req_Length, Resp_Length, State_Ref */
	{SecLevel1GetSeed, 0x01, 1, 3, 7},
	{SecLevel1CmpKey,  0x02, 5, 1, 7},
	{SecLevel2GetSeed, 0x03, 1, 3, 7},
	{SecLevel2CmpKey,  0x04, 5, 1, 7}
};


const Dcm_SessionCommEnableInfo Dcm_SessionCommEnable[NO_OF_SUPPORTTED_SESSIONS] =
{
/* Sub function,Comm_support */
	{1, FALSE},
	{2, TRUE},
	{3, TRUE},
	{4, TRUE}
};

const Dcm_DsdSubService85Type Dcm_DsdSubService85[Svc85NumOfsubFunc] = 
{
{Dem_DcmEnableDTCSetting,1,0},
{Dem_DcmDisableDTCSetting,2,0}
};

const Dcm_DsdSubService19Type Dcm_DsdSubService19[Svc19NumOfsubFunc] = 
{
{Dcm_DspService19_01Processor,0x01,2,0},
{Dcm_DspService19_02Processor,0x02,2,0},
{Dcm_DspService19_04Processor,0x04,5,0},
{Dcm_DspService19_0AProcessor,0x0A,1,0}
};


void Dcm_EnterCriticalSection(void)
{
	
	/* Qiuhuaqing Modify,  To be Release after Os Finished */
	//SchM_Enter_Dcm_DCM_EXCLUSIVE_AREA_0();
}
void Dcm_ExitCriticalSection(void)
{
	/* Qiuhuaqing Modify,  To be Release after Os Finished */
	//SchM_Exit_Dcm_DCM_EXCLUSIVE_AREA_0();
}
#endif

/*****************************************************************************
*     End of File
*
*******************************************************************************/
/****************************************************************************
*   for each change to this file, be sure to record:                        *
*      1.  who made the change and when the change was made                 *
*      2.  why the change was made and the intended result                  *
*   Following block needs to be repeated for each change                    *
*****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 23-Jun-2016                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      :                                                       */
/*Change Description: Datadesign And Framework implemented, Initial Version */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 21-Sep-2016                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      :                                                       */
/*Change Description: service 10,11,22 implementation						*/
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 17-Oct-2016                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      :                                                       */
/*Change Description: service 2E,2F,31 implementation						*/
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 21-Oct-2016                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      :                                                       */
/*Change Description: service 3E,27 implementation						    */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 09-Dec-2016                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      :                                                       */
/*Change Description: Initial configuration for BAIC 					    */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 22-Nov-2016                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 746031,RTC 746018                                 */
/*Change Description: service 28 and 27 timing implementation				*/
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 20-Jan-2017                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 765864,765855,765852.                             */
/*Change Description: Service 0x14,0x85 and sercice 19 with subfunction 0x01*/
/*                    0x02 and 0x0A Implementation.                         */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 22-March-2017                                         */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : Rtc# 830120                                           */
/*Change Description: Service 27 request positive response at reset is 	    */
/*						changed from 10 second to 8 second                  */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 3-April-2017                                          */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 838240                                            */
/*Change Description: Fixed the compiler warnings.                          */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 3-April-2017                                          */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : RTC 833392                                            */
/*Change Description: Configuration (state reference) is updated as per     */
/*					  requirement for 5001,5002,5003,5007,F184 and F150     */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 13-May-2017                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : Rtc# 859867                                           */
/*Change Description: Issue fix for service ID not supportted in Functional */
/*						Addressing                                          */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 19-May-2017                                           */
/*Version           :                                                       */
/*By                : akalarim                                              */
/*Traceability      : Rtc#  866349                                          */
/*Change Description: PR defect fixes for 866349							*/
/*--------------------------------------------------------------------------*/
