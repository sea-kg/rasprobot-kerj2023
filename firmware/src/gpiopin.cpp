
#include "gpiopin.h"
#include <fstream>
#include <wsjcpp_core.h>

// ---------------------------------------------------------------------
// GpioPin

GpioPin::GpioPin(int nPinNumber) {
    TAG = "GpioPin";
    m_nGpioPinNumber = nPinNumber;
    this->unexportPin();
    this->exportPin();
    this->directionOutPin();
    m_bHasError = false;
};

GpioPin::~GpioPin() {

};

void GpioPin::setValue(int nValue) {
    std::string sPin = "/sys/class/gpio/gpio" + std::to_string(m_nGpioPinNumber) + "/value";
    std::fstream fs;
    fs.open(sPin, std::fstream::out);
    if (fs.is_open()) {
        fs << std::to_string(nValue) << std::endl;
        fs.close();
    } else {
        WsjcppLog::err(TAG, "Could not open " + sPin);
    }
};

bool GpioPin::hasError() {
    return m_bHasError;
};

void GpioPin::unexportPin() {
    const std::string sUnexportPath = "/sys/class/gpio/unexport";
    std::fstream fs;
    fs.open(sUnexportPath, std::fstream::out);
    if (fs.is_open()) {
        fs << std::to_string(m_nGpioPinNumber) << std::endl;
        fs.close();
    } else {
        WsjcppLog::err(TAG, "Could not open " + sUnexportPath);
    }
};

void GpioPin::exportPin() {
    const std::string sExportPath = "/sys/class/gpio/export";
    std::fstream fs;
    fs.open(sExportPath, std::fstream::out);
    if (fs.is_open()) {
        fs << std::to_string(m_nGpioPinNumber) << std::endl;
        fs.close();
    } else {
        WsjcppLog::err(TAG, "Could not open " + sExportPath);
    }
};

void GpioPin::directionOutPin() {
    std::string sDiretionPath = "/sys/class/gpio/gpio" + std::to_string(m_nGpioPinNumber) + "/direction";
    std::fstream fs;
    fs.open(sDiretionPath, std::fstream::out);
    if (fs.is_open()) {
        fs << "out" << std::endl;
        fs.close();
    } else {
        WsjcppLog::err(TAG, "Could not open " + sDiretionPath);
    }
};

