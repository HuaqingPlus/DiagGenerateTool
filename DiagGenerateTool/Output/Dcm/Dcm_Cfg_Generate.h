/*********************************************************************/
/*                       DiagTool.Generate Start                     */
/*                       Generate Data: 2022-10-12 18:08:40          */
/*                       Author: QHQ                                 */
/*********************************************************************/

#ifndef __DCM_CFG_GENERATE_H__
#define __DCM_CFG_GENERATE_H__

//DcmGeneralConfig
#define DcmTesterResponseAddr       (2u)
#define DcmTesterSourcePhyAddr      (1u)
#define DcmTesterSourceFuncAddr     (0u)
#define DcmDslBufferSize            (4095u)


#define DcmNumOfDIDSupported		((uint8)2)
#define DcmDspNumOfDidOpInfo		((uint16)3)

//PID Define
#define PID_A1A1		((uint16)0xA1A1)
#define PID_B1B1		((uint16)0xB1B1)


#ifndef DCM_TABLE_SUPPORTED_DID
#define DCM_TABLE_SUPPORTED_DID \
	PID_A1A1, \
	PID_B1B1, \

#endif


#ifndef DCM_TABLE_DID_INFO
#define DCM_TABLE_DID_INFO \
	/*Length, OpInfoRef, Operations*/ \
	{   4,   0,  3}, /* DID: 0xA1A1 */ \
	{  20,   2,  4}, /* DID: 0xB1B1 */ \

#endif


#ifndef DCM_TABLE_DID_OPERATION_INFO
#define DCM_TABLE_DID_OPERATION_INFO \
	/* State_Ref, SignalInfo_Ref, CallTypes */ \
	{0x02, 0x00, 0x01}, /* DID: 0xA1A1 */ \
	{0x03, 0x00, 0x01}, /* DID: 0xA1A1 */ \
	{0x04, 0x00, 0x09}, /* DID: 0xB1B1 */ \

#endif


#define DcmNumOfRIDSupported		((uint8)1)
#define DcmDspNumOfRidSignalInfo		((uint16)1)

//RID Define
#define RID_F101		((uint16)0xF101)


#ifndef DCM_TABLE_SUPPORTED_RID
#define DCM_TABLE_SUPPORTED_RID \
	RID_F101, \

#endif


#ifndef DCM_TABLE_RID_INFO
#define DCM_TABLE_RID_INFO \
	/* SignalInfo_Ref, State_Ref, Operation */ \
	{0x0, 0x5, 0x0F}, /* RID: 0xF101 */ \

#endif


#ifndef DCM_TABLE_RID_SIGNAL_INFO
#define DCM_TABLE_RID_SIGNAL_INFO \
	/* RidOpFunc_Ref, Req_Length, Resp_Length, OpType */ \
	{0x0, 0x1, 0x0F, 0x0F}, /* RID: 0xF101 */ \

#endif




#endif
/*********************************************************************/
/*                       DiagTool.Generate End                       */
/*                       Author: QHQ                                 */
/*********************************************************************/
