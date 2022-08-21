/*********************************************************************/
/*                       DiagTool.Generate Start                     */
/*********************************************************************/

#ifndef __DCM_CFG_GENERATE_H__
#define __DCM_CFG_GENERATE_H__

#define DcmNumOfDIDSupported   ((uint8)2)
#define DcmNumOfRIDSupported   ((uint8)6)

/* PID Define */
#define Pid_A1A1		((uint16)0xA1A1)
#define Pid_F1B1		((uint16)0xF1B1)             

#ifndef DCM_TABLE_SUPPORTED_DID
#define DCM_TABLE_SUPPORTED_DID \
/* User Define */       Pid_A1A1, 	   \
/* User Define */	    Pid_F1B1,  
#endif

#ifndef DCM_TABLE_DID_INFO
#define DCM_TABLE_DID_INFO \
{10  ,0,  3},\
{1   ,2,  4},
#endif

#ifndef DCM_TABLE_DID_OPERATION_INFO
#define DCM_TABLE_DID_OPERATION_INFO \
{0x02 ,0x00 ,0x01 },\
{0x03 ,0x00 ,0x01 },\
{0x04 ,0x00 ,0x09 },
#endif


// #ifndef DCM_TABLE_SUPPORTED_RID
// #define DCM_TABLE_SUPPORTED_RID \
// /* User Define */   0x0202,\
// /* User Define */   0x0203,\
// /* User Define */   0xFF01,\
// /* User Define */   0xF103,\
// /* User Define */   0xF104,\
// /* User Define */   0xF11E
// #endif

// #ifndef DCM_TABLE_RID_INFO
// #define DCM_TABLE_RID_INFO \
// {0x0, 0x5, 0x0F},\
// {0x1, 0x5, 0x0F},\
// {0x2, 0x5, 0x0F},\
// {0x3, 0x5, 0x0F},\
// {0x4, 0x5, 0x0F},\
// {0x5, 0x5, 0x0F}
// #endif

// #ifndef DCM_TABLE_RID_SIGNAL_INFO
// #define DCM_TABLE_RID_SIGNAL_INFO \
// { 0, 0x0, 0xF, 0x0F},\
// { 0, 0x0, 0xF, 0x0F},\
// { 0, 0x0, 0xF, 0x0F},\
// { 0, 0x0, 0xF, 0x0F},\
// { 0, 0x0, 0xF, 0x0F},\
// { 0, 0x1, 0xF, 0x0F} 
// #endif


/*********************************************************************/
/*                       DiagTool.Generate Stop                      */
/*********************************************************************/

#endif
