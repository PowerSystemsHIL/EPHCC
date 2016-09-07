/*
 * rt_look.c
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

#include "rt_look.h"

/*
 * Routine to get the index of the input from a table using binary or
 * interpolation search.
 *
 * Inputs:
 *   *x   : Pointer to table, x[0] ....x[xlen-1]
 *   xlen : Number of values in xtable
 *   u    : input value to look up
 *
 * Output:
 *   idx  : the index into the table such that:
 *         if u is negative
 *            x[idx] <= u < x[idx+1]
 *         else
 *            x[idx] < u <= x[idx+1]
 *
 * Interpolation Search: If the table contains a large number of nearly
 * uniformly spaced entries, i.e., x[n] vs n is linear then the index
 * corresponding to the input can be found in one shot using the linear
 * interpolation formula. Therefore if you have a look-up table block with
 * many data points, using interpolation search might speed up the code.
 * Compile the generated code with the following flag:
 *
 *            make_rtw OPTS=-DDOINTERPSEARCH
 *
 * to enable interpolation search.
 */
int_T rt_GetLookupIndex(const real_T *x, int_T xlen, real_T u)
{
  int_T idx = 0;
  int_T bottom = 0;
  int_T top = xlen-1;
  int_T retValue = 0;
  boolean_T returnStatus = 0U;

#ifdef DOINTERPSEARCH

  real_T offset = 0;

#endif

  /*
   * Deal with the extreme cases first:
   *   if u <= x[bottom] then return idx = bottom
   *   if u >= x[top]    then return idx = top-1
   */
  if (u <= x[bottom]) {
    retValue = bottom;
    returnStatus = 1U;
  } else if (u >= x[top]) {
    retValue = top-1;
    returnStatus = 1U;
  } else {
    /* else required to ensure safe programming, even *
     * if it's expected that it will never be reached */
  }

  if (returnStatus == 0U) {
    if (u < 0) {
      /* For negative input find index such that: x[idx] <= u < x[idx+1] */
      for (;;) {

#ifdef DOINTERPSEARCH

        offset = (u-x[bottom])/(x[top]-x[bottom]);
        idx = bottom + (int_T)((top-bottom)*(offset-DBL_EPSILON));

#else

        idx = (bottom + top)/2;

#endif

        if (u < x[idx]) {
          top = idx - 1;
        } else if (u >= x[idx+1]) {
          bottom = idx + 1;
        } else {
          /* we have x[idx] <= u < x[idx+1], return idx */
          retValue = idx;
          break;
        }
      }
    } else {
      /* For non-negative input find index such that: x[idx] < u <= x[idx+1] */
      for (;;) {

#ifdef DOINTERPSEARCH

        offset = (u-x[bottom])/(x[top]-x[bottom]);
        idx = bottom + (int_T)((top-bottom)*(offset-DBL_EPSILON));

#else

        idx = (bottom + top)/2;

#endif

        if (u <= x[idx]) {
          top = idx - 1;
        } else if (u > x[idx+1]) {
          bottom = idx + 1;
        } else {
          /* we have x[idx] < u <= x[idx+1], return idx */
          retValue = idx;
          break;
        }
      }
    }
  }

  return retValue;
}
