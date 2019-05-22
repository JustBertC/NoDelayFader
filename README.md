# NoDelayFader for Arduino

NoDelayFader is a library for Arduino based boards that allows a GPIO or variable to fade between values without using a for loop or the delay function (which blocks the code from running temporarily).

## Install
- Download a copy of this repo by clicking "**Clone or download**" -> "**Download ZIP**"

- Follow the instructions [here.](https://www.arduino.cc/en/Guide/Libraries)

## Usage

### 1. Inlcude the NoDelayFader header file.
```cpp
#include "NoDelayFader.h"
```

### 2. Declare an instance of the NoDelayFader

*You can either use a variable or GPIO pin*

- GPIO - *(Where 2 is the pin number)*:
```cpp
NoDelayFader myFader(GPIO, 2);
```
- Variable:
```cpp
NoDelayFader myFader(VIRTUAL);
```

### 3. Call begin in void setup() *(you only need this if using a GPIO pin)*
```cpp
void setup() {
    myFader.begin();
}
```

### 4. Set up the fade amount and duration *(fade to 255 over 3 seconds)*
```cpp
myFader.setFader(255, 3000);
```

### 5. Finally call update() in void loop() or other timer function
```cpp
myFader.update();
```

## Setting a start value
Set a start value by calling setValue()
```cpp
myFader.setValue(23);
```

## Examples
Check out the examples in the **File -> Examples -> NoDelayFader** menu.