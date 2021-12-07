/** @file
 *  @brief Source file for the vehicle speed driver
 */

#include "vehicle_speed.h"

#include <stdio.h>

static uint16_t vehicle_speed = 0;
static vehicle_speed_sgcnd_t vehicle_speed_sgcnd = VEHICLE_SPEED_SGCND_NA;

void vehicle_speed_driver_init(){
    if(PRINTDEBUG){
        printf("[Vehicle speed] Initializing completed\n");
    }
}

vehicle_speed_sgcnd_t read_vehicle_speed(uint16_t* value){
    if(vehicle_speed_sgcnd == VEHICLE_SPEED_SGCND_OK){
        *value = vehicle_speed;
        return VEHICLE_SPEED_SGCND_OK;
    }
    *value = MINIMUM_VALID_SPEED;
    return vehicle_speed_sgcnd;
}

void set_vehicle_speed(uint16_t value, vehicle_speed_sgcnd_t signal_condition){
    vehicle_speed = value;
    vehicle_speed_sgcnd = signal_condition;
}
