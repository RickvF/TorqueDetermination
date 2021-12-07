/** @file
 *  @brief Header file for the multiple curve interpolation
 */
#ifndef MULTI_CURVE_MULTI_CURVE_H_
#define MULTI_CURVE_MULTI_CURVE_H_

#include <stdint.h>
#include <float.h>

#include "../single_curve/single_curve.h"

#define INTERPOLATION_MAP_LENGTH 7

/** @brief Interpolate and obtain y value based on x value
 *  @param[in] interpolated_map1 List interpolated values for the 1st curve
 *  @param[in] interpolated_map2 List of interpolated values for the 2nd curve
 *  @param[in] y_values List of predefined y values
 *  @param[in] max_value max possible value of the curve
 *  @param[in] curve_value value of which curve need to be calculated
 *  @param[in] array_length length of the y_values and interolated_values array
 *  @param[in] x_value x value for which a y value should be determined
 *  @param[out] y_value result of the interpolation
 */
void interpolate_multiple(float* interpolated_map1, float* interpolated_map2, int8_t* y_values, uint8_t max_value, uint8_t curve_value, uint8_t array_length, uint16_t x_value, float* y_value);

#endif  // MULTI_CURVE_MULTI_CURVE_H_