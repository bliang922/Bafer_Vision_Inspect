#pragma once
#include <stddef.h>
#define GT_API extern "C" short __stdcall

#define DLL_VERSION_0                   2
#define DLL_VERSION_1                   1
#define DLL_VERSION_2                   0

#define DLL_VERSION_3                   1
#define DLL_VERSION_4                   5
#define DLL_VERSION_5                   0
#define DLL_VERSION_6                   6
#define DLL_VERSION_7                   0
#define DLL_VERSION_8                   7

#define MC_NONE                         -1

#define MC_LIMIT_POSITIVE               0
#define MC_LIMIT_NEGATIVE               1
#define MC_ALARM                        2
#define MC_HOME                         3
#define MC_GPI                          4
#define MC_ARRIVE                       5
#define MC_MPG                          6

#define MC_ENABLE                       10
#define MC_CLEAR                        11
#define MC_GPO                          12

#define MC_DAC                          20
#define MC_STEP                         21
#define MC_PULSE                        22
#define MC_ENCODER                      23
#define MC_ADC                          24

#define MC_AXIS                         30
#define MC_PROFILE                      31
#define MC_CONTROL                      32

#define MC_SMART_CUTTER                 400

#define CAPTURE_HOME                    1
#define CAPTURE_INDEX                   2
#define CAPTURE_PROBE                   3
#define CAPTURE_HSIO0                   6
#define CAPTURE_HSIO1                   7
#define CAPTURE_HOME_GPI                8

#define PT_MODE_STATIC                  0
#define PT_MODE_DYNAMIC                 1

#define PT_SEGMENT_NORMAL               0
#define PT_SEGMENT_EVEN                 1
#define PT_SEGMENT_STOP                 2

#define GEAR_MASTER_ENCODER             1
#define GEAR_MASTER_PROFILE             2
#define GEAR_MASTER_AXIS                3

#define FOLLOW_MASTER_ENCODER           1
#define FOLLOW_MASTER_PROFILE           2
#define FOLLOW_MASTER_AXIS              3

#define FOLLOW_EVENT_START              1
#define FOLLOW_EVENT_PASS               2

#define GEAR_EVENT_START                1
#define GEAR_EVENT_PASS                 2
#define GEAR_EVENT_AREA                 5

#define FOLLOW_SEGMENT_NORMAL           0
#define FOLLOW_SEGMENT_EVEN             1
#define FOLLOW_SEGMENT_STOP             2
#define FOLLOW_SEGMENT_CONTINUE         3

#define CRD_FIFO_MAX                    4096
#define FIFO_MAX						2
#define CRD_MAX                         2
#define CRD_OPERATION_DATA_EXT_MAX      2

#define CRD_OPERATION_TYPE_NONE                   0
#define CRD_OPERATION_TYPE_BUF_IO_DELAY           1
#define CRD_OPERATION_TYPE_LASER_ON               2
#define CRD_OPERATION_TYPE_LASER_OFF              3
#define CRD_OPERATION_TYPE_BUF_DA                 4
#define CRD_OPERATION_TYPE_LASER_CMD              5
#define CRD_OPERATION_TYPE_LASER_FOLLOW_RATIO     6
#define CRD_OPERATION_TYPE_LMTS_ON                7
#define CRD_OPERATION_TYPE_LMTS_OFF               8
#define CRD_OPERATION_TYPE_SET_STOP_IO            9
#define CRD_OPERATION_TYPE_BUF_MOVE               10
#define CRD_OPERATION_TYPE_BUF_GEAR               11
#define CRD_OPERATION_TYPE_SET_SEG_NUM            12
#define CRD_OPERATION_TYPE_STOP_MOTION            13
#define CRD_OPERATION_TYPE_SET_VAR_VALUE          14
#define CRD_OPERATION_TYPE_JUMP_NEXT_SEG          15
#define CRD_OPERATION_TYPE_SYNCH_PRF_POS          16
#define CRD_OPERATION_TYPE_VIRTUAL_TO_ACTUAL      17
#define CRD_OPERATION_TYPE_SET_USER_VAR           18
#define CRD_OPERATION_TYPE_SET_DO_BIT_PULSE       19
#define CRD_OPERATION_TYPE_BUF_COMPAREPULSE       20
#define CRD_OPERATION_TYPE_LASER_ON_EX            21
#define CRD_OPERATION_TYPE_LASER_OFF_EX           22
#define CRD_OPERATION_TYPE_LASER_CMD_EX           23
#define CRD_OPERATION_TYPE_LASER_FOLLOW_RATIO_EX  24
#define CRD_OPERATION_TYPE_LASER_FOLLOW_MODE      25
#define CRD_OPERATION_TYPE_LASER_FOLLOW_OFF		  26
#define CRD_OPERATION_TYPE_LASER_FOLLOW_OFF_EX	  27
#define CRD_OPERATION_TYPE_LASER_FOLLOW_SPLINE	  28
#define CRD_OPERATION_TYPE_MOTION_DATA			  29

#define CRD_OPERATION_TYPE_BUF_TREND			  50

#define CRD_OPERATION_TYPE_BUF_FOLLOW_MASTER     (60)
#define CRD_OPERATION_TYPE_BUF_FOLLOW_EVENT      (61)
#define CRD_OPERATION_TYPE_BUF_FOLLOW_EVENT_TRIGGER	 (62)	//新前瞻指令需要通过这些宏进行区分，GT_BufFollowEventCross和GT_BufFollowEventTrigger共用CRD_OPERATION_TYPE_BUF_FOLLOW_EVENT，因此增加此宏进行区分
#define CRD_OPERATION_TYPE_BUF_FOLLOW_START      (63)
#define CRD_OPERATION_TYPE_BUF_FOLLOW_NEXT       (66)	
#define CRD_OPERATION_TYPE_BUF_FOLLOW_RETURN     (68)

#define CRD_OPERATION_TYPE_BUF_EVENT_ON			 (70)
#define CRD_OPERATION_TYPE_BUF_EVENT_OFF		 (71)

#define CRD_OPERATION_TYPE_WORK_LASER_FOLLOW_RATIO	(72)

#define CRD_OPERATION_TYPE_BUF_SMART_CUTTER_ENABLE (80)

#define INTERPOLATION_MOTION_TYPE_LINE  0
#define INTERPOLATION_MOTION_TYPE_CIRCLE 1
#define INTERPOLATION_MOTION_TYPE_HELIX 2
#define INTERPOLATION_MOTION_TYPE_CIRCLE_3D 3

#define INTERPOLATION_CIRCLE_PLAT_XY    0
#define INTERPOLATION_CIRCLE_PLAT_YZ    1
#define INTERPOLATION_CIRCLE_PLAT_ZX    2

#define INTERPOLATION_HELIX_CIRCLE_XY_LINE_Z    0
#define INTERPOLATION_HELIX_CIRCLE_YZ_LINE_X    1
#define INTERPOLATION_HELIX_CIRCLE_ZX_LINE_Y    2

#define INTERPOLATION_CIRCLE_DIR_CW     0
#define INTERPOLATION_CIRCLE_DIR_CCW    1
#define CRD_OPERATION_TYPE_LASER_FOLLOW_RATIO     6

#define COMPARE_PORT_HSIO                 (0)             //??zW??HSIO?
#define COMPARE_PORT_GPO                  (1)             //??zW??GPO?

#define  COMPARE2D_MODE_2D            1
#define  COMPARE2D_MODE_1D            0

#define  INTERFACEBOARD20                2
#define  INTERFACEBOARD30                3


#define AXIS_LASER                       7
#define AXIS_LASER_EX                    8

#define LASER_CTRL_MODE_PWM1            (0)                 // ??:PWM1
#define LASER_CTRL_FREQUENCY            (1)                 // ??:?
#define LASER_CTRL_VOLTAGE              (2)                 // ??:?
#define LASER_CTRL_MODE_PWM2            (3)                 // ??:PWM2

#define CRD_BUFFER_MODE_DYNAMIC_DEFAULT  (0)
#define CRD_BUFFER_MODE_DYNAMIC_KEEP     (1)
#define CRD_BUFFER_MODE_STATIC_INPUT     (11)
#define CRD_BUFFER_MODE_STATIC_READY     (12)
#define CRD_BUFFER_MODE_STATIC_START     (13)

#define CRD_SMOOTH_MODE_NONE                   (0)
#define CRD_SMOOTH_MODE_PERCENT                (1)
#define CRD_SMOOTH_MODE_JERK                   (2)

typedef struct TrapPrm
{
    double acc;
    double dec;
    double velStart;
    short  smoothTime;
} TTrapPrm;

typedef struct TTrapTime
{
	double totalTime;
	double remainderTime;
	double pad[2];
} TTrapTime;

typedef struct JogPrm
{
    double acc;
    double dec;
    double smooth;
} TJogPrm;

typedef struct Pid
{
    double kp;
    double ki;
    double kd;
    double kvff;
    double kaff;
    long   integralLimit;
    long   derivativeLimit;
    short  limit;
} TPid;

typedef struct ThreadSts
{
    short  run;
    short  error;
    double result;
    short  line;
} TThreadSts;

typedef struct VarInfo
{
    short id;
    short dataType;
    char  name[32];
} TVarInfo;

typedef struct CompileInfo
{
    char  *pFileName;
    short *pLineNo;
    char  *pMessage;
} TCompileInfo;

typedef struct CrdPrm
{
    short dimension;                              // 坐标系维数
    short profile[8];                             // 关联profile和坐标轴
    double synVelMax;                             // 最大合成速度
    double synAccMax;                             // 最大合成加速度
    short evenTime;                               // 最小匀速时间
    short setOriginFlag;                          // 设置原点坐标值标志,0:默认当前规划位置为原点位置;1:用户指定原点位置
    long originPos[8];                            // 用户指定的原点位置
}TCrdPrm;

typedef struct CrdBufOperation
{
    short flag;                                   // 标志该插补段是否含有IO和延时
    unsigned short delay;                         // 延时时间
    short doType;                                 // 缓存区IO的类型,0:不输出IO
    unsigned short doMask;                        // 缓存区IO的输出控制掩码
    unsigned short doValue;                       // 缓存区IO的输出值
    unsigned short dataExt[CRD_OPERATION_DATA_EXT_MAX];     // 辅助操作扩展数据
}TCrdBufOperation;

typedef struct CrdData
{
    short motionType;                             // 运动类型,0:直线插补,1:圆弧插补
    short circlePlat;                             // 圆弧插补的平面
    long pos[8];             // 当前段各轴终点位置
    double radius;                                  // 圆弧插补的半径
    short circleDir;                              // 圆弧旋转方向,0:顺时针;1:逆时针
    double center[3];                               // 圆弧插补的圆心坐标
    double vel;                                   // 当前段合成目标速度
    double acc;                                   // 当前段合成加速度
    short velEndZero;                             // 标志当前段的终点速度是否强制为0,0:不强制为0;1:强制为0
    TCrdBufOperation operation;                   // 缓存区延时和IO结构体

    double cos[8];           // 当前段各轴对应的余弦值
    double velEnd;                                // 当前段合成终点速度
    double velEndAdjust;                          // 调整终点速度时用到的变量(前瞻模块)
    double r;                                     // 当前段合成位移量
}TCrdData;

typedef struct Trigger
{
    short encoder;
    short probeType;
    short probeIndex;
	short sense;
    short offset;
	unsigned long loop;
    short windowOnly;
    long firstPosition;
    long lastPosition;
}TTrigger;

typedef struct TriggerStatus
{
    short execute;
    short done;
    long position;
}TTriggerStatus;

typedef struct TriggerStatusEx
{
	short execute;
	short done;
	long position;
	unsigned long clock;
	unsigned long loopCount;
}TTriggerStatusEx;

typedef struct
{
    long px;
    long py;
} T2DCompareData;

typedef struct
{
    short encx;
    short ency;
    short source;
    short outputType;
    short startLevel;
    short time;
    short maxerr;
    short threshold;
} T2DComparePrm;

typedef struct  
{
	short mode;
	short encoderX;
	short encoderY;
	short source;
	short outputType;
	short startLevel;
	long pulseTime;
	short maxerr;
	long pulseCount;
	long pulseCycle;
	long interval;
	unsigned short pad1[2];
	long pad2[2];
}T2DComparePrmEx;
typedef struct
{
	long px;
	long py;
	long intervalX;
	long intervalY;
	long count;
}T2DCompareDataGroup;
typedef struct  
{
	double time;
	long segmentUsed;
	long segmentHead;
	long segmentTail;
} TCrdTime;

typedef struct  
{
	short percent;
	short accStartPercent;
	short decEndPercent;
	double reserve;
} TCrdSmooth;

typedef struct
{
	short          mdlType;                       // 扩展模块的类型

	short          mdlAddressBegin;               // 该模块的起始地址偏移

	short          adChannels;                    // 如果为AD时，通道的数量
	double         adMaxVoltage;                  // 如果为AD时，最大转换位对应的电压值
	double         adMinVoltage;                  // 如果为AD时，最小转换位对应的电压值

	short          daChannels;                    // 如果为DA时，通道的数量
	double         daMaxVoltage;                  // 如果为DA时，最大转换位对应的电压值
	double         daMinVoltage;                  // 如果为DA时，最小转换位对应的电压值

	unsigned short outSave;                       // 保留当前IO输出的值
}TExtMdlCfgInfo;

GT_API GT_GetDllVersion(char **pDllVersion);

GT_API GT_SetCardNo(short index);
GT_API GT_GetCardNo(short *pIndex);

GT_API GT_GetVersion(char **pVersion);
GT_API GT_GetInterfaceBoardSts(short *pStatus);
GT_API GT_SetInterfaceBoardSts(short type);
GT_API GT_Open(short channel=0,short param=1);
GT_API GT_Close(void);

GT_API GT_LoadConfig(char *pFile);

GT_API GT_AlarmOff(short axis);
GT_API GT_AlarmOn(short axis);
GT_API GT_LmtsOn(short axis,short limitType=-1);
GT_API GT_LmtsOff(short axis,short limitType=-1);
GT_API GT_ProfileScale(short axis,short alpha,short beta);
GT_API GT_EncScale(short axis,short alpha,short beta);
GT_API GT_StepDir(short step);
GT_API GT_StepPulse(short step);
GT_API GT_SetMtrBias(short dac,short bias);
GT_API GT_GetMtrBias(short dac,short *pBias);
GT_API GT_SetMtrLmt(short dac,short limit);
GT_API GT_GetMtrLmt(short dac,short *pLimit);
GT_API GT_EncSns(unsigned short sense);
GT_API GT_EncOn(short encoder);
GT_API GT_EncOff(short encoder);
GT_API GT_SetPosErr(short control,long error);
GT_API GT_GetPosErr(short control,long *pError);
GT_API GT_SetStopDec(short profile,double decSmoothStop,double decAbruptStop);
GT_API GT_GetStopDec(short profile,double *pDecSmoothStop,double *pDecAbruptStop);
GT_API GT_LmtSns(unsigned short sense);
GT_API GT_CtrlMode(short axis,short mode);
GT_API GT_SetStopIo(short axis,short stopType,short inputType,short inputIndex);
GT_API GT_GpiSns(unsigned short sense);
GT_API GT_SetAdcFilter(short adc,short filterTime);
GT_API GT_SetAxisInputShaping(short axis,short enable,short count,double k);

GT_API GT_SetDo(short doType,long value);
GT_API GT_SetDoBit(short doType,short doIndex,short value);
GT_API GT_GetDo(short doType,long *pValue);
GT_API GT_SetDoBitReverse(short doType,short doIndex,short value,short reverseTime);
GT_API GT_SetDoMask(short doType,unsigned short doMask,long value);
GT_API GT_EnableDoBitPulse(short doType,short doIndex,unsigned short highLevelTime,unsigned short lowLevelTime,long pulseNum,short firstLevel);
GT_API GT_DisableDoBitPulse(short doType,short doIndex);

GT_API GT_GetDi(short diType,long *pValue);
GT_API GT_GetDiReverseCount(short diType,short diIndex,unsigned long *pReverseCount,short count=1);
GT_API GT_SetDiReverseCount(short diType,short diIndex,unsigned long *pReverseCount,short count=1);
GT_API GT_GetDiRaw(short diType,long *pValue);

GT_API GT_SetDac(short dac,short *pValue,short count=1);
GT_API GT_GetDac(short dac,short *pValue,short count=1,unsigned long *pClock=NULL);

GT_API GT_GetAdc(short adc,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAdcValue(short adc,short *pValue,short count=1,unsigned long *pClock=NULL);

GT_API GT_SetEncPos(short encoder,long encPos);
GT_API GT_GetEncPos(short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetEncPosPre(short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetEncVel(short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);

GT_API GT_SetCaptureMode(short encoder,short mode);
GT_API GT_GetCaptureMode(short encoder,short *pMode,short count=1);
GT_API GT_StopCapture(short encoder);
GT_API GT_GetCaptureStatus(short encoder,short *pStatus,long *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_SetCaptureSense(short encoder,short mode,short sense);
GT_API GT_ClearCaptureStatus(short encoder);
GT_API GT_SetCaptureRepeat(short encoder,short count);
GT_API GT_GetCaptureRepeatStatus(short encoder,short *pCount);
GT_API GT_GetCaptureRepeatPos(short encoder,long *pValue,short startNum,short count);

GT_API GT_SetCaptureEncoder(short trigger,short encoder);
GT_API GT_GetCaptureWidth(short trigger,short *pWidth,short count=1);
GT_API GT_GetCaptureHomeGpi(short trigger,short pHomeSts,short *pHomePos,short pGpiSts,short *pGpiPos,short count=1);

GT_API GT_Reset();
GT_API GT_GetClock(unsigned long *pClock,unsigned long *pLoop=NULL);
GT_API GT_GetClockHighPrecision(unsigned long *pClock);

GT_API GT_GetSts(short axis,long *pSts,short count=1,unsigned long *pClock=NULL);
GT_API GT_ClrSts(short axis,short count=1);
GT_API GT_AxisOn(short axis);
GT_API GT_AxisOff(short axis);
GT_API GT_Stop(long mask,long option);
GT_API GT_SetPrfPos(short profile,long prfPos);
GT_API GT_SynchAxisPos(long mask);
GT_API GT_ZeroPos(short axis,short count=1);

GT_API GT_SetSoftLimit(short axis,long positive,long negative);
GT_API GT_GetSoftLimit(short axis,long *pPositive,long *pNegative);
GT_API GT_SetAxisBand(short axis,long band,long time);
GT_API GT_GetAxisBand(short axis,long *pBand,long *pTime);
GT_API GT_SetBacklash(short axis,long compValue,double compChangeValue,long compDir);
GT_API GT_GetBacklash(short axis,long *pCompValue,double *pCompChangeValue,long *pCompDir);
GT_API GT_SetLeadScrewComp(short axis,short n,long startPos,long lenPos,long *pCompPos,long *pCompNeg);
GT_API GT_EnableLeadScrewComp(short axis,short mode);
GT_API GT_GetCompensate(short axis,double *pPitchError,double *pCrossError,double *pBacklashError,double *pEncPos,double *pPrfPos);

GT_API GT_EnableGantry(short gantryMaster,short gantrySlave,double masterKp,double slaveKp);
GT_API GT_DisableGantry();
GT_API GT_SetGantryErrLmt(long gantryErrLmt);
GT_API GT_GetGantryErrLmt(long *pGantryErrLmt);
GT_API GT_ZeroGantryPos(short gantryMaster,short gantrySlave);

GT_API GT_GetPrfPos(short profile,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetPrfVel(short profile,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetPrfAcc(short profile,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetPrfMode(short profile,long *pValue,short count=1,unsigned long *pClock=NULL);

GT_API GT_GetAxisPrfPos(short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAxisPrfVel(short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAxisPrfAcc(short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAxisEncPos(short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAxisEncVel(short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAxisEncAcc(short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAxisError(short axis,double *pValue,short count=1,unsigned long *pClock=NULL);

GT_API GT_SetLongVar(short index,long value);
GT_API GT_GetLongVar(short index,long *pValue);
GT_API GT_SetDoubleVar(short index,double pValue);
GT_API GT_GetDoubleVar(short index,double *pValue);

GT_API GT_SetControlFilter(short control,short index);
GT_API GT_GetControlFilter(short control,short *pIndex);

GT_API GT_SetPid(short control,short index,TPid *pPid);
GT_API GT_GetPid(short control,short index,TPid *pPid);

GT_API GT_SetKvffFilter(short control,short index,short kvffFilterExp,double accMax);
GT_API GT_GetKvffFilter(short control,short index,short *pKvffFilterExp,double *pAccMax);

GT_API GT_Update(long mask);
GT_API GT_SetPos(short profile,long pos);
GT_API GT_GetPos(short profile,long *pPos);
GT_API GT_SetVel(short profile,double vel);
GT_API GT_GetVel(short profile,double *pVel);

GT_API GT_PrfTrap(short profile);
GT_API GT_SetTrapPrm(short profile,TTrapPrm *pPrm);
GT_API GT_GetTrapPrm(short profile,TTrapPrm *pPrm);
GT_API GT_GetTrapTime(short profile,TTrapTime *pTime);

GT_API GT_PrfJog(short profile);
GT_API GT_SetJogPrm(short profile,TJogPrm *pPrm);
GT_API GT_GetJogPrm(short profile,TJogPrm *pPrm);

GT_API GT_PrfPt(short profile,short mode=PT_MODE_STATIC);
GT_API GT_SetPtLoop(short profile,long loop);
GT_API GT_GetPtLoop(short profile,long *pLoop);
GT_API GT_PtSpace(short profile,short *pSpace,short fifo=0);
GT_API GT_PtData(short profile,double pos,long time,short type=PT_SEGMENT_NORMAL,short fifo=0);
GT_API GT_PtDataWN(short profile,double pos,long time,short type=PT_SEGMENT_NORMAL,long segNum=0,short fifo=0);
GT_API GT_PtClear(short profile,short fifo=0);
GT_API GT_PtStart(long mask,long option=0);
GT_API GT_SetPtMemory(short profile,short memory);
GT_API GT_GetPtMemory(short profile,short *pMemory);
GT_API GT_PtGetSegNum(short profile,long *pSegNum);
GT_API GT_SetPtPrecisionMode(short profile,short precisionMode);
GT_API GT_GetPtPrecisionMode(short profile,short *pPrecisionMode);
GT_API GT_SetPtVel(short profile,double velLast,short fifo);
GT_API GT_SetPtLink(short profile,short fifo,short list);
GT_API GT_GetPtLink(short profile,short fifo,short *pList);
GT_API GT_PtDoBit(short profile,short doType,short index,short value,short fifo);
GT_API GT_PtAo(short profile,short aoType,short index,double value,short fifo);

GT_API GT_PrfGear(short profile,short dir=0);
GT_API GT_SetGearMaster(short profile,short masterIndex,short masterType=GEAR_MASTER_PROFILE,short masterItem=0);
GT_API GT_GetGearMaster(short profile,short *pMasterIndex,short *pMasterType=NULL,short *pMasterItem=NULL);
GT_API GT_SetGearRatio(short profile,long masterEven,long slaveEven,long masterSlope=0);
GT_API GT_GetGearRatio(short profile,long *pMasterEven,long *pSlaveEven,long *pMasterSlope=NULL);
GT_API GT_GearStart(long mask);
GT_API GT_SetGearEvent(short profile,short event,long startPara0,long startPara1);
GT_API GT_GetGearEvent(short profile,short *pEvent,long *pStartPara0,long *pStartPara1);

GT_API GT_PrfFollow(short profile,short dir=0);
GT_API GT_SetFollowMaster(short profile,short masterIndex,short masterType=FOLLOW_MASTER_PROFILE,short masterItem=0);
GT_API GT_GetFollowMaster(short profile,short *pMasterIndex,short *pMasterType=NULL,short *pMasterItem=NULL);
GT_API GT_SetFollowLoop(short profile,long loop);
GT_API GT_GetFollowLoop(short profile,long *pLoop);
GT_API GT_SetFollowEvent(short profile,short event,short masterDir,long pos=0);
GT_API GT_GetFollowEvent(short profile,short *pEvent,short *pMasterDir,long *pPos=NULL);
GT_API GT_FollowSpace(short profile,short *pSpace,short fifo=0);
GT_API GT_FollowData(short profile,long masterSegment,double slaveSegment,short type=FOLLOW_SEGMENT_NORMAL,short fifo=0);
GT_API GT_FollowClear(short profile,short fifo=0);
GT_API GT_FollowStart(long mask,long option=0);
GT_API GT_FollowSwitch(long mask);
GT_API GT_SetFollowMemory(short profile,short memory);
GT_API GT_GetFollowMemory(short profile,short *pMemory);
GT_API GT_GetFollowStatus(short profile,short *pFifoNum,short *pSwitchStatus);
GT_API GT_SetFollowPhasing(short profile,short profilePhasing);
GT_API GT_GetFollowPhasing(short profile,short *pProfilePhasing);

GT_API GT_Compile(char *pFileName,TCompileInfo *pWrongInfo);
GT_API GT_Download(char *pFileName);

GT_API GT_GetFunId(char *pFunName,short *pFunId);
GT_API GT_Bind(short thread,short funId,short page);

GT_API GT_RunThread(short thread);
GT_API GT_StopThread(short thread);
GT_API GT_PauseThread(short thread);

GT_API GT_GetThreadSts(short thread,TThreadSts *pThreadSts);

GT_API GT_GetVarId(char *pFunName,char *pVarName,TVarInfo *pVarInfo);
GT_API GT_SetVarValue(short page,TVarInfo *pVarInfo,double *pValue,short count=1);
GT_API GT_GetVarValue(short page,TVarInfo *pVarInfo,double *pValue,short count=1);

GT_API GT_SetCrdMapBase(short crd,short base);
GT_API GT_GetCrdMapBase(short crd,short *pBase);
GT_API GT_SetCrdSmooth(short crd,TCrdSmooth *pCrdSmooth);
GT_API GT_GetCrdSmooth(short crd,TCrdSmooth *pCrdSmooth);
GT_API GT_SetCrdJerk(short crd,double jerkMax);
GT_API GT_GetCrdJerk(short crd,double *pJerkMax);
GT_API GT_SetCrdPrm(short crd,TCrdPrm *pCrdPrm);
GT_API GT_GetCrdPrm(short crd,TCrdPrm *pCrdPrm);
GT_API GT_SetArcAllowError(short crd,double error);
GT_API GT_CrdSpace(short crd,long *pSpace,short fifo=0);
GT_API GT_CrdData(short crd,TCrdData *pCrdData,short fifo=0);
GT_API GT_CrdDataCircle(short crd,TCrdData *pCrdData,short fifo=0);
GT_API GT_LnXY(short crd,long x,long y,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYZ(short crd,long x,long y,long z,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYZA(short crd,long x,long y,long z,long a,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYG0(short crd,long x,long y,double synVel,double synAcc,short fifo=0);
GT_API GT_LnXYZG0(short crd,long x,long y,long z,double synVel,double synAcc,short fifo=0);
GT_API GT_LnXYZAG0(short crd,long x,long y,long z,long a,double synVel,double synAcc,short fifo=0);
GT_API GT_ArcXYR(short crd,long x,long y,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcXYC(short crd,long x,long y,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcYZR(short crd,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcYZC(short crd,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcZXR(short crd,long z,long x,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcZXC(short crd,long z,long x,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcXYZ(short crd,long x,long y,long z,double interX,double interY,double interZ,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYOverride2(short crd,long x,long y,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYZOverride2(short crd,long x,long y,long z,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYZAOverride2(short crd,long x,long y,long z,long a,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYG0Override2(short crd,long x,long y,double synVel,double synAcc,short fifo=0);
GT_API GT_LnXYZG0Override2(short crd,long x,long y,long z,double synVel,double synAcc,short fifo=0);
GT_API GT_LnXYZAG0Override2(short crd,long x,long y,long z,long a,double synVel,double synAcc,short fifo=0);
GT_API GT_ArcXYROverride2(short crd,long x,long y,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcXYCOverride2(short crd,long x,long y,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcYZROverride2(short crd,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcYZCOverride2(short crd,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcZXROverride2(short crd,long z,long x,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcZXCOverride2(short crd,long z,long x,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixXYRZ(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd,short fifo=0);
GT_API GT_HelixXYCZ(short crd,long x,long y,long z,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixYZRX(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixYZCX(short crd,long x,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixZXRY(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixZXCY(short crd,long x,long y,long z,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixXYRZOverride2(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixXYCZOverride2(short crd,long x,long y,long z,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixYZRXOverride2(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixYZCXOverride2(short crd,long x,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixZXRYOverride2(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixZXCYOverride2(short crd,long x,long y,long z,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYWN(short crd,long x,long y,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_LnXYZWN(short crd,long x,long y,long z,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_LnXYZAWN(short crd,long x,long y,long z,long a,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_LnXYG0WN(short crd,long x,long y,double synVel,double synAcc,long segNum=0,short fifo=0);
GT_API GT_LnXYZG0WN(short crd,long x,long y,long z,double synVel,double synAcc,long segNum=0,short fifo=0);
GT_API GT_LnXYZAG0WN(short crd,long x,long y,long z,long a,double synVel,double synAcc,long segNum=0,short fifo=0);
GT_API GT_ArcXYRWN(short crd,long x,long y,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_ArcXYCWN(short crd,long x,long y,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_ArcYZRWN(short crd,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_ArcYZCWN(short crd,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_ArcZXRWN(short crd,long z,long x,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_ArcZXCWN(short crd,long z,long x,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_ArcXYZWN(short crd,long x,long y,long z,double interX,double interY,double interZ,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_LnXYOverride2WN(short crd,long x,long y,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_LnXYZOverride2WN(short crd,long x,long y,long z,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_LnXYZAOverride2WN(short crd,long x,long y,long z,long a,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_LnXYG0Override2WN(short crd,long x,long y,double synVel,double synAcc,long segNum=0,short fifo=0);
GT_API GT_LnXYZG0Override2WN(short crd,long x,long y,long z,double synVel,double synAcc,long segNum=0,short fifo=0);
GT_API GT_LnXYZAG0Override2WN(short crd,long x,long y,long z,long a,double synVel,double synAcc,long segNum=0,short fifo=0);
GT_API GT_ArcXYROverride2WN(short crd,long x,long y,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_ArcXYCOverride2WN(short crd,long x,long y,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_ArcYZROverride2WN(short crd,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_ArcYZCOverride2WN(short crd,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_ArcZXROverride2WN(short crd,long z,long x,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_ArcZXCOverride2WN(short crd,long z,long x,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_ArcXYZOverride2WN(short crd,long x,long y,long z,double interX,double interY,double interZ,double synVel,double synAcc,double velEnd,long segNum,short fifo=0);
GT_API GT_HelixXYRZWN(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_HelixXYCZWN(short crd,long x,long y,long z,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_HelixYZRXWN(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_HelixYZCXWN(short crd,long x,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_HelixZXRYWN(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_HelixZXCYWN(short crd,long x,long y,long z,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_HelixXYRZOverride2WN(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_HelixXYCZOverride2WN(short crd,long x,long y,long z,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_HelixYZRXOverride2WN(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_HelixYZCXOverride2WN(short crd,long x,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_HelixZXRYOverride2WN(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_HelixZXCYOverride2WN(short crd,long x,long y,long z,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_BufTrend(short crd,unsigned long trendSegNum,double trendDistance,double trendVelEnd,short fifo=0);
GT_API GT_BufIO(short crd,unsigned short doType,unsigned short doMask,unsigned short doValue,short fifo=0);
GT_API GT_BufEnableDoBitPulse(short crd,short doType,short doIndex,unsigned short highLevelTime,unsigned short lowLevelTime,long pulseNum,short firstLevel,short fifo=0);
GT_API GT_BufDisableDoBitPulse(short crd,short doType,short doIndex,short fifo=0);
GT_API GT_BufDelay(short crd,unsigned short delayTime,short fifo=0);
GT_API GT_BufComparePulse(short crd,short level,short outputType,short time,short fifo=0);
GT_API GT_BufDA(short crd,short chn,short daValue,short fifo=0);
GT_API GT_BufLmtsOn(short crd,short axis,short limitType,short fifo=0);
GT_API GT_BufLmtsOff(short crd,short axis,short limitType,short fifo=0);
GT_API GT_BufSetStopIo(short crd,short axis,short stopType,short inputType,short inputIndex,short fifo=0);
GT_API GT_BufMove(short crd,short moveAxis,long pos,double vel,double acc,short modal,short fifo=0);
GT_API GT_BufGear(short crd,short gearAxis,long pos,short fifo=0);
GT_API GT_BufGearPercent(short crd,short gearAxis,long pos,short accPercent,short decPercent,short fifo=0);
GT_API GT_BufStopMotion(short crd,short fifo=0);
GT_API GT_BufSetVarValue(short crd,short pageId,TVarInfo *pVarInfo,double value,short fifo=0);
GT_API GT_BufJumpNextSeg(short crd,short axis,short limitType,short fifo=0);
GT_API GT_BufSynchPrfPos(short crd,short encoder,short profile,short fifo=0);
GT_API GT_BufVirtualToActual(short crd,short fifo=0);
GT_API GT_BufSetLongVar(short crd,short index,long value,short fifo=0);
GT_API GT_BufSetDoubleVar(short crd,short index,double value,short fifo=0);
GT_API GT_CrdStart(short mask,short option);
GT_API GT_CrdStartStep(short mask,short option);
GT_API GT_CrdStepMode(short mask,short option);
GT_API GT_SetOverride(short crd,double synVelRatio);
GT_API GT_SetOverride2(short crd,double synVelRatio);
GT_API GT_SetMaxOverrideLA(double maxSynVelRatio);
GT_API GT_InitLookAhead(short crd,short fifo,double T,double accMax,short n,TCrdData *pLookAheadBuf);
GT_API GT_GetLookAheadSpace(short crd,long *pSpace,short fifo=0);
GT_API GT_GetLookAheadSegCount(short crd,long *pSegCount,short fifo=0);
GT_API GT_CrdClear(short crd,short fifo);
GT_API GT_CrdStatus(short crd,short *pRun,long *pSegment,short fifo=0);
GT_API GT_SetUserSegNum(short crd,long segNum,short fifo=0);
GT_API GT_GetUserSegNum(short crd,long *pSegment,short fifo=0);
GT_API GT_GetUserSegNumWN(short crd,long *pSegment,short fifo=0);
GT_API GT_GetRemainderSegNum(short crd,long *pSegment,short fifo=0);
GT_API GT_SetCrdStopDec(short crd,double decSmoothStop,double decAbruptStop);
GT_API GT_GetCrdStopDec(short crd,double *pDecSmoothStop,double *pDecAbruptStop);
GT_API GT_SetCrdLmtStopMode(short crd,short lmtStopMode);
GT_API GT_GetCrdLmtStopMode(short crd,short *pLmtStopMode);
GT_API GT_GetUserTargetVel(short crd,double *pTargetVel);
GT_API GT_GetSegTargetPos(short crd,long *pTargetPos);
GT_API GT_GetCrdPos(short crd,double *pPos);
GT_API GT_GetCrdVel(short crd,double *pSynVel);
GT_API GT_SetCrdSingleMaxVel(short crd,double *pMaxVel);
GT_API GT_GetCrdSingleMaxVel(short crd,double *pMaxVel);
GT_API GT_GetCmdCount(short crd,short *pResult,short fifo);
GT_API GT_BufLaserOn(short crd,short fifo=0,short channel=0);
GT_API GT_BufLaserOff(short crd,short fifo=0,short channel=0);
GT_API GT_BufLaserPrfCmd(short crd,double laserPower,short fifo=0,short channel=0);
GT_API GT_BufLaserFollowRatio(short crd,double ratio,double minPower,double maxPower,short fifo=0,short channel=0);
GT_API GT_BufLaserFollowMode(short crd,short source =0,short fifo=0,short channel=0,double startPower =0);
GT_API GT_BufLaserFollowOff(short crd,short fifo=0,short channel=0);
GT_API GT_BufLaserFollowSpline(short crd,short tableId,double minPower,double maxPower,short fifo=0,short channel=0);
GT_API GT_LnXYZACUVW(short crd,long *pPos,short posMask,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYZACUVWWN(short crd,long *pPos,short posMask,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_LnXYZACUVWOverride2(short crd,long *pPos,short posMask,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYZACUVWOverride2WN(short crd,long *pPos,short posMask,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_PrfPvt(short profile);
GT_API GT_SetPvtLoop(short profile,long loop);
GT_API GT_GetPvtLoop(short profile,long *pLoopCount,long *pLoop);
GT_API GT_PvtStatus(short profile,short *pTableId,double *pTime,short count=1);
GT_API GT_PvtTableClear(short tableId);
GT_API GT_PvtStart(long mask);
GT_API GT_PvtTableSelect(short profile,short tableId);

GT_API GT_PvtTable(short tableId,long count,double *pTime,double *pPos,double *pVel);
GT_API GT_PvtTableEx(short tableId,long count,double *pTime,double *pPos,double *pVelBegin,double *pVelEnd);
GT_API GT_PvtTableComplete(short tableId,long count,double *pTime,double *pPos,double *pA,double *pB,double *pC,double velBegin=0,double velEnd=0);
GT_API GT_PvtTablePercent(short tableId,long count,double *pTime,double *pPos,double *pPercent,double velBegin=0);
GT_API GT_PvtPercentCalculate(long n,double *pTime,double *pPos,double *pPercent,double velBegin,double *pVel);
GT_API GT_PvtTableContinuous(short tableId,long count,double *pPos,double *pVel,double *pPercent,double *pVelMax,double *pAcc,double *pDec,double timeBegin);
GT_API GT_PvtContinuousCalculate(long n,double *pPos,double *pVel,double *pPercent,double *pVelMax,double *pAcc,double *pDec,double *pTime);
GT_API GT_PvtTableMovePercent(short tableId,long distance,double vm,double acc,double pa1,double pa2,double dec,double pd1,double pd2,double *pVel,double *pAcc,double *pDec,double *pTime);
GT_API GT_PvtTableMovePercentEx(short tableId,long distance,double vm,double acc,double pa1,double pa2,double ma,double dec,double pd1,double pd2,double md,double *pVel,double *pAcc,double *pDec,double *pTime);

GT_API GT_HomeInit();
GT_API GT_Home(short axis,long pos,double vel,double acc,long offset);
GT_API GT_Index(short axis,long pos,long offset);
GT_API GT_HomeStop(short axis,long pos,double vel,double acc);
GT_API GT_HomeSts(short axis,unsigned short *pStatus);

GT_API GT_HandwheelInit();
GT_API GT_SetHandwheelStopDec(short slave,double decSmoothStop,double decAbruptStop);
GT_API GT_StartHandwheel(short slave,short master,short masterEven,short slaveEven,short intervalTime,double acc,double dec,double vel,short stopWaitTime);
GT_API GT_EndHandwheel(short slave);

GT_API GT_SetTrigger(short i,TTrigger *pTrigger);
GT_API GT_GetTrigger(short i,TTrigger *pTrigger);
GT_API GT_GetTriggerStatus(short i,TTriggerStatus *pTriggerStatus,short count=1);
GT_API GT_GetTriggerStatusEx(short i,TTriggerStatusEx *pTriggerStatusEx,short count=1);
GT_API GT_ClearTriggerStatus(short i);

GT_API GT_SetComparePort(short channel,short hsio0,short hsio1);

GT_API GT_ComparePulse(short level,short outputType,short time);
GT_API GT_CompareStop();
GT_API GT_CompareStatus(short *pStatus,long *pCount);
GT_API GT_CompareData(short encoder,short source,short pulseType,short startLevel,short time,long *pBuf1,short count1,long *pBuf2,short count2);
GT_API GT_CompareLinear(short encoder,short channel,long startPos,long repeatTimes,long interval,short time,short source);
GT_API GT_CompareContinuePulseMode(short mode,short count,short standTime);

GT_API GT_SetEncResponseCheck(short control,short dacThreshold,double minEncVel,long time);
GT_API GT_GetEncResponseCheck(short control,short *pDacThreshold,double *pMinEncVel,long *pTime);
GT_API GT_EnableEncResponseCheck(short control);
GT_API GT_DisableEncResponseCheck(short control);

GT_API GT_2DCompareMode(short chn,short mode);
GT_API GT_2DComparePulse(short chn,short level,short outputType,short time);
GT_API GT_2DCompareStop(short chn);
GT_API GT_2DCompareClear(short chn);
GT_API GT_2DCompareStatus(short chn,short *pStatus,long *pCount,short *pFifo,short *pFifoCount,short *pBufCount =NULL);
GT_API GT_2DCompareSetPrm(short chn,T2DComparePrm *pPrm);
GT_API GT_2DCompareData(short chn,short count,T2DCompareData *pBuf,short fifo);
GT_API GT_2DCompareStart(short chn);
GT_API GT_2DCompareClearData(short chn);
GT_API GT_2DCompareSetPreOutTime(short chn,double preOutputTime);
GT_API GT_2DCompareSetPrmEx(short chn,T2DComparePrmEx *pMode);
GT_API GT_2DCompareDataGroup(short chn,short count,T2DCompareDataGroup *pDataGroup,short fifo);

GT_API GT_SetAxisMode(short axis,short mode);
GT_API GT_GetAxisMode(short axis,short *pMode);
GT_API GT_SetHSIOOpt(unsigned short value,short channel=0);
GT_API GT_GetHSIOOpt(unsigned short *pValue,short channel=0);
GT_API GT_LaserPowerMode(short laserPowerMode,double maxValue,double minValue,short channel=0,short delaymode =0);
GT_API GT_LaserPrfCmd(double outputCmd,short channel=0);
GT_API GT_LaserOutFrq(double outFrq,short channel=0);
GT_API GT_SetPulseWidth(unsigned long width,short channel=0);
GT_API GT_SetWaitPulse(unsigned short mode,double waitPulseFrq,double waitPulseDuty,short channel=0);
GT_API GT_SetPreVltg(unsigned short mode,double voltageValue,short channel=0);
GT_API GT_SetLevelDelay(unsigned short offDelay,unsigned short onDelay,short channel=0);
GT_API GT_EnaFPK(unsigned short time1,unsigned short time2,unsigned short laserOffDelay,short channel=0);
GT_API GT_DisFPK(short channel=0);
GT_API GT_SetLaserDisMode(short mode,short source,long *pPos,double *pScale,short channel=0);
GT_API GT_SetLaserDisRatio(double *pRatio,double minPower,double maxPower,short channel=0);
GT_API GT_SetWaitPulseEx(unsigned short mode,double waitPulseFrq,double waitPulseDuty);
GT_API GT_SetLaserMode(short mode);
GT_API GT_SetLaserFollowSpline(short tableId,long n,double *pX,double *pY,double beginValue,double endValue,short channel=0);
GT_API GT_GetLaserFollowSpline(short tableId,long n,double *pX,double *pY,double *pA,double *pB,double *pC,long *pCount,short channel=0);

GT_API GT_OpenExtMdl(char *pDllName=NULL);
GT_API GT_CloseExtMdl();
GT_API GT_SwitchtoCardNoExtMdl(short card);

GT_API GT_ResetExtMdl();
GT_API GT_LoadExtConfig(char *pFileName);
GT_API GT_SetExtIoValue(short mdl,unsigned short value);
GT_API GT_GetExtIoValue(short mdl,unsigned short *pValue);
GT_API GT_SetExtIoBit(short mdl,short index,unsigned short value);
GT_API GT_GetExtIoBit(short mdl,short index,unsigned short *pValue);
GT_API GT_GetExtAdValue(short mdl,short chn,unsigned short *pValue);
GT_API GT_GetExtAdVoltage(short mdl,short chn,double *pValue);
GT_API GT_SetExtDaValue(short mdl,short chn,unsigned short value);
GT_API GT_SetExtDaVoltage(short mdl,short chn,double value);
GT_API GT_GetStsExtMdl(short mdl,short chn,unsigned short *pStatus);
GT_API GT_GetExtDoValue(short mdl,unsigned short *pValue);
GT_API GT_GetExtAdCurrent(short mdl,short chn,double *pValue);

GT_API GT_GetExtMdlMode(short *pMode);
GT_API GT_SetExtMdlMode(short mode);
GT_API GT_UploadConfig();
GT_API GT_DownloadConfig();
GT_API GT_GetConfig(short mdl,TExtMdlCfgInfo *pExtMdlCfgInfo);
GT_API GT_SetConfig(short mdl,TExtMdlCfgInfo *pExtMdlCfgInfo);
GT_API GT_GetDriverVersion(unsigned short *mainVer,unsigned short *slaveVer);
GT_API GT_SaveConfigToFile(char *pFile);
GT_API GT_GetChnStsExtMdl(unsigned short *pStatus);

GT_API GT_GetUuid(char *pCode,short count);
GT_API GT_SetUuid(char *pCode,short count);

//////////////////////////////////////////////////////////////////////////
//2D Compensate
//////////////////////////////////////////////////////////////////////////
typedef struct  
{
	short count[2];                               // 行数和列数，最小值为2
	long posBegin[2];                             // 起点位置
	long step[2];                                 // 步长
} TCompensate2DTable;

typedef struct  
{
	short enable;                                  // 2D补偿使能标志
	short tableIndex;                              // 所使用的2D补偿表
	short axisType[2];	                           // 查表轴类型
	short axisIndex[2];	                           // 查表轴索引
} TCompensate2D;

GT_API GT_SetCompensate2DTable(short tableIndex,TCompensate2DTable *pTable,long *pData,short externComp=0);
GT_API GT_GetCompensate2DTable(short tableIndex,TCompensate2DTable *pTable,short *pExternComp=NULL);
GT_API GT_SetCompensate2D(short axis,TCompensate2D *pComp2d);
GT_API GT_GetCompensate2D(short axis,TCompensate2D *pComp2d);
GT_API GT_GetCompensate2DValue(short axis,double *pValue);

//////////////////////////////////////////////////////////////////////////
//Smart Home
//////////////////////////////////////////////////////////////////////////
#define HOME_STAGE_IDLE						(0)
#define HOME_STAGE_START					(1)
#define HOME_STAGE_ON_HOME_LIMIT_ESCAPE	(2)

#define HOME_STAGE_SEARCH_LIMIT				(10)
#define HOME_STAGE_SEARCH_LIMIT_STOP		(11)

#define HOME_STAGE_SEARCH_LIMIT_ESCAPE		(13)

#define HOME_STAGE_SEARCH_LIMIT_RETURN		(15)
#define HOME_STAGE_SEARCH_LIMIT_RETURN_STOP	(16)

#define HOME_STAGE_SEARCH_HOME				(20)

#define HOME_STAGE_SEARCH_HOME_STOP		(22)

#define HOME_STAGE_SEARCH_HOME_RETURN		(25)

#define HOME_STAGE_SEARCH_INDEX				(30)

#define HOME_STAGE_SEARCH_GPI				(40)

#define HOME_STAGE_SEARCH_GPI_RETURN		(45)

#define HOME_STAGE_GO_HOME					(80)

#define HOME_STAGE_END						(100)

#define HOME_ERROR_NONE						(0)
#define HOME_ERROR_NOT_TRAP_MODE			(1)
#define HOME_ERROR_DISABLE					(2)
#define HOME_ERROR_ALARM					(3)
#define HOME_ERROR_STOP						(4)
#define HOME_ERROR_STAGE					(5)
#define HOME_ERROR_HOME_MODE				(6)
#define HOME_ERROR_SET_CAPTURE_HOME			(7)
#define HOME_ERROR_NO_HOME					(8)
#define HOME_ERROR_SET_CAPTURE_INDEX		(9)
#define HOME_ERROR_NO_INDEX					(10)

#define HOME_MODE_LIMIT						(10)
#define HOME_MODE_LIMIT_HOME				(11)
#define HOME_MODE_LIMIT_INDEX				(12)
#define HOME_MODE_LIMIT_HOME_INDEX			(13)

#define HOME_MODE_HOME						(20)

#define HOME_MODE_HOME_INDEX				(22)

#define HOME_MODE_INDEX						(30)

#define HOME_MODE_FORCED_HOME			(40)
#define HOME_MODE_FORCED_HOME_INDEX	(41)

typedef struct  
{
	short mode;						// 回零模式
	short moveDir;					// 设置启动搜索时的运动方向
	short indexDir;					// 设置Index搜索方向
	short edge;						// 设置捕获沿
	short triggerIndex;				// 用于设置触发器，为-1表示和轴号对应
	short pad1[3];					// 保留1
	double velHigh;					// Home搜索速度
	double velLow;					// Index搜索速度
	double acc;					
	double dec;
	short smoothTime;
	short pad2[3];					// 保留2
	long homeOffset;				// 原点偏移
	long searchHomeDistance;		// Home最大搜索距离，为0表示不限制
	long searchIndexDistance;		// Index最大搜索距离，为0表示不限制
	long escapeStep;				// 脱离步长
	long pad3[2];					// 保留3
} THomePrm;

typedef struct  
{
	short run;
	short stage;
	short error;
	short pad1;
	long capturePos;
	long targetPos;
} THomeStatus;

GT_API GT_GoHome(short axis,THomePrm *pHomePrm);
GT_API GT_GetHomePrm(short axis,THomePrm *pHomePrm);
GT_API GT_GetHomeStatus(short axis,THomeStatus *pHomeStatus);
//////////////////////////////////////////////////////////////////////////
//Extern Control
//////////////////////////////////////////////////////////////////////////
typedef struct ControlConfigEx
{
	short refType;			//输出参考类型，只能取MC_AXIS
	short refIndex;			//输出轴号
	short feedbackType;		//反馈类型，为MC_ENCODER时表示反馈类型为编码器，为MC_ADC时表示反馈类型为电压
	short feedbackIndex;	//反馈通道号
	long errorLimit;		//误差极限，暂时不起作用
	short feedbackSmooth;	//反馈平滑系数，暂时不起作用
	short controlSmooth;	//控制器平滑系数，暂时不起作用

}TControlConfigEx;

GT_API GT_SetControlConfigEx(short control,TControlConfigEx *pControl);
GT_API GT_GetControlConfigEx(short control,TControlConfigEx *pControl);
//////////////////////////////////////////////////////////////////////////
//Adc filter
//////////////////////////////////////////////////////////////////////////
typedef struct AdcConfig
{
	short active;	
	short reverse;
	double a;			//输入电压线性变换a值，取值为1
	double b;			//输入电压线性变换b值，取值为0
	short filterMode;	//滤波模式，0-FIR滤波模式，1-IIR滤波模式

} TAdcConfig;

GT_API GT_SetAdcConfig(short adc,TAdcConfig *pAdc);
GT_API GT_GetAdcConfig(short adc,TAdcConfig *pAdc);

GT_API GT_SetAdcFilterPrm(short adc,double k);
GT_API GT_GetAdcFilterPrm(short adc,double *pk);

//////////////////////////////////////////////////////////////////////////
//Superimposed
//////////////////////////////////////////////////////////////////////////
GT_API GT_SetControlSuperimposed(short control,short superimposedType,short superimposedIndex);
GT_API GT_GetControlSuperimposed(short control,short *pSuperimposedType,short *pSuperimposedIndex);

//////////////////////////////////////////////////////////////////////////
//Pci Interrupt
//////////////////////////////////////////////////////////////////////////
#define PCI_INTERRUPT_SOURCE_USER		(1)				//PCI中断源为用户自定义
#define PCI_INTERRUPT_SOURCE_2DCOMPARE	(2)				//PCI中断源为二维位置比较
typedef struct
{
	short source;	//interrupt source of pci device
	short param;	//param coming with pci interrupt
	short reserve;
}TInterrupt;

typedef short (*TInterruptCallback)(TInterrupt);

GT_API GT_InterruptOn(TInterruptCallback pCallback);
GT_API GT_InterruptOff();
GT_API GT_SetInterruptMask(long mask);
GT_API GT_GetInterruptMask(long *pMask);
GT_API GT_InterruptTrigger(short param);

//////////////////////////////////////////////////////////////////////////
GT_API GT_ZeroLaserOnTime(short channel);
GT_API GT_GetLaserOnTime(short channel,unsigned long *pTime);

typedef struct
{
	short work;			//是否已经设置参数
	short n;			//补偿点数
	long startPos;		//起始位置
	long lenPos;		//总长度
	long compPos[256];	//正向补偿值
	long compNeg[256];	//负向补偿值

}TLeadScrewPrm;

GT_API GT_GetLeadScrewCompInnerValue(short axis,short dir,long pos,long *pCompValue);

GT_API GT_SetProfileScale(short axis,long alpha,long beta);
GT_API GT_GetProfileScale(short axis,long *pAlpha,long *pBeta);
GT_API GT_SetEncoderScale(short encoder,long alpha,long beta);
GT_API GT_GetEncoderScale(short encoder,long *pAlpha,long *pBeta);

GT_API GT_MultiAxisOn(unsigned long mask);
GT_API GT_MultiAxisOff(unsigned long mask);
GT_API GT_SetAxisOnDelayTime(unsigned short ms);
GT_API GT_GetAxisOnDelayTime(unsigned short *pMs);

GT_API GT_SetLaserDisTable1D(short count,double *pRatio,long *pPos,double minPower,double maxPower,double *pLimitPower,short channel=0);
GT_API GT_SetLaserDisTable2D(short axisIndex[2],short count[2],double *pRatio,long *pXPos,long *pYPos, 
							 double minPower,double maxPower,double *pLimitPower,short channel=0);
GT_API GT_SetLaserDisTable2DEx(short axisIndex[2],short count[2],double *pRatio,long posBegin[2],long posStep[2], 
							   double minPower,double maxPower,double *pLimitPower,short channel=0);
GT_API GT_SetLaserCrdMap(short channel,short map);
GT_API GT_GetLaserCrdMap(short channel,short *pMap);

//////////////////////////////////////////////////////////////////////////
//AutoFocus
//////////////////////////////////////////////////////////////////////////
GT_API GT_AutoFocus(unsigned short mode,double kp,short reverse,short chanel);
GT_API GT_SetAutoFocusRefVol(double refVol,double maxVol,double minVol,short chanel);
GT_API GT_GetAutoFocusStatus(unsigned short *pStatus,short count);
GT_API GT_ConfigAutoFocus(short chnAdc,short chanel);
GT_API GT_SetAutoFocusAuxPrm(double kf,double kd,double limitKd,short chanel);
GT_API GT_SetAutoFocusDeadVoltage(double voltage,short chanel);

GT_API GT_Delay(unsigned short time);
GT_API GT_DelayHighPrecision(unsigned short time);

//////////////////////////////////////////////////////////////////////////
//Random Code
//////////////////////////////////////////////////////////////////////////
GT_API GT_SetRandCode(short addr,short *pData);
GT_API GT_GetRandCode(short addr,short *pData);

#define CRD_BUFFER_MODE_DYNAMIC_DEFAULT  (0)
#define CRD_BUFFER_MODE_DYNAMIC_KEEP     (1)

#define CRD_BUFFER_MODE_STATIC_INPUT     (11)
#define CRD_BUFFER_MODE_STATIC_READY     (12)
#define CRD_BUFFER_MODE_STATIC_START     (13)
GT_API GT_SetCrdBufferMode(short crd,short bufferMode,short fifo);
GT_API GT_GetCrdBufferMode(short crd,short *pBufferMode,short fifo);
GT_API GT_GetCrdSegmentTime(short crd,long segmentIndex,double *pSegmentTime,long *pSegmentNumber,short fifo);
GT_API GT_GetCrdTime(short crd,TCrdTime *pTime,short fifo);

GT_API GT_SetLeadScrewLink(short axis,short link);
GT_API GT_GetLeadScrewLink(short axis,short *pLink);


//////////////////////////////////////////////////////////////////////////
//Crd Follow
//////////////////////////////////////////////////////////////////////////
typedef struct  
{
	short crdAxis;
	short masterIndex;
	short masterType;
} TBufFollowMaster;

typedef struct  
{
	long masterPos;
	long pad;
} TBufFollowEventCross;

typedef struct  
{
	short triggerIndex;
	long triggerOffset;
	long pad;
} TBufFollowEventTrigger;


typedef struct  
{
	short stage;
	double slavePos;
	double slaveVel;
	unsigned long loopCount;
} TCrdFollowStatus;

typedef struct  
{
	double velRatioMax;
	double accRatioMax;
	long masterLead;
	long masterEven;
	long slaveEven;
	short dir;
	short smoothPercent;
	short synchAlign;
} TCrdFollowPrm;

GT_API GT_BufFollowMaster(short crd,TBufFollowMaster *pBufFollowMaster,short fifo=0);
GT_API GT_BufFollowEventCross(short crd,TBufFollowEventCross *pEventCross,short fifo=0);
GT_API GT_BufFollowEventTrigger(short crd,TBufFollowEventTrigger *pEventTrigger,short fifo=0);
GT_API GT_BufFollowStart(short crd,long masterSegment,long slaveSegment,long masterFrameWidth,short fifo=0);
GT_API GT_BufFollowReturn(short crd,double vel,double acc,short smoothPercent,short fifo=0);
GT_API GT_BufFollowNext(short crd,long width,short fifo=0);
GT_API GT_GetCrdFollowStatus(short crd,TCrdFollowStatus *pStatus);

GT_API GT_SetCrdFollowLoop(short crd,unsigned long loop);
GT_API GT_GetCrdFollowLoop(short crd,unsigned long *pLoop);
GT_API GT_SetCrdFollowPrm(short crd,TCrdFollowPrm *pPrm);
GT_API GT_GetCrdFollowPrm(short crd,TCrdFollowPrm *pPrm);

typedef struct  
{
	short source;
	short enable;
	short x;
	short y;
	double theta;		// degree
} TTransformOrthogonal;

GT_API GT_SetTransformOrthogonal(short index,TTransformOrthogonal *pOrthogonal);
GT_API GT_GetTransformOrthogonal(short index,TTransformOrthogonal *pOrthogonal);
GT_API GT_GetTransformOrthogonalPosition(short index,double *pPositionX,double *pPositionY);

typedef struct  
{
	short source;
	short enable;
	short x;
	short y;
	short z;
	double alpha;		// Z轴和XY平面的夹角
	double beta;		// Z轴在XY平面的投影和X轴的夹角
	double gama;		// XY轴之间的夹角
} TTransformPerpendicularity;

GT_API GT_SetTransformPerpendicularity(short index,TTransformPerpendicularity *pPerpendicularity);
GT_API GT_GetTransformPerpendicularity(short index,TTransformPerpendicularity *pPerpendicularity);
GT_API GT_GetTransformPerpendicularityPosition(short index,double *pPositionX,double *pPositionY,double *pPositionZ);

GT_API GT_SetLaserPwmDac(double pwmWidth,double frq,short *pDacValue,long count,short channel);
GT_API GT_LaserPwmDacOn(short channel);
GT_API GT_LaserPwmDacOff(short channel);

typedef struct
{
	short mode;
	short prm1;
	short prm2;
	short prm3;
	short prm4;
	double reserve1;
	double reserve2;
	double reserve3;
	double reserve4;

}TMotionSmooth;

GT_API GT_SetMotionSmooth(short axis,TMotionSmooth *pSmooth);
GT_API GT_GetMotionSmooth(short axis,TMotionSmooth *pSmooth);

typedef struct  
{
	short master[2];
	short masterValueSource[2];
	long gearRatioNumerator[2];
	long gearRatioDenominator[2];
} TCombineAxes;

typedef struct  
{
	short enable;
	double slavePos;
	double slaveVel;
} TCombineAxesStatus;

GT_API GT_SetCombineAxes(short index,TCombineAxes *pCombineAxes);
GT_API GT_GetCombineAxes(short index,TCombineAxes *pCombineAxes);
GT_API GT_CombineAxesOn(short index);
GT_API GT_CombineAxesOff(short index);
GT_API GT_GetCombineAxesStatus(short index,TCombineAxesStatus *pCombineAxesStatus);
GT_API GT_SetAxisAddition(short axis,short dataType,short additionIndex,short additionType);
GT_API GT_GetAxisAddition(short axis,short dataType,short *pAdditionIndex,short *pAdditionType);

GT_API GT_SetLeadScrewCrossComp(short axis,short n,long startPos,long lenPos,long *pCompPos,long *pCompNeg,short link);
GT_API GT_EnableLeadScrewCrossComp(short axis,short mode);

typedef enum 
{
	MC_POSITIVE_DIRECTION,
	MC_NEGATIVE_DIRECTION,
	MC_CURRENT_DIRECTION,
	MC_SHORTEST_WAY,
} EMcDirection;

typedef struct
{
	long pos;
	double vel;
	double acc;
	double dec;
	short percent;
} TMoveAbsolutePrm;

typedef struct
{
	long pos;
	double vel;
	double acc;
	double dec;
	short percent;
	double velStart;
	double velEnd;
	short accStartPercent;
	short decEndPercent;
} TMoveAbsolutePrmEx;

GT_API GT_MoveAbsolute(short profile,TMoveAbsolutePrm *pPrm);
GT_API GT_GetMoveAbsolute(short profile,TMoveAbsolutePrm *pPrm);
GT_API GT_MoveAbsoluteEx(short profile,TMoveAbsolutePrmEx *pPrm);
GT_API GT_GetMoveAbsoluteEx(short profile,TMoveAbsolutePrmEx *pPrm);

typedef struct
{
	double vel;
	double acc;
	double dec;
	double jerkBegin;
	double jerkEnd;
	short direction;
} TMoveVelocityPrm;

GT_API GT_MoveVelocity(short profile,TMoveVelocityPrm *pPrm);
GT_API GT_GetMoveVelocity(short profile,TMoveVelocityPrm *pPrm);


//////////////////////////////////////////////////////////////////////////
//Smart Cutter
//////////////////////////////////////////////////////////////////////////
typedef struct  
{
	short x;						// X轴对应的规划轴
	short y;						// Y轴对应的规划轴
	short c;						// C轴对应的规划轴

	short tableRadiusIndex;			// 半径补偿表索引
	short tableAngleIndex;			// C轴补偿表索引

	short directionReverse;			// 默认规划位置增大时角度也是增大的

	long offset;		            // C轴旋转角度为0时的规划位置
	long resolution;				// C轴每转脉冲数

	short adcIndex;					// ADC索引
	double adcThreshold;			// ADC触发补偿的阈值
} TSmartCutterPrm;

typedef struct  
{
	short enable;
	short execute;
	double radiusValue;
	double angleValue;
} TSmartCutterInfo;

GT_API GT_SetSmartCutterPrm(short index,TSmartCutterPrm *pPrm);
GT_API GT_GetSmartCutterPrm(short index,TSmartCutterPrm *pPrm);
GT_API GT_SmartCutterOn(short index);
GT_API GT_SmartCutterOff(short index);
GT_API GT_BufSmartCutterOn(short crd,short smartCutterIndex,short fifo=0);
GT_API GT_BufSmartCutterOff(short crd,short smartCutterIndex,short fifo=0);
GT_API GT_GetSmartCutterInfo(short index,TSmartCutterInfo *pInfo);

GT_API GT_SetSmartCutterValue(short index,double radiusValue,double angleValue);
GT_API GT_SmartCutterStart(short index);


//////////////////////////////////////////////////////////////////////////
//Gantry
//////////////////////////////////////////////////////////////////////////
#define GANTRY_MODE_NONE								(-1)
#define GANTRY_MODE_OPEN_LOOP_GANTRY					(1)
#define GANTRY_MODE_DECOUPLE_POSITION_LOOP				(2)

GT_API GT_SetGantryMode(short group,short master,short slave,short mode,long syncErrorLimit=1000);
GT_API GT_GetGantryMode(short group,short *pMaster,short *pSlave,short *pMode,long *pSyncErrorLimit);
GT_API GT_SetGantryPid(short group,TPid *pGantryPid,TPid *pYawPid);
GT_API GT_GetGantryPid(short group,TPid *pGantryPid,TPid *pYawPid);
GT_API GT_GantryAxisOn(short group);
GT_API GT_GantryAxisOff(short group);

GT_API GT_SetEncoderOutSelect(short mode);
GT_API GT_GetEncoderOutSelect(short *pMode);

//////////////////////////////////////////////////////////////////////////
//Standard Home
//////////////////////////////////////////////////////////////////////////

#define STANDARD_HOME_STAGE_IDLE  (0) //未启动回原点
#define STANDARD_HOME_STAGE_START (1) //启动回原点
#define STANDARD_HOME_STAGE_SEARCH_HOME (20) //正在搜索Home
#define STANDARD_HOME_STAGE_SEARCH_INDEX  (30) //正在搜索Index
#define STANDARD_HOME_STAGE_GO_HOME       (80) //正在运动到原点
#define STANDARD_HOME_STAGE_END           (100) //回原点结束
#define STANDARD_HOME_STAGE_START_CHECK (-1) //启动回原点前自检
#define STANDARD_HOME_STAGE_CHECKING (-2) //自检中


#define STANDARD_HOME_ERROR_NONE		(0) //未发生错误
#define STANDARD_HOME_ERROR_DISABLE	(10) //执行回原点的轴未使能
#define STANDARD_HOME_ERROR_ALARM		(20) //执行回原点的轴报警
#define STANDARD_HOME_ERROR_STOP		(30) //未完成回原点，被停止运动
#define STANDARD_HOME_ERROR_ON_LIMIT   (40) //触发了限位无法继续
#define STANDARD_HOME_ERROR_NO_HOME	(50) //未找到Home
#define STANDARD_HOME_ERROR_NO_INDEX  (60) //未找到Index
#define STANDARD_HOME_ERROR_NO_LIMIT (70) //未找到限位
#define STANDARD_HOME_ERROR_ENCODER_DIR_SCALE (-1) //规划器与编码器方向方向相反或者当量不一致


typedef struct  
{
	short mode;		 // 回原点模式取值范围1~36
	double highSpeed; // 搜索Home的速度，单位pulse/ms
	double lowSpeed;	 // 搜索Index的速度，单位pulse/ms
	double acc;		 // 回零加速度，单位pulse/ms^2
	long offset;       // 回零偏移量，单位pulse
	short check; // 是否启用自检功能，1-启用，其它值-不启用
	short autoZeroPos; // 回零完毕是否自动清零，1-自动清零，其它值-不清零
	long motorStopDelay; //电机到位延时，单位：控制周期
	short pad1[3];	 // 保留（不需要设置）
} TStandardHomePrm;

typedef struct  
{
	short run;     // 是正在进行回原点，0—已停止运动，1-正在回原点
	short stage;   // 回原点运动的阶段
	short error;    // 回原点过程的发生的错误
	short pad1[3];       // 保留（无具体含义）
	long capturePos;  // 捕获到Home或Index时刻的编码器位置
	long targetPos;    // 需要运动到的目标位置（原点位置或者原点位置+偏移量），在搜索Limit时或者搜索Home或Index时，设置的搜索距离为0，那么该值显示为805306368
} TStandardHomeStatus;

GT_API GT_ExecuteStandardHome(short axis,TStandardHomePrm *pHomePrm);
GT_API GT_GetStandardHomePrm(short axis,TStandardHomePrm *pHomePrm);
GT_API GT_GetStandardHomeStatus(short axis,TStandardHomeStatus *pHomeStatus);

typedef struct  
{
	short year;
	short month;
	short day;
	short version;
	short user;
	short reserve1;
	short reserve2;
	short chip;
} TVersion;

GT_API GT_GetVersionEx(short type,TVersion *pVersion);

GT_API GT_CrdHsOn(short crd,short fifo,short link=1,unsigned short threshold=200,short lookAheadInMc=0);
GT_API GT_CrdHsOff(short crd,short fifo);

#define AUTO_HOME_MODE_HOME (1)
#define AUTO_HOME_MODE_HOME_INDEX (2)
#define AUTO_HOME_MODE_HOME_STOP (3)

typedef struct
{
	short mode;
	double homeSearchVel;
	double acc;
	long homeSearchDis;
	long indexSearchDis;
	long homeReturnOffset;
	long indexReturnOffest;
}TAutoHomePrm;

typedef struct
{
	short run;
	short stage;
	short result;
	long capturePos;
	long targetPos;
}TAutoHomeStatus;

GT_API GT_CheckPciCommandFlag(short *pFlag);
GT_API GT_ResetPciCommandFlag();