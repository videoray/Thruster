#ifndef  MOTOR_CONTROLLER_CUSTOM_COMMAND_H__
#define  MOTOR_CONTROLLER_CUSTOM_COMMAND_H__

#include <stdint.h>

/** @file   motor_controller_custom_command.h
 *  @brief  Defines structures for the custom command request packets, and any helper API
 *
 *          Device custom commands are special commands written to the CUSTOM COMMAND ADDRESS in the CSR 
 *          The custom command addres is defined as 0xF0.  
 *      
 *          These commands allow for the tailoring of the protocol to minimize
 *          bandwidth, as well as implementing multicast protocols or other paradigms outside of the standard CSR r/w methodology. 
 */

/** Define PRO4 Devices specific response packets */
typedef enum {
               /** The standard propulsion system actuation command */ 
               PROPULSION_CMD = 0xaa
             } MOTOR_CONTROLLER_CUSTOM_COMMANDS;

/** @name Custom command structures
 *  
 *  Structures defining the custom command packets.
 */
//@{
/** Propulsion power setpoint command
 *
 *  The standard propulsion command is multicast to a group of thrusters.
 *  Each thruster has a motor ID which is used as the index into array of power_targets.
 *  It is possible the multiple thruster have the same motor ID, in which case they will act in concert.
 *
 *  A single thruster (which is specified by it's node address in the second byte of the command) will respond.
 *  The response is determined by the flag byte of in the vrcsr packet header.
 *
 */
typedef struct Propulsion_power_setpoint_command_tag {
    /** Measured shaft rotational velocity */
    const uint8_t command;      // must be set to PROPULSION_COMMAND;
    uint8_t node_id_to_reply;   // protocol node address for the device which should send a response
    float *power_target;        // Variable length array of normalized power set point -1 to 1 (negative number are reverse)
} Propulsion_power_setpoint_command;

//@}
#endif
