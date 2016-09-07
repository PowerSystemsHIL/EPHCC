/*
 * sel751test_model_1_1_sm_system.h
 *
 * Code generation for model "sel751test_model_1_1_sm_system".
 *
 * Model version              : 1.2542
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Tue Aug 23 11:24:18 2016
 *
 * Target selection: rtlab_rtmodel.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_sel751test_model_1_1_sm_system_h_
#define RTW_HEADER_sel751test_model_1_1_sm_system_h_
#ifndef sel751test_model_1_1_sm_system_COMMON_INCLUDES_
# define sel751test_model_1_1_sm_system_COMMON_INCLUDES_
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
#include "rt_look.h"
#include "rt_look1d.h"
#include "rt_zcfcn.h"
#endif                                 /* sel751test_model_1_1_sm_system_COMMON_INCLUDES_ */

#include "sel751test_model_1_1_sm_system_types.h"

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
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
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
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
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
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
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
#define sel751test_model_1_1_sm_system_rtModel RT_MODEL_sel751test_model_1_1_sm_system_T

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

/* Block signals for system '<S8>/delay' */
typedef struct {
  real_T d;                            /* '<S8>/delay' */
} B_delay_sel751test_model_1_1__T;

/* Block signals for system '<S520>/Subsystem - pi//2 delay' */
typedef struct {
  real_T Fcn;                          /* '<S524>/Fcn' */
  real_T Fcn1;                         /* '<S524>/Fcn1' */
} B_Subsystempi2delay_sel751tes_T;

/* Block signals for system '<S520>/Subsystem1' */
typedef struct {
  real_T Fcn;                          /* '<S525>/Fcn' */
  real_T Fcn1;                         /* '<S525>/Fcn1' */
} B_Subsystem1_sel751test_model_T;

/* Block signals (auto storage) */
typedef struct {
  creal_T RealImagtoComplex[3];        /* '<S654>/Real-Imag to Complex' */
  creal_T RealImagtoComplex_a;         /* '<S619>/Real-Imag to Complex' */
  creal_T RealImagtoComplex_f[3];      /* '<S543>/Real-Imag to Complex' */
  creal_T RealImagtoComplex_l;         /* '<S508>/Real-Imag to Complex' */
  real_T SFunction;                    /* '<S2>/S-Function' */
  real_T Sum;                          /* '<S2>/Sum' */
  real_T Status;                       /* '<S8>/Memory5' */
  real_T Iabc[3];                      /* '<S8>/Memory1' */
  real_T Vabc_bus[3];                  /* '<S8>/Memory2' */
  real_T Vabc_line[3];                 /* '<S8>/Memory3' */
  real_T Status_a;                     /* '<S9>/Memory5' */
  real_T Iabc_c[3];                    /* '<S9>/Memory1' */
  real_T Vabc_bus_l[3];                /* '<S9>/Memory2' */
  real_T Vabc_line_p[3];               /* '<S9>/Memory3' */
  real_T kW;                           /* '<S16>/Memory5' */
  real_T kvar;                         /* '<S16>/Memory5' */
  real_T Loading;                      /* '<S16>/Memory5' */
  real_T DI_CH0007[8];                 /* '<S311>/DigitalIn' */
  real_T DigitalIn_o2;                 /* '<S311>/DigitalIn' */
  real_T states1[4];                   /* '<S315>/EventDetector' */
  real_T times1[4];                    /* '<S315>/EventDetector' */
  real_T states2[4];                   /* '<S315>/EventDetector' */
  real_T times2[4];                    /* '<S315>/EventDetector' */
  real_T states3[4];                   /* '<S315>/EventDetector' */
  real_T times3[4];                    /* '<S315>/EventDetector' */
  real_T states4[4];                   /* '<S315>/EventDetector' */
  real_T times4[4];                    /* '<S315>/EventDetector' */
  real_T states5[4];                   /* '<S315>/EventDetector' */
  real_T times5[4];                    /* '<S315>/EventDetector' */
  real_T states6[4];                   /* '<S315>/EventDetector' */
  real_T times6[4];                    /* '<S315>/EventDetector' */
  real_T states7[4];                   /* '<S315>/EventDetector' */
  real_T times7[4];                    /* '<S315>/EventDetector' */
  real_T states8[4];                   /* '<S315>/EventDetector' */
  real_T times8[4];                    /* '<S315>/EventDetector' */
  real_T EventDetector_o17;            /* '<S315>/EventDetector' */
  real_T states1_f[4];                 /* '<S315>/EventDetector1' */
  real_T times1_d[4];                  /* '<S315>/EventDetector1' */
  real_T states2_n[4];                 /* '<S315>/EventDetector1' */
  real_T times2_c[4];                  /* '<S315>/EventDetector1' */
  real_T states1_o[4];                 /* '<S315>/EventDetector1' */
  real_T times1_f[4];                  /* '<S315>/EventDetector1' */
  real_T states2_h[4];                 /* '<S315>/EventDetector1' */
  real_T times2_g[4];                  /* '<S315>/EventDetector1' */
  real_T states3_m[4];                 /* '<S315>/EventDetector1' */
  real_T times3_c[4];                  /* '<S315>/EventDetector1' */
  real_T states4_d[4];                 /* '<S315>/EventDetector1' */
  real_T times4_k[4];                  /* '<S315>/EventDetector1' */
  real_T states5_p[4];                 /* '<S315>/EventDetector1' */
  real_T times5_i[4];                  /* '<S315>/EventDetector1' */
  real_T states6_b[4];                 /* '<S315>/EventDetector1' */
  real_T times6_i[4];                  /* '<S315>/EventDetector1' */
  real_T states7_h;                    /* '<S315>/EventDetector1' */
  real_T Freq[8];                      /* '<S314>/PWM In' */
  real_T Duty[8];                      /* '<S314>/PWM In' */
  real_T PWMIn_o3;                     /* '<S314>/PWM In' */
  real_T Freq_g[8];                    /* '<S314>/PWM In1' */
  real_T Duty_c[8];                    /* '<S314>/PWM In1' */
  real_T PWMIn1_o3;                    /* '<S314>/PWM In1' */
  real_T BreakAlgebraicLoop;           /* '<S274>/Break Algebraic Loop' */
  real_T Switch;                       /* '<S264>/Switch' */
  real_T Pm;                           /* '<S275>/Pm- Integrator' */
  real_T P0;                           /* '<S277>/1//P0' */
  real_T TurbochargerThrottleFuelMixture;/* '<S277>/Turbocharger,Throttle,Fuel Mixture #1' */
  real_T TurbochargerThrottleFuelMixtu_j;/* '<S277>/Turbocharger,Throttle,Fuel Mixture #2' */
  real_T Force02;                      /* '<S277>/Force > 0 #2' */
  real_T TurbochargerThrottleFuelMixtu_a;/* '<S277>/Turbocharger,Throttle,Fuel Mixture #3' */
  real_T AnalogIn_o1[8];               /* '<S339>/AnalogIn' */
  real_T AnalogIn_o2;                  /* '<S339>/AnalogIn' */
  real_T Divide;                       /* '<S316>/Divide' */
  real_T Sum_o;                        /* '<S316>/Sum' */
  real_T GeneratedFilterBlock;         /* '<S340>/Generated Filter Block' */
  real_T SFunction_c[214];             /* '<S342>/S-Function' */
  real_T wood_Gov_bias;                /* '<S260>/Switch1' */
  real_T uRPMwhileTurning;             /* '<S252>/80 RPM while "Turning"' */
  real_T d_thetarad;                   /* '<S303>/Discrete-Time Integrator1' */
  real_T DigitalClock;                 /* '<S303>/Digital Clock' */
  real_T web2;                         /* '<S303>/web2' */
  real_T Sum3;                         /* '<S303>/Sum3' */
  real_T ElementaryMath;               /* '<S284>/Elementary Math' */
  real_T ElementaryMath1;              /* '<S284>/Elementary Math1' */
  real_T xk1[5];                       /* '<S294>/fluxes' */
  real_T Linv[25];                     /* '<S283>/Switch' */
  real_T dw;                           /* '<S303>/Discrete-Time Integrator' */
  real_T n;                            /* '<S303>/Sum' */
  real_T uk1[5];                       /* '<S294>/voltages' */
  real_T DigitalClock_b;               /* '<S294>/Digital Clock' */
  real_T IC[5];                        /* '<S294>/IC' */
  real_T Ik[5];                        /* '<S283>/Product3' */
  real_T changeIqIdcurrentsigns[5];    /* '<S283>/change Iq Id  current signs' */
  real_T Fcn;                          /* '<S285>/Fcn' */
  real_T Fcn1;                         /* '<S285>/Fcn1' */
  real_T Sum_j;                        /* '<S285>/Sum' */
  real_T ikq2;                         /* '<S282>/Switch' */
  real_T LaqLl_q[2];                   /* '<S292>/Laq//Ll_q' */
  real_T phimq;                        /* '<S292>/sum' */
  real_T LadLl_d[3];                   /* '<S292>/Lad//Ll_d' */
  real_T phimd;                        /* '<S292>/sum1' */
  real_T ib[3];                        /* '<S285>/ib' */
  real_T RateTransition2[2];           /* '<S281>/Rate Transition2' */
  real_T kW_g;                         /* '<S567>/Memory1' */
  real_T kvar_k;                       /* '<S567>/Memory2' */
  real_T Sum_m[2];                     /* '<S19>/Sum' */
  real_T Integrator;                   /* '<S565>/Integrator' */
  real_T DerivativeGain;               /* '<S565>/Derivative Gain' */
  real_T Filter;                       /* '<S565>/Filter' */
  real_T SumD;                         /* '<S565>/SumD' */
  real_T FilterCoefficient;            /* '<S565>/Filter Coefficient' */
  real_T Integrator_j;                 /* '<S566>/Integrator' */
  real_T DerivativeGain_c;             /* '<S566>/Derivative Gain' */
  real_T Filter_p;                     /* '<S566>/Filter' */
  real_T SumD_f;                       /* '<S566>/SumD' */
  real_T FilterCoefficient_n;          /* '<S566>/Filter Coefficient' */
  real_T DiscreteTimeIntegrator;       /* '<S613>/Discrete-Time Integrator' */
  real_T MathFunction;                 /* '<S613>/Math Function' */
  real_T Switch_b[3];                  /* '<S19>/Switch' */
  real_T kW_l;                         /* '<S456>/Memory1' */
  real_T kvar_e;                       /* '<S456>/Memory2' */
  real_T Sum_n[2];                     /* '<S18>/Sum' */
  real_T Integrator_c;                 /* '<S454>/Integrator' */
  real_T DerivativeGain_l;             /* '<S454>/Derivative Gain' */
  real_T Filter_j;                     /* '<S454>/Filter' */
  real_T SumD_p;                       /* '<S454>/SumD' */
  real_T FilterCoefficient_f;          /* '<S454>/Filter Coefficient' */
  real_T Integrator_l;                 /* '<S455>/Integrator' */
  real_T DerivativeGain_b;             /* '<S455>/Derivative Gain' */
  real_T Filter_c;                     /* '<S455>/Filter' */
  real_T SumD_b;                       /* '<S455>/SumD' */
  real_T FilterCoefficient_c;          /* '<S455>/Filter Coefficient' */
  real_T DiscreteTimeIntegrator_l;     /* '<S502>/Discrete-Time Integrator' */
  real_T MathFunction_h;               /* '<S502>/Math Function' */
  real_T Switch_i[3];                  /* '<S18>/Switch' */
  real_T SineWaveA;                    /* '<S248>/Sine Wave A' */
  real_T SineWaveB;                    /* '<S248>/Sine Wave B' */
  real_T SineWaveC;                    /* '<S248>/Sine Wave C' */
  real_T UnitDelay;                    /* '<S22>/Unit Delay' */
  real_T triggerFAULTsig;              /* '<S3>/triggerFAULT' */
  real_T DataTypeConversion;           /* '<S685>/Data Type Conversion' */
  real_T Clock;                        /* '<S684>/Clock' */
  real_T LookUpTable;                  /* '<S684>/Look-Up Table' */
  real_T Switch3;                      /* '<S683>/Switch3' */
  real_T DataTypeConversion_j;         /* '<S690>/Data Type Conversion' */
  real_T Clock_k;                      /* '<S689>/Clock' */
  real_T LookUpTable_p;                /* '<S689>/Look-Up Table' */
  real_T Switch3_h;                    /* '<S688>/Switch3' */
  real_T DataTypeConversion_k;         /* '<S695>/Data Type Conversion' */
  real_T Clock_m;                      /* '<S694>/Clock' */
  real_T LookUpTable_n;                /* '<S694>/Look-Up Table' */
  real_T Switch3_p;                    /* '<S693>/Switch3' */
  real_T DataTypeConversion_a;         /* '<S700>/Data Type Conversion' */
  real_T Clock_a;                      /* '<S699>/Clock' */
  real_T LookUpTable_e;                /* '<S699>/Look-Up Table' */
  real_T Switch3_j;                    /* '<S698>/Switch3' */
  real_T DataTypeConversion_c;         /* '<S714>/Data Type Conversion' */
  real_T Clock_e;                      /* '<S713>/Clock' */
  real_T LookUpTable_m;                /* '<S713>/Look-Up Table' */
  real_T Switch3_b;                    /* '<S712>/Switch3' */
  real_T DataTypeConversion_b;         /* '<S719>/Data Type Conversion' */
  real_T Clock_h;                      /* '<S718>/Clock' */
  real_T LookUpTable_a;                /* '<S718>/Look-Up Table' */
  real_T Switch3_a;                    /* '<S717>/Switch3' */
  real_T DataTypeConversion_m;         /* '<S724>/Data Type Conversion' */
  real_T Clock_o;                      /* '<S723>/Clock' */
  real_T LookUpTable_h;                /* '<S723>/Look-Up Table' */
  real_T Switch3_l;                    /* '<S722>/Switch3' */
  real_T DataTypeConversion_o;         /* '<S729>/Data Type Conversion' */
  real_T Clock_l;                      /* '<S728>/Clock' */
  real_T LookUpTable_eh;               /* '<S728>/Look-Up Table' */
  real_T Switch3_m;                    /* '<S727>/Switch3' */
  real_T DigitalInfromSEL751_o1[8];    /* '<S3>/DigitalIn from SEL-751' */
  real_T DigitalInfromSEL751_o2;       /* '<S3>/DigitalIn from SEL-751' */
  real_T DataTypeConversion1;          /* '<S8>/Data Type Conversion1' */
  real_T Delay;                        /* '<S8>/Delay' */
  real_T DigitalClock_f;               /* '<S98>/Digital Clock' */
  real_T LookUpTable_mi;               /* '<S98>/Look-Up Table' */
  real_T Switch3_j2;                   /* '<S27>/Switch3' */
  real_T Switch_f;                     /* '<S27>/Switch' */
  real_T DataTypeConversion_h;         /* '<S86>/Data Type Conversion' */
  real_T Clock_ea;                     /* '<S85>/Clock' */
  real_T LookUpTable_d;                /* '<S85>/Look-Up Table' */
  real_T Switch3_n;                    /* '<S84>/Switch3' */
  real_T Switch1;                      /* '<S27>/Switch1' */
  real_T DataTypeConversion_jl;        /* '<S91>/Data Type Conversion' */
  real_T Clock_mf;                     /* '<S90>/Clock' */
  real_T LookUpTable_nw;               /* '<S90>/Look-Up Table' */
  real_T Switch3_aa;                   /* '<S89>/Switch3' */
  real_T Switch2;                      /* '<S27>/Switch2' */
  real_T DataTypeConversion_n;         /* '<S96>/Data Type Conversion' */
  real_T Clock_mq;                     /* '<S95>/Clock' */
  real_T LookUpTable_l;                /* '<S95>/Look-Up Table' */
  real_T Switch3_k;                    /* '<S94>/Switch3' */
  real_T SFunction_l[32];              /* '<S768>/S-Function' */
  real_T DataTypeConversion1_d;        /* '<S9>/Data Type Conversion1' */
  real_T Delay_p;                      /* '<S9>/Delay' */
  real_T DigitalClock_k;               /* '<S172>/Digital Clock' */
  real_T LookUpTable_pp;               /* '<S172>/Look-Up Table' */
  real_T Switch3_ba;                   /* '<S101>/Switch3' */
  real_T Switch_h;                     /* '<S101>/Switch' */
  real_T DataTypeConversion_g;         /* '<S160>/Data Type Conversion' */
  real_T Clock_p;                      /* '<S159>/Clock' */
  real_T LookUpTable_b;                /* '<S159>/Look-Up Table' */
  real_T Switch3_o;                    /* '<S158>/Switch3' */
  real_T Switch1_j;                    /* '<S101>/Switch1' */
  real_T DataTypeConversion_c4;        /* '<S165>/Data Type Conversion' */
  real_T Clock_ec;                     /* '<S164>/Clock' */
  real_T LookUpTable_dd;               /* '<S164>/Look-Up Table' */
  real_T Switch3_pl;                   /* '<S163>/Switch3' */
  real_T Switch2_c;                    /* '<S101>/Switch2' */
  real_T DataTypeConversion_cm;        /* '<S170>/Data Type Conversion' */
  real_T Clock_mqg;                    /* '<S169>/Clock' */
  real_T LookUpTable_k;                /* '<S169>/Look-Up Table' */
  real_T Switch3_c;                    /* '<S168>/Switch3' */
  real_T Switch1_o;                    /* '<S312>/Switch1' */
  real_T Add;                          /* '<S312>/Add' */
  real_T Logic_trip;                   /* '<S250>/Fcn' */
  real_T DataTypeConversion1_i;        /* '<S10>/Data Type Conversion1' */
  real_T Delay_m;                      /* '<S10>/Delay' */
  real_T DigitalClock_h;               /* '<S246>/Digital Clock' */
  real_T LookUpTable_g;                /* '<S246>/Look-Up Table' */
  real_T Switch3_kf;                   /* '<S175>/Switch3' */
  real_T Switch_l;                     /* '<S175>/Switch' */
  real_T DataTypeConversion_p;         /* '<S234>/Data Type Conversion' */
  real_T Clock_j;                      /* '<S233>/Clock' */
  real_T LookUpTable_hf;               /* '<S233>/Look-Up Table' */
  real_T Switch3_j4;                   /* '<S232>/Switch3' */
  real_T Switch1_p;                    /* '<S175>/Switch1' */
  real_T DataTypeConversion_l;         /* '<S239>/Data Type Conversion' */
  real_T Clock_kq;                     /* '<S238>/Clock' */
  real_T LookUpTable_dz;               /* '<S238>/Look-Up Table' */
  real_T Switch3_lq;                   /* '<S237>/Switch3' */
  real_T Switch2_e;                    /* '<S175>/Switch2' */
  real_T DataTypeConversion_mw;        /* '<S244>/Data Type Conversion' */
  real_T Clock_lb;                     /* '<S243>/Clock' */
  real_T LookUpTable_c;                /* '<S243>/Look-Up Table' */
  real_T Switch3_g;                    /* '<S242>/Switch3' */
  real_T StateSpace_o1[91];            /* '<S771>/State-Space' */
  real_T StateSpace_o2[17];            /* '<S771>/State-Space' */
  real_T RateTransition1[2];           /* '<S281>/Rate Transition1' */
  real_T _Vb[2];                       /* '<S284>/1_Vb' */
  real_T Fcn2;                         /* '<S284>/Fcn2' */
  real_T Fcn3;                         /* '<S284>/Fcn3' */
  real_T Switch2_j[2];                 /* '<S283>/Switch2' */
  real_T xtheta;                       /* '<S288>/x->theta' */
  real_T Gain;                         /* '<S289>/Gain' */
  real_T Product2;                     /* '<S287>/Product2' */
  real_T Product3;                     /* '<S287>/Product3' */
  real_T Peo;                          /* '<S287>/Sum' */
  real_T Gain_m;                       /* '<S287>/Gain' */
  real_T Product4;                     /* '<S287>/Product4' */
  real_T Product5;                     /* '<S287>/Product5' */
  real_T Qeo;                          /* '<S287>/Sum1' */
  real_T Gain1;                        /* '<S287>/Gain1' */
  real_T outputformatting[18];         /* '<S282>/output formatting' */
  real_T RateTransition3[18];          /* '<S281>/Rate Transition3' */
  real_T Sum_l;                        /* '<S304>/Sum' */
  real_T ProportionalGain;             /* '<S306>/Proportional Gain' */
  real_T Integrator_k;                 /* '<S306>/Integrator' */
  real_T DerivativeGain_cv;            /* '<S306>/Derivative Gain' */
  real_T Filter_a;                     /* '<S306>/Filter' */
  real_T SumD_bo;                      /* '<S306>/SumD' */
  real_T FilterCoefficient_np;         /* '<S306>/Filter Coefficient' */
  real_T Sum_jc;                       /* '<S306>/Sum' */
  real_T Saturation;                   /* '<S306>/Saturation' */
  real_T dq;                           /* '<S304>/Sum1' */
  real_T ProportionalGain_o;           /* '<S307>/Proportional Gain' */
  real_T Integrator_f;                 /* '<S307>/Integrator' */
  real_T DerivativeGain_a;             /* '<S307>/Derivative Gain' */
  real_T Filter_n;                     /* '<S307>/Filter' */
  real_T SumD_k;                       /* '<S307>/SumD' */
  real_T FilterCoefficient_nm;         /* '<S307>/Filter Coefficient' */
  real_T Sum_md;                       /* '<S307>/Sum' */
  real_T Saturation_e;                 /* '<S307>/Saturation' */
  real_T Sum_g;                        /* '<S305>/Sum' */
  real_T ProportionalGain_h;           /* '<S308>/Proportional Gain' */
  real_T Integrator_e;                 /* '<S308>/Integrator' */
  real_T DerivativeGain_j;             /* '<S308>/Derivative Gain' */
  real_T Filter_m;                     /* '<S308>/Filter' */
  real_T SumD_a;                       /* '<S308>/SumD' */
  real_T FilterCoefficient_j;          /* '<S308>/Filter Coefficient' */
  real_T Sum_jm;                       /* '<S308>/Sum' */
  real_T Saturation_b;                 /* '<S308>/Saturation' */
  real_T Switch_o[2];                  /* '<S252>/Switch' */
  real_T Switch1_f;                    /* '<S252>/Switch1' */
  real_T w_ref;                        /* '<S252>/Switch2' */
  real_T Sum_f;                        /* '<S252>/Sum' */
  real_T wref;                         /* '<S252>/Rate Limiter' */
  real_T wms;                          /* '<S260>/Sum' */
  real_T units;                        /* '<S303>/units' */
  real_T iqsids[2];                    /* '<S290>/1-1' */
  real_T Mult1[2];                     /* '<S290>/Mult1' */
  real_T Sum2;                         /* '<S290>/Sum2' */
  real_T Pe;                           /* '<S303>/Product' */
  real_T units1;                       /* '<S303>/units1' */
  real_T DiscreteTimeIntegrator2;      /* '<S303>/Discrete-Time Integrator2' */
  real_T Fcn_b;                        /* '<S303>/Fcn' */
  real_T theta;                        /* '<S303>/theta' */
  real_T units2;                       /* '<S303>/units2' */
  real_T RateTransition2_d[6];         /* '<S303>/Rate Transition2' */
  real_T Sum_nl;                       /* '<S264>/Sum' */
  real_T ProportionalGain_f;           /* '<S276>/Proportional Gain' */
  real_T Integrator_d;                 /* '<S276>/Integrator' */
  real_T Sum_a;                        /* '<S276>/Sum' */
  real_T Saturation_k;                 /* '<S276>/Saturation' */
  real_T Force03;                      /* '<S277>/Force > 0 #3' */
  real_T TurbochargerThrottleFuelMixtu_h;/* '<S277>/Turbocharger,Throttle,Fuel Mixture #4' */
  real_T Product;                      /* '<S277>/Product' */
  real_T f;                            /* '<S275>/f- Integrator ' */
  real_T Product_e;                    /* '<S274>/Product' */
  real_T Preventdividebyzero;          /* '<S274>/Prevent divide by zero' */
  real_T Divide_n;                     /* '<S274>/Divide' */
  real_T VariableIntegerDelay;         /* '<S274>/Variable Integer Delay' */
  real_T H;                            /* '<S274>/H' */
  real_T Product2_i;                   /* '<S274>/Product2' */
  real_T Product1;                     /* '<S274>/Product1' */
  real_T Dampingduetopumpinglosses;    /* '<S274>/Damping due to pumping losses' */
  real_T Sum1;                         /* '<S274>/Sum1' */
  real_T kWpu;                         /* '<S264>/kW-> pu' */
  real_T Powerlimit;                   /* '<S264>/Power limit' */
  real_T UnitDelay2;                   /* '<S263>/Unit Delay2' */
  real_T ProportionalGain_f4;          /* '<S262>/Proportional Gain' */
  real_T Integrator_m;                 /* '<S262>/Integrator' */
  real_T DerivativeGain_m;             /* '<S262>/Derivative Gain' */
  real_T Filter_b;                     /* '<S262>/Filter' */
  real_T SumD_i;                       /* '<S262>/SumD' */
  real_T FilterCoefficient_k;          /* '<S262>/Filter Coefficient' */
  real_T Sum_lb;                       /* '<S262>/Sum' */
  real_T Saturation_p;                 /* '<S262>/Saturation' */
  real_T v_ref;                        /* '<S252>/Switch3' */
  real_T RateLimiter1;                 /* '<S252>/Rate Limiter1' */
  real_T Divide1;                      /* '<S316>/Divide1' */
  real_T Sum1_b;                       /* '<S316>/Sum1' */
  real_T GeneratedFilterBlock_f;       /* '<S341>/Generated Filter Block' */
  real_T wood_AVR_bias;                /* '<S260>/Switch2' */
  real_T vms;                          /* '<S260>/Fcn1' */
  real_T gal_per_hr_4MVA;              /* '<S252>/[gal//hr] vs. Pm[pu]' */
  real_T Status_l;                     /* '<S10>/Memory5' */
  real_T Iabc_i[3];                    /* '<S10>/Memory1' */
  real_T Vabc_bus_m[3];                /* '<S10>/Memory2' */
  real_T Vabc_line_e[3];               /* '<S10>/Memory3' */
  real_T TempActualdegF;               /* '<S249>/Load  Thermal  Mass 50 deg//MBTU' */
  real_T AF20;                         /* '<S277>/A//F=20' */
  real_T kgseclbmhr1;                  /* '<S264>/kg//sec->lbm//hr1' */
  real_T HeatRecoveredMBtuhr;          /* '<S264>/Heat Recovery Fraction, MBtu//lbm*0.2 ' */
  real_T Nm3perhourNGfuelusage;        /* '<S264>/lbm//hr->Nm^3//hr' */
  real_T lbmhrNOx;                     /* '<S264>/lbm of NOx per hour per shaft kW' */
  real_T CO2lbmhr;                     /* '<S264>/CH4->CO2' */
  real_T HeatFromBoilerMBtuhr;         /* '<S249>/Remove Algebraic Loop1' */
  real_T CHPHeatContributionMBtuhr;    /* '<S249>/Remove Algebraic Loop' */
  real_T Derivative;                   /* '<S684>/Derivative' */
  real_T Derivative_l;                 /* '<S689>/Derivative' */
  real_T Derivative_n;                 /* '<S694>/Derivative' */
  real_T Derivative_g;                 /* '<S699>/Derivative' */
  real_T Derivative_p;                 /* '<S713>/Derivative' */
  real_T Derivative_k;                 /* '<S718>/Derivative' */
  real_T Derivative_ng;                /* '<S723>/Derivative' */
  real_T Derivative_o;                 /* '<S728>/Derivative' */
  real_T AnalogOut2toSEL751;           /* '<S3>/AnalogOut2 to SEL-751' */
  real_T Derivative_i;                 /* '<S85>/Derivative' */
  real_T Derivative_iz;                /* '<S90>/Derivative' */
  real_T Derivative_nt;                /* '<S95>/Derivative' */
  real_T donotdeletethisgain;          /* '<S37>/do not delete this gain' */
  real_T donotdeletethisgain_p;        /* '<S38>/do not delete this gain' */
  real_T donotdeletethisgain_m;        /* '<S39>/do not delete this gain' */
  real_T Kv[3];                        /* '<S25>/Kv' */
  real_T donotdeletethisgain_d;        /* '<S40>/do not delete this gain' */
  real_T donotdeletethisgain_c;        /* '<S41>/do not delete this gain' */
  real_T donotdeletethisgain_a;        /* '<S42>/do not delete this gain' */
  real_T Kv1[3];                       /* '<S25>/Kv1' */
  real_T donotdeletethisgain_l;        /* '<S61>/do not delete this gain' */
  real_T donotdeletethisgain_i;        /* '<S62>/do not delete this gain' */
  real_T donotdeletethisgain_b;        /* '<S63>/do not delete this gain' */
  real_T Kv_l[3];                      /* '<S26>/Kv' */
  real_T donotdeletethisgain_k;        /* '<S64>/do not delete this gain' */
  real_T donotdeletethisgain_j;        /* '<S65>/do not delete this gain' */
  real_T donotdeletethisgain_b5;       /* '<S66>/do not delete this gain' */
  real_T Kv1_e[3];                     /* '<S26>/Kv1' */
  real_T Derivative_b;                 /* '<S159>/Derivative' */
  real_T Derivative_j;                 /* '<S164>/Derivative' */
  real_T Derivative_l2;                /* '<S169>/Derivative' */
  real_T donotdeletethisgain_mo;       /* '<S111>/do not delete this gain' */
  real_T donotdeletethisgain_c4;       /* '<S112>/do not delete this gain' */
  real_T donotdeletethisgain_if;       /* '<S113>/do not delete this gain' */
  real_T Kv_ls[3];                     /* '<S99>/Kv' */
  real_T donotdeletethisgain_ky;       /* '<S114>/do not delete this gain' */
  real_T donotdeletethisgain_ba;       /* '<S115>/do not delete this gain' */
  real_T donotdeletethisgain_bd;       /* '<S116>/do not delete this gain' */
  real_T Kv1_m[3];                     /* '<S99>/Kv1' */
  real_T donotdeletethisgain_g;        /* '<S135>/do not delete this gain' */
  real_T donotdeletethisgain_dj;       /* '<S136>/do not delete this gain' */
  real_T donotdeletethisgain_dp;       /* '<S137>/do not delete this gain' */
  real_T Kv_n[3];                      /* '<S100>/Kv' */
  real_T donotdeletethisgain_d3;       /* '<S138>/do not delete this gain' */
  real_T donotdeletethisgain_h;        /* '<S139>/do not delete this gain' */
  real_T donotdeletethisgain_c0;       /* '<S140>/do not delete this gain' */
  real_T Kv1_o[3];                     /* '<S100>/Kv1' */
  real_T Derivative_g4;                /* '<S233>/Derivative' */
  real_T Derivative_c;                 /* '<S238>/Derivative' */
  real_T Derivative_k0;                /* '<S243>/Derivative' */
  real_T donotdeletethisgain_la;       /* '<S185>/do not delete this gain' */
  real_T donotdeletethisgain_ix;       /* '<S186>/do not delete this gain' */
  real_T donotdeletethisgain_ifx;      /* '<S187>/do not delete this gain' */
  real_T Kv_o[3];                      /* '<S173>/Kv' */
  real_T donotdeletethisgain_e;        /* '<S188>/do not delete this gain' */
  real_T donotdeletethisgain_an;       /* '<S189>/do not delete this gain' */
  real_T donotdeletethisgain_o;        /* '<S190>/do not delete this gain' */
  real_T Kv1_l[3];                     /* '<S173>/Kv1' */
  real_T donotdeletethisgain_ch;       /* '<S209>/do not delete this gain' */
  real_T donotdeletethisgain_bt;       /* '<S210>/do not delete this gain' */
  real_T donotdeletethisgain_f;        /* '<S211>/do not delete this gain' */
  real_T Kv_j[3];                      /* '<S174>/Kv' */
  real_T donotdeletethisgain_moi;      /* '<S212>/do not delete this gain' */
  real_T donotdeletethisgain_hr;       /* '<S213>/do not delete this gain' */
  real_T donotdeletethisgain_jn;       /* '<S214>/do not delete this gain' */
  real_T Kv1_b[3];                     /* '<S174>/Kv1' */
  real_T DigitalOuttoSEL751;           /* '<S3>/DigitalOut to SEL-751' */
  real_T TmpSignalConversionAtModbusdevi[5];
  real_T Modbusdevice_o1;              /* '<S12>/Modbus device' */
  real_T Modbusdevice_o2[2];           /* '<S12>/Modbus device' */
  real_T SIM_HIL1;                     /* '<S249>/SIM_HIL1' */
  real_T Sum4;                         /* '<S249>/Sum4' */
  real_T DerivativeGain_n;             /* '<S251>/Derivative Gain' */
  real_T Filter_o;                     /* '<S251>/Filter' */
  real_T SumD_h;                       /* '<S251>/SumD' */
  real_T FilterCoefficient_e;          /* '<S251>/Filter Coefficient' */
  real_T IntegralGain;                 /* '<S251>/Integral Gain' */
  real_T Integrator_je;                /* '<S251>/Integrator' */
  real_T ProportionalGain_c;           /* '<S251>/Proportional Gain' */
  real_T Sum_d;                        /* '<S251>/Sum' */
  real_T Saturation_h;                 /* '<S251>/Saturation' */
  real_T CHPMIxingTC1;                 /* '<S249>/CHP MIxing TC1' */
  real_T PipingTransportDelay1;        /* '<S249>/Piping Transport Delay1' */
  real_T SIM_HIL2;                     /* '<S249>/SIM_HIL2' */
  real_T OpFromFile_o1;                /* '<S3>/OpFromFile' */
  real_T HeatLoadMBtuhr;               /* '<S3>/OpFromFile' */
  real_T OpFromFile_o3;                /* '<S3>/OpFromFile' */
  real_T OpFromFile_o4;                /* '<S3>/OpFromFile' */
  real_T Sum1_o;                       /* '<S249>/Sum1' */
  real_T CHPHeatContributionMBtuhr_o;  /* '<S249>/Supply Heating From Hrec to Load' */
  real_T Gain_g[3];                    /* '<S253>/Gain' */
  real_T Gain1_g[3];                   /* '<S253>/Gain1' */
  real_T Gain4[3];                     /* '<S253>/Gain4' */
  real_T AnalogOut;                    /* '<S253>/AnalogOut' */
  real_T Gain5[3];                     /* '<S253>/Gain5' */
  real_T Add1;                         /* '<S250>/Add1' */
  real_T Gain4_c;                      /* '<S309>/Gain4' */
  real_T RTESPWM;                      /* '<S309>/RTE SPWM' */
  real_T RTEConversion;                /* '<S309>/RTE Conversion' */
  real_T Gain1_a;                      /* '<S309>/Gain1' */
  real_T Gain4_h;                      /* '<S310>/Gain4' */
  real_T RTESPWM_c;                    /* '<S310>/RTE SPWM' */
  real_T RTEConversion_f;              /* '<S310>/RTE Conversion' */
  real_T Gain1_b;                      /* '<S310>/Gain1' */
  real_T AnalogOut1;                   /* '<S253>/AnalogOut1' */
  real_T Clock1;                       /* '<S309>/Clock1' */
  real_T Product3_p;                   /* '<S309>/Product3' */
  real_T Product1_e;                   /* '<S309>/Product1' */
  real_T Output;                       /* '<S309>/Output' */
  real_T Gain3;                        /* '<S309>/Gain3' */
  real_T Clock1_a;                     /* '<S310>/Clock1' */
  real_T Product3_i;                   /* '<S310>/Product3' */
  real_T Product1_o;                   /* '<S310>/Product1' */
  real_T Output_m;                     /* '<S310>/Output' */
  real_T Gain3_h;                      /* '<S310>/Gain3' */
  real_T Gain3_i[3];                   /* '<S253>/Gain3' */
  real_T Gain2[3];                     /* '<S253>/Gain2' */
  real_T Gain7[3];                     /* '<S253>/Gain7' */
  real_T Gain6[3];                     /* '<S253>/Gain6' */
  real_T AnalogOut2;                   /* '<S253>/AnalogOut2' */
  real_T IntegralGain_h;               /* '<S262>/Integral Gain' */
  real_T Sum1_d;                       /* '<S260>/Sum1' */
  real_T DiscreteStateSpace;           /* '<S268>/Discrete State-Space' */
  real_T UnitDelay1;                   /* '<S263>/Unit Delay1' */
  real_T Sum_mu;                       /* '<S263>/Sum' */
  real_T DiscreteStateSpace_f;         /* '<S267>/Discrete State-Space' */
  real_T Gain_k;                       /* '<S269>/Gain' */
  real_T DiscreteStateSpace_m;         /* '<S273>/Discrete State-Space' */
  real_T Vfdmax1;                      /* '<S270>/Vfdmax1' */
  real_T DataTypeConversion3;          /* '<S270>/Data Type  Conversion3' */
  real_T Vfdmax;                       /* '<S270>/Vfdmax' */
  real_T Sum_am;                       /* '<S270>/Sum' */
  real_T DataTypeConversion_cd;        /* '<S270>/Data Type  Conversion' */
  real_T Product_e4;                   /* '<S270>/Product' */
  real_T DataTypeConversion1_h;        /* '<S270>/Data Type  Conversion1' */
  real_T Product1_g;                   /* '<S270>/Product1' */
  real_T DataTypeConversion2;          /* '<S270>/Data Type  Conversion2' */
  real_T Product2_n;                   /* '<S270>/Product2' */
  real_T Sum1_c;                       /* '<S270>/Sum1' */
  real_T Gain_e;                       /* '<S266>/Gain' */
  real_T DiscreteStateSpace_b;         /* '<S272>/Discrete State-Space' */
  real_T Gain_c;                       /* '<S265>/Gain' */
  real_T DiscreteStateSpace_c;         /* '<S271>/Discrete State-Space' */
  real_T Pbase;                        /* '<S274>/1//Pbase' */
  real_T Initialspeed400RPM;           /* '<S274>/Initial speed 400 RPM' */
  real_T Inertia;                      /* '<S274>/Inertia' */
  real_T Preventdividebyzero1;         /* '<S274>/Prevent divide by zero1' */
  real_T Divide1_e;                    /* '<S274>/Divide1' */
  real_T Thermalefficiencycurve;       /* '<S274>/Thermal efficiency curve' */
  real_T Viscousdamping1;              /* '<S274>/Viscous damping1' */
  real_T radsecSpeedpu1;               /* '<S274>/rad//sec->Speed pu1' */
  real_T Product_l;                    /* '<S275>/Product' */
  real_T Sum_ju;                       /* '<S275>/Sum' */
  real_T Divide_b;                     /* '<S275>/Divide' */
  real_T Gain_j;                       /* '<S275>/Gain' */
  real_T Sum3_b;                       /* '<S275>/Sum3' */
  real_T Gain1_c;                      /* '<S275>/Gain1' */
  real_T Gain2_n;                      /* '<S275>/Gain2' */
  real_T puRPM;                        /* '<S275>/pu->RPM' */
  real_T RPMDisplacementssec;          /* '<S275>/RPM->Displacements//sec' */
  real_T Product1_n;                   /* '<S275>/Product1' */
  real_T Sum2_g;                       /* '<S275>/Sum2' */
  real_T Sum1_d3;                      /* '<S275>/Sum1' */
  real_T IntegralGain_i;               /* '<S276>/Integral Gain' */
  real_T SumI2;                        /* '<S276>/SumI2' */
  real_T Kb;                           /* '<S276>/Kb' */
  real_T SumI1;                        /* '<S276>/SumI1' */
  real_T kgseclbmhr;                   /* '<S264>/kg//sec->lbm//hr' */
  real_T xr;                           /* '<S288>/x->r' */
  real_T Vfd;                          /* '<S281>/N' */
  real_T RateTransition1_o;            /* '<S303>/Rate Transition1' */
  real_T _Pb;                          /* '<S303>/1_Pb' */
  real_T div;                          /* '<S303>/div' */
  real_T F1;                           /* '<S303>/F1' */
  real_T Sum2_d;                       /* '<S303>/Sum2' */
  real_T _2H;                          /* '<S303>/1_(2H)' */
  real_T web1;                         /* '<S303>/web1' */
  real_T web3;                         /* '<S303>/web3' */
  real_T IntegralGain_d;               /* '<S306>/Integral Gain' */
  real_T SumI2_l;                      /* '<S306>/SumI2' */
  real_T Kb_d;                         /* '<S306>/Kb' */
  real_T SumI1_j;                      /* '<S306>/SumI1' */
  real_T IntegralGain_k;               /* '<S307>/Integral Gain' */
  real_T SumI2_j;                      /* '<S307>/SumI2' */
  real_T Kb_a;                         /* '<S307>/Kb' */
  real_T SumI1_c;                      /* '<S307>/SumI1' */
  real_T IntegralGain_hw;              /* '<S308>/Integral Gain' */
  real_T SumI2_g;                      /* '<S308>/SumI2' */
  real_T Kb_f;                         /* '<S308>/Kb' */
  real_T SumI1_c2;                     /* '<S308>/SumI1' */
  real_T Switch_j;                     /* '<S250>/Switch' */
  real_T OpCtrl_o1;                    /* '<S254>/OpCtrl' */
  real_T OpCtrl_o2[8];                 /* '<S254>/OpCtrl' */
  real_T DataTypeConversion_ju;        /* '<S312>/Data Type Conversion' */
  real_T Switch4;                      /* '<S312>/Switch4' */
  real_T Switch3_kh;                   /* '<S312>/Switch3' */
  real_T DigitalOut;                   /* '<S311>/DigitalOut' */
  real_T Switch6;                      /* '<S312>/Switch6' */
  real_T Add2;                         /* '<S312>/Add2' */
  real_T Switch7;                      /* '<S312>/Switch7' */
  real_T Add3;                         /* '<S312>/Add3' */
  real_T DataTypeConversion1_l;        /* '<S312>/Data Type Conversion1' */
  real_T Switch_jb;                    /* '<S312>/Switch' */
  real_T Switch5;                      /* '<S312>/Switch5' */
  real_T Switch8;                      /* '<S312>/Switch8' */
  real_T Switch9;                      /* '<S312>/Switch9' */
  real_T PWMOut;                       /* '<S314>/PWM Out' */
  real_T PWMOut1;                      /* '<S314>/PWM Out1' */
  real_T EventGenerator;               /* '<S315>/EventGenerator' */
  real_T EventGenerator1;              /* '<S315>/EventGenerator1' */
  real_T AnalogIn1_o1[8];              /* '<S339>/AnalogIn1' */
  real_T AnalogIn1_o2;                 /* '<S339>/AnalogIn1' */
  real_T DataInSend;                   /* '<S313>/DataIn Send' */
  real_T DataInSend1;                  /* '<S313>/DataIn Send1' */
  real_T donotdeletethisgain_fy;       /* '<S401>/do not delete this gain' */
  real_T donotdeletethisgain_bp;       /* '<S402>/do not delete this gain' */
  real_T donotdeletethisgain_d5;       /* '<S403>/do not delete this gain' */
  real_T Kv1_c[3];                     /* '<S383>/Kv1' */
  real_T donotdeletethisgain_djc;      /* '<S398>/do not delete this gain' */
  real_T donotdeletethisgain_os;       /* '<S399>/do not delete this gain' */
  real_T donotdeletethisgain_n;        /* '<S400>/do not delete this gain' */
  real_T Kv_ld[3];                     /* '<S383>/Kv' */
  real_T Product1_i[3];                /* '<S384>/Product1' */
  real_T Sum5;                         /* '<S384>/Sum5' */
  real_T Sum6;                         /* '<S384>/Sum6' */
  real_T Sum_gz;                       /* '<S384>/Sum' */
  real_T Product3_ie[3];               /* '<S384>/Product3' */
  real_T Sum1_n;                       /* '<S384>/Sum1' */
  real_T P;                            /* '<S384>/Sum4' */
  real_T Q;                            /* '<S384>/pu->V' */
  real_T Integ4[2];                    /* '<S385>/Integ4' */
  real_T SFunction_a[2];               /* '<S386>/S-Function ' */
  real_T UnitDelay_n[2];               /* '<S385>/Unit Delay' */
  real_T Step;                         /* '<S385>/Step' */
  real_T Switch_d[2];                  /* '<S385>/Switch' */
  real_T Gain_kq[2];                   /* '<S381>/Gain' */
  real_T Fcn_k;                        /* '<S381>/Fcn' */
  real_T a[3];                         /* '<S3>/a' */
  real_T Memory;                       /* '<S734>/Memory' */
  real_T DiscreteTimeIntegrtor;        /* '<S734>/Discrete-Time Integrtor' */
  real_T Divide_bg;                    /* '<S734>/Divide' */
  real_T DiscreteTimeIntegrator_c;     /* '<S745>/Discrete-Time Integrator' */
  real_T MathFunction_m;               /* '<S745>/Math Function' */
  real_T TrigonometricFunction;        /* '<S745>/Trigonometric Function' */
  real_T Phase_sel;                    /* '<S733>/Phase_sel' */
  real_T Switch1_c;                    /* '<S733>/Switch1' */
  real_T Saturation_m;                 /* '<S747>/Saturation' */
  real_T Saturation_bz;                /* '<S746>/Saturation' */
  real_T Switch1_i;                    /* '<S22>/Switch1' */
  real_T Memory_d;                     /* '<S741>/Memory' */
  real_T MultiportSwitch;              /* '<S732>/Multiport Switch' */
  real_T DiscreteTimeIntegrator1;      /* '<S741>/Discrete-Time Integrator1' */
  real_T DataTypeConversion2_k;        /* '<S732>/Data Type Conversion2' */
  real_T Memory_a;                     /* '<S737>/Memory' */
  real_T DiscreteTimeIntegrtor_g;      /* '<S737>/Discrete-Time Integrtor' */
  real_T MultiportSwitch7;             /* '<S731>/Multiport Switch7' */
  real_T degrad1;                      /* '<S731>/deg//rad1' */
  real_T Phi_meas_add;                 /* '<S735>/Phi_meas_add' */
  real_T sin_n;                        /* '<S735>/sin' */
  real_T DiscreteTimeIntegrator_b;     /* '<S741>/Discrete-Time Integrator' */
  real_T Memory_j;                     /* '<S738>/Memory' */
  real_T DiscreteTimeIntegrtor_d;      /* '<S738>/Discrete-Time Integrtor' */
  real_T MultiportSwitch1;             /* '<S731>/Multiport Switch1' */
  real_T DataTypeConversion2_f;        /* '<S735>/Data Type Conversion2' */
  real_T MultiportSwitch5;             /* '<S731>/Multiport Switch5' */
  real_T Pulse_Fault_act_Tstart;       /* '<S735>/Data Type Conversion1' */
  real_T Tstart;                       /* '<S735>/POW_en_switch' */
  real_T Uk1;                          /* '<S739>/Delay Input1' */
  real_T UnitDelay_g;                  /* '<S739>/Unit Delay' */
  real_T Switch_g;                     /* '<S739>/Switch' */
  real_T WeightedSampleTimeMath;       /* '<S739>/Weighted Sample Time Math' */
  real_T Sum1_k;                       /* '<S739>/Sum1' */
  real_T WeightedSampleTimeMath1;      /* '<S739>/Weighted Sample Time Math1' */
  real_T DataTypeConversion1_e;        /* '<S731>/Data Type Conversion1' */
  real_T fault_type;                   /* '<S731>/Multiport Switch3' */
  real_T fault_location;               /* '<S731>/Multiport Switch4' */
  real_T Divide_p;                     /* '<S737>/Divide' */
  real_T Divide_j;                     /* '<S738>/Divide' */
  real_T DataTypeConversion1_hc;       /* '<S741>/Data Type Conversion1' */
  real_T TrigonometricFunction2;       /* '<S745>/Trigonometric Function2' */
  real_T Vq;                           /* '<S745>/Product1' */
  real_T Integ4_a;                     /* '<S752>/Integ4' */
  real_T UnitDelay_d;                  /* '<S745>/Unit Delay' */
  real_T Freq_i;                       /* '<S752>/To avoid division by zero' */
  real_T Numberofsamplespercycle;      /* '<S752>/Number of samples per cycle' */
  real_T RoundingFunction;             /* '<S752>/Rounding Function' */
  real_T Delay_k;                      /* '<S752>/Gain' */
  real_T SFunction_d;                  /* '<S763>/S-Function ' */
  real_T UnitDelay_b;                  /* '<S762>/Unit Delay' */
  real_T Step_b;                       /* '<S752>/Step' */
  real_T Switch_m;                     /* '<S752>/Switch' */
  real_T Divide_jx;                    /* '<S745>/Divide' */
  real_T Kp4;                          /* '<S750>/Kp4' */
  real_T DiscreteTimeIntegrator_g;     /* '<S750>/Discrete-Time Integrator' */
  real_T Kp6;                          /* '<S750>/Kp6' */
  real_T ZeroOrderHold;                /* '<S750>/Zero-Order Hold' */
  real_T TSamp;                        /* '<S761>/TSamp' */
  real_T Uk1_j;                        /* '<S761>/UD' */
  real_T Diff;                         /* '<S761>/Diff' */
  real_T Sum6_m;                       /* '<S750>/Sum6' */
  real_T Saturation2;                  /* '<S750>/Saturation2' */
  real_T Gain10;                       /* '<S745>/Gain10' */
  real_T y1;                           /* '<S751>/Unit  Delay' */
  real_T Sum1_ns;                      /* '<S751>/Sum1' */
  real_T Deltau_limit;                 /* '<S751>/Saturation' */
  real_T y;                            /* '<S751>/Sum' */
  real_T DiscreteStateSpace_g;         /* '<S748>/Discrete State-Space' */
  real_T Kp5;                          /* '<S750>/Kp5' */
  real_T IntegralGain_a;               /* '<S565>/Integral Gain' */
  real_T IntegralGain_f;               /* '<S566>/Integral Gain' */
  real_T Gain1_e;                      /* '<S19>/Gain1' */
  real_T Gain2_h;                      /* '<S19>/Gain2' */
  real_T DataTypeConversion_g2;        /* '<S567>/Data Type Conversion' */
  real_T PF;                           /* '<S567>/Memory3' */
  real_T Lag_Lead;                     /* '<S567>/Memory4' */
  real_T kVA;                          /* '<S567>/Memory5' */
  real_T Vabc[3];                      /* '<S567>/Memory6' */
  real_T donotdeletethisgain_lo;       /* '<S597>/do not delete this gain' */
  real_T donotdeletethisgain_jv;       /* '<S598>/do not delete this gain' */
  real_T donotdeletethisgain_gd;       /* '<S599>/do not delete this gain' */
  real_T Kv1_n[3];                     /* '<S577>/Kv1' */
  real_T donotdeletethisgain_as;       /* '<S594>/do not delete this gain' */
  real_T donotdeletethisgain_lam;      /* '<S595>/do not delete this gain' */
  real_T donotdeletethisgain_gi;       /* '<S596>/do not delete this gain' */
  real_T Kv_m[3];                      /* '<S577>/Kv' */
  real_T Product1_k[3];                /* '<S580>/Product1' */
  real_T Sum5_b;                       /* '<S580>/Sum5' */
  real_T Sum6_p;                       /* '<S580>/Sum6' */
  real_T Sum_jv;                       /* '<S580>/Sum' */
  real_T Product3_m[3];                /* '<S580>/Product3' */
  real_T Sum1_i;                       /* '<S580>/Sum1' */
  real_T P_c;                          /* '<S580>/Sum4' */
  real_T Q_k;                          /* '<S580>/pu->V' */
  real_T Integ4_o[2];                  /* '<S583>/Integ4' */
  real_T SFunction_p[2];               /* '<S587>/S-Function ' */
  real_T UnitDelay_gi[2];              /* '<S583>/Unit Delay' */
  real_T Step_a;                       /* '<S583>/Step' */
  real_T Switch_d5[2];                 /* '<S583>/Switch' */
  real_T Gain_ch[2];                   /* '<S576>/Gain' */
  real_T Abs3;                         /* '<S576>/Abs3' */
  real_T Abs4;                         /* '<S576>/Abs4' */
  real_T Abs5;                         /* '<S576>/Abs5' */
  real_T Fcn1_p;                       /* '<S576>/Fcn1' */
  real_T Divide1_c;                    /* '<S576>/Divide1' */
  real_T FixPtUnitDelay1;              /* '<S585>/FixPt Unit Delay1' */
  real_T Xnew;                         /* '<S585>/Enable' */
  real_T UnitDelay_l;                  /* '<S613>/Unit Delay' */
  real_T donotdeletethisgain_l5;       /* '<S572>/do not delete this gain' */
  real_T donotdeletethisgain_fh;       /* '<S573>/do not delete this gain' */
  real_T donotdeletethisgain_od;       /* '<S574>/do not delete this gain' */
  real_T TmpSignalConversionAtGain3Inpor[3];
  real_T Gain3_g[3];                   /* '<S647>/Gain3' */
  real_T Gain1_o[3];                   /* '<S647>/Gain1' */
  real_T Switch_dt[2];                 /* '<S646>/Switch' */
  real_T Integ4_f;                     /* '<S643>/Integ4' */
  real_T Freq_o;                       /* '<S643>/To avoid division  by zero' */
  real_T Numberofsamplespercycle_h;    /* '<S643>/Number of samples per cycle' */
  real_T RoundingFunction_l;           /* '<S643>/Rounding Function' */
  real_T Delay_e;                      /* '<S643>/Gain' */
  real_T SFunction_ap;                 /* '<S645>/S-Function' */
  real_T UnitDelay_c;                  /* '<S644>/Unit Delay' */
  real_T DigitalClock_d;               /* '<S643>/Digital  Clock' */
  real_T UnitDelay1_k;                 /* '<S643>/Unit Delay1' */
  real_T Switch_n;                     /* '<S643>/Switch' */
  real_T Divide_h;                     /* '<S613>/Divide' */
  real_T DiscreteDerivative;           /* '<S615>/Discrete Derivative ' */
  real_T DiscreteTimeIntegrator_o;     /* '<S615>/Discrete-Time Integrator' */
  real_T Kp4_g;                        /* '<S615>/Kp4' */
  real_T Sum6_a;                       /* '<S615>/Sum6' */
  real_T Saturation1;                  /* '<S615>/Saturation1' */
  real_T Gain10_c;                     /* '<S613>/Gain10' */
  real_T RateLimiter;                  /* '<S613>/Rate Limiter' */
  real_T x1k;                          /* '<S638>/Delay_x1' */
  real_T A11;                          /* '<S639>/A11' */
  real_T x2k;                          /* '<S638>/Delay_x2' */
  real_T A12;                          /* '<S639>/A12' */
  real_T A21;                          /* '<S639>/A21' */
  real_T A22;                          /* '<S639>/A22' */
  real_T sum2;                         /* '<S639>/sum2' */
  real_T sum3;                         /* '<S639>/sum3' */
  real_T B11;                          /* '<S640>/B11' */
  real_T x1k1;                         /* '<S638>/A*x1(k) + B*u1(k) ' */
  real_T B21;                          /* '<S640>/B21' */
  real_T x2k1;                         /* '<S638>/A*x2(k) + B*u2(k)' */
  real_T Duk;                          /* '<S638>/D*u(k)' */
  real_T C11;                          /* '<S641>/C11' */
  real_T C12;                          /* '<S641>/C12' */
  real_T sum2_n;                       /* '<S641>/sum2' */
  real_T yk;                           /* '<S638>/C*X(k)+D*u(k)' */
  real_T Switch_l3[3];                 /* '<S570>/Switch' */
  real_T IntegralGain_fg;              /* '<S454>/Integral Gain' */
  real_T IntegralGain_n;               /* '<S455>/Integral Gain' */
  real_T Gain1_cn;                     /* '<S18>/Gain1' */
  real_T Gain2_i;                      /* '<S18>/Gain2' */
  real_T DataTypeConversion_gb;        /* '<S456>/Data Type Conversion' */
  real_T PF_k;                         /* '<S456>/Memory3' */
  real_T Lag_Lead_j;                   /* '<S456>/Memory4' */
  real_T kVA_d;                        /* '<S456>/Memory5' */
  real_T Vabc_p[3];                    /* '<S456>/Memory6' */
  real_T donotdeletethisgain_ke;       /* '<S486>/do not delete this gain' */
  real_T donotdeletethisgain_ez;       /* '<S487>/do not delete this gain' */
  real_T donotdeletethisgain_i5;       /* '<S488>/do not delete this gain' */
  real_T Kv1_d[3];                     /* '<S466>/Kv1' */
  real_T donotdeletethisgain_j2;       /* '<S483>/do not delete this gain' */
  real_T donotdeletethisgain_ie;       /* '<S484>/do not delete this gain' */
  real_T donotdeletethisgain_fe;       /* '<S485>/do not delete this gain' */
  real_T Kv_h[3];                      /* '<S466>/Kv' */
  real_T Product1_oy[3];               /* '<S469>/Product1' */
  real_T Sum5_l;                       /* '<S469>/Sum5' */
  real_T Sum6_d;                       /* '<S469>/Sum6' */
  real_T Sum_my;                       /* '<S469>/Sum' */
  real_T Product3_o[3];                /* '<S469>/Product3' */
  real_T Sum1_h;                       /* '<S469>/Sum1' */
  real_T P_n;                          /* '<S469>/Sum4' */
  real_T Q_p;                          /* '<S469>/pu->V' */
  real_T Integ4_o3[2];                 /* '<S472>/Integ4' */
  real_T SFunction_am[2];              /* '<S476>/S-Function ' */
  real_T UnitDelay_j[2];               /* '<S472>/Unit Delay' */
  real_T Step_m;                       /* '<S472>/Step' */
  real_T Switch_ny[2];                 /* '<S472>/Switch' */
  real_T Gain_a[2];                    /* '<S465>/Gain' */
  real_T Abs3_e;                       /* '<S465>/Abs3' */
  real_T Abs4_d;                       /* '<S465>/Abs4' */
  real_T Abs5_b;                       /* '<S465>/Abs5' */
  real_T Fcn1_j;                       /* '<S465>/Fcn1' */
  real_T Divide1_p;                    /* '<S465>/Divide1' */
  real_T FixPtUnitDelay1_n;            /* '<S474>/FixPt Unit Delay1' */
  real_T Xnew_n;                       /* '<S474>/Enable' */
  real_T UnitDelay_c4;                 /* '<S502>/Unit Delay' */
  real_T donotdeletethisgain_o3;       /* '<S461>/do not delete this gain' */
  real_T donotdeletethisgain_mn;       /* '<S462>/do not delete this gain' */
  real_T donotdeletethisgain_is;       /* '<S463>/do not delete this gain' */
  real_T TmpSignalConversionAtGain3Inp_c[3];
  real_T Gain3_o[3];                   /* '<S536>/Gain3' */
  real_T Gain1_go[3];                  /* '<S536>/Gain1' */
  real_T Switch_k[2];                  /* '<S535>/Switch' */
  real_T Integ4_d;                     /* '<S532>/Integ4' */
  real_T Freq_m;                       /* '<S532>/To avoid division  by zero' */
  real_T Numberofsamplespercycle_d;    /* '<S532>/Number of samples per cycle' */
  real_T RoundingFunction_i;           /* '<S532>/Rounding Function' */
  real_T Delay_h;                      /* '<S532>/Gain' */
  real_T SFunction_e;                  /* '<S534>/S-Function' */
  real_T UnitDelay_bh;                 /* '<S533>/Unit Delay' */
  real_T DigitalClock_o;               /* '<S532>/Digital  Clock' */
  real_T UnitDelay1_o;                 /* '<S532>/Unit Delay1' */
  real_T Switch_lo;                    /* '<S532>/Switch' */
  real_T Divide_je;                    /* '<S502>/Divide' */
  real_T DiscreteDerivative_k;         /* '<S504>/Discrete Derivative ' */
  real_T DiscreteTimeIntegrator_d;     /* '<S504>/Discrete-Time Integrator' */
  real_T Kp4_f;                        /* '<S504>/Kp4' */
  real_T Sum6_c;                       /* '<S504>/Sum6' */
  real_T Saturation1_i;                /* '<S504>/Saturation1' */
  real_T Gain10_e;                     /* '<S502>/Gain10' */
  real_T RateLimiter_l;                /* '<S502>/Rate Limiter' */
  real_T x1k_e;                        /* '<S527>/Delay_x1' */
  real_T A11_h;                        /* '<S528>/A11' */
  real_T x2k_e;                        /* '<S527>/Delay_x2' */
  real_T A12_m;                        /* '<S528>/A12' */
  real_T A21_c;                        /* '<S528>/A21' */
  real_T A22_a;                        /* '<S528>/A22' */
  real_T sum2_e;                       /* '<S528>/sum2' */
  real_T sum3_e;                       /* '<S528>/sum3' */
  real_T B11_a;                        /* '<S529>/B11' */
  real_T x1k1_m;                       /* '<S527>/A*x1(k) + B*u1(k) ' */
  real_T B21_p;                        /* '<S529>/B21' */
  real_T x2k1_i;                       /* '<S527>/A*x2(k) + B*u2(k)' */
  real_T Duk_j;                        /* '<S527>/D*u(k)' */
  real_T C11_p;                        /* '<S530>/C11' */
  real_T C12_g;                        /* '<S530>/C12' */
  real_T sum2_na;                      /* '<S530>/sum2' */
  real_T yk_i;                         /* '<S527>/C*X(k)+D*u(k)' */
  real_T Switch_iv[3];                 /* '<S459>/Switch' */
  real_T OpFromFile1_o1;               /* '<S3>/OpFromFile1' */
  real_T OpFromFile1_o2[2];            /* '<S3>/OpFromFile1' */
  real_T OpFromFile1_o3;               /* '<S3>/OpFromFile1' */
  real_T OpFromFile1_o4;               /* '<S3>/OpFromFile1' */
  real_T Time_Scale_Factor1;           /* '<S3>/Time_Scale_Factor 1' */
  real_T kW_lr;                        /* '<S17>/Memory5' */
  real_T kvar_a;                       /* '<S17>/Memory5' */
  real_T Loading_c;                    /* '<S17>/Memory5' */
  real_T donotdeletethisgain_ax;       /* '<S436>/do not delete this gain' */
  real_T donotdeletethisgain_j0;       /* '<S437>/do not delete this gain' */
  real_T donotdeletethisgain_kn;       /* '<S438>/do not delete this gain' */
  real_T Kv1_h[3];                     /* '<S418>/Kv1' */
  real_T donotdeletethisgain_me;       /* '<S433>/do not delete this gain' */
  real_T donotdeletethisgain_ca;       /* '<S434>/do not delete this gain' */
  real_T donotdeletethisgain_pt;       /* '<S435>/do not delete this gain' */
  real_T Kv_jz[3];                     /* '<S418>/Kv' */
  real_T Product1_ka[3];               /* '<S419>/Product1' */
  real_T Sum5_f;                       /* '<S419>/Sum5' */
  real_T Sum6_k;                       /* '<S419>/Sum6' */
  real_T Sum_b;                        /* '<S419>/Sum' */
  real_T Product3_e[3];                /* '<S419>/Product3' */
  real_T Sum1_a;                       /* '<S419>/Sum1' */
  real_T P_g;                          /* '<S419>/Sum4' */
  real_T Q_f;                          /* '<S419>/pu->V' */
  real_T Integ4_g[2];                  /* '<S420>/Integ4' */
  real_T SFunction_b[2];               /* '<S421>/S-Function ' */
  real_T UnitDelay_a[2];               /* '<S420>/Unit Delay' */
  real_T Step_k;                       /* '<S420>/Step' */
  real_T Switch_fo[2];                 /* '<S420>/Switch' */
  real_T Gain_aj[2];                   /* '<S416>/Gain' */
  real_T Fcn_j;                        /* '<S416>/Fcn' */
  real_T donotdeletethisgain_hj;       /* '<S353>/do not delete this gain' */
  real_T donotdeletethisgain_jv2;      /* '<S355>/do not delete this gain' */
  real_T donotdeletethisgain_d0;       /* '<S351>/do not delete this gain' */
  real_T donotdeletethisgain_fl;       /* '<S369>/do not delete this gain' */
  real_T donotdeletethisgain_j2b;      /* '<S371>/do not delete this gain' */
  real_T donotdeletethisgain_df;       /* '<S367>/do not delete this gain' */
  real_T Sum1_g;                       /* '<S762>/Sum1' */
  real_T Sum5_bi;                      /* '<S762>/Sum5' */
  real_T Product5_j;                   /* '<S762>/Product5' */
  real_T Gain1_m;                      /* '<S762>/Gain1' */
  real_T Sum4_i;                       /* '<S762>/Sum4' */
  real_T Product2_a;                   /* '<S762>/Product2' */
  real_T Product4_e;                   /* '<S762>/Product4' */
  real_T Sum7;                         /* '<S752>/Sum7' */
  real_T Meanvalue;                    /* '<S752>/Product' */
  real_T Sum5_e;                       /* '<S752>/Sum5' */
  real_T Gain1_au[2];                  /* '<S753>/Gain1' */
  real_T Product_o[2];                 /* '<S753>/Product' */
  real_T Integ4_dt;                    /* '<S755>/Integ4' */
  real_T Freq_j;                       /* '<S755>/To avoid division by zero' */
  real_T Numberofsamplespercycle_a;    /* '<S755>/Number of samples per cycle' */
  real_T RoundingFunction_j;           /* '<S755>/Rounding Function' */
  real_T Delay_g;                      /* '<S755>/Gain' */
  real_T SFunction_bq;                 /* '<S758>/S-Function ' */
  real_T UnitDelay_cl;                 /* '<S757>/Unit Delay' */
  real_T Step_e;                       /* '<S755>/Step' */
  real_T Switch_bg;                    /* '<S755>/Switch' */
  real_T Integ4_i;                     /* '<S756>/Integ4' */
  real_T Freq_il;                      /* '<S756>/To avoid division by zero' */
  real_T Numberofsamplespercycle_l;    /* '<S756>/Number of samples per cycle' */
  real_T RoundingFunction_f;           /* '<S756>/Rounding Function' */
  real_T Delay_d;                      /* '<S756>/Gain' */
  real_T SFunction_i;                  /* '<S760>/S-Function ' */
  real_T UnitDelay_gh;                 /* '<S759>/Unit Delay' */
  real_T Step_ex;                      /* '<S756>/Step' */
  real_T Switch_c;                     /* '<S756>/Switch' */
  real_T xr_m;                         /* '<S754>/x->r' */
  real_T xtheta_o;                     /* '<S754>/x->theta' */
  real_T RadDeg;                       /* '<S753>/Rad->Deg.' */
  real_T Saturation_j;                 /* '<S749>/Saturation' */
  real_T MathFunction_f;               /* '<S749>/Math Function' */
  real_T Sum1_bb;                      /* '<S759>/Sum1' */
  real_T Sum5_l4;                      /* '<S759>/Sum5' */
  real_T Product5_g;                   /* '<S759>/Product5' */
  real_T Gain1_cr;                     /* '<S759>/Gain1' */
  real_T Sum4_b;                       /* '<S759>/Sum4' */
  real_T Product2_nu;                  /* '<S759>/Product2' */
  real_T Product4_j;                   /* '<S759>/Product4' */
  real_T Sum7_k;                       /* '<S756>/Sum7' */
  real_T Meanvalue_o;                  /* '<S756>/Product' */
  real_T Sum5_a;                       /* '<S756>/Sum5' */
  real_T Sum1_e;                       /* '<S757>/Sum1' */
  real_T Sum5_g;                       /* '<S757>/Sum5' */
  real_T Product5_m;                   /* '<S757>/Product5' */
  real_T Gain1_ow;                     /* '<S757>/Gain1' */
  real_T Sum4_e;                       /* '<S757>/Sum4' */
  real_T Product2_f;                   /* '<S757>/Product2' */
  real_T Product4_jc;                  /* '<S757>/Product4' */
  real_T Sum7_e;                       /* '<S755>/Sum7' */
  real_T Meanvalue_g;                  /* '<S755>/Product' */
  real_T Sum5_g0;                      /* '<S755>/Sum5' */
  real_T MultiportSwitch2;             /* '<S731>/Multiport Switch2' */
  real_T Add_k;                        /* '<S737>/Add' */
  real_T Add_f;                        /* '<S738>/Add' */
  real_T Add_m;                        /* '<S734>/Add' */
  real_T DataTypeConversion_d;         /* '<S733>/Data Type Conversion' */
  real_T DataTypeConversion_ci;        /* '<S730>/Data Type Conversion' */
  real_T DataTypeConversion_nl;        /* '<S725>/Data Type Conversion' */
  real_T DataTypeConversion_i;         /* '<S720>/Data Type Conversion' */
  real_T DataTypeConversion_ca;        /* '<S715>/Data Type Conversion' */
  real_T DataTypeConversion_e;         /* '<S701>/Data Type Conversion' */
  real_T DataTypeConversion_aw;        /* '<S696>/Data Type Conversion' */
  real_T DataTypeConversion_pq;        /* '<S691>/Data Type Conversion' */
  real_T DataTypeConversion_d0;        /* '<S686>/Data Type Conversion' */
  real_T DigitalClock_p;               /* '<S665>/Digital  Clock' */
  real_T Product_c[3];                 /* '<S653>/Product' */
  real_T Integ4_fg[3];                 /* '<S665>/Integ4' */
  real_T SFunction_lb[3];              /* '<S666>/S-Function' */
  real_T UnitDelay_ca[3];              /* '<S665>/Unit Delay' */
  real_T UnitDelay1_g[3];              /* '<S665>/Unit Delay1' */
  real_T Switch_e[3];                  /* '<S665>/Switch' */
  real_T Saturationtoavoidnegativesqrt[3];/* '<S653>/Saturation to avoid negative sqrt' */
  real_T Sqrt[3];                      /* '<S653>/Sqrt' */
  real_T Gain1_cf[3];                  /* '<S665>/Gain1' */
  real_T Gain_f[3];                    /* '<S665>/Gain' */
  real_T Correction[3];                /* '<S665>/Sum1' */
  real_T Sum7_i[3];                    /* '<S665>/Sum7' */
  real_T Mean[3];                      /* '<S665>/Product' */
  real_T Sum5_o[3];                    /* '<S665>/Sum5' */
  real_T sinwt;                        /* '<S654>/sin(wt)' */
  real_T Product_d[3];                 /* '<S654>/Product' */
  real_T Integ4_im[3];                 /* '<S661>/Integ4' */
  real_T SFunction_iy[3];              /* '<S662>/S-Function' */
  real_T UnitDelay_o[3];               /* '<S661>/Unit Delay' */
  real_T DigitalClock_f3;              /* '<S661>/Digital  Clock' */
  real_T UnitDelay1_f[3];              /* '<S661>/Unit Delay1' */
  real_T Switch_nf[3];                 /* '<S661>/Switch' */
  real_T coswt;                        /* '<S654>/cos(wt)' */
  real_T Product1_a[3];                /* '<S654>/Product1' */
  real_T Integ4_fr[3];                 /* '<S658>/Integ4' */
  real_T SFunction_la[3];              /* '<S659>/S-Function' */
  real_T UnitDelay_ct[3];              /* '<S658>/Unit Delay' */
  real_T DigitalClock_a;               /* '<S658>/Digital  Clock' */
  real_T UnitDelay1_b[3];              /* '<S658>/Unit Delay1' */
  real_T Switch_ls[3];                 /* '<S658>/Switch' */
  real_T ComplextoMagnitudeAngle_o1[3];/* '<S654>/Complex to Magnitude-Angle' */
  real_T ComplextoMagnitudeAngle_o2[3];/* '<S654>/Complex to Magnitude-Angle' */
  real_T RadDeg_h[3];                  /* '<S654>/Rad->Deg.' */
  real_T Gain_mm[3];                   /* '<S652>/Gain' */
  real_T Gain_p[3];                    /* '<S661>/Gain' */
  real_T Gain1_l[3];                   /* '<S661>/Gain1' */
  real_T Correction_a[3];              /* '<S661>/Sum1' */
  real_T Sum7_o[3];                    /* '<S661>/Sum7' */
  real_T Mean_k[3];                    /* '<S661>/Product' */
  real_T Sum5_lb[3];                   /* '<S661>/Sum5' */
  real_T Gain_c2[3];                   /* '<S658>/Gain' */
  real_T Gain1_gy[3];                  /* '<S658>/Gain1' */
  real_T Correction_c[3];              /* '<S658>/Sum1' */
  real_T Sum7_et[3];                   /* '<S658>/Sum7' */
  real_T Mean_n[3];                    /* '<S658>/Product' */
  real_T Sum5_gp[3];                   /* '<S658>/Sum5' */
  real_T Sum1_az;                      /* '<S644>/Sum1' */
  real_T Sum5_ek;                      /* '<S644>/Sum5' */
  real_T Product5_f;                   /* '<S644>/Product5' */
  real_T Gain1_bc;                     /* '<S644>/Gain1' */
  real_T Sum4_e3;                      /* '<S644>/Sum4' */
  real_T Product2_a2;                  /* '<S644>/Product2' */
  real_T Product4_o;                   /* '<S644>/Product4' */
  real_T Sum7_b;                       /* '<S643>/Sum7' */
  real_T Meanvalue_c;                  /* '<S643>/Product' */
  real_T Sum5_fo;                      /* '<S643>/Sum5' */
  real_T TmpSignalConversionAtGain3Inp_g[3];
  real_T Gain3_iy[3];                  /* '<S632>/Gain3' */
  real_T Gain1_p[3];                   /* '<S632>/Gain1' */
  real_T Switch_bn[2];                 /* '<S631>/Switch' */
  real_T Integ4_fd;                    /* '<S624>/Integ4' */
  real_T Freq_l;                       /* '<S624>/To avoid division  by zero' */
  real_T Numberofsamplespercycle_i;    /* '<S624>/Number of samples per cycle' */
  real_T RoundingFunction_k;           /* '<S624>/Rounding Function' */
  real_T Delay_hs;                     /* '<S624>/Gain' */
  real_T SFunction_eu;                 /* '<S626>/S-Function' */
  real_T UnitDelay_i;                  /* '<S625>/Unit Delay' */
  real_T DigitalClock_j;               /* '<S624>/Digital  Clock' */
  real_T UnitDelay1_ft;                /* '<S624>/Unit Delay1' */
  real_T Switch_b5;                    /* '<S624>/Switch' */
  real_T Integ4_ay;                    /* '<S628>/Integ4' */
  real_T Freq_mp;                      /* '<S628>/To avoid division  by zero' */
  real_T Numberofsamplespercycle_h2;   /* '<S628>/Number of samples per cycle' */
  real_T RoundingFunction_o;           /* '<S628>/Rounding Function' */
  real_T Delay_i;                      /* '<S628>/Gain' */
  real_T SFunction_h;                  /* '<S630>/S-Function' */
  real_T UnitDelay_d4;                 /* '<S629>/Unit Delay' */
  real_T DigitalClock_i;               /* '<S628>/Digital  Clock' */
  real_T UnitDelay1_n;                 /* '<S628>/Unit Delay1' */
  real_T Switch_n0;                    /* '<S628>/Switch' */
  real_T ComplextoMagnitudeAngle_o1_c; /* '<S619>/Complex to Magnitude-Angle' */
  real_T ComplextoMagnitudeAngle_o2_b; /* '<S619>/Complex to Magnitude-Angle' */
  real_T Saturation_c;                 /* '<S614>/Saturation' */
  real_T MathFunction_i;               /* '<S614>/Math Function' */
  real_T RadDeg_j;                     /* '<S619>/Rad->Deg.' */
  real_T Sum1_de;                      /* '<S629>/Sum1' */
  real_T Sum5_of;                      /* '<S629>/Sum5' */
  real_T Product5_h;                   /* '<S629>/Product5' */
  real_T Gain1_j;                      /* '<S629>/Gain1' */
  real_T Sum4_f;                       /* '<S629>/Sum4' */
  real_T Product2_g;                   /* '<S629>/Product2' */
  real_T Product4_n;                   /* '<S629>/Product4' */
  real_T Sum7_ka;                      /* '<S628>/Sum7' */
  real_T Meanvalue_i;                  /* '<S628>/Product' */
  real_T Sum5_p;                       /* '<S628>/Sum5' */
  real_T Sum1_dk;                      /* '<S625>/Sum1' */
  real_T Sum5_p2;                      /* '<S625>/Sum5' */
  real_T Product5_b;                   /* '<S625>/Product5' */
  real_T Gain1_d;                      /* '<S625>/Gain1' */
  real_T Sum4_n;                       /* '<S625>/Sum4' */
  real_T Product2_b;                   /* '<S625>/Product2' */
  real_T Product4_l;                   /* '<S625>/Product4' */
  real_T Sum7_p;                       /* '<S624>/Sum7' */
  real_T Meanvalue_l;                  /* '<S624>/Product' */
  real_T Sum5_ap;                      /* '<S624>/Sum5' */
  real_T Gain_jy[2];                   /* '<S583>/Gain' */
  real_T Gain1_ai[2];                  /* '<S583>/Gain1' */
  real_T Correction_i[2];              /* '<S583>/Sum1' */
  real_T Sum7_ky[2];                   /* '<S583>/Sum7' */
  real_T Meanvalue_e[2];               /* '<S583>/Product' */
  real_T Sum5_gn[2];                   /* '<S583>/Sum5' */
  real_T qdc;                          /* '<S571>/qd>c' */
  real_T qdb;                          /* '<S571>/qd>b' */
  real_T qda;                          /* '<S571>/qd>a' */
  real_T ProportionalGain_a;           /* '<S566>/Proportional Gain' */
  real_T Sum_h;                        /* '<S566>/Sum' */
  real_T ProportionalGain_m;           /* '<S565>/Proportional Gain' */
  real_T Sum_n0;                       /* '<S565>/Sum' */
  real_T qdc_c;                        /* '<S575>/qd>c' */
  real_T qdb_h;                        /* '<S575>/qd>b' */
  real_T qda_n;                        /* '<S575>/qd>a' */
  real_T Gain_ey[3];                   /* '<S19>/Gain' */
  real_T DigitalClock_hl;              /* '<S554>/Digital  Clock' */
  real_T Product_b[3];                 /* '<S542>/Product' */
  real_T Integ4_ft[3];                 /* '<S554>/Integ4' */
  real_T SFunction_pg[3];              /* '<S555>/S-Function' */
  real_T UnitDelay_lw[3];              /* '<S554>/Unit Delay' */
  real_T UnitDelay1_d[3];              /* '<S554>/Unit Delay1' */
  real_T Switch_n3[3];                 /* '<S554>/Switch' */
  real_T Saturationtoavoidnegativesqrt_g[3];/* '<S542>/Saturation to avoid negative sqrt' */
  real_T Sqrt_g[3];                    /* '<S542>/Sqrt' */
  real_T Gain1_cw[3];                  /* '<S554>/Gain1' */
  real_T Gain_o[3];                    /* '<S554>/Gain' */
  real_T Correction_g[3];              /* '<S554>/Sum1' */
  real_T Sum7_f[3];                    /* '<S554>/Sum7' */
  real_T Mean_o[3];                    /* '<S554>/Product' */
  real_T Sum5_pf[3];                   /* '<S554>/Sum5' */
  real_T sinwt_i;                      /* '<S543>/sin(wt)' */
  real_T Product_c2[3];                /* '<S543>/Product' */
  real_T Integ4_e[3];                  /* '<S550>/Integ4' */
  real_T SFunction_g[3];               /* '<S551>/S-Function' */
  real_T UnitDelay_h[3];               /* '<S550>/Unit Delay' */
  real_T DigitalClock_n;               /* '<S550>/Digital  Clock' */
  real_T UnitDelay1_o4[3];             /* '<S550>/Unit Delay1' */
  real_T Switch_jn[3];                 /* '<S550>/Switch' */
  real_T coswt_h;                      /* '<S543>/cos(wt)' */
  real_T Product1_or[3];               /* '<S543>/Product1' */
  real_T Integ4_i1[3];                 /* '<S547>/Integ4' */
  real_T SFunction_h1[3];              /* '<S548>/S-Function' */
  real_T UnitDelay_hc[3];              /* '<S547>/Unit Delay' */
  real_T DigitalClock_nj;              /* '<S547>/Digital  Clock' */
  real_T UnitDelay1_ni[3];             /* '<S547>/Unit Delay1' */
  real_T Switch_ix[3];                 /* '<S547>/Switch' */
  real_T ComplextoMagnitudeAngle_o1_p[3];/* '<S543>/Complex to Magnitude-Angle' */
  real_T ComplextoMagnitudeAngle_o2_l[3];/* '<S543>/Complex to Magnitude-Angle' */
  real_T RadDeg_k[3];                  /* '<S543>/Rad->Deg.' */
  real_T Gain_c0[3];                   /* '<S541>/Gain' */
  real_T Gain_ch1[3];                  /* '<S550>/Gain' */
  real_T Gain1_gh[3];                  /* '<S550>/Gain1' */
  real_T Correction_iq[3];             /* '<S550>/Sum1' */
  real_T Sum7_ih[3];                   /* '<S550>/Sum7' */
  real_T Mean_ne[3];                   /* '<S550>/Product' */
  real_T Sum5_px[3];                   /* '<S550>/Sum5' */
  real_T Gain_d[3];                    /* '<S547>/Gain' */
  real_T Gain1_cd[3];                  /* '<S547>/Gain1' */
  real_T Correction_o[3];              /* '<S547>/Sum1' */
  real_T Sum7_l[3];                    /* '<S547>/Sum7' */
  real_T Mean_c[3];                    /* '<S547>/Product' */
  real_T Sum5_k[3];                    /* '<S547>/Sum5' */
  real_T Sum1_ew;                      /* '<S533>/Sum1' */
  real_T Sum5_lj;                      /* '<S533>/Sum5' */
  real_T Product5_o;                   /* '<S533>/Product5' */
  real_T Gain1_ae;                     /* '<S533>/Gain1' */
  real_T Sum4_n3;                      /* '<S533>/Sum4' */
  real_T Product2_iy;                  /* '<S533>/Product2' */
  real_T Product4_el;                  /* '<S533>/Product4' */
  real_T Sum7_m;                       /* '<S532>/Sum7' */
  real_T Meanvalue_j;                  /* '<S532>/Product' */
  real_T Sum5_m;                       /* '<S532>/Sum5' */
  real_T TmpSignalConversionAtGain3Inp_m[3];
  real_T Gain3_b[3];                   /* '<S521>/Gain3' */
  real_T Gain1_lp[3];                  /* '<S521>/Gain1' */
  real_T Switch_gd[2];                 /* '<S520>/Switch' */
  real_T Integ4_g5;                    /* '<S513>/Integ4' */
  real_T Freq_h;                       /* '<S513>/To avoid division  by zero' */
  real_T Numberofsamplespercycle_m;    /* '<S513>/Number of samples per cycle' */
  real_T RoundingFunction_m;           /* '<S513>/Rounding Function' */
  real_T Delay_c;                      /* '<S513>/Gain' */
  real_T SFunction_ie;                 /* '<S515>/S-Function' */
  real_T UnitDelay_e;                  /* '<S514>/Unit Delay' */
  real_T DigitalClock_oe;              /* '<S513>/Digital  Clock' */
  real_T UnitDelay1_nc;                /* '<S513>/Unit Delay1' */
  real_T Switch_dm;                    /* '<S513>/Switch' */
  real_T Integ4_ayi;                   /* '<S517>/Integ4' */
  real_T Freq_e;                       /* '<S517>/To avoid division  by zero' */
  real_T Numberofsamplespercycle_ao;   /* '<S517>/Number of samples per cycle' */
  real_T RoundingFunction_d;           /* '<S517>/Rounding Function' */
  real_T Delay_pz;                     /* '<S517>/Gain' */
  real_T SFunction_hy;                 /* '<S519>/S-Function' */
  real_T UnitDelay_dl;                 /* '<S518>/Unit Delay' */
  real_T DigitalClock_h5;              /* '<S517>/Digital  Clock' */
  real_T UnitDelay1_j;                 /* '<S517>/Unit Delay1' */
  real_T Switch_i3;                    /* '<S517>/Switch' */
  real_T ComplextoMagnitudeAngle_o1_cb;/* '<S508>/Complex to Magnitude-Angle' */
  real_T ComplextoMagnitudeAngle_o2_lx;/* '<S508>/Complex to Magnitude-Angle' */
  real_T Saturation_mf;                /* '<S503>/Saturation' */
  real_T MathFunction_g;               /* '<S503>/Math Function' */
  real_T RadDeg_o;                     /* '<S508>/Rad->Deg.' */
  real_T Sum1_in;                      /* '<S518>/Sum1' */
  real_T Sum5_n;                       /* '<S518>/Sum5' */
  real_T Product5_e;                   /* '<S518>/Product5' */
  real_T Gain1_i;                      /* '<S518>/Gain1' */
  real_T Sum4_k;                       /* '<S518>/Sum4' */
  real_T Product2_c;                   /* '<S518>/Product2' */
  real_T Product4_h;                   /* '<S518>/Product4' */
  real_T Sum7_a;                       /* '<S517>/Sum7' */
  real_T Meanvalue_jl;                 /* '<S517>/Product' */
  real_T Sum5_ob;                      /* '<S517>/Sum5' */
  real_T Sum1_ex;                      /* '<S514>/Sum1' */
  real_T Sum5_ll;                      /* '<S514>/Sum5' */
  real_T Product5_k;                   /* '<S514>/Product5' */
  real_T Gain1_lm;                     /* '<S514>/Gain1' */
  real_T Sum4_a;                       /* '<S514>/Sum4' */
  real_T Product2_nx;                  /* '<S514>/Product2' */
  real_T Product4_m;                   /* '<S514>/Product4' */
  real_T Sum7_j;                       /* '<S513>/Sum7' */
  real_T Meanvalue_ot;                 /* '<S513>/Product' */
  real_T Sum5_h;                       /* '<S513>/Sum5' */
  real_T Gain_h[2];                    /* '<S472>/Gain' */
  real_T Gain1_ab[2];                  /* '<S472>/Gain1' */
  real_T Correction_f[2];              /* '<S472>/Sum1' */
  real_T Sum7_fs[2];                   /* '<S472>/Sum7' */
  real_T Meanvalue_k[2];               /* '<S472>/Product' */
  real_T Sum5_ln[2];                   /* '<S472>/Sum5' */
  real_T qdc_cg;                       /* '<S460>/qd>c' */
  real_T qdb_k;                        /* '<S460>/qd>b' */
  real_T qda_c;                        /* '<S460>/qd>a' */
  real_T ProportionalGain_p;           /* '<S455>/Proportional Gain' */
  real_T Sum_jp;                       /* '<S455>/Sum' */
  real_T ProportionalGain_mw;          /* '<S454>/Proportional Gain' */
  real_T Sum_e;                        /* '<S454>/Sum' */
  real_T qdc_l;                        /* '<S464>/qd>c' */
  real_T qdb_l;                        /* '<S464>/qd>b' */
  real_T qda_cr;                       /* '<S464>/qd>a' */
  real_T Gain_b[3];                    /* '<S18>/Gain' */
  real_T Gain1_n[2];                   /* '<S420>/Gain1' */
  real_T Gain_mq[2];                   /* '<S420>/Gain' */
  real_T Correction_m[2];              /* '<S420>/Sum1' */
  real_T Sum7_it[2];                   /* '<S420>/Sum7' */
  real_T Meanvalue_op[2];              /* '<S420>/Product' */
  real_T Sum5_ex[2];                   /* '<S420>/Sum5' */
  real_T Gain1_op[2];                  /* '<S385>/Gain1' */
  real_T Gain_bd[2];                   /* '<S385>/Gain' */
  real_T Correction_ad[2];             /* '<S385>/Sum1' */
  real_T Sum7_ps[2];                   /* '<S385>/Sum7' */
  real_T Meanvalue_a[2];               /* '<S385>/Product' */
  real_T Sum5_d[2];                    /* '<S385>/Sum5' */
  real_T wbaseTs2[25];                 /* '<S302>/wbase*Ts//2 ' */
  real_T Product1_ic[5];               /* '<S294>/Product1' */
  real_T Switch1_h[25];                /* '<S283>/Switch1' */
  real_T Gain1_k;                      /* '<S291>/Gain1' */
  real_T W12wr[25];                    /* '<S291>/W(1,2)=wr' */
  real_T W21wr[25];                    /* '<S291>/W(2,1)=-wr' */
  real_T A[25];                        /* '<S283>/Sum1' */
  real_T wbaseTs[25];                  /* '<S302>/wbase*Ts' */
  real_T Sum1_l[25];                   /* '<S302>/Sum1' */
  real_T Product2_a5[5];               /* '<S294>/Product2' */
  real_T xk[5];                        /* '<S294>/Ad*x(k-1) + Bd*u(k-1) ' */
  real_T Ll_d[3];                      /* '<S299>/1//Ll_d' */
  real_T phimd_f;                      /* '<S299>/sum2' */
  real_T Lmd_sat;                      /* '<S295>/Lmd_sat' */
  real_T MathFunction2;                /* '<S298>/Math Function2' */
  real_T Sum1_p;                       /* '<S298>/Sum1' */
  real_T MathFunction3;                /* '<S298>/Math Function3' */
  real_T phimd_h;                      /* '<S299>/Product4' */
  real_T Phisat;                       /* '<S295>/Abs' */
  real_T Ifsatd;                       /* '<S295>/Lookup Table' */
  real_T Switch_cf;                    /* '<S295>/Switch' */
  real_T Lmsatd;                       /* '<S295>/Lmd' */
  real_T Switch1_n;                    /* '<S293>/Switch1' */
  real_T UpdateLmqrows156col156[25];   /* '<S297>/Update Lmq rows[1,5, (6)] col[1,5, (6)] ' */
  real_T UpdateLmdrows234col234[25];   /* '<S297>/Update Lmd rows[2,3,4] col[2,3,4]' */
  real_T Sum2_m[25];                   /* '<S297>/Sum2' */
  real_T Linv_d[25];                   /* '<S293>/inversion' */
  real_T RLinv[25];                    /* '<S293>/Product1' */
  real_T Ll_q[2];                      /* '<S301>/1//Ll_q' */
  real_T phimq_k;                      /* '<S301>/sum1' */
  real_T Lmq_sat;                      /* '<S296>/Lmq_sat' */
  real_T MathFunction_c;               /* '<S300>/Math Function' */
  real_T Sum2_o;                       /* '<S300>/Sum2' */
  real_T MathFunction1;                /* '<S300>/Math Function1' */
  real_T phimq_b;                      /* '<S301>/Product3' */
  real_T Phisat_i;                     /* '<S296>/Abs' */
  real_T Ifsatq;                       /* '<S296>/Lookup Table' */
  real_T Switch_lw;                    /* '<S296>/Switch' */
  real_T Lmsatq;                       /* '<S296>/Lmq' */
  real_T Product_i;                    /* '<S296>/Product' */
  real_T Product_oy;                   /* '<S295>/Product' */
  real_T Gen1Gov;                      /* '<S316>/Switch' */
  real_T Gen1AVR;                      /* '<S316>/Switch1' */
  real_T bias;                         /* '<S257>/Gain2' */
  real_T Add2_c;                       /* '<S257>/Add2' */
  real_T bias_m;                       /* '<S257>/Gain3' */
  real_T Add3_m;                       /* '<S257>/Add3' */
  real_T MultiportSwitch1_l[2];        /* '<S258>/Multiport Switch1' */
  real_T Switch2_a;                    /* '<S312>/Switch2' */
  real_T Add1_h;                       /* '<S312>/Add1' */
  real_T DataTypeConversion_au;        /* '<S245>/Data Type Conversion' */
  real_T DataTypeConversion_dy;        /* '<S240>/Data Type Conversion' */
  real_T DataTypeConversion_cf;        /* '<S235>/Data Type Conversion' */
  real_T DataTypeConversion_f;         /* '<S171>/Data Type Conversion' */
  real_T DataTypeConversion_of;        /* '<S166>/Data Type Conversion' */
  real_T DataTypeConversion_pw;        /* '<S161>/Data Type Conversion' */
  real_T DataTypeConversion_hi;        /* '<S97>/Data Type Conversion' */
  real_T DataTypeConversion_ck;        /* '<S92>/Data Type Conversion' */
  real_T DataTypeConversion_juh;       /* '<S87>/Data Type Conversion' */
  int8_T DataTypeConversion1_d1;       /* '<S20>/Data Type  Conversion1' */
  int8_T BitwiseOperator3;             /* '<S20>/Bitwise Operator3' */
  int8_T BitwiseOperator2;             /* '<S20>/Bitwise Operator2' */
  int8_T BitwiseOperator1;             /* '<S20>/Bitwise Operator1' */
  int8_T BitwiseOperator;              /* '<S20>/Bitwise Operator' */
  int8_T DataTypeConversion1_f;        /* '<S21>/Data Type  Conversion1' */
  int8_T BitwiseOperator3_i;           /* '<S21>/Bitwise Operator3' */
  int8_T BitwiseOperator2_h;           /* '<S21>/Bitwise Operator2' */
  int8_T BitwiseOperator1_g;           /* '<S21>/Bitwise Operator1' */
  int8_T BitwiseOperator_f;            /* '<S21>/Bitwise Operator' */
  uint8_T Compare;                     /* '<S742>/Compare' */
  uint8_T Uk1_i;                       /* '<S732>/Delay Input1' */
  uint8_T Compare_l;                   /* '<S581>/Compare' */
  uint8_T Compare_f;                   /* '<S582>/Compare' */
  uint8_T Compare_c;                   /* '<S648>/Compare' */
  uint8_T Compare_p;                   /* '<S649>/Compare' */
  uint8_T Compare_cv;                  /* '<S470>/Compare' */
  uint8_T Compare_pv;                  /* '<S471>/Compare' */
  uint8_T Compare_m;                   /* '<S537>/Compare' */
  uint8_T Compare_a;                   /* '<S538>/Compare' */
  uint8_T Switch_lq;                   /* '<S733>/Switch' */
  uint8_T FixPtRelationalOperator;     /* '<S747>/FixPt Relational Operator' */
  uint8_T FixPtRelationalOperator_m;   /* '<S746>/FixPt Relational Operator' */
  uint8_T Compare_k;                   /* '<S633>/Compare' */
  uint8_T Compare_o;                   /* '<S634>/Compare' */
  uint8_T Compare_n;                   /* '<S522>/Compare' */
  uint8_T Compare_h;                   /* '<S523>/Compare' */
  boolean_T LogicalOperator2;          /* '<S312>/Logical Operator2' */
  boolean_T UnitDelay_dw;              /* '<S19>/Unit Delay' */
  boolean_T UnitDelay_ec;              /* '<S18>/Unit Delay' */
  boolean_T DataTypeConversion_ny;     /* '<S20>/Data Type Conversion' */
  boolean_T Compare_md;                /* '<S677>/Compare' */
  boolean_T LogicalOperator4;          /* '<S20>/Logical Operator4' */
  boolean_T DataTypeConversion7;       /* '<S20>/Data Type  Conversion7' */
  boolean_T Compare_fd;                /* '<S681>/Compare' */
  boolean_T LogicalOperator1;          /* '<S20>/Logical Operator1' */
  boolean_T Compare_lt;                /* '<S680>/Compare' */
  boolean_T LogicalOperator2_l;        /* '<S20>/Logical Operator2' */
  boolean_T Compare_b;                 /* '<S679>/Compare' */
  boolean_T LogicalOperator3;          /* '<S20>/Logical Operator3' */
  boolean_T Compare_bm;                /* '<S678>/Compare' */
  boolean_T DataTypeConversion_n2;     /* '<S21>/Data Type Conversion' */
  boolean_T Compare_fb;                /* '<S706>/Compare' */
  boolean_T LogicalOperator4_k;        /* '<S21>/Logical Operator4' */
  boolean_T DataTypeConversion7_a;     /* '<S21>/Data Type  Conversion7' */
  boolean_T Compare_lo;                /* '<S710>/Compare' */
  boolean_T LogicalOperator1_a;        /* '<S21>/Logical Operator1' */
  boolean_T Compare_bl;                /* '<S709>/Compare' */
  boolean_T LogicalOperator2_o;        /* '<S21>/Logical Operator2' */
  boolean_T Compare_d;                 /* '<S708>/Compare' */
  boolean_T LogicalOperator3_o;        /* '<S21>/Logical Operator3' */
  boolean_T Compare_e;                 /* '<S707>/Compare' */
  boolean_T DataTypeConversion_cv;     /* '<S3>/Data Type Conversion' */
  boolean_T DataTypeConversion1_do;    /* '<S3>/Data Type Conversion1' */
  boolean_T Memory_o;                  /* '<S14>/Memory' */
  boolean_T Logic[2];                  /* '<S14>/Logic' */
  boolean_T Compare_fq;                /* '<S319>/Compare' */
  boolean_T Compare_lw;                /* '<S320>/Compare' */
  boolean_T Memory_k;                  /* '<S333>/Memory' */
  boolean_T Logic_i[2];                /* '<S333>/Logic' */
  boolean_T Compare_di;                /* '<S325>/Compare' */
  boolean_T RelationalOperator2;       /* '<S270>/Relational Operator2' */
  boolean_T RelationalOperator;        /* '<S270>/Relational Operator' */
  boolean_T RelationalOperator1;       /* '<S270>/Relational Operator1' */
  boolean_T LogicalOperator;           /* '<S270>/Logical Operator' */
  boolean_T LogicalOperator1_l;        /* '<S270>/Logical Operator1' */
  boolean_T LogicalOperator2_f;        /* '<S270>/Logical Operator2' */
  boolean_T Compare_ni;                /* '<S326>/Compare' */
  boolean_T Compare_kn;                /* '<S327>/Compare' */
  boolean_T Memory_g;                  /* '<S334>/Memory' */
  boolean_T Logic_l[2];                /* '<S334>/Logic' */
  boolean_T LogicalOperator_h;         /* '<S312>/Logical Operator' */
  boolean_T Compare_pj;                /* '<S330>/Compare' */
  boolean_T Compare_ms;                /* '<S331>/Compare' */
  boolean_T Memory_i;                  /* '<S336>/Memory' */
  boolean_T Logic_lx[2];               /* '<S336>/Logic' */
  boolean_T Compare_nn;                /* '<S332>/Compare' */
  boolean_T Compare_nd;                /* '<S321>/Compare' */
  boolean_T Compare_na;                /* '<S322>/Compare' */
  boolean_T Memory_n;                  /* '<S337>/Memory' */
  boolean_T Logic_b[2];                /* '<S337>/Logic' */
  boolean_T Compare_j;                 /* '<S323>/Compare' */
  boolean_T Compare_ff;                /* '<S324>/Compare' */
  boolean_T Compare_cm;                /* '<S328>/Compare' */
  boolean_T Compare_jk;                /* '<S329>/Compare' */
  boolean_T LogicalOperator1_m;        /* '<S312>/Logical Operator1' */
  boolean_T Memory_k0;                 /* '<S335>/Memory' */
  boolean_T Logic_g[2];                /* '<S335>/Logic' */
  boolean_T Memory_nj;                 /* '<S338>/Memory' */
  boolean_T Logic_il[2];               /* '<S338>/Logic' */
  boolean_T RelationalOperator_e;      /* '<S734>/Relational Operator' */
  boolean_T FixPtRelationalOperator_n; /* '<S732>/FixPt Relational Operator' */
  boolean_T UnitDelay_ju;              /* '<S732>/Unit Delay' */
  boolean_T DataTypeConversion3_h;     /* '<S732>/Data Type Conversion3' */
  boolean_T Memory_m;                  /* '<S743>/Memory' */
  boolean_T Logic_a[2];                /* '<S743>/Logic' */
  boolean_T MultiportSwitch5_m;        /* '<S732>/Multiport Switch5' */
  boolean_T Uk;                        /* '<S747>/compare' */
  boolean_T Uk1_g;                     /* '<S747>/Delay Input1' */
  boolean_T Uk_m;                      /* '<S746>/compare' */
  boolean_T Uk1_c;                     /* '<S746>/Delay Input1' */
  boolean_T DataTypeConversion1_e1;    /* '<S732>/Data Type Conversion1' */
  boolean_T RelationalOperator_ep;     /* '<S741>/Relational Operator' */
  boolean_T LogicalOperator2_e;        /* '<S741>/Logical Operator2' */
  boolean_T Memory1;                   /* '<S741>/Memory1' */
  boolean_T Memory_h;                  /* '<S744>/Memory' */
  boolean_T Logic_h[2];                /* '<S744>/Logic' */
  boolean_T RelationalOperator1_n;     /* '<S741>/Relational Operator1' */
  boolean_T LogicalOperator_p;         /* '<S741>/Logical Operator' */
  boolean_T DataTypeConversion_pws;    /* '<S741>/Data Type Conversion' */
  boolean_T LogicalOperator_l;         /* '<S732>/Logical Operator' */
  boolean_T DataTypeConversion4;       /* '<S731>/Data Type Conversion4' */
  boolean_T RelationalOperator_c;      /* '<S737>/Relational Operator' */
  boolean_T delay;                     /* '<S739>/delay' */
  boolean_T LogicalOperator2_m;        /* '<S739>/Logical Operator2' */
  boolean_T Pulse_Phi_POW_cross;       /* '<S735>/Hit  Crossing' */
  boolean_T DataTypeConversion3_b;     /* '<S735>/Data Type Conversion3' */
  boolean_T RelationalOperator_o;      /* '<S738>/Relational Operator' */
  boolean_T Time_GoE_Tstart;           /* '<S735>/t_GoE_Tstart' */
  boolean_T Uk1_cz;                    /* '<S735>/Delay Input1' */
  boolean_T FixPtRelationalOperator_k; /* '<S735>/FixPt Relational Operator' */
  boolean_T DelayInput2;               /* '<S735>/Delay Input2' */
  boolean_T Memory_b;                  /* '<S740>/Memory' */
  boolean_T Logic_hj[2];               /* '<S740>/Logic' */
  boolean_T LogicalOperator1_c;        /* '<S735>/Logical Operator1' */
  boolean_T FixPtRelationalOperator_kg;/* '<S739>/FixPt Relational Operator' */
  boolean_T LogicalOperator1_g;        /* '<S739>/Logical Operator1' */
  boolean_T RelationalOperator_d;      /* '<S739>/Relational Operator' */
  boolean_T LogicalOperator2_j;        /* '<S731>/Logical Operator2' */
  boolean_T Memory_f;                  /* '<S731>/Memory' */
  boolean_T LogicalOperator3_g;        /* '<S731>/Logical Operator3' */
  boolean_T Memory_p;                  /* '<S736>/Memory' */
  boolean_T Logic_k[2];                /* '<S736>/Logic' */
  boolean_T LogicalOperator1_d;        /* '<S731>/Logical Operator1' */
  boolean_T LogicalOperator1_n;        /* '<S741>/Logical Operator1' */
  boolean_T FixPtUnitDelay1_d;         /* '<S586>/FixPt Unit Delay1' */
  boolean_T Compare_l4;                /* '<S584>/Compare' */
  boolean_T LogicalOperator1_al;       /* '<S576>/Logical Operator1' */
  boolean_T Xnew_l;                    /* '<S586>/Enable' */
  boolean_T RelationalOperator_b;      /* '<S643>/Relational Operator' */
  boolean_T DataTypeConversion_pg;     /* '<S570>/Data Type Conversion' */
  boolean_T LogicalOperator_e;         /* '<S570>/Logical Operator' */
  boolean_T RelationalOperator_g[3];   /* '<S19>/Relational Operator' */
  boolean_T RelationalOperator1_d[3];  /* '<S19>/Relational Operator1' */
  boolean_T disableifTRUE[3];          /* '<S19>/disable if TRUE' */
  boolean_T disableifTRUE1;            /* '<S19>/disable if TRUE1' */
  boolean_T FixPtUnitDelay1_do;        /* '<S475>/FixPt Unit Delay1' */
  boolean_T Compare_i;                 /* '<S473>/Compare' */
  boolean_T LogicalOperator1_cr;       /* '<S465>/Logical Operator1' */
  boolean_T Xnew_o;                    /* '<S475>/Enable' */
  boolean_T RelationalOperator_j;      /* '<S532>/Relational Operator' */
  boolean_T DataTypeConversion_ik;     /* '<S459>/Data Type Conversion' */
  boolean_T LogicalOperator_pf;        /* '<S459>/Logical Operator' */
  boolean_T RelationalOperator_cn[3];  /* '<S18>/Relational Operator' */
  boolean_T RelationalOperator1_k[3];  /* '<S18>/Relational Operator1' */
  boolean_T disableifTRUE_l[3];        /* '<S18>/disable if TRUE' */
  boolean_T disableifTRUE1_l;          /* '<S18>/disable if TRUE1' */
  boolean_T RelationalOperator_cx;     /* '<S665>/Relational Operator' */
  boolean_T RelationalOperator_n;      /* '<S661>/Relational Operator' */
  boolean_T RelationalOperator_a;      /* '<S658>/Relational Operator' */
  boolean_T RelationalOperator_f;      /* '<S624>/Relational Operator' */
  boolean_T RelationalOperator_fm;     /* '<S628>/Relational Operator' */
  boolean_T RelationalOperator_e1;     /* '<S554>/Relational Operator' */
  boolean_T RelationalOperator_bb;     /* '<S550>/Relational Operator' */
  boolean_T RelationalOperator_nz;     /* '<S547>/Relational Operator' */
  boolean_T RelationalOperator_be;     /* '<S513>/Relational Operator' */
  boolean_T RelationalOperator_ju;     /* '<S517>/Relational Operator' */
  B_Subsystem1_sel751test_model_T Subsystem1;/* '<S646>/Subsystem1' */
  B_Subsystempi2delay_sel751tes_T Subsystempi2delay;/* '<S646>/Subsystem - pi//2 delay' */
  B_Subsystem1_sel751test_model_T Subsystem1_e;/* '<S631>/Subsystem1' */
  B_Subsystempi2delay_sel751tes_T Subsystempi2delay_kg;/* '<S631>/Subsystem - pi//2 delay' */
  B_Subsystem1_sel751test_model_T Subsystem1_d;/* '<S535>/Subsystem1' */
  B_Subsystempi2delay_sel751tes_T Subsystempi2delay_k;/* '<S535>/Subsystem - pi//2 delay' */
  B_Subsystem1_sel751test_model_T Subsystem1_o;/* '<S520>/Subsystem1' */
  B_Subsystempi2delay_sel751tes_T Subsystempi2delay_e;/* '<S520>/Subsystem - pi//2 delay' */
  B_delay_sel751test_model_1_1__T sf_delay_i;/* '<S10>/delay' */
  B_delay_sel751test_model_1_1__T sf_delay_f;/* '<S9>/delay' */
  B_delay_sel751test_model_1_1__T sf_delay;/* '<S8>/delay' */
} B_sel751test_model_1_1_sm_system_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T BreakAlgebraicLoop_DSTATE;    /* '<S274>/Break Algebraic Loop' */
  real_T PmIntegrator_DSTATE;          /* '<S275>/Pm- Integrator' */
  real_T GeneratedFilterBlock_states[14];/* '<S340>/Generated Filter Block' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S303>/Discrete-Time Integrator1' */
  real_T fluxes_DSTATE[5];             /* '<S294>/fluxes' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S303>/Discrete-Time Integrator' */
  real_T voltages_DSTATE[5];           /* '<S294>/voltages' */
  real_T Integrator_DSTATE;            /* '<S565>/Integrator' */
  real_T Filter_DSTATE;                /* '<S565>/Filter' */
  real_T Integrator_DSTATE_i;          /* '<S566>/Integrator' */
  real_T Filter_DSTATE_p;              /* '<S566>/Filter' */
  real_T DiscreteTimeIntegrator_DSTATE_h;/* '<S613>/Discrete-Time Integrator' */
  real_T Integrator_DSTATE_o;          /* '<S454>/Integrator' */
  real_T Filter_DSTATE_l;              /* '<S454>/Filter' */
  real_T Integrator_DSTATE_ob;         /* '<S455>/Integrator' */
  real_T Filter_DSTATE_p5;             /* '<S455>/Filter' */
  real_T DiscreteTimeIntegrator_DSTAT_hc;/* '<S502>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE;             /* '<S22>/Unit Delay' */
  real_T Delay_DSTATE[1000];           /* '<S8>/Delay' */
  real_T Delay_DSTATE_a[1000];         /* '<S9>/Delay' */
  real_T Delay_DSTATE_i[1000];         /* '<S10>/Delay' */
  real_T SSNVersion19SSNFileNamesel751te[24];/* '<S771>/State-Space' */
  real_T StateSpace_xn_g1[15];         /* '<S771>/State-Space' */
  real_T SSNVersion19SSNFileNamesel751_h[21];/* '<S771>/State-Space' */
  real_T SSNVersion19SSNFileNamesel75_hg[13];/* '<S771>/State-Space' */
  real_T SSNVersion19SSNFileNamesel7_hgh[10];/* '<S771>/State-Space' */
  real_T SSNVersion19SSNFileNamesel_hgha[7];/* '<S771>/State-Space' */
  real_T SSNVersion19SSNFileNamese_hghah[10];/* '<S771>/State-Space' */
  real_T SSNVersion19SSNFileNames_hghahz[7];/* '<S771>/State-Space' */
  real_T SSNVersion19SSNFileName_hghahzd[10];/* '<S771>/State-Space' */
  real_T SSNVersion19SSNFileNam_hghahzd0[7];/* '<S771>/State-Space' */
  real_T SSNVersion19SSNFileNa_hghahzd0h[10];/* '<S771>/State-Space' */
  real_T SSNVersion19SSNFileN_hghahzd0hp[7];/* '<S771>/State-Space' */
  real_T SSNVersion19SSNFile_hghahzd0hp3[6];/* '<S771>/State-Space' */
  real_T SSNVersion19SSNFil_hghahzd0hp3w[6];/* '<S771>/State-Space' */
  real_T SSNVersion19SSNFi_hghahzd0hp3wu[54];/* '<S771>/State-Space' */
  real_T SSNVersion19SSNF_hghahzd0hp3wu2[37];/* '<S771>/State-Space' */
  real_T SSNVersion19SSN_hghahzd0hp3wu2e[54];/* '<S771>/State-Space' */
  real_T SSNVersion19SSN_b[37];        /* '<S771>/State-Space' */
  real_T SSNVersion19SSN_a;            /* '<S771>/State-Space' */
  real_T SSNVersion19SSN_e;            /* '<S771>/State-Space' */
  real_T Integrator_DSTATE_b;          /* '<S306>/Integrator' */
  real_T Filter_DSTATE_k;              /* '<S306>/Filter' */
  real_T Integrator_DSTATE_c;          /* '<S307>/Integrator' */
  real_T Filter_DSTATE_j;              /* '<S307>/Filter' */
  real_T Integrator_DSTATE_k;          /* '<S308>/Integrator' */
  real_T Filter_DSTATE_a;              /* '<S308>/Filter' */
  real_T DiscreteTimeIntegrator2_DSTATE;/* '<S303>/Discrete-Time Integrator2' */
  real_T Integrator_DSTATE_ch;         /* '<S276>/Integrator' */
  real_T fIntegrator_DSTATE;           /* '<S275>/f- Integrator ' */
  real_T VariableIntegerDelay_DSTATE[100];/* '<S274>/Variable Integer Delay' */
  real_T UnitDelay2_DSTATE;            /* '<S263>/Unit Delay2' */
  real_T Integrator_DSTATE_p;          /* '<S262>/Integrator' */
  real_T Filter_DSTATE_d;              /* '<S262>/Filter' */
  real_T GeneratedFilterBlock_states_n[14];/* '<S341>/Generated Filter Block' */
  real_T LoadThermalMass50degMBTU_DSTATE;/* '<S249>/Load  Thermal  Mass 50 deg//MBTU' */
  real_T RemoveAlgebraicLoop1_DSTATE;  /* '<S249>/Remove Algebraic Loop1' */
  real_T RemoveAlgebraicLoop_DSTATE;   /* '<S249>/Remove Algebraic Loop' */
  real_T Filter_DSTATE_jk;             /* '<S251>/Filter' */
  real_T Integrator_DSTATE_d;          /* '<S251>/Integrator' */
  real_T DiscreteStateSpace_DSTATE;    /* '<S268>/Discrete State-Space' */
  real_T UnitDelay1_DSTATE;            /* '<S263>/Unit Delay1' */
  real_T DiscreteStateSpace_DSTATE_o;  /* '<S267>/Discrete State-Space' */
  real_T DiscreteStateSpace_DSTATE_d;  /* '<S273>/Discrete State-Space' */
  real_T DiscreteStateSpace_DSTATE_c;  /* '<S272>/Discrete State-Space' */
  real_T DiscreteStateSpace_DSTATE_j;  /* '<S271>/Discrete State-Space' */
  real_T Initialspeed400RPM_DSTATE;    /* '<S274>/Initial speed 400 RPM' */
  real_T Integ4_DSTATE[2];             /* '<S385>/Integ4' */
  real_T UnitDelay_DSTATE_e[2];        /* '<S385>/Unit Delay' */
  real_T DiscreteTimeIntegrtor_DSTATE; /* '<S734>/Discrete-Time Integrtor' */
  real_T DiscreteTimeIntegrator_DSTATE_f;/* '<S745>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTAT_b;/* '<S741>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrtor_DSTATE_d;/* '<S737>/Discrete-Time Integrtor' */
  real_T DiscreteTimeIntegrator_DSTATE_l;/* '<S741>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrtor_DSTATE_n;/* '<S738>/Discrete-Time Integrtor' */
  real_T DelayInput1_DSTATE;           /* '<S739>/Delay Input1' */
  real_T UnitDelay_DSTATE_n;           /* '<S739>/Unit Delay' */
  real_T Integ4_DSTATE_e;              /* '<S752>/Integ4' */
  real_T UnitDelay_DSTATE_p;           /* '<S745>/Unit Delay' */
  real_T UnitDelay_DSTATE_h;           /* '<S762>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTAT_f5;/* '<S750>/Discrete-Time Integrator' */
  real_T UD_DSTATE;                    /* '<S761>/UD' */
  real_T UnitDelay_DSTATE_d;           /* '<S751>/Unit  Delay' */
  real_T DiscreteStateSpace_DSTATE_cp[2];/* '<S748>/Discrete State-Space' */
  real_T Integ4_DSTATE_h[2];           /* '<S583>/Integ4' */
  real_T UnitDelay_DSTATE_nq[2];       /* '<S583>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE;       /* '<S585>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_pb;          /* '<S613>/Unit Delay' */
  real_T Integ4_DSTATE_n;              /* '<S643>/Integ4' */
  real_T UnitDelay_DSTATE_do;          /* '<S644>/Unit Delay' */
  real_T UnitDelay1_DSTATE_o;          /* '<S643>/Unit Delay1' */
  real_T DiscreteDerivative_states;    /* '<S615>/Discrete Derivative ' */
  real_T DiscreteTimeIntegrator_DSTATE_d;/* '<S615>/Discrete-Time Integrator' */
  real_T Delay_x1_DSTATE;              /* '<S638>/Delay_x1' */
  real_T Delay_x2_DSTATE;              /* '<S638>/Delay_x2' */
  real_T Integ4_DSTATE_a[2];           /* '<S472>/Integ4' */
  real_T UnitDelay_DSTATE_pp[2];       /* '<S472>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_c;     /* '<S474>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_f;           /* '<S502>/Unit Delay' */
  real_T Integ4_DSTATE_c;              /* '<S532>/Integ4' */
  real_T UnitDelay_DSTATE_c;           /* '<S533>/Unit Delay' */
  real_T UnitDelay1_DSTATE_j;          /* '<S532>/Unit Delay1' */
  real_T DiscreteDerivative_states_p;  /* '<S504>/Discrete Derivative ' */
  real_T DiscreteTimeIntegrator_DSTAT_ls;/* '<S504>/Discrete-Time Integrator' */
  real_T Delay_x1_DSTATE_n;            /* '<S527>/Delay_x1' */
  real_T Delay_x2_DSTATE_o;            /* '<S527>/Delay_x2' */
  real_T Integ4_DSTATE_f[2];           /* '<S420>/Integ4' */
  real_T UnitDelay_DSTATE_db[2];       /* '<S420>/Unit Delay' */
  real_T Integ4_DSTATE_k;              /* '<S755>/Integ4' */
  real_T UnitDelay_DSTATE_e0;          /* '<S757>/Unit Delay' */
  real_T Integ4_DSTATE_ex;             /* '<S756>/Integ4' */
  real_T UnitDelay_DSTATE_o;           /* '<S759>/Unit Delay' */
  real_T Integ4_DSTATE_fr[3];          /* '<S665>/Integ4' */
  real_T UnitDelay_DSTATE_g[3];        /* '<S665>/Unit Delay' */
  real_T UnitDelay1_DSTATE_d[3];       /* '<S665>/Unit Delay1' */
  real_T Integ4_DSTATE_cv[3];          /* '<S661>/Integ4' */
  real_T UnitDelay_DSTATE_en[3];       /* '<S661>/Unit Delay' */
  real_T UnitDelay1_DSTATE_dv[3];      /* '<S661>/Unit Delay1' */
  real_T Integ4_DSTATE_hm[3];          /* '<S658>/Integ4' */
  real_T UnitDelay_DSTATE_pn[3];       /* '<S658>/Unit Delay' */
  real_T UnitDelay1_DSTATE_i[3];       /* '<S658>/Unit Delay1' */
  real_T Integ4_DSTATE_aa;             /* '<S624>/Integ4' */
  real_T UnitDelay_DSTATE_a;           /* '<S625>/Unit Delay' */
  real_T UnitDelay1_DSTATE_jp;         /* '<S624>/Unit Delay1' */
  real_T Integ4_DSTATE_o;              /* '<S628>/Integ4' */
  real_T UnitDelay_DSTATE_gi;          /* '<S629>/Unit Delay' */
  real_T UnitDelay1_DSTATE_b;          /* '<S628>/Unit Delay1' */
  real_T Integ4_DSTATE_cg[3];          /* '<S554>/Integ4' */
  real_T UnitDelay_DSTATE_ez[3];       /* '<S554>/Unit Delay' */
  real_T UnitDelay1_DSTATE_c[3];       /* '<S554>/Unit Delay1' */
  real_T Integ4_DSTATE_eh[3];          /* '<S550>/Integ4' */
  real_T UnitDelay_DSTATE_l[3];        /* '<S550>/Unit Delay' */
  real_T UnitDelay1_DSTATE_dh[3];      /* '<S550>/Unit Delay1' */
  real_T Integ4_DSTATE_j[3];           /* '<S547>/Integ4' */
  real_T UnitDelay_DSTATE_l4[3];       /* '<S547>/Unit Delay' */
  real_T UnitDelay1_DSTATE_a[3];       /* '<S547>/Unit Delay1' */
  real_T Integ4_DSTATE_ha;             /* '<S513>/Integ4' */
  real_T UnitDelay_DSTATE_n2;          /* '<S514>/Unit Delay' */
  real_T UnitDelay1_DSTATE_e;          /* '<S513>/Unit Delay1' */
  real_T Integ4_DSTATE_ab;             /* '<S517>/Integ4' */
  real_T UnitDelay_DSTATE_j;           /* '<S518>/Unit Delay' */
  real_T UnitDelay1_DSTATE_i1;         /* '<S517>/Unit Delay1' */
  real_T Lmd_sat_DSTATE;               /* '<S295>/Lmd_sat' */
  real_T Lmq_sat_DSTATE;               /* '<S296>/Lmq_sat' */
  real_T SFunction_PreviousInput;      /* '<S2>/S-Function' */
  real_T Memory5_PreviousInput;        /* '<S8>/Memory5' */
  real_T Memory1_PreviousInput[3];     /* '<S8>/Memory1' */
  real_T Memory2_PreviousInput[3];     /* '<S8>/Memory2' */
  real_T Memory3_PreviousInput[3];     /* '<S8>/Memory3' */
  real_T Memory5_PreviousInput_o;      /* '<S9>/Memory5' */
  real_T Memory1_PreviousInput_h[3];   /* '<S9>/Memory1' */
  real_T Memory2_PreviousInput_k[3];   /* '<S9>/Memory2' */
  real_T Memory3_PreviousInput_m[3];   /* '<S9>/Memory3' */
  real_T Memory5_1_PreviousInput;      /* '<S16>/Memory5' */
  real_T Memory5_2_PreviousInput;      /* '<S16>/Memory5' */
  real_T Memory5_3_PreviousInput;      /* '<S16>/Memory5' */
  real_T Memory1_PreviousInput_ha;     /* '<S567>/Memory1' */
  real_T Memory2_PreviousInput_b;      /* '<S567>/Memory2' */
  real_T Memory1_PreviousInput_i;      /* '<S456>/Memory1' */
  real_T Memory2_PreviousInput_o;      /* '<S456>/Memory2' */
  real_T lastSin;                      /* '<S248>/Sine Wave A' */
  real_T lastCos;                      /* '<S248>/Sine Wave A' */
  real_T lastSin_g;                    /* '<S248>/Sine Wave B' */
  real_T lastCos_p;                    /* '<S248>/Sine Wave B' */
  real_T lastSin_h;                    /* '<S248>/Sine Wave C' */
  real_T lastCos_o;                    /* '<S248>/Sine Wave C' */
  real_T PrevY;                        /* '<S252>/Rate Limiter' */
  real_T PrevY_o;                      /* '<S252>/Rate Limiter1' */
  real_T Memory5_PreviousInput_n;      /* '<S10>/Memory5' */
  real_T Memory1_PreviousInput_p[3];   /* '<S10>/Memory1' */
  real_T Memory2_PreviousInput_a[3];   /* '<S10>/Memory2' */
  real_T Memory3_PreviousInput_n[3];   /* '<S10>/Memory3' */
  real_T Memory_PreviousInput;         /* '<S734>/Memory' */
  real_T Memory_PreviousInput_g;       /* '<S741>/Memory' */
  real_T Memory_PreviousInput_k;       /* '<S737>/Memory' */
  real_T Memory_PreviousInput_b;       /* '<S738>/Memory' */
  real_T Memory3_PreviousInput_l;      /* '<S567>/Memory3' */
  real_T Memory4_PreviousInput;        /* '<S567>/Memory4' */
  real_T Memory5_PreviousInput_l;      /* '<S567>/Memory5' */
  real_T Memory6_PreviousInput[3];     /* '<S567>/Memory6' */
  real_T DiscreteDerivative_tmp;       /* '<S615>/Discrete Derivative ' */
  real_T PrevY_f;                      /* '<S613>/Rate Limiter' */
  real_T Memory3_PreviousInput_j;      /* '<S456>/Memory3' */
  real_T Memory4_PreviousInput_j;      /* '<S456>/Memory4' */
  real_T Memory5_PreviousInput_b;      /* '<S456>/Memory5' */
  real_T Memory6_PreviousInput_d[3];   /* '<S456>/Memory6' */
  real_T DiscreteDerivative_tmp_j;     /* '<S504>/Discrete Derivative ' */
  real_T PrevY_b;                      /* '<S502>/Rate Limiter' */
  real_T Memory5_1_PreviousInput_i;    /* '<S17>/Memory5' */
  real_T Memory5_2_PreviousInput_p;    /* '<S17>/Memory5' */
  real_T Memory5_3_PreviousInput_h;    /* '<S17>/Memory5' */
  real_T lastSin_a;                    /* '<S654>/sin(wt)' */
  real_T lastCos_d;                    /* '<S654>/sin(wt)' */
  real_T lastSin_e;                    /* '<S654>/cos(wt)' */
  real_T lastCos_h;                    /* '<S654>/cos(wt)' */
  real_T lastSin_d;                    /* '<S543>/sin(wt)' */
  real_T lastCos_ov;                   /* '<S543>/sin(wt)' */
  real_T lastSin_n;                    /* '<S543>/cos(wt)' */
  real_T lastCos_j;                    /* '<S543>/cos(wt)' */
  real_T inversion_DWORK1[25];         /* '<S293>/inversion' */
  real_T inversion_DWORK3[25];         /* '<S293>/inversion' */
  real_T inversion_DWORK4[25];         /* '<S293>/inversion' */
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK;                  /* '<S684>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_h;                /* '<S689>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_b;                /* '<S694>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_g;                /* '<S699>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_hs;               /* '<S713>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_f;                /* '<S718>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_p;                /* '<S723>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_b3;               /* '<S728>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_b0;               /* '<S85>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_l;                /* '<S90>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_j;                /* '<S95>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_m;                /* '<S159>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_n;                /* '<S164>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_pj;               /* '<S169>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_m2;               /* '<S233>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_a;                /* '<S238>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_m4;               /* '<S243>/Derivative' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[2048];
  } PipingTransportDelay1_RWORK;       /* '<S249>/Piping Transport Delay1' */

  real_T RTEConversion_RWORK;          /* '<S309>/RTE Conversion' */
  real_T RTEConversion_RWORK_p;        /* '<S310>/RTE Conversion' */
  real_T SFunction_RWORK;              /* '<S645>/S-Function' */
  real_T SFunction_RWORK_p;            /* '<S534>/S-Function' */
  real_T SFunction_RWORK_o;            /* '<S666>/S-Function' */
  real_T SFunction_RWORK_b;            /* '<S662>/S-Function' */
  real_T SFunction_RWORK_i;            /* '<S659>/S-Function' */
  real_T SFunction_RWORK_e;            /* '<S626>/S-Function' */
  real_T SFunction_RWORK_id;           /* '<S630>/S-Function' */
  real_T SFunction_RWORK_f;            /* '<S555>/S-Function' */
  real_T SFunction_RWORK_a;            /* '<S551>/S-Function' */
  real_T SFunction_RWORK_l;            /* '<S548>/S-Function' */
  real_T SFunction_RWORK_fz;           /* '<S515>/S-Function' */
  real_T SFunction_RWORK_g;            /* '<S519>/S-Function' */
  void *DigitalIn_PWORK;               /* '<S311>/DigitalIn' */
  void *EventDetector_PWORK;           /* '<S315>/EventDetector' */
  void *EventDetector1_PWORK;          /* '<S315>/EventDetector1' */
  void *PWMIn_PWORK;                   /* '<S314>/PWM In' */
  void *PWMIn1_PWORK;                  /* '<S314>/PWM In1' */
  void *AnalogIn_PWORK;                /* '<S339>/AnalogIn' */
  void *DigitalInfromSEL751_PWORK;     /* '<S3>/DigitalIn from SEL-751' */
  void *SFunction_PWORK;               /* '<S768>/S-Function' */
  void *StateSpace_PWORK;              /* '<S771>/State-Space' */
  void *AnalogOut2toSEL751_PWORK;      /* '<S3>/AnalogOut2 to SEL-751' */
  void *DigitalOuttoSEL751_PWORK;      /* '<S3>/DigitalOut to SEL-751' */
  struct {
    void *TUbufferPtrs[2];
  } PipingTransportDelay1_PWORK;       /* '<S249>/Piping Transport Delay1' */

  void *OpFromFile_PWORK;              /* '<S3>/OpFromFile' */
  void *AnalogOut_PWORK;               /* '<S253>/AnalogOut' */
  void *RTESPWM_PWORK;                 /* '<S309>/RTE SPWM' */
  void *RTEConversion_PWORK;           /* '<S309>/RTE Conversion' */
  void *RTESPWM_PWORK_l;               /* '<S310>/RTE SPWM' */
  void *RTEConversion_PWORK_f;         /* '<S310>/RTE Conversion' */
  void *AnalogOut1_PWORK;              /* '<S253>/AnalogOut1' */
  void *AnalogOut2_PWORK;              /* '<S253>/AnalogOut2' */
  struct {
    void *LoggedData;
  } PmechanicalkW_PWORK;               /* '<S264>/Pmechanical kW' */

  struct {
    void *LoggedData;
  } f_PWORK;                           /* '<S274>/f' */

  void *OpCtrl_PWORK;                  /* '<S254>/OpCtrl' */
  void *DigitalOut_PWORK;              /* '<S311>/DigitalOut' */
  void *PWMOut_PWORK;                  /* '<S314>/PWM Out' */
  void *PWMOut1_PWORK;                 /* '<S314>/PWM Out1' */
  void *EventGenerator_PWORK;          /* '<S315>/EventGenerator' */
  void *EventGenerator1_PWORK;         /* '<S315>/EventGenerator1' */
  void *AnalogIn1_PWORK;               /* '<S339>/AnalogIn1' */
  void *DataInSend_PWORK;              /* '<S313>/DataIn Send' */
  void *DataInSend1_PWORK;             /* '<S313>/DataIn Send1' */
  struct {
    void *uBuffers[2];
  } SFunction_PWORK_o;                 /* '<S386>/S-Function ' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S735>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S735>/Scope1' */

  struct {
    void *uBuffers;
  } SFunction_PWORK_k;                 /* '<S763>/S-Function ' */

  struct {
    void *uBuffers[2];
  } SFunction_PWORK_b;                 /* '<S587>/S-Function ' */

  void *SFunction_PWORK_l;             /* '<S645>/S-Function' */
  struct {
    void *uBuffers[2];
  } SFunction_PWORK_oi;                /* '<S476>/S-Function ' */

  void *SFunction_PWORK_f;             /* '<S534>/S-Function' */
  void *OpFromFile1_PWORK;             /* '<S3>/OpFromFile1' */
  struct {
    void *uBuffers[2];
  } SFunction_PWORK_f4;                /* '<S421>/S-Function ' */

  struct {
    void *uBuffers;
  } SFunction_PWORK_e;                 /* '<S758>/S-Function ' */

  struct {
    void *uBuffers;
  } SFunction_PWORK_fm;                /* '<S760>/S-Function ' */

  void *SFunction_PWORK_j[3];          /* '<S666>/S-Function' */
  void *SFunction_PWORK_p[3];          /* '<S662>/S-Function' */
  void *SFunction_PWORK_lq[3];         /* '<S659>/S-Function' */
  void *SFunction_PWORK_jz;            /* '<S626>/S-Function' */
  void *SFunction_PWORK_n;             /* '<S630>/S-Function' */
  void *SFunction_PWORK_ob[3];         /* '<S555>/S-Function' */
  void *SFunction_PWORK_m[3];          /* '<S551>/S-Function' */
  void *SFunction_PWORK_km[3];         /* '<S548>/S-Function' */
  void *SFunction_PWORK_h;             /* '<S515>/S-Function' */
  void *SFunction_PWORK_i;             /* '<S519>/S-Function' */
  int32_T GeneratedFilterBlock_circBuf;/* '<S340>/Generated Filter Block' */
  int32_T GeneratedFilterBlock_circBuf_i;/* '<S341>/Generated Filter Block' */
  int32_T systemEnable;                /* '<S248>/Sine Wave A' */
  int32_T systemEnable_m;              /* '<S248>/Sine Wave B' */
  int32_T systemEnable_o;              /* '<S248>/Sine Wave C' */
  int32_T systemEnable_c;              /* '<S654>/sin(wt)' */
  int32_T systemEnable_d;              /* '<S654>/cos(wt)' */
  int32_T systemEnable_h;              /* '<S543>/sin(wt)' */
  int32_T systemEnable_mi;             /* '<S543>/cos(wt)' */
  int32_T inversion_DWORK2[5];         /* '<S293>/inversion' */
  int_T SFunction_IWORK[5];            /* '<S766>/S-Function' */
  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } PipingTransportDelay1_IWORK;       /* '<S249>/Piping Transport Delay1' */

  int_T OpCtrl_IWORK;                  /* '<S254>/OpCtrl' */
  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_h;                 /* '<S386>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_e;                 /* '<S763>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_p;                 /* '<S587>/S-Function ' */

  int_T SFunction_IWORK_c;             /* '<S645>/S-Function' */
  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_l;                 /* '<S476>/S-Function ' */

  int_T SFunction_IWORK_n;             /* '<S534>/S-Function' */
  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_j;                 /* '<S421>/S-Function ' */

  int_T SFunction_IWORK_o[5];          /* '<S767>/S-Function' */
  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_or;                /* '<S758>/S-Function ' */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_f;                 /* '<S760>/S-Function ' */

  int_T SFunction_IWORK_i[3];          /* '<S666>/S-Function' */
  int_T SFunction_IWORK_nj[3];         /* '<S662>/S-Function' */
  int_T SFunction_IWORK_lh[3];         /* '<S659>/S-Function' */
  int_T SFunction_IWORK_k;             /* '<S626>/S-Function' */
  int_T SFunction_IWORK_o4;            /* '<S630>/S-Function' */
  int_T SFunction_IWORK_kp[3];         /* '<S555>/S-Function' */
  int_T SFunction_IWORK_cd[3];         /* '<S551>/S-Function' */
  int_T SFunction_IWORK_hs[3];         /* '<S548>/S-Function' */
  int_T SFunction_IWORK_jx;            /* '<S515>/S-Function' */
  int_T SFunction_IWORK_jp;            /* '<S519>/S-Function' */
  int_T HitCrossing_MODE;              /* '<S735>/Hit  Crossing' */
  uint8_T DelayInput1_DSTATE_o;        /* '<S732>/Delay Input1' */
  boolean_T UnitDelay_DSTATE_cg;       /* '<S19>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_na;       /* '<S18>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_m;        /* '<S732>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_d;      /* '<S747>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_l;      /* '<S746>/Delay Input1' */
  boolean_T delay_DSTATE;              /* '<S739>/delay' */
  boolean_T DelayInput1_DSTATE_ot;     /* '<S735>/Delay Input1' */
  boolean_T DelayInput2_DSTATE;        /* '<S735>/Delay Input2' */
  boolean_T FixPtUnitDelay1_DSTATE_k;  /* '<S586>/FixPt Unit Delay1' */
  boolean_T FixPtUnitDelay1_DSTATE_g;  /* '<S475>/FixPt Unit Delay1' */
  int8_T PmIntegrator_PrevResetState;  /* '<S275>/Pm- Integrator' */
  int8_T Integrator_PrevResetState;    /* '<S565>/Integrator' */
  int8_T Filter_PrevResetState;        /* '<S565>/Filter' */
  int8_T Integrator_PrevResetState_h;  /* '<S566>/Integrator' */
  int8_T Filter_PrevResetState_n;      /* '<S566>/Filter' */
  int8_T Integrator_PrevResetState_m;  /* '<S454>/Integrator' */
  int8_T Filter_PrevResetState_i;      /* '<S454>/Filter' */
  int8_T Integrator_PrevResetState_g;  /* '<S455>/Integrator' */
  int8_T Filter_PrevResetState_g;      /* '<S455>/Filter' */
  int8_T Integrator_PrevResetState_i;  /* '<S276>/Integrator' */
  int8_T fIntegrator_PrevResetState;   /* '<S275>/f- Integrator ' */
  int8_T Integrator_PrevResetState_hf; /* '<S262>/Integrator' */
  int8_T Filter_PrevResetState_nr;     /* '<S262>/Filter' */
  int8_T LoadThermalMass50degMBTU_PrevRe;/* '<S249>/Load  Thermal  Mass 50 deg//MBTU' */
  int8_T DiscreteTimeIntegrtor_PrevReset;/* '<S734>/Discrete-Time Integrtor' */
  int8_T DiscreteTimeIntegrtor_PrevRes_n;/* '<S737>/Discrete-Time Integrtor' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S741>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrtor_PrevRes_d;/* '<S738>/Discrete-Time Integrtor' */
  uint8_T icLoad;                      /* '<S8>/Delay' */
  uint8_T icLoad_i;                    /* '<S9>/Delay' */
  uint8_T icLoad_b;                    /* '<S10>/Delay' */
  uint8_T Integ4_SYSTEM_ENABLE;        /* '<S385>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_a;      /* '<S752>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_at;     /* '<S583>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_l;      /* '<S643>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_h;      /* '<S472>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_k;      /* '<S532>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_f;      /* '<S420>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_ak;     /* '<S755>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_n;      /* '<S756>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_k3;     /* '<S665>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_lc;     /* '<S661>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_fu;     /* '<S658>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_fn;     /* '<S624>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_o;      /* '<S628>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_p;      /* '<S554>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_m;      /* '<S550>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_j;      /* '<S547>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_oe;     /* '<S513>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_jf;     /* '<S517>/Integ4' */
  boolean_T Memory_PreviousInput_ke;   /* '<S14>/Memory' */
  boolean_T Memory_PreviousInput_e;    /* '<S333>/Memory' */
  boolean_T Memory_PreviousInput_p;    /* '<S334>/Memory' */
  boolean_T Memory_PreviousInput_l;    /* '<S336>/Memory' */
  boolean_T Memory_PreviousInput_a;    /* '<S337>/Memory' */
  boolean_T Memory_PreviousInput_i;    /* '<S335>/Memory' */
  boolean_T Memory_PreviousInput_o;    /* '<S338>/Memory' */
  boolean_T Memory_PreviousInput_n;    /* '<S743>/Memory' */
  boolean_T Memory1_PreviousInput_b;   /* '<S741>/Memory1' */
  boolean_T Memory_PreviousInput_ov;   /* '<S744>/Memory' */
  boolean_T Memory_PreviousInput_n2;   /* '<S740>/Memory' */
  boolean_T Memory_PreviousInput_m;    /* '<S731>/Memory' */
  boolean_T Memory_PreviousInput_av;   /* '<S736>/Memory' */
  boolean_T AutomaticGainControl_MODE; /* '<S745>/Automatic Gain Control' */
  boolean_T AutomaticGainControl_MODE_j;/* '<S613>/Automatic Gain Control' */
  boolean_T RMS_MODE;                  /* '<S570>/RMS ' */
  boolean_T TrueRMS_MODE;              /* '<S570>/TrueRMS ' */
  boolean_T AutomaticGainControl_MODE_m;/* '<S502>/Automatic Gain Control' */
  boolean_T RMS_MODE_d;                /* '<S459>/RMS ' */
  boolean_T TrueRMS_MODE_e;            /* '<S459>/TrueRMS ' */
} DW_sel751test_model_1_1_sm_system_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T CHPMIxingTC1_CSTATE[2];       /* '<S249>/CHP MIxing TC1' */
} X_sel751test_model_1_1_sm_system_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T CHPMIxingTC1_CSTATE[2];       /* '<S249>/CHP MIxing TC1' */
} XDot_sel751test_model_1_1_sm_system_T;

/* State disabled  */
typedef struct {
  boolean_T CHPMIxingTC1_CSTATE[2];    /* '<S249>/CHP MIxing TC1' */
} XDis_sel751test_model_1_1_sm_system_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState HitCrossing_Input_ZCE;    /* '<S735>/Hit  Crossing' */
} PrevZCX_sel751test_model_1_1_sm_system_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            sel751test_model_1_1_sm_system_B
#define BlockIO                        B_sel751test_model_1_1_sm_system_T
#define rtX                            sel751test_model_1_1_sm_system_X
#define ContinuousStates               X_sel751test_model_1_1_sm_system_T
#define rtXdot                         sel751test_model_1_1_sm_system_XDot
#define StateDerivatives               XDot_sel751test_model_1_1_sm_system_T
#define tXdis                          sel751test_model_1_1_sm_system_XDis
#define StateDisabled                  XDis_sel751test_model_1_1_sm_system_T
#define rtP                            sel751test_model_1_1_sm_system_P
#define Parameters                     P_sel751test_model_1_1_sm_system_T
#define rtDWork                        sel751test_model_1_1_sm_system_DW
#define D_Work                         DW_sel751test_model_1_1_sm_system_T
#define rtPrevZCSigState               sel751test_model_1_1_sm_system_PrevZCX
#define PrevZCSigStates                PrevZCX_sel751test_model_1_1_sm_system_T

/* Parameters (auto storage) */
struct P_sel751test_model_1_1_sm_system_T_ {
  real_T wref_set_Value;               /* Expression: 0
                                        * Referenced by: '<S257>/wref_set'
                                        */
  real_T Constant_Value;               /* Expression: 1.00
                                        * Referenced by: '<S316>/Constant'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1
                                        * Referenced by: '<S257>/Gain2'
                                        */
  real_T Vref_set_Value;               /* Expression: 0
                                        * Referenced by: '<S257>/Vref_set'
                                        */
  real_T Constant5_Value;              /* Expression: 1.00
                                        * Referenced by: '<S316>/Constant5'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1
                                        * Referenced by: '<S257>/Gain3'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S260>/Constant1'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S316>/Switch1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S260>/Constant2'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S316>/Switch'
                                        */
  real_T Constant1_Value_b;            /* Expression: 0
                                        * Referenced by: '<S264>/Constant1'
                                        */
  real_T Constant2_Value_g;            /* Expression: 0
                                        * Referenced by: '<S282>/Constant2'
                                        */
  real_T Lmqd_nosat_Value[2];          /* Expression: [SM.Lmq SM.Lmd]
                                        * Referenced by: '<S283>/Lmqd_nosat'
                                        */
  real_T Constant4_Value[25];          /* Expression: SM.Linv
                                        * Referenced by: '<S283>/Constant4'
                                        */
  real_T u3_Value;                     /* Expression: SM.Lmq
                                        * Referenced by: '<S293>/u3'
                                        */
  real_T Constant1_Value_f;            /* Expression: SM.Lmsatd(1)
                                        * Referenced by: '<S295>/Constant1'
                                        */
  real_T Constant1_Value_h;            /* Expression: SM.Lmsatq(1)
                                        * Referenced by: '<S296>/Constant1'
                                        */
  real_T Ll_q_Gain[2];                 /* Expression: SM.One_Llq
                                        * Referenced by: '<S301>/1//Ll_q'
                                        */
  real_T u2_Value[3];                  /* Expression: [ 1/SM.Ll 1/SM.Llkq1 1/SM.Llkq2]
                                        * Referenced by: '<S300>/u2'
                                        */
  real_T Lmq_sat_InitialCondition;     /* Expression: SM.Lmsatq(1)
                                        * Referenced by: '<S296>/Lmq_sat'
                                        */
  real_T LookupTable_XData[2];         /* Expression: SM.Phisat
                                        * Referenced by: '<S296>/Lookup Table'
                                        */
  real_T LookupTable_YData[2];         /* Expression: [ 0 SM.Phisat(2:end)./SM.Lmsatq(2:end)*SM.Lmq ]
                                        * Referenced by: '<S296>/Lookup Table'
                                        */
  real_T Lmq_Gain;                     /* Expression: SM.Lmq
                                        * Referenced by: '<S296>/Lmq'
                                        */
  real_T Ll_d_Gain[3];                 /* Expression: [ 1/SM.Ll   1/SM.Llfd   1/SM.Llkd ]
                                        * Referenced by: '<S299>/1//Ll_d'
                                        */
  real_T u1_Value[3];                  /* Expression: [1/SM.Ll 1/SM.Llkd 1/SM.Llfd]
                                        * Referenced by: '<S298>/u1'
                                        */
  real_T Lmd_sat_InitialCondition;     /* Expression: SM.Lmsatd(1)
                                        * Referenced by: '<S295>/Lmd_sat'
                                        */
  real_T LookupTable_XData_g[2];       /* Expression: SM.Phisat
                                        * Referenced by: '<S295>/Lookup Table'
                                        */
  real_T LookupTable_YData_f[2];       /* Expression: [ 0 SM.Phisat(2:end)./SM.Lmsatd(2:end)*SM.Lmd ]
                                        * Referenced by: '<S295>/Lookup Table'
                                        */
  real_T Lmd_Gain;                     /* Expression: SM.Lmd
                                        * Referenced by: '<S295>/Lmd'
                                        */
  real_T u1_Value_d[25];               /* Expression: SM.R
                                        * Referenced by: '<S293>/u1'
                                        */
  real_T u1_Value_k[25];               /* Expression: zeros(SM.nState,SM.nState)
                                        * Referenced by: '<S297>/u1'
                                        */
  real_T u5_Value[25];                 /* Expression: SM.Llqd
                                        * Referenced by: '<S297>/u5'
                                        */
  real_T Constant6_Value[25];          /* Expression: SM.RLinv
                                        * Referenced by: '<S283>/Constant6'
                                        */
  real_T In_Value[25];                 /* Expression: eye(SM.nState,SM.nState)
                                        * Referenced by: '<S302>/In'
                                        */
  real_T wbaseTs2_Gain;                /* Expression: SM.web*Ts
                                        * Referenced by: '<S302>/wbase*Ts//2 '
                                        */
  real_T Constant2_Value_gm;           /* Expression: SM.Sat
                                        * Referenced by: '<S283>/Constant2'
                                        */
  real_T Switch1_Threshold_c;          /* Expression: 0.5
                                        * Referenced by: '<S283>/Switch1'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S291>/Gain1'
                                        */
  real_T u1_Value_m[25];               /* Expression: zeros(SM.nState,SM.nState)
                                        * Referenced by: '<S291>/u1'
                                        */
  real_T wbaseTs_Gain;                 /* Expression: SM.web*Ts
                                        * Referenced by: '<S302>/wbase*Ts'
                                        */
  real_T Constant5_Value_o;            /* Expression: 0
                                        * Referenced by: '<S312>/Constant5'
                                        */
  real_T Constant4_Value_k;            /* Expression: 1
                                        * Referenced by: '<S312>/Constant4'
                                        */
  real_T Constant2_Value_b;            /* Expression: 0
                                        * Referenced by: '<S312>/Constant2'
                                        */
  real_T Constant1_Value_g;            /* Expression: 1
                                        * Referenced by: '<S312>/Constant1'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: K2
                                        * Referenced by: '<S385>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: K1
                                        * Referenced by: '<S385>/Gain'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: K2
                                        * Referenced by: '<S420>/Gain1'
                                        */
  real_T Gain_Gain_m;                  /* Expression: K1
                                        * Referenced by: '<S420>/Gain'
                                        */
  real_T q_Value;                      /* Expression: -1
                                        * Referenced by: '<S460>/q'
                                        */
  real_T d_Value;                      /* Expression: 0
                                        * Referenced by: '<S460>/d'
                                        */
  real_T ProportionalGain_Gain;        /* Expression: P
                                        * Referenced by: '<S455>/Proportional Gain'
                                        */
  real_T ProportionalGain_Gain_o;      /* Expression: P
                                        * Referenced by: '<S454>/Proportional Gain'
                                        */
  real_T Gain_Gain_k;                  /* Expression: .001
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T Constant_Value_n;             /* Expression: 0
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T Gain_Gain_j;                  /* Expression: K1
                                        * Referenced by: '<S472>/Gain'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: K2
                                        * Referenced by: '<S472>/Gain1'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: 0.5
                                        * Referenced by: '<S514>/Gain1'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: 0.5
                                        * Referenced by: '<S518>/Gain1'
                                        */
  real_T Gain_Y0;                      /* Expression: [1]
                                        * Referenced by: '<S503>/Gain'
                                        */
  real_T Gain3_Gain_i[9];              /* Expression: [ 1   -1/2   -1/2; 0   sqrt(3)/2   -sqrt(3)/2; 1/2  1/2  1/2 ]
                                        * Referenced by: '<S521>/Gain3'
                                        */
  real_T Gain1_Gain_cm;                /* Expression: 2/3
                                        * Referenced by: '<S521>/Gain1'
                                        */
  real_T Constant_Value_m;             /* Expression: Alignment
                                        * Referenced by: '<S520>/Constant'
                                        */
  real_T Constant_Value_l;             /* Expression: const
                                        * Referenced by: '<S522>/Constant'
                                        */
  real_T Constant_Value_b;             /* Expression: const
                                        * Referenced by: '<S523>/Constant'
                                        */
  real_T Integ4_gainval;               /* Computed Parameter: Integ4_gainval
                                        * Referenced by: '<S513>/Integ4'
                                        */
  real_T Integ4_IC;                    /* Expression: 0
                                        * Referenced by: '<S513>/Integ4'
                                        */
  real_T Toavoiddivisionbyzero_UpperSat;/* Expression: 1e6
                                         * Referenced by: '<S513>/To avoid division  by zero'
                                         */
  real_T Toavoiddivisionbyzero_LowerSat;/* Expression: eps
                                         * Referenced by: '<S513>/To avoid division  by zero'
                                         */
  real_T Gain_Gain_f;                  /* Expression: Ts
                                        * Referenced by: '<S513>/Gain'
                                        */
  real_T SFunction_P1_Size[2];         /* Computed Parameter: SFunction_P1_Size
                                        * Referenced by: '<S515>/S-Function'
                                        */
  real_T SFunction_P1;                 /* Expression: MaxDelay
                                        * Referenced by: '<S515>/S-Function'
                                        */
  real_T SFunction_P2_Size[2];         /* Computed Parameter: SFunction_P2_Size
                                        * Referenced by: '<S515>/S-Function'
                                        */
  real_T SFunction_P2;                 /* Expression: Ts
                                        * Referenced by: '<S515>/S-Function'
                                        */
  real_T SFunction_P3_Size[2];         /* Computed Parameter: SFunction_P3_Size
                                        * Referenced by: '<S515>/S-Function'
                                        */
  real_T SFunction_P3;                 /* Expression: InitialValue
                                        * Referenced by: '<S515>/S-Function'
                                        */
  real_T SFunction_P4_Size[2];         /* Computed Parameter: SFunction_P4_Size
                                        * Referenced by: '<S515>/S-Function'
                                        */
  real_T SFunction_P4;                 /* Expression: DFT
                                        * Referenced by: '<S515>/S-Function'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S514>/Unit Delay'
                                        */
  real_T Constant_Value_f;             /* Expression: 1/sps.Finit
                                        * Referenced by: '<S513>/Constant'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: sps.Vinit
                                        * Referenced by: '<S513>/Unit Delay1'
                                        */
  real_T Integ4_gainval_g;             /* Computed Parameter: Integ4_gainval_g
                                        * Referenced by: '<S517>/Integ4'
                                        */
  real_T Integ4_IC_a;                  /* Expression: 0
                                        * Referenced by: '<S517>/Integ4'
                                        */
  real_T Toavoiddivisionbyzero_UpperSa_m;/* Expression: 1e6
                                          * Referenced by: '<S517>/To avoid division  by zero'
                                          */
  real_T Toavoiddivisionbyzero_LowerSa_m;/* Expression: eps
                                          * Referenced by: '<S517>/To avoid division  by zero'
                                          */
  real_T Gain_Gain_d;                  /* Expression: Ts
                                        * Referenced by: '<S517>/Gain'
                                        */
  real_T SFunction_P1_Size_f[2];       /* Computed Parameter: SFunction_P1_Size_f
                                        * Referenced by: '<S519>/S-Function'
                                        */
  real_T SFunction_P1_g;               /* Expression: MaxDelay
                                        * Referenced by: '<S519>/S-Function'
                                        */
  real_T SFunction_P2_Size_l[2];       /* Computed Parameter: SFunction_P2_Size_l
                                        * Referenced by: '<S519>/S-Function'
                                        */
  real_T SFunction_P2_i;               /* Expression: Ts
                                        * Referenced by: '<S519>/S-Function'
                                        */
  real_T SFunction_P3_Size_i[2];       /* Computed Parameter: SFunction_P3_Size_i
                                        * Referenced by: '<S519>/S-Function'
                                        */
  real_T SFunction_P3_i;               /* Expression: InitialValue
                                        * Referenced by: '<S519>/S-Function'
                                        */
  real_T SFunction_P4_Size_c[2];       /* Computed Parameter: SFunction_P4_Size_c
                                        * Referenced by: '<S519>/S-Function'
                                        */
  real_T SFunction_P4_g;               /* Expression: DFT
                                        * Referenced by: '<S519>/S-Function'
                                        */
  real_T UnitDelay_InitialCondition_j; /* Expression: 0
                                        * Referenced by: '<S518>/Unit Delay'
                                        */
  real_T Constant_Value_fe;            /* Expression: 1/sps.Finit
                                        * Referenced by: '<S517>/Constant'
                                        */
  real_T UnitDelay1_InitialCondition_m;/* Expression: sps.Vinit
                                        * Referenced by: '<S517>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: inf
                                        * Referenced by: '<S503>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: eps
                                        * Referenced by: '<S503>/Saturation'
                                        */
  real_T RadDeg_Gain;                  /* Expression: 180/pi
                                        * Referenced by: '<S508>/Rad->Deg.'
                                        */
  real_T Gain1_Gain_hv;                /* Expression: 0.5
                                        * Referenced by: '<S533>/Gain1'
                                        */
  real_T Gain_Gain_p;                  /* Expression: sps.K1
                                        * Referenced by: '<S547>/Gain'
                                        */
  real_T Gain1_Gain_ce;                /* Expression: sps.K2
                                        * Referenced by: '<S547>/Gain1'
                                        */
  real_T Gain_Gain_pk;                 /* Expression: sps.K1
                                        * Referenced by: '<S550>/Gain'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: sps.K2
                                        * Referenced by: '<S550>/Gain1'
                                        */
  real_T sinwt_Amp;                    /* Expression: sps.k
                                        * Referenced by: '<S543>/sin(wt)'
                                        */
  real_T sinwt_Bias;                   /* Expression: 0
                                        * Referenced by: '<S543>/sin(wt)'
                                        */
  real_T sinwt_Freq;                   /* Expression: 2*pi*Freq*sps.n
                                        * Referenced by: '<S543>/sin(wt)'
                                        */
  real_T sinwt_Hsin;                   /* Computed Parameter: sinwt_Hsin
                                        * Referenced by: '<S543>/sin(wt)'
                                        */
  real_T sinwt_HCos;                   /* Computed Parameter: sinwt_HCos
                                        * Referenced by: '<S543>/sin(wt)'
                                        */
  real_T sinwt_PSin;                   /* Computed Parameter: sinwt_PSin
                                        * Referenced by: '<S543>/sin(wt)'
                                        */
  real_T sinwt_PCos;                   /* Computed Parameter: sinwt_PCos
                                        * Referenced by: '<S543>/sin(wt)'
                                        */
  real_T Integ4_gainval_n;             /* Computed Parameter: Integ4_gainval_n
                                        * Referenced by: '<S550>/Integ4'
                                        */
  real_T Integ4_IC_av;                 /* Expression: 0
                                        * Referenced by: '<S550>/Integ4'
                                        */
  real_T K1_Value;                     /* Expression: sps.Delay
                                        * Referenced by: '<S550>/K1'
                                        */
  real_T SFunction_P1_Size_j[2];       /* Computed Parameter: SFunction_P1_Size_j
                                        * Referenced by: '<S551>/S-Function'
                                        */
  real_T SFunction_P1_e;               /* Expression: MaxDelay
                                        * Referenced by: '<S551>/S-Function'
                                        */
  real_T SFunction_P2_Size_n[2];       /* Computed Parameter: SFunction_P2_Size_n
                                        * Referenced by: '<S551>/S-Function'
                                        */
  real_T SFunction_P2_c;               /* Expression: Ts
                                        * Referenced by: '<S551>/S-Function'
                                        */
  real_T SFunction_P3_Size_o[2];       /* Computed Parameter: SFunction_P3_Size_o
                                        * Referenced by: '<S551>/S-Function'
                                        */
  real_T SFunction_P3_h;               /* Expression: InitialValue
                                        * Referenced by: '<S551>/S-Function'
                                        */
  real_T SFunction_P4_Size_h[2];       /* Computed Parameter: SFunction_P4_Size_h
                                        * Referenced by: '<S551>/S-Function'
                                        */
  real_T SFunction_P4_a;               /* Expression: DFT
                                        * Referenced by: '<S551>/S-Function'
                                        */
  real_T K2_Value;                     /* Expression: sps.Freq
                                        * Referenced by: '<S550>/K2'
                                        */
  real_T UnitDelay_InitialCondition_p; /* Expression: 0
                                        * Referenced by: '<S550>/Unit Delay'
                                        */
  real_T UnitDelay1_InitialCondition_g;/* Expression: sps.Vinit
                                        * Referenced by: '<S550>/Unit Delay1'
                                        */
  real_T coswt_Amp;                    /* Expression: sps.k
                                        * Referenced by: '<S543>/cos(wt)'
                                        */
  real_T coswt_Bias;                   /* Expression: 0
                                        * Referenced by: '<S543>/cos(wt)'
                                        */
  real_T coswt_Freq;                   /* Expression: 2*pi*Freq*sps.n
                                        * Referenced by: '<S543>/cos(wt)'
                                        */
  real_T coswt_Hsin;                   /* Computed Parameter: coswt_Hsin
                                        * Referenced by: '<S543>/cos(wt)'
                                        */
  real_T coswt_HCos;                   /* Computed Parameter: coswt_HCos
                                        * Referenced by: '<S543>/cos(wt)'
                                        */
  real_T coswt_PSin;                   /* Computed Parameter: coswt_PSin
                                        * Referenced by: '<S543>/cos(wt)'
                                        */
  real_T coswt_PCos;                   /* Computed Parameter: coswt_PCos
                                        * Referenced by: '<S543>/cos(wt)'
                                        */
  real_T Integ4_gainval_p;             /* Computed Parameter: Integ4_gainval_p
                                        * Referenced by: '<S547>/Integ4'
                                        */
  real_T Integ4_IC_n;                  /* Expression: 0
                                        * Referenced by: '<S547>/Integ4'
                                        */
  real_T K1_Value_a;                   /* Expression: sps.Delay
                                        * Referenced by: '<S547>/K1'
                                        */
  real_T SFunction_P1_Size_d[2];       /* Computed Parameter: SFunction_P1_Size_d
                                        * Referenced by: '<S548>/S-Function'
                                        */
  real_T SFunction_P1_m;               /* Expression: MaxDelay
                                        * Referenced by: '<S548>/S-Function'
                                        */
  real_T SFunction_P2_Size_k[2];       /* Computed Parameter: SFunction_P2_Size_k
                                        * Referenced by: '<S548>/S-Function'
                                        */
  real_T SFunction_P2_b;               /* Expression: Ts
                                        * Referenced by: '<S548>/S-Function'
                                        */
  real_T SFunction_P3_Size_g[2];       /* Computed Parameter: SFunction_P3_Size_g
                                        * Referenced by: '<S548>/S-Function'
                                        */
  real_T SFunction_P3_j;               /* Expression: InitialValue
                                        * Referenced by: '<S548>/S-Function'
                                        */
  real_T SFunction_P4_Size_h2[2];      /* Computed Parameter: SFunction_P4_Size_h2
                                        * Referenced by: '<S548>/S-Function'
                                        */
  real_T SFunction_P4_c;               /* Expression: DFT
                                        * Referenced by: '<S548>/S-Function'
                                        */
  real_T K2_Value_k;                   /* Expression: sps.Freq
                                        * Referenced by: '<S547>/K2'
                                        */
  real_T UnitDelay_InitialCondition_i; /* Expression: 0
                                        * Referenced by: '<S547>/Unit Delay'
                                        */
  real_T UnitDelay1_InitialCondition_n;/* Expression: sps.Vinit
                                        * Referenced by: '<S547>/Unit Delay1'
                                        */
  real_T RadDeg_Gain_m;                /* Expression: 180/pi
                                        * Referenced by: '<S543>/Rad->Deg.'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 1/sqrt(2)
                                        * Referenced by: '<S541>/Gain'
                                        */
  real_T Gain1_Gain_gg;                /* Expression: sps.K2
                                        * Referenced by: '<S554>/Gain1'
                                        */
  real_T Gain_Gain_ji;                 /* Expression: sps.K1
                                        * Referenced by: '<S554>/Gain'
                                        */
  real_T Integ4_gainval_l;             /* Computed Parameter: Integ4_gainval_l
                                        * Referenced by: '<S554>/Integ4'
                                        */
  real_T Integ4_IC_c;                  /* Expression: 0
                                        * Referenced by: '<S554>/Integ4'
                                        */
  real_T K1_Value_f;                   /* Expression: sps.Delay
                                        * Referenced by: '<S554>/K1'
                                        */
  real_T SFunction_P1_Size_jx[2];      /* Computed Parameter: SFunction_P1_Size_jx
                                        * Referenced by: '<S555>/S-Function'
                                        */
  real_T SFunction_P1_f;               /* Expression: MaxDelay
                                        * Referenced by: '<S555>/S-Function'
                                        */
  real_T SFunction_P2_Size_p[2];       /* Computed Parameter: SFunction_P2_Size_p
                                        * Referenced by: '<S555>/S-Function'
                                        */
  real_T SFunction_P2_n;               /* Expression: Ts
                                        * Referenced by: '<S555>/S-Function'
                                        */
  real_T SFunction_P3_Size_iq[2];      /* Computed Parameter: SFunction_P3_Size_iq
                                        * Referenced by: '<S555>/S-Function'
                                        */
  real_T SFunction_P3_a;               /* Expression: InitialValue
                                        * Referenced by: '<S555>/S-Function'
                                        */
  real_T SFunction_P4_Size_hv[2];      /* Computed Parameter: SFunction_P4_Size_hv
                                        * Referenced by: '<S555>/S-Function'
                                        */
  real_T SFunction_P4_a2;              /* Expression: DFT
                                        * Referenced by: '<S555>/S-Function'
                                        */
  real_T UnitDelay_InitialCondition_e; /* Expression: 0
                                        * Referenced by: '<S554>/Unit Delay'
                                        */
  real_T K2_Value_j;                   /* Expression: sps.Freq
                                        * Referenced by: '<S554>/K2'
                                        */
  real_T UnitDelay1_InitialCondition_c;/* Expression: sps.Vinit
                                        * Referenced by: '<S554>/Unit Delay1'
                                        */
  real_T Saturationtoavoidnegativesqrt_U;/* Expression: Inf
                                          * Referenced by: '<S542>/Saturation to avoid negative sqrt'
                                          */
  real_T Saturationtoavoidnegativesqrt_L;/* Expression: 0
                                          * Referenced by: '<S542>/Saturation to avoid negative sqrt'
                                          */
  real_T q_Value_c;                    /* Expression: -1
                                        * Referenced by: '<S571>/q'
                                        */
  real_T d_Value_p;                    /* Expression: 0
                                        * Referenced by: '<S571>/d'
                                        */
  real_T ProportionalGain_Gain_f;      /* Expression: P
                                        * Referenced by: '<S566>/Proportional Gain'
                                        */
  real_T ProportionalGain_Gain_h;      /* Expression: P
                                        * Referenced by: '<S565>/Proportional Gain'
                                        */
  real_T Gain_Gain_k3;                 /* Expression: .001
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T Gain_Gain_c;                  /* Expression: K1
                                        * Referenced by: '<S583>/Gain'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: K2
                                        * Referenced by: '<S583>/Gain1'
                                        */
  real_T Gain1_Gain_cy;                /* Expression: 0.5
                                        * Referenced by: '<S625>/Gain1'
                                        */
  real_T Gain1_Gain_hk;                /* Expression: 0.5
                                        * Referenced by: '<S629>/Gain1'
                                        */
  real_T Gain_Y0_o;                    /* Expression: [1]
                                        * Referenced by: '<S614>/Gain'
                                        */
  real_T Gain3_Gain_k[9];              /* Expression: [ 1   -1/2   -1/2; 0   sqrt(3)/2   -sqrt(3)/2; 1/2  1/2  1/2 ]
                                        * Referenced by: '<S632>/Gain3'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: 2/3
                                        * Referenced by: '<S632>/Gain1'
                                        */
  real_T Constant_Value_j;             /* Expression: Alignment
                                        * Referenced by: '<S631>/Constant'
                                        */
  real_T Constant_Value_h;             /* Expression: const
                                        * Referenced by: '<S633>/Constant'
                                        */
  real_T Constant_Value_nn;            /* Expression: const
                                        * Referenced by: '<S634>/Constant'
                                        */
  real_T Integ4_gainval_e;             /* Computed Parameter: Integ4_gainval_e
                                        * Referenced by: '<S624>/Integ4'
                                        */
  real_T Integ4_IC_f;                  /* Expression: 0
                                        * Referenced by: '<S624>/Integ4'
                                        */
  real_T Toavoiddivisionbyzero_UpperSa_g;/* Expression: 1e6
                                          * Referenced by: '<S624>/To avoid division  by zero'
                                          */
  real_T Toavoiddivisionbyzero_LowerSa_l;/* Expression: eps
                                          * Referenced by: '<S624>/To avoid division  by zero'
                                          */
  real_T Gain_Gain_g;                  /* Expression: Ts
                                        * Referenced by: '<S624>/Gain'
                                        */
  real_T SFunction_P1_Size_l[2];       /* Computed Parameter: SFunction_P1_Size_l
                                        * Referenced by: '<S626>/S-Function'
                                        */
  real_T SFunction_P1_p;               /* Expression: MaxDelay
                                        * Referenced by: '<S626>/S-Function'
                                        */
  real_T SFunction_P2_Size_j[2];       /* Computed Parameter: SFunction_P2_Size_j
                                        * Referenced by: '<S626>/S-Function'
                                        */
  real_T SFunction_P2_l;               /* Expression: Ts
                                        * Referenced by: '<S626>/S-Function'
                                        */
  real_T SFunction_P3_Size_k[2];       /* Computed Parameter: SFunction_P3_Size_k
                                        * Referenced by: '<S626>/S-Function'
                                        */
  real_T SFunction_P3_j0;              /* Expression: InitialValue
                                        * Referenced by: '<S626>/S-Function'
                                        */
  real_T SFunction_P4_Size_p[2];       /* Computed Parameter: SFunction_P4_Size_p
                                        * Referenced by: '<S626>/S-Function'
                                        */
  real_T SFunction_P4_ax;              /* Expression: DFT
                                        * Referenced by: '<S626>/S-Function'
                                        */
  real_T UnitDelay_InitialCondition_k; /* Expression: 0
                                        * Referenced by: '<S625>/Unit Delay'
                                        */
  real_T Constant_Value_l4;            /* Expression: 1/sps.Finit
                                        * Referenced by: '<S624>/Constant'
                                        */
  real_T UnitDelay1_InitialCondition_p;/* Expression: sps.Vinit
                                        * Referenced by: '<S624>/Unit Delay1'
                                        */
  real_T Integ4_gainval_d;             /* Computed Parameter: Integ4_gainval_d
                                        * Referenced by: '<S628>/Integ4'
                                        */
  real_T Integ4_IC_p;                  /* Expression: 0
                                        * Referenced by: '<S628>/Integ4'
                                        */
  real_T Toavoiddivisionbyzero_UpperSa_j;/* Expression: 1e6
                                          * Referenced by: '<S628>/To avoid division  by zero'
                                          */
  real_T Toavoiddivisionbyzero_LowerSa_i;/* Expression: eps
                                          * Referenced by: '<S628>/To avoid division  by zero'
                                          */
  real_T Gain_Gain_o;                  /* Expression: Ts
                                        * Referenced by: '<S628>/Gain'
                                        */
  real_T SFunction_P1_Size_k[2];       /* Computed Parameter: SFunction_P1_Size_k
                                        * Referenced by: '<S630>/S-Function'
                                        */
  real_T SFunction_P1_j;               /* Expression: MaxDelay
                                        * Referenced by: '<S630>/S-Function'
                                        */
  real_T SFunction_P2_Size_d[2];       /* Computed Parameter: SFunction_P2_Size_d
                                        * Referenced by: '<S630>/S-Function'
                                        */
  real_T SFunction_P2_p;               /* Expression: Ts
                                        * Referenced by: '<S630>/S-Function'
                                        */
  real_T SFunction_P3_Size_gu[2];      /* Computed Parameter: SFunction_P3_Size_gu
                                        * Referenced by: '<S630>/S-Function'
                                        */
  real_T SFunction_P3_o;               /* Expression: InitialValue
                                        * Referenced by: '<S630>/S-Function'
                                        */
  real_T SFunction_P4_Size_m[2];       /* Computed Parameter: SFunction_P4_Size_m
                                        * Referenced by: '<S630>/S-Function'
                                        */
  real_T SFunction_P4_c5;              /* Expression: DFT
                                        * Referenced by: '<S630>/S-Function'
                                        */
  real_T UnitDelay_InitialCondition_l; /* Expression: 0
                                        * Referenced by: '<S629>/Unit Delay'
                                        */
  real_T Constant_Value_pp;            /* Expression: 1/sps.Finit
                                        * Referenced by: '<S628>/Constant'
                                        */
  real_T UnitDelay1_InitialCondition_ng;/* Expression: sps.Vinit
                                         * Referenced by: '<S628>/Unit Delay1'
                                         */
  real_T Saturation_UpperSat_n;        /* Expression: inf
                                        * Referenced by: '<S614>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: eps
                                        * Referenced by: '<S614>/Saturation'
                                        */
  real_T RadDeg_Gain_k;                /* Expression: 180/pi
                                        * Referenced by: '<S619>/Rad->Deg.'
                                        */
  real_T Gain1_Gain_k;                 /* Expression: 0.5
                                        * Referenced by: '<S644>/Gain1'
                                        */
  real_T Gain_Gain_ef;                 /* Expression: sps.K1
                                        * Referenced by: '<S658>/Gain'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: sps.K2
                                        * Referenced by: '<S658>/Gain1'
                                        */
  real_T Gain_Gain_o2;                 /* Expression: sps.K1
                                        * Referenced by: '<S661>/Gain'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: sps.K2
                                        * Referenced by: '<S661>/Gain1'
                                        */
  real_T sinwt_Amp_a;                  /* Expression: sps.k
                                        * Referenced by: '<S654>/sin(wt)'
                                        */
  real_T sinwt_Bias_o;                 /* Expression: 0
                                        * Referenced by: '<S654>/sin(wt)'
                                        */
  real_T sinwt_Freq_l;                 /* Expression: 2*pi*Freq*sps.n
                                        * Referenced by: '<S654>/sin(wt)'
                                        */
  real_T sinwt_Hsin_l;                 /* Computed Parameter: sinwt_Hsin_l
                                        * Referenced by: '<S654>/sin(wt)'
                                        */
  real_T sinwt_HCos_h;                 /* Computed Parameter: sinwt_HCos_h
                                        * Referenced by: '<S654>/sin(wt)'
                                        */
  real_T sinwt_PSin_l;                 /* Computed Parameter: sinwt_PSin_l
                                        * Referenced by: '<S654>/sin(wt)'
                                        */
  real_T sinwt_PCos_e;                 /* Computed Parameter: sinwt_PCos_e
                                        * Referenced by: '<S654>/sin(wt)'
                                        */
  real_T Integ4_gainval_o;             /* Computed Parameter: Integ4_gainval_o
                                        * Referenced by: '<S661>/Integ4'
                                        */
  real_T Integ4_IC_g;                  /* Expression: 0
                                        * Referenced by: '<S661>/Integ4'
                                        */
  real_T K1_Value_n;                   /* Expression: sps.Delay
                                        * Referenced by: '<S661>/K1'
                                        */
  real_T SFunction_P1_Size_e[2];       /* Computed Parameter: SFunction_P1_Size_e
                                        * Referenced by: '<S662>/S-Function'
                                        */
  real_T SFunction_P1_e5;              /* Expression: MaxDelay
                                        * Referenced by: '<S662>/S-Function'
                                        */
  real_T SFunction_P2_Size_b[2];       /* Computed Parameter: SFunction_P2_Size_b
                                        * Referenced by: '<S662>/S-Function'
                                        */
  real_T SFunction_P2_d;               /* Expression: Ts
                                        * Referenced by: '<S662>/S-Function'
                                        */
  real_T SFunction_P3_Size_gs[2];      /* Computed Parameter: SFunction_P3_Size_gs
                                        * Referenced by: '<S662>/S-Function'
                                        */
  real_T SFunction_P3_m;               /* Expression: InitialValue
                                        * Referenced by: '<S662>/S-Function'
                                        */
  real_T SFunction_P4_Size_a[2];       /* Computed Parameter: SFunction_P4_Size_a
                                        * Referenced by: '<S662>/S-Function'
                                        */
  real_T SFunction_P4_f;               /* Expression: DFT
                                        * Referenced by: '<S662>/S-Function'
                                        */
  real_T K2_Value_g;                   /* Expression: sps.Freq
                                        * Referenced by: '<S661>/K2'
                                        */
  real_T UnitDelay_InitialCondition_d; /* Expression: 0
                                        * Referenced by: '<S661>/Unit Delay'
                                        */
  real_T UnitDelay1_InitialCondition_gu;/* Expression: sps.Vinit
                                         * Referenced by: '<S661>/Unit Delay1'
                                         */
  real_T coswt_Amp_e;                  /* Expression: sps.k
                                        * Referenced by: '<S654>/cos(wt)'
                                        */
  real_T coswt_Bias_h;                 /* Expression: 0
                                        * Referenced by: '<S654>/cos(wt)'
                                        */
  real_T coswt_Freq_k;                 /* Expression: 2*pi*Freq*sps.n
                                        * Referenced by: '<S654>/cos(wt)'
                                        */
  real_T coswt_Hsin_a;                 /* Computed Parameter: coswt_Hsin_a
                                        * Referenced by: '<S654>/cos(wt)'
                                        */
  real_T coswt_HCos_p;                 /* Computed Parameter: coswt_HCos_p
                                        * Referenced by: '<S654>/cos(wt)'
                                        */
  real_T coswt_PSin_l;                 /* Computed Parameter: coswt_PSin_l
                                        * Referenced by: '<S654>/cos(wt)'
                                        */
  real_T coswt_PCos_c;                 /* Computed Parameter: coswt_PCos_c
                                        * Referenced by: '<S654>/cos(wt)'
                                        */
  real_T Integ4_gainval_oo;            /* Computed Parameter: Integ4_gainval_oo
                                        * Referenced by: '<S658>/Integ4'
                                        */
  real_T Integ4_IC_e;                  /* Expression: 0
                                        * Referenced by: '<S658>/Integ4'
                                        */
  real_T K1_Value_e;                   /* Expression: sps.Delay
                                        * Referenced by: '<S658>/K1'
                                        */
  real_T SFunction_P1_Size_jl[2];      /* Computed Parameter: SFunction_P1_Size_jl
                                        * Referenced by: '<S659>/S-Function'
                                        */
  real_T SFunction_P1_ee;              /* Expression: MaxDelay
                                        * Referenced by: '<S659>/S-Function'
                                        */
  real_T SFunction_P2_Size_c[2];       /* Computed Parameter: SFunction_P2_Size_c
                                        * Referenced by: '<S659>/S-Function'
                                        */
  real_T SFunction_P2_k;               /* Expression: Ts
                                        * Referenced by: '<S659>/S-Function'
                                        */
  real_T SFunction_P3_Size_m[2];       /* Computed Parameter: SFunction_P3_Size_m
                                        * Referenced by: '<S659>/S-Function'
                                        */
  real_T SFunction_P3_o2;              /* Expression: InitialValue
                                        * Referenced by: '<S659>/S-Function'
                                        */
  real_T SFunction_P4_Size_a2[2];      /* Computed Parameter: SFunction_P4_Size_a2
                                        * Referenced by: '<S659>/S-Function'
                                        */
  real_T SFunction_P4_gr;              /* Expression: DFT
                                        * Referenced by: '<S659>/S-Function'
                                        */
  real_T K2_Value_i;                   /* Expression: sps.Freq
                                        * Referenced by: '<S658>/K2'
                                        */
  real_T UnitDelay_InitialCondition_b; /* Expression: 0
                                        * Referenced by: '<S658>/Unit Delay'
                                        */
  real_T UnitDelay1_InitialCondition_gv;/* Expression: sps.Vinit
                                         * Referenced by: '<S658>/Unit Delay1'
                                         */
  real_T RadDeg_Gain_d;                /* Expression: 180/pi
                                        * Referenced by: '<S654>/Rad->Deg.'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 1/sqrt(2)
                                        * Referenced by: '<S652>/Gain'
                                        */
  real_T Gain1_Gain_lc;                /* Expression: sps.K2
                                        * Referenced by: '<S665>/Gain1'
                                        */
  real_T Gain_Gain_b;                  /* Expression: sps.K1
                                        * Referenced by: '<S665>/Gain'
                                        */
  real_T Integ4_gainval_i;             /* Computed Parameter: Integ4_gainval_i
                                        * Referenced by: '<S665>/Integ4'
                                        */
  real_T Integ4_IC_cv;                 /* Expression: 0
                                        * Referenced by: '<S665>/Integ4'
                                        */
  real_T K1_Value_h;                   /* Expression: sps.Delay
                                        * Referenced by: '<S665>/K1'
                                        */
  real_T SFunction_P1_Size_fo[2];      /* Computed Parameter: SFunction_P1_Size_fo
                                        * Referenced by: '<S666>/S-Function'
                                        */
  real_T SFunction_P1_c;               /* Expression: MaxDelay
                                        * Referenced by: '<S666>/S-Function'
                                        */
  real_T SFunction_P2_Size_i[2];       /* Computed Parameter: SFunction_P2_Size_i
                                        * Referenced by: '<S666>/S-Function'
                                        */
  real_T SFunction_P2_n2;              /* Expression: Ts
                                        * Referenced by: '<S666>/S-Function'
                                        */
  real_T SFunction_P3_Size_b[2];       /* Computed Parameter: SFunction_P3_Size_b
                                        * Referenced by: '<S666>/S-Function'
                                        */
  real_T SFunction_P3_c;               /* Expression: InitialValue
                                        * Referenced by: '<S666>/S-Function'
                                        */
  real_T SFunction_P4_Size_j[2];       /* Computed Parameter: SFunction_P4_Size_j
                                        * Referenced by: '<S666>/S-Function'
                                        */
  real_T SFunction_P4_i;               /* Expression: DFT
                                        * Referenced by: '<S666>/S-Function'
                                        */
  real_T UnitDelay_InitialCondition_c; /* Expression: 0
                                        * Referenced by: '<S665>/Unit Delay'
                                        */
  real_T K2_Value_c;                   /* Expression: sps.Freq
                                        * Referenced by: '<S665>/K2'
                                        */
  real_T UnitDelay1_InitialCondition_gx;/* Expression: sps.Vinit
                                         * Referenced by: '<S665>/Unit Delay1'
                                         */
  real_T Saturationtoavoidnegativesqrt_g;/* Expression: Inf
                                          * Referenced by: '<S653>/Saturation to avoid negative sqrt'
                                          */
  real_T Saturationtoavoidnegativesqrt_k;/* Expression: 0
                                          * Referenced by: '<S653>/Saturation to avoid negative sqrt'
                                          */
  real_T nonPOW_Value;                 /* Expression: 1
                                        * Referenced by: '<S22>/non-POW'
                                        */
  real_T Levelcrossing1_Value;         /* Expression: vol_sel
                                        * Referenced by: '<S733>/Level crossing1'
                                        */
  real_T Switch_Threshold_e;           /* Expression: 1.5
                                        * Referenced by: '<S733>/Switch'
                                        */
  real_T POW_angle_Value;              /* Expression: angle_POW
                                        * Referenced by: '<S731>/POW_angle'
                                        */
  real_T POW_en_Value;                 /* Expression: enable_POW
                                        * Referenced by: '<S731>/POW_en'
                                        */
  real_T Fault_loc_Value;              /* Expression: fault_location
                                        * Referenced by: '<S731>/Fault_loc'
                                        */
  real_T Ftype_Value;                  /* Expression: fault_type
                                        * Referenced by: '<S731>/Ftype'
                                        */
  real_T Tstart_Value;                 /* Expression: T_start
                                        * Referenced by: '<S731>/Tstart'
                                        */
  real_T Tdur_Value;                   /* Expression: T_dur
                                        * Referenced by: '<S731>/Tdur'
                                        */
  real_T Tacq_Value;                   /* Expression: T_acq
                                        * Referenced by: '<S732>/Tacq'
                                        */
  real_T Gain1_Gain_kz;                /* Expression: 0.5
                                        * Referenced by: '<S757>/Gain1'
                                        */
  real_T Gain1_Gain_d2;                /* Expression: 0.5
                                        * Referenced by: '<S759>/Gain1'
                                        */
  real_T Gain_Y0_l;                    /* Expression: [1]
                                        * Referenced by: '<S749>/Gain'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: 2
                                        * Referenced by: '<S753>/Gain1'
                                        */
  real_T Integ4_gainval_c;             /* Computed Parameter: Integ4_gainval_c
                                        * Referenced by: '<S755>/Integ4'
                                        */
  real_T Integ4_IC_b;                  /* Expression: 0
                                        * Referenced by: '<S755>/Integ4'
                                        */
  real_T Toavoiddivisionbyzero_UpperS_je;/* Expression: 1e6
                                          * Referenced by: '<S755>/To avoid division by zero'
                                          */
  real_T Toavoiddivisionbyzero_LowerS_mw;/* Expression: 1e-6
                                          * Referenced by: '<S755>/To avoid division by zero'
                                          */
  real_T Gain_Gain_n;                  /* Expression: Ts
                                        * Referenced by: '<S755>/Gain'
                                        */
  real_T UnitDelay_InitialCondition_o; /* Expression: 0
                                        * Referenced by: '<S757>/Unit Delay'
                                        */
  real_T Step_Time;                    /* Expression: 1/Finit
                                        * Referenced by: '<S755>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S755>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<S755>/Step'
                                        */
  real_T Constant_Value_lz;            /* Expression: Vinit
                                        * Referenced by: '<S755>/Constant'
                                        */
  real_T Switch_Threshold_j;           /* Expression: 0.5
                                        * Referenced by: '<S755>/Switch'
                                        */
  real_T Integ4_gainval_pe;            /* Computed Parameter: Integ4_gainval_pe
                                        * Referenced by: '<S756>/Integ4'
                                        */
  real_T Integ4_IC_j;                  /* Expression: 0
                                        * Referenced by: '<S756>/Integ4'
                                        */
  real_T Toavoiddivisionbyzero_UpperSa_h;/* Expression: 1e6
                                          * Referenced by: '<S756>/To avoid division by zero'
                                          */
  real_T Toavoiddivisionbyzero_LowerSa_a;/* Expression: 1e-6
                                          * Referenced by: '<S756>/To avoid division by zero'
                                          */
  real_T Gain_Gain_jq;                 /* Expression: Ts
                                        * Referenced by: '<S756>/Gain'
                                        */
  real_T UnitDelay_InitialCondition_i5;/* Expression: 0
                                        * Referenced by: '<S759>/Unit Delay'
                                        */
  real_T Step_Time_d;                  /* Expression: 1/Finit
                                        * Referenced by: '<S756>/Step'
                                        */
  real_T Step_Y0_c;                    /* Expression: 0
                                        * Referenced by: '<S756>/Step'
                                        */
  real_T Step_YFinal_c;                /* Expression: 1
                                        * Referenced by: '<S756>/Step'
                                        */
  real_T Constant_Value_pl;            /* Expression: Vinit
                                        * Referenced by: '<S756>/Constant'
                                        */
  real_T Switch_Threshold_g;           /* Expression: 0.5
                                        * Referenced by: '<S756>/Switch'
                                        */
  real_T RadDeg_Gain_h;                /* Expression: 180/pi
                                        * Referenced by: '<S753>/Rad->Deg.'
                                        */
  real_T Saturation_UpperSat_b;        /* Expression: 2
                                        * Referenced by: '<S749>/Saturation'
                                        */
  real_T Saturation_LowerSat_i;        /* Expression: 0.01
                                        * Referenced by: '<S749>/Saturation'
                                        */
  real_T Gain1_Gain_l0;                /* Expression: 0.5
                                        * Referenced by: '<S762>/Gain1'
                                        */
  real_T SFunction_P1_Size_p[2];       /* Computed Parameter: SFunction_P1_Size_p
                                        * Referenced by: '<S767>/S-Function'
                                        */
  real_T SFunction_P1_mj;              /* Expression: dest
                                        * Referenced by: '<S767>/S-Function'
                                        */
  real_T SFunction_P2_Size_dv[2];      /* Computed Parameter: SFunction_P2_Size_dv
                                        * Referenced by: '<S767>/S-Function'
                                        */
  real_T SFunction_P2_cd;              /* Expression: priority2
                                        * Referenced by: '<S767>/S-Function'
                                        */
  real_T SFunction_P3_Size_a[2];       /* Computed Parameter: SFunction_P3_Size_a
                                        * Referenced by: '<S767>/S-Function'
                                        */
  real_T SFunction_P3_n;               /* Expression: st
                                        * Referenced by: '<S767>/S-Function'
                                        */
  real_T SFunction1_Value;             /* Expression: 0
                                        * Referenced by: '<S2>/S-Function1'
                                        */
  real_T SFunction_X0;                 /* Expression: 0
                                        * Referenced by: '<S2>/S-Function'
                                        */
  real_T Memory5_X0;                   /* Expression: 0
                                        * Referenced by: '<S8>/Memory5'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S8>/Memory1'
                                        */
  real_T Memory2_X0;                   /* Expression: 0
                                        * Referenced by: '<S8>/Memory2'
                                        */
  real_T Memory3_X0;                   /* Expression: 0
                                        * Referenced by: '<S8>/Memory3'
                                        */
  real_T Memory5_X0_o;                 /* Expression: 0
                                        * Referenced by: '<S9>/Memory5'
                                        */
  real_T Memory1_X0_a;                 /* Expression: 0
                                        * Referenced by: '<S9>/Memory1'
                                        */
  real_T Memory2_X0_k;                 /* Expression: 0
                                        * Referenced by: '<S9>/Memory2'
                                        */
  real_T Memory3_X0_c;                 /* Expression: 0
                                        * Referenced by: '<S9>/Memory3'
                                        */
  real_T Memory5_1_X0;                 /* Expression: 0
                                        * Referenced by: '<S16>/Memory5'
                                        */
  real_T Memory5_2_X0;                 /* Expression: 0
                                        * Referenced by: '<S16>/Memory5'
                                        */
  real_T Memory5_3_X0;                 /* Expression: 0
                                        * Referenced by: '<S16>/Memory5'
                                        */
  real_T DigitalIn_P1_Size[2];         /* Computed Parameter: DigitalIn_P1_Size
                                        * Referenced by: '<S311>/DigitalIn'
                                        */
  real_T DigitalIn_P1[6];              /* Computed Parameter: DigitalIn_P1
                                        * Referenced by: '<S311>/DigitalIn'
                                        */
  real_T DigitalIn_P2_Size[2];         /* Computed Parameter: DigitalIn_P2_Size
                                        * Referenced by: '<S311>/DigitalIn'
                                        */
  real_T DigitalIn_P3_Size[2];         /* Computed Parameter: DigitalIn_P3_Size
                                        * Referenced by: '<S311>/DigitalIn'
                                        */
  real_T DigitalIn_P3;                 /* Expression: sampleTime
                                        * Referenced by: '<S311>/DigitalIn'
                                        */
  real_T DigitalIn_P4_Size[2];         /* Computed Parameter: DigitalIn_P4_Size
                                        * Referenced by: '<S311>/DigitalIn'
                                        */
  real_T DigitalIn_P4;                 /* Expression: portNb
                                        * Referenced by: '<S311>/DigitalIn'
                                        */
  real_T DigitalIn_P5_Size[2];         /* Computed Parameter: DigitalIn_P5_Size
                                        * Referenced by: '<S311>/DigitalIn'
                                        */
  real_T DigitalIn_P5;                 /* Expression: size
                                        * Referenced by: '<S311>/DigitalIn'
                                        */
  real_T DigitalIn_P6_Size[2];         /* Computed Parameter: DigitalIn_P6_Size
                                        * Referenced by: '<S311>/DigitalIn'
                                        */
  real_T DigitalIn_P6;                 /* Expression: numchan
                                        * Referenced by: '<S311>/DigitalIn'
                                        */
  real_T DigitalIn_P7_Size[2];         /* Computed Parameter: DigitalIn_P7_Size
                                        * Referenced by: '<S311>/DigitalIn'
                                        */
  real_T DigitalIn_P7;                 /* Expression: maxcount
                                        * Referenced by: '<S311>/DigitalIn'
                                        */
  real_T EventDetector_P1_Size[2];     /* Computed Parameter: EventDetector_P1_Size
                                        * Referenced by: '<S315>/EventDetector'
                                        */
  real_T EventDetector_P1[6];          /* Computed Parameter: EventDetector_P1
                                        * Referenced by: '<S315>/EventDetector'
                                        */
  real_T EventDetector_P2_Size[2];     /* Computed Parameter: EventDetector_P2_Size
                                        * Referenced by: '<S315>/EventDetector'
                                        */
  real_T EventDetector_P3_Size[2];     /* Computed Parameter: EventDetector_P3_Size
                                        * Referenced by: '<S315>/EventDetector'
                                        */
  real_T EventDetector_P3;             /* Expression: sampleTime
                                        * Referenced by: '<S315>/EventDetector'
                                        */
  real_T EventDetector_P4_Size[2];     /* Computed Parameter: EventDetector_P4_Size
                                        * Referenced by: '<S315>/EventDetector'
                                        */
  real_T EventDetector_P4;             /* Expression: portNb
                                        * Referenced by: '<S315>/EventDetector'
                                        */
  real_T EventDetector_P5_Size[2];     /* Computed Parameter: EventDetector_P5_Size
                                        * Referenced by: '<S315>/EventDetector'
                                        */
  real_T EventDetector_P5;             /* Expression: size
                                        * Referenced by: '<S315>/EventDetector'
                                        */
  real_T EventDetector_P6_Size[2];     /* Computed Parameter: EventDetector_P6_Size
                                        * Referenced by: '<S315>/EventDetector'
                                        */
  real_T EventDetector_P6;             /* Expression: nbChannels
                                        * Referenced by: '<S315>/EventDetector'
                                        */
  real_T EventDetector_P7_Size[2];     /* Computed Parameter: EventDetector_P7_Size
                                        * Referenced by: '<S315>/EventDetector'
                                        */
  real_T EventDetector_P7;             /* Expression: numwidth
                                        * Referenced by: '<S315>/EventDetector'
                                        */
  real_T EventDetector_P8_Size[2];     /* Computed Parameter: EventDetector_P8_Size
                                        * Referenced by: '<S315>/EventDetector'
                                        */
  real_T EventDetector_P8;             /* Expression: timeUnit
                                        * Referenced by: '<S315>/EventDetector'
                                        */
  real_T EventDetector_P9_Size[2];     /* Computed Parameter: EventDetector_P9_Size
                                        * Referenced by: '<S315>/EventDetector'
                                        */
  real_T EventDetector_P9;             /* Expression: maxcount
                                        * Referenced by: '<S315>/EventDetector'
                                        */
  real_T EventDetector1_P1_Size[2];    /* Computed Parameter: EventDetector1_P1_Size
                                        * Referenced by: '<S315>/EventDetector1'
                                        */
  real_T EventDetector1_P1[6];         /* Computed Parameter: EventDetector1_P1
                                        * Referenced by: '<S315>/EventDetector1'
                                        */
  real_T EventDetector1_P2_Size[2];    /* Computed Parameter: EventDetector1_P2_Size
                                        * Referenced by: '<S315>/EventDetector1'
                                        */
  real_T EventDetector1_P3_Size[2];    /* Computed Parameter: EventDetector1_P3_Size
                                        * Referenced by: '<S315>/EventDetector1'
                                        */
  real_T EventDetector1_P3;            /* Expression: sampleTime
                                        * Referenced by: '<S315>/EventDetector1'
                                        */
  real_T EventDetector1_P4_Size[2];    /* Computed Parameter: EventDetector1_P4_Size
                                        * Referenced by: '<S315>/EventDetector1'
                                        */
  real_T EventDetector1_P4;            /* Expression: portNb
                                        * Referenced by: '<S315>/EventDetector1'
                                        */
  real_T EventDetector1_P5_Size[2];    /* Computed Parameter: EventDetector1_P5_Size
                                        * Referenced by: '<S315>/EventDetector1'
                                        */
  real_T EventDetector1_P5;            /* Expression: size
                                        * Referenced by: '<S315>/EventDetector1'
                                        */
  real_T EventDetector1_P6_Size[2];    /* Computed Parameter: EventDetector1_P6_Size
                                        * Referenced by: '<S315>/EventDetector1'
                                        */
  real_T EventDetector1_P6;            /* Expression: nbChannels
                                        * Referenced by: '<S315>/EventDetector1'
                                        */
  real_T EventDetector1_P7_Size[2];    /* Computed Parameter: EventDetector1_P7_Size
                                        * Referenced by: '<S315>/EventDetector1'
                                        */
  real_T EventDetector1_P7;            /* Expression: numwidth
                                        * Referenced by: '<S315>/EventDetector1'
                                        */
  real_T EventDetector1_P8_Size[2];    /* Computed Parameter: EventDetector1_P8_Size
                                        * Referenced by: '<S315>/EventDetector1'
                                        */
  real_T EventDetector1_P8;            /* Expression: timeUnit
                                        * Referenced by: '<S315>/EventDetector1'
                                        */
  real_T EventDetector1_P9_Size[2];    /* Computed Parameter: EventDetector1_P9_Size
                                        * Referenced by: '<S315>/EventDetector1'
                                        */
  real_T EventDetector1_P9;            /* Expression: maxcount
                                        * Referenced by: '<S315>/EventDetector1'
                                        */
  real_T PWMIn_P1_Size[2];             /* Computed Parameter: PWMIn_P1_Size
                                        * Referenced by: '<S314>/PWM In'
                                        */
  real_T PWMIn_P1[6];                  /* Computed Parameter: PWMIn_P1
                                        * Referenced by: '<S314>/PWM In'
                                        */
  real_T PWMIn_P2_Size[2];             /* Computed Parameter: PWMIn_P2_Size
                                        * Referenced by: '<S314>/PWM In'
                                        */
  real_T PWMIn_P3_Size[2];             /* Computed Parameter: PWMIn_P3_Size
                                        * Referenced by: '<S314>/PWM In'
                                        */
  real_T PWMIn_P3;                     /* Expression: sampleTime
                                        * Referenced by: '<S314>/PWM In'
                                        */
  real_T PWMIn_P4_Size[2];             /* Computed Parameter: PWMIn_P4_Size
                                        * Referenced by: '<S314>/PWM In'
                                        */
  real_T PWMIn_P4;                     /* Expression: portNb
                                        * Referenced by: '<S314>/PWM In'
                                        */
  real_T PWMIn_P5_Size[2];             /* Computed Parameter: PWMIn_P5_Size
                                        * Referenced by: '<S314>/PWM In'
                                        */
  real_T PWMIn_P5;                     /* Expression: numchan
                                        * Referenced by: '<S314>/PWM In'
                                        */
  real_T PWMIn_P6_Size[2];             /* Computed Parameter: PWMIn_P6_Size
                                        * Referenced by: '<S314>/PWM In'
                                        */
  real_T PWMIn_P6;                     /* Expression: maxCount
                                        * Referenced by: '<S314>/PWM In'
                                        */
  real_T PWMIn1_P1_Size[2];            /* Computed Parameter: PWMIn1_P1_Size
                                        * Referenced by: '<S314>/PWM In1'
                                        */
  real_T PWMIn1_P1[6];                 /* Computed Parameter: PWMIn1_P1
                                        * Referenced by: '<S314>/PWM In1'
                                        */
  real_T PWMIn1_P2_Size[2];            /* Computed Parameter: PWMIn1_P2_Size
                                        * Referenced by: '<S314>/PWM In1'
                                        */
  real_T PWMIn1_P3_Size[2];            /* Computed Parameter: PWMIn1_P3_Size
                                        * Referenced by: '<S314>/PWM In1'
                                        */
  real_T PWMIn1_P3;                    /* Expression: sampleTime
                                        * Referenced by: '<S314>/PWM In1'
                                        */
  real_T PWMIn1_P4_Size[2];            /* Computed Parameter: PWMIn1_P4_Size
                                        * Referenced by: '<S314>/PWM In1'
                                        */
  real_T PWMIn1_P4;                    /* Expression: portNb
                                        * Referenced by: '<S314>/PWM In1'
                                        */
  real_T PWMIn1_P5_Size[2];            /* Computed Parameter: PWMIn1_P5_Size
                                        * Referenced by: '<S314>/PWM In1'
                                        */
  real_T PWMIn1_P5;                    /* Expression: numchan
                                        * Referenced by: '<S314>/PWM In1'
                                        */
  real_T PWMIn1_P6_Size[2];            /* Computed Parameter: PWMIn1_P6_Size
                                        * Referenced by: '<S314>/PWM In1'
                                        */
  real_T PWMIn1_P6;                    /* Expression: maxCount
                                        * Referenced by: '<S314>/PWM In1'
                                        */
  real_T BreakAlgebraicLoop_InitialCondi;/* Expression: 0
                                          * Referenced by: '<S274>/Break Algebraic Loop'
                                          */
  real_T Constant_Value_o;             /* Expression: SIM_HIL
                                        * Referenced by: '<S264>/Constant'
                                        */
  real_T Switch_Threshold_l;           /* Expression: 0
                                        * Referenced by: '<S264>/Switch'
                                        */
  real_T PmIntegrator_gainval;         /* Computed Parameter: PmIntegrator_gainval
                                        * Referenced by: '<S275>/Pm- Integrator'
                                        */
  real_T PmIntegrator_IC;              /* Expression: .8/.000145
                                        * Referenced by: '<S275>/Pm- Integrator'
                                        */
  real_T PmIntegrator_UpperSat;        /* Expression: 400000
                                        * Referenced by: '<S275>/Pm- Integrator'
                                        */
  real_T PmIntegrator_LowerSat;        /* Expression: 0
                                        * Referenced by: '<S275>/Pm- Integrator'
                                        */
  real_T P0_Gain;                      /* Expression: 1/P0
                                        * Referenced by: '<S277>/1//P0'
                                        */
  real_T Force02_UpperSat;             /* Expression: inf
                                        * Referenced by: '<S277>/Force > 0 #2'
                                        */
  real_T Force02_LowerSat;             /* Expression: 0
                                        * Referenced by: '<S277>/Force > 0 #2'
                                        */
  real_T AnalogIn_P1_Size[2];          /* Computed Parameter: AnalogIn_P1_Size
                                        * Referenced by: '<S339>/AnalogIn'
                                        */
  real_T AnalogIn_P1[6];               /* Computed Parameter: AnalogIn_P1
                                        * Referenced by: '<S339>/AnalogIn'
                                        */
  real_T AnalogIn_P2_Size[2];          /* Computed Parameter: AnalogIn_P2_Size
                                        * Referenced by: '<S339>/AnalogIn'
                                        */
  real_T AnalogIn_P3_Size[2];          /* Computed Parameter: AnalogIn_P3_Size
                                        * Referenced by: '<S339>/AnalogIn'
                                        */
  real_T AnalogIn_P3;                  /* Expression: sampleTime
                                        * Referenced by: '<S339>/AnalogIn'
                                        */
  real_T AnalogIn_P4_Size[2];          /* Computed Parameter: AnalogIn_P4_Size
                                        * Referenced by: '<S339>/AnalogIn'
                                        */
  real_T AnalogIn_P4;                  /* Expression: portNb
                                        * Referenced by: '<S339>/AnalogIn'
                                        */
  real_T AnalogIn_P5_Size[2];          /* Computed Parameter: AnalogIn_P5_Size
                                        * Referenced by: '<S339>/AnalogIn'
                                        */
  real_T AnalogIn_P5;                  /* Expression: size
                                        * Referenced by: '<S339>/AnalogIn'
                                        */
  real_T AnalogIn_P6_Size[2];          /* Computed Parameter: AnalogIn_P6_Size
                                        * Referenced by: '<S339>/AnalogIn'
                                        */
  real_T AnalogIn_P6;                  /* Expression: numchan
                                        * Referenced by: '<S339>/AnalogIn'
                                        */
  real_T AnalogIn_P7_Size[2];          /* Computed Parameter: AnalogIn_P7_Size
                                        * Referenced by: '<S339>/AnalogIn'
                                        */
  real_T AnalogIn_P7;                  /* Expression: maxcount
                                        * Referenced by: '<S339>/AnalogIn'
                                        */
  real_T Constant2_Value_k;            /* Expression: 20
                                        * Referenced by: '<S316>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S316>/Constant3'
                                        */
  real_T GeneratedFilterBlock_InitialSta;/* Expression: 0
                                          * Referenced by: '<S340>/Generated Filter Block'
                                          */
  real_T GeneratedFilterBlock_Coefficien[15];/* Expression: [0.0069552863617617106 0.014587901014631248 -0.0057896483056441538 -0.056861876528372622 -0.059476680260783142 0.076118200884714562 0.29579154768342669 0.40638624201187618 0.29579154768342669 0.076118200884714562 -0.059476680260783142 -0.056861876528372622 -0.0057896483056441538 0.014587901014631248 0.0069552863617617106]
                                              * Referenced by: '<S340>/Generated Filter Block'
                                              */
  real_T SFunction_P1_Size_a[2];       /* Computed Parameter: SFunction_P1_Size_a
                                        * Referenced by: '<S342>/S-Function'
                                        */
  real_T SFunction_P1_jn;              /* Expression: Data_width
                                        * Referenced by: '<S342>/S-Function'
                                        */
  real_T SFunction_P2_Size_h[2];       /* Computed Parameter: SFunction_P2_Size_h
                                        * Referenced by: '<S342>/S-Function'
                                        */
  real_T SFunction_P2_lu[214];         /* Expression: InitialConditions
                                        * Referenced by: '<S342>/S-Function'
                                        */
  real_T Constant1_Value_g4;           /* Expression: 0
                                        * Referenced by: '<S316>/Constant1'
                                        */
  real_T Switch1_Threshold_k;          /* Expression: 0.5
                                        * Referenced by: '<S260>/Switch1'
                                        */
  real_T uRPMwhileTurning_Gain;        /* Expression: .044
                                        * Referenced by: '<S252>/80 RPM while "Turning"'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<S303>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: SM.tho
                                        * Referenced by: '<S303>/Discrete-Time Integrator1'
                                        */
  real_T web2_Gain;                    /* Expression: SM.web
                                        * Referenced by: '<S303>/web2'
                                        */
  real_T fluxes_InitialCondition[5];   /* Expression: SM.phiqd0
                                        * Referenced by: '<S294>/fluxes'
                                        */
  real_T Constant1_Value_l;            /* Expression: SM.Sat
                                        * Referenced by: '<S283>/Constant1'
                                        */
  real_T Constant3_Value_c;            /* Expression: SM.Sat
                                        * Referenced by: '<S283>/Constant3'
                                        */
  real_T Switch_Threshold_i;           /* Expression: 0.5
                                        * Referenced by: '<S283>/Switch'
                                        */
  real_T nomspeed_Value;               /* Expression: 1
                                        * Referenced by: '<S303>/nom. speed'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S303>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: SM.dwo
                                        * Referenced by: '<S303>/Discrete-Time Integrator'
                                        */
  real_T voltages_InitialCondition;    /* Expression: 0
                                        * Referenced by: '<S294>/voltages'
                                        */
  real_T IC_Threshold;                 /* Expression: Ts
                                        * Referenced by: '<S294>/IC'
                                        */
  real_T changeIqIdcurrentsigns_Gain[5];/* Expression: SM.IqdSign
                                         * Referenced by: '<S283>/change Iq Id  current signs'
                                         */
  real_T LaqLl_q_Gain[2];              /* Expression: SM.Laq*SM.One_Llq
                                        * Referenced by: '<S292>/Laq//Ll_q'
                                        */
  real_T LadLl_d_Gain[3];              /* Expression: [ SM.Lad/SM.Ll   SM.Lad/SM.Llfd   SM.Lad/SM.Llkd ]
                                        * Referenced by: '<S292>/Lad//Ll_d'
                                        */
  real_T SwitchCurrents_Value[17];     /* Expression: zeros(17,1)
                                        * Referenced by: '<S773>/SwitchCurrents'
                                        */
  real_T ib_Gain;                      /* Expression: SM.ib
                                        * Referenced by: '<S285>/ib'
                                        */
  real_T DC_Value;                     /* Expression: Amplitude
                                        * Referenced by: '<S356>/DC'
                                        */
  real_T DC_Value_d;                   /* Expression: Amplitude
                                        * Referenced by: '<S359>/DC'
                                        */
  real_T DC_Value_p;                   /* Expression: Amplitude
                                        * Referenced by: '<S362>/DC'
                                        */
  real_T DC_Value_o;                   /* Expression: Amplitude
                                        * Referenced by: '<S372>/DC'
                                        */
  real_T DC_Value_n;                   /* Expression: Amplitude
                                        * Referenced by: '<S375>/DC'
                                        */
  real_T DC_Value_nu;                  /* Expression: Amplitude
                                        * Referenced by: '<S378>/DC'
                                        */
  real_T Memory1_X0_o;                 /* Expression: 0
                                        * Referenced by: '<S567>/Memory1'
                                        */
  real_T Memory2_X0_kt;                /* Expression: 0
                                        * Referenced by: '<S567>/Memory2'
                                        */
  real_T Constant_Value_g;             /* Expression: 1000
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant1_Value_c;            /* Expression: 500
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S565>/Integrator'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S565>/Integrator'
                                        */
  real_T DerivativeGain_Gain;          /* Expression: D
                                        * Referenced by: '<S565>/Derivative Gain'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S565>/Filter'
                                        */
  real_T Filter_IC;                    /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S565>/Filter'
                                        */
  real_T FilterCoefficient_Gain;       /* Expression: N
                                        * Referenced by: '<S565>/Filter Coefficient'
                                        */
  real_T Integrator_gainval_p;         /* Computed Parameter: Integrator_gainval_p
                                        * Referenced by: '<S566>/Integrator'
                                        */
  real_T Integrator_IC_c;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S566>/Integrator'
                                        */
  real_T DerivativeGain_Gain_f;        /* Expression: D
                                        * Referenced by: '<S566>/Derivative Gain'
                                        */
  real_T Filter_gainval_k;             /* Computed Parameter: Filter_gainval_k
                                        * Referenced by: '<S566>/Filter'
                                        */
  real_T Filter_IC_i;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S566>/Filter'
                                        */
  real_T FilterCoefficient_Gain_o;     /* Expression: N
                                        * Referenced by: '<S566>/Filter Coefficient'
                                        */
  real_T DiscreteTimeIntegrator_gainva_f;/* Computed Parameter: DiscreteTimeIntegrator_gainva_f
                                          * Referenced by: '<S613>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_d;  /* Expression: sps.Phase_Init*pi/180
                                        * Referenced by: '<S613>/Discrete-Time Integrator'
                                        */
  real_T Constant4_Value_d;            /* Expression: 2*pi
                                        * Referenced by: '<S613>/Constant4'
                                        */
  real_T Memory1_X0_b;                 /* Expression: 0
                                        * Referenced by: '<S456>/Memory1'
                                        */
  real_T Memory2_X0_d;                 /* Expression: 0
                                        * Referenced by: '<S456>/Memory2'
                                        */
  real_T Constant2_Value_p;            /* Expression: 1000
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real_T Constant3_Value_e;            /* Expression: 500
                                        * Referenced by: '<S3>/Constant3'
                                        */
  real_T Integrator_gainval_f;         /* Computed Parameter: Integrator_gainval_f
                                        * Referenced by: '<S454>/Integrator'
                                        */
  real_T Integrator_IC_k;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S454>/Integrator'
                                        */
  real_T DerivativeGain_Gain_g;        /* Expression: D
                                        * Referenced by: '<S454>/Derivative Gain'
                                        */
  real_T Filter_gainval_b;             /* Computed Parameter: Filter_gainval_b
                                        * Referenced by: '<S454>/Filter'
                                        */
  real_T Filter_IC_k;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S454>/Filter'
                                        */
  real_T FilterCoefficient_Gain_n;     /* Expression: N
                                        * Referenced by: '<S454>/Filter Coefficient'
                                        */
  real_T Integrator_gainval_d;         /* Computed Parameter: Integrator_gainval_d
                                        * Referenced by: '<S455>/Integrator'
                                        */
  real_T Integrator_IC_d;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S455>/Integrator'
                                        */
  real_T DerivativeGain_Gain_p;        /* Expression: D
                                        * Referenced by: '<S455>/Derivative Gain'
                                        */
  real_T Filter_gainval_g;             /* Computed Parameter: Filter_gainval_g
                                        * Referenced by: '<S455>/Filter'
                                        */
  real_T Filter_IC_m;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S455>/Filter'
                                        */
  real_T FilterCoefficient_Gain_h;     /* Expression: N
                                        * Referenced by: '<S455>/Filter Coefficient'
                                        */
  real_T DiscreteTimeIntegrator_gainva_a;/* Computed Parameter: DiscreteTimeIntegrator_gainva_a
                                          * Referenced by: '<S502>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_a;  /* Expression: sps.Phase_Init*pi/180
                                        * Referenced by: '<S502>/Discrete-Time Integrator'
                                        */
  real_T Constant4_Value_h;            /* Expression: 2*pi
                                        * Referenced by: '<S502>/Constant4'
                                        */
  real_T SineWaveA_Amp;                /* Expression: Amplitude
                                        * Referenced by: '<S248>/Sine Wave A'
                                        */
  real_T SineWaveA_Bias;               /* Expression: 0
                                        * Referenced by: '<S248>/Sine Wave A'
                                        */
  real_T SineWaveA_Freq;               /* Expression: 2*pi*Frequency
                                        * Referenced by: '<S248>/Sine Wave A'
                                        */
  real_T SineWaveA_Hsin;               /* Computed Parameter: SineWaveA_Hsin
                                        * Referenced by: '<S248>/Sine Wave A'
                                        */
  real_T SineWaveA_HCos;               /* Computed Parameter: SineWaveA_HCos
                                        * Referenced by: '<S248>/Sine Wave A'
                                        */
  real_T SineWaveA_PSin;               /* Computed Parameter: SineWaveA_PSin
                                        * Referenced by: '<S248>/Sine Wave A'
                                        */
  real_T SineWaveA_PCos;               /* Computed Parameter: SineWaveA_PCos
                                        * Referenced by: '<S248>/Sine Wave A'
                                        */
  real_T SineWaveB_Amp;                /* Expression: Amplitude
                                        * Referenced by: '<S248>/Sine Wave B'
                                        */
  real_T SineWaveB_Bias;               /* Expression: 0
                                        * Referenced by: '<S248>/Sine Wave B'
                                        */
  real_T SineWaveB_Freq;               /* Expression: 2*pi*Frequency
                                        * Referenced by: '<S248>/Sine Wave B'
                                        */
  real_T SineWaveB_Hsin;               /* Computed Parameter: SineWaveB_Hsin
                                        * Referenced by: '<S248>/Sine Wave B'
                                        */
  real_T SineWaveB_HCos;               /* Computed Parameter: SineWaveB_HCos
                                        * Referenced by: '<S248>/Sine Wave B'
                                        */
  real_T SineWaveB_PSin;               /* Computed Parameter: SineWaveB_PSin
                                        * Referenced by: '<S248>/Sine Wave B'
                                        */
  real_T SineWaveB_PCos;               /* Computed Parameter: SineWaveB_PCos
                                        * Referenced by: '<S248>/Sine Wave B'
                                        */
  real_T SineWaveC_Amp;                /* Expression: Amplitude
                                        * Referenced by: '<S248>/Sine Wave C'
                                        */
  real_T SineWaveC_Bias;               /* Expression: 0
                                        * Referenced by: '<S248>/Sine Wave C'
                                        */
  real_T SineWaveC_Freq;               /* Expression: 2*pi*Frequency
                                        * Referenced by: '<S248>/Sine Wave C'
                                        */
  real_T SineWaveC_Hsin;               /* Computed Parameter: SineWaveC_Hsin
                                        * Referenced by: '<S248>/Sine Wave C'
                                        */
  real_T SineWaveC_HCos;               /* Computed Parameter: SineWaveC_HCos
                                        * Referenced by: '<S248>/Sine Wave C'
                                        */
  real_T SineWaveC_PSin;               /* Computed Parameter: SineWaveC_PSin
                                        * Referenced by: '<S248>/Sine Wave C'
                                        */
  real_T SineWaveC_PCos;               /* Computed Parameter: SineWaveC_PCos
                                        * Referenced by: '<S248>/Sine Wave C'
                                        */
  real_T UnitDelay_InitialCondition_k4;/* Expression: 0
                                        * Referenced by: '<S22>/Unit Delay'
                                        */
  real_T triggerFAULT_Gain;            /* Expression: 1
                                        * Referenced by: '<S3>/triggerFAULT'
                                        */
  real_T Constant_Value_e;             /* Expression: const
                                        * Referenced by: '<S677>/Constant'
                                        */
  real_T C4_Value;                     /* Expression: BR.com
                                        * Referenced by: '<S683>/C4'
                                        */
  real_T LookUpTable_XData[7];         /* Expression: tv
                                        * Referenced by: '<S684>/Look-Up Table'
                                        */
  real_T LookUpTable_YData[7];         /* Expression: opv
                                        * Referenced by: '<S684>/Look-Up Table'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S683>/Switch3'
                                        */
  real_T C4_Value_i;                   /* Expression: BR.com
                                        * Referenced by: '<S688>/C4'
                                        */
  real_T LookUpTable_XData_e[7];       /* Expression: tv
                                        * Referenced by: '<S689>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_p[7];       /* Expression: opv
                                        * Referenced by: '<S689>/Look-Up Table'
                                        */
  real_T Switch3_Threshold_c;          /* Expression: 0.5
                                        * Referenced by: '<S688>/Switch3'
                                        */
  real_T C4_Value_f;                   /* Expression: BR.com
                                        * Referenced by: '<S693>/C4'
                                        */
  real_T LookUpTable_XData_n[7];       /* Expression: tv
                                        * Referenced by: '<S694>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_f[7];       /* Expression: opv
                                        * Referenced by: '<S694>/Look-Up Table'
                                        */
  real_T Switch3_Threshold_n;          /* Expression: 0.5
                                        * Referenced by: '<S693>/Switch3'
                                        */
  real_T C4_Value_b;                   /* Expression: BR.com
                                        * Referenced by: '<S698>/C4'
                                        */
  real_T LookUpTable_XData_b[7];       /* Expression: tv
                                        * Referenced by: '<S699>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_m[7];       /* Expression: opv
                                        * Referenced by: '<S699>/Look-Up Table'
                                        */
  real_T Switch3_Threshold_f;          /* Expression: 0.5
                                        * Referenced by: '<S698>/Switch3'
                                        */
  real_T Constant_Value_nns;           /* Expression: const
                                        * Referenced by: '<S706>/Constant'
                                        */
  real_T C4_Value_p;                   /* Expression: BR.com
                                        * Referenced by: '<S712>/C4'
                                        */
  real_T LookUpTable_XData_l[7];       /* Expression: tv
                                        * Referenced by: '<S713>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_d[7];       /* Expression: opv
                                        * Referenced by: '<S713>/Look-Up Table'
                                        */
  real_T Switch3_Threshold_a;          /* Expression: 0.5
                                        * Referenced by: '<S712>/Switch3'
                                        */
  real_T C4_Value_k;                   /* Expression: BR.com
                                        * Referenced by: '<S717>/C4'
                                        */
  real_T LookUpTable_XData_nn[7];      /* Expression: tv
                                        * Referenced by: '<S718>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_h[7];       /* Expression: opv
                                        * Referenced by: '<S718>/Look-Up Table'
                                        */
  real_T Switch3_Threshold_ac;         /* Expression: 0.5
                                        * Referenced by: '<S717>/Switch3'
                                        */
  real_T C4_Value_c;                   /* Expression: BR.com
                                        * Referenced by: '<S722>/C4'
                                        */
  real_T LookUpTable_XData_m[7];       /* Expression: tv
                                        * Referenced by: '<S723>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_g[7];       /* Expression: opv
                                        * Referenced by: '<S723>/Look-Up Table'
                                        */
  real_T Switch3_Threshold_i;          /* Expression: 0.5
                                        * Referenced by: '<S722>/Switch3'
                                        */
  real_T C4_Value_bb;                  /* Expression: BR.com
                                        * Referenced by: '<S727>/C4'
                                        */
  real_T LookUpTable_XData_f[7];       /* Expression: tv
                                        * Referenced by: '<S728>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_mj[7];      /* Expression: opv
                                        * Referenced by: '<S728>/Look-Up Table'
                                        */
  real_T Switch3_Threshold_d;          /* Expression: 0.5
                                        * Referenced by: '<S727>/Switch3'
                                        */
  real_T DigitalInfromSEL751_P1_Size[2];/* Computed Parameter: DigitalInfromSEL751_P1_Size
                                         * Referenced by: '<S3>/DigitalIn from SEL-751'
                                         */
  real_T DigitalInfromSEL751_P1[6];    /* Computed Parameter: DigitalInfromSEL751_P1
                                        * Referenced by: '<S3>/DigitalIn from SEL-751'
                                        */
  real_T DigitalInfromSEL751_P2_Size[2];/* Computed Parameter: DigitalInfromSEL751_P2_Size
                                         * Referenced by: '<S3>/DigitalIn from SEL-751'
                                         */
  real_T DigitalInfromSEL751_P3_Size[2];/* Computed Parameter: DigitalInfromSEL751_P3_Size
                                         * Referenced by: '<S3>/DigitalIn from SEL-751'
                                         */
  real_T DigitalInfromSEL751_P3;       /* Expression: sampleTime
                                        * Referenced by: '<S3>/DigitalIn from SEL-751'
                                        */
  real_T DigitalInfromSEL751_P4_Size[2];/* Computed Parameter: DigitalInfromSEL751_P4_Size
                                         * Referenced by: '<S3>/DigitalIn from SEL-751'
                                         */
  real_T DigitalInfromSEL751_P4;       /* Expression: portNb
                                        * Referenced by: '<S3>/DigitalIn from SEL-751'
                                        */
  real_T DigitalInfromSEL751_P5_Size[2];/* Computed Parameter: DigitalInfromSEL751_P5_Size
                                         * Referenced by: '<S3>/DigitalIn from SEL-751'
                                         */
  real_T DigitalInfromSEL751_P5;       /* Expression: size
                                        * Referenced by: '<S3>/DigitalIn from SEL-751'
                                        */
  real_T DigitalInfromSEL751_P6_Size[2];/* Computed Parameter: DigitalInfromSEL751_P6_Size
                                         * Referenced by: '<S3>/DigitalIn from SEL-751'
                                         */
  real_T DigitalInfromSEL751_P6;       /* Expression: numchan
                                        * Referenced by: '<S3>/DigitalIn from SEL-751'
                                        */
  real_T DigitalInfromSEL751_P7_Size[2];/* Computed Parameter: DigitalInfromSEL751_P7_Size
                                         * Referenced by: '<S3>/DigitalIn from SEL-751'
                                         */
  real_T DigitalInfromSEL751_P7;       /* Expression: maxcount
                                        * Referenced by: '<S3>/DigitalIn from SEL-751'
                                        */
  real_T C4_Value_a;                   /* Expression: External
                                        * Referenced by: '<S27>/C4'
                                        */
  real_T LookUpTable_XData_j[7];       /* Expression: tv
                                        * Referenced by: '<S98>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_k[7];       /* Expression: opv
                                        * Referenced by: '<S98>/Look-Up Table'
                                        */
  real_T Switch3_Threshold_i4;         /* Expression: 0.5
                                        * Referenced by: '<S27>/Switch3'
                                        */
  real_T Constant1_Value_o;            /* Expression: SwitchA
                                        * Referenced by: '<S27>/Constant1'
                                        */
  real_T Constant5_Value_d;            /* Expression: InitialState
                                        * Referenced by: '<S27>/Constant5'
                                        */
  real_T Switch_Threshold_jw;          /* Expression: 0.5
                                        * Referenced by: '<S27>/Switch'
                                        */
  real_T C4_Value_h;                   /* Expression: BR.com
                                        * Referenced by: '<S84>/C4'
                                        */
  real_T LookUpTable_XData_ec[7];      /* Expression: tv
                                        * Referenced by: '<S85>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_hl[7];      /* Expression: opv
                                        * Referenced by: '<S85>/Look-Up Table'
                                        */
  real_T Switch3_Threshold_a0;         /* Expression: 0.5
                                        * Referenced by: '<S84>/Switch3'
                                        */
  real_T Constant2_Value_m;            /* Expression: SwitchB
                                        * Referenced by: '<S27>/Constant2'
                                        */
  real_T Switch1_Threshold_f;          /* Expression: 0.5
                                        * Referenced by: '<S27>/Switch1'
                                        */
  real_T C4_Value_p5;                  /* Expression: BR.com
                                        * Referenced by: '<S89>/C4'
                                        */
  real_T LookUpTable_XData_e4[7];      /* Expression: tv
                                        * Referenced by: '<S90>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_a[7];       /* Expression: opv
                                        * Referenced by: '<S90>/Look-Up Table'
                                        */
  real_T Switch3_Threshold_o;          /* Expression: 0.5
                                        * Referenced by: '<S89>/Switch3'
                                        */
  real_T Constant3_Value_a;            /* Expression: SwitchC
                                        * Referenced by: '<S27>/Constant3'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S27>/Switch2'
                                        */
  real_T C4_Value_hl;                  /* Expression: BR.com
                                        * Referenced by: '<S94>/C4'
                                        */
  real_T LookUpTable_XData_d[7];       /* Expression: tv
                                        * Referenced by: '<S95>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_ph[7];      /* Expression: opv
                                        * Referenced by: '<S95>/Look-Up Table'
                                        */
  real_T Switch3_Threshold_l;          /* Expression: 0.5
                                        * Referenced by: '<S94>/Switch3'
                                        */
  real_T SFunction_P1_Size_ja[2];      /* Computed Parameter: SFunction_P1_Size_ja
                                        * Referenced by: '<S768>/S-Function'
                                        */
  real_T SFunction_P1_n;               /* Expression: src
                                        * Referenced by: '<S768>/S-Function'
                                        */
  real_T SFunction_P2_Size_kj[2];      /* Computed Parameter: SFunction_P2_Size_kj
                                        * Referenced by: '<S768>/S-Function'
                                        */
  real_T SFunction_P2_lq;              /* Expression: Data_width
                                        * Referenced by: '<S768>/S-Function'
                                        */
  real_T SFunction_P3_Size_h[2];       /* Computed Parameter: SFunction_P3_Size_h
                                        * Referenced by: '<S768>/S-Function'
                                        */
  real_T SFunction_P3_ci;              /* Expression: st
                                        * Referenced by: '<S768>/S-Function'
                                        */
  real_T C4_Value_l;                   /* Expression: External
                                        * Referenced by: '<S101>/C4'
                                        */
  real_T LookUpTable_XData_mp[7];      /* Expression: tv
                                        * Referenced by: '<S172>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_mm[7];      /* Expression: opv
                                        * Referenced by: '<S172>/Look-Up Table'
                                        */
  real_T Switch3_Threshold_e;          /* Expression: 0.5
                                        * Referenced by: '<S101>/Switch3'
                                        */
  real_T Constant1_Value_d;            /* Expression: SwitchA
                                        * Referenced by: '<S101>/Constant1'
                                        */
  real_T Constant5_Value_m;            /* Expression: InitialState
                                        * Referenced by: '<S101>/Constant5'
                                        */
  real_T Switch_Threshold_n;           /* Expression: 0.5
                                        * Referenced by: '<S101>/Switch'
                                        */
  real_T C4_Value_ag;                  /* Expression: BR.com
                                        * Referenced by: '<S158>/C4'
                                        */
  real_T LookUpTable_XData_fi[7];      /* Expression: tv
                                        * Referenced by: '<S159>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_i[7];       /* Expression: opv
                                        * Referenced by: '<S159>/Look-Up Table'
                                        */
  real_T Switch3_Threshold_av;         /* Expression: 0.5
                                        * Referenced by: '<S158>/Switch3'
                                        */
  real_T Constant2_Value_a;            /* Expression: SwitchB
                                        * Referenced by: '<S101>/Constant2'
                                        */
  real_T Switch1_Threshold_l;          /* Expression: 0.5
                                        * Referenced by: '<S101>/Switch1'
                                        */
  real_T C4_Value_bv;                  /* Expression: BR.com
                                        * Referenced by: '<S163>/C4'
                                        */
  real_T LookUpTable_XData_na[7];      /* Expression: tv
                                        * Referenced by: '<S164>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_df[7];      /* Expression: opv
                                        * Referenced by: '<S164>/Look-Up Table'
                                        */
  real_T Switch3_Threshold_p;          /* Expression: 0.5
                                        * Referenced by: '<S163>/Switch3'
                                        */
  real_T Constant3_Value_k;            /* Expression: SwitchC
                                        * Referenced by: '<S101>/Constant3'
                                        */
  real_T Switch2_Threshold_g;          /* Expression: 0.5
                                        * Referenced by: '<S101>/Switch2'
                                        */
  real_T C4_Value_ci;                  /* Expression: BR.com
                                        * Referenced by: '<S168>/C4'
                                        */
  real_T LookUpTable_XData_p[7];       /* Expression: tv
                                        * Referenced by: '<S169>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_pb[7];      /* Expression: opv
                                        * Referenced by: '<S169>/Look-Up Table'
                                        */
  real_T Switch3_Threshold_g;          /* Expression: 0.5
                                        * Referenced by: '<S168>/Switch3'
                                        */
  real_T Constant_Value_oz;            /* Expression: 0
                                        * Referenced by: '<S319>/Constant'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S320>/Constant'
                                        */
  real_T Constant_Value_c2;            /* Expression: 0
                                        * Referenced by: '<S325>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S312>/Constant'
                                        */
  real_T C4_Value_c2;                  /* Expression: External
                                        * Referenced by: '<S175>/C4'
                                        */
  real_T LookUpTable_XData_i[7];       /* Expression: tv
                                        * Referenced by: '<S246>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_is[7];      /* Expression: opv
                                        * Referenced by: '<S246>/Look-Up Table'
                                        */
  real_T Switch3_Threshold_a4;         /* Expression: 0.5
                                        * Referenced by: '<S175>/Switch3'
                                        */
  real_T Constant1_Value_cj;           /* Expression: SwitchA
                                        * Referenced by: '<S175>/Constant1'
                                        */
  real_T Constant5_Value_b;            /* Expression: InitialState
                                        * Referenced by: '<S175>/Constant5'
                                        */
  real_T Switch_Threshold_f;           /* Expression: 0.5
                                        * Referenced by: '<S175>/Switch'
                                        */
  real_T C4_Value_b1;                  /* Expression: BR.com
                                        * Referenced by: '<S232>/C4'
                                        */
  real_T LookUpTable_XData_bz[7];      /* Expression: tv
                                        * Referenced by: '<S233>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_gy[7];      /* Expression: opv
                                        * Referenced by: '<S233>/Look-Up Table'
                                        */
  real_T Switch3_Threshold_oc;         /* Expression: 0.5
                                        * Referenced by: '<S232>/Switch3'
                                        */
  real_T Constant2_Value_n;            /* Expression: SwitchB
                                        * Referenced by: '<S175>/Constant2'
                                        */
  real_T Switch1_Threshold_i;          /* Expression: 0.5
                                        * Referenced by: '<S175>/Switch1'
                                        */
  real_T C4_Value_n;                   /* Expression: BR.com
                                        * Referenced by: '<S237>/C4'
                                        */
  real_T LookUpTable_XData_bf[7];      /* Expression: tv
                                        * Referenced by: '<S238>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_o[7];       /* Expression: opv
                                        * Referenced by: '<S238>/Look-Up Table'
                                        */
  real_T Switch3_Threshold_h;          /* Expression: 0.5
                                        * Referenced by: '<S237>/Switch3'
                                        */
  real_T Constant3_Value_a5;           /* Expression: SwitchC
                                        * Referenced by: '<S175>/Constant3'
                                        */
  real_T Switch2_Threshold_j;          /* Expression: 0.5
                                        * Referenced by: '<S175>/Switch2'
                                        */
  real_T C4_Value_d;                   /* Expression: BR.com
                                        * Referenced by: '<S242>/C4'
                                        */
  real_T LookUpTable_XData_io[7];      /* Expression: tv
                                        * Referenced by: '<S243>/Look-Up Table'
                                        */
  real_T LookUpTable_YData_g5[7];      /* Expression: opv
                                        * Referenced by: '<S243>/Look-Up Table'
                                        */
  real_T Switch3_Threshold_lr;         /* Expression: 0.5
                                        * Referenced by: '<S242>/Switch3'
                                        */
  real_T StateSpace_P1_Size[2];        /* Computed Parameter: StateSpace_P1_Size
                                        * Referenced by: '<S771>/State-Space'
                                        */
  real_T StateSpace_P1;                /* Expression: 0
                                        * Referenced by: '<S771>/State-Space'
                                        */
  real_T StateSpace_P2_Size[2];        /* Computed Parameter: StateSpace_P2_Size
                                        * Referenced by: '<S771>/State-Space'
                                        */
  real_T StateSpace_P2;                /* Expression: 0
                                        * Referenced by: '<S771>/State-Space'
                                        */
  real_T _Vb_Gain;                     /* Expression: 1/SM.Vb
                                        * Referenced by: '<S284>/1_Vb'
                                        */
  real_T Constant5_Value_l;            /* Expression: SM.Sat
                                        * Referenced by: '<S283>/Constant5'
                                        */
  real_T Switch2_Threshold_k;          /* Expression: 0.5
                                        * Referenced by: '<S283>/Switch2'
                                        */
  real_T Gain_Gain_k0;                 /* Expression: 180/pi
                                        * Referenced by: '<S289>/Gain'
                                        */
  real_T Gain_Gain_h;                  /* Expression: SM.Gain1
                                        * Referenced by: '<S287>/Gain'
                                        */
  real_T Gain1_Gain_a;                 /* Expression: SM.Gain1
                                        * Referenced by: '<S287>/Gain1'
                                        */
  real_T outputformatting_Gain[18];    /* Expression: [SM.Ib2*ones(1,5),SM.N2,SM.Ib2,SM.Ib2,SM.Ib2,SM.phib,SM.phib,SM.Vb2,SM.Vb2,(SM.phib/SM.Ib2)*ones(1,2),1,1,1]
                                        * Referenced by: '<S282>/output formatting'
                                        */
  real_T ProportionalGain_Gain_c;      /* Expression: P
                                        * Referenced by: '<S306>/Proportional Gain'
                                        */
  real_T Integrator_gainval_h;         /* Computed Parameter: Integrator_gainval_h
                                        * Referenced by: '<S306>/Integrator'
                                        */
  real_T Integrator_IC_e;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S306>/Integrator'
                                        */
  real_T DerivativeGain_Gain_e;        /* Expression: D
                                        * Referenced by: '<S306>/Derivative Gain'
                                        */
  real_T Filter_gainval_h;             /* Computed Parameter: Filter_gainval_h
                                        * Referenced by: '<S306>/Filter'
                                        */
  real_T Filter_IC_p;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S306>/Filter'
                                        */
  real_T FilterCoefficient_Gain_i;     /* Expression: N
                                        * Referenced by: '<S306>/Filter Coefficient'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: UpperSaturationLimit
                                        * Referenced by: '<S306>/Saturation'
                                        */
  real_T Saturation_LowerSat_m;        /* Expression: LowerSaturationLimit
                                        * Referenced by: '<S306>/Saturation'
                                        */
  real_T ProportionalGain_Gain_m;      /* Expression: P
                                        * Referenced by: '<S307>/Proportional Gain'
                                        */
  real_T Integrator_gainval_m;         /* Computed Parameter: Integrator_gainval_m
                                        * Referenced by: '<S307>/Integrator'
                                        */
  real_T Integrator_IC_c1;             /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S307>/Integrator'
                                        */
  real_T DerivativeGain_Gain_f2;       /* Expression: D
                                        * Referenced by: '<S307>/Derivative Gain'
                                        */
  real_T Filter_gainval_e;             /* Computed Parameter: Filter_gainval_e
                                        * Referenced by: '<S307>/Filter'
                                        */
  real_T Filter_IC_h;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S307>/Filter'
                                        */
  real_T FilterCoefficient_Gain_c;     /* Expression: N
                                        * Referenced by: '<S307>/Filter Coefficient'
                                        */
  real_T Saturation_UpperSat_e;        /* Expression: UpperSaturationLimit
                                        * Referenced by: '<S307>/Saturation'
                                        */
  real_T Saturation_LowerSat_b;        /* Expression: LowerSaturationLimit
                                        * Referenced by: '<S307>/Saturation'
                                        */
  real_T ProportionalGain_Gain_n;      /* Expression: P
                                        * Referenced by: '<S308>/Proportional Gain'
                                        */
  real_T Integrator_gainval_c;         /* Computed Parameter: Integrator_gainval_c
                                        * Referenced by: '<S308>/Integrator'
                                        */
  real_T Integrator_IC_a;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S308>/Integrator'
                                        */
  real_T DerivativeGain_Gain_d;        /* Expression: D
                                        * Referenced by: '<S308>/Derivative Gain'
                                        */
  real_T Filter_gainval_bt;            /* Computed Parameter: Filter_gainval_bt
                                        * Referenced by: '<S308>/Filter'
                                        */
  real_T Filter_IC_j;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S308>/Filter'
                                        */
  real_T FilterCoefficient_Gain_e;     /* Expression: N
                                        * Referenced by: '<S308>/Filter Coefficient'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: UpperSaturationLimit
                                        * Referenced by: '<S308>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: LowerSaturationLimit
                                        * Referenced by: '<S308>/Saturation'
                                        */
  real_T Switch_Threshold_o;           /* Expression: 0.5
                                        * Referenced by: '<S252>/Switch'
                                        */
  real_T Switch1_Threshold_b;          /* Expression: 0.5
                                        * Referenced by: '<S252>/Switch1'
                                        */
  real_T Constant_Value_d;             /* Expression: 0
                                        * Referenced by: '<S252>/Constant'
                                        */
  real_T Switch2_Threshold_l;          /* Expression: 0.5
                                        * Referenced by: '<S252>/Switch2'
                                        */
  real_T RateLimiter_RisingLim;        /* Computed Parameter: RateLimiter_RisingLim
                                        * Referenced by: '<S252>/Rate Limiter'
                                        */
  real_T RateLimiter_FallingLim;       /* Computed Parameter: RateLimiter_FallingLim
                                        * Referenced by: '<S252>/Rate Limiter'
                                        */
  real_T RateLimiter_IC;               /* Expression: 0
                                        * Referenced by: '<S252>/Rate Limiter'
                                        */
  real_T units_Gain;                   /* Expression: SM.Nb
                                        * Referenced by: '<S303>/units'
                                        */
  real_T u_Gain[2];                    /* Expression: [1 -1]
                                        * Referenced by: '<S290>/1-1'
                                        */
  real_T units1_Gain;                  /* Expression: SM.Pb
                                        * Referenced by: '<S303>/units1'
                                        */
  real_T DiscreteTimeIntegrator2_gainval;/* Computed Parameter: DiscreteTimeIntegrator2_gainval
                                          * Referenced by: '<S303>/Discrete-Time Integrator2'
                                          */
  real_T DiscreteTimeIntegrator2_IC;   /* Expression: SM.tho
                                        * Referenced by: '<S303>/Discrete-Time Integrator2'
                                        */
  real_T theta_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<S303>/theta'
                                        */
  real_T units2_Gain;                  /* Expression: SM.Pb/SM.Nb
                                        * Referenced by: '<S303>/units2'
                                        */
  real_T ProportionalGain_Gain_p;      /* Expression: P
                                        * Referenced by: '<S276>/Proportional Gain'
                                        */
  real_T Integrator_gainval_n;         /* Computed Parameter: Integrator_gainval_n
                                        * Referenced by: '<S276>/Integrator'
                                        */
  real_T Integrator_IC_ki;             /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S276>/Integrator'
                                        */
  real_T Saturation_UpperSat_eh;       /* Expression: UpperSaturationLimit
                                        * Referenced by: '<S276>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: LowerSaturationLimit
                                        * Referenced by: '<S276>/Saturation'
                                        */
  real_T Force03_UpperSat;             /* Expression: 1
                                        * Referenced by: '<S277>/Force > 0 #3'
                                        */
  real_T Force03_LowerSat;             /* Expression: 0
                                        * Referenced by: '<S277>/Force > 0 #3'
                                        */
  real_T fIntegrator_gainval;          /* Computed Parameter: fIntegrator_gainval
                                        * Referenced by: '<S275>/f- Integrator '
                                        */
  real_T fIntegrator_IC;               /* Expression: 1/21
                                        * Referenced by: '<S275>/f- Integrator '
                                        */
  real_T fIntegrator_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S275>/f- Integrator '
                                        */
  real_T fIntegrator_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S275>/f- Integrator '
                                        */
  real_T Delay025seconds_Value;        /* Expression: 1/(90*Ts)
                                        * Referenced by: '<S274>/Delay 0.25 seconds'
                                        */
  real_T Preventdividebyzero_UpperSat; /* Expression: inf
                                        * Referenced by: '<S274>/Prevent divide by zero'
                                        */
  real_T Preventdividebyzero_LowerSat; /* Expression: .001
                                        * Referenced by: '<S274>/Prevent divide by zero'
                                        */
  real_T VariableIntegerDelay_InitialCon;/* Computed Parameter: VariableIntegerDelay_InitialCon
                                          * Referenced by: '<S274>/Variable Integer Delay'
                                          */
  real_T H_Gain;                       /* Expression: H
                                        * Referenced by: '<S274>/H'
                                        */
  real_T Dampingduetopumpinglosses_Gain;/* Expression: 100
                                         * Referenced by: '<S274>/Damping due to pumping losses'
                                         */
  real_T kWpu_Gain;                    /* Expression: 1/3500
                                        * Referenced by: '<S264>/kW-> pu'
                                        */
  real_T Powerlimit_UpperSat;          /* Expression: UPL
                                        * Referenced by: '<S264>/Power limit'
                                        */
  real_T Powerlimit_LowerSat;          /* Expression: LPL
                                        * Referenced by: '<S264>/Power limit'
                                        */
  real_T UnitDelay2_InitialCondition;  /* Expression: v0(2)
                                        * Referenced by: '<S263>/Unit Delay2'
                                        */
  real_T ProportionalGain_Gain_a;      /* Expression: P
                                        * Referenced by: '<S262>/Proportional Gain'
                                        */
  real_T Integrator_gainval_p5;        /* Computed Parameter: Integrator_gainval_p5
                                        * Referenced by: '<S262>/Integrator'
                                        */
  real_T Integrator_IC_m;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S262>/Integrator'
                                        */
  real_T DerivativeGain_Gain_a;        /* Expression: D
                                        * Referenced by: '<S262>/Derivative Gain'
                                        */
  real_T Filter_gainval_l;             /* Computed Parameter: Filter_gainval_l
                                        * Referenced by: '<S262>/Filter'
                                        */
  real_T Filter_IC_o;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S262>/Filter'
                                        */
  real_T FilterCoefficient_Gain_a;     /* Expression: N
                                        * Referenced by: '<S262>/Filter Coefficient'
                                        */
  real_T Saturation_UpperSat_m;        /* Expression: UpperSaturationLimit
                                        * Referenced by: '<S262>/Saturation'
                                        */
  real_T Saturation_LowerSat_l;        /* Expression: LowerSaturationLimit
                                        * Referenced by: '<S262>/Saturation'
                                        */
  real_T Switch3_Threshold_at;         /* Expression: 0.5
                                        * Referenced by: '<S252>/Switch3'
                                        */
  real_T RateLimiter1_RisingLim;       /* Computed Parameter: RateLimiter1_RisingLim
                                        * Referenced by: '<S252>/Rate Limiter1'
                                        */
  real_T RateLimiter1_FallingLim;      /* Computed Parameter: RateLimiter1_FallingLim
                                        * Referenced by: '<S252>/Rate Limiter1'
                                        */
  real_T RateLimiter1_IC;              /* Expression: 0
                                        * Referenced by: '<S252>/Rate Limiter1'
                                        */
  real_T Constant4_Value_g;            /* Expression: 0
                                        * Referenced by: '<S316>/Constant4'
                                        */
  real_T GeneratedFilterBlock_InitialS_i;/* Expression: 0
                                          * Referenced by: '<S341>/Generated Filter Block'
                                          */
  real_T GeneratedFilterBlock_Coeffici_h[15];/* Expression: [0.0069552863617617106 0.014587901014631248 -0.0057896483056441538 -0.056861876528372622 -0.059476680260783142 0.076118200884714562 0.29579154768342669 0.40638624201187618 0.29579154768342669 0.076118200884714562 -0.059476680260783142 -0.056861876528372622 -0.0057896483056441538 0.014587901014631248 0.0069552863617617106]
                                              * Referenced by: '<S341>/Generated Filter Block'
                                              */
  real_T Switch2_Threshold_o;          /* Expression: 0.5
                                        * Referenced by: '<S260>/Switch2'
                                        */
  real_T Memory5_X0_j;                 /* Expression: 0
                                        * Referenced by: '<S10>/Memory5'
                                        */
  real_T Memory1_X0_g;                 /* Expression: 0
                                        * Referenced by: '<S10>/Memory1'
                                        */
  real_T Memory2_X0_dj;                /* Expression: 0
                                        * Referenced by: '<S10>/Memory2'
                                        */
  real_T Memory3_X0_j;                 /* Expression: 0
                                        * Referenced by: '<S10>/Memory3'
                                        */
  real_T LoadThermalMass50degMBTU_gainva;/* Computed Parameter: LoadThermalMass50degMBTU_gainva
                                          * Referenced by: '<S249>/Load  Thermal  Mass 50 deg//MBTU'
                                          */
  real_T LoadThermalMass50degMBTU_IC;  /* Expression: 20
                                        * Referenced by: '<S249>/Load  Thermal  Mass 50 deg//MBTU'
                                        */
  real_T AF20_Gain;                    /* Expression: 1/21
                                        * Referenced by: '<S277>/A//F=20'
                                        */
  real_T kgseclbmhr1_Gain;             /* Expression: 1/.000126
                                        * Referenced by: '<S264>/kg//sec->lbm//hr1'
                                        */
  real_T lbmhrNm3hr_Gain;              /* Expression: 1/1.76
                                        * Referenced by: '<S264>/lbm//hr->Nm^3//hr'
                                        */
  real_T lbmofNOxperhourpershaftkW_Gain;/* Expression: .00473
                                         * Referenced by: '<S264>/lbm of NOx per hour per shaft kW'
                                         */
  real_T CH4CO2_Gain;                  /* Expression: 2.75
                                        * Referenced by: '<S264>/CH4->CO2'
                                        */
  real_T RemoveAlgebraicLoop1_InitialCon;/* Expression: 0
                                          * Referenced by: '<S249>/Remove Algebraic Loop1'
                                          */
  real_T RemoveAlgebraicLoop_InitialCond;/* Expression: 0
                                          * Referenced by: '<S249>/Remove Algebraic Loop'
                                          */
  real_T SFunction_P1_Size_h[2];       /* Computed Parameter: SFunction_P1_Size_h
                                        * Referenced by: '<S766>/S-Function'
                                        */
  real_T SFunction_P1_l;               /* Expression: Acqu_group
                                        * Referenced by: '<S766>/S-Function'
                                        */
  real_T HitCrossing_Offset;           /* Expression: 0
                                        * Referenced by: '<S684>/Hit  Crossing'
                                        */
  real_T HitCrossing_Offset_j;         /* Expression: 0
                                        * Referenced by: '<S689>/Hit  Crossing'
                                        */
  real_T HitCrossing_Offset_i;         /* Expression: 0
                                        * Referenced by: '<S694>/Hit  Crossing'
                                        */
  real_T HitCrossing_Offset_p;         /* Expression: 0
                                        * Referenced by: '<S699>/Hit  Crossing'
                                        */
  real_T HitCrossing_Offset_ja;        /* Expression: 0
                                        * Referenced by: '<S713>/Hit  Crossing'
                                        */
  real_T HitCrossing_Offset_l;         /* Expression: 0
                                        * Referenced by: '<S718>/Hit  Crossing'
                                        */
  real_T HitCrossing_Offset_d;         /* Expression: 0
                                        * Referenced by: '<S723>/Hit  Crossing'
                                        */
  real_T HitCrossing_Offset_g;         /* Expression: 0
                                        * Referenced by: '<S728>/Hit  Crossing'
                                        */
  real_T Cal_Value;                    /* Expression: 0
                                        * Referenced by: '<S3>/Cal'
                                        */
  real_T AnalogOut2toSEL751_P1_Size[2];/* Computed Parameter: AnalogOut2toSEL751_P1_Size
                                        * Referenced by: '<S3>/AnalogOut2 to SEL-751'
                                        */
  real_T AnalogOut2toSEL751_P1[6];     /* Computed Parameter: AnalogOut2toSEL751_P1
                                        * Referenced by: '<S3>/AnalogOut2 to SEL-751'
                                        */
  real_T AnalogOut2toSEL751_P2_Size[2];/* Computed Parameter: AnalogOut2toSEL751_P2_Size
                                        * Referenced by: '<S3>/AnalogOut2 to SEL-751'
                                        */
  real_T AnalogOut2toSEL751_P3_Size[2];/* Computed Parameter: AnalogOut2toSEL751_P3_Size
                                        * Referenced by: '<S3>/AnalogOut2 to SEL-751'
                                        */
  real_T AnalogOut2toSEL751_P3;        /* Expression: portNb
                                        * Referenced by: '<S3>/AnalogOut2 to SEL-751'
                                        */
  real_T AnalogOut2toSEL751_P4_Size[2];/* Computed Parameter: AnalogOut2toSEL751_P4_Size
                                        * Referenced by: '<S3>/AnalogOut2 to SEL-751'
                                        */
  real_T AnalogOut2toSEL751_P4;        /* Expression: size
                                        * Referenced by: '<S3>/AnalogOut2 to SEL-751'
                                        */
  real_T AnalogOut2toSEL751_P5_Size[2];/* Computed Parameter: AnalogOut2toSEL751_P5_Size
                                        * Referenced by: '<S3>/AnalogOut2 to SEL-751'
                                        */
  real_T AnalogOut2toSEL751_P5;        /* Expression: numchan
                                        * Referenced by: '<S3>/AnalogOut2 to SEL-751'
                                        */
  real_T AnalogOut2toSEL751_P6_Size[2];/* Computed Parameter: AnalogOut2toSEL751_P6_Size
                                        * Referenced by: '<S3>/AnalogOut2 to SEL-751'
                                        */
  real_T AnalogOut2toSEL751_P6;        /* Expression: maxcount
                                        * Referenced by: '<S3>/AnalogOut2 to SEL-751'
                                        */
  real_T AnalogOut2toSEL751_P7_Size[2];/* Computed Parameter: AnalogOut2toSEL751_P7_Size
                                        * Referenced by: '<S3>/AnalogOut2 to SEL-751'
                                        */
  real_T AnalogOut2toSEL751_P7;        /* Expression: slot
                                        * Referenced by: '<S3>/AnalogOut2 to SEL-751'
                                        */
  real_T AnalogOut2toSEL751_P8_Size[2];/* Computed Parameter: AnalogOut2toSEL751_P8_Size
                                        * Referenced by: '<S3>/AnalogOut2 to SEL-751'
                                        */
  real_T AnalogOut2toSEL751_P8;        /* Expression: side
                                        * Referenced by: '<S3>/AnalogOut2 to SEL-751'
                                        */
  real_T AnalogOut2toSEL751_P9_Size[2];/* Computed Parameter: AnalogOut2toSEL751_P9_Size
                                        * Referenced by: '<S3>/AnalogOut2 to SEL-751'
                                        */
  real_T AnalogOut2toSEL751_P9;        /* Expression: voltagerange
                                        * Referenced by: '<S3>/AnalogOut2 to SEL-751'
                                        */
  real_T AnalogOut2toSEL751_P10_Size[2];/* Computed Parameter: AnalogOut2toSEL751_P10_Size
                                         * Referenced by: '<S3>/AnalogOut2 to SEL-751'
                                         */
  real_T AnalogOut2toSEL751_P10;       /* Expression: mismatch
                                        * Referenced by: '<S3>/AnalogOut2 to SEL-751'
                                        */
  real_T AnalogOut2toSEL751_P11_Size[2];/* Computed Parameter: AnalogOut2toSEL751_P11_Size
                                         * Referenced by: '<S3>/AnalogOut2 to SEL-751'
                                         */
  real_T AnalogOut2toSEL751_P11;       /* Expression: israngeinput
                                        * Referenced by: '<S3>/AnalogOut2 to SEL-751'
                                        */
  real_T HitCrossing_Offset_h;         /* Expression: 0
                                        * Referenced by: '<S85>/Hit  Crossing'
                                        */
  real_T HitCrossing_Offset_c;         /* Expression: 0
                                        * Referenced by: '<S90>/Hit  Crossing'
                                        */
  real_T HitCrossing_Offset_hk;        /* Expression: 0
                                        * Referenced by: '<S95>/Hit  Crossing'
                                        */
  real_T donotdeletethisgain_Gain;     /* Expression: 1
                                        * Referenced by: '<S37>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_f;   /* Expression: 1
                                        * Referenced by: '<S38>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_n;   /* Expression: 1
                                        * Referenced by: '<S39>/do not delete this gain'
                                        */
  real_T Kv_Gain;                      /* Expression: Ki
                                        * Referenced by: '<S25>/Kv'
                                        */
  real_T donotdeletethisgain_Gain_k;   /* Expression: 1
                                        * Referenced by: '<S40>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_i;   /* Expression: 1
                                        * Referenced by: '<S41>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_o;   /* Expression: 1
                                        * Referenced by: '<S42>/do not delete this gain'
                                        */
  real_T Kv1_Gain;                     /* Expression: Kv
                                        * Referenced by: '<S25>/Kv1'
                                        */
  real_T donotdeletethisgain_Gain_a;   /* Expression: 1
                                        * Referenced by: '<S61>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_oc;  /* Expression: 1
                                        * Referenced by: '<S62>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_ao;  /* Expression: 1
                                        * Referenced by: '<S63>/do not delete this gain'
                                        */
  real_T Kv_Gain_o;                    /* Expression: Ki
                                        * Referenced by: '<S26>/Kv'
                                        */
  real_T donotdeletethisgain_Gain_ox;  /* Expression: 1
                                        * Referenced by: '<S64>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_m;   /* Expression: 1
                                        * Referenced by: '<S65>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_ky;  /* Expression: 1
                                        * Referenced by: '<S66>/do not delete this gain'
                                        */
  real_T Kv1_Gain_d;                   /* Expression: Kv
                                        * Referenced by: '<S26>/Kv1'
                                        */
  real_T HitCrossing_Offset_hr;        /* Expression: 0
                                        * Referenced by: '<S159>/Hit  Crossing'
                                        */
  real_T HitCrossing_Offset_m;         /* Expression: 0
                                        * Referenced by: '<S164>/Hit  Crossing'
                                        */
  real_T HitCrossing_Offset_f;         /* Expression: 0
                                        * Referenced by: '<S169>/Hit  Crossing'
                                        */
  real_T donotdeletethisgain_Gain_fu;  /* Expression: 1
                                        * Referenced by: '<S111>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_p;   /* Expression: 1
                                        * Referenced by: '<S112>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_h;   /* Expression: 1
                                        * Referenced by: '<S113>/do not delete this gain'
                                        */
  real_T Kv_Gain_n;                    /* Expression: Ki
                                        * Referenced by: '<S99>/Kv'
                                        */
  real_T donotdeletethisgain_Gain_c;   /* Expression: 1
                                        * Referenced by: '<S114>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_ih;  /* Expression: 1
                                        * Referenced by: '<S115>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_p4;  /* Expression: 1
                                        * Referenced by: '<S116>/do not delete this gain'
                                        */
  real_T Kv1_Gain_c;                   /* Expression: Kv
                                        * Referenced by: '<S99>/Kv1'
                                        */
  real_T donotdeletethisgain_Gain_pp;  /* Expression: 1
                                        * Referenced by: '<S135>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_j;   /* Expression: 1
                                        * Referenced by: '<S136>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_ke;  /* Expression: 1
                                        * Referenced by: '<S137>/do not delete this gain'
                                        */
  real_T Kv_Gain_e;                    /* Expression: Ki
                                        * Referenced by: '<S100>/Kv'
                                        */
  real_T donotdeletethisgain_Gain_e;   /* Expression: 1
                                        * Referenced by: '<S138>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_kn;  /* Expression: 1
                                        * Referenced by: '<S139>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_cc;  /* Expression: 1
                                        * Referenced by: '<S140>/do not delete this gain'
                                        */
  real_T Kv1_Gain_p;                   /* Expression: Kv
                                        * Referenced by: '<S100>/Kv1'
                                        */
  real_T HitCrossing_Offset_i0;        /* Expression: 0
                                        * Referenced by: '<S233>/Hit  Crossing'
                                        */
  real_T HitCrossing_Offset_cf;        /* Expression: 0
                                        * Referenced by: '<S238>/Hit  Crossing'
                                        */
  real_T HitCrossing_Offset_jf;        /* Expression: 0
                                        * Referenced by: '<S243>/Hit  Crossing'
                                        */
  real_T donotdeletethisgain_Gain_d;   /* Expression: 1
                                        * Referenced by: '<S185>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_hb;  /* Expression: 1
                                        * Referenced by: '<S186>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_b;   /* Expression: 1
                                        * Referenced by: '<S187>/do not delete this gain'
                                        */
  real_T Kv_Gain_m;                    /* Expression: Ki
                                        * Referenced by: '<S173>/Kv'
                                        */
  real_T donotdeletethisgain_Gain_fx;  /* Expression: 1
                                        * Referenced by: '<S188>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_n0;  /* Expression: 1
                                        * Referenced by: '<S189>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_c0;  /* Expression: 1
                                        * Referenced by: '<S190>/do not delete this gain'
                                        */
  real_T Kv1_Gain_i;                   /* Expression: Kv
                                        * Referenced by: '<S173>/Kv1'
                                        */
  real_T donotdeletethisgain_Gain_f1;  /* Expression: 1
                                        * Referenced by: '<S209>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_pu;  /* Expression: 1
                                        * Referenced by: '<S210>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_dj;  /* Expression: 1
                                        * Referenced by: '<S211>/do not delete this gain'
                                        */
  real_T Kv_Gain_b;                    /* Expression: Ki
                                        * Referenced by: '<S174>/Kv'
                                        */
  real_T donotdeletethisgain_Gain_l;   /* Expression: 1
                                        * Referenced by: '<S212>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_kem; /* Expression: 1
                                        * Referenced by: '<S213>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_lr;  /* Expression: 1
                                        * Referenced by: '<S214>/do not delete this gain'
                                        */
  real_T Kv1_Gain_h;                   /* Expression: Kv
                                        * Referenced by: '<S174>/Kv1'
                                        */
  real_T DigitalOuttoSEL751_P1_Size[2];/* Computed Parameter: DigitalOuttoSEL751_P1_Size
                                        * Referenced by: '<S3>/DigitalOut to SEL-751'
                                        */
  real_T DigitalOuttoSEL751_P1[6];     /* Computed Parameter: DigitalOuttoSEL751_P1
                                        * Referenced by: '<S3>/DigitalOut to SEL-751'
                                        */
  real_T DigitalOuttoSEL751_P2_Size[2];/* Computed Parameter: DigitalOuttoSEL751_P2_Size
                                        * Referenced by: '<S3>/DigitalOut to SEL-751'
                                        */
  real_T DigitalOuttoSEL751_P3_Size[2];/* Computed Parameter: DigitalOuttoSEL751_P3_Size
                                        * Referenced by: '<S3>/DigitalOut to SEL-751'
                                        */
  real_T DigitalOuttoSEL751_P3;        /* Expression: portNb
                                        * Referenced by: '<S3>/DigitalOut to SEL-751'
                                        */
  real_T DigitalOuttoSEL751_P4_Size[2];/* Computed Parameter: DigitalOuttoSEL751_P4_Size
                                        * Referenced by: '<S3>/DigitalOut to SEL-751'
                                        */
  real_T DigitalOuttoSEL751_P4;        /* Expression: size
                                        * Referenced by: '<S3>/DigitalOut to SEL-751'
                                        */
  real_T DigitalOuttoSEL751_P5_Size[2];/* Computed Parameter: DigitalOuttoSEL751_P5_Size
                                        * Referenced by: '<S3>/DigitalOut to SEL-751'
                                        */
  real_T DigitalOuttoSEL751_P5;        /* Expression: count
                                        * Referenced by: '<S3>/DigitalOut to SEL-751'
                                        */
  real_T DigitalOuttoSEL751_P6_Size[2];/* Computed Parameter: DigitalOuttoSEL751_P6_Size
                                        * Referenced by: '<S3>/DigitalOut to SEL-751'
                                        */
  real_T DigitalOuttoSEL751_P6;        /* Expression: maxcount
                                        * Referenced by: '<S3>/DigitalOut to SEL-751'
                                        */
  real_T Interpolation1_Value;         /* Expression: 1
                                        * Referenced by: '<S3>/Interpolation 1'
                                        */
  real_T Modbusdevice_P1_Size[2];      /* Computed Parameter: Modbusdevice_P1_Size
                                        * Referenced by: '<S12>/Modbus device'
                                        */
  real_T Modbusdevice_P1;              /* Expression: sample_time
                                        * Referenced by: '<S12>/Modbus device'
                                        */
  real_T Modbusdevice_P2_Size[2];      /* Computed Parameter: Modbusdevice_P2_Size
                                        * Referenced by: '<S12>/Modbus device'
                                        */
  real_T Modbusdevice_P2[18];          /* Computed Parameter: Modbusdevice_P2
                                        * Referenced by: '<S12>/Modbus device'
                                        */
  real_T Constant_Value_i1;            /* Expression: SIM_HIL
                                        * Referenced by: '<S249>/Constant'
                                        */
  real_T SIM_HIL1_Threshold;           /* Expression: .5
                                        * Referenced by: '<S249>/SIM_HIL1'
                                        */
  real_T DerivativeGain_Gain_o;        /* Expression: D
                                        * Referenced by: '<S251>/Derivative Gain'
                                        */
  real_T Filter_gainval_hn;            /* Computed Parameter: Filter_gainval_hn
                                        * Referenced by: '<S251>/Filter'
                                        */
  real_T Filter_IC_e;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S251>/Filter'
                                        */
  real_T FilterCoefficient_Gain_k;     /* Expression: N
                                        * Referenced by: '<S251>/Filter Coefficient'
                                        */
  real_T IntegralGain_Gain;            /* Expression: I
                                        * Referenced by: '<S251>/Integral Gain'
                                        */
  real_T Integrator_gainval_l;         /* Computed Parameter: Integrator_gainval_l
                                        * Referenced by: '<S251>/Integrator'
                                        */
  real_T Integrator_IC_b;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S251>/Integrator'
                                        */
  real_T ProportionalGain_Gain_ai;     /* Expression: P
                                        * Referenced by: '<S251>/Proportional Gain'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: UpperSaturationLimit
                                        * Referenced by: '<S251>/Saturation'
                                        */
  real_T Saturation_LowerSat_n;        /* Expression: LowerSaturationLimit
                                        * Referenced by: '<S251>/Saturation'
                                        */
  real_T CHPHeatingOff_Value;          /* Expression: 0
                                        * Referenced by: '<S249>/CHP Heating Off'
                                        */
  real_T CHPMIxingTC1_A[3];            /* Computed Parameter: CHPMIxingTC1_A
                                        * Referenced by: '<S249>/CHP MIxing TC1'
                                        */
  real_T CHPMIxingTC1_B;               /* Computed Parameter: CHPMIxingTC1_B
                                        * Referenced by: '<S249>/CHP MIxing TC1'
                                        */
  real_T CHPMIxingTC1_C;               /* Computed Parameter: CHPMIxingTC1_C
                                        * Referenced by: '<S249>/CHP MIxing TC1'
                                        */
  real_T CHPMIxingTC1_X0;              /* Expression: 0
                                        * Referenced by: '<S249>/CHP MIxing TC1'
                                        */
  real_T Constant1_Value_oo;           /* Expression: SIM_HIL
                                        * Referenced by: '<S249>/Constant1'
                                        */
  real_T PipingTransportDelay1_Delay;  /* Expression: 10
                                        * Referenced by: '<S249>/Piping Transport Delay1'
                                        */
  real_T PipingTransportDelay1_InitOutpu;/* Expression: 0
                                          * Referenced by: '<S249>/Piping Transport Delay1'
                                          */
  real_T SIM_HIL2_Threshold;           /* Expression: .5
                                        * Referenced by: '<S249>/SIM_HIL2'
                                        */
  real_T State1_Value;                 /* Expression: 1
                                        * Referenced by: '<S3>/State 1'
                                        */
  real_T Repetative1_Value;            /* Expression: 1
                                        * Referenced by: '<S3>/Repetative 1'
                                        */
  real_T Start_Index1_Value;           /* Expression: 1
                                        * Referenced by: '<S3>/Start_Index 1'
                                        */
  real_T Stop_Index1_Value;            /* Expression: 1800-1
                                        * Referenced by: '<S3>/Stop_Index 1'
                                        */
  real_T OpFromFile_P1_Size[2];        /* Computed Parameter: OpFromFile_P1_Size
                                        * Referenced by: '<S3>/OpFromFile'
                                        */
  real_T OpFromFile_P1;                /* Expression: filename_mode
                                        * Referenced by: '<S3>/OpFromFile'
                                        */
  real_T OpFromFile_P2_Size[2];        /* Computed Parameter: OpFromFile_P2_Size
                                        * Referenced by: '<S3>/OpFromFile'
                                        */
  real_T OpFromFile_P2;                /* Expression: reload_mode
                                        * Referenced by: '<S3>/OpFromFile'
                                        */
  real_T OpFromFile_P3_Size[2];        /* Computed Parameter: OpFromFile_P3_Size
                                        * Referenced by: '<S3>/OpFromFile'
                                        */
  real_T OpFromFile_P3;                /* Expression: init_file_id
                                        * Referenced by: '<S3>/OpFromFile'
                                        */
  real_T OpFromFile_P4_Size[2];        /* Computed Parameter: OpFromFile_P4_Size
                                        * Referenced by: '<S3>/OpFromFile'
                                        */
  real_T OpFromFile_P4[12];            /* Computed Parameter: OpFromFile_P4
                                        * Referenced by: '<S3>/OpFromFile'
                                        */
  real_T OpFromFile_P5_Size[2];        /* Computed Parameter: OpFromFile_P5_Size
                                        * Referenced by: '<S3>/OpFromFile'
                                        */
  real_T OpFromFile_P5[2];             /* Computed Parameter: OpFromFile_P5
                                        * Referenced by: '<S3>/OpFromFile'
                                        */
  real_T OpFromFile_P6_Size[2];        /* Computed Parameter: OpFromFile_P6_Size
                                        * Referenced by: '<S3>/OpFromFile'
                                        */
  real_T OpFromFile_P6[2];             /* Computed Parameter: OpFromFile_P6
                                        * Referenced by: '<S3>/OpFromFile'
                                        */
  real_T OpFromFile_P7_Size[2];        /* Computed Parameter: OpFromFile_P7_Size
                                        * Referenced by: '<S3>/OpFromFile'
                                        */
  real_T OpFromFile_P7;                /* Expression: sample_time
                                        * Referenced by: '<S3>/OpFromFile'
                                        */
  real_T SupplyHeatingFromHrectoLoad_Thr;/* Expression: .5
                                          * Referenced by: '<S249>/Supply Heating From Hrec to Load'
                                          */
  real_T Gain_Gain_hs;                 /* Expression: 15/11268
                                        * Referenced by: '<S253>/Gain'
                                        */
  real_T Gain1_Gain_h2;                /* Expression: 15/11268
                                        * Referenced by: '<S253>/Gain1'
                                        */
  real_T Gain4_Gain;                   /* Expression: 15/11268
                                        * Referenced by: '<S253>/Gain4'
                                        */
  real_T AnalogOut_P1_Size[2];         /* Computed Parameter: AnalogOut_P1_Size
                                        * Referenced by: '<S253>/AnalogOut'
                                        */
  real_T AnalogOut_P1[6];              /* Computed Parameter: AnalogOut_P1
                                        * Referenced by: '<S253>/AnalogOut'
                                        */
  real_T AnalogOut_P2_Size[2];         /* Computed Parameter: AnalogOut_P2_Size
                                        * Referenced by: '<S253>/AnalogOut'
                                        */
  real_T AnalogOut_P3_Size[2];         /* Computed Parameter: AnalogOut_P3_Size
                                        * Referenced by: '<S253>/AnalogOut'
                                        */
  real_T AnalogOut_P3;                 /* Expression: portNb
                                        * Referenced by: '<S253>/AnalogOut'
                                        */
  real_T AnalogOut_P4_Size[2];         /* Computed Parameter: AnalogOut_P4_Size
                                        * Referenced by: '<S253>/AnalogOut'
                                        */
  real_T AnalogOut_P4;                 /* Expression: size
                                        * Referenced by: '<S253>/AnalogOut'
                                        */
  real_T AnalogOut_P5_Size[2];         /* Computed Parameter: AnalogOut_P5_Size
                                        * Referenced by: '<S253>/AnalogOut'
                                        */
  real_T AnalogOut_P5;                 /* Expression: numchan
                                        * Referenced by: '<S253>/AnalogOut'
                                        */
  real_T AnalogOut_P6_Size[2];         /* Computed Parameter: AnalogOut_P6_Size
                                        * Referenced by: '<S253>/AnalogOut'
                                        */
  real_T AnalogOut_P6;                 /* Expression: maxcount
                                        * Referenced by: '<S253>/AnalogOut'
                                        */
  real_T AnalogOut_P7_Size[2];         /* Computed Parameter: AnalogOut_P7_Size
                                        * Referenced by: '<S253>/AnalogOut'
                                        */
  real_T AnalogOut_P7;                 /* Expression: slot
                                        * Referenced by: '<S253>/AnalogOut'
                                        */
  real_T AnalogOut_P8_Size[2];         /* Computed Parameter: AnalogOut_P8_Size
                                        * Referenced by: '<S253>/AnalogOut'
                                        */
  real_T AnalogOut_P8;                 /* Expression: side
                                        * Referenced by: '<S253>/AnalogOut'
                                        */
  real_T AnalogOut_P9_Size[2];         /* Computed Parameter: AnalogOut_P9_Size
                                        * Referenced by: '<S253>/AnalogOut'
                                        */
  real_T AnalogOut_P9;                 /* Expression: voltagerange
                                        * Referenced by: '<S253>/AnalogOut'
                                        */
  real_T AnalogOut_P10_Size[2];        /* Computed Parameter: AnalogOut_P10_Size
                                        * Referenced by: '<S253>/AnalogOut'
                                        */
  real_T AnalogOut_P10;                /* Expression: mismatch
                                        * Referenced by: '<S253>/AnalogOut'
                                        */
  real_T AnalogOut_P11_Size[2];        /* Computed Parameter: AnalogOut_P11_Size
                                        * Referenced by: '<S253>/AnalogOut'
                                        */
  real_T AnalogOut_P11;                /* Expression: israngeinput
                                        * Referenced by: '<S253>/AnalogOut'
                                        */
  real_T Gain5_Gain;                   /* Expression: 15/11268
                                        * Referenced by: '<S253>/Gain5'
                                        */
  real_T Constant1_Value_hd;           /* Expression: .02
                                        * Referenced by: '<S250>/Constant1'
                                        */
  real_T Gain4_Gain_b;                 /* Expression: 1800
                                        * Referenced by: '<S309>/Gain4'
                                        */
  real_T Duty_Value;                   /* Expression: 0.5
                                        * Referenced by: '<S309>/Duty'
                                        */
  real_T RTESPWM_P1_Size[2];           /* Computed Parameter: RTESPWM_P1_Size
                                        * Referenced by: '<S309>/RTE SPWM'
                                        */
  real_T RTESPWM_P1;                   /* Expression: MaxEvents
                                        * Referenced by: '<S309>/RTE SPWM'
                                        */
  real_T RTESPWM_P2_Size[2];           /* Computed Parameter: RTESPWM_P2_Size
                                        * Referenced by: '<S309>/RTE SPWM'
                                        */
  real_T RTESPWM_P2;                   /* Expression: SampleTime
                                        * Referenced by: '<S309>/RTE SPWM'
                                        */
  real_T RTESPWM_P3_Size[2];           /* Computed Parameter: RTESPWM_P3_Size
                                        * Referenced by: '<S309>/RTE SPWM'
                                        */
  real_T RTESPWM_P3;                   /* Expression: MaxFreq
                                        * Referenced by: '<S309>/RTE SPWM'
                                        */
  real_T RTESPWM_P4_Size[2];           /* Computed Parameter: RTESPWM_P4_Size
                                        * Referenced by: '<S309>/RTE SPWM'
                                        */
  real_T RTESPWM_P4;                   /* Expression: MinFreq
                                        * Referenced by: '<S309>/RTE SPWM'
                                        */
  real_T RTESPWM_P5_Size[2];           /* Computed Parameter: RTESPWM_P5_Size
                                        * Referenced by: '<S309>/RTE SPWM'
                                        */
  real_T RTESPWM_P5;                   /* Expression: EnablingPort
                                        * Referenced by: '<S309>/RTE SPWM'
                                        */
  real_T RTESPWM_P6_Size[2];           /* Computed Parameter: RTESPWM_P6_Size
                                        * Referenced by: '<S309>/RTE SPWM'
                                        */
  real_T RTESPWM_P6;                   /* Expression: NumberPhases
                                        * Referenced by: '<S309>/RTE SPWM'
                                        */
  real_T RTESPWM_P7_Size[2];           /* Computed Parameter: RTESPWM_P7_Size
                                        * Referenced by: '<S309>/RTE SPWM'
                                        */
  real_T RTESPWM_P7;                   /* Expression: ComplementaryMode
                                        * Referenced by: '<S309>/RTE SPWM'
                                        */
  real_T RTESPWM_P8_Size[2];           /* Computed Parameter: RTESPWM_P8_Size
                                        * Referenced by: '<S309>/RTE SPWM'
                                        */
  real_T RTESPWM_P8;                   /* Expression: RiseTimeDelay
                                        * Referenced by: '<S309>/RTE SPWM'
                                        */
  real_T RTESPWM_P9_Size[2];           /* Computed Parameter: RTESPWM_P9_Size
                                        * Referenced by: '<S309>/RTE SPWM'
                                        */
  real_T RTESPWM_P9;                   /* Expression: CenterAlignmentMode
                                        * Referenced by: '<S309>/RTE SPWM'
                                        */
  real_T RTESPWM_P10_Size[2];          /* Computed Parameter: RTESPWM_P10_Size
                                        * Referenced by: '<S309>/RTE SPWM'
                                        */
  real_T RTESPWM_P10;                  /* Expression: SpaceVector
                                        * Referenced by: '<S309>/RTE SPWM'
                                        */
  real_T RTEConversion_P1_Size[2];     /* Computed Parameter: RTEConversion_P1_Size
                                        * Referenced by: '<S309>/RTE Conversion'
                                        */
  real_T RTEConversion_P1;             /* Expression: nbMaxEvents
                                        * Referenced by: '<S309>/RTE Conversion'
                                        */
  real_T RTEConversion_P2_Size[2];     /* Computed Parameter: RTEConversion_P2_Size
                                        * Referenced by: '<S309>/RTE Conversion'
                                        */
  real_T RTEConversion_P2;             /* Expression: inputdatatype
                                        * Referenced by: '<S309>/RTE Conversion'
                                        */
  real_T RTEConversion_P3_Size[2];     /* Computed Parameter: RTEConversion_P3_Size
                                        * Referenced by: '<S309>/RTE Conversion'
                                        */
  real_T RTEConversion_P3;             /* Expression: outputdatatype
                                        * Referenced by: '<S309>/RTE Conversion'
                                        */
  real_T RTEConversion_P4_Size[2];     /* Computed Parameter: RTEConversion_P4_Size
                                        * Referenced by: '<S309>/RTE Conversion'
                                        */
  real_T RTEConversion_P4;             /* Expression: compensation
                                        * Referenced by: '<S309>/RTE Conversion'
                                        */
  real_T RTEConversion_P5_Size[2];     /* Computed Parameter: RTEConversion_P5_Size
                                        * Referenced by: '<S309>/RTE Conversion'
                                        */
  real_T RTEConversion_P5;             /* Expression: sampleTime
                                        * Referenced by: '<S309>/RTE Conversion'
                                        */
  real_T Gain1_Gain_p0;                /* Expression: 5
                                        * Referenced by: '<S309>/Gain1'
                                        */
  real_T Gain4_Gain_d;                 /* Expression: 1800
                                        * Referenced by: '<S310>/Gain4'
                                        */
  real_T Duty_Value_i;                 /* Expression: 0.5
                                        * Referenced by: '<S310>/Duty'
                                        */
  real_T RTESPWM_P1_Size_h[2];         /* Computed Parameter: RTESPWM_P1_Size_h
                                        * Referenced by: '<S310>/RTE SPWM'
                                        */
  real_T RTESPWM_P1_j;                 /* Expression: MaxEvents
                                        * Referenced by: '<S310>/RTE SPWM'
                                        */
  real_T RTESPWM_P2_Size_b[2];         /* Computed Parameter: RTESPWM_P2_Size_b
                                        * Referenced by: '<S310>/RTE SPWM'
                                        */
  real_T RTESPWM_P2_c;                 /* Expression: SampleTime
                                        * Referenced by: '<S310>/RTE SPWM'
                                        */
  real_T RTESPWM_P3_Size_e[2];         /* Computed Parameter: RTESPWM_P3_Size_e
                                        * Referenced by: '<S310>/RTE SPWM'
                                        */
  real_T RTESPWM_P3_j;                 /* Expression: MaxFreq
                                        * Referenced by: '<S310>/RTE SPWM'
                                        */
  real_T RTESPWM_P4_Size_b[2];         /* Computed Parameter: RTESPWM_P4_Size_b
                                        * Referenced by: '<S310>/RTE SPWM'
                                        */
  real_T RTESPWM_P4_j;                 /* Expression: MinFreq
                                        * Referenced by: '<S310>/RTE SPWM'
                                        */
  real_T RTESPWM_P5_Size_b[2];         /* Computed Parameter: RTESPWM_P5_Size_b
                                        * Referenced by: '<S310>/RTE SPWM'
                                        */
  real_T RTESPWM_P5_a;                 /* Expression: EnablingPort
                                        * Referenced by: '<S310>/RTE SPWM'
                                        */
  real_T RTESPWM_P6_Size_c[2];         /* Computed Parameter: RTESPWM_P6_Size_c
                                        * Referenced by: '<S310>/RTE SPWM'
                                        */
  real_T RTESPWM_P6_h;                 /* Expression: NumberPhases
                                        * Referenced by: '<S310>/RTE SPWM'
                                        */
  real_T RTESPWM_P7_Size_l[2];         /* Computed Parameter: RTESPWM_P7_Size_l
                                        * Referenced by: '<S310>/RTE SPWM'
                                        */
  real_T RTESPWM_P7_h;                 /* Expression: ComplementaryMode
                                        * Referenced by: '<S310>/RTE SPWM'
                                        */
  real_T RTESPWM_P8_Size_h[2];         /* Computed Parameter: RTESPWM_P8_Size_h
                                        * Referenced by: '<S310>/RTE SPWM'
                                        */
  real_T RTESPWM_P8_p;                 /* Expression: RiseTimeDelay
                                        * Referenced by: '<S310>/RTE SPWM'
                                        */
  real_T RTESPWM_P9_Size_h[2];         /* Computed Parameter: RTESPWM_P9_Size_h
                                        * Referenced by: '<S310>/RTE SPWM'
                                        */
  real_T RTESPWM_P9_a;                 /* Expression: CenterAlignmentMode
                                        * Referenced by: '<S310>/RTE SPWM'
                                        */
  real_T RTESPWM_P10_Size_d[2];        /* Computed Parameter: RTESPWM_P10_Size_d
                                        * Referenced by: '<S310>/RTE SPWM'
                                        */
  real_T RTESPWM_P10_d;                /* Expression: SpaceVector
                                        * Referenced by: '<S310>/RTE SPWM'
                                        */
  real_T RTEConversion_P1_Size_g[2];   /* Computed Parameter: RTEConversion_P1_Size_g
                                        * Referenced by: '<S310>/RTE Conversion'
                                        */
  real_T RTEConversion_P1_a;           /* Expression: nbMaxEvents
                                        * Referenced by: '<S310>/RTE Conversion'
                                        */
  real_T RTEConversion_P2_Size_p[2];   /* Computed Parameter: RTEConversion_P2_Size_p
                                        * Referenced by: '<S310>/RTE Conversion'
                                        */
  real_T RTEConversion_P2_c;           /* Expression: inputdatatype
                                        * Referenced by: '<S310>/RTE Conversion'
                                        */
  real_T RTEConversion_P3_Size_k[2];   /* Computed Parameter: RTEConversion_P3_Size_k
                                        * Referenced by: '<S310>/RTE Conversion'
                                        */
  real_T RTEConversion_P3_h;           /* Expression: outputdatatype
                                        * Referenced by: '<S310>/RTE Conversion'
                                        */
  real_T RTEConversion_P4_Size_m[2];   /* Computed Parameter: RTEConversion_P4_Size_m
                                        * Referenced by: '<S310>/RTE Conversion'
                                        */
  real_T RTEConversion_P4_m;           /* Expression: compensation
                                        * Referenced by: '<S310>/RTE Conversion'
                                        */
  real_T RTEConversion_P5_Size_g[2];   /* Computed Parameter: RTEConversion_P5_Size_g
                                        * Referenced by: '<S310>/RTE Conversion'
                                        */
  real_T RTEConversion_P5_g;           /* Expression: sampleTime
                                        * Referenced by: '<S310>/RTE Conversion'
                                        */
  real_T Gain1_Gain_k5;                /* Expression: 5
                                        * Referenced by: '<S310>/Gain1'
                                        */
  real_T AnalogOut1_P1_Size[2];        /* Computed Parameter: AnalogOut1_P1_Size
                                        * Referenced by: '<S253>/AnalogOut1'
                                        */
  real_T AnalogOut1_P1[6];             /* Computed Parameter: AnalogOut1_P1
                                        * Referenced by: '<S253>/AnalogOut1'
                                        */
  real_T AnalogOut1_P2_Size[2];        /* Computed Parameter: AnalogOut1_P2_Size
                                        * Referenced by: '<S253>/AnalogOut1'
                                        */
  real_T AnalogOut1_P3_Size[2];        /* Computed Parameter: AnalogOut1_P3_Size
                                        * Referenced by: '<S253>/AnalogOut1'
                                        */
  real_T AnalogOut1_P3;                /* Expression: portNb
                                        * Referenced by: '<S253>/AnalogOut1'
                                        */
  real_T AnalogOut1_P4_Size[2];        /* Computed Parameter: AnalogOut1_P4_Size
                                        * Referenced by: '<S253>/AnalogOut1'
                                        */
  real_T AnalogOut1_P4;                /* Expression: size
                                        * Referenced by: '<S253>/AnalogOut1'
                                        */
  real_T AnalogOut1_P5_Size[2];        /* Computed Parameter: AnalogOut1_P5_Size
                                        * Referenced by: '<S253>/AnalogOut1'
                                        */
  real_T AnalogOut1_P5;                /* Expression: numchan
                                        * Referenced by: '<S253>/AnalogOut1'
                                        */
  real_T AnalogOut1_P6_Size[2];        /* Computed Parameter: AnalogOut1_P6_Size
                                        * Referenced by: '<S253>/AnalogOut1'
                                        */
  real_T AnalogOut1_P6;                /* Expression: maxcount
                                        * Referenced by: '<S253>/AnalogOut1'
                                        */
  real_T AnalogOut1_P7_Size[2];        /* Computed Parameter: AnalogOut1_P7_Size
                                        * Referenced by: '<S253>/AnalogOut1'
                                        */
  real_T AnalogOut1_P7;                /* Expression: slot
                                        * Referenced by: '<S253>/AnalogOut1'
                                        */
  real_T AnalogOut1_P8_Size[2];        /* Computed Parameter: AnalogOut1_P8_Size
                                        * Referenced by: '<S253>/AnalogOut1'
                                        */
  real_T AnalogOut1_P8;                /* Expression: side
                                        * Referenced by: '<S253>/AnalogOut1'
                                        */
  real_T AnalogOut1_P9_Size[2];        /* Computed Parameter: AnalogOut1_P9_Size
                                        * Referenced by: '<S253>/AnalogOut1'
                                        */
  real_T AnalogOut1_P9;                /* Expression: voltagerange
                                        * Referenced by: '<S253>/AnalogOut1'
                                        */
  real_T AnalogOut1_P10_Size[2];       /* Computed Parameter: AnalogOut1_P10_Size
                                        * Referenced by: '<S253>/AnalogOut1'
                                        */
  real_T AnalogOut1_P10;               /* Expression: mismatch
                                        * Referenced by: '<S253>/AnalogOut1'
                                        */
  real_T AnalogOut1_P11_Size[2];       /* Computed Parameter: AnalogOut1_P11_Size
                                        * Referenced by: '<S253>/AnalogOut1'
                                        */
  real_T AnalogOut1_P11;               /* Expression: israngeinput
                                        * Referenced by: '<S253>/AnalogOut1'
                                        */
  real_T initialFreq_Value;            /* Expression: 2*pi
                                        * Referenced by: '<S309>/initialFreq'
                                        */
  real_T Gain3_Gain_i2;                /* Expression: 5
                                        * Referenced by: '<S309>/Gain3'
                                        */
  real_T initialFreq_Value_p;          /* Expression: 2*pi
                                        * Referenced by: '<S310>/initialFreq'
                                        */
  real_T Gain3_Gain_d;                 /* Expression: 5
                                        * Referenced by: '<S310>/Gain3'
                                        */
  real_T Gain3_Gain_m;                 /* Expression: 15/(3150000/11268)
                                        * Referenced by: '<S253>/Gain3'
                                        */
  real_T Gain2_Gain_p;                 /* Expression: 15/(3150000/11268)
                                        * Referenced by: '<S253>/Gain2'
                                        */
  real_T Gain7_Gain;                   /* Expression: 15/(900000/11268)
                                        * Referenced by: '<S253>/Gain7'
                                        */
  real_T Gain6_Gain;                   /* Expression: 15/(900000/391)
                                        * Referenced by: '<S253>/Gain6'
                                        */
  real_T AnalogOut2_P1_Size[2];        /* Computed Parameter: AnalogOut2_P1_Size
                                        * Referenced by: '<S253>/AnalogOut2'
                                        */
  real_T AnalogOut2_P1[6];             /* Computed Parameter: AnalogOut2_P1
                                        * Referenced by: '<S253>/AnalogOut2'
                                        */
  real_T AnalogOut2_P2_Size[2];        /* Computed Parameter: AnalogOut2_P2_Size
                                        * Referenced by: '<S253>/AnalogOut2'
                                        */
  real_T AnalogOut2_P3_Size[2];        /* Computed Parameter: AnalogOut2_P3_Size
                                        * Referenced by: '<S253>/AnalogOut2'
                                        */
  real_T AnalogOut2_P3;                /* Expression: portNb
                                        * Referenced by: '<S253>/AnalogOut2'
                                        */
  real_T AnalogOut2_P4_Size[2];        /* Computed Parameter: AnalogOut2_P4_Size
                                        * Referenced by: '<S253>/AnalogOut2'
                                        */
  real_T AnalogOut2_P4;                /* Expression: size
                                        * Referenced by: '<S253>/AnalogOut2'
                                        */
  real_T AnalogOut2_P5_Size[2];        /* Computed Parameter: AnalogOut2_P5_Size
                                        * Referenced by: '<S253>/AnalogOut2'
                                        */
  real_T AnalogOut2_P5;                /* Expression: numchan
                                        * Referenced by: '<S253>/AnalogOut2'
                                        */
  real_T AnalogOut2_P6_Size[2];        /* Computed Parameter: AnalogOut2_P6_Size
                                        * Referenced by: '<S253>/AnalogOut2'
                                        */
  real_T AnalogOut2_P6;                /* Expression: maxcount
                                        * Referenced by: '<S253>/AnalogOut2'
                                        */
  real_T AnalogOut2_P7_Size[2];        /* Computed Parameter: AnalogOut2_P7_Size
                                        * Referenced by: '<S253>/AnalogOut2'
                                        */
  real_T AnalogOut2_P7;                /* Expression: slot
                                        * Referenced by: '<S253>/AnalogOut2'
                                        */
  real_T AnalogOut2_P8_Size[2];        /* Computed Parameter: AnalogOut2_P8_Size
                                        * Referenced by: '<S253>/AnalogOut2'
                                        */
  real_T AnalogOut2_P8;                /* Expression: side
                                        * Referenced by: '<S253>/AnalogOut2'
                                        */
  real_T AnalogOut2_P9_Size[2];        /* Computed Parameter: AnalogOut2_P9_Size
                                        * Referenced by: '<S253>/AnalogOut2'
                                        */
  real_T AnalogOut2_P9;                /* Expression: voltagerange
                                        * Referenced by: '<S253>/AnalogOut2'
                                        */
  real_T AnalogOut2_P10_Size[2];       /* Computed Parameter: AnalogOut2_P10_Size
                                        * Referenced by: '<S253>/AnalogOut2'
                                        */
  real_T AnalogOut2_P10;               /* Expression: mismatch
                                        * Referenced by: '<S253>/AnalogOut2'
                                        */
  real_T AnalogOut2_P11_Size[2];       /* Computed Parameter: AnalogOut2_P11_Size
                                        * Referenced by: '<S253>/AnalogOut2'
                                        */
  real_T AnalogOut2_P11;               /* Expression: israngeinput
                                        * Referenced by: '<S253>/AnalogOut2'
                                        */
  real_T IntegralGain_Gain_p;          /* Expression: I
                                        * Referenced by: '<S262>/Integral Gain'
                                        */
  real_T Vf0ka_Value;                  /* Expression: v0(2)/reg(1)
                                        * Referenced by: '<S263>/Vf0 // ka'
                                        */
  real_T DiscreteStateSpace_A;         /* Computed Parameter: DiscreteStateSpace_A
                                        * Referenced by: '<S268>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_B;         /* Computed Parameter: DiscreteStateSpace_B
                                        * Referenced by: '<S268>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_C;         /* Computed Parameter: DiscreteStateSpace_C
                                        * Referenced by: '<S268>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_D;         /* Computed Parameter: DiscreteStateSpace_D
                                        * Referenced by: '<S268>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_X0;        /* Expression: x0d
                                        * Referenced by: '<S268>/Discrete State-Space'
                                        */
  real_T UnitDelay1_InitialCondition_e;/* Expression: 0
                                        * Referenced by: '<S263>/Unit Delay1'
                                        */
  real_T DiscreteStateSpace_A_f;       /* Computed Parameter: DiscreteStateSpace_A_f
                                        * Referenced by: '<S267>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_B_b;       /* Computed Parameter: DiscreteStateSpace_B_b
                                        * Referenced by: '<S267>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_D_h;       /* Computed Parameter: DiscreteStateSpace_D_h
                                        * Referenced by: '<S267>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_X0_h;      /* Expression: x0d
                                        * Referenced by: '<S267>/Discrete State-Space'
                                        */
  real_T Gain_Gain_dz;                 /* Expression: reg(1)
                                        * Referenced by: '<S269>/Gain'
                                        */
  real_T DiscreteStateSpace_A_n;       /* Computed Parameter: DiscreteStateSpace_A_n
                                        * Referenced by: '<S273>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_B_a;       /* Computed Parameter: DiscreteStateSpace_B_a
                                        * Referenced by: '<S273>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_C_p;       /* Computed Parameter: DiscreteStateSpace_C_p
                                        * Referenced by: '<S273>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_D_n;       /* Computed Parameter: DiscreteStateSpace_D_n
                                        * Referenced by: '<S273>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_X0_l;      /* Expression: x0d
                                        * Referenced by: '<S273>/Discrete State-Space'
                                        */
  real_T Constant1_Value_l3;           /* Expression: lim(1)
                                        * Referenced by: '<S270>/Constant1'
                                        */
  real_T Vfdmax1_Gain;                 /* Expression: lim(3)
                                        * Referenced by: '<S270>/Vfdmax1'
                                        */
  real_T Constant_Value_a;             /* Expression: lim(3)
                                        * Referenced by: '<S270>/Constant'
                                        */
  real_T Constant3_Value_i;            /* Expression: 0
                                        * Referenced by: '<S270>/Constant3'
                                        */
  real_T Vfdmax_Gain;                  /* Expression: lim(2)
                                        * Referenced by: '<S270>/Vfdmax'
                                        */
  real_T Gain_Gain_ec;                 /* Expression: 1/exc(1)
                                        * Referenced by: '<S266>/Gain'
                                        */
  real_T DiscreteStateSpace_A_d;       /* Computed Parameter: DiscreteStateSpace_A_d
                                        * Referenced by: '<S272>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_B_az;      /* Computed Parameter: DiscreteStateSpace_B_az
                                        * Referenced by: '<S272>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_C_g;       /* Computed Parameter: DiscreteStateSpace_C_g
                                        * Referenced by: '<S272>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_D_g;       /* Computed Parameter: DiscreteStateSpace_D_g
                                        * Referenced by: '<S272>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_X0_j;      /* Expression: x0d
                                        * Referenced by: '<S272>/Discrete State-Space'
                                        */
  real_T Gain_Gain_gr;                 /* Expression: damp(1)/damp(2)
                                        * Referenced by: '<S265>/Gain'
                                        */
  real_T DiscreteStateSpace_A_p;       /* Computed Parameter: DiscreteStateSpace_A_p
                                        * Referenced by: '<S271>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_B_d;       /* Computed Parameter: DiscreteStateSpace_B_d
                                        * Referenced by: '<S271>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_C_m;       /* Computed Parameter: DiscreteStateSpace_C_m
                                        * Referenced by: '<S271>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_D_b;       /* Computed Parameter: DiscreteStateSpace_D_b
                                        * Referenced by: '<S271>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_X0_d;      /* Expression: x0d
                                        * Referenced by: '<S271>/Discrete State-Space'
                                        */
  real_T Pbase_Gain;                   /* Expression: 1/3500
                                        * Referenced by: '<S274>/1//Pbase'
                                        */
  real_T Initialspeed400RPM_gainval;   /* Computed Parameter: Initialspeed400RPM_gainval
                                        * Referenced by: '<S274>/Initial speed 400 RPM'
                                        */
  real_T Initialspeed400RPM_IC;        /* Expression: 10/60*2*pi
                                        * Referenced by: '<S274>/Initial speed 400 RPM'
                                        */
  real_T Initialspeed400RPM_UpperSat;  /* Expression: inf
                                        * Referenced by: '<S274>/Initial speed 400 RPM'
                                        */
  real_T Initialspeed400RPM_LowerSat;  /* Expression: 0
                                        * Referenced by: '<S274>/Initial speed 400 RPM'
                                        */
  real_T Inertia_Gain;                 /* Expression: 10*.001
                                        * Referenced by: '<S274>/Inertia'
                                        */
  real_T Preventdividebyzero1_UpperSat;/* Expression: inf
                                        * Referenced by: '<S274>/Prevent divide by zero1'
                                        */
  real_T Preventdividebyzero1_LowerSat;/* Expression: .001
                                        * Referenced by: '<S274>/Prevent divide by zero1'
                                        */
  real_T Viscousdamping1_Gain;         /* Expression: 2*7*5.5/4
                                        * Referenced by: '<S274>/Viscous damping1'
                                        */
  real_T radsecSpeedpu1_Gain;          /* Expression: 1/2/pi*60/1800
                                        * Referenced by: '<S274>/rad//sec->Speed pu1'
                                        */
  real_T Gain_Gain_j5;                 /* Expression: R*Tm/V/Ma
                                        * Referenced by: '<S275>/Gain'
                                        */
  real_T Gain1_Gain_nq;                /* Expression: R*Tm/V/Ma
                                        * Referenced by: '<S275>/Gain1'
                                        */
  real_T Gain2_Gain_b;                 /* Expression: R*Tm/V/Mf
                                        * Referenced by: '<S275>/Gain2'
                                        */
  real_T puRPM_Gain;                   /* Expression: 900
                                        * Referenced by: '<S275>/pu->RPM'
                                        */
  real_T RPMDisplacementssec_Gain;     /* Expression: 1/120*Vd/V*volumeEfficiency
                                        * Referenced by: '<S275>/RPM->Displacements//sec'
                                        */
  real_T IntegralGain_Gain_p1;         /* Expression: I
                                        * Referenced by: '<S276>/Integral Gain'
                                        */
  real_T Kb_Gain;                      /* Expression: Kb
                                        * Referenced by: '<S276>/Kb'
                                        */
  real_T kgseclbmhr_Gain;              /* Expression: 1/.000126
                                        * Referenced by: '<S264>/kg//sec->lbm//hr'
                                        */
  real_T N_Gain;                       /* Expression: SM.N
                                        * Referenced by: '<S281>/N'
                                        */
  real_T Vkd0Vkq10Vkq20_Value[2];      /* Expression: zeros(1, SM.nState-3)
                                        * Referenced by: '<S281>/[ Vkd =0 Vkq1=0  Vkq2=0 ]'
                                        */
  real_T _Pb_Gain;                     /* Expression: 1/SM.Pb
                                        * Referenced by: '<S303>/1_Pb'
                                        */
  real_T F1_Gain;                      /* Expression: SM.F
                                        * Referenced by: '<S303>/F1'
                                        */
  real_T _2H_Gain;                     /* Expression: 1/(2*SM.H)
                                        * Referenced by: '<S303>/1_(2H)'
                                        */
  real_T web1_Gain;                    /* Expression: SM.web
                                        * Referenced by: '<S303>/web1'
                                        */
  real_T web3_Gain;                    /* Expression: SM.web
                                        * Referenced by: '<S303>/web3'
                                        */
  real_T IntegralGain_Gain_i;          /* Expression: I
                                        * Referenced by: '<S306>/Integral Gain'
                                        */
  real_T Kb_Gain_b;                    /* Expression: Kb
                                        * Referenced by: '<S306>/Kb'
                                        */
  real_T IntegralGain_Gain_b;          /* Expression: I
                                        * Referenced by: '<S307>/Integral Gain'
                                        */
  real_T Kb_Gain_c;                    /* Expression: Kb
                                        * Referenced by: '<S307>/Kb'
                                        */
  real_T IntegralGain_Gain_h;          /* Expression: I
                                        * Referenced by: '<S308>/Integral Gain'
                                        */
  real_T Kb_Gain_o;                    /* Expression: Kb
                                        * Referenced by: '<S308>/Kb'
                                        */
  real_T Constant_Value_do;            /* Expression: 0
                                        * Referenced by: '<S326>/Constant'
                                        */
  real_T Constant_Value_hi;            /* Expression: 0
                                        * Referenced by: '<S327>/Constant'
                                        */
  real_T Switch_Threshold_h;           /* Expression: 0.5
                                        * Referenced by: '<S250>/Switch'
                                        */
  real_T OpCtrl_P1_Size[2];            /* Computed Parameter: OpCtrl_P1_Size
                                        * Referenced by: '<S254>/OpCtrl'
                                        */
  real_T OpCtrl_P1[6];                 /* Computed Parameter: OpCtrl_P1
                                        * Referenced by: '<S254>/OpCtrl'
                                        */
  real_T OpCtrl_P2_Size[2];            /* Computed Parameter: OpCtrl_P2_Size
                                        * Referenced by: '<S254>/OpCtrl'
                                        */
  real_T OpCtrl_P2;                    /* Expression: boardid
                                        * Referenced by: '<S254>/OpCtrl'
                                        */
  real_T OpCtrl_P3_Size[2];            /* Computed Parameter: OpCtrl_P3_Size
                                        * Referenced by: '<S254>/OpCtrl'
                                        */
  real_T OpCtrl_P3;                    /* Expression: mode
                                        * Referenced by: '<S254>/OpCtrl'
                                        */
  real_T OpCtrl_P4_Size[2];            /* Computed Parameter: OpCtrl_P4_Size
                                        * Referenced by: '<S254>/OpCtrl'
                                        */
  real_T OpCtrl_P4;                    /* Expression: externalClock
                                        * Referenced by: '<S254>/OpCtrl'
                                        */
  real_T OpCtrl_P5_Size[2];            /* Computed Parameter: OpCtrl_P5_Size
                                        * Referenced by: '<S254>/OpCtrl'
                                        */
  real_T OpCtrl_P5;                    /* Expression: decimRtsi
                                        * Referenced by: '<S254>/OpCtrl'
                                        */
  real_T OpCtrl_P6_Size[2];            /* Computed Parameter: OpCtrl_P6_Size
                                        * Referenced by: '<S254>/OpCtrl'
                                        */
  real_T OpCtrl_P6;                    /* Expression: 1
                                        * Referenced by: '<S254>/OpCtrl'
                                        */
  real_T OpCtrl_P7_Size[2];            /* Computed Parameter: OpCtrl_P7_Size
                                        * Referenced by: '<S254>/OpCtrl'
                                        */
  real_T OpCtrl_P7;                    /* Expression: SampleTime
                                        * Referenced by: '<S254>/OpCtrl'
                                        */
  real_T OpCtrl_P8_Size[2];            /* Computed Parameter: OpCtrl_P8_Size
                                        * Referenced by: '<S254>/OpCtrl'
                                        */
  real_T OpCtrl_P8;                    /* Expression: calibIO
                                        * Referenced by: '<S254>/OpCtrl'
                                        */
  real_T OpCtrl_P9_Size[2];            /* Computed Parameter: OpCtrl_P9_Size
                                        * Referenced by: '<S254>/OpCtrl'
                                        */
  real_T OpCtrl_P9;                    /* Expression: numconfig
                                        * Referenced by: '<S254>/OpCtrl'
                                        */
  real_T OpCtrl_P10_Size[2];           /* Computed Parameter: OpCtrl_P10_Size
                                        * Referenced by: '<S254>/OpCtrl'
                                        */
  real_T OpCtrl_P10;                   /* Expression: loadinport
                                        * Referenced by: '<S254>/OpCtrl'
                                        */
  real_T OpCtrl_P11_Size[2];           /* Computed Parameter: OpCtrl_P11_Size
                                        * Referenced by: '<S254>/OpCtrl'
                                        */
  real_T OpCtrl_P11;                   /* Expression: BoardType
                                        * Referenced by: '<S254>/OpCtrl'
                                        */
  real_T OpCtrl_P12_Size[2];           /* Computed Parameter: OpCtrl_P12_Size
                                        * Referenced by: '<S254>/OpCtrl'
                                        */
  real_T OpCtrl_P12;                   /* Expression: sync_type
                                        * Referenced by: '<S254>/OpCtrl'
                                        */
  real_T DigitalOut_P1_Size[2];        /* Computed Parameter: DigitalOut_P1_Size
                                        * Referenced by: '<S311>/DigitalOut'
                                        */
  real_T DigitalOut_P1[6];             /* Computed Parameter: DigitalOut_P1
                                        * Referenced by: '<S311>/DigitalOut'
                                        */
  real_T DigitalOut_P2_Size[2];        /* Computed Parameter: DigitalOut_P2_Size
                                        * Referenced by: '<S311>/DigitalOut'
                                        */
  real_T DigitalOut_P3_Size[2];        /* Computed Parameter: DigitalOut_P3_Size
                                        * Referenced by: '<S311>/DigitalOut'
                                        */
  real_T DigitalOut_P3;                /* Expression: portNb
                                        * Referenced by: '<S311>/DigitalOut'
                                        */
  real_T DigitalOut_P4_Size[2];        /* Computed Parameter: DigitalOut_P4_Size
                                        * Referenced by: '<S311>/DigitalOut'
                                        */
  real_T DigitalOut_P4;                /* Expression: size
                                        * Referenced by: '<S311>/DigitalOut'
                                        */
  real_T DigitalOut_P5_Size[2];        /* Computed Parameter: DigitalOut_P5_Size
                                        * Referenced by: '<S311>/DigitalOut'
                                        */
  real_T DigitalOut_P5;                /* Expression: count
                                        * Referenced by: '<S311>/DigitalOut'
                                        */
  real_T DigitalOut_P6_Size[2];        /* Computed Parameter: DigitalOut_P6_Size
                                        * Referenced by: '<S311>/DigitalOut'
                                        */
  real_T DigitalOut_P6;                /* Expression: maxcount
                                        * Referenced by: '<S311>/DigitalOut'
                                        */
  real_T Constant_Value_cq;            /* Expression: 0
                                        * Referenced by: '<S330>/Constant'
                                        */
  real_T Constant_Value_d2;            /* Expression: 0
                                        * Referenced by: '<S331>/Constant'
                                        */
  real_T Constant_Value_bp;            /* Expression: 0
                                        * Referenced by: '<S332>/Constant'
                                        */
  real_T Constant3_Value_h;            /* Expression: 1
                                        * Referenced by: '<S312>/Constant3'
                                        */
  real_T Constant_Value_er;            /* Expression: 0
                                        * Referenced by: '<S321>/Constant'
                                        */
  real_T Constant_Value_lm;            /* Expression: 0
                                        * Referenced by: '<S322>/Constant'
                                        */
  real_T Constant_Value_hj;            /* Expression: 0
                                        * Referenced by: '<S323>/Constant'
                                        */
  real_T Constant_Value_he;            /* Expression: 0
                                        * Referenced by: '<S324>/Constant'
                                        */
  real_T Constant_Value_ls;            /* Expression: 0
                                        * Referenced by: '<S328>/Constant'
                                        */
  real_T Constant_Value_of;            /* Expression: 0
                                        * Referenced by: '<S329>/Constant'
                                        */
  real_T PWMOut_P1_Size[2];            /* Computed Parameter: PWMOut_P1_Size
                                        * Referenced by: '<S314>/PWM Out'
                                        */
  real_T PWMOut_P1[6];                 /* Computed Parameter: PWMOut_P1
                                        * Referenced by: '<S314>/PWM Out'
                                        */
  real_T PWMOut_P2_Size[2];            /* Computed Parameter: PWMOut_P2_Size
                                        * Referenced by: '<S314>/PWM Out'
                                        */
  real_T PWMOut_P3_Size[2];            /* Computed Parameter: PWMOut_P3_Size
                                        * Referenced by: '<S314>/PWM Out'
                                        */
  real_T PWMOut_P3;                    /* Expression: portNb
                                        * Referenced by: '<S314>/PWM Out'
                                        */
  real_T PWMOut_P4_Size[2];            /* Computed Parameter: PWMOut_P4_Size
                                        * Referenced by: '<S314>/PWM Out'
                                        */
  real_T PWMOut_P4;                    /* Expression: size
                                        * Referenced by: '<S314>/PWM Out'
                                        */
  real_T PWMOut_P5_Size[2];            /* Computed Parameter: PWMOut_P5_Size
                                        * Referenced by: '<S314>/PWM Out'
                                        */
  real_T PWMOut_P5;                    /* Expression: numchan
                                        * Referenced by: '<S314>/PWM Out'
                                        */
  real_T PWMOut_P6_Size[2];            /* Computed Parameter: PWMOut_P6_Size
                                        * Referenced by: '<S314>/PWM Out'
                                        */
  real_T PWMOut_P6;                    /* Expression: polarity
                                        * Referenced by: '<S314>/PWM Out'
                                        */
  real_T PWMOut_P7_Size[2];            /* Computed Parameter: PWMOut_P7_Size
                                        * Referenced by: '<S314>/PWM Out'
                                        */
  real_T PWMOut_P7;                    /* Expression: symMode
                                        * Referenced by: '<S314>/PWM Out'
                                        */
  real_T PWMOut_P8_Size[2];            /* Computed Parameter: PWMOut_P8_Size
                                        * Referenced by: '<S314>/PWM Out'
                                        */
  real_T PWMOut_P8;                    /* Expression: complementary
                                        * Referenced by: '<S314>/PWM Out'
                                        */
  real_T PWMOut_P9_Size[2];            /* Computed Parameter: PWMOut_P9_Size
                                        * Referenced by: '<S314>/PWM Out'
                                        */
  real_T PWMOut_P9;                    /* Expression: deadTime
                                        * Referenced by: '<S314>/PWM Out'
                                        */
  real_T PWMOut_P10_Size[2];           /* Computed Parameter: PWMOut_P10_Size
                                        * Referenced by: '<S314>/PWM Out'
                                        */
  real_T PWMOut_P10;                   /* Expression: loadnb
                                        * Referenced by: '<S314>/PWM Out'
                                        */
  real_T PWMOut_P11_Size[2];           /* Computed Parameter: PWMOut_P11_Size
                                        * Referenced by: '<S314>/PWM Out'
                                        */
  real_T PWMOut_P11[8];                /* Expression: initphase
                                        * Referenced by: '<S314>/PWM Out'
                                        */
  real_T PWMOut_P12_Size[2];           /* Computed Parameter: PWMOut_P12_Size
                                        * Referenced by: '<S314>/PWM Out'
                                        */
  real_T PWMOut_P12;                   /* Expression: maxcount
                                        * Referenced by: '<S314>/PWM Out'
                                        */
  real_T PWMOut1_P1_Size[2];           /* Computed Parameter: PWMOut1_P1_Size
                                        * Referenced by: '<S314>/PWM Out1'
                                        */
  real_T PWMOut1_P1[6];                /* Computed Parameter: PWMOut1_P1
                                        * Referenced by: '<S314>/PWM Out1'
                                        */
  real_T PWMOut1_P2_Size[2];           /* Computed Parameter: PWMOut1_P2_Size
                                        * Referenced by: '<S314>/PWM Out1'
                                        */
  real_T PWMOut1_P3_Size[2];           /* Computed Parameter: PWMOut1_P3_Size
                                        * Referenced by: '<S314>/PWM Out1'
                                        */
  real_T PWMOut1_P3;                   /* Expression: portNb
                                        * Referenced by: '<S314>/PWM Out1'
                                        */
  real_T PWMOut1_P4_Size[2];           /* Computed Parameter: PWMOut1_P4_Size
                                        * Referenced by: '<S314>/PWM Out1'
                                        */
  real_T PWMOut1_P4;                   /* Expression: size
                                        * Referenced by: '<S314>/PWM Out1'
                                        */
  real_T PWMOut1_P5_Size[2];           /* Computed Parameter: PWMOut1_P5_Size
                                        * Referenced by: '<S314>/PWM Out1'
                                        */
  real_T PWMOut1_P5;                   /* Expression: numchan
                                        * Referenced by: '<S314>/PWM Out1'
                                        */
  real_T PWMOut1_P6_Size[2];           /* Computed Parameter: PWMOut1_P6_Size
                                        * Referenced by: '<S314>/PWM Out1'
                                        */
  real_T PWMOut1_P6;                   /* Expression: polarity
                                        * Referenced by: '<S314>/PWM Out1'
                                        */
  real_T PWMOut1_P7_Size[2];           /* Computed Parameter: PWMOut1_P7_Size
                                        * Referenced by: '<S314>/PWM Out1'
                                        */
  real_T PWMOut1_P7;                   /* Expression: symMode
                                        * Referenced by: '<S314>/PWM Out1'
                                        */
  real_T PWMOut1_P8_Size[2];           /* Computed Parameter: PWMOut1_P8_Size
                                        * Referenced by: '<S314>/PWM Out1'
                                        */
  real_T PWMOut1_P8;                   /* Expression: complementary
                                        * Referenced by: '<S314>/PWM Out1'
                                        */
  real_T PWMOut1_P9_Size[2];           /* Computed Parameter: PWMOut1_P9_Size
                                        * Referenced by: '<S314>/PWM Out1'
                                        */
  real_T PWMOut1_P9;                   /* Expression: deadTime
                                        * Referenced by: '<S314>/PWM Out1'
                                        */
  real_T PWMOut1_P10_Size[2];          /* Computed Parameter: PWMOut1_P10_Size
                                        * Referenced by: '<S314>/PWM Out1'
                                        */
  real_T PWMOut1_P10;                  /* Expression: loadnb
                                        * Referenced by: '<S314>/PWM Out1'
                                        */
  real_T PWMOut1_P11_Size[2];          /* Computed Parameter: PWMOut1_P11_Size
                                        * Referenced by: '<S314>/PWM Out1'
                                        */
  real_T PWMOut1_P11[8];               /* Expression: initphase
                                        * Referenced by: '<S314>/PWM Out1'
                                        */
  real_T PWMOut1_P12_Size[2];          /* Computed Parameter: PWMOut1_P12_Size
                                        * Referenced by: '<S314>/PWM Out1'
                                        */
  real_T PWMOut1_P12;                  /* Expression: maxcount
                                        * Referenced by: '<S314>/PWM Out1'
                                        */
  real_T EventGenerator_P1_Size[2];    /* Computed Parameter: EventGenerator_P1_Size
                                        * Referenced by: '<S315>/EventGenerator'
                                        */
  real_T EventGenerator_P1[6];         /* Computed Parameter: EventGenerator_P1
                                        * Referenced by: '<S315>/EventGenerator'
                                        */
  real_T EventGenerator_P2_Size[2];    /* Computed Parameter: EventGenerator_P2_Size
                                        * Referenced by: '<S315>/EventGenerator'
                                        */
  real_T EventGenerator_P2;            /* Expression: portNb
                                        * Referenced by: '<S315>/EventGenerator'
                                        */
  real_T EventGenerator_P3_Size[2];    /* Computed Parameter: EventGenerator_P3_Size
                                        * Referenced by: '<S315>/EventGenerator'
                                        */
  real_T EventGenerator_P4_Size[2];    /* Computed Parameter: EventGenerator_P4_Size
                                        * Referenced by: '<S315>/EventGenerator'
                                        */
  real_T EventGenerator_P4;            /* Expression: size
                                        * Referenced by: '<S315>/EventGenerator'
                                        */
  real_T EventGenerator_P5_Size[2];    /* Computed Parameter: EventGenerator_P5_Size
                                        * Referenced by: '<S315>/EventGenerator'
                                        */
  real_T EventGenerator_P5;            /* Expression: nbChannels
                                        * Referenced by: '<S315>/EventGenerator'
                                        */
  real_T EventGenerator_P6_Size[2];    /* Computed Parameter: EventGenerator_P6_Size
                                        * Referenced by: '<S315>/EventGenerator'
                                        */
  real_T EventGenerator_P6;            /* Expression: numwidth
                                        * Referenced by: '<S315>/EventGenerator'
                                        */
  real_T EventGenerator_P7_Size[2];    /* Computed Parameter: EventGenerator_P7_Size
                                        * Referenced by: '<S315>/EventGenerator'
                                        */
  real_T EventGenerator_P7;            /* Expression: timeUnit
                                        * Referenced by: '<S315>/EventGenerator'
                                        */
  real_T EventGenerator1_P1_Size[2];   /* Computed Parameter: EventGenerator1_P1_Size
                                        * Referenced by: '<S315>/EventGenerator1'
                                        */
  real_T EventGenerator1_P1[6];        /* Computed Parameter: EventGenerator1_P1
                                        * Referenced by: '<S315>/EventGenerator1'
                                        */
  real_T EventGenerator1_P2_Size[2];   /* Computed Parameter: EventGenerator1_P2_Size
                                        * Referenced by: '<S315>/EventGenerator1'
                                        */
  real_T EventGenerator1_P2;           /* Expression: portNb
                                        * Referenced by: '<S315>/EventGenerator1'
                                        */
  real_T EventGenerator1_P3_Size[2];   /* Computed Parameter: EventGenerator1_P3_Size
                                        * Referenced by: '<S315>/EventGenerator1'
                                        */
  real_T EventGenerator1_P4_Size[2];   /* Computed Parameter: EventGenerator1_P4_Size
                                        * Referenced by: '<S315>/EventGenerator1'
                                        */
  real_T EventGenerator1_P4;           /* Expression: size
                                        * Referenced by: '<S315>/EventGenerator1'
                                        */
  real_T EventGenerator1_P5_Size[2];   /* Computed Parameter: EventGenerator1_P5_Size
                                        * Referenced by: '<S315>/EventGenerator1'
                                        */
  real_T EventGenerator1_P5;           /* Expression: nbChannels
                                        * Referenced by: '<S315>/EventGenerator1'
                                        */
  real_T EventGenerator1_P6_Size[2];   /* Computed Parameter: EventGenerator1_P6_Size
                                        * Referenced by: '<S315>/EventGenerator1'
                                        */
  real_T EventGenerator1_P6;           /* Expression: numwidth
                                        * Referenced by: '<S315>/EventGenerator1'
                                        */
  real_T EventGenerator1_P7_Size[2];   /* Computed Parameter: EventGenerator1_P7_Size
                                        * Referenced by: '<S315>/EventGenerator1'
                                        */
  real_T EventGenerator1_P7;           /* Expression: timeUnit
                                        * Referenced by: '<S315>/EventGenerator1'
                                        */
  real_T AnalogIn1_P1_Size[2];         /* Computed Parameter: AnalogIn1_P1_Size
                                        * Referenced by: '<S339>/AnalogIn1'
                                        */
  real_T AnalogIn1_P1[6];              /* Computed Parameter: AnalogIn1_P1
                                        * Referenced by: '<S339>/AnalogIn1'
                                        */
  real_T AnalogIn1_P2_Size[2];         /* Computed Parameter: AnalogIn1_P2_Size
                                        * Referenced by: '<S339>/AnalogIn1'
                                        */
  real_T AnalogIn1_P3_Size[2];         /* Computed Parameter: AnalogIn1_P3_Size
                                        * Referenced by: '<S339>/AnalogIn1'
                                        */
  real_T AnalogIn1_P3;                 /* Expression: sampleTime
                                        * Referenced by: '<S339>/AnalogIn1'
                                        */
  real_T AnalogIn1_P4_Size[2];         /* Computed Parameter: AnalogIn1_P4_Size
                                        * Referenced by: '<S339>/AnalogIn1'
                                        */
  real_T AnalogIn1_P4;                 /* Expression: portNb
                                        * Referenced by: '<S339>/AnalogIn1'
                                        */
  real_T AnalogIn1_P5_Size[2];         /* Computed Parameter: AnalogIn1_P5_Size
                                        * Referenced by: '<S339>/AnalogIn1'
                                        */
  real_T AnalogIn1_P5;                 /* Expression: size
                                        * Referenced by: '<S339>/AnalogIn1'
                                        */
  real_T AnalogIn1_P6_Size[2];         /* Computed Parameter: AnalogIn1_P6_Size
                                        * Referenced by: '<S339>/AnalogIn1'
                                        */
  real_T AnalogIn1_P6;                 /* Expression: numchan
                                        * Referenced by: '<S339>/AnalogIn1'
                                        */
  real_T AnalogIn1_P7_Size[2];         /* Computed Parameter: AnalogIn1_P7_Size
                                        * Referenced by: '<S339>/AnalogIn1'
                                        */
  real_T AnalogIn1_P7;                 /* Expression: maxcount
                                        * Referenced by: '<S339>/AnalogIn1'
                                        */
  real_T Subsection3DOUTtype_Value;    /* Expression: 1
                                        * Referenced by: '<S313>/Subsection 3 DOUT type'
                                        */
  real_T DataInSend_P1_Size[2];        /* Computed Parameter: DataInSend_P1_Size
                                        * Referenced by: '<S313>/DataIn Send'
                                        */
  real_T DataInSend_P1[6];             /* Computed Parameter: DataInSend_P1
                                        * Referenced by: '<S313>/DataIn Send'
                                        */
  real_T DataInSend_P2_Size[2];        /* Computed Parameter: DataInSend_P2_Size
                                        * Referenced by: '<S313>/DataIn Send'
                                        */
  real_T DataInSend_P2;                /* Expression: FcnNos
                                        * Referenced by: '<S313>/DataIn Send'
                                        */
  real_T DataInSend_P3_Size[2];        /* Computed Parameter: DataInSend_P3_Size
                                        * Referenced by: '<S313>/DataIn Send'
                                        */
  real_T DataInSend_P3;                /* Expression: width
                                        * Referenced by: '<S313>/DataIn Send'
                                        */
  real_T DataInSend_P4_Size[2];        /* Computed Parameter: DataInSend_P4_Size
                                        * Referenced by: '<S313>/DataIn Send'
                                        */
  real_T DataInSend_P4;                /* Expression: portType
                                        * Referenced by: '<S313>/DataIn Send'
                                        */
  real_T DataInSend_P5_Size[2];        /* Computed Parameter: DataInSend_P5_Size
                                        * Referenced by: '<S313>/DataIn Send'
                                        */
  real_T DataInSend_P5;                /* Expression: checkVersion
                                        * Referenced by: '<S313>/DataIn Send'
                                        */
  real_T DataInSend_P6_Size[2];        /* Computed Parameter: DataInSend_P6_Size
                                        * Referenced by: '<S313>/DataIn Send'
                                        */
  real_T DataInSend_P6;                /* Expression: expectedId
                                        * Referenced by: '<S313>/DataIn Send'
                                        */
  real_T DataInSend_P7_Size[2];        /* Computed Parameter: DataInSend_P7_Size
                                        * Referenced by: '<S313>/DataIn Send'
                                        */
  real_T DataInSend_P7;                /* Expression: expectedVersion
                                        * Referenced by: '<S313>/DataIn Send'
                                        */
  real_T DataInSend_P8_Size[2];        /* Computed Parameter: DataInSend_P8_Size
                                        * Referenced by: '<S313>/DataIn Send'
                                        */
  real_T DataInSend_P8;                /* Expression: opComp
                                        * Referenced by: '<S313>/DataIn Send'
                                        */
  real_T Subsection4DOUTtype_Value;    /* Expression: 1
                                        * Referenced by: '<S313>/Subsection 4 DOUT type'
                                        */
  real_T DataInSend1_P1_Size[2];       /* Computed Parameter: DataInSend1_P1_Size
                                        * Referenced by: '<S313>/DataIn Send1'
                                        */
  real_T DataInSend1_P1[6];            /* Computed Parameter: DataInSend1_P1
                                        * Referenced by: '<S313>/DataIn Send1'
                                        */
  real_T DataInSend1_P2_Size[2];       /* Computed Parameter: DataInSend1_P2_Size
                                        * Referenced by: '<S313>/DataIn Send1'
                                        */
  real_T DataInSend1_P2;               /* Expression: FcnNos
                                        * Referenced by: '<S313>/DataIn Send1'
                                        */
  real_T DataInSend1_P3_Size[2];       /* Computed Parameter: DataInSend1_P3_Size
                                        * Referenced by: '<S313>/DataIn Send1'
                                        */
  real_T DataInSend1_P3;               /* Expression: width
                                        * Referenced by: '<S313>/DataIn Send1'
                                        */
  real_T DataInSend1_P4_Size[2];       /* Computed Parameter: DataInSend1_P4_Size
                                        * Referenced by: '<S313>/DataIn Send1'
                                        */
  real_T DataInSend1_P4;               /* Expression: portType
                                        * Referenced by: '<S313>/DataIn Send1'
                                        */
  real_T DataInSend1_P5_Size[2];       /* Computed Parameter: DataInSend1_P5_Size
                                        * Referenced by: '<S313>/DataIn Send1'
                                        */
  real_T DataInSend1_P5;               /* Expression: checkVersion
                                        * Referenced by: '<S313>/DataIn Send1'
                                        */
  real_T DataInSend1_P6_Size[2];       /* Computed Parameter: DataInSend1_P6_Size
                                        * Referenced by: '<S313>/DataIn Send1'
                                        */
  real_T DataInSend1_P6;               /* Expression: expectedId
                                        * Referenced by: '<S313>/DataIn Send1'
                                        */
  real_T DataInSend1_P7_Size[2];       /* Computed Parameter: DataInSend1_P7_Size
                                        * Referenced by: '<S313>/DataIn Send1'
                                        */
  real_T DataInSend1_P7;               /* Expression: expectedVersion
                                        * Referenced by: '<S313>/DataIn Send1'
                                        */
  real_T DataInSend1_P8_Size[2];       /* Computed Parameter: DataInSend1_P8_Size
                                        * Referenced by: '<S313>/DataIn Send1'
                                        */
  real_T DataInSend1_P8;               /* Expression: opComp
                                        * Referenced by: '<S313>/DataIn Send1'
                                        */
  real_T donotdeletethisgain_Gain_a2;  /* Expression: 1
                                        * Referenced by: '<S401>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_de;  /* Expression: 1
                                        * Referenced by: '<S402>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_kyl; /* Expression: 1
                                        * Referenced by: '<S403>/do not delete this gain'
                                        */
  real_T Kv1_Gain_if;                  /* Expression: Kv
                                        * Referenced by: '<S383>/Kv1'
                                        */
  real_T donotdeletethisgain_Gain_bp;  /* Expression: 1
                                        * Referenced by: '<S398>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_nz;  /* Expression: 1
                                        * Referenced by: '<S399>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_fq;  /* Expression: 1
                                        * Referenced by: '<S400>/do not delete this gain'
                                        */
  real_T Kv_Gain_i;                    /* Expression: Ki
                                        * Referenced by: '<S383>/Kv'
                                        */
  real_T puV_Gain;                     /* Expression: 1/sqrt(3)
                                        * Referenced by: '<S384>/pu->V'
                                        */
  real_T Constant_Value_hm;            /* Expression: Vinit
                                        * Referenced by: '<S385>/Constant'
                                        */
  real_T Integ4_gainval_m;             /* Computed Parameter: Integ4_gainval_m
                                        * Referenced by: '<S385>/Integ4'
                                        */
  real_T Integ4_IC_ag;                 /* Expression: 0
                                        * Referenced by: '<S385>/Integ4'
                                        */
  real_T K1_Value_b;                   /* Expression: Delay
                                        * Referenced by: '<S385>/K1'
                                        */
  real_T UnitDelay_InitialCondition_f; /* Expression: 0
                                        * Referenced by: '<S385>/Unit Delay'
                                        */
  real_T K2_Value_d;                   /* Expression: Freq
                                        * Referenced by: '<S385>/K2'
                                        */
  real_T Step_Time_e;                  /* Expression: 1/Freq
                                        * Referenced by: '<S385>/Step'
                                        */
  real_T Step_Y0_p;                    /* Expression: 0
                                        * Referenced by: '<S385>/Step'
                                        */
  real_T Step_YFinal_e;                /* Expression: 1
                                        * Referenced by: '<S385>/Step'
                                        */
  real_T Switch_Threshold_hb;          /* Expression: 0.5
                                        * Referenced by: '<S385>/Switch'
                                        */
  real_T Gain_Gain_dl;                 /* Expression: 1/1000
                                        * Referenced by: '<S381>/Gain'
                                        */
  real_T a_Gain;                       /* Expression: 1/(13800*sqrt(2/3))
                                        * Referenced by: '<S3>/a'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S734>/Memory'
                                        */
  real_T DiscreteTimeIntegrtor_gainval;/* Computed Parameter: DiscreteTimeIntegrtor_gainval
                                        * Referenced by: '<S734>/Discrete-Time Integrtor'
                                        */
  real_T DiscreteTimeIntegrtor_IC;     /* Expression: 0
                                        * Referenced by: '<S734>/Discrete-Time Integrtor'
                                        */
  real_T operation_mode_Value;         /* Expression: 1
                                        * Referenced by: '<S732>/operation_mode'
                                        */
  real_T enable_event_Value;           /* Expression: 0
                                        * Referenced by: '<S732>/enable_event'
                                        */
  real_T Constant_Value_la;            /* Expression: const
                                        * Referenced by: '<S742>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainva_p;/* Computed Parameter: DiscreteTimeIntegrator_gainva_p
                                          * Referenced by: '<S745>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_h;  /* Expression: Phase_Init*pi/180
                                        * Referenced by: '<S745>/Discrete-Time Integrator'
                                        */
  real_T Constant4_Value_f;            /* Expression: 2*pi
                                        * Referenced by: '<S745>/Constant4'
                                        */
  real_T Levelcrossing2_Value;         /* Expression: usePLL
                                        * Referenced by: '<S733>/Level crossing2'
                                        */
  real_T SyncPhase_Value;              /* Expression: SyncPhase
                                        * Referenced by: '<S733>/SyncPhase'
                                        */
  real_T Switch1_Threshold_lv;         /* Expression: 0.5
                                        * Referenced by: '<S733>/Switch1'
                                        */
  real_T Constant_Value_ct;            /* Expression: vlevel
                                        * Referenced by: '<S747>/Constant'
                                        */
  real_T Saturation_UpperSat_gj;       /* Expression: 1
                                        * Referenced by: '<S747>/Saturation'
                                        */
  real_T Saturation_LowerSat_d0;       /* Expression: -1
                                        * Referenced by: '<S747>/Saturation'
                                        */
  real_T Constant_Value_p5;            /* Expression: vlevel
                                        * Referenced by: '<S746>/Constant'
                                        */
  real_T Saturation_UpperSat_ny;       /* Expression: 1
                                        * Referenced by: '<S746>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: -1
                                        * Referenced by: '<S746>/Saturation'
                                        */
  real_T Switch1_Threshold_o;          /* Expression: 0.5
                                        * Referenced by: '<S22>/Switch1'
                                        */
  real_T Memory_X0_n;                  /* Expression: 0
                                        * Referenced by: '<S741>/Memory'
                                        */
  real_T DiscreteTimeIntegrator1_gainv_p;/* Computed Parameter: DiscreteTimeIntegrator1_gainv_p
                                          * Referenced by: '<S741>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC_d; /* Expression: 0
                                        * Referenced by: '<S741>/Discrete-Time Integrator1'
                                        */
  real_T DiscreteTimeIntegrator1_UpperSa;/* Expression: 1000
                                          * Referenced by: '<S741>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_LowerSa;/* Expression: -1000
                                          * Referenced by: '<S741>/Discrete-Time Integrator1'
                                          */
  real_T operation_mode_Value_i;       /* Expression: 1
                                        * Referenced by: '<S731>/operation_mode'
                                        */
  real_T Memory_X0_f;                  /* Expression: 0
                                        * Referenced by: '<S737>/Memory'
                                        */
  real_T DiscreteTimeIntegrtor_gainval_k;/* Computed Parameter: DiscreteTimeIntegrtor_gainval_k
                                          * Referenced by: '<S737>/Discrete-Time Integrtor'
                                          */
  real_T DiscreteTimeIntegrtor_IC_a;   /* Expression: 0
                                        * Referenced by: '<S737>/Discrete-Time Integrtor'
                                        */
  real_T degrad1_Gain;                 /* Expression: 2*pi/360
                                        * Referenced by: '<S731>/deg//rad1'
                                        */
  real_T HitCrossing_Offset_e;         /* Expression: 0
                                        * Referenced by: '<S735>/Hit  Crossing'
                                        */
  real_T DiscreteTimeIntegrator_gainva_e;/* Computed Parameter: DiscreteTimeIntegrator_gainva_e
                                          * Referenced by: '<S741>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_k;  /* Expression: 0
                                        * Referenced by: '<S741>/Discrete-Time Integrator'
                                        */
  real_T Memory_X0_p;                  /* Expression: 0
                                        * Referenced by: '<S738>/Memory'
                                        */
  real_T DiscreteTimeIntegrtor_gainval_n;/* Computed Parameter: DiscreteTimeIntegrtor_gainval_n
                                          * Referenced by: '<S738>/Discrete-Time Integrtor'
                                          */
  real_T DiscreteTimeIntegrtor_IC_g;   /* Expression: 0
                                        * Referenced by: '<S738>/Discrete-Time Integrtor'
                                        */
  real_T POW_en_switch_Threshold;      /* Expression: 0.5
                                        * Referenced by: '<S735>/POW_en_switch'
                                        */
  real_T DelayInput1_InitialCondition; /* Expression: 0
                                        * Referenced by: '<S739>/Delay Input1'
                                        */
  real_T UnitDelay_InitialCondition_dj;/* Expression: 0
                                        * Referenced by: '<S739>/Unit Delay'
                                        */
  real_T Constant_Value_ap;            /* Expression: 1
                                        * Referenced by: '<S739>/Constant'
                                        */
  real_T WeightedSampleTimeMath_WtEt;  /* Computed Parameter: WeightedSampleTimeMath_WtEt
                                        * Referenced by: '<S739>/Weighted Sample Time Math'
                                        */
  real_T Constant1_Value_p;            /* Expression: -1
                                        * Referenced by: '<S739>/Constant1'
                                        */
  real_T WeightedSampleTimeMath1_WtEt; /* Computed Parameter: WeightedSampleTimeMath1_WtEt
                                        * Referenced by: '<S739>/Weighted Sample Time Math1'
                                        */
  real_T operation_mode_Value_e;       /* Expression: 1
                                        * Referenced by: '<S741>/operation_mode'
                                        */
  real_T Integ4_gainval_pd;            /* Computed Parameter: Integ4_gainval_pd
                                        * Referenced by: '<S752>/Integ4'
                                        */
  real_T Integ4_IC_at;                 /* Expression: 0
                                        * Referenced by: '<S752>/Integ4'
                                        */
  real_T UnitDelay_InitialCondition_ou;/* Expression: Finit
                                        * Referenced by: '<S745>/Unit Delay'
                                        */
  real_T Toavoiddivisionbyzero_UpperSa_o;/* Expression: 1e6
                                          * Referenced by: '<S752>/To avoid division by zero'
                                          */
  real_T Toavoiddivisionbyzero_LowerS_mu;/* Expression: 1e-6
                                          * Referenced by: '<S752>/To avoid division by zero'
                                          */
  real_T Gain_Gain_hq;                 /* Expression: Ts
                                        * Referenced by: '<S752>/Gain'
                                        */
  real_T UnitDelay_InitialCondition_di;/* Expression: 0
                                        * Referenced by: '<S762>/Unit Delay'
                                        */
  real_T Step_Time_i;                  /* Expression: 1/Finit
                                        * Referenced by: '<S752>/Step'
                                        */
  real_T Step_Y0_a;                    /* Expression: 0
                                        * Referenced by: '<S752>/Step'
                                        */
  real_T Step_YFinal_o;                /* Expression: 1
                                        * Referenced by: '<S752>/Step'
                                        */
  real_T Constant_Value_k;             /* Expression: Vinit
                                        * Referenced by: '<S752>/Constant'
                                        */
  real_T Switch_Threshold_e1;          /* Expression: 0.5
                                        * Referenced by: '<S752>/Switch'
                                        */
  real_T Constant1_Value_i;            /* Expression: AGC
                                        * Referenced by: '<S745>/Constant1'
                                        */
  real_T Kp4_Gain;                     /* Expression: Kp
                                        * Referenced by: '<S750>/Kp4'
                                        */
  real_T DiscreteTimeIntegrator_gainv_af;/* Computed Parameter: DiscreteTimeIntegrator_gainv_af
                                          * Referenced by: '<S750>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_ar; /* Expression: Init
                                        * Referenced by: '<S750>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: UpperLimit
                                          * Referenced by: '<S750>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: LowerLimit
                                          * Referenced by: '<S750>/Discrete-Time Integrator'
                                          */
  real_T Kp6_Gain;                     /* Expression: Kd
                                        * Referenced by: '<S750>/Kp6'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S761>/TSamp'
                                        */
  real_T UD_InitialCondition;          /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S761>/UD'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: UpperLimit
                                        * Referenced by: '<S750>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: LowerLimit
                                        * Referenced by: '<S750>/Saturation2'
                                        */
  real_T Gain10_Gain;                  /* Expression: 1/2/pi
                                        * Referenced by: '<S745>/Gain10'
                                        */
  real_T UnitDelay_InitialCondition_n; /* Expression: Vinit
                                        * Referenced by: '<S751>/Unit  Delay'
                                        */
  real_T Saturation_UpperSat_h;        /* Expression: UpperLimit
                                        * Referenced by: '<S751>/Saturation'
                                        */
  real_T Saturation_LowerSat_mq;       /* Expression: LowerLimit
                                        * Referenced by: '<S751>/Saturation'
                                        */
  real_T DiscreteStateSpace_A_fm[4];   /* Computed Parameter: DiscreteStateSpace_A_fm
                                        * Referenced by: '<S748>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_B_du[2];   /* Computed Parameter: DiscreteStateSpace_B_du
                                        * Referenced by: '<S748>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_C_cy[2];   /* Computed Parameter: DiscreteStateSpace_C_cy
                                        * Referenced by: '<S748>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_D_k;       /* Computed Parameter: DiscreteStateSpace_D_k
                                        * Referenced by: '<S748>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_X0_p[2];   /* Expression: x0d
                                        * Referenced by: '<S748>/Discrete State-Space'
                                        */
  real_T Kp5_Gain;                     /* Expression: Ki
                                        * Referenced by: '<S750>/Kp5'
                                        */
  real_T IntegralGain_Gain_j;          /* Expression: I
                                        * Referenced by: '<S565>/Integral Gain'
                                        */
  real_T IntegralGain_Gain_m;          /* Expression: I
                                        * Referenced by: '<S566>/Integral Gain'
                                        */
  real_T VRMSnom_Value;                /* Expression: V/1.7321
                                        * Referenced by: '<S19>/VRMSnom'
                                        */
  real_T Gain1_Gain_nr;                /* Expression: 1.5
                                        * Referenced by: '<S19>/Gain1'
                                        */
  real_T Gain2_Gain_h;                 /* Expression: 0.5
                                        * Referenced by: '<S19>/Gain2'
                                        */
  real_T Memory3_X0_p;                 /* Expression: 0
                                        * Referenced by: '<S567>/Memory3'
                                        */
  real_T Memory4_X0;                   /* Expression: 0
                                        * Referenced by: '<S567>/Memory4'
                                        */
  real_T Memory5_X0_a;                 /* Expression: 0
                                        * Referenced by: '<S567>/Memory5'
                                        */
  real_T Memory6_X0;                   /* Expression: 0
                                        * Referenced by: '<S567>/Memory6'
                                        */
  real_T donotdeletethisgain_Gain_m1;  /* Expression: 1
                                        * Referenced by: '<S597>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_g;   /* Expression: 1
                                        * Referenced by: '<S598>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_ht;  /* Expression: 1
                                        * Referenced by: '<S599>/do not delete this gain'
                                        */
  real_T Kv1_Gain_o;                   /* Expression: Kv
                                        * Referenced by: '<S577>/Kv1'
                                        */
  real_T donotdeletethisgain_Gain_lo;  /* Expression: 1
                                        * Referenced by: '<S594>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_el;  /* Expression: 1
                                        * Referenced by: '<S595>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_cg;  /* Expression: 1
                                        * Referenced by: '<S596>/do not delete this gain'
                                        */
  real_T Kv_Gain_j;                    /* Expression: Ki
                                        * Referenced by: '<S577>/Kv'
                                        */
  real_T puV_Gain_j;                   /* Expression: 1/sqrt(3)
                                        * Referenced by: '<S580>/pu->V'
                                        */
  real_T Integ4_gainval_k;             /* Computed Parameter: Integ4_gainval_k
                                        * Referenced by: '<S583>/Integ4'
                                        */
  real_T Integ4_IC_ai;                 /* Expression: 0
                                        * Referenced by: '<S583>/Integ4'
                                        */
  real_T K1_Value_l;                   /* Expression: Delay
                                        * Referenced by: '<S583>/K1'
                                        */
  real_T K2_Value_b;                   /* Expression: Freq
                                        * Referenced by: '<S583>/K2'
                                        */
  real_T UnitDelay_InitialCondition_i3;/* Expression: 0
                                        * Referenced by: '<S583>/Unit Delay'
                                        */
  real_T Step_Time_f;                  /* Expression: 1/Freq
                                        * Referenced by: '<S583>/Step'
                                        */
  real_T Step_Y0_px;                   /* Expression: 0
                                        * Referenced by: '<S583>/Step'
                                        */
  real_T Step_YFinal_i;                /* Expression: 1
                                        * Referenced by: '<S583>/Step'
                                        */
  real_T Constant_Value_ad;            /* Expression: Vinit
                                        * Referenced by: '<S583>/Constant'
                                        */
  real_T Switch_Threshold_a;           /* Expression: 0.5
                                        * Referenced by: '<S583>/Switch'
                                        */
  real_T Gain_Gain_ek;                 /* Expression: 1/1000
                                        * Referenced by: '<S576>/Gain'
                                        */
  real_T Constant_Value_fn;            /* Expression: const
                                        * Referenced by: '<S581>/Constant'
                                        */
  real_T Constant_Value_in;            /* Expression: const
                                        * Referenced by: '<S582>/Constant'
                                        */
  real_T Constant_Value_jv;            /* Expression: const
                                        * Referenced by: '<S584>/Constant'
                                        */
  real_T FixPtUnitDelay1_InitialConditio;/* Expression: vinit
                                          * Referenced by: '<S585>/FixPt Unit Delay1'
                                          */
  real_T UnitDelay_InitialCondition_dv;/* Expression: sps.Finit
                                        * Referenced by: '<S613>/Unit Delay'
                                        */
  real_T donotdeletethisgain_Gain_nx;  /* Expression: 1
                                        * Referenced by: '<S572>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_jx;  /* Expression: 1
                                        * Referenced by: '<S573>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_an;  /* Expression: 1
                                        * Referenced by: '<S574>/do not delete this gain'
                                        */
  real_T Constant1_Value_b4;           /* Expression: sps.AGC
                                        * Referenced by: '<S613>/Constant1'
                                        */
  real_T Gain3_Gain_c[9];              /* Expression: [ 1   -1/2   -1/2; 0   sqrt(3)/2   -sqrt(3)/2; 1/2  1/2  1/2 ]
                                        * Referenced by: '<S647>/Gain3'
                                        */
  real_T Gain1_Gain_l5;                /* Expression: 2/3
                                        * Referenced by: '<S647>/Gain1'
                                        */
  real_T Constant_Value_ig;            /* Expression: Alignment
                                        * Referenced by: '<S646>/Constant'
                                        */
  real_T Constant_Value_bv;            /* Expression: const
                                        * Referenced by: '<S648>/Constant'
                                        */
  real_T Constant_Value_j5;            /* Expression: const
                                        * Referenced by: '<S649>/Constant'
                                        */
  real_T Integ4_gainval_oy;            /* Computed Parameter: Integ4_gainval_oy
                                        * Referenced by: '<S643>/Integ4'
                                        */
  real_T Integ4_IC_fn;                 /* Expression: 0
                                        * Referenced by: '<S643>/Integ4'
                                        */
  real_T Toavoiddivisionbyzero_UpperS_jp;/* Expression: 1e6
                                          * Referenced by: '<S643>/To avoid division  by zero'
                                          */
  real_T Toavoiddivisionbyzero_LowerS_mz;/* Expression: eps
                                          * Referenced by: '<S643>/To avoid division  by zero'
                                          */
  real_T Gain_Gain_bd;                 /* Expression: Ts
                                        * Referenced by: '<S643>/Gain'
                                        */
  real_T SFunction_P1_Size_fe[2];      /* Computed Parameter: SFunction_P1_Size_fe
                                        * Referenced by: '<S645>/S-Function'
                                        */
  real_T SFunction_P1_fc;              /* Expression: MaxDelay
                                        * Referenced by: '<S645>/S-Function'
                                        */
  real_T SFunction_P2_Size_o[2];       /* Computed Parameter: SFunction_P2_Size_o
                                        * Referenced by: '<S645>/S-Function'
                                        */
  real_T SFunction_P2_o;               /* Expression: Ts
                                        * Referenced by: '<S645>/S-Function'
                                        */
  real_T SFunction_P3_Size_mh[2];      /* Computed Parameter: SFunction_P3_Size_mh
                                        * Referenced by: '<S645>/S-Function'
                                        */
  real_T SFunction_P3_k;               /* Expression: InitialValue
                                        * Referenced by: '<S645>/S-Function'
                                        */
  real_T SFunction_P4_Size_pj[2];      /* Computed Parameter: SFunction_P4_Size_pj
                                        * Referenced by: '<S645>/S-Function'
                                        */
  real_T SFunction_P4_ir;              /* Expression: DFT
                                        * Referenced by: '<S645>/S-Function'
                                        */
  real_T UnitDelay_InitialCondition_k5;/* Expression: 0
                                        * Referenced by: '<S644>/Unit Delay'
                                        */
  real_T Constant_Value_k4;            /* Expression: 1/sps.Finit
                                        * Referenced by: '<S643>/Constant'
                                        */
  real_T UnitDelay1_InitialCondition_k;/* Expression: sps.Vinit
                                        * Referenced by: '<S643>/Unit Delay1'
                                        */
  real_T DiscreteDerivative_NumCoef[2];/* Expression: [ 1  -1 ]*Kd
                                        * Referenced by: '<S615>/Discrete Derivative '
                                        */
  real_T DiscreteDerivative_DenCoef[2];/* Expression: [ TcD  Ts-TcD ]
                                        * Referenced by: '<S615>/Discrete Derivative '
                                        */
  real_T DiscreteDerivative_InitialState;/* Expression: 0
                                          * Referenced by: '<S615>/Discrete Derivative '
                                          */
  real_T DiscreteTimeIntegrator_gainva_l;/* Computed Parameter: DiscreteTimeIntegrator_gainva_l
                                          * Referenced by: '<S615>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_i;  /* Expression: Init
                                        * Referenced by: '<S615>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperS_c;/* Expression: Par_Limits(1)
                                          * Referenced by: '<S615>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_p;/* Expression: Par_Limits(2)
                                          * Referenced by: '<S615>/Discrete-Time Integrator'
                                          */
  real_T Kp4_Gain_g;                   /* Expression: Kp
                                        * Referenced by: '<S615>/Kp4'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: Par_Limits(1)
                                        * Referenced by: '<S615>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: Par_Limits(2)
                                        * Referenced by: '<S615>/Saturation1'
                                        */
  real_T Gain10_Gain_b;                /* Expression: 1/2/pi
                                        * Referenced by: '<S613>/Gain10'
                                        */
  real_T RateLimiter_RisingLim_p;      /* Computed Parameter: RateLimiter_RisingLim_p
                                        * Referenced by: '<S613>/Rate Limiter'
                                        */
  real_T RateLimiter_FallingLim_f;     /* Computed Parameter: RateLimiter_FallingLim_f
                                        * Referenced by: '<S613>/Rate Limiter'
                                        */
  real_T RateLimiter_IC_e;             /* Expression: sps.Finit
                                        * Referenced by: '<S613>/Rate Limiter'
                                        */
  real_T Delay_x1_InitialCondition;    /* Expression: sps.x0(1,:)
                                        * Referenced by: '<S638>/Delay_x1'
                                        */
  real_T A11_Gain;                     /* Expression: sps.A11
                                        * Referenced by: '<S639>/A11'
                                        */
  real_T Delay_x2_InitialCondition;    /* Expression: sps.x0(2,:)
                                        * Referenced by: '<S638>/Delay_x2'
                                        */
  real_T A12_Gain;                     /* Expression: sps.A12
                                        * Referenced by: '<S639>/A12'
                                        */
  real_T A21_Gain;                     /* Expression: sps.A21
                                        * Referenced by: '<S639>/A21'
                                        */
  real_T A22_Gain;                     /* Expression: sps.A22
                                        * Referenced by: '<S639>/A22'
                                        */
  real_T B11_Gain;                     /* Expression: sps.B11
                                        * Referenced by: '<S640>/B11'
                                        */
  real_T B21_Gain;                     /* Expression: sps.B21
                                        * Referenced by: '<S640>/B21'
                                        */
  real_T Duk_Gain;                     /* Expression: sps.D
                                        * Referenced by: '<S638>/D*u(k)'
                                        */
  real_T C11_Gain;                     /* Expression: sps.C11
                                        * Referenced by: '<S641>/C11'
                                        */
  real_T C12_Gain;                     /* Expression: sps.C12
                                        * Referenced by: '<S641>/C12'
                                        */
  real_T Constant_Value_dg;            /* Expression: TrueRMS
                                        * Referenced by: '<S570>/Constant'
                                        */
  real_T IntegralGain_Gain_mr;         /* Expression: I
                                        * Referenced by: '<S454>/Integral Gain'
                                        */
  real_T IntegralGain_Gain_c;          /* Expression: I
                                        * Referenced by: '<S455>/Integral Gain'
                                        */
  real_T VRMSnom_Value_j;              /* Expression: V/1.7321
                                        * Referenced by: '<S18>/VRMSnom'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 1.5
                                        * Referenced by: '<S18>/Gain1'
                                        */
  real_T Gain2_Gain_b0;                /* Expression: 0.5
                                        * Referenced by: '<S18>/Gain2'
                                        */
  real_T Memory3_X0_py;                /* Expression: 0
                                        * Referenced by: '<S456>/Memory3'
                                        */
  real_T Memory4_X0_i;                 /* Expression: 0
                                        * Referenced by: '<S456>/Memory4'
                                        */
  real_T Memory5_X0_m;                 /* Expression: 0
                                        * Referenced by: '<S456>/Memory5'
                                        */
  real_T Memory6_X0_j;                 /* Expression: 0
                                        * Referenced by: '<S456>/Memory6'
                                        */
  real_T donotdeletethisgain_Gain_eln; /* Expression: 1
                                        * Referenced by: '<S486>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_mf;  /* Expression: 1
                                        * Referenced by: '<S487>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_ba;  /* Expression: 1
                                        * Referenced by: '<S488>/do not delete this gain'
                                        */
  real_T Kv1_Gain_b;                   /* Expression: Kv
                                        * Referenced by: '<S466>/Kv1'
                                        */
  real_T donotdeletethisgain_Gain_gv;  /* Expression: 1
                                        * Referenced by: '<S483>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_mp;  /* Expression: 1
                                        * Referenced by: '<S484>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_hy;  /* Expression: 1
                                        * Referenced by: '<S485>/do not delete this gain'
                                        */
  real_T Kv_Gain_jm;                   /* Expression: Ki
                                        * Referenced by: '<S466>/Kv'
                                        */
  real_T puV_Gain_e;                   /* Expression: 1/sqrt(3)
                                        * Referenced by: '<S469>/pu->V'
                                        */
  real_T Integ4_gainval_n2;            /* Computed Parameter: Integ4_gainval_n2
                                        * Referenced by: '<S472>/Integ4'
                                        */
  real_T Integ4_IC_bj;                 /* Expression: 0
                                        * Referenced by: '<S472>/Integ4'
                                        */
  real_T K1_Value_b1;                  /* Expression: Delay
                                        * Referenced by: '<S472>/K1'
                                        */
  real_T K2_Value_m;                   /* Expression: Freq
                                        * Referenced by: '<S472>/K2'
                                        */
  real_T UnitDelay_InitialCondition_ow;/* Expression: 0
                                        * Referenced by: '<S472>/Unit Delay'
                                        */
  real_T Step_Time_d3;                 /* Expression: 1/Freq
                                        * Referenced by: '<S472>/Step'
                                        */
  real_T Step_Y0_j;                    /* Expression: 0
                                        * Referenced by: '<S472>/Step'
                                        */
  real_T Step_YFinal_n;                /* Expression: 1
                                        * Referenced by: '<S472>/Step'
                                        */
  real_T Constant_Value_gg;            /* Expression: Vinit
                                        * Referenced by: '<S472>/Constant'
                                        */
  real_T Switch_Threshold_hi;          /* Expression: 0.5
                                        * Referenced by: '<S472>/Switch'
                                        */
  real_T Gain_Gain_fq;                 /* Expression: 1/1000
                                        * Referenced by: '<S465>/Gain'
                                        */
  real_T Constant_Value_ip;            /* Expression: const
                                        * Referenced by: '<S470>/Constant'
                                        */
  real_T Constant_Value_iw;            /* Expression: const
                                        * Referenced by: '<S471>/Constant'
                                        */
  real_T Constant_Value_bn;            /* Expression: const
                                        * Referenced by: '<S473>/Constant'
                                        */
  real_T FixPtUnitDelay1_InitialCondit_f;/* Expression: vinit
                                          * Referenced by: '<S474>/FixPt Unit Delay1'
                                          */
  real_T UnitDelay_InitialCondition_m; /* Expression: sps.Finit
                                        * Referenced by: '<S502>/Unit Delay'
                                        */
  real_T donotdeletethisgain_Gain_by;  /* Expression: 1
                                        * Referenced by: '<S461>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_af;  /* Expression: 1
                                        * Referenced by: '<S462>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_k1;  /* Expression: 1
                                        * Referenced by: '<S463>/do not delete this gain'
                                        */
  real_T Constant1_Value_pi;           /* Expression: sps.AGC
                                        * Referenced by: '<S502>/Constant1'
                                        */
  real_T Gain3_Gain_k5[9];             /* Expression: [ 1   -1/2   -1/2; 0   sqrt(3)/2   -sqrt(3)/2; 1/2  1/2  1/2 ]
                                        * Referenced by: '<S536>/Gain3'
                                        */
  real_T Gain1_Gain_kv;                /* Expression: 2/3
                                        * Referenced by: '<S536>/Gain1'
                                        */
  real_T Constant_Value_j2;            /* Expression: Alignment
                                        * Referenced by: '<S535>/Constant'
                                        */
  real_T Constant_Value_ez;            /* Expression: const
                                        * Referenced by: '<S537>/Constant'
                                        */
  real_T Constant_Value_dw;            /* Expression: const
                                        * Referenced by: '<S538>/Constant'
                                        */
  real_T Integ4_gainval_f;             /* Computed Parameter: Integ4_gainval_f
                                        * Referenced by: '<S532>/Integ4'
                                        */
  real_T Integ4_IC_h;                  /* Expression: 0
                                        * Referenced by: '<S532>/Integ4'
                                        */
  real_T Toavoiddivisionbyzero_UpperSa_a;/* Expression: 1e6
                                          * Referenced by: '<S532>/To avoid division  by zero'
                                          */
  real_T Toavoiddivisionbyzero_LowerSa_b;/* Expression: eps
                                          * Referenced by: '<S532>/To avoid division  by zero'
                                          */
  real_T Gain_Gain_ax;                 /* Expression: Ts
                                        * Referenced by: '<S532>/Gain'
                                        */
  real_T SFunction_P1_Size_c[2];       /* Computed Parameter: SFunction_P1_Size_c
                                        * Referenced by: '<S534>/S-Function'
                                        */
  real_T SFunction_P1_jw;              /* Expression: MaxDelay
                                        * Referenced by: '<S534>/S-Function'
                                        */
  real_T SFunction_P2_Size_g[2];       /* Computed Parameter: SFunction_P2_Size_g
                                        * Referenced by: '<S534>/S-Function'
                                        */
  real_T SFunction_P2_d0;              /* Expression: Ts
                                        * Referenced by: '<S534>/S-Function'
                                        */
  real_T SFunction_P3_Size_f[2];       /* Computed Parameter: SFunction_P3_Size_f
                                        * Referenced by: '<S534>/S-Function'
                                        */
  real_T SFunction_P3_b;               /* Expression: InitialValue
                                        * Referenced by: '<S534>/S-Function'
                                        */
  real_T SFunction_P4_Size_n[2];       /* Computed Parameter: SFunction_P4_Size_n
                                        * Referenced by: '<S534>/S-Function'
                                        */
  real_T SFunction_P4_o;               /* Expression: DFT
                                        * Referenced by: '<S534>/S-Function'
                                        */
  real_T UnitDelay_InitialCondition_dh;/* Expression: 0
                                        * Referenced by: '<S533>/Unit Delay'
                                        */
  real_T Constant_Value_f2;            /* Expression: 1/sps.Finit
                                        * Referenced by: '<S532>/Constant'
                                        */
  real_T UnitDelay1_InitialCondition_o;/* Expression: sps.Vinit
                                        * Referenced by: '<S532>/Unit Delay1'
                                        */
  real_T DiscreteDerivative_NumCoef_n[2];/* Expression: [ 1  -1 ]*Kd
                                          * Referenced by: '<S504>/Discrete Derivative '
                                          */
  real_T DiscreteDerivative_DenCoef_g[2];/* Expression: [ TcD  Ts-TcD ]
                                          * Referenced by: '<S504>/Discrete Derivative '
                                          */
  real_T DiscreteDerivative_InitialSta_g;/* Expression: 0
                                          * Referenced by: '<S504>/Discrete Derivative '
                                          */
  real_T DiscreteTimeIntegrator_gainva_j;/* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                                          * Referenced by: '<S504>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_j;  /* Expression: Init
                                        * Referenced by: '<S504>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperS_e;/* Expression: Par_Limits(1)
                                          * Referenced by: '<S504>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerS_n;/* Expression: Par_Limits(2)
                                          * Referenced by: '<S504>/Discrete-Time Integrator'
                                          */
  real_T Kp4_Gain_h;                   /* Expression: Kp
                                        * Referenced by: '<S504>/Kp4'
                                        */
  real_T Saturation1_UpperSat_f;       /* Expression: Par_Limits(1)
                                        * Referenced by: '<S504>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_n;       /* Expression: Par_Limits(2)
                                        * Referenced by: '<S504>/Saturation1'
                                        */
  real_T Gain10_Gain_e;                /* Expression: 1/2/pi
                                        * Referenced by: '<S502>/Gain10'
                                        */
  real_T RateLimiter_RisingLim_i;      /* Computed Parameter: RateLimiter_RisingLim_i
                                        * Referenced by: '<S502>/Rate Limiter'
                                        */
  real_T RateLimiter_FallingLim_j;     /* Computed Parameter: RateLimiter_FallingLim_j
                                        * Referenced by: '<S502>/Rate Limiter'
                                        */
  real_T RateLimiter_IC_n;             /* Expression: sps.Finit
                                        * Referenced by: '<S502>/Rate Limiter'
                                        */
  real_T Delay_x1_InitialCondition_e;  /* Expression: sps.x0(1,:)
                                        * Referenced by: '<S527>/Delay_x1'
                                        */
  real_T A11_Gain_g;                   /* Expression: sps.A11
                                        * Referenced by: '<S528>/A11'
                                        */
  real_T Delay_x2_InitialCondition_k;  /* Expression: sps.x0(2,:)
                                        * Referenced by: '<S527>/Delay_x2'
                                        */
  real_T A12_Gain_c;                   /* Expression: sps.A12
                                        * Referenced by: '<S528>/A12'
                                        */
  real_T A21_Gain_a;                   /* Expression: sps.A21
                                        * Referenced by: '<S528>/A21'
                                        */
  real_T A22_Gain_e;                   /* Expression: sps.A22
                                        * Referenced by: '<S528>/A22'
                                        */
  real_T B11_Gain_f;                   /* Expression: sps.B11
                                        * Referenced by: '<S529>/B11'
                                        */
  real_T B21_Gain_f;                   /* Expression: sps.B21
                                        * Referenced by: '<S529>/B21'
                                        */
  real_T Duk_Gain_k;                   /* Expression: sps.D
                                        * Referenced by: '<S527>/D*u(k)'
                                        */
  real_T C11_Gain_k;                   /* Expression: sps.C11
                                        * Referenced by: '<S530>/C11'
                                        */
  real_T C12_Gain_c;                   /* Expression: sps.C12
                                        * Referenced by: '<S530>/C12'
                                        */
  real_T Constant_Value_o0;            /* Expression: TrueRMS
                                        * Referenced by: '<S459>/Constant'
                                        */
  real_T Interpolation_Value;          /* Expression: 1
                                        * Referenced by: '<S3>/Interpolation '
                                        */
  real_T State_Value;                  /* Expression: 1
                                        * Referenced by: '<S3>/State '
                                        */
  real_T Repetative_Value;             /* Expression: 1
                                        * Referenced by: '<S3>/Repetative '
                                        */
  real_T Start_Index_Value;            /* Expression: 1
                                        * Referenced by: '<S3>/Start_Index '
                                        */
  real_T Stop_Index_Value;             /* Expression: 1800-1
                                        * Referenced by: '<S3>/Stop_Index '
                                        */
  real_T Time_Scale_Factor_Value;      /* Expression: 1
                                        * Referenced by: '<S3>/Time_Scale_Factor '
                                        */
  real_T OpFromFile1_P1_Size[2];       /* Computed Parameter: OpFromFile1_P1_Size
                                        * Referenced by: '<S3>/OpFromFile1'
                                        */
  real_T OpFromFile1_P1;               /* Expression: filename_mode
                                        * Referenced by: '<S3>/OpFromFile1'
                                        */
  real_T OpFromFile1_P2_Size[2];       /* Computed Parameter: OpFromFile1_P2_Size
                                        * Referenced by: '<S3>/OpFromFile1'
                                        */
  real_T OpFromFile1_P2;               /* Expression: reload_mode
                                        * Referenced by: '<S3>/OpFromFile1'
                                        */
  real_T OpFromFile1_P3_Size[2];       /* Computed Parameter: OpFromFile1_P3_Size
                                        * Referenced by: '<S3>/OpFromFile1'
                                        */
  real_T OpFromFile1_P3;               /* Expression: init_file_id
                                        * Referenced by: '<S3>/OpFromFile1'
                                        */
  real_T OpFromFile1_P4_Size[2];       /* Computed Parameter: OpFromFile1_P4_Size
                                        * Referenced by: '<S3>/OpFromFile1'
                                        */
  real_T OpFromFile1_P4[16];           /* Computed Parameter: OpFromFile1_P4
                                        * Referenced by: '<S3>/OpFromFile1'
                                        */
  real_T OpFromFile1_P5_Size[2];       /* Computed Parameter: OpFromFile1_P5_Size
                                        * Referenced by: '<S3>/OpFromFile1'
                                        */
  real_T OpFromFile1_P5[2];            /* Computed Parameter: OpFromFile1_P5
                                        * Referenced by: '<S3>/OpFromFile1'
                                        */
  real_T OpFromFile1_P6_Size[2];       /* Computed Parameter: OpFromFile1_P6_Size
                                        * Referenced by: '<S3>/OpFromFile1'
                                        */
  real_T OpFromFile1_P6[2];            /* Computed Parameter: OpFromFile1_P6
                                        * Referenced by: '<S3>/OpFromFile1'
                                        */
  real_T OpFromFile1_P7_Size[2];       /* Computed Parameter: OpFromFile1_P7_Size
                                        * Referenced by: '<S3>/OpFromFile1'
                                        */
  real_T OpFromFile1_P7;               /* Expression: sample_time
                                        * Referenced by: '<S3>/OpFromFile1'
                                        */
  real_T Time_Scale_Factor1_Value;     /* Expression: 1
                                        * Referenced by: '<S3>/Time_Scale_Factor 1'
                                        */
  real_T Memory5_1_X0_p;               /* Expression: 0
                                        * Referenced by: '<S17>/Memory5'
                                        */
  real_T Memory5_2_X0_p;               /* Expression: 0
                                        * Referenced by: '<S17>/Memory5'
                                        */
  real_T Memory5_3_X0_p;               /* Expression: 0
                                        * Referenced by: '<S17>/Memory5'
                                        */
  real_T donotdeletethisgain_Gain_dc;  /* Expression: 1
                                        * Referenced by: '<S436>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_e0;  /* Expression: 1
                                        * Referenced by: '<S437>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_dv;  /* Expression: 1
                                        * Referenced by: '<S438>/do not delete this gain'
                                        */
  real_T Kv1_Gain_e;                   /* Expression: Kv
                                        * Referenced by: '<S418>/Kv1'
                                        */
  real_T donotdeletethisgain_Gain_cv;  /* Expression: 1
                                        * Referenced by: '<S433>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_co;  /* Expression: 1
                                        * Referenced by: '<S434>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_le;  /* Expression: 1
                                        * Referenced by: '<S435>/do not delete this gain'
                                        */
  real_T Kv_Gain_jf;                   /* Expression: Ki
                                        * Referenced by: '<S418>/Kv'
                                        */
  real_T puV_Gain_h;                   /* Expression: 1/sqrt(3)
                                        * Referenced by: '<S419>/pu->V'
                                        */
  real_T Constant_Value_i5;            /* Expression: Vinit
                                        * Referenced by: '<S420>/Constant'
                                        */
  real_T Integ4_gainval_p4;            /* Computed Parameter: Integ4_gainval_p4
                                        * Referenced by: '<S420>/Integ4'
                                        */
  real_T Integ4_IC_ht;                 /* Expression: 0
                                        * Referenced by: '<S420>/Integ4'
                                        */
  real_T K1_Value_d;                   /* Expression: Delay
                                        * Referenced by: '<S420>/K1'
                                        */
  real_T UnitDelay_InitialCondition_djf;/* Expression: 0
                                         * Referenced by: '<S420>/Unit Delay'
                                         */
  real_T K2_Value_f;                   /* Expression: Freq
                                        * Referenced by: '<S420>/K2'
                                        */
  real_T Step_Time_fm;                 /* Expression: 1/Freq
                                        * Referenced by: '<S420>/Step'
                                        */
  real_T Step_Y0_e;                    /* Expression: 0
                                        * Referenced by: '<S420>/Step'
                                        */
  real_T Step_YFinal_h;                /* Expression: 1
                                        * Referenced by: '<S420>/Step'
                                        */
  real_T Switch_Threshold_jg;          /* Expression: 0.5
                                        * Referenced by: '<S420>/Switch'
                                        */
  real_T Gain_Gain_aj;                 /* Expression: 1/1000
                                        * Referenced by: '<S416>/Gain'
                                        */
  real_T donotdeletethisgain_Gain_nk;  /* Expression: 1
                                        * Referenced by: '<S353>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_ir;  /* Expression: 1
                                        * Referenced by: '<S355>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_mk;  /* Expression: 1
                                        * Referenced by: '<S351>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_br;  /* Expression: 1
                                        * Referenced by: '<S369>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_jd;  /* Expression: 1
                                        * Referenced by: '<S371>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_e1;  /* Expression: 1
                                        * Referenced by: '<S367>/do not delete this gain'
                                        */
  int8_T BitwiseOperator3_BitMask;     /* Expression: BitMask
                                        * Referenced by: '<S20>/Bitwise Operator3'
                                        */
  int8_T Constant_Value_nv;            /* Computed Parameter: Constant_Value_nv
                                        * Referenced by: '<S681>/Constant'
                                        */
  int8_T BitwiseOperator2_BitMask;     /* Expression: BitMask
                                        * Referenced by: '<S20>/Bitwise Operator2'
                                        */
  int8_T Constant_Value_ab;            /* Computed Parameter: Constant_Value_ab
                                        * Referenced by: '<S680>/Constant'
                                        */
  int8_T BitwiseOperator1_BitMask;     /* Expression: BitMask
                                        * Referenced by: '<S20>/Bitwise Operator1'
                                        */
  int8_T Constant_Value_d5;            /* Computed Parameter: Constant_Value_d5
                                        * Referenced by: '<S679>/Constant'
                                        */
  int8_T BitwiseOperator_BitMask;      /* Expression: BitMask
                                        * Referenced by: '<S20>/Bitwise Operator'
                                        */
  int8_T Constant_Value_ne;            /* Computed Parameter: Constant_Value_ne
                                        * Referenced by: '<S678>/Constant'
                                        */
  int8_T BitwiseOperator3_BitMask_j;   /* Expression: BitMask
                                        * Referenced by: '<S21>/Bitwise Operator3'
                                        */
  int8_T Constant_Value_na;            /* Computed Parameter: Constant_Value_na
                                        * Referenced by: '<S710>/Constant'
                                        */
  int8_T BitwiseOperator2_BitMask_o;   /* Expression: BitMask
                                        * Referenced by: '<S21>/Bitwise Operator2'
                                        */
  int8_T Constant_Value_dq;            /* Computed Parameter: Constant_Value_dq
                                        * Referenced by: '<S709>/Constant'
                                        */
  int8_T BitwiseOperator1_BitMask_o;   /* Expression: BitMask
                                        * Referenced by: '<S21>/Bitwise Operator1'
                                        */
  int8_T Constant_Value_ht;            /* Computed Parameter: Constant_Value_ht
                                        * Referenced by: '<S708>/Constant'
                                        */
  int8_T BitwiseOperator_BitMask_o;    /* Expression: BitMask
                                        * Referenced by: '<S21>/Bitwise Operator'
                                        */
  int8_T Constant_Value_ce;            /* Computed Parameter: Constant_Value_ce
                                        * Referenced by: '<S707>/Constant'
                                        */
  uint8_T DelayInput1_InitialCondition_b;/* Computed Parameter: DelayInput1_InitialCondition_b
                                          * Referenced by: '<S732>/Delay Input1'
                                          */
  boolean_T Constant1_Value_ob;        /* Expression: SM.nState==6
                                        * Referenced by: '<S293>/Constant1'
                                        */
  boolean_T Constant2_Value_d;         /* Expression: SM.nState==6
                                        * Referenced by: '<S293>/Constant2'
                                        */
  boolean_T Constant_Value_gj;         /* Computed Parameter: Constant_Value_gj
                                        * Referenced by: '<S732>/Constant'
                                        */
  boolean_T Constant1_Value_j;         /* Expression: SM.nState==6
                                        * Referenced by: '<S282>/Constant1'
                                        */
  boolean_T UnitDelay_InitialCondition_mi;/* Computed Parameter: UnitDelay_InitialCondition_mi
                                           * Referenced by: '<S19>/Unit Delay'
                                           */
  boolean_T UnitDelay_InitialCondition_mh;/* Computed Parameter: UnitDelay_InitialCondition_mh
                                           * Referenced by: '<S18>/Unit Delay'
                                           */
  boolean_T Memory_X0_k;               /* Computed Parameter: Memory_X0_k
                                        * Referenced by: '<S14>/Memory'
                                        */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S14>/Logic'
                                        */
  boolean_T Memory_X0_a;               /* Computed Parameter: Memory_X0_a
                                        * Referenced by: '<S333>/Memory'
                                        */
  boolean_T Logic_table_n[16];         /* Computed Parameter: Logic_table_n
                                        * Referenced by: '<S333>/Logic'
                                        */
  boolean_T Memory_X0_b;               /* Computed Parameter: Memory_X0_b
                                        * Referenced by: '<S334>/Memory'
                                        */
  boolean_T Logic_table_d[16];         /* Computed Parameter: Logic_table_d
                                        * Referenced by: '<S334>/Logic'
                                        */
  boolean_T Memory_X0_d;               /* Computed Parameter: Memory_X0_d
                                        * Referenced by: '<S336>/Memory'
                                        */
  boolean_T Logic_table_p[16];         /* Computed Parameter: Logic_table_p
                                        * Referenced by: '<S336>/Logic'
                                        */
  boolean_T Memory_X0_j;               /* Computed Parameter: Memory_X0_j
                                        * Referenced by: '<S337>/Memory'
                                        */
  boolean_T Logic_table_f[16];         /* Computed Parameter: Logic_table_f
                                        * Referenced by: '<S337>/Logic'
                                        */
  boolean_T Memory_X0_g;               /* Computed Parameter: Memory_X0_g
                                        * Referenced by: '<S335>/Memory'
                                        */
  boolean_T Logic_table_p2[16];        /* Computed Parameter: Logic_table_p2
                                        * Referenced by: '<S335>/Logic'
                                        */
  boolean_T Memory_X0_pk;              /* Computed Parameter: Memory_X0_pk
                                        * Referenced by: '<S338>/Memory'
                                        */
  boolean_T Logic_table_i[16];         /* Computed Parameter: Logic_table_i
                                        * Referenced by: '<S338>/Logic'
                                        */
  boolean_T UnitDelay_InitialCondition_iq;/* Computed Parameter: UnitDelay_InitialCondition_iq
                                           * Referenced by: '<S732>/Unit Delay'
                                           */
  boolean_T Memory_X0_af;              /* Computed Parameter: Memory_X0_af
                                        * Referenced by: '<S743>/Memory'
                                        */
  boolean_T Logic_table_pz[16];        /* Computed Parameter: Logic_table_pz
                                        * Referenced by: '<S743>/Logic'
                                        */
  boolean_T DelayInput1_InitialCondition_d;/* Computed Parameter: DelayInput1_InitialCondition_d
                                            * Referenced by: '<S747>/Delay Input1'
                                            */
  boolean_T DelayInput1_InitialCondition_h;/* Computed Parameter: DelayInput1_InitialCondition_h
                                            * Referenced by: '<S746>/Delay Input1'
                                            */
  boolean_T Memory1_X0_d;              /* Computed Parameter: Memory1_X0_d
                                        * Referenced by: '<S741>/Memory1'
                                        */
  boolean_T Memory_X0_fx;              /* Computed Parameter: Memory_X0_fx
                                        * Referenced by: '<S744>/Memory'
                                        */
  boolean_T Logic_table_ia[16];        /* Computed Parameter: Logic_table_ia
                                        * Referenced by: '<S744>/Logic'
                                        */
  boolean_T delay_InitialCondition;    /* Computed Parameter: delay_InitialCondition
                                        * Referenced by: '<S739>/delay'
                                        */
  boolean_T DelayInput1_InitialCondition_g;/* Computed Parameter: DelayInput1_InitialCondition_g
                                            * Referenced by: '<S735>/Delay Input1'
                                            */
  boolean_T DelayInput2_InitialCondition;/* Computed Parameter: DelayInput2_InitialCondition
                                          * Referenced by: '<S735>/Delay Input2'
                                          */
  boolean_T Memory_X0_o;               /* Computed Parameter: Memory_X0_o
                                        * Referenced by: '<S740>/Memory'
                                        */
  boolean_T Logic_table_l[16];         /* Computed Parameter: Logic_table_l
                                        * Referenced by: '<S740>/Logic'
                                        */
  boolean_T Memory_X0_b0;              /* Computed Parameter: Memory_X0_b0
                                        * Referenced by: '<S731>/Memory'
                                        */
  boolean_T Memory_X0_ay;              /* Computed Parameter: Memory_X0_ay
                                        * Referenced by: '<S736>/Memory'
                                        */
  boolean_T Logic_table_nf[16];        /* Computed Parameter: Logic_table_nf
                                        * Referenced by: '<S736>/Logic'
                                        */
  boolean_T FixPtUnitDelay1_InitialCondit_h;/* Computed Parameter: FixPtUnitDelay1_InitialCondit_h
                                             * Referenced by: '<S586>/FixPt Unit Delay1'
                                             */
  boolean_T FixPtUnitDelay1_InitialCondit_n;/* Computed Parameter: FixPtUnitDelay1_InitialCondit_n
                                             * Referenced by: '<S475>/FixPt Unit Delay1'
                                             */
};

/* Real-time Model Data Structure */
struct tag_RTM_sel751test_model_1_1_sm_system_T {
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
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[45];
    SimStruct *childSFunctionPtrs[45];
    struct _ssBlkInfo2 blkInfo2[45];
    struct _ssSFcnModelMethods2 methods2[45];
    struct _ssSFcnModelMethods3 methods3[45];
    struct _ssStatesInfo2 statesInfo2[45];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[3];
      struct _ssDWorkAuxRecord dWorkAux[3];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[3];
      struct _ssDWorkAuxRecord dWorkAux[3];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[3];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[3];
      struct _ssDWorkAuxRecord dWorkAux[3];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[3];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[3];
      struct _ssDWorkAuxRecord dWorkAux[3];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[3];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[3];
      struct _ssDWorkAuxRecord dWorkAux[3];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[3];
      struct _ssDWorkAuxRecord dWorkAux[3];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[3];
      struct _ssDWorkAuxRecord dWorkAux[3];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[3];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[3];
      struct _ssDWorkAuxRecord dWorkAux[3];
    } Sfcn7;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[3];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[3];
      struct _ssDWorkAuxRecord dWorkAux[3];
    } Sfcn8;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[3];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[3];
      struct _ssDWorkAuxRecord dWorkAux[3];
    } Sfcn9;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[23];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn10;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn11;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[17];
      uint_T attribs[9];
      mxArray *params[9];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn12;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[17];
      uint_T attribs[9];
      mxArray *params[9];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn13;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[3];
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn14;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[3];
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn15;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn16;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn17;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn18;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn19;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[34];
      real_T const *UPtrs1[17];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[21];
      struct _ssDWorkAuxRecord dWorkAux[21];
    } Sfcn20;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[227];
      uint_T attribs[1];
      mxArray *params[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn21;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[8];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[11];
      mxArray *params[11];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn22;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[8];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn23;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[4];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn24;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[6];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      real_T const *UPtrs2[1];
      real_T const *UPtrs3[1];
      real_T const *UPtrs4[1];
      real_T const *UPtrs5[1];
      struct _ssPortOutputs outputPortInfo[4];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn25;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[8];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[11];
      mxArray *params[11];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn26;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[10];
      mxArray *params[10];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn27;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn28;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[10];
      mxArray *params[10];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn29;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn30;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[8];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[11];
      mxArray *params[11];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn31;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[8];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[11];
      mxArray *params[11];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn32;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[12];
      mxArray *params[12];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn33;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[8];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn34;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[8];
      real_T const *UPtrs1[8];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[12];
      mxArray *params[12];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn35;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[8];
      real_T const *UPtrs1[8];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[12];
      mxArray *params[12];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn36;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[16];
      real_T const *UPtrs0[4];
      real_T const *UPtrs1[4];
      real_T const *UPtrs2[4];
      real_T const *UPtrs3[4];
      real_T const *UPtrs4[4];
      real_T const *UPtrs5[4];
      real_T const *UPtrs6[4];
      real_T const *UPtrs7[4];
      real_T const *UPtrs8[4];
      real_T const *UPtrs9[4];
      real_T const *UPtrs10[4];
      real_T const *UPtrs11[4];
      real_T const *UPtrs12[4];
      real_T const *UPtrs13[4];
      real_T const *UPtrs14[4];
      real_T const *UPtrs15[4];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn37;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[16];
      real_T const *UPtrs0[4];
      real_T const *UPtrs1[4];
      real_T const *UPtrs2[4];
      real_T const *UPtrs3[4];
      real_T const *UPtrs4[4];
      real_T const *UPtrs5[4];
      real_T const *UPtrs6[4];
      real_T const *UPtrs7[4];
      real_T const *UPtrs8[4];
      real_T const *UPtrs9[4];
      real_T const *UPtrs10[4];
      real_T const *UPtrs11[4];
      real_T const *UPtrs12[4];
      real_T const *UPtrs13[4];
      real_T const *UPtrs14[4];
      real_T const *UPtrs15[4];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn38;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn39;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[8];
      mxArray *params[8];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn40;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[8];
      mxArray *params[8];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn41;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[3];
      struct _ssDWorkAuxRecord dWorkAux[3];
    } Sfcn42;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[3];
      struct _ssDWorkAuxRecord dWorkAux[3];
    } Sfcn43;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[6];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      real_T const *UPtrs2[1];
      real_T const *UPtrs3[1];
      real_T const *UPtrs4[1];
      real_T const *UPtrs5[1];
      struct _ssPortOutputs outputPortInfo[4];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn44;
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
    real_T odeY[2];
    real_T odeF[4][2];
    ODE4_IntgData intgData;
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
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
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
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_sel751test_model_1_1_sm_system_T sel751test_model_1_1_sm_system_P;

/* Block signals (auto storage) */
extern B_sel751test_model_1_1_sm_system_T sel751test_model_1_1_sm_system_B;

/* Continuous states (auto storage) */
extern X_sel751test_model_1_1_sm_system_T sel751test_model_1_1_sm_system_X;

/* Block states (auto storage) */
extern DW_sel751test_model_1_1_sm_system_T sel751test_model_1_1_sm_system_DW;

/* External data declarations for dependent source files */
extern const real_T sel751test_model_1_1_sm_system_RGND;/* real_T ground */

/* Model entry point functions */
extern RT_MODEL_sel751test_model_1_1_sm_system_T *sel751test_model_1_1_sm_system
  (void);
extern void sel751test_model_1_1_sm_system_initialize(void);
extern void sel751test_model_1_1_sm_system_output(void);
extern void sel751test_model_1_1_sm_system_update(void);
extern void sel751test_model_1_1_sm_system_terminate(void);

/* Real-time Model object */
extern RT_MODEL_sel751test_model_1_1_sm_system_T *const
  sel751test_model_1_1_sm_system_M;

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
 * '<Root>' : 'sel751test_model_1_1_sm_system'
 * '<S1>'   : 'sel751test_model_1_1_sm_system/ARTEMIS Guide'
 * '<S2>'   : 'sel751test_model_1_1_sm_system/OpCCode_do_not_touch'
 * '<S3>'   : 'sel751test_model_1_1_sm_system/SM_system'
 * '<S4>'   : 'sel751test_model_1_1_sm_system/powergui'
 * '<S5>'   : 'sel751test_model_1_1_sm_system/SM_system/500kcmil-Mutual1'
 * '<S6>'   : 'sel751test_model_1_1_sm_system/SM_system/500kcmil-Mutual2'
 * '<S7>'   : 'sel751test_model_1_1_sm_system/SM_system/500kcmil-Mutual4'
 * '<S8>'   : 'sel751test_model_1_1_sm_system/SM_system/Breaker1'
 * '<S9>'   : 'sel751test_model_1_1_sm_system/SM_system/Breaker2'
 * '<S10>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker3'
 * '<S11>'  : 'sel751test_model_1_1_sm_system/SM_system/FEEDER_1'
 * '<S12>'  : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP'
 * '<S13>'  : 'sel751test_model_1_1_sm_system/SM_system/OpComm2'
 * '<S14>'  : 'sel751test_model_1_1_sm_system/SM_system/S-R Flip-Flop'
 * '<S15>'  : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)'
 * '<S16>'  : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1'
 * '<S17>'  : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2'
 * '<S18>'  : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad'
 * '<S19>'  : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1'
 * '<S20>'  : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault'
 * '<S21>'  : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1'
 * '<S22>'  : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1'
 * '<S23>'  : 'sel751test_model_1_1_sm_system/SM_system/rtlab_send_subsystem'
 * '<S24>'  : 'sel751test_model_1_1_sm_system/SM_system/zzzOpComm'
 * '<S25>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement'
 * '<S26>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1'
 * '<S27>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase Breaker'
 * '<S28>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/delay'
 * '<S29>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/impedance'
 * '<S30>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/impedance1'
 * '<S31>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement/Mode I'
 * '<S32>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement/Mode V'
 * '<S33>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement/Model'
 * '<S34>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement/Mode I/Complex'
 * '<S35>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement/Mode V/Complex'
 * '<S36>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement/Model/VI'
 * '<S37>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement/Model/VI/I A:'
 * '<S38>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement/Model/VI/I B:'
 * '<S39>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement/Model/VI/I C:'
 * '<S40>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement/Model/VI/U A:'
 * '<S41>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement/Model/VI/U B:'
 * '<S42>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement/Model/VI/U C:'
 * '<S43>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement/Model/VI/I A:/Model'
 * '<S44>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement/Model/VI/I A:/Model/Complex'
 * '<S45>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement/Model/VI/I B:/Model'
 * '<S46>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement/Model/VI/I B:/Model/Complex'
 * '<S47>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement/Model/VI/I C:/Model'
 * '<S48>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement/Model/VI/I C:/Model/Complex'
 * '<S49>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement/Model/VI/U A:/Model'
 * '<S50>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement/Model/VI/U A:/Model/Complex'
 * '<S51>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement/Model/VI/U B:/Model'
 * '<S52>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement/Model/VI/U B:/Model/Complex'
 * '<S53>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement/Model/VI/U C:/Model'
 * '<S54>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement/Model/VI/U C:/Model/Complex'
 * '<S55>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1/Mode I'
 * '<S56>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1/Mode V'
 * '<S57>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1/Model'
 * '<S58>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1/Mode I/Complex'
 * '<S59>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1/Mode V/Complex'
 * '<S60>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1/Model/VI'
 * '<S61>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1/Model/VI/I A:'
 * '<S62>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1/Model/VI/I B:'
 * '<S63>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1/Model/VI/I C:'
 * '<S64>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1/Model/VI/U A:'
 * '<S65>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1/Model/VI/U B:'
 * '<S66>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1/Model/VI/U C:'
 * '<S67>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1/Model/VI/I A:/Model'
 * '<S68>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1/Model/VI/I A:/Model/Complex'
 * '<S69>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1/Model/VI/I B:/Model'
 * '<S70>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1/Model/VI/I B:/Model/Complex'
 * '<S71>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1/Model/VI/I C:/Model'
 * '<S72>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1/Model/VI/I C:/Model/Complex'
 * '<S73>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1/Model/VI/U A:/Model'
 * '<S74>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1/Model/VI/U A:/Model/Complex'
 * '<S75>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1/Model/VI/U B:/Model'
 * '<S76>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1/Model/VI/U B:/Model/Complex'
 * '<S77>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1/Model/VI/U C:/Model'
 * '<S78>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase V-I Measurement1/Model/VI/U C:/Model/Complex'
 * '<S79>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase Breaker/Breaker A'
 * '<S80>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase Breaker/Breaker B'
 * '<S81>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase Breaker/Breaker C'
 * '<S82>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase Breaker/Model'
 * '<S83>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase Breaker/Breaker A/Model'
 * '<S84>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase Breaker/Breaker A/Model/ArtemisDiscrete'
 * '<S85>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase Breaker/Breaker A/Model/ArtemisDiscrete/Timer'
 * '<S86>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase Breaker/Breaker A/Model/ArtemisDiscrete/fts5conversion'
 * '<S87>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase Breaker/Breaker A/Model/ArtemisDiscrete/fts5conversion1'
 * '<S88>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase Breaker/Breaker B/Model'
 * '<S89>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase Breaker/Breaker B/Model/ArtemisDiscrete'
 * '<S90>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase Breaker/Breaker B/Model/ArtemisDiscrete/Timer'
 * '<S91>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase Breaker/Breaker B/Model/ArtemisDiscrete/fts5conversion'
 * '<S92>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase Breaker/Breaker B/Model/ArtemisDiscrete/fts5conversion1'
 * '<S93>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase Breaker/Breaker C/Model'
 * '<S94>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase Breaker/Breaker C/Model/ArtemisDiscrete'
 * '<S95>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase Breaker/Breaker C/Model/ArtemisDiscrete/Timer'
 * '<S96>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase Breaker/Breaker C/Model/ArtemisDiscrete/fts5conversion'
 * '<S97>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase Breaker/Breaker C/Model/ArtemisDiscrete/fts5conversion1'
 * '<S98>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker1/Three-Phase Breaker/Model/Discrete'
 * '<S99>'  : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement'
 * '<S100>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1'
 * '<S101>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase Breaker'
 * '<S102>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/delay'
 * '<S103>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/impedance'
 * '<S104>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/impedance1'
 * '<S105>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement/Mode I'
 * '<S106>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement/Mode V'
 * '<S107>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement/Model'
 * '<S108>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement/Mode I/Complex'
 * '<S109>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement/Mode V/Complex'
 * '<S110>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement/Model/VI'
 * '<S111>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement/Model/VI/I A:'
 * '<S112>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement/Model/VI/I B:'
 * '<S113>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement/Model/VI/I C:'
 * '<S114>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement/Model/VI/U A:'
 * '<S115>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement/Model/VI/U B:'
 * '<S116>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement/Model/VI/U C:'
 * '<S117>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement/Model/VI/I A:/Model'
 * '<S118>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement/Model/VI/I A:/Model/Complex'
 * '<S119>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement/Model/VI/I B:/Model'
 * '<S120>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement/Model/VI/I B:/Model/Complex'
 * '<S121>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement/Model/VI/I C:/Model'
 * '<S122>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement/Model/VI/I C:/Model/Complex'
 * '<S123>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement/Model/VI/U A:/Model'
 * '<S124>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement/Model/VI/U A:/Model/Complex'
 * '<S125>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement/Model/VI/U B:/Model'
 * '<S126>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement/Model/VI/U B:/Model/Complex'
 * '<S127>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement/Model/VI/U C:/Model'
 * '<S128>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement/Model/VI/U C:/Model/Complex'
 * '<S129>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1/Mode I'
 * '<S130>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1/Mode V'
 * '<S131>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1/Model'
 * '<S132>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1/Mode I/Complex'
 * '<S133>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1/Mode V/Complex'
 * '<S134>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1/Model/VI'
 * '<S135>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1/Model/VI/I A:'
 * '<S136>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1/Model/VI/I B:'
 * '<S137>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1/Model/VI/I C:'
 * '<S138>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1/Model/VI/U A:'
 * '<S139>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1/Model/VI/U B:'
 * '<S140>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1/Model/VI/U C:'
 * '<S141>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1/Model/VI/I A:/Model'
 * '<S142>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1/Model/VI/I A:/Model/Complex'
 * '<S143>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1/Model/VI/I B:/Model'
 * '<S144>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1/Model/VI/I B:/Model/Complex'
 * '<S145>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1/Model/VI/I C:/Model'
 * '<S146>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1/Model/VI/I C:/Model/Complex'
 * '<S147>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1/Model/VI/U A:/Model'
 * '<S148>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1/Model/VI/U A:/Model/Complex'
 * '<S149>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1/Model/VI/U B:/Model'
 * '<S150>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1/Model/VI/U B:/Model/Complex'
 * '<S151>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1/Model/VI/U C:/Model'
 * '<S152>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase V-I Measurement1/Model/VI/U C:/Model/Complex'
 * '<S153>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase Breaker/Breaker A'
 * '<S154>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase Breaker/Breaker B'
 * '<S155>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase Breaker/Breaker C'
 * '<S156>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase Breaker/Model'
 * '<S157>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase Breaker/Breaker A/Model'
 * '<S158>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase Breaker/Breaker A/Model/ArtemisDiscrete'
 * '<S159>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase Breaker/Breaker A/Model/ArtemisDiscrete/Timer'
 * '<S160>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase Breaker/Breaker A/Model/ArtemisDiscrete/fts5conversion'
 * '<S161>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase Breaker/Breaker A/Model/ArtemisDiscrete/fts5conversion1'
 * '<S162>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase Breaker/Breaker B/Model'
 * '<S163>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase Breaker/Breaker B/Model/ArtemisDiscrete'
 * '<S164>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase Breaker/Breaker B/Model/ArtemisDiscrete/Timer'
 * '<S165>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase Breaker/Breaker B/Model/ArtemisDiscrete/fts5conversion'
 * '<S166>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase Breaker/Breaker B/Model/ArtemisDiscrete/fts5conversion1'
 * '<S167>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase Breaker/Breaker C/Model'
 * '<S168>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase Breaker/Breaker C/Model/ArtemisDiscrete'
 * '<S169>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase Breaker/Breaker C/Model/ArtemisDiscrete/Timer'
 * '<S170>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase Breaker/Breaker C/Model/ArtemisDiscrete/fts5conversion'
 * '<S171>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase Breaker/Breaker C/Model/ArtemisDiscrete/fts5conversion1'
 * '<S172>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker2/Three-Phase Breaker/Model/Discrete'
 * '<S173>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement'
 * '<S174>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1'
 * '<S175>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase Breaker'
 * '<S176>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/delay'
 * '<S177>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/impedance'
 * '<S178>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/impedance1'
 * '<S179>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement/Mode I'
 * '<S180>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement/Mode V'
 * '<S181>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement/Model'
 * '<S182>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement/Mode I/Complex'
 * '<S183>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement/Mode V/Complex'
 * '<S184>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement/Model/VI'
 * '<S185>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement/Model/VI/I A:'
 * '<S186>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement/Model/VI/I B:'
 * '<S187>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement/Model/VI/I C:'
 * '<S188>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement/Model/VI/U A:'
 * '<S189>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement/Model/VI/U B:'
 * '<S190>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement/Model/VI/U C:'
 * '<S191>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement/Model/VI/I A:/Model'
 * '<S192>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement/Model/VI/I A:/Model/Complex'
 * '<S193>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement/Model/VI/I B:/Model'
 * '<S194>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement/Model/VI/I B:/Model/Complex'
 * '<S195>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement/Model/VI/I C:/Model'
 * '<S196>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement/Model/VI/I C:/Model/Complex'
 * '<S197>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement/Model/VI/U A:/Model'
 * '<S198>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement/Model/VI/U A:/Model/Complex'
 * '<S199>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement/Model/VI/U B:/Model'
 * '<S200>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement/Model/VI/U B:/Model/Complex'
 * '<S201>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement/Model/VI/U C:/Model'
 * '<S202>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement/Model/VI/U C:/Model/Complex'
 * '<S203>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1/Mode I'
 * '<S204>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1/Mode V'
 * '<S205>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1/Model'
 * '<S206>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1/Mode I/Complex'
 * '<S207>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1/Mode V/Complex'
 * '<S208>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1/Model/VI'
 * '<S209>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1/Model/VI/I A:'
 * '<S210>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1/Model/VI/I B:'
 * '<S211>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1/Model/VI/I C:'
 * '<S212>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1/Model/VI/U A:'
 * '<S213>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1/Model/VI/U B:'
 * '<S214>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1/Model/VI/U C:'
 * '<S215>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1/Model/VI/I A:/Model'
 * '<S216>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1/Model/VI/I A:/Model/Complex'
 * '<S217>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1/Model/VI/I B:/Model'
 * '<S218>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1/Model/VI/I B:/Model/Complex'
 * '<S219>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1/Model/VI/I C:/Model'
 * '<S220>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1/Model/VI/I C:/Model/Complex'
 * '<S221>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1/Model/VI/U A:/Model'
 * '<S222>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1/Model/VI/U A:/Model/Complex'
 * '<S223>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1/Model/VI/U B:/Model'
 * '<S224>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1/Model/VI/U B:/Model/Complex'
 * '<S225>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1/Model/VI/U C:/Model'
 * '<S226>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase V-I Measurement1/Model/VI/U C:/Model/Complex'
 * '<S227>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase Breaker/Breaker A'
 * '<S228>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase Breaker/Breaker B'
 * '<S229>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase Breaker/Breaker C'
 * '<S230>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase Breaker/Model'
 * '<S231>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase Breaker/Breaker A/Model'
 * '<S232>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase Breaker/Breaker A/Model/ArtemisDiscrete'
 * '<S233>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase Breaker/Breaker A/Model/ArtemisDiscrete/Timer'
 * '<S234>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase Breaker/Breaker A/Model/ArtemisDiscrete/fts5conversion'
 * '<S235>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase Breaker/Breaker A/Model/ArtemisDiscrete/fts5conversion1'
 * '<S236>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase Breaker/Breaker B/Model'
 * '<S237>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase Breaker/Breaker B/Model/ArtemisDiscrete'
 * '<S238>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase Breaker/Breaker B/Model/ArtemisDiscrete/Timer'
 * '<S239>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase Breaker/Breaker B/Model/ArtemisDiscrete/fts5conversion'
 * '<S240>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase Breaker/Breaker B/Model/ArtemisDiscrete/fts5conversion1'
 * '<S241>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase Breaker/Breaker C/Model'
 * '<S242>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase Breaker/Breaker C/Model/ArtemisDiscrete'
 * '<S243>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase Breaker/Breaker C/Model/ArtemisDiscrete/Timer'
 * '<S244>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase Breaker/Breaker C/Model/ArtemisDiscrete/fts5conversion'
 * '<S245>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase Breaker/Breaker C/Model/ArtemisDiscrete/fts5conversion1'
 * '<S246>' : 'sel751test_model_1_1_sm_system/SM_system/Breaker3/Three-Phase Breaker/Model/Discrete'
 * '<S247>' : 'sel751test_model_1_1_sm_system/SM_system/FEEDER_1/Model'
 * '<S248>' : 'sel751test_model_1_1_sm_system/SM_system/FEEDER_1/Model/ThreePhaseSource'
 * '<S249>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/CHPThermalModel'
 * '<S250>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator'
 * '<S251>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/CHPThermalModel/Boiler controller'
 * '<S252>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA'
 * '<S253>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Inputs'
 * '<S254>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs'
 * '<S255>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1'
 * '<S256>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/DocBlock'
 * '<S257>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/Interface between Woodward Controller and simated generator'
 * '<S258>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/Simulated Generator Controller 3.5 MW'
 * '<S259>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/StabilityL'
 * '<S260>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/NG Engine Speed & Voltage Control fast'
 * '<S261>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental'
 * '<S262>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/NG Engine Speed & Voltage Control fast/Discrete PID Controller1'
 * '<S263>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/NG Engine Speed & Voltage Control fast/Excitation1'
 * '<S264>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/NG Engine Speed & Voltage Control fast/GE//Jenbacher J620 NG Engine (1800 RPM)'
 * '<S265>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/NG Engine Speed & Voltage Control fast/Excitation1/Damping kf.s // (tf.s +1)'
 * '<S266>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/NG Engine Speed & Voltage Control fast/Excitation1/Exciter  1 // (te.s + ke)'
 * '<S267>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/NG Engine Speed & Voltage Control fast/Excitation1/Lead Lag Compensator tc.s+1 // tb.s+1'
 * '<S268>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/NG Engine Speed & Voltage Control fast/Excitation1/Low Pass Filter 1 // (tr.s +1) (with IC)'
 * '<S269>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/NG Engine Speed & Voltage Control fast/Excitation1/Main Regulator ka // (ta.s +1)'
 * '<S270>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/NG Engine Speed & Voltage Control fast/Excitation1/proportional saturation'
 * '<S271>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/NG Engine Speed & Voltage Control fast/Excitation1/Damping kf.s // (tf.s +1)/1st-Order Discrete Filter'
 * '<S272>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/NG Engine Speed & Voltage Control fast/Excitation1/Exciter  1 // (te.s + ke)/1st order Lowpass'
 * '<S273>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/NG Engine Speed & Voltage Control fast/Excitation1/Main Regulator ka // (ta.s +1)/1st order Lowpass'
 * '<S274>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/NG Engine Speed & Voltage Control fast/GE//Jenbacher J620 NG Engine (1800 RPM)/Engine'
 * '<S275>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/NG Engine Speed & Voltage Control fast/GE//Jenbacher J620 NG Engine (1800 RPM)/Intake manifold'
 * '<S276>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/NG Engine Speed & Voltage Control fast/GE//Jenbacher J620 NG Engine (1800 RPM)/NG Engine Speed Control'
 * '<S277>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/NG Engine Speed & Voltage Control fast/GE//Jenbacher J620 NG Engine (1800 RPM)/Throttle body'
 * '<S278>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Electrical model'
 * '<S279>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Measurement list'
 * '<S280>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Mechanical model'
 * '<S281>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Electrical model/Discrete'
 * '<S282>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Electrical model/Discrete/Machine measurements'
 * '<S283>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Electrical model/Discrete/Synchronous Machine Discrete Model'
 * '<S284>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Electrical model/Discrete/abc to qd transformation'
 * '<S285>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Electrical model/Discrete/qd to abc transformation'
 * '<S286>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Electrical model/Discrete/Machine measurements/Delta angle'
 * '<S287>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Electrical model/Discrete/Machine measurements/PQ'
 * '<S288>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Electrical model/Discrete/Machine measurements/Delta angle/Cartesian to Polar'
 * '<S289>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Electrical model/Discrete/Machine measurements/Delta angle/Radians to Degrees'
 * '<S290>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Electrical model/Discrete/Synchronous Machine Discrete Model/Electromagnetic Torque'
 * '<S291>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Electrical model/Discrete/Synchronous Machine Discrete Model/Matrix W'
 * '<S292>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Electrical model/Discrete/Synchronous Machine Discrete Model/Phimqd'
 * '<S293>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Electrical model/Discrete/Synchronous Machine Discrete Model/Saturation'
 * '<S294>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Electrical model/Discrete/Synchronous Machine Discrete Model/phi'
 * '<S295>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Electrical model/Discrete/Synchronous Machine Discrete Model/Saturation/Lmd_sat'
 * '<S296>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Electrical model/Discrete/Synchronous Machine Discrete Model/Saturation/Lmq_sat'
 * '<S297>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Electrical model/Discrete/Synchronous Machine Discrete Model/Saturation/Update Matrix L'
 * '<S298>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Electrical model/Discrete/Synchronous Machine Discrete Model/Saturation/Lmd_sat/Lad'
 * '<S299>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Electrical model/Discrete/Synchronous Machine Discrete Model/Saturation/Lmd_sat/phimd'
 * '<S300>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Electrical model/Discrete/Synchronous Machine Discrete Model/Saturation/Lmq_sat/Laq'
 * '<S301>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Electrical model/Discrete/Synchronous Machine Discrete Model/Saturation/Lmq_sat/phimq'
 * '<S302>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Electrical model/Discrete/Synchronous Machine Discrete Model/phi/Subsystem'
 * '<S303>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/3.5MVA Generator with  Primary Controllers1/Synchronous Machine pu Fundamental/Mechanical model/Discrete Pm input'
 * '<S304>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/Simulated Generator Controller 3.5 MW/PQ control'
 * '<S305>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/Simulated Generator Controller 3.5 MW/PV control'
 * '<S306>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/Simulated Generator Controller 3.5 MW/PQ control/Discrete PID Controller'
 * '<S307>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/Simulated Generator Controller 3.5 MW/PQ control/Discrete PID Controller1'
 * '<S308>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/NG Genset 3.5MVA/Simulated Generator Controller 3.5 MW/PV control/Discrete PID Controller'
 * '<S309>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Inputs/Speed_System'
 * '<S310>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Inputs/Speed_System1'
 * '<S311>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DIO - Gr3'
 * '<S312>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DIO - Woodward'
 * '<S313>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DOUT type config'
 * '<S314>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/PWM IO - Gr3'
 * '<S315>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/TSDIO - Gr3'
 * '<S316>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/Woodward Primary Inputs'
 * '<S317>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DIO - Gr3/Conditioning'
 * '<S318>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DIO - Gr3/Conditioning1'
 * '<S319>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DIO - Woodward/Compare To Zero'
 * '<S320>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DIO - Woodward/Compare To Zero1'
 * '<S321>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DIO - Woodward/Compare To Zero10'
 * '<S322>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DIO - Woodward/Compare To Zero11'
 * '<S323>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DIO - Woodward/Compare To Zero12'
 * '<S324>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DIO - Woodward/Compare To Zero13'
 * '<S325>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DIO - Woodward/Compare To Zero2'
 * '<S326>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DIO - Woodward/Compare To Zero3'
 * '<S327>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DIO - Woodward/Compare To Zero4'
 * '<S328>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DIO - Woodward/Compare To Zero5'
 * '<S329>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DIO - Woodward/Compare To Zero6'
 * '<S330>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DIO - Woodward/Compare To Zero7'
 * '<S331>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DIO - Woodward/Compare To Zero8'
 * '<S332>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DIO - Woodward/Compare To Zero9'
 * '<S333>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DIO - Woodward/S-R Flip-Flop'
 * '<S334>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DIO - Woodward/S-R Flip-Flop1'
 * '<S335>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DIO - Woodward/S-R Flip-Flop2'
 * '<S336>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DIO - Woodward/S-R Flip-Flop3'
 * '<S337>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DIO - Woodward/S-R Flip-Flop4'
 * '<S338>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/DIO - Woodward/S-R Flip-Flop5'
 * '<S339>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/Woodward Primary Inputs/GR1 B AIN (CH00-15)'
 * '<S340>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/Woodward Primary Inputs/Lowpass Filter'
 * '<S341>' : 'sel751test_model_1_1_sm_system/SM_system/NG_CHP/Generator/Woodward Outputs/Woodward Primary Inputs/Lowpass Filter1'
 * '<S342>' : 'sel751test_model_1_1_sm_system/SM_system/OpComm2/Receive'
 * '<S343>' : 'sel751test_model_1_1_sm_system/SM_system/OpComm2/busStruct'
 * '<S344>' : 'sel751test_model_1_1_sm_system/SM_system/OpComm2/busStruct/Sub1'
 * '<S345>' : 'sel751test_model_1_1_sm_system/SM_system/OpComm2/busStruct/Sub2'
 * '<S346>' : 'sel751test_model_1_1_sm_system/SM_system/OpComm2/busStruct/Sub3'
 * '<S347>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type1'
 * '<S348>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type2'
 * '<S349>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type1/SSN-type-V3'
 * '<S350>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type1/SSN-type-V3/V1A'
 * '<S351>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type1/SSN-type-V3/V1A_CM'
 * '<S352>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type1/SSN-type-V3/V1B'
 * '<S353>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type1/SSN-type-V3/V1B_CM'
 * '<S354>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type1/SSN-type-V3/V1C'
 * '<S355>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type1/SSN-type-V3/V1C_CM'
 * '<S356>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type1/SSN-type-V3/V1A/Model'
 * '<S357>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type1/SSN-type-V3/V1A_CM/Model'
 * '<S358>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type1/SSN-type-V3/V1A_CM/Model/Complex'
 * '<S359>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type1/SSN-type-V3/V1B/Model'
 * '<S360>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type1/SSN-type-V3/V1B_CM/Model'
 * '<S361>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type1/SSN-type-V3/V1B_CM/Model/Complex'
 * '<S362>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type1/SSN-type-V3/V1C/Model'
 * '<S363>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type1/SSN-type-V3/V1C_CM/Model'
 * '<S364>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type1/SSN-type-V3/V1C_CM/Model/Complex'
 * '<S365>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type2/SSN-type-V3'
 * '<S366>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type2/SSN-type-V3/V1A'
 * '<S367>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type2/SSN-type-V3/V1A_CM'
 * '<S368>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type2/SSN-type-V3/V1B'
 * '<S369>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type2/SSN-type-V3/V1B_CM'
 * '<S370>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type2/SSN-type-V3/V1C'
 * '<S371>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type2/SSN-type-V3/V1C_CM'
 * '<S372>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type2/SSN-type-V3/V1A/Model'
 * '<S373>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type2/SSN-type-V3/V1A_CM/Model'
 * '<S374>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type2/SSN-type-V3/V1A_CM/Model/Complex'
 * '<S375>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type2/SSN-type-V3/V1B/Model'
 * '<S376>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type2/SSN-type-V3/V1B_CM/Model'
 * '<S377>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type2/SSN-type-V3/V1B_CM/Model/Complex'
 * '<S378>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type2/SSN-type-V3/V1C/Model'
 * '<S379>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type2/SSN-type-V3/V1C_CM/Model'
 * '<S380>' : 'sel751test_model_1_1_sm_system/SM_system/SSN Interface Block (3ph)/SSN_type2/SSN-type-V3/V1C_CM/Model/Complex'
 * '<S381>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Percentage_Loading'
 * '<S382>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase Transformer (Two Windings)'
 * '<S383>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2'
 * '<S384>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Percentage_Loading/3-phase  Instantaneous  Active & Reactive Power'
 * '<S385>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Percentage_Loading/Discrete  Mean value2'
 * '<S386>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Percentage_Loading/Discrete  Mean value2/Discrete Variable Transport Delay'
 * '<S387>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase Transformer (Two Windings)/Model'
 * '<S388>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase Transformer (Two Windings)/Model/Linear'
 * '<S389>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase Transformer (Two Windings)/Model/Linear/Linear'
 * '<S390>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase Transformer (Two Windings)/Model/Linear/Linear1'
 * '<S391>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase Transformer (Two Windings)/Model/Linear/Linear2'
 * '<S392>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2/Mode I'
 * '<S393>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2/Mode V'
 * '<S394>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2/Model'
 * '<S395>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2/Mode I/Complex'
 * '<S396>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2/Mode V/Complex'
 * '<S397>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2/Model/VI'
 * '<S398>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2/Model/VI/I A:'
 * '<S399>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2/Model/VI/I B:'
 * '<S400>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2/Model/VI/I C:'
 * '<S401>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2/Model/VI/U A:'
 * '<S402>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2/Model/VI/U B:'
 * '<S403>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2/Model/VI/U C:'
 * '<S404>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2/Model/VI/I A:/Model'
 * '<S405>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2/Model/VI/I A:/Model/Complex'
 * '<S406>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2/Model/VI/I B:/Model'
 * '<S407>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2/Model/VI/I B:/Model/Complex'
 * '<S408>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2/Model/VI/I C:/Model'
 * '<S409>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2/Model/VI/I C:/Model/Complex'
 * '<S410>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2/Model/VI/U A:/Model'
 * '<S411>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2/Model/VI/U A:/Model/Complex'
 * '<S412>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2/Model/VI/U B:/Model'
 * '<S413>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2/Model/VI/U B:/Model/Complex'
 * '<S414>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2/Model/VI/U C:/Model'
 * '<S415>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL1/Three-Phase V-I Measurement2/Model/VI/U C:/Model/Complex'
 * '<S416>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Percentage_Loading'
 * '<S417>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase Transformer (Two Windings)'
 * '<S418>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2'
 * '<S419>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Percentage_Loading/3-phase  Instantaneous  Active & Reactive Power'
 * '<S420>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Percentage_Loading/Discrete  Mean value2'
 * '<S421>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Percentage_Loading/Discrete  Mean value2/Discrete Variable Transport Delay'
 * '<S422>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase Transformer (Two Windings)/Model'
 * '<S423>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase Transformer (Two Windings)/Model/Linear'
 * '<S424>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase Transformer (Two Windings)/Model/Linear/Linear'
 * '<S425>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase Transformer (Two Windings)/Model/Linear/Linear1'
 * '<S426>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase Transformer (Two Windings)/Model/Linear/Linear2'
 * '<S427>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2/Mode I'
 * '<S428>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2/Mode V'
 * '<S429>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2/Model'
 * '<S430>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2/Mode I/Complex'
 * '<S431>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2/Mode V/Complex'
 * '<S432>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2/Model/VI'
 * '<S433>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2/Model/VI/I A:'
 * '<S434>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2/Model/VI/I B:'
 * '<S435>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2/Model/VI/I C:'
 * '<S436>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2/Model/VI/U A:'
 * '<S437>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2/Model/VI/U B:'
 * '<S438>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2/Model/VI/U C:'
 * '<S439>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2/Model/VI/I A:/Model'
 * '<S440>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2/Model/VI/I A:/Model/Complex'
 * '<S441>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2/Model/VI/I B:/Model'
 * '<S442>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2/Model/VI/I B:/Model/Complex'
 * '<S443>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2/Model/VI/I C:/Model'
 * '<S444>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2/Model/VI/I C:/Model/Complex'
 * '<S445>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2/Model/VI/U A:/Model'
 * '<S446>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2/Model/VI/U A:/Model/Complex'
 * '<S447>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2/Model/VI/U B:/Model'
 * '<S448>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2/Model/VI/U B:/Model/Complex'
 * '<S449>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2/Model/VI/U C:/Model'
 * '<S450>' : 'sel751test_model_1_1_sm_system/SM_system/XFR DYg-30 HIL2/Three-Phase V-I Measurement2/Model/VI/U C:/Model/Complex'
 * '<S451>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Controlled Current Source'
 * '<S452>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Controlled Current Source1'
 * '<S453>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Controlled Current Source2'
 * '<S454>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Discrete PID Controller alpha'
 * '<S455>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Discrete PID Controller beta'
 * '<S456>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter'
 * '<S457>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)'
 * '<S458>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Parallel_Constant_Load'
 * '<S459>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/RMS'
 * '<S460>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Subsystem'
 * '<S461>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Voltage Measurement'
 * '<S462>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Voltage Measurement1'
 * '<S463>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Voltage Measurement2'
 * '<S464>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/alpha_beta -> abc1'
 * '<S465>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/PQ'
 * '<S466>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement'
 * '<S467>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/impedance'
 * '<S468>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/impedance1'
 * '<S469>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/PQ/3-phase  Instantaneous  Active & Reactive Power'
 * '<S470>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/PQ/Compare To Constant2'
 * '<S471>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/PQ/Compare To Constant3'
 * '<S472>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/PQ/Discrete  Mean value2'
 * '<S473>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/PQ/Lagging (Pushing VARs)=TRUE Leading (Pulling VARs)=FALSE'
 * '<S474>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/PQ/Unit Delay Enabled1'
 * '<S475>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/PQ/Unit Delay Enabled3'
 * '<S476>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/PQ/Discrete  Mean value2/Discrete Variable Transport Delay'
 * '<S477>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement/Mode I'
 * '<S478>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement/Mode V'
 * '<S479>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement/Model'
 * '<S480>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement/Mode I/Complex'
 * '<S481>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement/Mode V/Complex'
 * '<S482>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement/Model/VI'
 * '<S483>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement/Model/VI/I A:'
 * '<S484>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement/Model/VI/I B:'
 * '<S485>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement/Model/VI/I C:'
 * '<S486>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement/Model/VI/U A:'
 * '<S487>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement/Model/VI/U B:'
 * '<S488>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement/Model/VI/U C:'
 * '<S489>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement/Model/VI/I A:/Model'
 * '<S490>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement/Model/VI/I A:/Model/Complex'
 * '<S491>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement/Model/VI/I B:/Model'
 * '<S492>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement/Model/VI/I B:/Model/Complex'
 * '<S493>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement/Model/VI/I C:/Model'
 * '<S494>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement/Model/VI/I C:/Model/Complex'
 * '<S495>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement/Model/VI/U A:/Model'
 * '<S496>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement/Model/VI/U A:/Model/Complex'
 * '<S497>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement/Model/VI/U B:/Model'
 * '<S498>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement/Model/VI/U B:/Model/Complex'
 * '<S499>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement/Model/VI/U C:/Model'
 * '<S500>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Meter/Three-Phase V-I Measurement/Model/VI/U C:/Model/Complex'
 * '<S501>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model'
 * '<S502>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete'
 * '<S503>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Automatic Gain Control'
 * '<S504>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Discrete'
 * '<S505>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Second-Order Filter'
 * '<S506>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Variable Frequency Mean value'
 * '<S507>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/abc to dq0'
 * '<S508>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)'
 * '<S509>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1'
 * '<S510>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2'
 * '<S511>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0'
 * '<S512>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model'
 * '<S513>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model/Discrete'
 * '<S514>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model/Discrete/Correction subsystem'
 * '<S515>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model/Discrete/Discrete Variable Time Delay'
 * '<S516>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model'
 * '<S517>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model/Discrete'
 * '<S518>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model/Discrete/Correction subsystem'
 * '<S519>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model/Discrete/Discrete Variable Time Delay'
 * '<S520>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0'
 * '<S521>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/abc to Alpha-Beta-Zero'
 * '<S522>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0/Compare To Constant'
 * '<S523>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0/Compare To Constant1'
 * '<S524>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay'
 * '<S525>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0/Subsystem1'
 * '<S526>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Second-Order Filter/Model'
 * '<S527>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Second-Order Filter/Model/Discrete'
 * '<S528>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Second-Order Filter/Model/Discrete/A*k(k-1)'
 * '<S529>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Second-Order Filter/Model/Discrete/B*(u(k)+u(k-1))'
 * '<S530>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Second-Order Filter/Model/Discrete/C*x(k)'
 * '<S531>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Variable Frequency Mean value/Model'
 * '<S532>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Variable Frequency Mean value/Model/Discrete'
 * '<S533>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Variable Frequency Mean value/Model/Discrete/Correction subsystem'
 * '<S534>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/Variable Frequency Mean value/Model/Discrete/Discrete Variable Time Delay'
 * '<S535>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/abc to dq0/Alpha-Beta-Zero to dq0'
 * '<S536>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/abc to dq0/abc to Alpha-Beta-Zero'
 * '<S537>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/abc to dq0/Alpha-Beta-Zero to dq0/Compare To Constant'
 * '<S538>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/abc to dq0/Alpha-Beta-Zero to dq0/Compare To Constant1'
 * '<S539>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay'
 * '<S540>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/PLL (3ph)/Model/Discrete/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem1'
 * '<S541>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/RMS/RMS '
 * '<S542>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/RMS/TrueRMS '
 * '<S543>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/RMS/RMS /Fourier1'
 * '<S544>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/RMS/RMS /Fourier1/Mean'
 * '<S545>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/RMS/RMS /Fourier1/Mean value1'
 * '<S546>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/RMS/RMS /Fourier1/Mean/Model'
 * '<S547>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/RMS/RMS /Fourier1/Mean/Model/Discrete'
 * '<S548>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/RMS/RMS /Fourier1/Mean/Model/Discrete/Discrete Variable Time Delay'
 * '<S549>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/RMS/RMS /Fourier1/Mean value1/Model'
 * '<S550>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/RMS/RMS /Fourier1/Mean value1/Model/Discrete'
 * '<S551>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/RMS/RMS /Fourier1/Mean value1/Model/Discrete/Discrete Variable Time Delay'
 * '<S552>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/RMS/TrueRMS /Mean value'
 * '<S553>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/RMS/TrueRMS /Mean value/Model'
 * '<S554>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/RMS/TrueRMS /Mean value/Model/Discrete'
 * '<S555>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/RMS/TrueRMS /Mean value/Model/Discrete/Discrete Variable Time Delay'
 * '<S556>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Voltage Measurement/Model'
 * '<S557>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Voltage Measurement/Model/Complex'
 * '<S558>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Voltage Measurement1/Model'
 * '<S559>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Voltage Measurement1/Model/Complex'
 * '<S560>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Voltage Measurement2/Model'
 * '<S561>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad/Voltage Measurement2/Model/Complex'
 * '<S562>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Controlled Current Source'
 * '<S563>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Controlled Current Source1'
 * '<S564>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Controlled Current Source2'
 * '<S565>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Discrete PID Controller alpha'
 * '<S566>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Discrete PID Controller beta'
 * '<S567>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter'
 * '<S568>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)'
 * '<S569>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Parallel_Constant_Load'
 * '<S570>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/RMS'
 * '<S571>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Subsystem'
 * '<S572>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Voltage Measurement'
 * '<S573>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Voltage Measurement1'
 * '<S574>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Voltage Measurement2'
 * '<S575>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/alpha_beta -> abc1'
 * '<S576>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/PQ'
 * '<S577>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement'
 * '<S578>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/impedance'
 * '<S579>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/impedance1'
 * '<S580>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/PQ/3-phase  Instantaneous  Active & Reactive Power'
 * '<S581>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/PQ/Compare To Constant2'
 * '<S582>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/PQ/Compare To Constant3'
 * '<S583>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/PQ/Discrete  Mean value2'
 * '<S584>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/PQ/Lagging (Pushing VARs)=TRUE Leading (Pulling VARs)=FALSE'
 * '<S585>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/PQ/Unit Delay Enabled1'
 * '<S586>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/PQ/Unit Delay Enabled3'
 * '<S587>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/PQ/Discrete  Mean value2/Discrete Variable Transport Delay'
 * '<S588>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement/Mode I'
 * '<S589>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement/Mode V'
 * '<S590>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement/Model'
 * '<S591>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement/Mode I/Complex'
 * '<S592>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement/Mode V/Complex'
 * '<S593>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement/Model/VI'
 * '<S594>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement/Model/VI/I A:'
 * '<S595>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement/Model/VI/I B:'
 * '<S596>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement/Model/VI/I C:'
 * '<S597>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement/Model/VI/U A:'
 * '<S598>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement/Model/VI/U B:'
 * '<S599>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement/Model/VI/U C:'
 * '<S600>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement/Model/VI/I A:/Model'
 * '<S601>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement/Model/VI/I A:/Model/Complex'
 * '<S602>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement/Model/VI/I B:/Model'
 * '<S603>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement/Model/VI/I B:/Model/Complex'
 * '<S604>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement/Model/VI/I C:/Model'
 * '<S605>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement/Model/VI/I C:/Model/Complex'
 * '<S606>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement/Model/VI/U A:/Model'
 * '<S607>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement/Model/VI/U A:/Model/Complex'
 * '<S608>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement/Model/VI/U B:/Model'
 * '<S609>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement/Model/VI/U B:/Model/Complex'
 * '<S610>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement/Model/VI/U C:/Model'
 * '<S611>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Meter/Three-Phase V-I Measurement/Model/VI/U C:/Model/Complex'
 * '<S612>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model'
 * '<S613>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete'
 * '<S614>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Automatic Gain Control'
 * '<S615>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Discrete'
 * '<S616>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Second-Order Filter'
 * '<S617>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Variable Frequency Mean value'
 * '<S618>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/abc to dq0'
 * '<S619>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)'
 * '<S620>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1'
 * '<S621>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2'
 * '<S622>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0'
 * '<S623>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model'
 * '<S624>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model/Discrete'
 * '<S625>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model/Discrete/Correction subsystem'
 * '<S626>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)1/Model/Discrete/Discrete Variable Time Delay'
 * '<S627>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model'
 * '<S628>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model/Discrete'
 * '<S629>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model/Discrete/Correction subsystem'
 * '<S630>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/Mean (Variable Frequency)2/Model/Discrete/Discrete Variable Time Delay'
 * '<S631>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0'
 * '<S632>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/abc to Alpha-Beta-Zero'
 * '<S633>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0/Compare To Constant'
 * '<S634>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0/Compare To Constant1'
 * '<S635>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay'
 * '<S636>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Automatic Gain Control/Positive-Sequence (PLL-Driven)/abc ->dq0/Alpha-Beta-Zero to dq0/Subsystem1'
 * '<S637>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Second-Order Filter/Model'
 * '<S638>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Second-Order Filter/Model/Discrete'
 * '<S639>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Second-Order Filter/Model/Discrete/A*k(k-1)'
 * '<S640>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Second-Order Filter/Model/Discrete/B*(u(k)+u(k-1))'
 * '<S641>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Second-Order Filter/Model/Discrete/C*x(k)'
 * '<S642>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Variable Frequency Mean value/Model'
 * '<S643>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Variable Frequency Mean value/Model/Discrete'
 * '<S644>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Variable Frequency Mean value/Model/Discrete/Correction subsystem'
 * '<S645>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/Variable Frequency Mean value/Model/Discrete/Discrete Variable Time Delay'
 * '<S646>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/abc to dq0/Alpha-Beta-Zero to dq0'
 * '<S647>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/abc to dq0/abc to Alpha-Beta-Zero'
 * '<S648>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/abc to dq0/Alpha-Beta-Zero to dq0/Compare To Constant'
 * '<S649>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/abc to dq0/Alpha-Beta-Zero to dq0/Compare To Constant1'
 * '<S650>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay'
 * '<S651>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/PLL (3ph)/Model/Discrete/abc to dq0/Alpha-Beta-Zero to dq0/Subsystem1'
 * '<S652>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/RMS/RMS '
 * '<S653>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/RMS/TrueRMS '
 * '<S654>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/RMS/RMS /Fourier1'
 * '<S655>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/RMS/RMS /Fourier1/Mean'
 * '<S656>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/RMS/RMS /Fourier1/Mean value1'
 * '<S657>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/RMS/RMS /Fourier1/Mean/Model'
 * '<S658>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/RMS/RMS /Fourier1/Mean/Model/Discrete'
 * '<S659>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/RMS/RMS /Fourier1/Mean/Model/Discrete/Discrete Variable Time Delay'
 * '<S660>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/RMS/RMS /Fourier1/Mean value1/Model'
 * '<S661>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/RMS/RMS /Fourier1/Mean value1/Model/Discrete'
 * '<S662>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/RMS/RMS /Fourier1/Mean value1/Model/Discrete/Discrete Variable Time Delay'
 * '<S663>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/RMS/TrueRMS /Mean value'
 * '<S664>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/RMS/TrueRMS /Mean value/Model'
 * '<S665>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/RMS/TrueRMS /Mean value/Model/Discrete'
 * '<S666>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/RMS/TrueRMS /Mean value/Model/Discrete/Discrete Variable Time Delay'
 * '<S667>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Voltage Measurement/Model'
 * '<S668>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Voltage Measurement/Model/Complex'
 * '<S669>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Voltage Measurement1/Model'
 * '<S670>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Voltage Measurement1/Model/Complex'
 * '<S671>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Voltage Measurement2/Model'
 * '<S672>' : 'sel751test_model_1_1_sm_system/SM_system/alpha_betaActiveLoad1/Voltage Measurement2/Model/Complex'
 * '<S673>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Breaker'
 * '<S674>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Breaker1'
 * '<S675>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Breaker2'
 * '<S676>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Breaker3'
 * '<S677>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Compare To Constant1'
 * '<S678>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Compare To Zero'
 * '<S679>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Compare To Zero1'
 * '<S680>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Compare To Zero2'
 * '<S681>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Compare To Zero3'
 * '<S682>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Breaker/Model'
 * '<S683>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Breaker/Model/ArtemisDiscrete'
 * '<S684>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Breaker/Model/ArtemisDiscrete/Timer'
 * '<S685>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Breaker/Model/ArtemisDiscrete/fts5conversion'
 * '<S686>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Breaker/Model/ArtemisDiscrete/fts5conversion1'
 * '<S687>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Breaker1/Model'
 * '<S688>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Breaker1/Model/ArtemisDiscrete'
 * '<S689>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Breaker1/Model/ArtemisDiscrete/Timer'
 * '<S690>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Breaker1/Model/ArtemisDiscrete/fts5conversion'
 * '<S691>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Breaker1/Model/ArtemisDiscrete/fts5conversion1'
 * '<S692>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Breaker2/Model'
 * '<S693>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Breaker2/Model/ArtemisDiscrete'
 * '<S694>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Breaker2/Model/ArtemisDiscrete/Timer'
 * '<S695>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Breaker2/Model/ArtemisDiscrete/fts5conversion'
 * '<S696>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Breaker2/Model/ArtemisDiscrete/fts5conversion1'
 * '<S697>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Breaker3/Model'
 * '<S698>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Breaker3/Model/ArtemisDiscrete'
 * '<S699>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Breaker3/Model/ArtemisDiscrete/Timer'
 * '<S700>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Breaker3/Model/ArtemisDiscrete/fts5conversion'
 * '<S701>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault/Breaker3/Model/ArtemisDiscrete/fts5conversion1'
 * '<S702>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Breaker'
 * '<S703>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Breaker1'
 * '<S704>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Breaker2'
 * '<S705>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Breaker3'
 * '<S706>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Compare To Constant1'
 * '<S707>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Compare To Zero'
 * '<S708>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Compare To Zero1'
 * '<S709>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Compare To Zero2'
 * '<S710>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Compare To Zero3'
 * '<S711>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Breaker/Model'
 * '<S712>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Breaker/Model/ArtemisDiscrete'
 * '<S713>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Breaker/Model/ArtemisDiscrete/Timer'
 * '<S714>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Breaker/Model/ArtemisDiscrete/fts5conversion'
 * '<S715>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Breaker/Model/ArtemisDiscrete/fts5conversion1'
 * '<S716>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Breaker1/Model'
 * '<S717>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Breaker1/Model/ArtemisDiscrete'
 * '<S718>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Breaker1/Model/ArtemisDiscrete/Timer'
 * '<S719>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Breaker1/Model/ArtemisDiscrete/fts5conversion'
 * '<S720>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Breaker1/Model/ArtemisDiscrete/fts5conversion1'
 * '<S721>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Breaker2/Model'
 * '<S722>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Breaker2/Model/ArtemisDiscrete'
 * '<S723>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Breaker2/Model/ArtemisDiscrete/Timer'
 * '<S724>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Breaker2/Model/ArtemisDiscrete/fts5conversion'
 * '<S725>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Breaker2/Model/ArtemisDiscrete/fts5conversion1'
 * '<S726>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Breaker3/Model'
 * '<S727>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Breaker3/Model/ArtemisDiscrete'
 * '<S728>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Breaker3/Model/ArtemisDiscrete/Timer'
 * '<S729>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Breaker3/Model/ArtemisDiscrete/fts5conversion'
 * '<S730>' : 'sel751test_model_1_1_sm_system/SM_system/opElectricFault1/Breaker3/Model/ArtemisDiscrete/fts5conversion1'
 * '<S731>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/OpFault'
 * '<S732>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/OpSequencer'
 * '<S733>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/opPOWsynch'
 * '<S734>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/OpFault/Ang'
 * '<S735>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/OpFault/Fault_synchronization'
 * '<S736>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/OpFault/S-R Flip-Flop1'
 * '<S737>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/OpFault/Tdr'
 * '<S738>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/OpFault/Tst'
 * '<S739>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/OpFault/Fault_synchronization/Discrete Monostable SIMPLIFIED'
 * '<S740>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/OpFault/Fault_synchronization/S-R Flip-Flop'
 * '<S741>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/OpSequencer/Acquisition_timer'
 * '<S742>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/OpSequencer/Compare To Constant'
 * '<S743>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/OpSequencer/S-R Flip-Flop'
 * '<S744>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/OpSequencer/Acquisition_timer/S-R Flip-Flop'
 * '<S745>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/opPOWsynch/Discrete 1-phase PLL'
 * '<S746>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/opPOWsynch/falling voltage level detect'
 * '<S747>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/opPOWsynch/rising voltage level detect'
 * '<S748>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/opPOWsynch/Discrete 1-phase PLL/2nd-Order Filter'
 * '<S749>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/opPOWsynch/Discrete 1-phase PLL/Automatic Gain Control'
 * '<S750>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/opPOWsynch/Discrete 1-phase PLL/Controller'
 * '<S751>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/opPOWsynch/Discrete 1-phase PLL/Discrete Rate Limiter'
 * '<S752>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/opPOWsynch/Discrete 1-phase PLL/Variable Frequency Mean value'
 * '<S753>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/opPOWsynch/Discrete 1-phase PLL/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value'
 * '<S754>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/opPOWsynch/Discrete 1-phase PLL/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Cartesian to Polar'
 * '<S755>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/opPOWsynch/Discrete 1-phase PLL/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value'
 * '<S756>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/opPOWsynch/Discrete 1-phase PLL/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value1'
 * '<S757>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/opPOWsynch/Discrete 1-phase PLL/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value/Correction subsystem'
 * '<S758>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/opPOWsynch/Discrete 1-phase PLL/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value/Discrete Variable Transport Delay'
 * '<S759>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/opPOWsynch/Discrete 1-phase PLL/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value1/Correction subsystem'
 * '<S760>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/opPOWsynch/Discrete 1-phase PLL/Automatic Gain Control/Discrete PLL-Driven  Fundamental Value/Discrete Variable Frequency Mean value1/Discrete Variable Transport Delay'
 * '<S761>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/opPOWsynch/Discrete 1-phase PLL/Controller/Discrete Derivative'
 * '<S762>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/opPOWsynch/Discrete 1-phase PLL/Variable Frequency Mean value/Correction subsystem'
 * '<S763>' : 'sel751test_model_1_1_sm_system/SM_system/opPOWFaultControl1/opPOWsynch/Discrete 1-phase PLL/Variable Frequency Mean value/Discrete Variable Transport Delay'
 * '<S764>' : 'sel751test_model_1_1_sm_system/SM_system/rtlab_send_subsystem/Subsystem1'
 * '<S765>' : 'sel751test_model_1_1_sm_system/SM_system/rtlab_send_subsystem/Subsystem4'
 * '<S766>' : 'sel751test_model_1_1_sm_system/SM_system/rtlab_send_subsystem/Subsystem1/Send1'
 * '<S767>' : 'sel751test_model_1_1_sm_system/SM_system/rtlab_send_subsystem/Subsystem4/Send4'
 * '<S768>' : 'sel751test_model_1_1_sm_system/SM_system/zzzOpComm/Receive_1'
 * '<S769>' : 'sel751test_model_1_1_sm_system/SM_system/zzzOpComm/busStruct'
 * '<S770>' : 'sel751test_model_1_1_sm_system/SM_system/zzzOpComm/busStruct/Sub1'
 * '<S771>' : 'sel751test_model_1_1_sm_system/powergui/EquivalentModel1'
 * '<S772>' : 'sel751test_model_1_1_sm_system/powergui/EquivalentModel1/Gates'
 * '<S773>' : 'sel751test_model_1_1_sm_system/powergui/EquivalentModel1/Sources'
 * '<S774>' : 'sel751test_model_1_1_sm_system/powergui/EquivalentModel1/Status'
 * '<S775>' : 'sel751test_model_1_1_sm_system/powergui/EquivalentModel1/Yout'
 */
#endif                                 /* RTW_HEADER_sel751test_model_1_1_sm_system_h_ */
