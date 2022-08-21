#ifndef __FEE_CFG_GENERATE_H__
#define __FEE_CFG_GENERATE_H__

#include "Std_Types.h"

#define FEE_NUM_BLOCKS          11
#define FEE_NUM_PARTITIONS      1
#define FEE_MAX_LENGTH          48    /* Remainding Byte */
#define FEE_SECTOR_SIZE         2048  /* 2k */
#define FEE_SECTOR_HEADER_SIZE  8     /* Page size */
#define FEE_SECTOR_FOOTER_SIZE  8     /* Page size */
#define FEE_HEADER_SIZE         8     /* Page size */


#ifndef FeeCfg_BlockConfig_Table
#define FeeCfg_BlockConfig_Table \
  {\
    0,            /*   uint16 BlockNumber;    */ \
    0,            /*   uint16 BlockSize;      */ \
    0,            /*   uint8  PartitionNo;    */ \
    0             /*   boolean ImmediateData; */ \
  },\
  {\
    1,            /*   uint16 BlockNumber;    */ \
    8,            /*   uint16 BlockSize;      */ \
    0,            /*   uint8  PartitionNo;    */ \
    0             /*   boolean ImmediateData; */ \
  },\
  {\
    2,            /*   uint16 BlockNumber;    */ \
    8,            /*   uint16 BlockSize;      */ \
    0,            /*   uint8  PartitionNo;    */ \
    0             /*   boolean ImmediateData; */ \
  },\
  {\
    3,            /*   uint16 BlockNumber;    */ \
    24,           /*   uint16 BlockSize;      */ \
    0,            /*   uint8  PartitionNo;    */ \
    0             /*   boolean ImmediateData; */ \
  },\
  {\
    4,            /*   uint16 BlockNumber;    */ \
    24,           /*   uint16 BlockSize;      */ \
    0,            /*   uint8  PartitionNo;    */ \
    0             /*   boolean ImmediateData; */ \
  },\
  {\
    5,            /*   uint16 BlockNumber;    */ \
    24,           /*   uint16 BlockSize;      */ \
    0,            /*   uint8  PartitionNo;    */ \
    0             /*   boolean ImmediateData; */ \
  },\
  {\
    6,            /*   uint16 BlockNumber;    */ \
    24,           /*   uint16 BlockSize;      */ \
    0,            /*   uint8  PartitionNo;    */ \
    0             /*   boolean ImmediateData; */ \
  },\
  {\
    7,            /*   uint16 BlockNumber;    */ \
    24,           /*   uint16 BlockSize;      */ \
    0,            /*   uint8  PartitionNo;    */ \
    0             /*   boolean ImmediateData; */ \
  },\
  {\
    8,            /*   uint16 BlockNumber;    */ \
    24,           /*   uint16 BlockSize;      */ \
    0,            /*   uint8  PartitionNo;    */ \
    0             /*   boolean ImmediateData; */ \
  },\
  {\
    9,            /*   uint16 BlockNumber;    */ \
    200,          /*   uint16 BlockSize;      */ \
    0,            /*   uint8  PartitionNo;    */ \
    0             /*   boolean ImmediateData; */ \
  },\
  {\
    10,           /*   uint16 BlockNumber;    */ \
    8,            /*   uint16 BlockSize;      */ \
    0,            /*   uint8  PartitionNo;    */ \
    0             /*   boolean ImmediateData; */ \
  },\

#endif


#endif
