/** @file
 *  @brief Header file for the calculation of a pedal angle based on a single ADC channel
 */
#ifndef PEDAL_ANGLE_CALCULATOR_H_
#define PEDAL_ANGLE_CALCULATOR_H_

#include <stdint.h>
#include <float.h>

#include "../drivers/adc_driver/adc_driver.h"
#include "../fault_manager/fault_manager.h"

#define MINIMUM_PEDAL_ANGLE 0
#define MAXIMUM_PEDAL_ANGLE 30

/** @brief Return type for angle after calculation */
typedef enum {
  ANGLE_OK = 0,  //!< No errors during calculation
  ANGLE_NOK,  //!< Errors during calculation
} angle_return_t;

/** @brief calculate from adc the pedal angle and sets faults when invalid
 *  @param[in] id The ID of the ADC channel.
 *  @param[in] fac1 Conversion factor 1 for the adc to angle conversion.
 *  @param[in] fac2 Conversion factor 2 for the adc to angle conversion
 *  @param[out] value pedal angle between 0 and 30 degrees
 *  @returns status of the calculated angle
 */
angle_return_t calculate_angle(adc_channel_id_t id, float fac1, float fac2, uint8_t* value);

/** @brief low pass filter for adc value
 *  @param[in] avg previous calculated average which will be updated
 *  @param[in] new_sample new reading of the adc
 */
void filter(float* avg, float* new_sample);

#endif  // PEDAL_ANGLE_CALCULATOR_H_