/** @file
 *  @brief Source file for a (dummy) ADC driver.
 */

#include "adc_driver.h"

#include <stdio.h>

// Some utilities that might help you with testing
static adc_value_t adc_read_values[ADC_NUM_CHANNELS] = {0};
static adc_return_t adc_read_return_value[ADC_NUM_CHANNELS] = {ADC_RET_OK};

void adc_read_set_output(adc_channel_id_t id, adc_value_t value,
                    adc_return_t return_value) {
  if (id < ADC_NUM_CHANNELS) {
    adc_read_values[id] = (adc_value_t)((MOVING_AVERAGE_FACTOR * value) + (1.0 - MOVING_AVERAGE_FACTOR) * adc_read_values[id]); //moving average on reading
    adc_read_return_value[id] = return_value;
  }
}

adc_return_t adc_init(adc_channel_id_t id) {
  if(PRINTDEBUG){
    printf("[ADC] Initializing channel %i\n", id);
  }
  return ADC_RET_OK;
}

adc_return_t adc_read(adc_channel_id_t id, adc_value_t* value) {
  *value = adc_read_values[id];
  adc_return_t return_value = adc_read_return_value[id];

  if(PRINTDEBUG){
    printf("[ADC] Reading channel %i = %u. Ret = %i\n", id, *value, return_value);
  }

  return return_value;
}

void adc_to_voltage(adc_value_t value, float* voltage){
  *voltage = (float)((value * MAX_VOLTAGE) / MAX_COUNTS);
}
