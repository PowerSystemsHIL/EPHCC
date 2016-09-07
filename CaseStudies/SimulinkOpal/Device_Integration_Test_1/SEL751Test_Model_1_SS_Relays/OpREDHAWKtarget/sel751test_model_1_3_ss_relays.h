/*
 * sel751test_model_1_3_ss_relays.h
 *
 * Code generation for model "sel751test_model_1_3_ss_relays".
 *
 * Model version              : 1.2540
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Tue Aug 23 08:04:55 2016
 *
 * Target selection: rtlab_rtmodel.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_sel751test_model_1_3_ss_relays_h_
#define RTW_HEADER_sel751test_model_1_3_ss_relays_h_
#ifndef sel751test_model_1_3_ss_relays_COMMON_INCLUDES_
# define sel751test_model_1_3_ss_relays_COMMON_INCLUDES_
#include <math.h>
#include <stddef.h>
#include <float.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#endif                                 /* sel751test_model_1_3_ss_relays_COMMON_INCLUDES_ */

#include "sel751test_model_1_3_ss_relays_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->ModelData.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->ModelData.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) 0
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define sel751test_model_1_3_ss_relays_rtModel RT_MODEL_sel751test_model_1_3_ss_relays_T

/* user code (top of header file) */
/* System '<Root>' */
/* Opal-RT Technologies */
extern int opalSizeDwork;
extern int opalSizeBlockIO;
extern int opalSizeRTP;

#ifdef USE_RTMODEL

extern void * pRtModel;                //pointer on the RTmodel struc
int_T Opal_rtmGetNumBlockParams(void *ptr);
int_T Opal_rtmGetNumBlockIO(void *ptr);

#endif

/* Block signals for system '<S19>/deadbus fcn' */
typedef struct {
  boolean_T y;                         /* '<S19>/deadbus fcn' */
} B_deadbusfcn_sel751test_model_T;

/* Block signals for system '<S23>/Relays' */
typedef struct {
  boolean_T trip50;                    /* '<S23>/Relays' */
  boolean_T trip51;                    /* '<S23>/Relays' */
  boolean_T trip27;                    /* '<S23>/Relays' */
  boolean_T trip59;                    /* '<S23>/Relays' */
} B_Relays_sel751test_model_1_3_T;

/* Block states (auto storage) for system '<S23>/Relays' */
typedef struct {
  real_T n50;                          /* '<S23>/Relays' */
  real_T n51;                          /* '<S23>/Relays' */
  real_T n27;                          /* '<S23>/Relays' */
  real_T n59;                          /* '<S23>/Relays' */
  boolean_T R50;                       /* '<S23>/Relays' */
  boolean_T R51;                       /* '<S23>/Relays' */
  boolean_T R51_not_empty;             /* '<S23>/Relays' */
  boolean_T R27;                       /* '<S23>/Relays' */
  boolean_T R59;                       /* '<S23>/Relays' */
} DW_Relays_sel751test_model_1__T;

/* Block signals for system '<S5>/trip_out mng' */
typedef struct {
  real_T trip_out;                     /* '<S5>/trip_out mng' */
} B_trip_outmng_sel751test_mode_T;

/* Block states (auto storage) for system '<S5>/trip_out mng' */
typedef struct {
  real_T n25;                          /* '<S5>/trip_out mng' */
  real_T prev_mode;                    /* '<S5>/trip_out mng' */
  real_T prev_trip_in;                 /* '<S5>/trip_out mng' */
} DW_trip_outmng_sel751test_mod_T;

/* Block signals (auto storage) */
typedef struct {
  real_T SFunction;                    /* '<S2>/S-Function' */
  real_T Sum;                          /* '<S2>/Sum' */
  real_T op_mode;                      /* '<S5>/Memory1' */
  real_T Logic_trip;                   /* '<S5>/Memory8' */
  real_T Iabc[3];                      /* '<S5>/Memory3' */
  real_T Vabc[3];                      /* '<S5>/Memory3' */
  real_T P;                            /* '<S5>/Memory3' */
  real_T Q;                            /* '<S5>/Memory3' */
  real_T freq;                         /* '<S5>/Memory3' */
  real_T Va_rms;                       /* '<S5>/Memory3' */
  real_T pf;                           /* '<S5>/Memory3' */
  real_T Vpu;                          /* '<S5>/Memory3' */
  real_T status;                       /* '<S5>/Memory3' */
  real_T pf_states;                    /* '<S5>/Memory3' */
  real_T op_mode_d;                    /* '<S6>/Memory1' */
  real_T Logic_trip_h;                 /* '<S6>/Memory8' */
  real_T Iabc_b[3];                    /* '<S6>/Memory3' */
  real_T Vabc_n[3];                    /* '<S6>/Memory3' */
  real_T P_a;                          /* '<S6>/Memory3' */
  real_T Q_j;                          /* '<S6>/Memory3' */
  real_T freq_m;                       /* '<S6>/Memory3' */
  real_T Va_rms_o;                     /* '<S6>/Memory3' */
  real_T pf_b;                         /* '<S6>/Memory3' */
  real_T Vpu_h;                        /* '<S6>/Memory3' */
  real_T status_f;                     /* '<S6>/Memory3' */
  real_T pf_states_i;                  /* '<S6>/Memory3' */
  real_T SFunction_l[23];              /* '<S199>/S-Function' */
  real_T Divide1[3];                   /* '<S5>/Divide1' */
  real_T DiscreteTimeIntegrator;       /* '<S10>/Discrete-Time Integrator' */
  real_T MathFunction;                 /* '<S10>/Math Function' */
  real_T TrigonometricFunction;        /* '<S10>/Trigonometric Function' */
  real_T TrigonometricFunction2;       /* '<S10>/Trigonometric Function2' */
  real_T Product;                      /* '<S29>/Product' */
  real_T Product1;                     /* '<S29>/Product1' */
  real_T sinwt2pi3;                    /* '<S29>/Sum' */
  real_T Product3;                     /* '<S29>/Product3' */
  real_T Product2;                     /* '<S29>/Product2' */
  real_T coswt2pi3;                    /* '<S29>/Sum1' */
  real_T sinwt2pi3_i;                  /* '<S29>/Sum2' */
  real_T coswt2pi3_k;                  /* '<S29>/Sum3' */
  real_T Vq;                           /* '<S29>/Fcn1' */
  real_T Integ4;                       /* '<S28>/Integ4' */
  real_T SFunction_e;                  /* '<S31>/S-Function ' */
  real_T UnitDelay;                    /* '<S28>/Unit Delay' */
  real_T Step;                         /* '<S28>/Step' */
  real_T Switch;                       /* '<S28>/Switch' */
  real_T Kp4;                          /* '<S26>/Kp4' */
  real_T DiscreteTimeIntegrator_k;     /* '<S26>/Discrete-Time Integrator' */
  real_T Kp6;                          /* '<S26>/Kp6' */
  real_T ZeroOrderHold;                /* '<S26>/Zero-Order Hold' */
  real_T TSamp;                        /* '<S30>/TSamp' */
  real_T Uk1;                          /* '<S30>/UD' */
  real_T Diff;                         /* '<S30>/Diff' */
  real_T Sum6;                         /* '<S26>/Sum6' */
  real_T Saturation2;                  /* '<S26>/Saturation2' */
  real_T Gain10;                       /* '<S10>/Gain10' */
  real_T y1;                           /* '<S27>/Unit  Delay' */
  real_T Sum1;                         /* '<S27>/Sum1' */
  real_T Deltau_limit;                 /* '<S27>/Saturation' */
  real_T y;                            /* '<S27>/Sum' */
  real_T DiscreteStateSpace;           /* '<S25>/Discrete State-Space' */
  real_T Kp5;                          /* '<S26>/Kp5' */
  real_T UnitDelay_e;                  /* '<S10>/Unit Delay' */
  real_T Vd;                           /* '<S29>/Fcn2' */
  real_T Sum4;                         /* '<S29>/Sum4' */
  real_T Gain1;                        /* '<S29>/Gain1' */
  real_T Gain21;                       /* '<S5>/Gain21' */
  real_T Divide[3];                    /* '<S5>/Divide' */
  real_T DiscreteTimeIntegrator_m;     /* '<S11>/Discrete-Time Integrator' */
  real_T MathFunction_i;               /* '<S11>/Math Function' */
  real_T TrigonometricFunction_j;      /* '<S11>/Trigonometric Function' */
  real_T TrigonometricFunction2_n;     /* '<S11>/Trigonometric Function2' */
  real_T Product_m;                    /* '<S36>/Product' */
  real_T Product1_o;                   /* '<S36>/Product1' */
  real_T sinwt2pi3_g;                  /* '<S36>/Sum' */
  real_T Product3_o;                   /* '<S36>/Product3' */
  real_T Product2_e;                   /* '<S36>/Product2' */
  real_T coswt2pi3_g;                  /* '<S36>/Sum1' */
  real_T sinwt2pi3_n;                  /* '<S36>/Sum2' */
  real_T coswt2pi3_j;                  /* '<S36>/Sum3' */
  real_T Vq_i;                         /* '<S36>/Fcn1' */
  real_T Integ4_j;                     /* '<S35>/Integ4' */
  real_T SFunction_f;                  /* '<S38>/S-Function ' */
  real_T UnitDelay_c;                  /* '<S35>/Unit Delay' */
  real_T Step_i;                       /* '<S35>/Step' */
  real_T Switch_k;                     /* '<S35>/Switch' */
  real_T Kp4_k;                        /* '<S33>/Kp4' */
  real_T DiscreteTimeIntegrator_kv;    /* '<S33>/Discrete-Time Integrator' */
  real_T Kp6_c;                        /* '<S33>/Kp6' */
  real_T ZeroOrderHold_e;              /* '<S33>/Zero-Order Hold' */
  real_T TSamp_c;                      /* '<S37>/TSamp' */
  real_T Uk1_c;                        /* '<S37>/UD' */
  real_T Diff_d;                       /* '<S37>/Diff' */
  real_T Sum6_b;                       /* '<S33>/Sum6' */
  real_T Saturation2_a;                /* '<S33>/Saturation2' */
  real_T Gain10_p;                     /* '<S11>/Gain10' */
  real_T y1_c;                         /* '<S34>/Unit  Delay' */
  real_T Sum1_e;                       /* '<S34>/Sum1' */
  real_T Deltau_limit_j;               /* '<S34>/Saturation' */
  real_T y_g;                          /* '<S34>/Sum' */
  real_T DiscreteStateSpace_d;         /* '<S32>/Discrete State-Space' */
  real_T Kp5_l;                        /* '<S33>/Kp5' */
  real_T UnitDelay_j;                  /* '<S11>/Unit Delay' */
  real_T Vd_g;                         /* '<S36>/Fcn2' */
  real_T Sum4_h;                       /* '<S36>/Sum4' */
  real_T Gain1_p;                      /* '<S36>/Gain1' */
  real_T Product1_k[3];                /* '<S48>/Product1' */
  real_T P_i;                          /* '<S48>/Sum4' */
  real_T Sum5;                         /* '<S48>/Sum5' */
  real_T Sum6_m;                       /* '<S48>/Sum6' */
  real_T Sum_d;                        /* '<S48>/Sum' */
  real_T Product3_g[3];                /* '<S48>/Product3' */
  real_T Sum1_c;                       /* '<S48>/Sum1' */
  real_T Q_b;                          /* '<S48>/pu->V' */
  real_T Integ4_c[2];                  /* '<S49>/Integ4' */
  real_T SFunction_ek[2];              /* '<S50>/S-Function ' */
  real_T UnitDelay_n[2];               /* '<S49>/Unit Delay' */
  real_T Step_l;                       /* '<S49>/Step' */
  real_T Switch_kt[2];                 /* '<S49>/Switch' */
  real_T Abs;                          /* '<S12>/Abs' */
  real_T Abs1;                         /* '<S12>/Abs1' */
  real_T Abs2;                         /* '<S12>/Abs2' */
  real_T Fcn;                          /* '<S12>/Fcn' */
  real_T Divide2;                      /* '<S12>/Divide2' */
  real_T FixPtUnitDelay1;              /* '<S43>/FixPt Unit Delay1' */
  real_T Xnew;                         /* '<S43>/Enable' */
  real_T DigitalClock;                 /* '<S5>/Digital Clock' */
  real_T SFunction_o[6];               /* '<S192>/S-Function' */
  real_T DataTypeConversion3;          /* '<S23>/Data Type Conversion3' */
  real_T Product3_c[3];                /* '<S17>/Product3' */
  real_T Integ4_ct[3];                 /* '<S51>/Integ4' */
  real_T SFunction_p[3];               /* '<S52>/S-Function ' */
  real_T UnitDelay_b[3];               /* '<S51>/Unit Delay' */
  real_T Step_j;                       /* '<S51>/Step' */
  real_T Switch_i[3];                  /* '<S51>/Switch' */
  real_T SignedSqrt[3];                /* '<S17>/Signed Sqrt' */
  real_T Product3_h[3];                /* '<S18>/Product3' */
  real_T Integ4_d[3];                  /* '<S53>/Integ4' */
  real_T SFunction_b[3];               /* '<S54>/S-Function ' */
  real_T UnitDelay_cs[3];              /* '<S53>/Unit Delay' */
  real_T Step_k;                       /* '<S53>/Step' */
  real_T Switch_e[3];                  /* '<S53>/Switch' */
  real_T SignedSqrt_k[3];              /* '<S18>/Signed Sqrt' */
  real_T Gain;                         /* '<S23>/Gain' */
  real_T Switch_a[7];                  /* '<S20>/Switch' */
  real_T trip_in;                      /* '<S5>/Data Type Conversion1' */
  real_T DataTypeConversion2;          /* '<S5>/Data Type Conversion2' */
  real_T DataTypeConversion4[4];       /* '<S5>/Data Type Conversion4' */
  real_T Gain2;                        /* '<S5>/Gain2' */
  real_T Vpu_hv;                       /* '<S5>/Divide2' */
  real_T Gain_p;                       /* '<S5>/Gain' */
  real_T Gain1_a;                      /* '<S5>/Gain1' */
  real_T Gain10_k;                     /* '<S5>/Gain10' */
  real_T Add2;                         /* '<S16>/Add2' */
  real_T MathFunction_e;               /* '<S16>/Math Function' */
  real_T Gain11;                       /* '<S5>/Gain11' */
  real_T Gain12;                       /* '<S5>/Gain12' */
  real_T Gain13;                       /* '<S5>/Gain13' */
  real_T Gain14;                       /* '<S5>/Gain14' */
  real_T Gain15;                       /* '<S5>/Gain15' */
  real_T Gain16;                       /* '<S5>/Gain16' */
  real_T Gain17;                       /* '<S5>/Gain17' */
  real_T Gain18;                       /* '<S5>/Gain18' */
  real_T Gain19;                       /* '<S5>/Gain19' */
  real_T Gain20;                       /* '<S5>/Gain20' */
  real_T Add3;                         /* '<S15>/Add3' */
  real_T MathFunction1;                /* '<S15>/Math Function1' */
  real_T Gain3;                        /* '<S5>/Gain3' */
  real_T Gain4;                        /* '<S5>/Gain4' */
  real_T Add2_h;                       /* '<S15>/Add2' */
  real_T MathFunction_g;               /* '<S15>/Math Function' */
  real_T Gain5;                        /* '<S5>/Gain5' */
  real_T Gain6;                        /* '<S5>/Gain6' */
  real_T Gain7;                        /* '<S5>/Gain7' */
  real_T Gain8;                        /* '<S5>/Gain8' */
  real_T Add3_h;                       /* '<S16>/Add3' */
  real_T MathFunction1_g;              /* '<S16>/Math Function1' */
  real_T Gain9;                        /* '<S5>/Gain9' */
  real_T Uk1_a;                        /* '<S46>/Delay Input1' */
  real_T Product3_oh[2];               /* '<S57>/Product3' */
  real_T Integ4_m[2];                  /* '<S63>/Integ4' */
  real_T SFunction_i[2];               /* '<S64>/S-Function ' */
  real_T UnitDelay_g[2];               /* '<S63>/Unit Delay' */
  real_T Step_g;                       /* '<S63>/Step' */
  real_T Switch_p[2];                  /* '<S63>/Switch' */
  real_T SignedSqrt_a[2];              /* '<S57>/Signed Sqrt' */
  real_T sqrt3[2];                     /* '<S19>/sqrt3' */
  real_T Fcn_e;                        /* '<S19>/Fcn' */
  real_T Product_k;                    /* '<S59>/Product' */
  real_T thshld;                       /* '<S59>/Fcn2' */
  real_T UnitDelay_jh;                 /* '<S66>/Unit Delay' */
  real_T UnitDelay_d;                  /* '<S65>/Unit Delay' */
  real_T Fcn2;                         /* '<S55>/Fcn2' */
  real_T DiscreteTimeIntegrator_f;     /* '<S66>/Discrete-Time Integrator' */
  real_T MathFunction_p;               /* '<S66>/Math Function' */
  real_T DiscreteTimeIntegrator_o;     /* '<S65>/Discrete-Time Integrator' */
  real_T MathFunction_d;               /* '<S65>/Math Function' */
  real_T TmpSignalConversionAtMathFuncti[2];
  real_T MathFunction_n[2];            /* '<S56>/Math Function' */
  real_T Unwrap[2];                    /* '<S56>/Unwrap' */
  real_T diff;                         /* '<S56>/Fcn3' */
  real_T Gain_a;                       /* '<S62>/Gain' */
  real_T bool_k;                       /* '<S56>/Fcn1' */
  real_T Logic_out;                    /* '<S13>/Switch' */
  real_T Memory2;                      /* '<S5>/Memory2' */
  real_T Memory9;                      /* '<S5>/Memory9' */
  real_T Divide_a;                     /* '<S61>/Divide' */
  real_T TrigonometricFunction2_o;     /* '<S65>/Trigonometric Function2' */
  real_T Vq_b;                         /* '<S65>/Product1' */
  real_T Integ4_e;                     /* '<S71>/Integ4' */
  real_T Freq;                         /* '<S71>/To avoid division by zero' */
  real_T Numberofsamplespercycle;      /* '<S71>/Number of samples per cycle' */
  real_T RoundingFunction;             /* '<S71>/Rounding Function' */
  real_T Delay;                        /* '<S71>/Gain' */
  real_T SFunction_j;                  /* '<S82>/S-Function ' */
  real_T UnitDelay_o;                  /* '<S81>/Unit Delay' */
  real_T Step_p;                       /* '<S71>/Step' */
  real_T Switch_f;                     /* '<S71>/Switch' */
  real_T TrigonometricFunction_h;      /* '<S65>/Trigonometric Function' */
  real_T Divide_n;                     /* '<S65>/Divide' */
  real_T Kp4_d;                        /* '<S69>/Kp4' */
  real_T DiscreteTimeIntegrator_d;     /* '<S69>/Discrete-Time Integrator' */
  real_T Kp6_n;                        /* '<S69>/Kp6' */
  real_T ZeroOrderHold_m;              /* '<S69>/Zero-Order Hold' */
  real_T TSamp_b;                      /* '<S80>/TSamp' */
  real_T Uk1_ck;                       /* '<S80>/UD' */
  real_T Diff_l;                       /* '<S80>/Diff' */
  real_T Sum6_a;                       /* '<S69>/Sum6' */
  real_T Saturation2_m;                /* '<S69>/Saturation2' */
  real_T Gain10_c;                     /* '<S65>/Gain10' */
  real_T y1_a;                         /* '<S70>/Unit  Delay' */
  real_T Sum1_a;                       /* '<S70>/Sum1' */
  real_T Deltau_limit_d;               /* '<S70>/Saturation' */
  real_T y_o;                          /* '<S70>/Sum' */
  real_T DiscreteStateSpace_m;         /* '<S67>/Discrete State-Space' */
  real_T Kp5_k;                        /* '<S69>/Kp5' */
  real_T Divide1_g;                    /* '<S61>/Divide1' */
  real_T TrigonometricFunction2_b;     /* '<S66>/Trigonometric Function2' */
  real_T Vq_n;                         /* '<S66>/Product1' */
  real_T Integ4_mb;                    /* '<S87>/Integ4' */
  real_T Freq_n;                       /* '<S87>/To avoid division by zero' */
  real_T Numberofsamplespercycle_a;    /* '<S87>/Number of samples per cycle' */
  real_T RoundingFunction_i;           /* '<S87>/Rounding Function' */
  real_T Delay_d;                      /* '<S87>/Gain' */
  real_T SFunction_n;                  /* '<S98>/S-Function ' */
  real_T UnitDelay_m;                  /* '<S97>/Unit Delay' */
  real_T Step_k5;                      /* '<S87>/Step' */
  real_T Switch_pm;                    /* '<S87>/Switch' */
  real_T TrigonometricFunction_c;      /* '<S66>/Trigonometric Function' */
  real_T Divide_h;                     /* '<S66>/Divide' */
  real_T Kp4_l;                        /* '<S85>/Kp4' */
  real_T DiscreteTimeIntegrator_c;     /* '<S85>/Discrete-Time Integrator' */
  real_T Kp6_k;                        /* '<S85>/Kp6' */
  real_T ZeroOrderHold_j;              /* '<S85>/Zero-Order Hold' */
  real_T TSamp_m;                      /* '<S96>/TSamp' */
  real_T Uk1_k;                        /* '<S96>/UD' */
  real_T Diff_p;                       /* '<S96>/Diff' */
  real_T Sum6_a0;                      /* '<S85>/Sum6' */
  real_T Saturation2_j;                /* '<S85>/Saturation2' */
  real_T Gain10_i;                     /* '<S66>/Gain10' */
  real_T y1_f;                         /* '<S86>/Unit  Delay' */
  real_T Sum1_n;                       /* '<S86>/Sum1' */
  real_T Deltau_limit_b;               /* '<S86>/Saturation' */
  real_T y_k;                          /* '<S86>/Sum' */
  real_T DiscreteStateSpace_n;         /* '<S83>/Discrete State-Space' */
  real_T Kp5_m;                        /* '<S85>/Kp5' */
  real_T Sum_o;                        /* '<S5>/Sum' */
  real_T Sum1_i;                       /* '<S5>/Sum1' */
  real_T DataTypeConversion1;          /* '<S21>/Data Type Conversion1' */
  real_T DataTypeConversion1_g;        /* '<S22>/Data Type Conversion1' */
  real_T Divide1_i[3];                 /* '<S6>/Divide1' */
  real_T DiscreteTimeIntegrator_g;     /* '<S101>/Discrete-Time Integrator' */
  real_T MathFunction_nc;              /* '<S101>/Math Function' */
  real_T TrigonometricFunction_jk;     /* '<S101>/Trigonometric Function' */
  real_T TrigonometricFunction2_f;     /* '<S101>/Trigonometric Function2' */
  real_T Product_e;                    /* '<S120>/Product' */
  real_T Product1_g;                   /* '<S120>/Product1' */
  real_T sinwt2pi3_g2;                 /* '<S120>/Sum' */
  real_T Product3_m;                   /* '<S120>/Product3' */
  real_T Product2_l;                   /* '<S120>/Product2' */
  real_T coswt2pi3_h;                  /* '<S120>/Sum1' */
  real_T sinwt2pi3_d;                  /* '<S120>/Sum2' */
  real_T coswt2pi3_l;                  /* '<S120>/Sum3' */
  real_T Vq_j;                         /* '<S120>/Fcn1' */
  real_T Integ4_jt;                    /* '<S119>/Integ4' */
  real_T SFunction_h;                  /* '<S122>/S-Function ' */
  real_T UnitDelay_nr;                 /* '<S119>/Unit Delay' */
  real_T Step_jv;                      /* '<S119>/Step' */
  real_T Switch_j;                     /* '<S119>/Switch' */
  real_T Kp4_dr;                       /* '<S117>/Kp4' */
  real_T DiscreteTimeIntegrator_i;     /* '<S117>/Discrete-Time Integrator' */
  real_T Kp6_o;                        /* '<S117>/Kp6' */
  real_T ZeroOrderHold_h;              /* '<S117>/Zero-Order Hold' */
  real_T TSamp_e;                      /* '<S121>/TSamp' */
  real_T Uk1_i;                        /* '<S121>/UD' */
  real_T Diff_b;                       /* '<S121>/Diff' */
  real_T Sum6_g;                       /* '<S117>/Sum6' */
  real_T Saturation2_d;                /* '<S117>/Saturation2' */
  real_T Gain10_d;                     /* '<S101>/Gain10' */
  real_T y1_p;                         /* '<S118>/Unit  Delay' */
  real_T Sum1_k;                       /* '<S118>/Sum1' */
  real_T Deltau_limit_c;               /* '<S118>/Saturation' */
  real_T y_gn;                         /* '<S118>/Sum' */
  real_T DiscreteStateSpace_mz;        /* '<S116>/Discrete State-Space' */
  real_T Kp5_g;                        /* '<S117>/Kp5' */
  real_T UnitDelay_b3;                 /* '<S101>/Unit Delay' */
  real_T Vd_n;                         /* '<S120>/Fcn2' */
  real_T Sum4_k;                       /* '<S120>/Sum4' */
  real_T Gain1_m;                      /* '<S120>/Gain1' */
  real_T Gain21_o;                     /* '<S6>/Gain21' */
  real_T Divide_o[3];                  /* '<S6>/Divide' */
  real_T DiscreteTimeIntegrator_p;     /* '<S102>/Discrete-Time Integrator' */
  real_T MathFunction_k;               /* '<S102>/Math Function' */
  real_T TrigonometricFunction_a;      /* '<S102>/Trigonometric Function' */
  real_T TrigonometricFunction2_d;     /* '<S102>/Trigonometric Function2' */
  real_T Product_j;                    /* '<S127>/Product' */
  real_T Product1_m;                   /* '<S127>/Product1' */
  real_T sinwt2pi3_dr;                 /* '<S127>/Sum' */
  real_T Product3_j;                   /* '<S127>/Product3' */
  real_T Product2_li;                  /* '<S127>/Product2' */
  real_T coswt2pi3_i;                  /* '<S127>/Sum1' */
  real_T sinwt2pi3_na;                 /* '<S127>/Sum2' */
  real_T coswt2pi3_m;                  /* '<S127>/Sum3' */
  real_T Vq_f;                         /* '<S127>/Fcn1' */
  real_T Integ4_l;                     /* '<S126>/Integ4' */
  real_T SFunction_oy;                 /* '<S129>/S-Function ' */
  real_T UnitDelay_i;                  /* '<S126>/Unit Delay' */
  real_T Step_c;                       /* '<S126>/Step' */
  real_T Switch_fw;                    /* '<S126>/Switch' */
  real_T Kp4_o;                        /* '<S124>/Kp4' */
  real_T DiscreteTimeIntegrator_i2;    /* '<S124>/Discrete-Time Integrator' */
  real_T Kp6_i;                        /* '<S124>/Kp6' */
  real_T ZeroOrderHold_l;              /* '<S124>/Zero-Order Hold' */
  real_T TSamp_d;                      /* '<S128>/TSamp' */
  real_T Uk1_e;                        /* '<S128>/UD' */
  real_T Diff_lk;                      /* '<S128>/Diff' */
  real_T Sum6_n;                       /* '<S124>/Sum6' */
  real_T Saturation2_k;                /* '<S124>/Saturation2' */
  real_T Gain10_b;                     /* '<S102>/Gain10' */
  real_T y1_b;                         /* '<S125>/Unit  Delay' */
  real_T Sum1_o;                       /* '<S125>/Sum1' */
  real_T Deltau_limit_m;               /* '<S125>/Saturation' */
  real_T y_h;                          /* '<S125>/Sum' */
  real_T DiscreteStateSpace_mi;        /* '<S123>/Discrete State-Space' */
  real_T Kp5_a;                        /* '<S124>/Kp5' */
  real_T UnitDelay_k;                  /* '<S102>/Unit Delay' */
  real_T Vd_i;                         /* '<S127>/Fcn2' */
  real_T Sum4_a;                       /* '<S127>/Sum4' */
  real_T Gain1_mg;                     /* '<S127>/Gain1' */
  real_T Product1_n[3];                /* '<S139>/Product1' */
  real_T P_j;                          /* '<S139>/Sum4' */
  real_T Sum5_e;                       /* '<S139>/Sum5' */
  real_T Sum6_bc;                      /* '<S139>/Sum6' */
  real_T Sum_l;                        /* '<S139>/Sum' */
  real_T Product3_cj[3];               /* '<S139>/Product3' */
  real_T Sum1_ei;                      /* '<S139>/Sum1' */
  real_T Q_f;                          /* '<S139>/pu->V' */
  real_T Integ4_b[2];                  /* '<S140>/Integ4' */
  real_T SFunction_j1[2];              /* '<S141>/S-Function ' */
  real_T UnitDelay_cx[2];              /* '<S140>/Unit Delay' */
  real_T Step_n;                       /* '<S140>/Step' */
  real_T Switch_m[2];                  /* '<S140>/Switch' */
  real_T Abs_f;                        /* '<S103>/Abs' */
  real_T Abs1_h;                       /* '<S103>/Abs1' */
  real_T Abs2_l;                       /* '<S103>/Abs2' */
  real_T Fcn_p;                        /* '<S103>/Fcn' */
  real_T Divide2_f;                    /* '<S103>/Divide2' */
  real_T FixPtUnitDelay1_a;            /* '<S134>/FixPt Unit Delay1' */
  real_T Xnew_h;                       /* '<S134>/Enable' */
  real_T DigitalClock_p;               /* '<S6>/Digital Clock' */
  real_T DataTypeConversion3_l;        /* '<S114>/Data Type Conversion3' */
  real_T Product3_d[3];                /* '<S108>/Product3' */
  real_T Integ4_ja[3];                 /* '<S142>/Integ4' */
  real_T SFunction_m[3];               /* '<S143>/S-Function ' */
  real_T UnitDelay_i2[3];              /* '<S142>/Unit Delay' */
  real_T Step_ip;                      /* '<S142>/Step' */
  real_T Switch_c[3];                  /* '<S142>/Switch' */
  real_T SignedSqrt_p[3];              /* '<S108>/Signed Sqrt' */
  real_T Product3_b[3];                /* '<S109>/Product3' */
  real_T Integ4_cl[3];                 /* '<S144>/Integ4' */
  real_T SFunction_of[3];              /* '<S145>/S-Function ' */
  real_T UnitDelay_cn[3];              /* '<S144>/Unit Delay' */
  real_T Step_j4;                      /* '<S144>/Step' */
  real_T Switch_as[3];                 /* '<S144>/Switch' */
  real_T SignedSqrt_d[3];              /* '<S109>/Signed Sqrt' */
  real_T Gain_m;                       /* '<S114>/Gain' */
  real_T Switch_d[7];                  /* '<S111>/Switch' */
  real_T trip_in_n;                    /* '<S6>/Data Type Conversion1' */
  real_T DataTypeConversion2_p;        /* '<S6>/Data Type Conversion2' */
  real_T DataTypeConversion4_e[4];     /* '<S6>/Data Type Conversion4' */
  real_T Gain2_m;                      /* '<S6>/Gain2' */
  real_T Vpu_n;                        /* '<S6>/Divide2' */
  real_T Gain_d;                       /* '<S6>/Gain' */
  real_T Gain1_az;                     /* '<S6>/Gain1' */
  real_T Gain10_dl;                    /* '<S6>/Gain10' */
  real_T Add2_j;                       /* '<S107>/Add2' */
  real_T MathFunction_b;               /* '<S107>/Math Function' */
  real_T Gain11_e;                     /* '<S6>/Gain11' */
  real_T Gain12_j;                     /* '<S6>/Gain12' */
  real_T Gain13_o;                     /* '<S6>/Gain13' */
  real_T Gain14_f;                     /* '<S6>/Gain14' */
  real_T Gain15_a;                     /* '<S6>/Gain15' */
  real_T Gain16_j;                     /* '<S6>/Gain16' */
  real_T Gain17_l;                     /* '<S6>/Gain17' */
  real_T Gain18_d;                     /* '<S6>/Gain18' */
  real_T Gain19_g;                     /* '<S6>/Gain19' */
  real_T Gain20_m;                     /* '<S6>/Gain20' */
  real_T Add3_i;                       /* '<S106>/Add3' */
  real_T MathFunction1_b;              /* '<S106>/Math Function1' */
  real_T Gain3_d;                      /* '<S6>/Gain3' */
  real_T Gain4_h;                      /* '<S6>/Gain4' */
  real_T Add2_l;                       /* '<S106>/Add2' */
  real_T MathFunction_dh;              /* '<S106>/Math Function' */
  real_T Gain5_n;                      /* '<S6>/Gain5' */
  real_T Gain6_p;                      /* '<S6>/Gain6' */
  real_T Gain7_l;                      /* '<S6>/Gain7' */
  real_T Gain8_p;                      /* '<S6>/Gain8' */
  real_T Add3_f;                       /* '<S107>/Add3' */
  real_T MathFunction1_gd;             /* '<S107>/Math Function1' */
  real_T Gain9_p;                      /* '<S6>/Gain9' */
  real_T Uk1_l;                        /* '<S137>/Delay Input1' */
  real_T Product3_f[2];                /* '<S148>/Product3' */
  real_T Integ4_ef[2];                 /* '<S154>/Integ4' */
  real_T SFunction_li[2];              /* '<S155>/S-Function ' */
  real_T UnitDelay_ny[2];              /* '<S154>/Unit Delay' */
  real_T Step_px;                      /* '<S154>/Step' */
  real_T Switch_h[2];                  /* '<S154>/Switch' */
  real_T SignedSqrt_o[2];              /* '<S148>/Signed Sqrt' */
  real_T sqrt3_o[2];                   /* '<S110>/sqrt3' */
  real_T Fcn_f;                        /* '<S110>/Fcn' */
  real_T Product_d;                    /* '<S150>/Product' */
  real_T thshld_g;                     /* '<S150>/Fcn2' */
  real_T UnitDelay_cu;                 /* '<S157>/Unit Delay' */
  real_T UnitDelay_jf;                 /* '<S156>/Unit Delay' */
  real_T Fcn2_l;                       /* '<S146>/Fcn2' */
  real_T DiscreteTimeIntegrator_a;     /* '<S157>/Discrete-Time Integrator' */
  real_T MathFunction_iq;              /* '<S157>/Math Function' */
  real_T DiscreteTimeIntegrator_g5;    /* '<S156>/Discrete-Time Integrator' */
  real_T MathFunction_n3;              /* '<S156>/Math Function' */
  real_T TmpSignalConversionAtMathFunc_p[2];
  real_T MathFunction_a[2];            /* '<S147>/Math Function' */
  real_T Unwrap_p[2];                  /* '<S147>/Unwrap' */
  real_T diff_o;                       /* '<S147>/Fcn3' */
  real_T Gain_pk;                      /* '<S153>/Gain' */
  real_T bool_h;                       /* '<S147>/Fcn1' */
  real_T Logic_out_p;                  /* '<S104>/Switch' */
  real_T Memory2_n;                    /* '<S6>/Memory2' */
  real_T Memory9_g;                    /* '<S6>/Memory9' */
  real_T Divide_b;                     /* '<S152>/Divide' */
  real_T TrigonometricFunction2_e;     /* '<S156>/Trigonometric Function2' */
  real_T Vq_l;                         /* '<S156>/Product1' */
  real_T Integ4_p;                     /* '<S162>/Integ4' */
  real_T Freq_o;                       /* '<S162>/To avoid division by zero' */
  real_T Numberofsamplespercycle_c;    /* '<S162>/Number of samples per cycle' */
  real_T RoundingFunction_l;           /* '<S162>/Rounding Function' */
  real_T Delay_o;                      /* '<S162>/Gain' */
  real_T SFunction_e0;                 /* '<S173>/S-Function ' */
  real_T UnitDelay_cv;                 /* '<S172>/Unit Delay' */
  real_T Step_d;                       /* '<S162>/Step' */
  real_T Switch_m2;                    /* '<S162>/Switch' */
  real_T TrigonometricFunction_cx;     /* '<S156>/Trigonometric Function' */
  real_T Divide_i;                     /* '<S156>/Divide' */
  real_T Kp4_p;                        /* '<S160>/Kp4' */
  real_T DiscreteTimeIntegrator_l;     /* '<S160>/Discrete-Time Integrator' */
  real_T Kp6_a;                        /* '<S160>/Kp6' */
  real_T ZeroOrderHold_d;              /* '<S160>/Zero-Order Hold' */
  real_T TSamp_n;                      /* '<S171>/TSamp' */
  real_T Uk1_p;                        /* '<S171>/UD' */
  real_T Diff_pb;                      /* '<S171>/Diff' */
  real_T Sum6_p;                       /* '<S160>/Sum6' */
  real_T Saturation2_jn;               /* '<S160>/Saturation2' */
  real_T Gain10_m;                     /* '<S156>/Gain10' */
  real_T y1_p2;                        /* '<S161>/Unit  Delay' */
  real_T Sum1_f;                       /* '<S161>/Sum1' */
  real_T Deltau_limit_cm;              /* '<S161>/Saturation' */
  real_T y_l;                          /* '<S161>/Sum' */
  real_T DiscreteStateSpace_c;         /* '<S158>/Discrete State-Space' */
  real_T Kp5_kx;                       /* '<S160>/Kp5' */
  real_T Divide1_o;                    /* '<S152>/Divide1' */
  real_T TrigonometricFunction2_j;     /* '<S157>/Trigonometric Function2' */
  real_T Vq_il;                        /* '<S157>/Product1' */
  real_T Integ4_pa;                    /* '<S178>/Integ4' */
  real_T Freq_m;                       /* '<S178>/To avoid division by zero' */
  real_T Numberofsamplespercycle_j;    /* '<S178>/Number of samples per cycle' */
  real_T RoundingFunction_c;           /* '<S178>/Rounding Function' */
  real_T Delay_ds;                     /* '<S178>/Gain' */
  real_T SFunction_je;                 /* '<S189>/S-Function ' */
  real_T UnitDelay_bh;                 /* '<S188>/Unit Delay' */
  real_T Step_lg;                      /* '<S178>/Step' */
  real_T Switch_b;                     /* '<S178>/Switch' */
  real_T TrigonometricFunction_e;      /* '<S157>/Trigonometric Function' */
  real_T Divide_av;                    /* '<S157>/Divide' */
  real_T Kp4_b;                        /* '<S176>/Kp4' */
  real_T DiscreteTimeIntegrator_pa;    /* '<S176>/Discrete-Time Integrator' */
  real_T Kp6_e;                        /* '<S176>/Kp6' */
  real_T ZeroOrderHold_j2;             /* '<S176>/Zero-Order Hold' */
  real_T TSamp_h;                      /* '<S187>/TSamp' */
  real_T Uk1_pi;                       /* '<S187>/UD' */
  real_T Diff_n;                       /* '<S187>/Diff' */
  real_T Sum6_h;                       /* '<S176>/Sum6' */
  real_T Saturation2_l;                /* '<S176>/Saturation2' */
  real_T Gain10_l;                     /* '<S157>/Gain10' */
  real_T y1_a4;                        /* '<S177>/Unit  Delay' */
  real_T Sum1_c0;                      /* '<S177>/Sum1' */
  real_T Deltau_limit_e;               /* '<S177>/Saturation' */
  real_T y_e;                          /* '<S177>/Sum' */
  real_T DiscreteStateSpace_l;         /* '<S174>/Discrete State-Space' */
  real_T Kp5_e;                        /* '<S176>/Kp5' */
  real_T Sum_m;                        /* '<S6>/Sum' */
  real_T Sum1_n2;                      /* '<S6>/Sum1' */
  real_T DataTypeConversion1_o;        /* '<S112>/Data Type Conversion1' */
  real_T DataTypeConversion1_e;        /* '<S113>/Data Type Conversion1' */
  real_T Sum1_l;                       /* '<S188>/Sum1' */
  real_T Sum5_c;                       /* '<S188>/Sum5' */
  real_T Product5;                     /* '<S188>/Product5' */
  real_T Gain1_m0;                     /* '<S188>/Gain1' */
  real_T Sum4_d;                       /* '<S188>/Sum4' */
  real_T Product2_b;                   /* '<S188>/Product2' */
  real_T Product4;                     /* '<S188>/Product4' */
  real_T Sum7;                         /* '<S178>/Sum7' */
  real_T Meanvalue;                    /* '<S178>/Product' */
  real_T Sum5_h;                       /* '<S178>/Sum5' */
  real_T Gain1_p4[2];                  /* '<S179>/Gain1' */
  real_T Product_h[2];                 /* '<S179>/Product' */
  real_T Integ4_a;                     /* '<S181>/Integ4' */
  real_T Freq_mz;                      /* '<S181>/To avoid division by zero' */
  real_T Numberofsamplespercycle_e;    /* '<S181>/Number of samples per cycle' */
  real_T RoundingFunction_l5;          /* '<S181>/Rounding Function' */
  real_T Delay_a;                      /* '<S181>/Gain' */
  real_T SFunction_lx;                 /* '<S184>/S-Function ' */
  real_T UnitDelay_jj;                 /* '<S183>/Unit Delay' */
  real_T Step_cz;                      /* '<S181>/Step' */
  real_T Switch_g;                     /* '<S181>/Switch' */
  real_T Integ4_c0;                    /* '<S182>/Integ4' */
  real_T Freq_b;                       /* '<S182>/To avoid division by zero' */
  real_T Numberofsamplespercycle_d;    /* '<S182>/Number of samples per cycle' */
  real_T RoundingFunction_cc;          /* '<S182>/Rounding Function' */
  real_T Delay_oy;                     /* '<S182>/Gain' */
  real_T SFunction_m2;                 /* '<S186>/S-Function ' */
  real_T UnitDelay_jp;                 /* '<S185>/Unit Delay' */
  real_T Step_dd;                      /* '<S182>/Step' */
  real_T Switch_bu;                    /* '<S182>/Switch' */
  real_T xr;                           /* '<S180>/x->r' */
  real_T xtheta;                       /* '<S180>/x->theta' */
  real_T RadDeg;                       /* '<S179>/Rad->Deg.' */
  real_T Saturation;                   /* '<S175>/Saturation' */
  real_T MathFunction_o;               /* '<S175>/Math Function' */
  real_T Sum1_h;                       /* '<S185>/Sum1' */
  real_T Sum5_g;                       /* '<S185>/Sum5' */
  real_T Product5_d;                   /* '<S185>/Product5' */
  real_T Gain1_h;                      /* '<S185>/Gain1' */
  real_T Sum4_km;                      /* '<S185>/Sum4' */
  real_T Product2_b3;                  /* '<S185>/Product2' */
  real_T Product4_m;                   /* '<S185>/Product4' */
  real_T Sum7_b;                       /* '<S182>/Sum7' */
  real_T Meanvalue_i;                  /* '<S182>/Product' */
  real_T Sum5_d;                       /* '<S182>/Sum5' */
  real_T Sum1_hg;                      /* '<S183>/Sum1' */
  real_T Sum5_hn;                      /* '<S183>/Sum5' */
  real_T Product5_b;                   /* '<S183>/Product5' */
  real_T Gain1_f;                      /* '<S183>/Gain1' */
  real_T Sum4_i;                       /* '<S183>/Sum4' */
  real_T Product2_g;                   /* '<S183>/Product2' */
  real_T Product4_o;                   /* '<S183>/Product4' */
  real_T Sum7_h;                       /* '<S181>/Sum7' */
  real_T Meanvalue_e;                  /* '<S181>/Product' */
  real_T Sum5_m;                       /* '<S181>/Sum5' */
  real_T Sum1_lc;                      /* '<S172>/Sum1' */
  real_T Sum5_i;                       /* '<S172>/Sum5' */
  real_T Product5_o;                   /* '<S172>/Product5' */
  real_T Gain1_l;                      /* '<S172>/Gain1' */
  real_T Sum4_g;                       /* '<S172>/Sum4' */
  real_T Product2_f;                   /* '<S172>/Product2' */
  real_T Product4_l;                   /* '<S172>/Product4' */
  real_T Sum7_a;                       /* '<S162>/Sum7' */
  real_T Meanvalue_f;                  /* '<S162>/Product' */
  real_T Sum5_ct;                      /* '<S162>/Sum5' */
  real_T Gain1_o[2];                   /* '<S163>/Gain1' */
  real_T Product_a[2];                 /* '<S163>/Product' */
  real_T Integ4_cf;                    /* '<S165>/Integ4' */
  real_T Freq_j;                       /* '<S165>/To avoid division by zero' */
  real_T Numberofsamplespercycle_k;    /* '<S165>/Number of samples per cycle' */
  real_T RoundingFunction_a;           /* '<S165>/Rounding Function' */
  real_T Delay_at;                     /* '<S165>/Gain' */
  real_T SFunction_mq;                 /* '<S168>/S-Function ' */
  real_T UnitDelay_dg;                 /* '<S167>/Unit Delay' */
  real_T Step_e;                       /* '<S165>/Step' */
  real_T Switch_be;                    /* '<S165>/Switch' */
  real_T Integ4_d2;                    /* '<S166>/Integ4' */
  real_T Freq_bf;                      /* '<S166>/To avoid division by zero' */
  real_T Numberofsamplespercycle_l;    /* '<S166>/Number of samples per cycle' */
  real_T RoundingFunction_h;           /* '<S166>/Rounding Function' */
  real_T Delay_m;                      /* '<S166>/Gain' */
  real_T SFunction_fa;                 /* '<S170>/S-Function ' */
  real_T UnitDelay_p;                  /* '<S169>/Unit Delay' */
  real_T Step_b;                       /* '<S166>/Step' */
  real_T Switch_ms;                    /* '<S166>/Switch' */
  real_T xr_b;                         /* '<S164>/x->r' */
  real_T xtheta_m;                     /* '<S164>/x->theta' */
  real_T RadDeg_i;                     /* '<S163>/Rad->Deg.' */
  real_T Saturation_h;                 /* '<S159>/Saturation' */
  real_T MathFunction_ib;              /* '<S159>/Math Function' */
  real_T Sum1_oz;                      /* '<S169>/Sum1' */
  real_T Sum5_gz;                      /* '<S169>/Sum5' */
  real_T Product5_a;                   /* '<S169>/Product5' */
  real_T Gain1_b;                      /* '<S169>/Gain1' */
  real_T Sum4_m;                       /* '<S169>/Sum4' */
  real_T Product2_h;                   /* '<S169>/Product2' */
  real_T Product4_j;                   /* '<S169>/Product4' */
  real_T Sum7_j;                       /* '<S166>/Sum7' */
  real_T Meanvalue_n;                  /* '<S166>/Product' */
  real_T Sum5_mh;                      /* '<S166>/Sum5' */
  real_T Sum1_ol;                      /* '<S167>/Sum1' */
  real_T Sum5_d3;                      /* '<S167>/Sum5' */
  real_T Product5_l;                   /* '<S167>/Product5' */
  real_T Gain1_d;                      /* '<S167>/Gain1' */
  real_T Sum4_c;                       /* '<S167>/Sum4' */
  real_T Product2_lv;                  /* '<S167>/Product2' */
  real_T Product4_n;                   /* '<S167>/Product4' */
  real_T Sum7_m;                       /* '<S165>/Sum7' */
  real_T Meanvalue_c;                  /* '<S165>/Product' */
  real_T Sum5_f;                       /* '<S165>/Sum5' */
  real_T Gain_f[2];                    /* '<S154>/Gain' */
  real_T Gain1_n[2];                   /* '<S154>/Gain1' */
  real_T Correction[2];                /* '<S154>/Sum1' */
  real_T Sum7_l[2];                    /* '<S154>/Sum7' */
  real_T Meanvalue_o[2];               /* '<S154>/Product' */
  real_T Sum5_g0[2];                   /* '<S154>/Sum5' */
  real_T Gain_e[3];                    /* '<S144>/Gain' */
  real_T Gain1_mb[3];                  /* '<S144>/Gain1' */
  real_T Correction_n[3];              /* '<S144>/Sum1' */
  real_T Sum7_f[3];                    /* '<S144>/Sum7' */
  real_T Meanvalue_p[3];               /* '<S144>/Product' */
  real_T Sum5_mz[3];                   /* '<S144>/Sum5' */
  real_T Gain_m0[3];                   /* '<S142>/Gain' */
  real_T Gain1_j[3];                   /* '<S142>/Gain1' */
  real_T Correction_j[3];              /* '<S142>/Sum1' */
  real_T Sum7_jf[3];                   /* '<S142>/Sum7' */
  real_T Meanvalue_d[3];               /* '<S142>/Product' */
  real_T Sum5_ds[3];                   /* '<S142>/Sum5' */
  real_T Gain_fu[2];                   /* '<S140>/Gain' */
  real_T Gain1_oz[2];                  /* '<S140>/Gain1' */
  real_T Correction_k[2];              /* '<S140>/Sum1' */
  real_T Sum7_fx[2];                   /* '<S140>/Sum7' */
  real_T Meanvalue_h[2];               /* '<S140>/Product' */
  real_T Sum5_n[2];                    /* '<S140>/Sum5' */
  real_T Fcn_f2;                       /* '<S104>/Fcn' */
  real_T DataTypeConversion;           /* '<S104>/Data Type Conversion' */
  real_T Gain_mo;                      /* '<S126>/Gain' */
  real_T Gain1_h3;                     /* '<S126>/Gain1' */
  real_T Correction_p;                 /* '<S126>/Sum1' */
  real_T Sum7_g;                       /* '<S126>/Sum7' */
  real_T Meanvalue_a;                  /* '<S126>/Product' */
  real_T Sum5_o;                       /* '<S126>/Sum5' */
  real_T Gain_i;                       /* '<S119>/Gain' */
  real_T Gain1_i;                      /* '<S119>/Gain1' */
  real_T Correction_e;                 /* '<S119>/Sum1' */
  real_T Sum7_gd;                      /* '<S119>/Sum7' */
  real_T Meanvalue_iu;                 /* '<S119>/Product' */
  real_T Sum5_or;                      /* '<S119>/Sum5' */
  real_T Sum1_cc;                      /* '<S97>/Sum1' */
  real_T Sum5_a;                       /* '<S97>/Sum5' */
  real_T Product5_f;                   /* '<S97>/Product5' */
  real_T Gain1_hb;                     /* '<S97>/Gain1' */
  real_T Sum4_p;                       /* '<S97>/Sum4' */
  real_T Product2_m;                   /* '<S97>/Product2' */
  real_T Product4_nr;                  /* '<S97>/Product4' */
  real_T Sum7_e;                       /* '<S87>/Sum7' */
  real_T Meanvalue_aq;                 /* '<S87>/Product' */
  real_T Sum5_om;                      /* '<S87>/Sum5' */
  real_T Gain1_p3[2];                  /* '<S88>/Gain1' */
  real_T Product_hq[2];                /* '<S88>/Product' */
  real_T Integ4_pk;                    /* '<S90>/Integ4' */
  real_T Freq_d;                       /* '<S90>/To avoid division by zero' */
  real_T Numberofsamplespercycle_m;    /* '<S90>/Number of samples per cycle' */
  real_T RoundingFunction_m;           /* '<S90>/Rounding Function' */
  real_T Delay_k;                      /* '<S90>/Gain' */
  real_T SFunction_i5;                 /* '<S93>/S-Function ' */
  real_T UnitDelay_ma;                 /* '<S92>/Unit Delay' */
  real_T Step_ce;                      /* '<S90>/Step' */
  real_T Switch_l;                     /* '<S90>/Switch' */
  real_T Integ4_f;                     /* '<S91>/Integ4' */
  real_T Freq_c;                       /* '<S91>/To avoid division by zero' */
  real_T Numberofsamplespercycle_g;    /* '<S91>/Number of samples per cycle' */
  real_T RoundingFunction_hw;          /* '<S91>/Rounding Function' */
  real_T Delay_ox;                     /* '<S91>/Gain' */
  real_T SFunction_mm;                 /* '<S95>/S-Function ' */
  real_T UnitDelay_ik;                 /* '<S94>/Unit Delay' */
  real_T Step_kd;                      /* '<S91>/Step' */
  real_T Switch_n;                     /* '<S91>/Switch' */
  real_T xr_p;                         /* '<S89>/x->r' */
  real_T xtheta_g;                     /* '<S89>/x->theta' */
  real_T RadDeg_l;                     /* '<S88>/Rad->Deg.' */
  real_T Saturation_k;                 /* '<S84>/Saturation' */
  real_T MathFunction_g0;              /* '<S84>/Math Function' */
  real_T Sum1_g;                       /* '<S94>/Sum1' */
  real_T Sum5_l;                       /* '<S94>/Sum5' */
  real_T Product5_o0;                  /* '<S94>/Product5' */
  real_T Gain1_c;                      /* '<S94>/Gain1' */
  real_T Sum4_al;                      /* '<S94>/Sum4' */
  real_T Product2_l0;                  /* '<S94>/Product2' */
  real_T Product4_c;                   /* '<S94>/Product4' */
  real_T Sum7_k;                       /* '<S91>/Sum7' */
  real_T Meanvalue_b;                  /* '<S91>/Product' */
  real_T Sum5_n5;                      /* '<S91>/Sum5' */
  real_T Sum1_a3;                      /* '<S92>/Sum1' */
  real_T Sum5_b;                       /* '<S92>/Sum5' */
  real_T Product5_j;                   /* '<S92>/Product5' */
  real_T Gain1_m0g;                    /* '<S92>/Gain1' */
  real_T Sum4_az;                      /* '<S92>/Sum4' */
  real_T Product2_p;                   /* '<S92>/Product2' */
  real_T Product4_k;                   /* '<S92>/Product4' */
  real_T Sum7_p;                       /* '<S90>/Sum7' */
  real_T Meanvalue_od;                 /* '<S90>/Product' */
  real_T Sum5_cb;                      /* '<S90>/Sum5' */
  real_T Sum1_hp;                      /* '<S81>/Sum1' */
  real_T Sum5_p;                       /* '<S81>/Sum5' */
  real_T Product5_n;                   /* '<S81>/Product5' */
  real_T Gain1_ol;                     /* '<S81>/Gain1' */
  real_T Sum4_n;                       /* '<S81>/Sum4' */
  real_T Product2_k;                   /* '<S81>/Product2' */
  real_T Product4_jj;                  /* '<S81>/Product4' */
  real_T Sum7_e1;                      /* '<S71>/Sum7' */
  real_T Meanvalue_k;                  /* '<S71>/Product' */
  real_T Sum5_mk;                      /* '<S71>/Sum5' */
  real_T Gain1_h1[2];                  /* '<S72>/Gain1' */
  real_T Product_k3[2];                /* '<S72>/Product' */
  real_T Integ4_h;                     /* '<S74>/Integ4' */
  real_T Freq_ms;                      /* '<S74>/To avoid division by zero' */
  real_T Numberofsamplespercycle_cy;   /* '<S74>/Number of samples per cycle' */
  real_T RoundingFunction_g;           /* '<S74>/Rounding Function' */
  real_T Delay_p;                      /* '<S74>/Gain' */
  real_T SFunction_nb;                 /* '<S77>/S-Function ' */
  real_T UnitDelay_be;                 /* '<S76>/Unit Delay' */
  real_T Step_dh;                      /* '<S74>/Step' */
  real_T Switch_dh;                    /* '<S74>/Switch' */
  real_T Integ4_k;                     /* '<S75>/Integ4' */
  real_T Freq_jb;                      /* '<S75>/To avoid division by zero' */
  real_T Numberofsamplespercycle_e4;   /* '<S75>/Number of samples per cycle' */
  real_T RoundingFunction_m3;          /* '<S75>/Rounding Function' */
  real_T Delay_c;                      /* '<S75>/Gain' */
  real_T SFunction_g;                  /* '<S79>/S-Function ' */
  real_T UnitDelay_en;                 /* '<S78>/Unit Delay' */
  real_T Step_db;                      /* '<S75>/Step' */
  real_T Switch_lo;                    /* '<S75>/Switch' */
  real_T xr_h;                         /* '<S73>/x->r' */
  real_T xtheta_f;                     /* '<S73>/x->theta' */
  real_T RadDeg_c;                     /* '<S72>/Rad->Deg.' */
  real_T Saturation_l;                 /* '<S68>/Saturation' */
  real_T MathFunction_gy;              /* '<S68>/Math Function' */
  real_T Sum1_lu;                      /* '<S78>/Sum1' */
  real_T Sum5_hq;                      /* '<S78>/Sum5' */
  real_T Product5_dd;                  /* '<S78>/Product5' */
  real_T Gain1_mp;                     /* '<S78>/Gain1' */
  real_T Sum4_a3;                      /* '<S78>/Sum4' */
  real_T Product2_g5;                  /* '<S78>/Product2' */
  real_T Product4_g;                   /* '<S78>/Product4' */
  real_T Sum7_ad;                      /* '<S75>/Sum7' */
  real_T Meanvalue_ht;                 /* '<S75>/Product' */
  real_T Sum5_b5;                      /* '<S75>/Sum5' */
  real_T Sum1_f0;                      /* '<S76>/Sum1' */
  real_T Sum5_nc;                      /* '<S76>/Sum5' */
  real_T Product5_av;                  /* '<S76>/Product5' */
  real_T Gain1_ov;                     /* '<S76>/Gain1' */
  real_T Sum4_o;                       /* '<S76>/Sum4' */
  real_T Product2_d;                   /* '<S76>/Product2' */
  real_T Product4_nf;                  /* '<S76>/Product4' */
  real_T Sum7_i;                       /* '<S74>/Sum7' */
  real_T Meanvalue_cl;                 /* '<S74>/Product' */
  real_T Sum5_bk;                      /* '<S74>/Sum5' */
  real_T Gain_j[2];                    /* '<S63>/Gain' */
  real_T Gain1_lq[2];                  /* '<S63>/Gain1' */
  real_T Correction_i[2];              /* '<S63>/Sum1' */
  real_T Sum7_d[2];                    /* '<S63>/Sum7' */
  real_T Meanvalue_cy[2];              /* '<S63>/Product' */
  real_T Sum5_an[2];                   /* '<S63>/Sum5' */
  real_T Gain_pg[3];                   /* '<S53>/Gain' */
  real_T Gain1_jr[3];                  /* '<S53>/Gain1' */
  real_T Correction_g[3];              /* '<S53>/Sum1' */
  real_T Sum7_o[3];                    /* '<S53>/Sum7' */
  real_T Meanvalue_du[3];              /* '<S53>/Product' */
  real_T Sum5_ba[3];                   /* '<S53>/Sum5' */
  real_T Gain_g[3];                    /* '<S51>/Gain' */
  real_T Gain1_o2[3];                  /* '<S51>/Gain1' */
  real_T Correction_b[3];              /* '<S51>/Sum1' */
  real_T Sum7_c[3];                    /* '<S51>/Sum7' */
  real_T Meanvalue_os[3];              /* '<S51>/Product' */
  real_T Sum5_ec[3];                   /* '<S51>/Sum5' */
  real_T Gain_o[2];                    /* '<S49>/Gain' */
  real_T Gain1_bh[2];                  /* '<S49>/Gain1' */
  real_T Correction_l[2];              /* '<S49>/Sum1' */
  real_T Sum7_ji[2];                   /* '<S49>/Sum7' */
  real_T Meanvalue_c4[2];              /* '<S49>/Product' */
  real_T Sum5_m0[2];                   /* '<S49>/Sum5' */
  real_T Fcn_fz;                       /* '<S13>/Fcn' */
  real_T DataTypeConversion_i;         /* '<S13>/Data Type Conversion' */
  real_T Gain_pz;                      /* '<S35>/Gain' */
  real_T Gain1_oy;                     /* '<S35>/Gain1' */
  real_T Correction_jn;                /* '<S35>/Sum1' */
  real_T Sum7_lm;                      /* '<S35>/Sum7' */
  real_T Meanvalue_px;                 /* '<S35>/Product' */
  real_T Sum5_pz;                      /* '<S35>/Sum5' */
  real_T Gain_c;                       /* '<S28>/Gain' */
  real_T Gain1_b1;                     /* '<S28>/Gain1' */
  real_T Correction_bl;                /* '<S28>/Sum1' */
  real_T Sum7_ch;                      /* '<S28>/Sum7' */
  real_T Meanvalue_l;                  /* '<S28>/Product' */
  real_T Sum5_pb;                      /* '<S28>/Sum5' */
  uint16_T DataTypeConversion_h[7];    /* '<S21>/Data Type Conversion' */
  uint16_T ShiftArithmetic;            /* '<S21>/Shift Arithmetic' */
  uint16_T ShiftArithmetic1;           /* '<S21>/Shift Arithmetic1' */
  uint16_T ShiftArithmetic2;           /* '<S21>/Shift Arithmetic2' */
  uint16_T ShiftArithmetic3;           /* '<S21>/Shift Arithmetic3' */
  uint16_T ShiftArithmetic4;           /* '<S21>/Shift Arithmetic4' */
  uint16_T ShiftArithmetic5;           /* '<S21>/Shift Arithmetic5' */
  uint16_T BitwiseOperator;            /* '<S21>/Bitwise Operator' */
  uint16_T DataTypeConversion_a[2];    /* '<S22>/Data Type Conversion' */
  uint16_T ShiftArithmetic_g;          /* '<S22>/Shift Arithmetic' */
  uint16_T BitwiseOperator_k;          /* '<S22>/Bitwise Operator' */
  uint16_T DataTypeConversion_k[7];    /* '<S112>/Data Type Conversion' */
  uint16_T ShiftArithmetic_h;          /* '<S112>/Shift Arithmetic' */
  uint16_T ShiftArithmetic1_j;         /* '<S112>/Shift Arithmetic1' */
  uint16_T ShiftArithmetic2_h;         /* '<S112>/Shift Arithmetic2' */
  uint16_T ShiftArithmetic3_h;         /* '<S112>/Shift Arithmetic3' */
  uint16_T ShiftArithmetic4_n;         /* '<S112>/Shift Arithmetic4' */
  uint16_T ShiftArithmetic5_o;         /* '<S112>/Shift Arithmetic5' */
  uint16_T BitwiseOperator_m;          /* '<S112>/Bitwise Operator' */
  uint16_T DataTypeConversion_f[2];    /* '<S113>/Data Type Conversion' */
  uint16_T ShiftArithmetic_m;          /* '<S113>/Shift Arithmetic' */
  uint16_T BitwiseOperator_a;          /* '<S113>/Bitwise Operator' */
  uint8_T Compare;                     /* '<S39>/Compare' */
  uint8_T Compare_c;                   /* '<S40>/Compare' */
  uint8_T FixPtRelationalOperator;     /* '<S99>/FixPt Relational Operator' */
  uint8_T Compare_d;                   /* '<S130>/Compare' */
  uint8_T Compare_f;                   /* '<S131>/Compare' */
  uint8_T FixPtRelationalOperator_h;   /* '<S190>/FixPt Relational Operator' */
  boolean_T Compare_b;                 /* '<S41>/Compare' */
  boolean_T Compare_h;                 /* '<S42>/Compare' */
  boolean_T LogicalOperator;           /* '<S12>/Logical Operator' */
  boolean_T FixPtUnitDelay1_d;         /* '<S44>/FixPt Unit Delay1' */
  boolean_T Xnew_p;                    /* '<S44>/Enable' */
  boolean_T FixPtUnitDelay1_p;         /* '<S45>/FixPt Unit Delay1' */
  boolean_T Xnew_o;                    /* '<S45>/Enable' */
  boolean_T RelationalOperator;        /* '<S23>/Relational Operator' */
  boolean_T LogicalOperator1;          /* '<S20>/Logical Operator1' */
  boolean_T Uk1_b;                     /* '<S99>/Delay Input1' */
  boolean_T LogicalOperator4;          /* '<S5>/Logical Operator4' */
  boolean_T LogicalOperator_f;         /* '<S5>/Logical Operator' */
  boolean_T DataTypeConversion3_j[2];  /* '<S5>/Data Type Conversion3' */
  boolean_T reset;                     /* '<S5>/Data Type Conversion5' */
  boolean_T Status;                    /* '<S5>/Data Type Conversion6' */
  boolean_T DataTypeConversion1_a;     /* '<S13>/Data Type Conversion1' */
  boolean_T FixPtRelationalOperator_e; /* '<S46>/FixPt Relational Operator' */
  boolean_T Memory;                    /* '<S47>/Memory' */
  boolean_T Logic[2];                  /* '<S47>/Logic' */
  boolean_T dVdFdW;                    /* '<S19>/Logical Operator' */
  boolean_T LogicalOperator1_b;        /* '<S19>/Logical Operator1' */
  boolean_T Memory_m;                  /* '<S58>/Memory' */
  boolean_T Logic_a[2];                /* '<S58>/Logic' */
  boolean_T LogicalOperator3;          /* '<S19>/Logical Operator3' */
  boolean_T Compare_i;                 /* '<S132>/Compare' */
  boolean_T Compare_o;                 /* '<S133>/Compare' */
  boolean_T LogicalOperator_e;         /* '<S103>/Logical Operator' */
  boolean_T FixPtUnitDelay1_i;         /* '<S135>/FixPt Unit Delay1' */
  boolean_T Xnew_b;                    /* '<S135>/Enable' */
  boolean_T FixPtUnitDelay1_j;         /* '<S136>/FixPt Unit Delay1' */
  boolean_T Xnew_f;                    /* '<S136>/Enable' */
  boolean_T RelationalOperator_n;      /* '<S114>/Relational Operator' */
  boolean_T LogicalOperator1_g;        /* '<S111>/Logical Operator1' */
  boolean_T Uk1_d;                     /* '<S190>/Delay Input1' */
  boolean_T LogicalOperator4_o;        /* '<S6>/Logical Operator4' */
  boolean_T LogicalOperator_fs;        /* '<S6>/Logical Operator' */
  boolean_T DataTypeConversion3_a[2];  /* '<S6>/Data Type Conversion3' */
  boolean_T reset_j;                   /* '<S6>/Data Type Conversion5' */
  boolean_T Status_n;                  /* '<S6>/Data Type Conversion6' */
  boolean_T DataTypeConversion1_n;     /* '<S104>/Data Type Conversion1' */
  boolean_T FixPtRelationalOperator_p; /* '<S137>/FixPt Relational Operator' */
  boolean_T Memory_j;                  /* '<S138>/Memory' */
  boolean_T Logic_h[2];                /* '<S138>/Logic' */
  boolean_T dVdFdW_c;                  /* '<S110>/Logical Operator' */
  boolean_T LogicalOperator1_gn;       /* '<S110>/Logical Operator1' */
  boolean_T Memory_jt;                 /* '<S149>/Memory' */
  boolean_T Logic_b[2];                /* '<S149>/Logic' */
  boolean_T LogicalOperator3_d;        /* '<S110>/Logical Operator3' */
  B_trip_outmng_sel751test_mode_T sf_trip_outmng_a;/* '<S6>/trip_out mng' */
  B_Relays_sel751test_model_1_3_T sf_Relays_c;/* '<S114>/Relays' */
  B_deadbusfcn_sel751test_model_T sf_deadbusfcn_l;/* '<S110>/deadbus fcn' */
  B_trip_outmng_sel751test_mode_T sf_trip_outmng;/* '<S5>/trip_out mng' */
  B_Relays_sel751test_model_1_3_T sf_Relays;/* '<S23>/Relays' */
  B_deadbusfcn_sel751test_model_T sf_deadbusfcn;/* '<S19>/deadbus fcn' */
} B_sel751test_model_1_3_ss_relays_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S10>/Discrete-Time Integrator' */
  real_T Integ4_DSTATE;                /* '<S28>/Integ4' */
  real_T UnitDelay_DSTATE;             /* '<S28>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_d;/* '<S26>/Discrete-Time Integrator' */
  real_T UD_DSTATE;                    /* '<S30>/UD' */
  real_T UnitDelay_DSTATE_l;           /* '<S27>/Unit  Delay' */
  real_T DiscreteStateSpace_DSTATE[2]; /* '<S25>/Discrete State-Space' */
  real_T UnitDelay_DSTATE_n;           /* '<S10>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_i;/* '<S11>/Discrete-Time Integrator' */
  real_T Integ4_DSTATE_o;              /* '<S35>/Integ4' */
  real_T UnitDelay_DSTATE_n1;          /* '<S35>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_b;/* '<S33>/Discrete-Time Integrator' */
  real_T UD_DSTATE_p;                  /* '<S37>/UD' */
  real_T UnitDelay_DSTATE_e;           /* '<S34>/Unit  Delay' */
  real_T DiscreteStateSpace_DSTATE_b[2];/* '<S32>/Discrete State-Space' */
  real_T UnitDelay_DSTATE_k;           /* '<S11>/Unit Delay' */
  real_T Integ4_DSTATE_i[2];           /* '<S49>/Integ4' */
  real_T UnitDelay_DSTATE_kt[2];       /* '<S49>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE;       /* '<S43>/FixPt Unit Delay1' */
  real_T Integ4_DSTATE_c[3];           /* '<S51>/Integ4' */
  real_T UnitDelay_DSTATE_h[3];        /* '<S51>/Unit Delay' */
  real_T Integ4_DSTATE_a[3];           /* '<S53>/Integ4' */
  real_T UnitDelay_DSTATE_d[3];        /* '<S53>/Unit Delay' */
  real_T DelayInput1_DSTATE;           /* '<S46>/Delay Input1' */
  real_T Integ4_DSTATE_id[2];          /* '<S63>/Integ4' */
  real_T UnitDelay_DSTATE_m[2];        /* '<S63>/Unit Delay' */
  real_T UnitDelay_DSTATE_j;           /* '<S66>/Unit Delay' */
  real_T UnitDelay_DSTATE_ez;          /* '<S65>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_h;/* '<S66>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_o;/* '<S65>/Discrete-Time Integrator' */
  real_T Integ4_DSTATE_m;              /* '<S71>/Integ4' */
  real_T UnitDelay_DSTATE_ed;          /* '<S81>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_a;/* '<S69>/Discrete-Time Integrator' */
  real_T UD_DSTATE_e;                  /* '<S80>/UD' */
  real_T UnitDelay_DSTATE_i;           /* '<S70>/Unit  Delay' */
  real_T DiscreteStateSpace_DSTATE_l[2];/* '<S67>/Discrete State-Space' */
  real_T Integ4_DSTATE_oi;             /* '<S87>/Integ4' */
  real_T UnitDelay_DSTATE_g;           /* '<S97>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTAT_iq;/* '<S85>/Discrete-Time Integrator' */
  real_T UD_DSTATE_b;                  /* '<S96>/UD' */
  real_T UnitDelay_DSTATE_a;           /* '<S86>/Unit  Delay' */
  real_T DiscreteStateSpace_DSTATE_k[2];/* '<S83>/Discrete State-Space' */
  real_T DiscreteTimeIntegrator_DSTATE_p;/* '<S101>/Discrete-Time Integrator' */
  real_T Integ4_DSTATE_h;              /* '<S119>/Integ4' */
  real_T UnitDelay_DSTATE_au;          /* '<S119>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_j;/* '<S117>/Discrete-Time Integrator' */
  real_T UD_DSTATE_n;                  /* '<S121>/UD' */
  real_T UnitDelay_DSTATE_o;           /* '<S118>/Unit  Delay' */
  real_T DiscreteStateSpace_DSTATE_d[2];/* '<S116>/Discrete State-Space' */
  real_T UnitDelay_DSTATE_b;           /* '<S101>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_m;/* '<S102>/Discrete-Time Integrator' */
  real_T Integ4_DSTATE_cw;             /* '<S126>/Integ4' */
  real_T UnitDelay_DSTATE_jt;          /* '<S126>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTAT_jr;/* '<S124>/Discrete-Time Integrator' */
  real_T UD_DSTATE_m;                  /* '<S128>/UD' */
  real_T UnitDelay_DSTATE_an;          /* '<S125>/Unit  Delay' */
  real_T DiscreteStateSpace_DSTATE_j[2];/* '<S123>/Discrete State-Space' */
  real_T UnitDelay_DSTATE_hh;          /* '<S102>/Unit Delay' */
  real_T Integ4_DSTATE_e[2];           /* '<S140>/Integ4' */
  real_T UnitDelay_DSTATE_e5[2];       /* '<S140>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_g;     /* '<S134>/FixPt Unit Delay1' */
  real_T Integ4_DSTATE_f[3];           /* '<S142>/Integ4' */
  real_T UnitDelay_DSTATE_p[3];        /* '<S142>/Unit Delay' */
  real_T Integ4_DSTATE_k[3];           /* '<S144>/Integ4' */
  real_T UnitDelay_DSTATE_jf[3];       /* '<S144>/Unit Delay' */
  real_T DelayInput1_DSTATE_a;         /* '<S137>/Delay Input1' */
  real_T Integ4_DSTATE_p[2];           /* '<S154>/Integ4' */
  real_T UnitDelay_DSTATE_ea[2];       /* '<S154>/Unit Delay' */
  real_T UnitDelay_DSTATE_jm;          /* '<S157>/Unit Delay' */
  real_T UnitDelay_DSTATE_im;          /* '<S156>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTAT_ii;/* '<S157>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_f;/* '<S156>/Discrete-Time Integrator' */
  real_T Integ4_DSTATE_pp;             /* '<S162>/Integ4' */
  real_T UnitDelay_DSTATE_l0;          /* '<S172>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTAT_pw;/* '<S160>/Discrete-Time Integrator' */
  real_T UD_DSTATE_h;                  /* '<S171>/UD' */
  real_T UnitDelay_DSTATE_gp;          /* '<S161>/Unit  Delay' */
  real_T DiscreteStateSpace_DSTATE_h[2];/* '<S158>/Discrete State-Space' */
  real_T Integ4_DSTATE_ei;             /* '<S178>/Integ4' */
  real_T UnitDelay_DSTATE_lo;          /* '<S188>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_c;/* '<S176>/Discrete-Time Integrator' */
  real_T UD_DSTATE_i;                  /* '<S187>/UD' */
  real_T UnitDelay_DSTATE_pk;          /* '<S177>/Unit  Delay' */
  real_T DiscreteStateSpace_DSTATE_m[2];/* '<S174>/Discrete State-Space' */
  real_T Integ4_DSTATE_pe;             /* '<S181>/Integ4' */
  real_T UnitDelay_DSTATE_pr;          /* '<S183>/Unit Delay' */
  real_T Integ4_DSTATE_d;              /* '<S182>/Integ4' */
  real_T UnitDelay_DSTATE_hw;          /* '<S185>/Unit Delay' */
  real_T Integ4_DSTATE_my;             /* '<S165>/Integ4' */
  real_T UnitDelay_DSTATE_ir;          /* '<S167>/Unit Delay' */
  real_T Integ4_DSTATE_ip;             /* '<S166>/Integ4' */
  real_T UnitDelay_DSTATE_lv;          /* '<S169>/Unit Delay' */
  real_T Integ4_DSTATE_er;             /* '<S90>/Integ4' */
  real_T UnitDelay_DSTATE_go;          /* '<S92>/Unit Delay' */
  real_T Integ4_DSTATE_h4;             /* '<S91>/Integ4' */
  real_T UnitDelay_DSTATE_ku;          /* '<S94>/Unit Delay' */
  real_T Integ4_DSTATE_n;              /* '<S74>/Integ4' */
  real_T UnitDelay_DSTATE_b5;          /* '<S76>/Unit Delay' */
  real_T Integ4_DSTATE_j;              /* '<S75>/Integ4' */
  real_T UnitDelay_DSTATE_hf;          /* '<S78>/Unit Delay' */
  real_T SFunction_PreviousInput;      /* '<S2>/S-Function' */
  real_T Memory1_PreviousInput;        /* '<S5>/Memory1' */
  real_T Memory8_PreviousInput;        /* '<S5>/Memory8' */
  real_T Memory3_1_PreviousInput[3];   /* '<S5>/Memory3' */
  real_T Memory3_2_PreviousInput[3];   /* '<S5>/Memory3' */
  real_T Memory3_3_PreviousInput;      /* '<S5>/Memory3' */
  real_T Memory3_4_PreviousInput;      /* '<S5>/Memory3' */
  real_T Memory3_5_PreviousInput;      /* '<S5>/Memory3' */
  real_T Memory3_6_PreviousInput;      /* '<S5>/Memory3' */
  real_T Memory3_7_PreviousInput;      /* '<S5>/Memory3' */
  real_T Memory3_8_PreviousInput;      /* '<S5>/Memory3' */
  real_T Memory3_9_PreviousInput;      /* '<S5>/Memory3' */
  real_T Memory3_10_PreviousInput;     /* '<S5>/Memory3' */
  real_T Memory1_PreviousInput_e;      /* '<S6>/Memory1' */
  real_T Memory8_PreviousInput_e;      /* '<S6>/Memory8' */
  real_T Memory3_1_PreviousInput_p[3]; /* '<S6>/Memory3' */
  real_T Memory3_2_PreviousInput_l[3]; /* '<S6>/Memory3' */
  real_T Memory3_3_PreviousInput_n;    /* '<S6>/Memory3' */
  real_T Memory3_4_PreviousInput_g;    /* '<S6>/Memory3' */
  real_T Memory3_5_PreviousInput_d;    /* '<S6>/Memory3' */
  real_T Memory3_6_PreviousInput_m;    /* '<S6>/Memory3' */
  real_T Memory3_7_PreviousInput_c;    /* '<S6>/Memory3' */
  real_T Memory3_8_PreviousInput_d;    /* '<S6>/Memory3' */
  real_T Memory3_9_PreviousInput_l;    /* '<S6>/Memory3' */
  real_T Memory3_10_PreviousInput_e;   /* '<S6>/Memory3' */
  real_T Unwrap_Prev;                  /* '<S56>/Unwrap' */
  real_T Unwrap_Cumsum;                /* '<S56>/Unwrap' */
  real_T Memory2_PreviousInput;        /* '<S5>/Memory2' */
  real_T Memory9_PreviousInput;        /* '<S5>/Memory9' */
  real_T Unwrap_Prev_a;                /* '<S147>/Unwrap' */
  real_T Unwrap_Cumsum_b;              /* '<S147>/Unwrap' */
  real_T Memory2_PreviousInput_j;      /* '<S6>/Memory2' */
  real_T Memory9_PreviousInput_i;      /* '<S6>/Memory9' */
  void *SFunction_PWORK;               /* '<S199>/S-Function' */
  struct {
    void *uBuffers;
  } SFunction_PWORK_e;                 /* '<S31>/S-Function ' */

  struct {
    void *uBuffers;
  } SFunction_PWORK_a;                 /* '<S38>/S-Function ' */

  struct {
    void *uBuffers[2];
  } SFunction_PWORK_o;                 /* '<S50>/S-Function ' */

  struct {
    void *uBuffers[3];
  } SFunction_PWORK_n;                 /* '<S52>/S-Function ' */

  struct {
    void *uBuffers[3];
  } SFunction_PWORK_m;                 /* '<S54>/S-Function ' */

  struct {
    void *uBuffers[2];
  } SFunction_PWORK_ne;                /* '<S64>/S-Function ' */

  struct {
    void *uBuffers;
  } SFunction_PWORK_g;                 /* '<S82>/S-Function ' */

  struct {
    void *uBuffers;
  } SFunction_PWORK_f;                 /* '<S98>/S-Function ' */

  struct {
    void *uBuffers;
  } SFunction_PWORK_b;                 /* '<S122>/S-Function ' */

  struct {
    void *uBuffers;
  } SFunction_PWORK_bf;                /* '<S129>/S-Function ' */

  struct {
    void *uBuffers[2];
  } SFunction_PWORK_k;                 /* '<S141>/S-Function ' */

  struct {
    void *uBuffers[3];
  } SFunction_PWORK_c;                 /* '<S143>/S-Function ' */

  struct {
    void *uBuffers[3];
  } SFunction_PWORK_p;                 /* '<S145>/S-Function ' */

  struct {
    void *uBuffers[2];
  } SFunction_PWORK_ko;                /* '<S155>/S-Function ' */

  struct {
    void *uBuffers;
  } SFunction_PWORK_o3;                /* '<S173>/S-Function ' */

  struct {
    void *uBuffers;
  } SFunction_PWORK_kx;                /* '<S189>/S-Function ' */

  struct {
    void *uBuffers;
  } SFunction_PWORK_i;                 /* '<S184>/S-Function ' */

  struct {
    void *uBuffers;
  } SFunction_PWORK_fl;                /* '<S186>/S-Function ' */

  struct {
    void *uBuffers;
  } SFunction_PWORK_e5;                /* '<S168>/S-Function ' */

  struct {
    void *uBuffers;
  } SFunction_PWORK_gs;                /* '<S170>/S-Function ' */

  struct {
    void *uBuffers;
  } SFunction_PWORK_gl;                /* '<S93>/S-Function ' */

  struct {
    void *uBuffers;
  } SFunction_PWORK_l;                 /* '<S95>/S-Function ' */

  struct {
    void *uBuffers;
  } SFunction_PWORK_es;                /* '<S77>/S-Function ' */

  struct {
    void *uBuffers;
  } SFunction_PWORK_h;                 /* '<S79>/S-Function ' */

  int_T SFunction_IWORK[5];            /* '<S197>/S-Function' */
  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_e;                 /* '<S31>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_h;                 /* '<S38>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_l;                 /* '<S50>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_j;                 /* '<S52>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_es;                /* '<S54>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_f;                 /* '<S64>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_hj;                /* '<S82>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_d;                 /* '<S98>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_a;                 /* '<S122>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_fv;                /* '<S129>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_jj;                /* '<S141>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_k;                 /* '<S143>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_p;                 /* '<S145>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_hc;                /* '<S155>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_fs;                /* '<S173>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_ff;                /* '<S189>/S-Function ' */

  int_T SFunction_IWORK_g[5];          /* '<S198>/S-Function' */
  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_p1;                /* '<S184>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_c;                 /* '<S186>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_a2;                /* '<S168>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_n;                 /* '<S170>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_m;                 /* '<S93>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_nd;                /* '<S95>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_f5;                /* '<S77>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_dt;                /* '<S79>/S-Function ' */

  boolean_T FixPtUnitDelay1_DSTATE_n;  /* '<S44>/FixPt Unit Delay1' */
  boolean_T FixPtUnitDelay1_DSTATE_n0; /* '<S45>/FixPt Unit Delay1' */
  boolean_T DelayInput1_DSTATE_k;      /* '<S99>/Delay Input1' */
  boolean_T FixPtUnitDelay1_DSTATE_b;  /* '<S135>/FixPt Unit Delay1' */
  boolean_T FixPtUnitDelay1_DSTATE_a;  /* '<S136>/FixPt Unit Delay1' */
  boolean_T DelayInput1_DSTATE_o;      /* '<S190>/Delay Input1' */
  uint8_T Integ4_SYSTEM_ENABLE;        /* '<S28>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_o;      /* '<S35>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_k;      /* '<S49>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_d;      /* '<S51>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_b;      /* '<S53>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_e;      /* '<S63>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_eh;     /* '<S71>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_od;     /* '<S87>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_l;      /* '<S119>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_c;      /* '<S126>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_lg;     /* '<S140>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_f;      /* '<S142>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_fs;     /* '<S144>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_h;      /* '<S154>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_bf;     /* '<S162>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_os;     /* '<S178>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_l4;     /* '<S181>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_hr;     /* '<S182>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_kt;     /* '<S165>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_ds;     /* '<S166>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_ll;     /* '<S90>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_fr;     /* '<S91>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_m;      /* '<S74>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_ei;     /* '<S75>/Integ4' */
  boolean_T Memory_PreviousInput;      /* '<S47>/Memory' */
  boolean_T Unwrap_FirstStep;          /* '<S56>/Unwrap' */
  boolean_T Memory_PreviousInput_o;    /* '<S58>/Memory' */
  boolean_T Memory_PreviousInput_g;    /* '<S138>/Memory' */
  boolean_T Unwrap_FirstStep_b;        /* '<S147>/Unwrap' */
  boolean_T Memory_PreviousInput_h;    /* '<S149>/Memory' */
  boolean_T AutomaticGainControl_MODE; /* '<S65>/Automatic Gain Control' */
  boolean_T AutomaticGainControl_MODE_c;/* '<S66>/Automatic Gain Control' */
  boolean_T AutomaticGainControl_MODE_m;/* '<S156>/Automatic Gain Control' */
  boolean_T AutomaticGainControl_MODE_o;/* '<S157>/Automatic Gain Control' */
  DW_trip_outmng_sel751test_mod_T sf_trip_outmng_a;/* '<S6>/trip_out mng' */
  DW_Relays_sel751test_model_1__T sf_Relays_c;/* '<S114>/Relays' */
  DW_trip_outmng_sel751test_mod_T sf_trip_outmng;/* '<S5>/trip_out mng' */
  DW_Relays_sel751test_model_1__T sf_Relays;/* '<S23>/Relays' */
} DW_sel751test_model_1_3_ss_relays_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Expression: tol)
   * Referenced by:
   *   '<S56>/Unwrap'
   *   '<S147>/Unwrap'
   */
  real_T pooled1;
} ConstP_sel751test_model_1_3_ss_relays_T;

/* Backward compatible GRT Identifiers */
#define rtB                            sel751test_model_1_3_ss_relays_B
#define BlockIO                        B_sel751test_model_1_3_ss_relays_T
#define rtP                            sel751test_model_1_3_ss_relays_P
#define Parameters                     P_sel751test_model_1_3_ss_relays_T
#define rtDWork                        sel751test_model_1_3_ss_relays_DW
#define D_Work                         DW_sel751test_model_1_3_ss_relays_T
#define ConstParam                     ConstP_sel751test_model_1_3_ss_relays_T
#define rtcP                           sel751test_model_1_3_ss_relays_ConstP

/* Parameters (auto storage) */
struct P_sel751test_model_1_3_ss_relays_T_ {
  real_T Gain_Gain;                    /* Expression: K1
                                        * Referenced by: '<S28>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: K2
                                        * Referenced by: '<S28>/Gain1'
                                        */
  real_T Gain_Gain_p;                  /* Expression: K1
                                        * Referenced by: '<S35>/Gain'
                                        */
  real_T Gain1_Gain_a;                 /* Expression: K2
                                        * Referenced by: '<S35>/Gain1'
                                        */
  real_T Gain_Gain_h;                  /* Expression: K1
                                        * Referenced by: '<S49>/Gain'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: K2
                                        * Referenced by: '<S49>/Gain1'
                                        */
  real_T Gain_Gain_m;                  /* Expression: K1
                                        * Referenced by: '<S51>/Gain'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: K2
                                        * Referenced by: '<S51>/Gain1'
                                        */
  real_T Gain_Gain_o;                  /* Expression: K1
                                        * Referenced by: '<S53>/Gain'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: K2
                                        * Referenced by: '<S53>/Gain1'
                                        */
  real_T Gain_Gain_oj;                 /* Expression: K1
                                        * Referenced by: '<S63>/Gain'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: K2
                                        * Referenced by: '<S63>/Gain1'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: 0.5
                                        * Referenced by: '<S76>/Gain1'
                                        */
  real_T Gain1_Gain_cf;                /* Expression: 0.5
                                        * Referenced by: '<S78>/Gain1'
                                        */
  real_T Gain_Y0;                      /* Expression: [1]
                                        * Referenced by: '<S68>/Gain'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: 2
                                        * Referenced by: '<S72>/Gain1'
                                        */
  real_T Integ4_gainval;               /* Computed Parameter: Integ4_gainval
                                        * Referenced by: '<S74>/Integ4'
                                        */
  real_T Integ4_IC;                    /* Expression: 0
                                        * Referenced by: '<S74>/Integ4'
                                        */
  real_T Toavoiddivisionbyzero_UpperSat;/* Expression: 1e6
                                         * Referenced by: '<S74>/To avoid division by zero'
                                         */
  real_T Toavoiddivisionbyzero_LowerSat;/* Expression: 1e-6
                                         * Referenced by: '<S74>/To avoid division by zero'
                                         */
  real_T Gain_Gain_l;                  /* Expression: Ts
                                        * Referenced by: '<S74>/Gain'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S76>/Unit Delay'
                                        */
  real_T Step_Time;                    /* Expression: 1/Finit
                                        * Referenced by: '<S74>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S74>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<S74>/Step'
                                        */
  real_T Constant_Value;               /* Expression: Vinit
                                        * Referenced by: '<S74>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S74>/Switch'
                                        */
  real_T Integ4_gainval_m;             /* Computed Parameter: Integ4_gainval_m
                                        * Referenced by: '<S75>/Integ4'
                                        */
  real_T Integ4_IC_o;                  /* Expression: 0
                                        * Referenced by: '<S75>/Integ4'
                                        */
  real_T Toavoiddivisionbyzero_UpperSa_f;/* Expression: 1e6
                                          * Referenced by: '<S75>/To avoid division by zero'
                                          */
  real_T Toavoiddivisionbyzero_LowerSa_m;/* Expression: 1e-6
                                          * Referenced by: '<S75>/To avoid division by zero'
                                          */
  real_T Gain_Gain_pn;                 /* Expression: Ts
                                        * Referenced by: '<S75>/Gain'
                                        */
  real_T UnitDelay_InitialCondition_e; /* Expression: 0
                                        * Referenced by: '<S78>/Unit Delay'
                                        */
  real_T Step_Time_m;                  /* Expression: 1/Finit
                                        * Referenced by: '<S75>/Step'
                                        */
  real_T Step_Y0_k;                    /* Expression: 0
                                        * Referenced by: '<S75>/Step'
                                        */
  real_T Step_YFinal_p;                /* Expression: 1
                                        * Referenced by: '<S75>/Step'
                                        */
  real_T Constant_Value_o;             /* Expression: Vinit
                                        * Referenced by: '<S75>/Constant'
                                        */
  real_T Switch_Threshold_i;           /* Expression: 0.5
                                        * Referenced by: '<S75>/Switch'
                                        */
  real_T RadDeg_Gain;                  /* Expression: 180/pi
                                        * Referenced by: '<S72>/Rad->Deg.'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 2
                                        * Referenced by: '<S68>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0.01
                                        * Referenced by: '<S68>/Saturation'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: 0.5
                                        * Referenced by: '<S81>/Gain1'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: 0.5
                                        * Referenced by: '<S92>/Gain1'
                                        */
  real_T Gain1_Gain_cfi;               /* Expression: 0.5
                                        * Referenced by: '<S94>/Gain1'
                                        */
  real_T Gain_Y0_p;                    /* Expression: [1]
                                        * Referenced by: '<S84>/Gain'
                                        */
  real_T Gain1_Gain_co;                /* Expression: 2
                                        * Referenced by: '<S88>/Gain1'
                                        */
  real_T Integ4_gainval_h;             /* Computed Parameter: Integ4_gainval_h
                                        * Referenced by: '<S90>/Integ4'
                                        */
  real_T Integ4_IC_a;                  /* Expression: 0
                                        * Referenced by: '<S90>/Integ4'
                                        */
  real_T Toavoiddivisionbyzero_UpperSa_l;/* Expression: 1e6
                                          * Referenced by: '<S90>/To avoid division by zero'
                                          */
  real_T Toavoiddivisionbyzero_LowerSa_e;/* Expression: 1e-6
                                          * Referenced by: '<S90>/To avoid division by zero'
                                          */
  real_T Gain_Gain_f;                  /* Expression: Ts
                                        * Referenced by: '<S90>/Gain'
                                        */
  real_T UnitDelay_InitialCondition_g; /* Expression: 0
                                        * Referenced by: '<S92>/Unit Delay'
                                        */
  real_T Step_Time_k;                  /* Expression: 1/Finit
                                        * Referenced by: '<S90>/Step'
                                        */
  real_T Step_Y0_i;                    /* Expression: 0
                                        * Referenced by: '<S90>/Step'
                                        */
  real_T Step_YFinal_pu;               /* Expression: 1
                                        * Referenced by: '<S90>/Step'
                                        */
  real_T Constant_Value_oz;            /* Expression: Vinit
                                        * Referenced by: '<S90>/Constant'
                                        */
  real_T Switch_Threshold_ir;          /* Expression: 0.5
                                        * Referenced by: '<S90>/Switch'
                                        */
  real_T Integ4_gainval_n;             /* Computed Parameter: Integ4_gainval_n
                                        * Referenced by: '<S91>/Integ4'
                                        */
  real_T Integ4_IC_i;                  /* Expression: 0
                                        * Referenced by: '<S91>/Integ4'
                                        */
  real_T Toavoiddivisionbyzero_UpperSa_h;/* Expression: 1e6
                                          * Referenced by: '<S91>/To avoid division by zero'
                                          */
  real_T Toavoiddivisionbyzero_LowerSa_g;/* Expression: 1e-6
                                          * Referenced by: '<S91>/To avoid division by zero'
                                          */
  real_T Gain_Gain_j;                  /* Expression: Ts
                                        * Referenced by: '<S91>/Gain'
                                        */
  real_T UnitDelay_InitialCondition_i; /* Expression: 0
                                        * Referenced by: '<S94>/Unit Delay'
                                        */
  real_T Step_Time_n;                  /* Expression: 1/Finit
                                        * Referenced by: '<S91>/Step'
                                        */
  real_T Step_Y0_h;                    /* Expression: 0
                                        * Referenced by: '<S91>/Step'
                                        */
  real_T Step_YFinal_j;                /* Expression: 1
                                        * Referenced by: '<S91>/Step'
                                        */
  real_T Constant_Value_a;             /* Expression: Vinit
                                        * Referenced by: '<S91>/Constant'
                                        */
  real_T Switch_Threshold_k;           /* Expression: 0.5
                                        * Referenced by: '<S91>/Switch'
                                        */
  real_T RadDeg_Gain_p;                /* Expression: 180/pi
                                        * Referenced by: '<S88>/Rad->Deg.'
                                        */
  real_T Saturation_UpperSat_h;        /* Expression: 2
                                        * Referenced by: '<S84>/Saturation'
                                        */
  real_T Saturation_LowerSat_o;        /* Expression: 0.01
                                        * Referenced by: '<S84>/Saturation'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 0.5
                                        * Referenced by: '<S97>/Gain1'
                                        */
  real_T group1gridtiedparameters_Value[7];/* Expression: [relay_settings(9:15)]
                                            * Referenced by: '<S20>/group#1 - gridtied parameters'
                                            */
  real_T group2islandedparameters_Value[7];/* Expression: [relay_settings(16:22)]
                                            * Referenced by: '<S20>/group#2 - islanded parameters'
                                            */
  real_T Gain_Gain_n;                  /* Expression: K1
                                        * Referenced by: '<S119>/Gain'
                                        */
  real_T Gain1_Gain_k;                 /* Expression: K2
                                        * Referenced by: '<S119>/Gain1'
                                        */
  real_T Gain_Gain_c;                  /* Expression: K1
                                        * Referenced by: '<S126>/Gain'
                                        */
  real_T Gain1_Gain_l0;                /* Expression: K2
                                        * Referenced by: '<S126>/Gain1'
                                        */
  real_T Gain_Gain_ls;                 /* Expression: K1
                                        * Referenced by: '<S140>/Gain'
                                        */
  real_T Gain1_Gain_bu;                /* Expression: K2
                                        * Referenced by: '<S140>/Gain1'
                                        */
  real_T Gain_Gain_or;                 /* Expression: K1
                                        * Referenced by: '<S142>/Gain'
                                        */
  real_T Gain1_Gain_kr;                /* Expression: K2
                                        * Referenced by: '<S142>/Gain1'
                                        */
  real_T Gain_Gain_i;                  /* Expression: K1
                                        * Referenced by: '<S144>/Gain'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: K2
                                        * Referenced by: '<S144>/Gain1'
                                        */
  real_T Gain_Gain_k;                  /* Expression: K1
                                        * Referenced by: '<S154>/Gain'
                                        */
  real_T Gain1_Gain_i;                 /* Expression: K2
                                        * Referenced by: '<S154>/Gain1'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: 0.5
                                        * Referenced by: '<S167>/Gain1'
                                        */
  real_T Gain1_Gain_oo;                /* Expression: 0.5
                                        * Referenced by: '<S169>/Gain1'
                                        */
  real_T Gain_Y0_f;                    /* Expression: [1]
                                        * Referenced by: '<S159>/Gain'
                                        */
  real_T Gain1_Gain_pd;                /* Expression: 2
                                        * Referenced by: '<S163>/Gain1'
                                        */
  real_T Integ4_gainval_c;             /* Computed Parameter: Integ4_gainval_c
                                        * Referenced by: '<S165>/Integ4'
                                        */
  real_T Integ4_IC_b;                  /* Expression: 0
                                        * Referenced by: '<S165>/Integ4'
                                        */
  real_T Toavoiddivisionbyzero_UpperSa_a;/* Expression: 1e6
                                          * Referenced by: '<S165>/To avoid division by zero'
                                          */
  real_T Toavoiddivisionbyzero_LowerSa_f;/* Expression: 1e-6
                                          * Referenced by: '<S165>/To avoid division by zero'
                                          */
  real_T Gain_Gain_lv;                 /* Expression: Ts
                                        * Referenced by: '<S165>/Gain'
                                        */
  real_T UnitDelay_InitialCondition_j; /* Expression: 0
                                        * Referenced by: '<S167>/Unit Delay'
                                        */
  real_T Step_Time_c;                  /* Expression: 1/Finit
                                        * Referenced by: '<S165>/Step'
                                        */
  real_T Step_Y0_j;                    /* Expression: 0
                                        * Referenced by: '<S165>/Step'
                                        */
  real_T Step_YFinal_jv;               /* Expression: 1
                                        * Referenced by: '<S165>/Step'
                                        */
  real_T Constant_Value_l;             /* Expression: Vinit
                                        * Referenced by: '<S165>/Constant'
                                        */
  real_T Switch_Threshold_a;           /* Expression: 0.5
                                        * Referenced by: '<S165>/Switch'
                                        */
  real_T Integ4_gainval_a;             /* Computed Parameter: Integ4_gainval_a
                                        * Referenced by: '<S166>/Integ4'
                                        */
  real_T Integ4_IC_om;                 /* Expression: 0
                                        * Referenced by: '<S166>/Integ4'
                                        */
  real_T Toavoiddivisionbyzero_UpperS_fc;/* Expression: 1e6
                                          * Referenced by: '<S166>/To avoid division by zero'
                                          */
  real_T Toavoiddivisionbyzero_LowerSa_h;/* Expression: 1e-6
                                          * Referenced by: '<S166>/To avoid division by zero'
                                          */
  real_T Gain_Gain_kv;                 /* Expression: Ts
                                        * Referenced by: '<S166>/Gain'
                                        */
  real_T UnitDelay_InitialCondition_p; /* Expression: 0
                                        * Referenced by: '<S169>/Unit Delay'
                                        */
  real_T Step_Time_l;                  /* Expression: 1/Finit
                                        * Referenced by: '<S166>/Step'
                                        */
  real_T Step_Y0_d;                    /* Expression: 0
                                        * Referenced by: '<S166>/Step'
                                        */
  real_T Step_YFinal_pt;               /* Expression: 1
                                        * Referenced by: '<S166>/Step'
                                        */
  real_T Constant_Value_g;             /* Expression: Vinit
                                        * Referenced by: '<S166>/Constant'
                                        */
  real_T Switch_Threshold_ap;          /* Expression: 0.5
                                        * Referenced by: '<S166>/Switch'
                                        */
  real_T RadDeg_Gain_e;                /* Expression: 180/pi
                                        * Referenced by: '<S163>/Rad->Deg.'
                                        */
  real_T Saturation_UpperSat_c;        /* Expression: 2
                                        * Referenced by: '<S159>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: 0.01
                                        * Referenced by: '<S159>/Saturation'
                                        */
  real_T Gain1_Gain_mj;                /* Expression: 0.5
                                        * Referenced by: '<S172>/Gain1'
                                        */
  real_T Gain1_Gain_as;                /* Expression: 0.5
                                        * Referenced by: '<S183>/Gain1'
                                        */
  real_T Gain1_Gain_om;                /* Expression: 0.5
                                        * Referenced by: '<S185>/Gain1'
                                        */
  real_T Gain_Y0_k;                    /* Expression: [1]
                                        * Referenced by: '<S175>/Gain'
                                        */
  real_T Gain1_Gain_n3;                /* Expression: 2
                                        * Referenced by: '<S179>/Gain1'
                                        */
  real_T Integ4_gainval_f;             /* Computed Parameter: Integ4_gainval_f
                                        * Referenced by: '<S181>/Integ4'
                                        */
  real_T Integ4_IC_h;                  /* Expression: 0
                                        * Referenced by: '<S181>/Integ4'
                                        */
  real_T Toavoiddivisionbyzero_UpperS_au;/* Expression: 1e6
                                          * Referenced by: '<S181>/To avoid division by zero'
                                          */
  real_T Toavoiddivisionbyzero_LowerS_fy;/* Expression: 1e-6
                                          * Referenced by: '<S181>/To avoid division by zero'
                                          */
  real_T Gain_Gain_mb;                 /* Expression: Ts
                                        * Referenced by: '<S181>/Gain'
                                        */
  real_T UnitDelay_InitialCondition_jg;/* Expression: 0
                                        * Referenced by: '<S183>/Unit Delay'
                                        */
  real_T Step_Time_e;                  /* Expression: 1/Finit
                                        * Referenced by: '<S181>/Step'
                                        */
  real_T Step_Y0_m;                    /* Expression: 0
                                        * Referenced by: '<S181>/Step'
                                        */
  real_T Step_YFinal_m;                /* Expression: 1
                                        * Referenced by: '<S181>/Step'
                                        */
  real_T Constant_Value_d;             /* Expression: Vinit
                                        * Referenced by: '<S181>/Constant'
                                        */
  real_T Switch_Threshold_n;           /* Expression: 0.5
                                        * Referenced by: '<S181>/Switch'
                                        */
  real_T Integ4_gainval_i;             /* Computed Parameter: Integ4_gainval_i
                                        * Referenced by: '<S182>/Integ4'
                                        */
  real_T Integ4_IC_m;                  /* Expression: 0
                                        * Referenced by: '<S182>/Integ4'
                                        */
  real_T Toavoiddivisionbyzero_UpperSa_m;/* Expression: 1e6
                                          * Referenced by: '<S182>/To avoid division by zero'
                                          */
  real_T Toavoiddivisionbyzero_LowerSa_k;/* Expression: 1e-6
                                          * Referenced by: '<S182>/To avoid division by zero'
                                          */
  real_T Gain_Gain_lx;                 /* Expression: Ts
                                        * Referenced by: '<S182>/Gain'
                                        */
  real_T UnitDelay_InitialCondition_c; /* Expression: 0
                                        * Referenced by: '<S185>/Unit Delay'
                                        */
  real_T Step_Time_p;                  /* Expression: 1/Finit
                                        * Referenced by: '<S182>/Step'
                                        */
  real_T Step_Y0_b;                    /* Expression: 0
                                        * Referenced by: '<S182>/Step'
                                        */
  real_T Step_YFinal_c;                /* Expression: 1
                                        * Referenced by: '<S182>/Step'
                                        */
  real_T Constant_Value_i;             /* Expression: Vinit
                                        * Referenced by: '<S182>/Constant'
                                        */
  real_T Switch_Threshold_b;           /* Expression: 0.5
                                        * Referenced by: '<S182>/Switch'
                                        */
  real_T RadDeg_Gain_a;                /* Expression: 180/pi
                                        * Referenced by: '<S179>/Rad->Deg.'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: 2
                                        * Referenced by: '<S175>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: 0.01
                                        * Referenced by: '<S175>/Saturation'
                                        */
  real_T Gain1_Gain_cb;                /* Expression: 0.5
                                        * Referenced by: '<S188>/Gain1'
                                        */
  real_T group1gridtiedparameters_Valu_b[7];/* Expression: [relay_settings(9:15)]
                                             * Referenced by: '<S111>/group#1 - gridtied parameters'
                                             */
  real_T group2islandedparameters_Valu_n[7];/* Expression: [relay_settings(16:22)]
                                             * Referenced by: '<S111>/group#2 - islanded parameters'
                                             */
  real_T SFunction_P1_Size[2];         /* Computed Parameter: SFunction_P1_Size
                                        * Referenced by: '<S198>/S-Function'
                                        */
  real_T SFunction_P1;                 /* Expression: dest
                                        * Referenced by: '<S198>/S-Function'
                                        */
  real_T SFunction_P2_Size[2];         /* Computed Parameter: SFunction_P2_Size
                                        * Referenced by: '<S198>/S-Function'
                                        */
  real_T SFunction_P2;                 /* Expression: priority2
                                        * Referenced by: '<S198>/S-Function'
                                        */
  real_T SFunction_P3_Size[2];         /* Computed Parameter: SFunction_P3_Size
                                        * Referenced by: '<S198>/S-Function'
                                        */
  real_T SFunction_P3;                 /* Expression: st
                                        * Referenced by: '<S198>/S-Function'
                                        */
  real_T SFunction1_Value;             /* Expression: 0
                                        * Referenced by: '<S2>/S-Function1'
                                        */
  real_T SFunction_X0;                 /* Expression: 0
                                        * Referenced by: '<S2>/S-Function'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S5>/Memory1'
                                        */
  real_T Memory8_X0;                   /* Expression: 0
                                        * Referenced by: '<S5>/Memory8'
                                        */
  real_T Memory3_1_X0;                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory3'
                                        */
  real_T Memory3_2_X0;                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory3'
                                        */
  real_T Memory3_3_X0;                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory3'
                                        */
  real_T Memory3_4_X0;                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory3'
                                        */
  real_T Memory3_5_X0;                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory3'
                                        */
  real_T Memory3_6_X0;                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory3'
                                        */
  real_T Memory3_7_X0;                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory3'
                                        */
  real_T Memory3_8_X0;                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory3'
                                        */
  real_T Memory3_9_X0;                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory3'
                                        */
  real_T Memory3_10_X0;                /* Expression: 0
                                        * Referenced by: '<S5>/Memory3'
                                        */
  real_T Memory1_X0_l;                 /* Expression: 0
                                        * Referenced by: '<S6>/Memory1'
                                        */
  real_T Memory8_X0_o;                 /* Expression: 0
                                        * Referenced by: '<S6>/Memory8'
                                        */
  real_T Memory3_1_X0_b;               /* Expression: 0
                                        * Referenced by: '<S6>/Memory3'
                                        */
  real_T Memory3_2_X0_b;               /* Expression: 0
                                        * Referenced by: '<S6>/Memory3'
                                        */
  real_T Memory3_3_X0_b;               /* Expression: 0
                                        * Referenced by: '<S6>/Memory3'
                                        */
  real_T Memory3_4_X0_b;               /* Expression: 0
                                        * Referenced by: '<S6>/Memory3'
                                        */
  real_T Memory3_5_X0_b;               /* Expression: 0
                                        * Referenced by: '<S6>/Memory3'
                                        */
  real_T Memory3_6_X0_b;               /* Expression: 0
                                        * Referenced by: '<S6>/Memory3'
                                        */
  real_T Memory3_7_X0_b;               /* Expression: 0
                                        * Referenced by: '<S6>/Memory3'
                                        */
  real_T Memory3_8_X0_b;               /* Expression: 0
                                        * Referenced by: '<S6>/Memory3'
                                        */
  real_T Memory3_9_X0_b;               /* Expression: 0
                                        * Referenced by: '<S6>/Memory3'
                                        */
  real_T Memory3_10_X0_b;              /* Expression: 0
                                        * Referenced by: '<S6>/Memory3'
                                        */
  real_T SFunction_P1_Size_g[2];       /* Computed Parameter: SFunction_P1_Size_g
                                        * Referenced by: '<S197>/S-Function'
                                        */
  real_T SFunction_P1_h;               /* Expression: Acqu_group
                                        * Referenced by: '<S197>/S-Function'
                                        */
  real_T SFunction_P1_Size_p[2];       /* Computed Parameter: SFunction_P1_Size_p
                                        * Referenced by: '<S199>/S-Function'
                                        */
  real_T SFunction_P1_j;               /* Expression: src
                                        * Referenced by: '<S199>/S-Function'
                                        */
  real_T SFunction_P2_Size_c[2];       /* Computed Parameter: SFunction_P2_Size_c
                                        * Referenced by: '<S199>/S-Function'
                                        */
  real_T SFunction_P2_h;               /* Expression: Data_width
                                        * Referenced by: '<S199>/S-Function'
                                        */
  real_T SFunction_P3_Size_g[2];       /* Computed Parameter: SFunction_P3_Size_g
                                        * Referenced by: '<S199>/S-Function'
                                        */
  real_T SFunction_P3_e;               /* Expression: st
                                        * Referenced by: '<S199>/S-Function'
                                        */
  real_T baseparameters_Value[8];      /* Expression: [relay_settings(1:8)]
                                        * Referenced by: '<S20>/base parameters'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S10>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: Phase_Init*pi/180
                                        * Referenced by: '<S10>/Discrete-Time Integrator'
                                        */
  real_T Constant4_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S10>/Constant4'
                                        */
  real_T K1_Value;                     /* Expression: 0.5
                                        * Referenced by: '<S29>/K1'
                                        */
  real_T K2_Value;                     /* Expression: sqrt(3)/2
                                        * Referenced by: '<S29>/K2'
                                        */
  real_T Integ4_gainval_g;             /* Computed Parameter: Integ4_gainval_g
                                        * Referenced by: '<S28>/Integ4'
                                        */
  real_T Integ4_IC_bo;                 /* Expression: 0
                                        * Referenced by: '<S28>/Integ4'
                                        */
  real_T K1_Value_n;                   /* Expression: Delay
                                        * Referenced by: '<S28>/K1'
                                        */
  real_T K2_Value_i;                   /* Expression: Freq
                                        * Referenced by: '<S28>/K2'
                                        */
  real_T UnitDelay_InitialCondition_h; /* Expression: 0
                                        * Referenced by: '<S28>/Unit Delay'
                                        */
  real_T Step_Time_j;                  /* Expression: 1/Freq
                                        * Referenced by: '<S28>/Step'
                                        */
  real_T Step_Y0_ky;                   /* Expression: 0
                                        * Referenced by: '<S28>/Step'
                                        */
  real_T Step_YFinal_ps;               /* Expression: 1
                                        * Referenced by: '<S28>/Step'
                                        */
  real_T Constant_Value_f;             /* Expression: Vinit
                                        * Referenced by: '<S28>/Constant'
                                        */
  real_T Switch_Threshold_k2;          /* Expression: 0.5
                                        * Referenced by: '<S28>/Switch'
                                        */
  real_T Kp4_Gain;                     /* Expression: Kp
                                        * Referenced by: '<S26>/Kp4'
                                        */
  real_T DiscreteTimeIntegrator_gainva_f;/* Computed Parameter: DiscreteTimeIntegrator_gainva_f
                                          * Referenced by: '<S26>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_m;  /* Expression: Init
                                        * Referenced by: '<S26>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: UpperLimit
                                          * Referenced by: '<S26>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: LowerLimit
                                          * Referenced by: '<S26>/Discrete-Time Integrator'
                                          */
  real_T Kp6_Gain;                     /* Expression: Kd
                                        * Referenced by: '<S26>/Kp6'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S30>/TSamp'
                                        */
  real_T UD_InitialCondition;          /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S30>/UD'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: UpperLimit
                                        * Referenced by: '<S26>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: LowerLimit
                                        * Referenced by: '<S26>/Saturation2'
                                        */
  real_T Gain10_Gain;                  /* Expression: 1/2/pi
                                        * Referenced by: '<S10>/Gain10'
                                        */
  real_T UnitDelay_InitialCondition_ia;/* Expression: Vinit
                                        * Referenced by: '<S27>/Unit  Delay'
                                        */
  real_T Saturation_UpperSat_m;        /* Expression: UpperLimit
                                        * Referenced by: '<S27>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: LowerLimit
                                        * Referenced by: '<S27>/Saturation'
                                        */
  real_T DiscreteStateSpace_A[4];      /* Computed Parameter: DiscreteStateSpace_A
                                        * Referenced by: '<S25>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_B[2];      /* Computed Parameter: DiscreteStateSpace_B
                                        * Referenced by: '<S25>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_C[2];      /* Computed Parameter: DiscreteStateSpace_C
                                        * Referenced by: '<S25>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_D;         /* Computed Parameter: DiscreteStateSpace_D
                                        * Referenced by: '<S25>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_X0[2];     /* Expression: x0d
                                        * Referenced by: '<S25>/Discrete State-Space'
                                        */
  real_T Kp5_Gain;                     /* Expression: Ki
                                        * Referenced by: '<S26>/Kp5'
                                        */
  real_T UnitDelay_InitialCondition_k; /* Expression: Finit
                                        * Referenced by: '<S10>/Unit Delay'
                                        */
  real_T Gain1_Gain_a0;                /* Expression: 1/3
                                        * Referenced by: '<S29>/Gain1'
                                        */
  real_T Gain21_Gain;                  /* Expression: 1.414
                                        * Referenced by: '<S5>/Gain21'
                                        */
  real_T DiscreteTimeIntegrator_gainva_k;/* Computed Parameter: DiscreteTimeIntegrator_gainva_k
                                          * Referenced by: '<S11>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_l;  /* Expression: Phase_Init*pi/180
                                        * Referenced by: '<S11>/Discrete-Time Integrator'
                                        */
  real_T Constant4_Value_o;            /* Expression: 2*pi
                                        * Referenced by: '<S11>/Constant4'
                                        */
  real_T K1_Value_d;                   /* Expression: 0.5
                                        * Referenced by: '<S36>/K1'
                                        */
  real_T K2_Value_e;                   /* Expression: sqrt(3)/2
                                        * Referenced by: '<S36>/K2'
                                        */
  real_T Integ4_gainval_nf;            /* Computed Parameter: Integ4_gainval_nf
                                        * Referenced by: '<S35>/Integ4'
                                        */
  real_T Integ4_IC_f;                  /* Expression: 0
                                        * Referenced by: '<S35>/Integ4'
                                        */
  real_T K1_Value_l;                   /* Expression: Delay
                                        * Referenced by: '<S35>/K1'
                                        */
  real_T K2_Value_c;                   /* Expression: Freq
                                        * Referenced by: '<S35>/K2'
                                        */
  real_T UnitDelay_InitialCondition_a; /* Expression: 0
                                        * Referenced by: '<S35>/Unit Delay'
                                        */
  real_T Step_Time_b;                  /* Expression: 1/Freq
                                        * Referenced by: '<S35>/Step'
                                        */
  real_T Step_Y0_l;                    /* Expression: 0
                                        * Referenced by: '<S35>/Step'
                                        */
  real_T Step_YFinal_cz;               /* Expression: 1
                                        * Referenced by: '<S35>/Step'
                                        */
  real_T Constant_Value_gq;            /* Expression: Vinit
                                        * Referenced by: '<S35>/Constant'
                                        */
  real_T Switch_Threshold_ad;          /* Expression: 0.5
                                        * Referenced by: '<S35>/Switch'
                                        */
  real_T Kp4_Gain_i;                   /* Expression: Kp
                                        * Referenced by: '<S33>/Kp4'
                                        */
  real_T DiscreteTimeIntegrator_gainva_c;/* Computed Parameter: DiscreteTimeIntegrator_gainva_c
                                          * Referenced by: '<S33>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_me; /* Expression: Init
                                        * Referenced by: '<S33>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperS_a;/* Expression: UpperLimit
                                          * Referenced by: '<S33>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_n;/* Expression: LowerLimit
                                          * Referenced by: '<S33>/Discrete-Time Integrator'
                                          */
  real_T Kp6_Gain_j;                   /* Expression: Kd
                                        * Referenced by: '<S33>/Kp6'
                                        */
  real_T TSamp_WtEt_n;                 /* Computed Parameter: TSamp_WtEt_n
                                        * Referenced by: '<S37>/TSamp'
                                        */
  real_T UD_InitialCondition_e;        /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S37>/UD'
                                        */
  real_T Saturation2_UpperSat_j;       /* Expression: UpperLimit
                                        * Referenced by: '<S33>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_h;       /* Expression: LowerLimit
                                        * Referenced by: '<S33>/Saturation2'
                                        */
  real_T Gain10_Gain_h;                /* Expression: 1/2/pi
                                        * Referenced by: '<S11>/Gain10'
                                        */
  real_T UnitDelay_InitialCondition_aa;/* Expression: Vinit
                                        * Referenced by: '<S34>/Unit  Delay'
                                        */
  real_T Saturation_UpperSat_lx;       /* Expression: UpperLimit
                                        * Referenced by: '<S34>/Saturation'
                                        */
  real_T Saturation_LowerSat_f;        /* Expression: LowerLimit
                                        * Referenced by: '<S34>/Saturation'
                                        */
  real_T DiscreteStateSpace_A_o[4];    /* Computed Parameter: DiscreteStateSpace_A_o
                                        * Referenced by: '<S32>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_B_o[2];    /* Computed Parameter: DiscreteStateSpace_B_o
                                        * Referenced by: '<S32>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_C_b[2];    /* Computed Parameter: DiscreteStateSpace_C_b
                                        * Referenced by: '<S32>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_D_h;       /* Computed Parameter: DiscreteStateSpace_D_h
                                        * Referenced by: '<S32>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_X0_i[2];   /* Expression: x0d
                                        * Referenced by: '<S32>/Discrete State-Space'
                                        */
  real_T Kp5_Gain_o;                   /* Expression: Ki
                                        * Referenced by: '<S33>/Kp5'
                                        */
  real_T UnitDelay_InitialCondition_b; /* Expression: Finit
                                        * Referenced by: '<S11>/Unit Delay'
                                        */
  real_T Gain1_Gain_n1;                /* Expression: 1/3
                                        * Referenced by: '<S36>/Gain1'
                                        */
  real_T puV_Gain;                     /* Expression: 1/sqrt(3)
                                        * Referenced by: '<S48>/pu->V'
                                        */
  real_T Integ4_gainval_f3;            /* Computed Parameter: Integ4_gainval_f3
                                        * Referenced by: '<S49>/Integ4'
                                        */
  real_T Integ4_IC_i4;                 /* Expression: 0
                                        * Referenced by: '<S49>/Integ4'
                                        */
  real_T K1_Value_m;                   /* Expression: Delay
                                        * Referenced by: '<S49>/K1'
                                        */
  real_T K2_Value_b;                   /* Expression: Freq
                                        * Referenced by: '<S49>/K2'
                                        */
  real_T UnitDelay_InitialCondition_f; /* Expression: 0
                                        * Referenced by: '<S49>/Unit Delay'
                                        */
  real_T Step_Time_d;                  /* Expression: 1/Freq
                                        * Referenced by: '<S49>/Step'
                                        */
  real_T Step_Y0_e;                    /* Expression: 0
                                        * Referenced by: '<S49>/Step'
                                        */
  real_T Step_YFinal_a;                /* Expression: 1
                                        * Referenced by: '<S49>/Step'
                                        */
  real_T Constant_Value_h;             /* Expression: Vinit
                                        * Referenced by: '<S49>/Constant'
                                        */
  real_T Switch_Threshold_e;           /* Expression: 0.5
                                        * Referenced by: '<S49>/Switch'
                                        */
  real_T Constant_Value_io;            /* Expression: const
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T Constant_Value_j;             /* Expression: const
                                        * Referenced by: '<S40>/Constant'
                                        */
  real_T Constant_Value_c;             /* Expression: const
                                        * Referenced by: '<S41>/Constant'
                                        */
  real_T Constant_Value_k;             /* Expression: const
                                        * Referenced by: '<S42>/Constant'
                                        */
  real_T FixPtUnitDelay1_InitialConditio;/* Expression: vinit
                                          * Referenced by: '<S43>/FixPt Unit Delay1'
                                          */
  real_T Constant1_Value;              /* Expression: 2/60
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0.1
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Constant4_Value_g;            /* Expression: Ts
                                        * Referenced by: '<S5>/Constant4'
                                        */
  real_T a4_Value;                     /* Expression: Ts
                                        * Referenced by: '<S23>/a4'
                                        */
  real_T SFunction_P1_Size_c[2];       /* Computed Parameter: SFunction_P1_Size_c
                                        * Referenced by: '<S192>/S-Function'
                                        */
  real_T SFunction_P1_k;               /* Expression: Data_width
                                        * Referenced by: '<S192>/S-Function'
                                        */
  real_T SFunction_P2_Size_i[2];       /* Computed Parameter: SFunction_P2_Size_i
                                        * Referenced by: '<S192>/S-Function'
                                        */
  real_T SFunction_P2_l[6];            /* Expression: InitialConditions
                                        * Referenced by: '<S192>/S-Function'
                                        */
  real_T Integ4_gainval_cf;            /* Computed Parameter: Integ4_gainval_cf
                                        * Referenced by: '<S51>/Integ4'
                                        */
  real_T Integ4_IC_k;                  /* Expression: 0
                                        * Referenced by: '<S51>/Integ4'
                                        */
  real_T K1_Value_b;                   /* Expression: Delay
                                        * Referenced by: '<S51>/K1'
                                        */
  real_T K2_Value_g;                   /* Expression: Freq
                                        * Referenced by: '<S51>/K2'
                                        */
  real_T UnitDelay_InitialCondition_jv;/* Expression: 0
                                        * Referenced by: '<S51>/Unit Delay'
                                        */
  real_T Step_Time_dt;                 /* Expression: 1/Freq
                                        * Referenced by: '<S51>/Step'
                                        */
  real_T Step_Y0_ih;                   /* Expression: 0
                                        * Referenced by: '<S51>/Step'
                                        */
  real_T Step_YFinal_i;                /* Expression: 1
                                        * Referenced by: '<S51>/Step'
                                        */
  real_T Constant_Value_b;             /* Expression: Vinit
                                        * Referenced by: '<S51>/Constant'
                                        */
  real_T Switch_Threshold_b2;          /* Expression: 0.5
                                        * Referenced by: '<S51>/Switch'
                                        */
  real_T Integ4_gainval_b;             /* Computed Parameter: Integ4_gainval_b
                                        * Referenced by: '<S53>/Integ4'
                                        */
  real_T Integ4_IC_fb;                 /* Expression: 0
                                        * Referenced by: '<S53>/Integ4'
                                        */
  real_T K1_Value_d5;                  /* Expression: Delay
                                        * Referenced by: '<S53>/K1'
                                        */
  real_T K2_Value_d;                   /* Expression: Freq
                                        * Referenced by: '<S53>/K2'
                                        */
  real_T UnitDelay_InitialCondition_aw;/* Expression: 0
                                        * Referenced by: '<S53>/Unit Delay'
                                        */
  real_T Step_Time_pt;                 /* Expression: 1/Freq
                                        * Referenced by: '<S53>/Step'
                                        */
  real_T Step_Y0_de;                   /* Expression: 0
                                        * Referenced by: '<S53>/Step'
                                        */
  real_T Step_YFinal_k;                /* Expression: 1
                                        * Referenced by: '<S53>/Step'
                                        */
  real_T Constant_Value_dm;            /* Expression: Vinit
                                        * Referenced by: '<S53>/Constant'
                                        */
  real_T Switch_Threshold_e1;          /* Expression: 0.5
                                        * Referenced by: '<S53>/Switch'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 1/1.732025
                                        * Referenced by: '<S23>/Gain'
                                        */
  real_T Switch_Threshold_m;           /* Expression: 0.5
                                        * Referenced by: '<S20>/Switch'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/1.732
                                        * Referenced by: '<S5>/Gain2'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 2^3
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Gain1_Gain_dm;                /* Expression: 100
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T Gain10_Gain_p;                /* Expression: 1/1000
                                        * Referenced by: '<S5>/Gain10'
                                        */
  real_T Constant5_Value;              /* Expression: 120
                                        * Referenced by: '<S16>/Constant5'
                                        */
  real_T Constant7_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S16>/Constant7'
                                        */
  real_T Gain11_Gain;                  /* Expression: 10
                                        * Referenced by: '<S5>/Gain11'
                                        */
  real_T Gain12_Gain;                  /* Expression: 10
                                        * Referenced by: '<S5>/Gain12'
                                        */
  real_T Gain13_Gain;                  /* Expression: 2
                                        * Referenced by: '<S5>/Gain13'
                                        */
  real_T Gain14_Gain;                  /* Expression: 2^14
                                        * Referenced by: '<S5>/Gain14'
                                        */
  real_T Gain15_Gain;                  /* Expression: 1.4142
                                        * Referenced by: '<S5>/Gain15'
                                        */
  real_T Gain16_Gain;                  /* Expression: 1.4142
                                        * Referenced by: '<S5>/Gain16'
                                        */
  real_T Gain17_Gain;                  /* Expression: 1.4142
                                        * Referenced by: '<S5>/Gain17'
                                        */
  real_T Gain18_Gain;                  /* Expression: 1.4142
                                        * Referenced by: '<S5>/Gain18'
                                        */
  real_T Gain19_Gain;                  /* Expression: 1.4142
                                        * Referenced by: '<S5>/Gain19'
                                        */
  real_T Gain20_Gain;                  /* Expression: 1.4142
                                        * Referenced by: '<S5>/Gain20'
                                        */
  real_T Constant6_Value;              /* Expression: 120
                                        * Referenced by: '<S15>/Constant6'
                                        */
  real_T Constant8_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S15>/Constant8'
                                        */
  real_T Gain3_Gain;                   /* Expression: 10
                                        * Referenced by: '<S5>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: 10
                                        * Referenced by: '<S5>/Gain4'
                                        */
  real_T Constant5_Value_b;            /* Expression: 120
                                        * Referenced by: '<S15>/Constant5'
                                        */
  real_T Constant7_Value_b;            /* Expression: 2*pi
                                        * Referenced by: '<S15>/Constant7'
                                        */
  real_T Gain5_Gain;                   /* Expression: 10
                                        * Referenced by: '<S5>/Gain5'
                                        */
  real_T Gain6_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<S5>/Gain6'
                                        */
  real_T Gain7_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<S5>/Gain7'
                                        */
  real_T Gain8_Gain;                   /* Expression: 10
                                        * Referenced by: '<S5>/Gain8'
                                        */
  real_T Constant6_Value_h;            /* Expression: 120
                                        * Referenced by: '<S16>/Constant6'
                                        */
  real_T Constant8_Value_l;            /* Expression: 2*pi
                                        * Referenced by: '<S16>/Constant8'
                                        */
  real_T Gain9_Gain;                   /* Expression: 10
                                        * Referenced by: '<S5>/Gain9'
                                        */
  real_T never_reset_Value;            /* Expression: 0
                                        * Referenced by: '<S13>/never_reset'
                                        */
  real_T DelayInput1_InitialCondition; /* Expression: vinit
                                        * Referenced by: '<S46>/Delay Input1'
                                        */
  real_T Integ4_gainval_me;            /* Computed Parameter: Integ4_gainval_me
                                        * Referenced by: '<S63>/Integ4'
                                        */
  real_T Integ4_IC_ke;                 /* Expression: 0
                                        * Referenced by: '<S63>/Integ4'
                                        */
  real_T K1_Value_j;                   /* Expression: Delay
                                        * Referenced by: '<S63>/K1'
                                        */
  real_T K2_Value_k;                   /* Expression: Freq
                                        * Referenced by: '<S63>/K2'
                                        */
  real_T UnitDelay_InitialCondition_k3;/* Expression: 0
                                        * Referenced by: '<S63>/Unit Delay'
                                        */
  real_T Step_Time_p0;                 /* Expression: 1/Freq
                                        * Referenced by: '<S63>/Step'
                                        */
  real_T Step_Y0_o;                    /* Expression: 0
                                        * Referenced by: '<S63>/Step'
                                        */
  real_T Step_YFinal_ii;               /* Expression: 1
                                        * Referenced by: '<S63>/Step'
                                        */
  real_T Constant_Value_n;             /* Expression: Vinit
                                        * Referenced by: '<S63>/Constant'
                                        */
  real_T Switch_Threshold_et;          /* Expression: 0.5
                                        * Referenced by: '<S63>/Switch'
                                        */
  real_T sqrt3_Gain;                   /* Expression: 1.7321
                                        * Referenced by: '<S19>/sqrt3'
                                        */
  real_T UnitDelay_InitialCondition_cg;/* Expression: Finit
                                        * Referenced by: '<S66>/Unit Delay'
                                        */
  real_T UnitDelay_InitialCondition_ab;/* Expression: Finit
                                        * Referenced by: '<S65>/Unit Delay'
                                        */
  real_T DiscreteTimeIntegrator_gainva_n;/* Computed Parameter: DiscreteTimeIntegrator_gainva_n
                                          * Referenced by: '<S66>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_p;  /* Expression: Phase_Init*pi/180
                                        * Referenced by: '<S66>/Discrete-Time Integrator'
                                        */
  real_T Constant4_Value_d;            /* Expression: 2*pi
                                        * Referenced by: '<S66>/Constant4'
                                        */
  real_T DiscreteTimeIntegrator_gainva_l;/* Computed Parameter: DiscreteTimeIntegrator_gainva_l
                                          * Referenced by: '<S65>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_b;  /* Expression: Phase_Init*pi/180
                                        * Referenced by: '<S65>/Discrete-Time Integrator'
                                        */
  real_T Constant4_Value_e;            /* Expression: 2*pi
                                        * Referenced by: '<S65>/Constant4'
                                        */
  real_T Constant3_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S56>/Constant3'
                                        */
  real_T Gain_Gain_bc;                 /* Expression: 180/pi
                                        * Referenced by: '<S62>/Gain'
                                        */
  real_T Memory2_X0;                   /* Expression: 0
                                        * Referenced by: '<S5>/Memory2'
                                        */
  real_T Memory9_X0;                   /* Expression: 0
                                        * Referenced by: '<S5>/Memory9'
                                        */
  real_T Integ4_gainval_e;             /* Computed Parameter: Integ4_gainval_e
                                        * Referenced by: '<S71>/Integ4'
                                        */
  real_T Integ4_IC_j;                  /* Expression: 0
                                        * Referenced by: '<S71>/Integ4'
                                        */
  real_T Toavoiddivisionbyzero_UpperSa_g;/* Expression: 1e6
                                          * Referenced by: '<S71>/To avoid division by zero'
                                          */
  real_T Toavoiddivisionbyzero_LowerS_gb;/* Expression: 1e-6
                                          * Referenced by: '<S71>/To avoid division by zero'
                                          */
  real_T Gain_Gain_h2;                 /* Expression: Ts
                                        * Referenced by: '<S71>/Gain'
                                        */
  real_T UnitDelay_InitialCondition_ij;/* Expression: 0
                                        * Referenced by: '<S81>/Unit Delay'
                                        */
  real_T Step_Time_ls;                 /* Expression: 1/Finit
                                        * Referenced by: '<S71>/Step'
                                        */
  real_T Step_Y0_c;                    /* Expression: 0
                                        * Referenced by: '<S71>/Step'
                                        */
  real_T Step_YFinal_g;                /* Expression: 1
                                        * Referenced by: '<S71>/Step'
                                        */
  real_T Constant_Value_g5;            /* Expression: Vinit
                                        * Referenced by: '<S71>/Constant'
                                        */
  real_T Switch_Threshold_am;          /* Expression: 0.5
                                        * Referenced by: '<S71>/Switch'
                                        */
  real_T Constant1_Value_b;            /* Expression: AGC
                                        * Referenced by: '<S65>/Constant1'
                                        */
  real_T Kp4_Gain_i3;                  /* Expression: Kp
                                        * Referenced by: '<S69>/Kp4'
                                        */
  real_T DiscreteTimeIntegrator_gainva_m;/* Computed Parameter: DiscreteTimeIntegrator_gainva_m
                                          * Referenced by: '<S69>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_m2; /* Expression: Init
                                        * Referenced by: '<S69>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperS_k;/* Expression: UpperLimit
                                          * Referenced by: '<S69>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_h;/* Expression: LowerLimit
                                          * Referenced by: '<S69>/Discrete-Time Integrator'
                                          */
  real_T Kp6_Gain_d;                   /* Expression: Kd
                                        * Referenced by: '<S69>/Kp6'
                                        */
  real_T TSamp_WtEt_n0;                /* Computed Parameter: TSamp_WtEt_n0
                                        * Referenced by: '<S80>/TSamp'
                                        */
  real_T UD_InitialCondition_k;        /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S80>/UD'
                                        */
  real_T Saturation2_UpperSat_n;       /* Expression: UpperLimit
                                        * Referenced by: '<S69>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_ha;      /* Expression: LowerLimit
                                        * Referenced by: '<S69>/Saturation2'
                                        */
  real_T Gain10_Gain_g;                /* Expression: 1/2/pi
                                        * Referenced by: '<S65>/Gain10'
                                        */
  real_T UnitDelay_InitialCondition_bu;/* Expression: Vinit
                                        * Referenced by: '<S70>/Unit  Delay'
                                        */
  real_T Saturation_UpperSat_j;        /* Expression: UpperLimit
                                        * Referenced by: '<S70>/Saturation'
                                        */
  real_T Saturation_LowerSat_m;        /* Expression: LowerLimit
                                        * Referenced by: '<S70>/Saturation'
                                        */
  real_T DiscreteStateSpace_A_g[4];    /* Computed Parameter: DiscreteStateSpace_A_g
                                        * Referenced by: '<S67>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_B_a[2];    /* Computed Parameter: DiscreteStateSpace_B_a
                                        * Referenced by: '<S67>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_C_l[2];    /* Computed Parameter: DiscreteStateSpace_C_l
                                        * Referenced by: '<S67>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_D_l;       /* Computed Parameter: DiscreteStateSpace_D_l
                                        * Referenced by: '<S67>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_X0_o[2];   /* Expression: x0d
                                        * Referenced by: '<S67>/Discrete State-Space'
                                        */
  real_T Kp5_Gain_l;                   /* Expression: Ki
                                        * Referenced by: '<S69>/Kp5'
                                        */
  real_T Integ4_gainval_hr;            /* Computed Parameter: Integ4_gainval_hr
                                        * Referenced by: '<S87>/Integ4'
                                        */
  real_T Integ4_IC_j3;                 /* Expression: 0
                                        * Referenced by: '<S87>/Integ4'
                                        */
  real_T Toavoiddivisionbyzero_UpperS_mf;/* Expression: 1e6
                                          * Referenced by: '<S87>/To avoid division by zero'
                                          */
  real_T Toavoiddivisionbyzero_LowerS_mf;/* Expression: 1e-6
                                          * Referenced by: '<S87>/To avoid division by zero'
                                          */
  real_T Gain_Gain_ni;                 /* Expression: Ts
                                        * Referenced by: '<S87>/Gain'
                                        */
  real_T UnitDelay_InitialCondition_ff;/* Expression: 0
                                        * Referenced by: '<S97>/Unit Delay'
                                        */
  real_T Step_Time_l0;                 /* Expression: 1/Finit
                                        * Referenced by: '<S87>/Step'
                                        */
  real_T Step_Y0_p;                    /* Expression: 0
                                        * Referenced by: '<S87>/Step'
                                        */
  real_T Step_YFinal_ab;               /* Expression: 1
                                        * Referenced by: '<S87>/Step'
                                        */
  real_T Constant_Value_iq;            /* Expression: Vinit
                                        * Referenced by: '<S87>/Constant'
                                        */
  real_T Switch_Threshold_ni;          /* Expression: 0.5
                                        * Referenced by: '<S87>/Switch'
                                        */
  real_T Constant1_Value_bu;           /* Expression: AGC
                                        * Referenced by: '<S66>/Constant1'
                                        */
  real_T Kp4_Gain_b;                   /* Expression: Kp
                                        * Referenced by: '<S85>/Kp4'
                                        */
  real_T DiscreteTimeIntegrator_gainv_f4;/* Computed Parameter: DiscreteTimeIntegrator_gainv_f4
                                          * Referenced by: '<S85>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_i;  /* Expression: Init
                                        * Referenced by: '<S85>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperS_n;/* Expression: UpperLimit
                                          * Referenced by: '<S85>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_l;/* Expression: LowerLimit
                                          * Referenced by: '<S85>/Discrete-Time Integrator'
                                          */
  real_T Kp6_Gain_c;                   /* Expression: Kd
                                        * Referenced by: '<S85>/Kp6'
                                        */
  real_T TSamp_WtEt_k;                 /* Computed Parameter: TSamp_WtEt_k
                                        * Referenced by: '<S96>/TSamp'
                                        */
  real_T UD_InitialCondition_b;        /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S96>/UD'
                                        */
  real_T Saturation2_UpperSat_p;       /* Expression: UpperLimit
                                        * Referenced by: '<S85>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_d;       /* Expression: LowerLimit
                                        * Referenced by: '<S85>/Saturation2'
                                        */
  real_T Gain10_Gain_k;                /* Expression: 1/2/pi
                                        * Referenced by: '<S66>/Gain10'
                                        */
  real_T UnitDelay_InitialCondition_m; /* Expression: Vinit
                                        * Referenced by: '<S86>/Unit  Delay'
                                        */
  real_T Saturation_UpperSat_n;        /* Expression: UpperLimit
                                        * Referenced by: '<S86>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: LowerLimit
                                        * Referenced by: '<S86>/Saturation'
                                        */
  real_T DiscreteStateSpace_A_h[4];    /* Computed Parameter: DiscreteStateSpace_A_h
                                        * Referenced by: '<S83>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_B_ow[2];   /* Computed Parameter: DiscreteStateSpace_B_ow
                                        * Referenced by: '<S83>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_C_bf[2];   /* Computed Parameter: DiscreteStateSpace_C_bf
                                        * Referenced by: '<S83>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_D_d;       /* Computed Parameter: DiscreteStateSpace_D_d
                                        * Referenced by: '<S83>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_X0_j[2];   /* Expression: x0d
                                        * Referenced by: '<S83>/Discrete State-Space'
                                        */
  real_T Kp5_Gain_b;                   /* Expression: Ki
                                        * Referenced by: '<S85>/Kp5'
                                        */
  real_T baseparameters_Value_f[8];    /* Expression: [relay_settings(1:8)]
                                        * Referenced by: '<S111>/base parameters'
                                        */
  real_T DiscreteTimeIntegrator_gainva_b;/* Computed Parameter: DiscreteTimeIntegrator_gainva_b
                                          * Referenced by: '<S101>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_g;  /* Expression: Phase_Init*pi/180
                                        * Referenced by: '<S101>/Discrete-Time Integrator'
                                        */
  real_T Constant4_Value_a;            /* Expression: 2*pi
                                        * Referenced by: '<S101>/Constant4'
                                        */
  real_T K1_Value_ny;                  /* Expression: 0.5
                                        * Referenced by: '<S120>/K1'
                                        */
  real_T K2_Value_o;                   /* Expression: sqrt(3)/2
                                        * Referenced by: '<S120>/K2'
                                        */
  real_T Integ4_gainval_k;             /* Computed Parameter: Integ4_gainval_k
                                        * Referenced by: '<S119>/Integ4'
                                        */
  real_T Integ4_IC_mt;                 /* Expression: 0
                                        * Referenced by: '<S119>/Integ4'
                                        */
  real_T K1_Value_a;                   /* Expression: Delay
                                        * Referenced by: '<S119>/K1'
                                        */
  real_T K2_Value_ce;                  /* Expression: Freq
                                        * Referenced by: '<S119>/K2'
                                        */
  real_T UnitDelay_InitialCondition_l; /* Expression: 0
                                        * Referenced by: '<S119>/Unit Delay'
                                        */
  real_T Step_Time_i;                  /* Expression: 1/Freq
                                        * Referenced by: '<S119>/Step'
                                        */
  real_T Step_Y0_er;                   /* Expression: 0
                                        * Referenced by: '<S119>/Step'
                                        */
  real_T Step_YFinal_m3;               /* Expression: 1
                                        * Referenced by: '<S119>/Step'
                                        */
  real_T Constant_Value_jg;            /* Expression: Vinit
                                        * Referenced by: '<S119>/Constant'
                                        */
  real_T Switch_Threshold_ao;          /* Expression: 0.5
                                        * Referenced by: '<S119>/Switch'
                                        */
  real_T Kp4_Gain_e;                   /* Expression: Kp
                                        * Referenced by: '<S117>/Kp4'
                                        */
  real_T DiscreteTimeIntegrator_gainva_p;/* Computed Parameter: DiscreteTimeIntegrator_gainva_p
                                          * Referenced by: '<S117>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_b2; /* Expression: Init
                                        * Referenced by: '<S117>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperS_m;/* Expression: UpperLimit
                                          * Referenced by: '<S117>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_o;/* Expression: LowerLimit
                                          * Referenced by: '<S117>/Discrete-Time Integrator'
                                          */
  real_T Kp6_Gain_cp;                  /* Expression: Kd
                                        * Referenced by: '<S117>/Kp6'
                                        */
  real_T TSamp_WtEt_g;                 /* Computed Parameter: TSamp_WtEt_g
                                        * Referenced by: '<S121>/TSamp'
                                        */
  real_T UD_InitialCondition_p;        /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S121>/UD'
                                        */
  real_T Saturation2_UpperSat_o;       /* Expression: UpperLimit
                                        * Referenced by: '<S117>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_p;       /* Expression: LowerLimit
                                        * Referenced by: '<S117>/Saturation2'
                                        */
  real_T Gain10_Gain_d;                /* Expression: 1/2/pi
                                        * Referenced by: '<S101>/Gain10'
                                        */
  real_T UnitDelay_InitialCondition_o; /* Expression: Vinit
                                        * Referenced by: '<S118>/Unit  Delay'
                                        */
  real_T Saturation_UpperSat_p;        /* Expression: UpperLimit
                                        * Referenced by: '<S118>/Saturation'
                                        */
  real_T Saturation_LowerSat_g;        /* Expression: LowerLimit
                                        * Referenced by: '<S118>/Saturation'
                                        */
  real_T DiscreteStateSpace_A_m[4];    /* Computed Parameter: DiscreteStateSpace_A_m
                                        * Referenced by: '<S116>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_B_j[2];    /* Computed Parameter: DiscreteStateSpace_B_j
                                        * Referenced by: '<S116>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_C_c[2];    /* Computed Parameter: DiscreteStateSpace_C_c
                                        * Referenced by: '<S116>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_D_dp;      /* Computed Parameter: DiscreteStateSpace_D_dp
                                        * Referenced by: '<S116>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_X0_k[2];   /* Expression: x0d
                                        * Referenced by: '<S116>/Discrete State-Space'
                                        */
  real_T Kp5_Gain_e;                   /* Expression: Ki
                                        * Referenced by: '<S117>/Kp5'
                                        */
  real_T UnitDelay_InitialCondition_hc;/* Expression: Finit
                                        * Referenced by: '<S101>/Unit Delay'
                                        */
  real_T Gain1_Gain_in;                /* Expression: 1/3
                                        * Referenced by: '<S120>/Gain1'
                                        */
  real_T Gain21_Gain_k;                /* Expression: 1.414
                                        * Referenced by: '<S6>/Gain21'
                                        */
  real_T DiscreteTimeIntegrator_gainva_g;/* Computed Parameter: DiscreteTimeIntegrator_gainva_g
                                          * Referenced by: '<S102>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_e;  /* Expression: Phase_Init*pi/180
                                        * Referenced by: '<S102>/Discrete-Time Integrator'
                                        */
  real_T Constant4_Value_l;            /* Expression: 2*pi
                                        * Referenced by: '<S102>/Constant4'
                                        */
  real_T K1_Value_g;                   /* Expression: 0.5
                                        * Referenced by: '<S127>/K1'
                                        */
  real_T K2_Value_ek;                  /* Expression: sqrt(3)/2
                                        * Referenced by: '<S127>/K2'
                                        */
  real_T Integ4_gainval_g3;            /* Computed Parameter: Integ4_gainval_g3
                                        * Referenced by: '<S126>/Integ4'
                                        */
  real_T Integ4_IC_l;                  /* Expression: 0
                                        * Referenced by: '<S126>/Integ4'
                                        */
  real_T K1_Value_b2;                  /* Expression: Delay
                                        * Referenced by: '<S126>/K1'
                                        */
  real_T K2_Value_e1;                  /* Expression: Freq
                                        * Referenced by: '<S126>/K2'
                                        */
  real_T UnitDelay_InitialCondition_d; /* Expression: 0
                                        * Referenced by: '<S126>/Unit Delay'
                                        */
  real_T Step_Time_kr;                 /* Expression: 1/Freq
                                        * Referenced by: '<S126>/Step'
                                        */
  real_T Step_Y0_df;                   /* Expression: 0
                                        * Referenced by: '<S126>/Step'
                                        */
  real_T Step_YFinal_cr;               /* Expression: 1
                                        * Referenced by: '<S126>/Step'
                                        */
  real_T Constant_Value_g5s;           /* Expression: Vinit
                                        * Referenced by: '<S126>/Constant'
                                        */
  real_T Switch_Threshold_b1;          /* Expression: 0.5
                                        * Referenced by: '<S126>/Switch'
                                        */
  real_T Kp4_Gain_h;                   /* Expression: Kp
                                        * Referenced by: '<S124>/Kp4'
                                        */
  real_T DiscreteTimeIntegrator_gainva_o;/* Computed Parameter: DiscreteTimeIntegrator_gainva_o
                                          * Referenced by: '<S124>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_h;  /* Expression: Init
                                        * Referenced by: '<S124>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_Upper_m5;/* Expression: UpperLimit
                                          * Referenced by: '<S124>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_m;/* Expression: LowerLimit
                                          * Referenced by: '<S124>/Discrete-Time Integrator'
                                          */
  real_T Kp6_Gain_cd;                  /* Expression: Kd
                                        * Referenced by: '<S124>/Kp6'
                                        */
  real_T TSamp_WtEt_l;                 /* Computed Parameter: TSamp_WtEt_l
                                        * Referenced by: '<S128>/TSamp'
                                        */
  real_T UD_InitialCondition_a;        /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S128>/UD'
                                        */
  real_T Saturation2_UpperSat_d;       /* Expression: UpperLimit
                                        * Referenced by: '<S124>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_n;       /* Expression: LowerLimit
                                        * Referenced by: '<S124>/Saturation2'
                                        */
  real_T Gain10_Gain_a;                /* Expression: 1/2/pi
                                        * Referenced by: '<S102>/Gain10'
                                        */
  real_T UnitDelay_InitialCondition_as;/* Expression: Vinit
                                        * Referenced by: '<S125>/Unit  Delay'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: UpperLimit
                                        * Referenced by: '<S125>/Saturation'
                                        */
  real_T Saturation_LowerSat_i;        /* Expression: LowerLimit
                                        * Referenced by: '<S125>/Saturation'
                                        */
  real_T DiscreteStateSpace_A_hs[4];   /* Computed Parameter: DiscreteStateSpace_A_hs
                                        * Referenced by: '<S123>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_B_f[2];    /* Computed Parameter: DiscreteStateSpace_B_f
                                        * Referenced by: '<S123>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_C_o[2];    /* Computed Parameter: DiscreteStateSpace_C_o
                                        * Referenced by: '<S123>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_D_i;       /* Computed Parameter: DiscreteStateSpace_D_i
                                        * Referenced by: '<S123>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_X0_n[2];   /* Expression: x0d
                                        * Referenced by: '<S123>/Discrete State-Space'
                                        */
  real_T Kp5_Gain_i;                   /* Expression: Ki
                                        * Referenced by: '<S124>/Kp5'
                                        */
  real_T UnitDelay_InitialCondition_px;/* Expression: Finit
                                        * Referenced by: '<S102>/Unit Delay'
                                        */
  real_T Gain1_Gain_ez;                /* Expression: 1/3
                                        * Referenced by: '<S127>/Gain1'
                                        */
  real_T puV_Gain_l;                   /* Expression: 1/sqrt(3)
                                        * Referenced by: '<S139>/pu->V'
                                        */
  real_T Integ4_gainval_mc;            /* Computed Parameter: Integ4_gainval_mc
                                        * Referenced by: '<S140>/Integ4'
                                        */
  real_T Integ4_IC_p;                  /* Expression: 0
                                        * Referenced by: '<S140>/Integ4'
                                        */
  real_T K1_Value_dv;                  /* Expression: Delay
                                        * Referenced by: '<S140>/K1'
                                        */
  real_T K2_Value_p;                   /* Expression: Freq
                                        * Referenced by: '<S140>/K2'
                                        */
  real_T UnitDelay_InitialCondition_lr;/* Expression: 0
                                        * Referenced by: '<S140>/Unit Delay'
                                        */
  real_T Step_Time_g;                  /* Expression: 1/Freq
                                        * Referenced by: '<S140>/Step'
                                        */
  real_T Step_Y0_du;                   /* Expression: 0
                                        * Referenced by: '<S140>/Step'
                                        */
  real_T Step_YFinal_b;                /* Expression: 1
                                        * Referenced by: '<S140>/Step'
                                        */
  real_T Constant_Value_lu;            /* Expression: Vinit
                                        * Referenced by: '<S140>/Constant'
                                        */
  real_T Switch_Threshold_es;          /* Expression: 0.5
                                        * Referenced by: '<S140>/Switch'
                                        */
  real_T Constant_Value_e;             /* Expression: const
                                        * Referenced by: '<S130>/Constant'
                                        */
  real_T Constant_Value_fx;            /* Expression: const
                                        * Referenced by: '<S131>/Constant'
                                        */
  real_T Constant_Value_ht;            /* Expression: const
                                        * Referenced by: '<S132>/Constant'
                                        */
  real_T Constant_Value_bg;            /* Expression: const
                                        * Referenced by: '<S133>/Constant'
                                        */
  real_T FixPtUnitDelay1_InitialCondit_c;/* Expression: vinit
                                          * Referenced by: '<S134>/FixPt Unit Delay1'
                                          */
  real_T Constant1_Value_j;            /* Expression: 2/60
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Constant2_Value_e;            /* Expression: 0.1
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T Constant4_Value_b;            /* Expression: Ts
                                        * Referenced by: '<S6>/Constant4'
                                        */
  real_T a4_Value_l;                   /* Expression: Ts
                                        * Referenced by: '<S114>/a4'
                                        */
  real_T Integ4_gainval_nk;            /* Computed Parameter: Integ4_gainval_nk
                                        * Referenced by: '<S142>/Integ4'
                                        */
  real_T Integ4_IC_jj;                 /* Expression: 0
                                        * Referenced by: '<S142>/Integ4'
                                        */
  real_T K1_Value_ja;                  /* Expression: Delay
                                        * Referenced by: '<S142>/K1'
                                        */
  real_T K2_Value_d3;                  /* Expression: Freq
                                        * Referenced by: '<S142>/K2'
                                        */
  real_T UnitDelay_InitialCondition_kx;/* Expression: 0
                                        * Referenced by: '<S142>/Unit Delay'
                                        */
  real_T Step_Time_lw;                 /* Expression: 1/Freq
                                        * Referenced by: '<S142>/Step'
                                        */
  real_T Step_Y0_bx;                   /* Expression: 0
                                        * Referenced by: '<S142>/Step'
                                        */
  real_T Step_YFinal_a3;               /* Expression: 1
                                        * Referenced by: '<S142>/Step'
                                        */
  real_T Constant_Value_by;            /* Expression: Vinit
                                        * Referenced by: '<S142>/Constant'
                                        */
  real_T Switch_Threshold_f;           /* Expression: 0.5
                                        * Referenced by: '<S142>/Switch'
                                        */
  real_T Integ4_gainval_nj;            /* Computed Parameter: Integ4_gainval_nj
                                        * Referenced by: '<S144>/Integ4'
                                        */
  real_T Integ4_IC_fn;                 /* Expression: 0
                                        * Referenced by: '<S144>/Integ4'
                                        */
  real_T K1_Value_mw;                  /* Expression: Delay
                                        * Referenced by: '<S144>/K1'
                                        */
  real_T K2_Value_pu;                  /* Expression: Freq
                                        * Referenced by: '<S144>/K2'
                                        */
  real_T UnitDelay_InitialCondition_lz;/* Expression: 0
                                        * Referenced by: '<S144>/Unit Delay'
                                        */
  real_T Step_Time_pv;                 /* Expression: 1/Freq
                                        * Referenced by: '<S144>/Step'
                                        */
  real_T Step_Y0_cj;                   /* Expression: 0
                                        * Referenced by: '<S144>/Step'
                                        */
  real_T Step_YFinal_pg;               /* Expression: 1
                                        * Referenced by: '<S144>/Step'
                                        */
  real_T Constant_Value_ic;            /* Expression: Vinit
                                        * Referenced by: '<S144>/Constant'
                                        */
  real_T Switch_Threshold_bk;          /* Expression: 0.5
                                        * Referenced by: '<S144>/Switch'
                                        */
  real_T Gain_Gain_pd;                 /* Expression: 1/1.732025
                                        * Referenced by: '<S114>/Gain'
                                        */
  real_T Switch_Threshold_o;           /* Expression: 0.5
                                        * Referenced by: '<S111>/Switch'
                                        */
  real_T Gain2_Gain_e;                 /* Expression: 1/1.732
                                        * Referenced by: '<S6>/Gain2'
                                        */
  real_T Gain_Gain_j2;                 /* Expression: 2^3
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: 100
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T Gain10_Gain_b;                /* Expression: 1/1000
                                        * Referenced by: '<S6>/Gain10'
                                        */
  real_T Constant5_Value_l;            /* Expression: 120
                                        * Referenced by: '<S107>/Constant5'
                                        */
  real_T Constant7_Value_m;            /* Expression: 2*pi
                                        * Referenced by: '<S107>/Constant7'
                                        */
  real_T Gain11_Gain_b;                /* Expression: 10
                                        * Referenced by: '<S6>/Gain11'
                                        */
  real_T Gain12_Gain_a;                /* Expression: 10
                                        * Referenced by: '<S6>/Gain12'
                                        */
  real_T Gain13_Gain_b;                /* Expression: 2
                                        * Referenced by: '<S6>/Gain13'
                                        */
  real_T Gain14_Gain_d;                /* Expression: 2^14
                                        * Referenced by: '<S6>/Gain14'
                                        */
  real_T Gain15_Gain_f;                /* Expression: 1.4142
                                        * Referenced by: '<S6>/Gain15'
                                        */
  real_T Gain16_Gain_k;                /* Expression: 1.4142
                                        * Referenced by: '<S6>/Gain16'
                                        */
  real_T Gain17_Gain_c;                /* Expression: 1.4142
                                        * Referenced by: '<S6>/Gain17'
                                        */
  real_T Gain18_Gain_d;                /* Expression: 1.4142
                                        * Referenced by: '<S6>/Gain18'
                                        */
  real_T Gain19_Gain_c;                /* Expression: 1.4142
                                        * Referenced by: '<S6>/Gain19'
                                        */
  real_T Gain20_Gain_b;                /* Expression: 1.4142
                                        * Referenced by: '<S6>/Gain20'
                                        */
  real_T Constant6_Value_j;            /* Expression: 120
                                        * Referenced by: '<S106>/Constant6'
                                        */
  real_T Constant8_Value_m;            /* Expression: 2*pi
                                        * Referenced by: '<S106>/Constant8'
                                        */
  real_T Gain3_Gain_e;                 /* Expression: 10
                                        * Referenced by: '<S6>/Gain3'
                                        */
  real_T Gain4_Gain_k;                 /* Expression: 10
                                        * Referenced by: '<S6>/Gain4'
                                        */
  real_T Constant5_Value_f;            /* Expression: 120
                                        * Referenced by: '<S106>/Constant5'
                                        */
  real_T Constant7_Value_e;            /* Expression: 2*pi
                                        * Referenced by: '<S106>/Constant7'
                                        */
  real_T Gain5_Gain_n;                 /* Expression: 10
                                        * Referenced by: '<S6>/Gain5'
                                        */
  real_T Gain6_Gain_e;                 /* Expression: 1/1000
                                        * Referenced by: '<S6>/Gain6'
                                        */
  real_T Gain7_Gain_a;                 /* Expression: 1/1000
                                        * Referenced by: '<S6>/Gain7'
                                        */
  real_T Gain8_Gain_i;                 /* Expression: 10
                                        * Referenced by: '<S6>/Gain8'
                                        */
  real_T Constant6_Value_i;            /* Expression: 120
                                        * Referenced by: '<S107>/Constant6'
                                        */
  real_T Constant8_Value_a;            /* Expression: 2*pi
                                        * Referenced by: '<S107>/Constant8'
                                        */
  real_T Gain9_Gain_i;                 /* Expression: 10
                                        * Referenced by: '<S6>/Gain9'
                                        */
  real_T never_reset_Value_m;          /* Expression: 0
                                        * Referenced by: '<S104>/never_reset'
                                        */
  real_T DelayInput1_InitialCondition_a;/* Expression: vinit
                                         * Referenced by: '<S137>/Delay Input1'
                                         */
  real_T Integ4_gainval_an;            /* Computed Parameter: Integ4_gainval_an
                                        * Referenced by: '<S154>/Integ4'
                                        */
  real_T Integ4_IC_jt;                 /* Expression: 0
                                        * Referenced by: '<S154>/Integ4'
                                        */
  real_T K1_Value_gb;                  /* Expression: Delay
                                        * Referenced by: '<S154>/K1'
                                        */
  real_T K2_Value_l;                   /* Expression: Freq
                                        * Referenced by: '<S154>/K2'
                                        */
  real_T UnitDelay_InitialCondition_ig;/* Expression: 0
                                        * Referenced by: '<S154>/Unit Delay'
                                        */
  real_T Step_Time_cd;                 /* Expression: 1/Freq
                                        * Referenced by: '<S154>/Step'
                                        */
  real_T Step_Y0_n;                    /* Expression: 0
                                        * Referenced by: '<S154>/Step'
                                        */
  real_T Step_YFinal_h;                /* Expression: 1
                                        * Referenced by: '<S154>/Step'
                                        */
  real_T Constant_Value_af;            /* Expression: Vinit
                                        * Referenced by: '<S154>/Constant'
                                        */
  real_T Switch_Threshold_kt;          /* Expression: 0.5
                                        * Referenced by: '<S154>/Switch'
                                        */
  real_T sqrt3_Gain_o;                 /* Expression: 1.7321
                                        * Referenced by: '<S110>/sqrt3'
                                        */
  real_T UnitDelay_InitialCondition_ip;/* Expression: Finit
                                        * Referenced by: '<S157>/Unit Delay'
                                        */
  real_T UnitDelay_InitialCondition_ed;/* Expression: Finit
                                        * Referenced by: '<S156>/Unit Delay'
                                        */
  real_T DiscreteTimeIntegrator_gainv_kv;/* Computed Parameter: DiscreteTimeIntegrator_gainv_kv
                                          * Referenced by: '<S157>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_gi; /* Expression: Phase_Init*pi/180
                                        * Referenced by: '<S157>/Discrete-Time Integrator'
                                        */
  real_T Constant4_Value_i;            /* Expression: 2*pi
                                        * Referenced by: '<S157>/Constant4'
                                        */
  real_T DiscreteTimeIntegrator_gainva_j;/* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                                          * Referenced by: '<S156>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_pm; /* Expression: Phase_Init*pi/180
                                        * Referenced by: '<S156>/Discrete-Time Integrator'
                                        */
  real_T Constant4_Value_op;           /* Expression: 2*pi
                                        * Referenced by: '<S156>/Constant4'
                                        */
  real_T Constant3_Value_p;            /* Expression: 2*pi
                                        * Referenced by: '<S147>/Constant3'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 180/pi
                                        * Referenced by: '<S153>/Gain'
                                        */
  real_T Memory2_X0_l;                 /* Expression: 0
                                        * Referenced by: '<S6>/Memory2'
                                        */
  real_T Memory9_X0_g;                 /* Expression: 0
                                        * Referenced by: '<S6>/Memory9'
                                        */
  real_T Integ4_gainval_p;             /* Computed Parameter: Integ4_gainval_p
                                        * Referenced by: '<S162>/Integ4'
                                        */
  real_T Integ4_IC_mh;                 /* Expression: 0
                                        * Referenced by: '<S162>/Integ4'
                                        */
  real_T Toavoiddivisionbyzero_UpperSa_o;/* Expression: 1e6
                                          * Referenced by: '<S162>/To avoid division by zero'
                                          */
  real_T Toavoiddivisionbyzero_LowerS_hk;/* Expression: 1e-6
                                          * Referenced by: '<S162>/To avoid division by zero'
                                          */
  real_T Gain_Gain_jk;                 /* Expression: Ts
                                        * Referenced by: '<S162>/Gain'
                                        */
  real_T UnitDelay_InitialCondition_ew;/* Expression: 0
                                        * Referenced by: '<S172>/Unit Delay'
                                        */
  real_T Step_Time_eq;                 /* Expression: 1/Finit
                                        * Referenced by: '<S162>/Step'
                                        */
  real_T Step_Y0_a;                    /* Expression: 0
                                        * Referenced by: '<S162>/Step'
                                        */
  real_T Step_YFinal_pi;               /* Expression: 1
                                        * Referenced by: '<S162>/Step'
                                        */
  real_T Constant_Value_fn;            /* Expression: Vinit
                                        * Referenced by: '<S162>/Constant'
                                        */
  real_T Switch_Threshold_kq;          /* Expression: 0.5
                                        * Referenced by: '<S162>/Switch'
                                        */
  real_T Constant1_Value_l;            /* Expression: AGC
                                        * Referenced by: '<S156>/Constant1'
                                        */
  real_T Kp4_Gain_d;                   /* Expression: Kp
                                        * Referenced by: '<S160>/Kp4'
                                        */
  real_T DiscreteTimeIntegrator_gainva_h;/* Computed Parameter: DiscreteTimeIntegrator_gainva_h
                                          * Referenced by: '<S160>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_f;  /* Expression: Init
                                        * Referenced by: '<S160>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperS_o;/* Expression: UpperLimit
                                          * Referenced by: '<S160>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_Lower_hx;/* Expression: LowerLimit
                                          * Referenced by: '<S160>/Discrete-Time Integrator'
                                          */
  real_T Kp6_Gain_g;                   /* Expression: Kd
                                        * Referenced by: '<S160>/Kp6'
                                        */
  real_T TSamp_WtEt_f;                 /* Computed Parameter: TSamp_WtEt_f
                                        * Referenced by: '<S171>/TSamp'
                                        */
  real_T UD_InitialCondition_o;        /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S171>/UD'
                                        */
  real_T Saturation2_UpperSat_i;       /* Expression: UpperLimit
                                        * Referenced by: '<S160>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_b;       /* Expression: LowerLimit
                                        * Referenced by: '<S160>/Saturation2'
                                        */
  real_T Gain10_Gain_e;                /* Expression: 1/2/pi
                                        * Referenced by: '<S156>/Gain10'
                                        */
  real_T UnitDelay_InitialCondition_c0;/* Expression: Vinit
                                        * Referenced by: '<S161>/Unit  Delay'
                                        */
  real_T Saturation_UpperSat_b;        /* Expression: UpperLimit
                                        * Referenced by: '<S161>/Saturation'
                                        */
  real_T Saturation_LowerSat_o0;       /* Expression: LowerLimit
                                        * Referenced by: '<S161>/Saturation'
                                        */
  real_T DiscreteStateSpace_A_b[4];    /* Computed Parameter: DiscreteStateSpace_A_b
                                        * Referenced by: '<S158>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_B_m[2];    /* Computed Parameter: DiscreteStateSpace_B_m
                                        * Referenced by: '<S158>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_C_f[2];    /* Computed Parameter: DiscreteStateSpace_C_f
                                        * Referenced by: '<S158>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_D_hy;      /* Computed Parameter: DiscreteStateSpace_D_hy
                                        * Referenced by: '<S158>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_X0_e[2];   /* Expression: x0d
                                        * Referenced by: '<S158>/Discrete State-Space'
                                        */
  real_T Kp5_Gain_p;                   /* Expression: Ki
                                        * Referenced by: '<S160>/Kp5'
                                        */
  real_T Integ4_gainval_eg;            /* Computed Parameter: Integ4_gainval_eg
                                        * Referenced by: '<S178>/Integ4'
                                        */
  real_T Integ4_IC_o5;                 /* Expression: 0
                                        * Referenced by: '<S178>/Integ4'
                                        */
  real_T Toavoiddivisionbyzero_UpperSa_j;/* Expression: 1e6
                                          * Referenced by: '<S178>/To avoid division by zero'
                                          */
  real_T Toavoiddivisionbyzero_LowerSa_n;/* Expression: 1e-6
                                          * Referenced by: '<S178>/To avoid division by zero'
                                          */
  real_T Gain_Gain_ei;                 /* Expression: Ts
                                        * Referenced by: '<S178>/Gain'
                                        */
  real_T UnitDelay_InitialCondition_n; /* Expression: 0
                                        * Referenced by: '<S188>/Unit Delay'
                                        */
  real_T Step_Time_kt;                 /* Expression: 1/Finit
                                        * Referenced by: '<S178>/Step'
                                        */
  real_T Step_Y0_ac;                   /* Expression: 0
                                        * Referenced by: '<S178>/Step'
                                        */
  real_T Step_YFinal_l;                /* Expression: 1
                                        * Referenced by: '<S178>/Step'
                                        */
  real_T Constant_Value_fj;            /* Expression: Vinit
                                        * Referenced by: '<S178>/Constant'
                                        */
  real_T Switch_Threshold_nn;          /* Expression: 0.5
                                        * Referenced by: '<S178>/Switch'
                                        */
  real_T Constant1_Value_m;            /* Expression: AGC
                                        * Referenced by: '<S157>/Constant1'
                                        */
  real_T Kp4_Gain_dg;                  /* Expression: Kp
                                        * Referenced by: '<S176>/Kp4'
                                        */
  real_T DiscreteTimeIntegrator_gainv_kk;/* Computed Parameter: DiscreteTimeIntegrator_gainv_kk
                                          * Referenced by: '<S176>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_d;  /* Expression: Init
                                        * Referenced by: '<S176>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_Upper_au;/* Expression: UpperLimit
                                          * Referenced by: '<S176>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_p;/* Expression: LowerLimit
                                          * Referenced by: '<S176>/Discrete-Time Integrator'
                                          */
  real_T Kp6_Gain_l;                   /* Expression: Kd
                                        * Referenced by: '<S176>/Kp6'
                                        */
  real_T TSamp_WtEt_j;                 /* Computed Parameter: TSamp_WtEt_j
                                        * Referenced by: '<S187>/TSamp'
                                        */
  real_T UD_InitialCondition_g;        /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S187>/UD'
                                        */
  real_T Saturation2_UpperSat_c;       /* Expression: UpperLimit
                                        * Referenced by: '<S176>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_pm;      /* Expression: LowerLimit
                                        * Referenced by: '<S176>/Saturation2'
                                        */
  real_T Gain10_Gain_g0;               /* Expression: 1/2/pi
                                        * Referenced by: '<S157>/Gain10'
                                        */
  real_T UnitDelay_InitialCondition_kl;/* Expression: Vinit
                                        * Referenced by: '<S177>/Unit  Delay'
                                        */
  real_T Saturation_UpperSat_ns;       /* Expression: UpperLimit
                                        * Referenced by: '<S177>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: LowerLimit
                                        * Referenced by: '<S177>/Saturation'
                                        */
  real_T DiscreteStateSpace_A_hy[4];   /* Computed Parameter: DiscreteStateSpace_A_hy
                                        * Referenced by: '<S174>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_B_l[2];    /* Computed Parameter: DiscreteStateSpace_B_l
                                        * Referenced by: '<S174>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_C_d[2];    /* Computed Parameter: DiscreteStateSpace_C_d
                                        * Referenced by: '<S174>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_D_l2;      /* Computed Parameter: DiscreteStateSpace_D_l2
                                        * Referenced by: '<S174>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_X0_g[2];   /* Expression: x0d
                                        * Referenced by: '<S174>/Discrete State-Space'
                                        */
  real_T Kp5_Gain_j;                   /* Expression: Ki
                                        * Referenced by: '<S176>/Kp5'
                                        */
  int16_T ShiftArithmetic_Power2Exponent;/* Computed Parameter: ShiftArithmetic_Power2Exponent
                                          * Referenced by: '<S21>/Shift Arithmetic'
                                          */
  int16_T ShiftArithmetic1_Power2Exponent;/* Computed Parameter: ShiftArithmetic1_Power2Exponent
                                           * Referenced by: '<S21>/Shift Arithmetic1'
                                           */
  int16_T ShiftArithmetic2_Power2Exponent;/* Computed Parameter: ShiftArithmetic2_Power2Exponent
                                           * Referenced by: '<S21>/Shift Arithmetic2'
                                           */
  int16_T ShiftArithmetic3_Power2Exponent;/* Computed Parameter: ShiftArithmetic3_Power2Exponent
                                           * Referenced by: '<S21>/Shift Arithmetic3'
                                           */
  int16_T ShiftArithmetic4_Power2Exponent;/* Computed Parameter: ShiftArithmetic4_Power2Exponent
                                           * Referenced by: '<S21>/Shift Arithmetic4'
                                           */
  int16_T ShiftArithmetic5_Power2Exponent;/* Computed Parameter: ShiftArithmetic5_Power2Exponent
                                           * Referenced by: '<S21>/Shift Arithmetic5'
                                           */
  int16_T ShiftArithmetic_Power2Exponen_k;/* Computed Parameter: ShiftArithmetic_Power2Exponen_k
                                           * Referenced by: '<S22>/Shift Arithmetic'
                                           */
  int16_T ShiftArithmetic_Power2Exponen_i;/* Computed Parameter: ShiftArithmetic_Power2Exponen_i
                                           * Referenced by: '<S112>/Shift Arithmetic'
                                           */
  int16_T ShiftArithmetic1_Power2Expone_c;/* Computed Parameter: ShiftArithmetic1_Power2Expone_c
                                           * Referenced by: '<S112>/Shift Arithmetic1'
                                           */
  int16_T ShiftArithmetic2_Power2Expone_g;/* Computed Parameter: ShiftArithmetic2_Power2Expone_g
                                           * Referenced by: '<S112>/Shift Arithmetic2'
                                           */
  int16_T ShiftArithmetic3_Power2Expone_e;/* Computed Parameter: ShiftArithmetic3_Power2Expone_e
                                           * Referenced by: '<S112>/Shift Arithmetic3'
                                           */
  int16_T ShiftArithmetic4_Power2Expone_n;/* Computed Parameter: ShiftArithmetic4_Power2Expone_n
                                           * Referenced by: '<S112>/Shift Arithmetic4'
                                           */
  int16_T ShiftArithmetic5_Power2Expone_l;/* Computed Parameter: ShiftArithmetic5_Power2Expone_l
                                           * Referenced by: '<S112>/Shift Arithmetic5'
                                           */
  int16_T ShiftArithmetic_Power2Exponen_m;/* Computed Parameter: ShiftArithmetic_Power2Exponen_m
                                           * Referenced by: '<S113>/Shift Arithmetic'
                                           */
  boolean_T FixPtUnitDelay1_InitialCondit_a;/* Computed Parameter: FixPtUnitDelay1_InitialCondit_a
                                             * Referenced by: '<S44>/FixPt Unit Delay1'
                                             */
  boolean_T FixPtUnitDelay1_InitialCondit_g;/* Computed Parameter: FixPtUnitDelay1_InitialCondit_g
                                             * Referenced by: '<S45>/FixPt Unit Delay1'
                                             */
  boolean_T DelayInput1_InitialCondition_i;/* Computed Parameter: DelayInput1_InitialCondition_i
                                            * Referenced by: '<S99>/Delay Input1'
                                            */
  boolean_T Memory_X0;                 /* Computed Parameter: Memory_X0
                                        * Referenced by: '<S47>/Memory'
                                        */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S47>/Logic'
                                        */
  boolean_T Memory_X0_p;               /* Computed Parameter: Memory_X0_p
                                        * Referenced by: '<S58>/Memory'
                                        */
  boolean_T Logic_table_n[16];         /* Computed Parameter: Logic_table_n
                                        * Referenced by: '<S58>/Logic'
                                        */
  boolean_T FixPtUnitDelay1_InitialCondit_k;/* Computed Parameter: FixPtUnitDelay1_InitialCondit_k
                                             * Referenced by: '<S135>/FixPt Unit Delay1'
                                             */
  boolean_T FixPtUnitDelay1_InitialCondit_e;/* Computed Parameter: FixPtUnitDelay1_InitialCondit_e
                                             * Referenced by: '<S136>/FixPt Unit Delay1'
                                             */
  boolean_T DelayInput1_InitialCondition_l;/* Computed Parameter: DelayInput1_InitialCondition_l
                                            * Referenced by: '<S190>/Delay Input1'
                                            */
  boolean_T Memory_X0_f;               /* Computed Parameter: Memory_X0_f
                                        * Referenced by: '<S138>/Memory'
                                        */
  boolean_T Logic_table_d[16];         /* Computed Parameter: Logic_table_d
                                        * Referenced by: '<S138>/Logic'
                                        */
  boolean_T Memory_X0_l;               /* Computed Parameter: Memory_X0_l
                                        * Referenced by: '<S149>/Memory'
                                        */
  boolean_T Logic_table_f[16];         /* Computed Parameter: Logic_table_f
                                        * Referenced by: '<S149>/Logic'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_sel751test_model_1_3_ss_relays_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[1];
    SimStruct childSFunctions[4];
    SimStruct *childSFunctionPtrs[4];
    struct _ssBlkInfo2 blkInfo2[4];
    struct _ssSFcnModelMethods2 methods2[4];
    struct _ssSFcnModelMethods3 methods3[4];
    struct _ssStatesInfo2 statesInfo2[4];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[32];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[32];
      uint_T attribs[1];
      mxArray *params[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn3;
  } NonInlinedSFcns;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    void *dwork;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[1];
    time_T offsetTimesArray[1];
    int_T sampleTimeTaskIDArray[1];
    int_T sampleHitArray[1];
    int_T perTaskSampleHitsArray[1];
    time_T tArray[1];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_sel751test_model_1_3_ss_relays_T sel751test_model_1_3_ss_relays_P;

/* Block signals (auto storage) */
extern B_sel751test_model_1_3_ss_relays_T sel751test_model_1_3_ss_relays_B;

/* Block states (auto storage) */
extern DW_sel751test_model_1_3_ss_relays_T sel751test_model_1_3_ss_relays_DW;

/* Constant parameters (auto storage) */
extern const ConstP_sel751test_model_1_3_ss_relays_T
  sel751test_model_1_3_ss_relays_ConstP;

/* Real-time Model object */
extern RT_MODEL_sel751test_model_1_3_ss_relays_T *const
  sel751test_model_1_3_ss_relays_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'sel751test_model_1_3_ss_relays'
 * '<S1>'   : 'sel751test_model_1_3_ss_relays/ARTEMIS Guide'
 * '<S2>'   : 'sel751test_model_1_3_ss_relays/OpCCode_do_not_touch'
 * '<S3>'   : 'sel751test_model_1_3_ss_relays/SS_Relays'
 * '<S4>'   : 'sel751test_model_1_3_ss_relays/powergui'
 * '<S5>'   : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1'
 * '<S6>'   : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2'
 * '<S7>'   : 'sel751test_model_1_3_ss_relays/SS_Relays/OpComm1'
 * '<S8>'   : 'sel751test_model_1_3_ss_relays/SS_Relays/rtlab_send_subsystem'
 * '<S9>'   : 'sel751test_model_1_3_ss_relays/SS_Relays/zzzOpComm'
 * '<S10>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/CS Modified PLL'
 * '<S11>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/CS Modified PLL1'
 * '<S12>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Complex Power and Power Factor'
 * '<S13>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Initial_cond_mng'
 * '<S14>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/PQ_Calculator'
 * '<S15>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Phase_Calc'
 * '<S16>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Phase_Calc1'
 * '<S17>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/RMS_Calculator'
 * '<S18>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/RMS_Calculator1'
 * '<S19>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param'
 * '<S20>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay_param'
 * '<S21>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/bitwise_faults'
 * '<S22>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/pf bitwise'
 * '<S23>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/relay_protection_functions'
 * '<S24>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/trip_out mng'
 * '<S25>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/CS Modified PLL/2nd-Order Filter'
 * '<S26>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/CS Modified PLL/Controller'
 * '<S27>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/CS Modified PLL/Discrete Rate Limiter'
 * '<S28>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/CS Modified PLL/Discrete  Mean value'
 * '<S29>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/CS Modified PLL/abc_to_dq0 Transformation'
 * '<S30>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/CS Modified PLL/Controller/Discrete Derivative'
 * '<S31>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/CS Modified PLL/Discrete  Mean value/Discrete Variable Transport Delay'
 * '<S32>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/CS Modified PLL1/2nd-Order Filter'
 * '<S33>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/CS Modified PLL1/Controller'
 * '<S34>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/CS Modified PLL1/Discrete Rate Limiter'
 * '<S35>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/CS Modified PLL1/Discrete  Mean value'
 * '<S36>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/CS Modified PLL1/abc_to_dq0 Transformation'
 * '<S37>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/CS Modified PLL1/Controller/Discrete Derivative'
 * '<S38>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/CS Modified PLL1/Discrete  Mean value/Discrete Variable Transport Delay'
 * '<S39>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Complex Power and Power Factor/Compare To Constant'
 * '<S40>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Complex Power and Power Factor/Compare To Constant1'
 * '<S41>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Complex Power and Power Factor/Importing=TRUE Exporting=FALSE'
 * '<S42>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Complex Power and Power Factor/Lagging (Pushing VARs)=TRUE Leading (Pulling VARs)=FALSE'
 * '<S43>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Complex Power and Power Factor/Unit Delay Enabled'
 * '<S44>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Complex Power and Power Factor/Unit Delay Enabled1'
 * '<S45>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Complex Power and Power Factor/Unit Delay Enabled2'
 * '<S46>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Initial_cond_mng/Detect Change'
 * '<S47>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Initial_cond_mng/S-R Flip-Flop1'
 * '<S48>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/PQ_Calculator/3-phase  Instantaneous  Active & Reactive Power'
 * '<S49>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/PQ_Calculator/Discrete  Mean value2'
 * '<S50>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/PQ_Calculator/Discrete  Mean value2/Discrete Variable Transport Delay'
 * '<S51>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/RMS_Calculator/Discrete  Mean value6'
 * '<S52>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/RMS_Calculator/Discrete  Mean value6/Discrete Variable Transport Delay'
 * '<S53>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/RMS_Calculator1/Discrete  Mean value6'
 * '<S54>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/RMS_Calculator1/Discrete  Mean value6/Discrete Variable Transport Delay'
 * '<S55>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/Freq_Comparator'
 * '<S56>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/Phase_Comparator'
 * '<S57>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/RMS'
 * '<S58>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/S-R Flip-Flop1'
 * '<S59>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/Voltage_Comparator'
 * '<S60>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/deadbus fcn'
 * '<S61>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs'
 * '<S62>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/Phase_Comparator/Radians to Degrees'
 * '<S63>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/RMS/Discrete  Mean value6'
 * '<S64>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/RMS/Discrete  Mean value6/Discrete Variable Transport Delay'
 * '<S65>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL'
 * '<S66>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1'
 * '<S67>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/2nd-Order Filter'
 * '<S68>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Automatic Gain Control'
 * '<S69>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Controller'
 * '<S70>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Discrete Rate Limiter'
 * '<S71>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Variable Frequency Mean value'
 * '<S72>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value'
 * '<S73>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Cartesian to Polar'
 * '<S74>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value'
 * '<S75>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value1'
 * '<S76>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value/Correction subsystem'
 * '<S77>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value/Discrete Variable Transport Delay'
 * '<S78>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value1/Correction subsystem'
 * '<S79>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value1/Discrete Variable Transport Delay'
 * '<S80>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Controller/Discrete Derivative'
 * '<S81>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Variable Frequency Mean value/Correction subsystem'
 * '<S82>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Variable Frequency Mean value/Discrete Variable Transport Delay'
 * '<S83>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/2nd-Order Filter'
 * '<S84>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Automatic Gain Control'
 * '<S85>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Controller'
 * '<S86>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Discrete Rate Limiter'
 * '<S87>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Variable Frequency Mean value'
 * '<S88>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value'
 * '<S89>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Cartesian to Polar'
 * '<S90>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value'
 * '<S91>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value1'
 * '<S92>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value/Correction subsystem'
 * '<S93>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value/Discrete Variable Transport Delay'
 * '<S94>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value1/Correction subsystem'
 * '<S95>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value1/Discrete Variable Transport Delay'
 * '<S96>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Controller/Discrete Derivative'
 * '<S97>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Variable Frequency Mean value/Correction subsystem'
 * '<S98>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Variable Frequency Mean value/Discrete Variable Transport Delay'
 * '<S99>'  : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/Relay_param/Detect Change'
 * '<S100>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_1/relay_protection_functions/Relays'
 * '<S101>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/CS Modified PLL'
 * '<S102>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/CS Modified PLL1'
 * '<S103>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Complex Power and Power Factor'
 * '<S104>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Initial_cond_mng'
 * '<S105>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/PQ_Calculator'
 * '<S106>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Phase_Calc'
 * '<S107>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Phase_Calc1'
 * '<S108>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/RMS_Calculator'
 * '<S109>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/RMS_Calculator1'
 * '<S110>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param'
 * '<S111>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay_param'
 * '<S112>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/bitwise_faults'
 * '<S113>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/pf bitwise'
 * '<S114>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/relay_protection_functions'
 * '<S115>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/trip_out mng'
 * '<S116>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/CS Modified PLL/2nd-Order Filter'
 * '<S117>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/CS Modified PLL/Controller'
 * '<S118>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/CS Modified PLL/Discrete Rate Limiter'
 * '<S119>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/CS Modified PLL/Discrete  Mean value'
 * '<S120>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/CS Modified PLL/abc_to_dq0 Transformation'
 * '<S121>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/CS Modified PLL/Controller/Discrete Derivative'
 * '<S122>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/CS Modified PLL/Discrete  Mean value/Discrete Variable Transport Delay'
 * '<S123>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/CS Modified PLL1/2nd-Order Filter'
 * '<S124>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/CS Modified PLL1/Controller'
 * '<S125>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/CS Modified PLL1/Discrete Rate Limiter'
 * '<S126>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/CS Modified PLL1/Discrete  Mean value'
 * '<S127>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/CS Modified PLL1/abc_to_dq0 Transformation'
 * '<S128>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/CS Modified PLL1/Controller/Discrete Derivative'
 * '<S129>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/CS Modified PLL1/Discrete  Mean value/Discrete Variable Transport Delay'
 * '<S130>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Complex Power and Power Factor/Compare To Constant'
 * '<S131>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Complex Power and Power Factor/Compare To Constant1'
 * '<S132>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Complex Power and Power Factor/Importing=TRUE Exporting=FALSE'
 * '<S133>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Complex Power and Power Factor/Lagging (Pushing VARs)=TRUE Leading (Pulling VARs)=FALSE'
 * '<S134>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Complex Power and Power Factor/Unit Delay Enabled'
 * '<S135>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Complex Power and Power Factor/Unit Delay Enabled1'
 * '<S136>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Complex Power and Power Factor/Unit Delay Enabled2'
 * '<S137>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Initial_cond_mng/Detect Change'
 * '<S138>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Initial_cond_mng/S-R Flip-Flop1'
 * '<S139>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/PQ_Calculator/3-phase  Instantaneous  Active & Reactive Power'
 * '<S140>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/PQ_Calculator/Discrete  Mean value2'
 * '<S141>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/PQ_Calculator/Discrete  Mean value2/Discrete Variable Transport Delay'
 * '<S142>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/RMS_Calculator/Discrete  Mean value6'
 * '<S143>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/RMS_Calculator/Discrete  Mean value6/Discrete Variable Transport Delay'
 * '<S144>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/RMS_Calculator1/Discrete  Mean value6'
 * '<S145>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/RMS_Calculator1/Discrete  Mean value6/Discrete Variable Transport Delay'
 * '<S146>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/Freq_Comparator'
 * '<S147>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/Phase_Comparator'
 * '<S148>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/RMS'
 * '<S149>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/S-R Flip-Flop1'
 * '<S150>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/Voltage_Comparator'
 * '<S151>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/deadbus fcn'
 * '<S152>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs'
 * '<S153>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/Phase_Comparator/Radians to Degrees'
 * '<S154>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/RMS/Discrete  Mean value6'
 * '<S155>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/RMS/Discrete  Mean value6/Discrete Variable Transport Delay'
 * '<S156>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL'
 * '<S157>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1'
 * '<S158>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/2nd-Order Filter'
 * '<S159>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Automatic Gain Control'
 * '<S160>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Controller'
 * '<S161>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Discrete Rate Limiter'
 * '<S162>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Variable Frequency Mean value'
 * '<S163>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value'
 * '<S164>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Cartesian to Polar'
 * '<S165>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value'
 * '<S166>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value1'
 * '<S167>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value/Correction subsystem'
 * '<S168>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value/Discrete Variable Transport Delay'
 * '<S169>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value1/Correction subsystem'
 * '<S170>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value1/Discrete Variable Transport Delay'
 * '<S171>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Controller/Discrete Derivative'
 * '<S172>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Variable Frequency Mean value/Correction subsystem'
 * '<S173>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL/Variable Frequency Mean value/Discrete Variable Transport Delay'
 * '<S174>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/2nd-Order Filter'
 * '<S175>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Automatic Gain Control'
 * '<S176>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Controller'
 * '<S177>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Discrete Rate Limiter'
 * '<S178>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Variable Frequency Mean value'
 * '<S179>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value'
 * '<S180>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Cartesian to Polar'
 * '<S181>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value'
 * '<S182>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value1'
 * '<S183>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value/Correction subsystem'
 * '<S184>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value/Discrete Variable Transport Delay'
 * '<S185>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value1/Correction subsystem'
 * '<S186>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value1/Discrete Variable Transport Delay'
 * '<S187>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Controller/Discrete Derivative'
 * '<S188>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Variable Frequency Mean value/Correction subsystem'
 * '<S189>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay 25 - Sync Check - ext_param/set of 1ph PLLs/Discrete 1-phase PLL1/Variable Frequency Mean value/Discrete Variable Transport Delay'
 * '<S190>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/Relay_param/Detect Change'
 * '<S191>' : 'sel751test_model_1_3_ss_relays/SS_Relays/Generic_Relay_v2_2/relay_protection_functions/Relays'
 * '<S192>' : 'sel751test_model_1_3_ss_relays/SS_Relays/OpComm1/Receive'
 * '<S193>' : 'sel751test_model_1_3_ss_relays/SS_Relays/OpComm1/busStruct'
 * '<S194>' : 'sel751test_model_1_3_ss_relays/SS_Relays/OpComm1/busStruct/Sub1'
 * '<S195>' : 'sel751test_model_1_3_ss_relays/SS_Relays/rtlab_send_subsystem/Subsystem1'
 * '<S196>' : 'sel751test_model_1_3_ss_relays/SS_Relays/rtlab_send_subsystem/Subsystem2'
 * '<S197>' : 'sel751test_model_1_3_ss_relays/SS_Relays/rtlab_send_subsystem/Subsystem1/Send1'
 * '<S198>' : 'sel751test_model_1_3_ss_relays/SS_Relays/rtlab_send_subsystem/Subsystem2/Send2'
 * '<S199>' : 'sel751test_model_1_3_ss_relays/SS_Relays/zzzOpComm/Receive_1'
 * '<S200>' : 'sel751test_model_1_3_ss_relays/SS_Relays/zzzOpComm/busStruct'
 * '<S201>' : 'sel751test_model_1_3_ss_relays/SS_Relays/zzzOpComm/busStruct/Sub1'
 */
#endif                                 /* RTW_HEADER_sel751test_model_1_3_ss_relays_h_ */
