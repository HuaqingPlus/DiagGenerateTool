#ifndef SLP_CFG_H
#define SLP_CFG_H

/*****************************************************************
| Type declare
|----------------------------------------------------------------*/
typedef struct {
	IoHwAb_LabelType stPin;
	IoHwAb_StdType stActiveLv;
	void (*WakeupFn) (void);
}SLP_WakeConfigType;


extern const SLP_WakeConfigType SLP_stStandbyWakeupSource[3];
#define SLP_MAX_STANDBYWAKEUPSRC	(sizeof(SLP_stStandbyWakeupSource)/sizeof(SLP_WakeConfigType))

extern const SLP_WakeConfigType SLP_stSleepWakeupSource[2];
#define SLP_MAX_SLEEPWAKEUPSRC	(sizeof(SLP_stSleepWakeupSource)/sizeof(SLP_WakeConfigType))

#endif
