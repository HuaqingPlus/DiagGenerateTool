/*********************************************************************/
/*                       DiagTool.Generate Start                     */
/*********************************************************************/

#ifndef __DCM_CFG_GENERATE_H__
#define __DCM_CFG_GENERATE_H__

//DcmGeneralConfig
#define DcmTesterResponseAddr		(1u)
#define DcmTesterSourcePhyAddr		(1u)
#define DcmTesterSourceFuncAddr		(0u)
#define DcmDslBufferSize		(4095u)


#define DcmNumOfDIDSupported		((uint8)16)
#define DcmDspNumOfDidOpInfo		((uint16)27)

//PID Define
#define PID_A1A1		((uint16)0xA1A1)
#define PID_F190		((uint16)0xF190)
#define PID_F193		((uint16)0xF193)
#define PID_F195		((uint16)0xF195)
#define PID_F1B1		((uint16)0xF1B1)
#define PID_F187		((uint16)0xF187)
#define PID_F18A		((uint16)0xF18A)
#define PID_F18C		((uint16)0xF18C)
#define PID_F1A2		((uint16)0xF1A2)
#define PID_F1B5		((uint16)0xF1B5)
#define PID_F189		((uint16)0xF189)
#define PID_F1C0		((uint16)0xF1C0)
#define PID_F1C1		((uint16)0xF1C1)
#define PID_F299		((uint16)0xF299)
#define PID_F298		((uint16)0xF298)
#define PID_F297		((uint16)0xF297)


#ifndef DCM_TABLE_SUPPORTED_DID
#define DCM_TABLE_SUPPORTED_DID \
	PID_A1A1, \
	PID_F190, \
	PID_F193, \
	PID_F195, \
	PID_F1B1, \
	PID_F187, \
	PID_F18A, \
	PID_F18C, \
	PID_F1A2, \
	PID_F1B5, \
	PID_F189, \
	PID_F1C0, \
	PID_F1C1, \
	PID_F299, \
	PID_F298, \
	PID_F297, \

#endif


#ifndef DCM_TABLE_DID_INFO
#define DCM_TABLE_DID_INFO \
{ 0,  2,  7}, \
{11,  5,  7}, \
{ 0,  6,  3}, \
{ 4,  8,  1}, \
{ 0,  9,  3}, \
{ 0, 11,  1}, \
{ 8, 12,  1}, \
{14, 13,  3}, \
{13, 15,  1}, \
{ 4, 16,  1}, \
{ 0, 17,  1}, \
{ 0, 18,  1}, \
{ 0, 19,  1}, \
{ 4, 20,  3}, \
{10, 22,  3}, \
{ 2, 26,  7}, \

#endif


#ifndef DCM_TABLE_DID_OPERATION_INFO
#define DCM_TABLE_DID_OPERATION_INFO \
{0x0e, 0x00, 0x01}, \
{0x0f, 0x00, 0x01}, \
{0x10, 0x00, 0x09}, \
{0x0e, 0x00, 0x01}, \
{0x0f, 0x00, 0x01}, \
{0x10, 0x00, 0x09}, \
{0x02, 0x00, 0x01}, \
{0x03, 0x00, 0x01}, \
{0x02, 0x00, 0x01}, \
{0x02, 0x00, 0x01}, \
{0x03, 0x00, 0x01}, \
{0x02, 0x00, 0x01}, \
{0x02, 0x00, 0x01}, \
{0x02, 0x00, 0x01}, \
{0x03, 0x00, 0x01}, \
{0x02, 0x00, 0x01}, \
{0x02, 0x00, 0x01}, \
{0x02, 0x00, 0x01}, \
{0x02, 0x00, 0x01}, \
{0x02, 0x00, 0x01}, \
{0x02, 0x00, 0x01}, \
{0x03, 0x00, 0x01}, \
{0x02, 0x00, 0x01}, \
{0x03, 0x00, 0x01}, \
{0x0e, 0x00, 0x01}, \
{0x0f, 0x00, 0x01}, \
{0x10, 0x00, 0x09}, \

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
{0x0, 0x5, 0x15}, \
{0x1, 0x5, 0x15}, \
{0x2, 0x5, 0x15}, \
{0x3, 0x5, 0x15}, \
{0x4, 0x5, 0x15}, \
{0x5, 0x5, 0x15}, \

#endif


#ifndef DCM_TABLE_RID_SIGNAL_INFO
#define DCM_TABLE_RID_SIGNAL_INFO \
{0x0, 0x0, 0x15, 0x15}, \
{0x0, 0x0, 0x15, 0x15}, \
{0x0, 0x0, 0x15, 0x15}, \
{0x0, 0x0, 0x15, 0x15}, \
{0x0, 0x0, 0x15, 0x15}, \
{0x0, 0x1, 0x15, 0x15}, \

#endif



#endif
/*********************************************************************/
/*                       DiagTool.Generate Stop                      */
/*********************************************************************/

