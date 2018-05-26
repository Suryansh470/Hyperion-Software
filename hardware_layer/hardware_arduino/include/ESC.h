#ifndef ESC_h
#define ESC_h

// in order to incorporate the changes of the beta releases
#if defined(ARDUINO) && (ARDUINO >= 100)
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

#include <Servo.h>                // Including the Servo library
#define calib_delay_ 7000    // Calibration delay (milisecond)

class ESC
{
    public:
        //constructor to initialise the ESC
        ESC(byte ESC_pin, int maxReverse, int maxForward, int armVal);
    
        //function to calibrate
        void calibrate();
    
        //function to arm the ESC to accept the input signals
        void arm(void);
    
        //function to control the speed of ESC
        void speed(int ESC_val);
    
    private:
        byte ESCPin_;    // Output pin for ESC
    
        int maxRev_;     // contains the value of max reverse value
        int maxFor_;     // contains the value of max forward value
        int valArm_;     // contains the arming value of an ESC
        Servo ESC_;      // create servo object to control an ESC
};

#endif