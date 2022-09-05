/*********************************************************************/
/*                       DiagTool.Generate Start                     */
/*********************************************************************/

#ifndef __DCM_CFG_GENERATE_H__
#define __DCM_CFG_GENERATE_H__

//DcmGeneralConfig
#define DcmTesterResponseAddr		(2u)
#define DcmTesterSourcePhyAddr		(1u)
#define DcmTesterSourceFuncAddr		(0u)
#define DcmDslBufferSize		(4095u)


#define DcmNumOfDIDSupported		((uint8)4)
#define DcmDspNumOfDidOpInfo		((uint16)5)

//PID Define
#define PID_A1A1		((uint16)0xA1A1)
#define PID_F1B1		((uint16)0xF1B1)
#define PID_F193		((uint16)0xF193)
#define PID_F195		((uint16)0xF195)


#ifndef DCM_TABLE_SUPPORTED_DID
#define DCM_TABLE_SUPPORTED_DID \
	PID_A1A1, \
	PID_F1B1, \
	PID_F193, \
	PID_F195, \

#endif


#ifndef DCM_TABLE_DID_INFO
#define DCM_TABLE_DID_INFO \
{10,  0,  3}, \
{ 1,  2,  4}, \
{ 4,  3,  1}, \
{ 4,  4,  1}, \

#endif


#ifndef DCM_TABLE_DID_OPERATION_INFO
#define DCM_TABLE_DID_OPERATION_INFO \
{0x02, 0x00, 0x01}, \
{0x03, 0x00, 0x01}, \
{0x04, 0x00, 0x09}, \
{0x02, 0x00, 0x01}, \
{0x02, 0x00, 0x01}, \

#endif


#define DcmNumOfRIDSupported		((uint8)6)
#define DcmDspNumOfRidSignalInfo		((uint16)6)

//RID Define
#define RID_0202		((uint16)0x0202)
#define RID_0203		((uint16)0x0203)
#define RID_FF01		((uint16)0xFF01)
#define RID_F103		((uint16)0xF103)
#define RID_F104		((uint16)0xF104)
#define RID_F11E		((uint16)0xF11E)


#ifndef DCM_TABLE_SUPPORTED_RID
#define DCM_TABLE_SUPPORTED_RID \
	RID_0202, \
	RID_0203, \
	RID_FF01, \
	RID_F103, \
	RID_F104, \
	RID_F11E, \

#endif


#ifndef DCM_TABLE_RID_INFO
#define DCM_TABLE_RID_INFO \
{0x0, 0x5, 0x0F}, \
{0x1, 0x5, 0x0F}, \
{0x2, 0x5, 0x0F}, \
{0x3, 0x5, 0x0F}, \
{0x4, 0x5, 0x0F}, \
{0x5, 0x5, 0x0F}, \

#endif


#ifndef DCM_TABLE_RID_SIGNAL_INFO
#define DCM_TABLE_RID_SIGNAL_INFO \
{0x0, 0x0, 0x0F, 0x0F}, \
{0x0, 0x0, 0x0F, 0x0F}, \
{0x0, 0x0, 0x0F, 0x0F}, \
{0x0, 0x0, 0x0F, 0x0F}, \
{0x0, 0x0, 0x0F, 0x0F}, \
{0x0, 0x1, 0x0F, 0x0F}, \

#endif



#endif
/*********************************************************************/
/*                       DiagTool.Generate Stop                      */
/*********************************************************************/

