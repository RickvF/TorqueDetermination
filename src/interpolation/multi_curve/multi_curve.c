/** @file
 *  @brief Source file for the multiple curve interpolation
 */

 
#include <stdio.h>

#include "multi_curve.h"



void interpolate_multiple(float* interpolated_map1, float* interpolated_map2, int8_t* y_values, uint8_t max_value, uint8_t curve_value, uint8_t array_length, uint16_t x_value, float* y_value){
    float interpolated_values[INTERPOLATION_MAP_LENGTH] = {0};

    for(int i=0; i<array_length; i++){
        interpolated_values[i] = interpolated_map1[i] + (interpolated_map2[i]-interpolated_map1[i])*(float)((float)(curve_value)/(float)(max_value-0));
    }

    interpolate(y_values, interpolated_values, array_length, x_value, y_value);
    
}