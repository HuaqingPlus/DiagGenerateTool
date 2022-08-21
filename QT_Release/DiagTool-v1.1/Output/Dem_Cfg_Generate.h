/*********************************************************************/
/*                       DiagTool.Generate Start                     */
/*********************************************************************/

#ifndef __DEM_CFG_GENERATE_H__
#define __DEM_CFG_GENERATE_H__

#include "Std_Types.h"


//Dem Event Kind
#define DEM_EVENT_KIND_BSW		 ((uint8)0)
#define DEM_EVENT_KIND_SWC		 ((uint8)1)

//Dem Debounce class
#define DEM_CFG_DEBOUNCETYPE_COUNTER		((uint8)0)
#define DEM_CFG_DEBOUNCETYPE_TIMER		((uint8)1)
#define DEM_CFG_DEBOUNCETYPE_EXTERNAL		((uint8)2)
#define DEM_CFG_DEBOUNCETYPE_INVALID		((uint8)3)

#define DEM_DEBOUNCE_FREEZE		((uint8)0)
#define DEM_DEBOUNCE_RESET		((uint8)1)

//Dem Operation Cycle ID's
#define DemOpCycle_Ignition		((uint8)0)
#define DemOpCycle_Profile2		((uint8)1)
#define DemOpCycle_Profile3		((uint8)2)
#define DemOpCycle_Profile4		((uint8)3)


//OpCYcle Table
#define Dem_Cfg_Num_Of_OpCycle		((uint8)         4)

#ifndef DEM_TABLE_OPCYCLE
#define DEM_TABLE_OPCYCLE \
	/*Index, Id, Type, AutoStart, AutoStop*/\
	{ /* 0 */DemOpCycle_Ignition, 0, 0, 0 },\
	{ /* 1 */DemOpCycle_Profile2, 0, 0, 0},\
	{ /* 2 */DemOpCycle_Profile3, 0, 0, 0},\
	{ /* 3 */DemOpCycle_Profile4, 0, 1, 1},\

#endif


//Debounce Table
#define Dem_Cfg_Num_Of_DebounceTable		((uint8)3)

#ifndef DEM_TABLE_DEBOUNCE
#define DEM_TABLE_DEBOUNCE \
	/*Index, F.Td, P.Td, FT.Td, PT.Td, Dec-Stp, Inc-Stp, JmpUpVal, JmpDwnVal, Algo, JmpUp, Jmpdwn, Behavior*/ \
	{ /* 0 */0, 0, 100, 100, 0, 0, 0, 0, DEM_CFG_DEBOUNCETYPE_TIMER, 0, 0, DEM_DEBOUNCE_RESET},\
	{ /* 1 */127, -128, 0, 0, -1, 1, 0, 0, DEM_CFG_DEBOUNCETYPE_COUNTER, 0, 0, DEM_DEBOUNCE_RESET},\
	{ /* 2 */0, 0, 0, 0, 0, 0, 0, 0, DEM_CFG_DEBOUNCETYPE_INVALID, 0, 0, DEM_DEBOUNCE_RESET},\

#endif


//DTC Value
#define Dem_Cfg_Num_Of_DTC		((uint8)3)

#ifndef DEM_TABLE_DTC
#define DEM_TABLE_DTC \
	/*Index  Dtc Value, DTC Attribute Ref*/\
	{ /* 0 */0xFFFFFF, 0},\
	{ /* 1 */0x000000, 1},\
	{ /* 2 */0x000000, 2},\
	{ /* 3 */0xF00316, 3},\

#endif


//DTC Attributes Table
#ifndef DEM_TABLE_DTC_ATTRIBUTES
#define DEM_TABLE_DTC_ATTRIBUTES \
	/*Index, AgingThershold, AgingOpCycleRef, ImmediateNvStorageAllowed, AgingAllowed*/\
	{ /* 0 */255, 4, FALSE, FALSE},\
	{ /* 1 */40, 0, TRUE, TRUE},\
	{ /* 2 */40, 0, TRUE, TRUE},\
	{ /* 3 */40, 0, TRUE, TRUE},\

#endif


//Event Table
#define Dem_Cfg_Num_Of_Event		((uint8)3)

#ifndef DEM_TABLE_EVENT_PARAMETERS
#define DEM_TABLE_EVENT_PARAMETERS \
	/* Index CB_InitMForE, Event ID, EventKind, FDCThershold, Debounce TabRef, OpCycleRef, DTC TabRef, EnCntRef, StrCntRef, Available Status  */\
	{ /* 0 */((void *) 0), 0, DEM_EVENT_KIND_BSW, 255, 255, 4, 0, 0, 0, FALSE},\
	{ /* 1 */((void *) 0), 1, DEM_EVENT_KIND_BSW, 255, 255, 2, 1, 0, 0, TRUE},\
	{ /* 2 */((void *) 0), 2, DEM_EVENT_KIND_SWC, 255, 255, 2, 2, 0, 0, TRUE},\
	{ /* 3 */((void *) 0), 3, DEM_EVENT_KIND_BSW, 255, 0, 3, 3, 0, 0, TRUE},\

#endif



#endif
/*********************************************************************/
/*                       DiagTool.Generate Stop                      */
/*********************************************************************/

