#ifndef  MOTOR_CONTROLLER_SPECIFIC_RESPONSE_H__
#define  MOTOR_CONTROLLER_SPECIFIC_RESPONSE_H__

#include <stdint.h>

/** @file   motor_controller/specific_response.h
 *  @brief  Defines structures for the response packets, and a helper API
 *
 *          Device specific responses are sent in reply to a request where the 
 *          FLAG byte is < 0x80.  
 *      
 *          These responses allow for the tailoring of the protocol to minimize
 *          bandwidth, as sequential reads are not required.  Also, data not 
 *          available in the CSR can be transmitted as well. 
 */


/** @enum 
* @brief Define PRO4 Devices specific response packets */ 
typedef enum {
               /** A one byte reply, just the device type in the payload */ 
               RESPONSE_ACK_FLAG = 1,
               /** Standard motor operating parameters */
               RESPONSE_THRUSTER_STANDARD
             } MOTOR_CONTROLLER_RESPONSES;

/** @struct Response Structures
 *  @brief Structures defining the response packets.
 * 
 * Motor operating parameter response 
 */
typedef struct Response_Thruster_Standard_tag {
 /*@{*/
    /** Measured shaft rotational velocity */
    float rpm;
    /** Bus voltage (Volts) */
    float bus_v;
    /** Bus current (Amps) */
    float bus_i;
    /** Temperature (Degree C) */
    float temp;
    /** fault flags */
    uint8_t fault;
} Response_Thruster_Standard;

/*@}*/
#endif
