/** @file
 *  @brief Header file for the vehicle speed driver
 */
#ifndef DRIVERS_VEHICLE_SPEED_VEHICLE_SPEED_H_
#define DRIVERS_VEHICLE_SPEED_VEHICLE_SPEED_H_

#include <stdint.h>

#include "../../fault_manager/fault_manager.h"

#define MINIMUM_VALID_SPEED 0
#define MAXIMUM_VALID_SPEED 50

/** @brief Return type for vehicle speed signal condition */
typedef enum {
  VEHICLE_SPEED_SGCND_OK = 0,  //!< Vehicle speed valid received
  VEHICLE_SPEED_SGCND_RSVD, //!< Vehicle speed received within the reserved J1939 CAN range    
  VEHICLE_SPEED_SGCND_NA, //!< Vehicle speed not available
} vehicle_speed_sgcnd_t;

/** @brief Initializes the vehicle speed driver.
 */
void vehicle_speed_driver_init();

/** @brief Reads the value of the Vehicle speed
 *  @param[out] value The vehicle Speed value.
 *  @returns The signal condition of the vehicle speed signal.
 */
 vehicle_speed_sgcnd_t read_vehicle_speed(uint16_t* value);

 /** @brief Helper function for setting a vehicle speed and signal condition.
 *  @param[in] value The vehicle speed that should be returned by read_vehicle_speed().
 *  @param[in] return_value The signal condition indicating the state of the vehicle speed.
 */
void set_vehicle_speed(uint16_t value,
                         vehicle_speed_sgcnd_t signal_condition);

#endif  // DRIVERS_VEHICLE_SPEED_VEHICLE_SPEED_H_
