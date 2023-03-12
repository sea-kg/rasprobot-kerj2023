#ifndef GPIOPIN_H
#define GPIOPIN_H

// #include "icmdhandler.h"
#include <string>
#include <icontrolserver.h>

class GpioPin {

    public:
        GpioPin(int n);
        ~GpioPin();

        void setValue(int value);
        
        bool hasError();

    private:
        std::string TAG;
        bool m_bHasError;
        int m_nGpioPinNumber;
        void unexportPin();
        void exportPin();
        void directionOutPin();
};

#endif // GPIOPIN_H