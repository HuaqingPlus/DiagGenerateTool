/*********************************************************************/
/*                       DiagTool.Generate Start                     */
/*                       Generate Data: 2022-10-12 18:08:40          */
/*                       Author: QHQ                                 */
/*********************************************************************/

#ifndef __FEE_CFG_GENERATE_H__
#define __FEE_CFG_GENERATE_H__

#include "Std_Types.h"
#include "Dem_Cfg_Generate.h"

//FEE Config
#define FEE_NUM_BLOCKS                 ((uint8)8)
#define FEE_NUM_PARTITIONS             (1u)     
#define FEE_MAX_LENGTH                 (216u)   /* Max Block length: Max length of NvmBlock + 2 * PageSize */
#define FEE_SECTOR_NUMBER              (30u)    /* Sector' number */
#define FEE_SECTOR_SIZE                (2048u)  /* Sector Size, unit: Byte */
#define FEE_SECTOR_HEADER_SIZE         (8u)     /* should be same size as PageSize */
#define FEE_SECTOR_FOOTER_SIZE         (8u)     /* should be same size as PageSize */
#define FEE_HEADER_SIZE                (8u)     /* should be same size as PageSize */

//Fee Block Config
#ifndef FeeCfg_BlockConfig_Table
#define FeeCfg_BlockConfig_Table \
	{\
		0,        /*   uint16 BlockNumber;    */ \
		0,        /*   uint16 BlockSize;      */ \
		0,        /*   uint8  PartitionNo;    */ \
		0,        /*   boolean ImmediateData; */ \
	},\
	{\
		1,        /*   uint16 BlockNumber;    */ \
		0,        /*   uint16 BlockSize;      */ \
		0,        /*   uint8  PartitionNo;    */ \
		0,        /*   boolean ImmediateData; */ \
	},\
	{\
		2,        /*   uint16 BlockNumber;    */ \
		sizeof(Dem_Cfg_OpCycleType),/*   uint16 BlockSize;      */ \
		0,        /*   uint8  PartitionNo;    */ \
		0,        /*   boolean ImmediateData; */ \
	},\
	{\
		3,        /*   uint16 BlockNumber;    */ \
		sizeof(Dem_Cfg_AdminDataType),/*   uint16 BlockSize;      */ \
		0,        /*   uint8  PartitionNo;    */ \
		0,        /*   boolean ImmediateData; */ \
	},\
	{\
		4,        /*   uint16 BlockNumber;    */ \
		sizeof(Dem_Cfg_UdsStatusDataType),/*   uint16 BlockSize;      */ \
		0,        /*   uint8  PartitionNo;    */ \
		0,        /*   boolean ImmediateData; */ \
	},\
	{\
		5,        /*   uint16 BlockNumber;    */ \
		sizeof(Dem_Cfg_PrimaryMemEntryType),/*   uint16 BlockSize;      */ \
		0,        /*   uint8  PartitionNo;    */ \
		0,        /*   boolean ImmediateData; */ \
	},\
	{\
		6,        /*   uint16 BlockNumber;    */ \
		8,        /*   uint16 BlockSize;      */ \
		0,        /*   uint8  PartitionNo;    */ \
		0,        /*   boolean ImmediateData; */ \
	},\
	{\
		7,        /*   uint16 BlockNumber;    */ \
		sizeof(Dem_Cfg_PrimaryMemEntryType),/*   uint16 BlockSize;      */ \
		0,        /*   uint8  PartitionNo;    */ \
		0,        /*   boolean ImmediateData; */ \
	},\

#endif


#endif
/*********************************************************************/
/*                       DiagTool.Generate End                       */
/*                       Author: QHQ                                 */
/*********************************************************************/
