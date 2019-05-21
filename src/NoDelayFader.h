/*
 * NoDelayfader.h
 *
 * Brett Crawford <> 16-05-19
 *
 */

#include "Arduino.h"

#ifndef NoDelayFader_h
#define NoDelayFader_h

#define GPIO 0
#define VIRTUAL 1

class NoDelayFader
{        
    public:
        NoDelayFader();
        NoDelayFader(uint8_t virtualMode=1, uint8_t pwmPin=0, uint16_t minValue=0, uint16_t maxValue=1023);

        void begin();
        void setValue(uint16_t valueToSet);
        void setFader(uint16_t valueTarget, unsigned int duration);
        void update();
        void stop();
        uint16_t currentValue();
        bool running();
        
    private:
        int _virtual;
        int _pin;
        
        uint16_t _valueCurrent;
        uint16_t _valueTarget;
        unsigned int _duration;
        bool _faderSet;
        
        uint16_t _minValue;
        uint16_t _maxValue;

        unsigned long _timeNow;
        unsigned long _timeLast;
        unsigned long _timeTarget;
        
        bool _run;
};

#endif