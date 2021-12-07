/** @file
 *  @brief Source file for the single curve interpolation
 */

#include "single_curve.h"
 
#include <stdio.h>

void interpolate(int8_t* y_values, float* interpolated_values, uint8_t array_length, uint16_t x_value, float* y_value){
    int i = 0;
    for(i; i<array_length; i++){
        if((i+1) < array_length){
            if(i==0){
                if(interpolated_values[i] <= x_value && x_value <= interpolated_values[i+1]){
                    break;
                }
            }else{
                if(interpolated_values[i] < x_value && x_value <= interpolated_values[i+1]){
                    break;
                }
            }            
        } 
    }

    if((i+1) < array_length){
        *y_value = (float)(y_values[i] + (((float)(y_values[i+1]-y_values[i])/(float)(interpolated_values[i+1]-interpolated_values[i])) * (float)(x_value - interpolated_values[i])));
    }
}