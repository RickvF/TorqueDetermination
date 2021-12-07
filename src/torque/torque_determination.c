/** @file
 *  @brief Source file for the determination of the torque
 */

#include "torque_determination.h"
 
#include <stdio.h>

void determine_torque(uint16_t angle, uint16_t vehicle_speed, float* value){
    interpolate_multiple(zero_kmh_curve, fift_kmh_curve, torque_curve, MAXIMUM_VALID_SPEED, vehicle_speed, TORQUE_MAP_LENGTH, angle, value);
}