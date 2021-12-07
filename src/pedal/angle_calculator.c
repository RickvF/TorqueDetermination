/** @file
 *  @brief Source file for the calculation of a pedal angle based on a single ADC channel
 */

#include "angle_calculator.h"
 
#include <stdio.h>

angle_return_t calculate_angle(adc_channel_id_t id, float fac1, float fac2, uint8_t* value){
    adc_value_t adc_value = 0;
    float filtered_adc_value = 0;
    float voltage = 0;
    
    //obtain adc value
    adc_return_t status = adc_read(id, &adc_value);

    if(status == ADC_RET_NOK){
        set_generic_fault();
        *value = 0;
        return ANGLE_NOK;
    }  

    //convert counts to voltage
    adc_to_voltage(adc_value, &voltage);
    
    if(PRINTDEBUG){
        printf("[CALCULATE ANGLE] VOLTAGE: %f\n", voltage);
    }

    //calculate angle based on voltage
    uint8_t calculated_angle = (int)(((voltage - fac1) / fac2));

    if(PRINTDEBUG){
        printf("[CALCULATE ANGLE] ANGLE: %i\n", calculated_angle);
    }

    //check angle between boundaries
    if(MINIMUM_PEDAL_ANGLE <= calculated_angle && MAXIMUM_PEDAL_ANGLE >= calculated_angle){
        *value = (int)calculated_angle;
        return ANGLE_OK;
    } else {
        set_generic_fault();
        return ANGLE_NOK;
    }

    return ANGLE_NOK;
}