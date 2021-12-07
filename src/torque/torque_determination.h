/** @file
 *  @brief Header file for the determination of the torque
 */
#ifndef TORQUE_TORQUE_DETERMINATION_H_
#define TORQUE_TORQUE_DETERMINATION_H_

#include <stdint.h>

#include "../interpolation/multi_curve/multi_curve.h"
#include "../drivers/vehicle_speed/vehicle_speed.h"

#define TORQUE_MAP_LENGTH 7

static float zero_kmh_curve[TORQUE_MAP_LENGTH] = {0.0, 14.1176, 17.0588, 23.3333, 38.3333, 58.0, 77.1429};
static float fift_kmh_curve[TORQUE_MAP_LENGTH] = {15.0, 27.5, 30.0, 36.6667, 51.1111, 66.9565, 84.0};
static int8_t torque_curve[TORQUE_MAP_LENGTH] = {0, 25, 30, 45, 60, 80, 100};

/** @brief determine the torque based on the pedal angle and vehicle speed
 *  @param[in] angle Pedal angle between 0 and 30 degrees
 *  @param[in] vehicle_speed vehicle speed
 *  @param[out] value determined torque
 */
void determine_torque(uint16_t angle, uint16_t vehicle_speed, float* value);

#endif  // TORQUE_TORQUE_DETERMINATION_H_