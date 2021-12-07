/** @file
 *  @brief Header file for the single curve interpolation
 */
#ifndef SINGLE_CURVE_SINGLE_CURVE_H_
#define SINGLE_CURVE_SINGLE_CURVE_H_

#include <stdint.h>
#include <float.h>

/** @brief Interpolate and obtain y value based on x value
 *  @param[in] y_values List of predefined y values
 *  @param[in] interpolated_values List of x values based on the interpolation of two curves
 *  @param[in] array_length length of the y_values and interolated_values array
 *  @param[in] x_value x value for which a y value should be determined
 *  @param[out] y_value result of the interpolation
 */
void interpolate(int8_t* y_values, float* interpolated_values, uint8_t array_length, uint16_t x_value, float* y_value);

#endif  // SINGLE_CURVE_SINGLE_CURVE_H_