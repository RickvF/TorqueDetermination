/** @file
 *  @brief Source file for the fault manager to set and heal faults. Fault manager determines fault reaction
 */

 #include "fault_manager.h"
 
 #include <stdio.h>

 void fault_manager_init(){
    printf("[Fault manager] Initializing completed. All faults are healed.\n");
 }

void set_generic_fault(){
    printf("[Fault manager] Set generic fault\n");
    error_led_set(true);
}


void heal_generic_fault(){
    printf("[Fault manager] Heal generic fault\n");
    error_led_set(false);
}