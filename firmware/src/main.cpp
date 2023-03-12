#include <string.h>
#include <iostream>
#include <algorithm>
#include <wsjcpp_core.h>
#include "gpiopin.h"

int main(int argc, const char* argv[]) {
    std::string TAG = "MAIN";
    std::string appName = std::string(WSJCPP_APP_NAME);
    std::string appVersion = std::string(WSJCPP_APP_VERSION);
    if (!WsjcppCore::dirExists(".logs")) {
        WsjcppCore::makeDir(".logs");
    }
    WsjcppLog::setPrefixLogFile("wsjcpp");
    WsjcppLog::setLogDirectory(".logs");
    // TODO your code here

    GpioPin pin20(20);
    GpioPin pin21(21);
    

    pin20.setValue(1);
    pin21.setValue(0);

    return 0;
}

