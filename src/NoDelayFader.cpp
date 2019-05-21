/*
 * NoDelayfader.h
 *
 * Brett Crawford <> 16-05-19
 *
 */

#include "Arduino.h"
#include "NoDelayFader.h"

NoDelayFader::NoDelayFader(uint8_t virtualMode, uint8_t pwmPin, uint16_t minValue, uint16_t maxValue)
{
    _virtual = virtualMode;
    _pin = pwmPin;
    _minValue = minValue;
    _maxValue = maxValue;
}

void NoDelayFader::begin()
{
    if (!_pin) return;
    pinMode(_pin, OUTPUT);
}

void NoDelayFader::setFader(uint16_t valueTarget, unsigned int duration)
{
    _valueTarget = valueTarget;
    _duration = duration;
    _timeTarget = millis() + _duration;
    _timeLast = millis();
    _faderSet = true;
    _run = true;
}

void NoDelayFader::setValue(uint16_t valueToSet)
{
    _valueCurrent = valueToSet;
    if (!_virtual) analogWrite(_pin, _valueCurrent);
}

void  NoDelayFader::update()
{
    if (_run)
    {
        if (!_faderSet) return;

        _timeNow = millis();

        int newValue = constrain(map(_timeNow, _timeLast, _timeTarget, _valueCurrent, _valueTarget), _minValue, _maxValue);

        _valueCurrent = newValue;
            
        if (_valueCurrent == _valueTarget) this->stop();

        if (!_virtual) analogWrite(_pin, _valueCurrent);

        _timeLast = _timeNow;
    }
}

void NoDelayFader::stop()
{
    _run = false;
    _faderSet = false;
}

uint16_t NoDelayFader::currentValue()
{
    return _valueCurrent;
}

bool NoDelayFader::running()
{
    return _run;
}