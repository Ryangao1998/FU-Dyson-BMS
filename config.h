/* 
 * File:   config.h
 * Author: user
 *
 * Created on February 25, 2022, 2:45 PM
 */

#ifndef CONFIG_H
#define	CONFIG_H


//Uncomment these lines while in debug mode to disable certain temperature checks for testing.
#ifdef __DEBUG  //Make sure these only work in debug mode
//#define __DEBUG_DISABLE_PIC_THERMISTOR_READ       //Uncomment for testing
//#define __DEBUG_DISABLE_PIC_ISL_INT_READ          //Uncomment for testing
#endif

#define redLED RA7
#define greenLED RB3
#define blueLED RA6

#define SDA RB1
#define SCL RB4
#define TRIS_SDA TRISB1
#define TRIS_SCL TRISB4
#define ANS_SDA ANSB1
#define ANS_SCL ANSB4

#define ISL_ADDR 0x50

/*ADC Channels, Defined in adc.h
     Discharge_Isense_AN0 =     0x0,
    Thermistor_AN1 =            0x1,
    ISL_AnalogOut_AN4 =         0x4,
    channel_Temp =              0x1D,
    channel_DAC =               0x1E,
    channel_FVR =               0x1F
 */

#define ADC_DISCHARGE_ISENSE 0x0
#define ADC_THERMISTOR 0x1
#define ADC_ISL_OUT 0x4
#define ADC_PIC_INT_TEMP 0x1D
#define ADC_PIC_DAC 0x1E
#define ADC_PIC_FVR 0x1F
#define ADC_CHRG_TRIG_DETECT 0x07
#define ADC_SV09CHECK 0x0A

const uint16_t VREF_VOLTAGE_mV = 2500;

const uint8_t MAX_CHARGE_TEMP_C = 50;           //Celsius. MAX_DISCHARGE_TEMP_C must be greater than MAX_CHARGE_TEMP_C for it to work correctly.
const uint8_t MAX_DISCHARGE_TEMP_C = 60;        //Celsius
const uint16_t MAX_DISCHARGE_CURRENT_mA = 30000;
const uint16_t MIN_DISCHARGE_CELL_VOLTAGE_mV = 3000;
const uint16_t MAX_CHARGE_CELL_VOLTAGE_mV = 4200;
const uint16_t PACK_CHARGE_NOT_COMPLETE_THRESH_mV = 4100;

const uint16_t DETECT_CHARGER_THRESH_mV = 1500;
const uint16_t DETECT_TRIGGER_THRESH_mV = 400;

const uint8_t HYSTERESIS_TEMP_C = 3;

/* Mark charge complete if a charging cycle takes less than this amount of time.
313 * 32ms = 10.016s, if it took less than 10 seconds for max cell voltage to be > 4.20v, mark charge complete */
const uint16_t CHARGE_COMPELTE_TIMEOUT = 313;   


/* Length of time to wait between charge cycles
 2188 * 32ms = 70.016 seconds*/
const uint16_t CHARGE_WAIT_TIMEOUT = 2188;

/* Length of time to wait while idle before going to sleep
  938*32ms = 30.016s */
const uint16_t IDLE_SLEEP_TIMEOUT = 938;

/* Length of time to wait while in an error state before going to sleep
 1876*32ms = 60.032s */
const uint16_t ERROR_SLEEP_TIMEOUT = 938;

/* Length of time there must be no errors before exiting error state
 94 * 32ms = 3.008s */
const uint8_t ERROR_EXIT_TIMEOUT = 94;

/* Number of times the LED error code will be presented after the fault is cleared and trigger/charger removed.
 Ensures the error code won't immediately go away once the user stops pulling the trigger.*/
const uint8_t NUM_OF_LED_CODES_AFTER_FAULT_CLEAR = 3;













#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */

