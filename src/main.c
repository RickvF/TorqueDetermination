/** @file
 *  @brief Main file.
 *  @description Just contains some example code. Adapt it in the way you like.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "drivers/adc_driver/adc_driver.h"
#include "drivers/error_led/error_led.h"
#include "drivers/vehicle_speed/vehicle_speed.h"
#include "pedal/angle_calculator.h"
#include "torque/torque_determination.h"

#define ADC1_FACTOR1 0.5
#define ADC1_FACTOR2 0.1
#define ADC2_FACTOR1 1.0
#define ADC2_FACTOR2 0.08

#define AMOUNT_READING_FILTER 100

/** @brief generic function to set the preconditions for a single testcase
 *  @param[in] adc1 counts value for adc1
 *  @param[in] adc2 counts value for adc2
 *  @param[in] vehicle_speed vehicle speed
 */
void testcase(uint16_t adc1, uint16_t adc2, uint16_t vehcile_speed){
  for(int i=0; i<AMOUNT_READING_FILTER; i++){
    adc_read_set_output(ADC_CHANNEL0, adc1, ADC_RET_OK);
    adc_read_set_output(ADC_CHANNEL1, adc2, ADC_RET_OK);
    set_vehicle_speed(vehcile_speed, VEHICLE_SPEED_SGCND_OK);
  }
}

/** @brief testcase for scenario pedal to 10 degrees and vehicle speed to 0km/h
 */
void testcase_pedal10_vehicle0(){
  testcase(130, 160, 0);
}

/** @brief testcase for scenario pedal to 10 degrees and vehicle speed to 10km/h
 */
void testcase_pedal10_vehicle10(){
  testcase(130, 160, 10);
}

/** @brief testcase for scenario pedal to 10 degrees and vehicle speed to 40km/h
 */
void testcase_pedal10_vehicle40(){
  testcase(130, 160, 40);
}

/** @brief testcase for scenario pedal to 10 degrees and vehicle speed to 50km/h
 */
void testcase_pedal10_vehicle50(){
  testcase(130, 160, 50);
}

/** @brief testcase for scenario pedal to 30 degrees and vehicle speed to 0km/h
 */
void testcase_pedal30_vehicle0(){
  testcase(305, 295, 0);
}

/** @brief testcase for scenario pedal to 30 degrees and vehicle speed to 40km/h
 */
void testcase_pedal30_vehicle40(){
  testcase(305, 295, 40);
}

/** @brief testcase for scenario pedal to 30 degrees and vehicle speed to 50km/h
 */
void testcase_pedal30_vehicle50(){
  testcase(305, 295, 50);
}

/** @brief testcase for scenario pedal to 80 degrees and vehicle speed to 40km/h
 */
void testcase_pedal80_OK(){
  testcase(730, 635, 40);
}

/** @brief Determine torque based on set preconditions
 */
void program(){
  uint8_t angle_adc1 = 0;
  uint8_t angle_adc2 = 0;
  angle_return_t status_angle1 = calculate_angle(ADC_CHANNEL0, ADC1_FACTOR1, ADC1_FACTOR2, &angle_adc1);
  angle_return_t status_angle2 = calculate_angle(ADC_CHANNEL1, ADC2_FACTOR1, ADC2_FACTOR2, &angle_adc2);

  printf("[ANGLE 1] %i\n", angle_adc1);
  printf("[ANGLE 2]  %i\n", angle_adc2);

  uint16_t vehicle_speed = 0;
  vehicle_speed_sgcnd_t vehicle_speed_sgcnd = read_vehicle_speed(&vehicle_speed);

  printf("[VEHICLE SPEED] Speed %i, Sgcnd %i\n", vehicle_speed, vehicle_speed_sgcnd);

  //Safety measure to validate angles are equal.
  if(angle_adc1 == angle_adc2 && status_angle1 == ANGLE_OK && status_angle2 == ANGLE_OK){ 
    //Check validity of the speed signal
    if(MINIMUM_VALID_SPEED <= vehicle_speed && MAXIMUM_VALID_SPEED >= vehicle_speed  && vehicle_speed_sgcnd == VEHICLE_SPEED_SGCND_OK){
      float torque = 0;
      determine_torque(angle_adc1, vehicle_speed, &torque);
      printf("\n[TORQUE] Requested torque: %f\n", torque);
    } else{
      printf("[TORQUE] Vehicle speed invalid, no torque determined.\n");
      set_generic_fault();
    }   
  } else {
    printf("[Torque] Angle invalid, no torque determined.\n");
    set_generic_fault();
  }
}


int main(int argc, char *argv[]) {
  error_led_init();
  adc_init(ADC_CHANNEL0);
  adc_init(ADC_CHANNEL1);
  vehicle_speed_driver_init();

  // execute testcase with a pedal position of 10 degree.
  printf("\n\n[TESTCASE 10 degrees]\n\n");
  printf("[TESTCASE VEHICLE SPEED 0 km/h]\n\n");
  heal_generic_fault();
  testcase_pedal10_vehicle0();
  program();

  printf("\n[TESTCASE VEHICLE SPEED 10 km/h]\n\n");
  heal_generic_fault();
  testcase_pedal10_vehicle10();
  program();

  printf("\n[TESTCASE VEHICLE SPEED 40 km/h]\n\n");
  heal_generic_fault();
  testcase_pedal10_vehicle40();
  program();

  printf("\nTESTCASE [VEHICLE SPEED 50 km/h]\n\n");
  heal_generic_fault();
  testcase_pedal10_vehicle50();
  program();

  // execute testcase with a pedal position of 30 degree.
  printf("\n\n[TESTCASE 30 degrees]\n\n");
  printf("[TESTCASE VEHICLE SPEED 0 km/h]\n\n");
  heal_generic_fault();
  testcase_pedal30_vehicle0();
  program();

  printf("\n[TESTCASE VEHICLE SPEED 40 km/h]\n\n");
  heal_generic_fault();
  testcase_pedal30_vehicle40();
  program();

  printf("\n[TESTCASE VEHICLE SPEED 50 km/h]\n\n");
  heal_generic_fault();
  testcase_pedal30_vehicle50();
  program();

  //execute testcase with a pedal position of 80 degree.
  printf("\n\n[TESTCASE 80 degrees]\n\n");
  printf("[TESTCASE VEHICLE SPEED 40 km/h]\n\n");
  heal_generic_fault();
  testcase_pedal80_OK();
  program();
}
