/*********************************************************************/
/*                       DiagTool.Generate Start                     */
/*********************************************************************/

#ifndef __DEM_CFG_GENERATE_H__
#define __DEM_CFG_GENERATE_H__

#include "Std_Types.h"
#include "Dem_Cfg_Types.h"
#include "NvM_Cfg_Generate.h"


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


//OpCycle Table
#define Dem_Cfg_Num_Of_OpCycle		((uint8)4)

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
	{ /* 1 */127, -128, 0, 0, -1, 1, 0, 0, DEM_CFG_DEBOUNCETYPE_COUNTER, 1, 1, DEM_DEBOUNCE_RESET},\
	{ /* 2 */0, 0, 0, 0, 0, 0, 0, 0, DEM_CFG_DEBOUNCETYPE_INVALID, 0, 0, DEM_DEBOUNCE_RESET},\

#endif


//DTC Value
#define Dem_Cfg_Num_Of_Event		((uint8)10)
#define Dem_Cfg_Num_Of_DTC			(Dem_Cfg_Num_Of_Event)

#define Dem_Cfg_Mem_Total_Primary_Entry (Dem_Cfg_Num_Of_DTC)
#define Dem_Cfg_Mem_Primary_Entry_Stop  (Dem_Cfg_Mem_Total_Primary_Entry + 2)
#define Dem_Cfg_Mem_Total_Entry      	(Dem_Cfg_Mem_Total_Primary_Entry + 2)

#ifndef DEM_TABLE_DTC
#define DEM_TABLE_DTC \
	/*Index  Dtc Value, DTC Attribute Ref*/\
	{ /* 0 */0xFFFFFF, 0},\
	{ /* 1 */0x000000, 1},\
	{ /* 2 */0x000000, 2},\
	{ /* 3 */0xC14087, 3},\
	{ /* 4 */0xD10017, 4},\
	{ /* 5 */0xD10116, 5},\
	{ /* 6 */0xC07388, 6},\
	{ /* 7 */0x900A98, 7},\
	{ /* 8 */0x900A81, 8},\
	{ /* 9 */0x900A96, 9},\

#endif


//Index of Event 
#define INDEX_DTC_EVENT_FFFFFF		(0x0)
#define INDEX_DTC_EVENT_000000		(0x1)
#define INDEX_DTC_EVENT_000000		(0x2)
#define INDEX_DTC_EVENT_C14087		(0x3)
#define INDEX_DTC_EVENT_D10017		(0x4)
#define INDEX_DTC_EVENT_D10116		(0x5)
#define INDEX_DTC_EVENT_C07388		(0x6)
#define INDEX_DTC_EVENT_900A98		(0x7)
#define INDEX_DTC_EVENT_900A81		(0x8)
#define INDEX_DTC_EVENT_900A96		(0x9)

//DTC Attributes Table
#ifndef DEM_TABLE_DTC_ATTRIBUTES
#define DEM_TABLE_DTC_ATTRIBUTES \
	/*Index, AgingThershold, AgingOpCycleRef, ImmediateNvStorageAllowed, AgingAllowed*/\
	{ /* 0 */255, 4, FALSE, FALSE},\
	{ /* 1 */40, 0, TRUE, TRUE},\
	{ /* 2 */40, 0, TRUE, TRUE},\
	{ /* 3 */40, 0, TRUE, TRUE},\
	{ /* 4 */40, 3, TRUE, TRUE},\
	{ /* 5 */40, 3, TRUE, TRUE},\
	{ /* 6 */40, 3, TRUE, TRUE},\
	{ /* 7 */40, 3, TRUE, TRUE},\
	{ /* 8 */40, 3, TRUE, TRUE},\
	{ /* 9 */40, 3, TRUE, TRUE},\

#endif


//Event Table
#ifndef DEM_TABLE_EVENT_PARAMETERS
#define DEM_TABLE_EVENT_PARAMETERS \
	/* Index CB_InitMForE, Event ID, EventKind, FDCThershold, Debounce TabRef, OpCycleRef, DTC TabRef, EnCntRef, StrCntRef, Available Status  */\
	{ /* 0 */((void *) 0), 0, DEM_EVENT_KIND_BSW, 255, 255, 4, 0, 0, 0, FALSE},\
	{ /* 1 */((void *) 0), 1, DEM_EVENT_KIND_BSW, 255, 255, 2, 1, 0, 0, TRUE},\
	{ /* 2 */((void *) 0), 2, DEM_EVENT_KIND_SWC, 255, 255, 2, 2, 0, 0, TRUE},\
	{ /* 3 */((void *) 0), 3, DEM_EVENT_KIND_BSW, 255, 1, 3, 3, 0, 0, TRUE},\
	{ /* 4 */((void *) 0), 4, DEM_EVENT_KIND_BSW, 255, 0, 3, 4, 0, 0, TRUE},\
	{ /* 5 */((void *) 0), 5, DEM_EVENT_KIND_BSW, 255, 0, 3, 5, 0, 0, TRUE},\
	{ /* 6 */((void *) 0), 6, DEM_EVENT_KIND_BSW, 255, 0, 3, 6, 0, 0, TRUE},\
	{ /* 7 */((void *) 0), 7, DEM_EVENT_KIND_BSW, 255, 0, 3, 7, 0, 0, TRUE},\
	{ /* 8 */((void *) 0), 8, DEM_EVENT_KIND_BSW, 255, 0, 3, 8, 0, 0, TRUE},\
	{ /* 9 */((void *) 0), 9, DEM_EVENT_KIND_BSW, 255, 0, 3, 9, 0, 0, TRUE},\

#endif


//Type Define
typedef struct
{
	uint16 FirstFailedEvent;
	uint16 FirstConfirmedEvent;
	uint16 RecentFailedEvent;
	uint16 RecentConfirmedEvent;
	uint8 EventStatus[Dem_Cfg_Mem_Total_Entry];
} Dem_Cfg_UdsStatusDataType;

typedef struct
{
	uint16 Counter[Dem_Cfg_Num_Of_OpCycle];
	uint8 MagicFlag;
} Dem_Cfg_OpCycleType;


extern const Dem_Cfg_PrimaryMemEntryType Dem_MemoryEntryInit;
extern const Dem_Cfg_OpCycleType DemCfg_OpCycle_Default;
extern const Dem_Cfg_AdminDataType DemCfg_AdminData_Default;
extern const Dem_Cfg_UdsStatusDataType DemCfg_StatusData_Default;

//Dem Primary Table
extern Dem_Cfg_OpCycleType Dem_Cfg_OpCycle;
extern Dem_Cfg_AdminDataType Dem_Cfg_AdminData;
extern Dem_Cfg_UdsStatusDataType Dem_Cfg_StatusData;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_000;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_001;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_002;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_003;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_004;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_005;
extern Dem_Cfg_PrimaryMemEntryType Dem_PrimaryEntry_006;

//Dem NvmBlock RamData Table
extern const uint8* Dem_Cfg_MemPtr[Dem_Cfg_Mem_Total_Entry];


//Dem NvmBlock_Id Table
extern const Dem_Cfg_NvRamBlockIdType Dem_Cfg_Memory_BlockId[Dem_Cfg_Mem_Total_Entry];



#endif
/*********************************************************************/
/*                       DiagTool.Generate Stop                      */
/*********************************************************************/

