#ifndef MOTOR_CONTROLLER_CSR_H__
#define MOTOR_CONTROLLER_CSR_H__

#include <stdint.h>
/** @file   motor_controller/CSR.h
 *  @brief  CSR Struct and application specific command definitions for the bootloader
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

#define PROPULSION_COMMAND 0xaa


/** @struct CSR_Motor_Controller_tag 
 * @brief Structure definition for the m5 Motor Controller CSR file.
 *
 * The standard CSR memory space is at most 256 bytes.  
 * The entire memory space is reserved by this structure.
 * Assumes that the structure is packed and byte aligned.
 * It may be necessary to hand tune member sizes to insure proper alignment and packing.
 */
 typedef struct CSR_Motor_Controller_tag {
    /*@{*/
    /** @name Control Section, values sent at high update rates  
    */
    float rpm_target;           // rpm          (RW) NOT USED YET
    float pwr_target;           // -1 to 1      (RW)
    float rpm;                  // rpm          (R)
    float bus_v;                // volts        (R)
    float bus_i;                // amps         (R)
    uint32_t fault;             // fault flags  (R)
    float temp;                 // deg C        (R)
    float pwr_actual;           // -1 to 1      (R)
    float rpm_P;                // 0 to 1       (R) NOT USED YET
    float rpm_I;                // 0 to 1       (R) NOT USED YET
    float rpm_D;                // 0 to 1       (R) NOT USED YET

    char reserved[32];
    /*@}*/
    
    /*@{*/
    /** @name application config parameters
    */
    uint16_t motor_ID;               // ordinal  (RW)
    char reserved1[2];
    uint8_t system_flags;
    char reserved2[3];
    uint32_t fault_interlock;  // password (RW)

    char reserved3[8];
 
    /*@}*/
    
    /*@{*/
    /** @name motor control parameters
    */
    uint8_t control_flags;      // Bitfield     (RW) 
    uint8_t motor_control_flags;      // Bitfield     (RW)
    uint8_t poles;              // count        (RW)
    uint8_t pwm_deadband;       // ticks        (RW)
    float commutation_threshold;         // 0 to 1       (RW)
    uint32_t commutation_loss_timeout;   // ms  (RW)
    float startup_dutycycle;             // 0 to 1       (RW)
    uint16_t startup_initial_rpm;                // rpm          (RW)
    uint16_t startup_final_rpm;                  // rpm          (RW)
    float startup_duration;      // mS           (RW)
    float deadband_neg;         // -1 to 0      (RW)
    float deadband_pos;         //  0 to 1      (RW)
    float dutycycle_limit_neg;            // -1 to 0      (RW)
    float dutycycle_limit_pos;            //  0 to 1      (RW)
    float acceleration_rate;              // delta/mS     (RW)
    float deceleration_rate;            // delta/mS     (RW)
    float rpm_kP;               // -1 to 1      (RW) NOT USED YET
    float rpm_kI;               // -1 to 1      (RW) NOT USED YET
    float rpm_kD;               // -1 to 1      (RW) NOT USED YET

    char reserved5[4];
    /*@}*/
    
    /*@{*/
    /** @name fault control parameters
    */
    uint32_t fault_control;              // flag     (RW)
    uint8_t undervoltage_trigger;        // volts    (RW)
    uint8_t overvoltage_trigger;         // volts    (RW)
    uint8_t overcurrent_trigger;         // amps     (RW)
    uint8_t temp_trigger;                // deg C    (RW)
    uint8_t stall_count_max;             // count    (RW)
    char reserved6[3];
    uint32_t undervoltage_err_cnt;       // count    (R)
    uint32_t overvoltage_err_cnt;        // count    (R)
    uint32_t overcurrent_err_cnt;        // count    (R)
    uint32_t temp_err_cnt;               // count    (R)
    uint32_t stall_err_cnt;              // count     (R)

    char reserved7[24];
    /*@}*/

    /*@{*/
    /** @name comms parameters
    */  
    uint32_t comms_sync1_err_cnt;          // count (R)
    uint32_t comms_sync2_err_cnt;          // count (R)
    uint32_t comms_headerxsum_err_cnt;     // count (R)
    uint32_t comms_overrun_err_cnt;        // count (R)
    uint32_t comms_payloadxsum_err_cnt;    // count (R)
    uint16_t comms_err_flag;
    uint16_t save_settings;                // code (W)
    /*@}*/
    
    /*@{*/
    /** @name PROTOCOL STANDARD REGISTERS **/
    /* Address: 0xF0 */
    uint32_t  custom_command;       //  (W)  Special Register
    uint32_t  FACTORY_SERVICE_DATA; //  (R)  Device specific service data
    uint16_t  CONFIG_DATA_SIZE;     //  (R)
    uint8_t   CONFIG_DATA;          //  (R)  Special Register
    uint8_t   FIRMWARE_VERSION;     //  (R)  Special Register
    uint8_t   NODE_ID;              //  (RW) Special Register
    uint8_t   GROUP_ID;             //  (RW) Special Register
    uint16_t  UTILITY;              //  (W)  Special Register
 }  CSR_Motor_Controller; 

#ifdef __cplusplus
}
#endif

#endif
