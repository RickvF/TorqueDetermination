/** @file
 *  @brief Header file for the fault manager to set and heal faults. Fault manager determines fault reaction
 */
#ifndef FAULT_MANAGER_FAULT_MANAGER_H_
#define FAULT_MANAGER_FAULT_MANAGER_H_

#include <stdint.h>

#include "../drivers/error_led/error_led.h"

#define PRINTDEBUG false

/** @brief Initializes the fault manager and heal all faults.
 */
void fault_manager_init();

/** @brief Set the generic malfunction fault and trigger fault reaction
 */
void set_generic_fault();

 /** @brief Heal the generic malfuntion fault and deactivate fault reaction
 */
void heal_generic_fault();

#endif  // FAULT_MANAGER_FAULT_MANAGER_H_