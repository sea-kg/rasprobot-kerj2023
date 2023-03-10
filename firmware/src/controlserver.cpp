#include "controlserver.h"

// #include <QJsonDocument>
// #include <QJsonObject>
// #include <QDateTime>
// #include <QHostAddress>
// #include "cmd_handlers/create_cmd_handlers.h"
// #include <QProcess>
// #include <QFile>
#include <iostream>

// ---------------------------------------------------------------------

ControlServer::ControlServer(ISettings *pSett) {
    m_pSettings = pSett;
    // m_pWebSocketServer = new QWebSocketServer(QStringLiteral("SopovRobotics"), QWebSocketServer::NonSecureMode, this);
// 
    // if (m_pWebSocketServer->listen(QHostAddress::Any, pSett->get_port())) {
    //     std::cout << "SopovRobotics listening on port" << pSett->get_port();
    //     connect(m_pWebSocketServer, &QWebSocketServer::newConnection, this, &ControlServer::onNewConnection);
    //     connect(m_pWebSocketServer, &QWebSocketServer::closed, this, &ControlServer::closed);
    //     create_cmd_handlers(m_mapCmdHandlers);
    //     m_bHasError = false;
    // }else{
    //     std::cout << "[ERROR] SopovRobotics could not listening on port" << pSett->get_port();
    //     m_bHasError = true;
    // }

    unexportPin(m_pSettings->get_drivers_pin_A1());
    unexportPin(m_pSettings->get_drivers_pin_A2());
    unexportPin(m_pSettings->get_drivers_pin_B1());
    unexportPin(m_pSettings->get_drivers_pin_B2());

    exportPin(m_pSettings->get_drivers_pin_A1());
    exportPin(m_pSettings->get_drivers_pin_A2());
    exportPin(m_pSettings->get_drivers_pin_B1());
    exportPin(m_pSettings->get_drivers_pin_B2());

    directionOutPin(m_pSettings->get_drivers_pin_A1());
    directionOutPin(m_pSettings->get_drivers_pin_A2());
    directionOutPin(m_pSettings->get_drivers_pin_B1());
    directionOutPin(m_pSettings->get_drivers_pin_B2());
    
    // comb
    unexportPin(m_pSettings->get_servo_pin_comb());
    exportPin(m_pSettings->get_servo_pin_comb());
    directionOutPin(m_pSettings->get_servo_pin_comb());
    
    // connect(this, &ControlServer::_sendAutoStoppedSignal, this, &ControlServer::_sendAutoStopped);
}

// ---------------------------------------------------------------------

ControlServer::~ControlServer() {
    // m_pWebSocketServer->close();
    // qDeleteAll(m_clients.begin(), m_clients.end());
}

// ---------------------------------------------------------------------

bool ControlServer::hasError(){
    return m_bHasError;
}

// ---------------------------------------------------------------------

// void ControlServer::onNewConnection()
// {
//     QWebSocket *pSocket = m_pWebSocketServer->nextPendingConnection();
// 
//     
//     std::cout << "NewConnection " << pSocket->peerAddress().toString().toStdString() << " " << pSocket->peerPort();
// 
//     connect(pSocket, &QWebSocket::textMessageReceived, this, &ControlServer::processTextMessage);
//     connect(pSocket, &QWebSocket::binaryMessageReceived, this, &ControlServer::processBinaryMessage);
//     connect(pSocket, &QWebSocket::disconnected, this, &ControlServer::socketDisconnected);
// 
//     m_clients << pSocket;
//     
//     QJsonObject obj;
//     obj["msg"] = "info";
//     obj["version"] = "v20170528";
//     obj["firmware"] = 1;
//     obj["name"] = "ForKeva";
//     // TODO 
// 
//     QJsonObject capabilities;
//     capabilities["turnleft"] = true;
//     capabilities["turnright"] = true;
//     capabilities["forward"] = true;
//     capabilities["backward"] = true;
//     capabilities["autocontrol"] = false;
//     capabilities["light"] = false;
//     obj["capabilities"] = capabilities;
//     this->sendMessage(pSocket, obj);
// }

ISettings * ControlServer::settings(){
    return m_pSettings;
}

void ControlServer::turnleft(){

    setPinValue(
        m_pSettings->get_drivers_pin_A1(),
        m_pSettings->get_drivers_turnleft_A1()
    );
    setPinValue(
        m_pSettings->get_drivers_pin_A2(),
        m_pSettings->get_drivers_turnleft_A2()
    );
    setPinValue(
        m_pSettings->get_drivers_pin_B1(),
        m_pSettings->get_drivers_turnleft_B1()
    );
    setPinValue(
        m_pSettings->get_drivers_pin_B2(),
        m_pSettings->get_drivers_turnleft_B2()
    );
}

// ---------------------------------------------------------------------

void ControlServer::turnright(){
    setPinValue(
        m_pSettings->get_drivers_pin_A1(),
        m_pSettings->get_drivers_turnright_A1()
    );
    setPinValue(
        m_pSettings->get_drivers_pin_A2(),
        m_pSettings->get_drivers_turnright_A2()
    );
    setPinValue(
        m_pSettings->get_drivers_pin_B1(),
        m_pSettings->get_drivers_turnright_B1()
    );
    setPinValue(
        m_pSettings->get_drivers_pin_B2(),
        m_pSettings->get_drivers_turnright_B2()
    );
}

// ---------------------------------------------------------------------

void ControlServer::forward(){
    setPinValue(
        m_pSettings->get_drivers_pin_A1(),
        m_pSettings->get_drivers_forward_A1()
    );
    setPinValue(
        m_pSettings->get_drivers_pin_A2(),
        m_pSettings->get_drivers_forward_A2()
    );
    setPinValue(
        m_pSettings->get_drivers_pin_B1(),
        m_pSettings->get_drivers_forward_B1()
    );
    setPinValue(
        m_pSettings->get_drivers_pin_B2(),
        m_pSettings->get_drivers_forward_B2()
    );
}

// ---------------------------------------------------------------------

void ControlServer::backward(){
    setPinValue(
        m_pSettings->get_drivers_pin_A1(),
        m_pSettings->get_drivers_backward_A1()
    );
    setPinValue(
        m_pSettings->get_drivers_pin_A2(),
        m_pSettings->get_drivers_backward_A2()
    );
    setPinValue(
        m_pSettings->get_drivers_pin_B1(),
        m_pSettings->get_drivers_backward_B1()
    );
    setPinValue(
        m_pSettings->get_drivers_pin_B2(),
        m_pSettings->get_drivers_backward_B2()
    );
}

// ---------------------------------------------------------------------

void ControlServer::stop(){
    setPinValue(
        m_pSettings->get_drivers_pin_A1(),
        0
    );
    setPinValue(
        m_pSettings->get_drivers_pin_A2(),
        0
    );
    setPinValue(
        m_pSettings->get_drivers_pin_B1(),
        0
    );
    setPinValue(
        m_pSettings->get_drivers_pin_B2(),
        0
    );
}

// ---------------------------------------------------------------------

void ControlServer::comb_up(){
    // this->pwmPin(
    //     m_pSettings->get_servo_pin_comb(),
    //     m_pSettings->get_servo_pin_comb_value_up()
    // );
}

// ---------------------------------------------------------------------

void ControlServer::comb_down(){
    // this->pwmPin(
    //     m_pSettings->get_servo_pin_comb(),
    //     m_pSettings->get_servo_pin_comb_value_down()
    // );
}

void ControlServer::unexportPin(int pin){
    // QFile file("/sys/class/gpio/unexport");
    // if (file.open(QIODevice::WriteOnly)){
    //     QTextStream stream( &file );
    //     stream << std::to_string(pin) << std::endl;
    // }else{
    //     std::cout << "Could not open gpio" + std::to_string(pin) + "/unexport";
    // }
}

// ---------------------------------------------------------------------

void ControlServer::exportPin(int pin){
    // QFile file("/sys/class/gpio/export");
    // if (file.open(QIODevice::WriteOnly)){
    //     QTextStream stream( &file );
    //     stream << std::to_string(pin) << std::endl;
    // } else {
    //     std::cout << "Could not open gpio" + std::to_string(pin) + "/export";
    // }
}

// ---------------------------------------------------------------------

void ControlServer::setPinValue(int pin, int value){
    // QFile file("/sys/class/gpio/gpio" + std::to_string(pin) + "/value");
    // if (file.open(QIODevice::WriteOnly)){
    //     std::cout << "Set value " << value << " to " << pin;
    //     QTextStream stream( &file );
    //     stream << std::to_string(value) << std::endl;
    // } else {
    //     std::cout << "Could not open gpio" + std::to_string(pin) + "/value";
    // }
}

// ---------------------------------------------------------------------


void ControlServer::directionOutPin(int pin){
    // QFile file("/sys/class/gpio/gpio" + std::to_string(pin) + "/direction");
    // if (file.open(QIODevice::WriteOnly)){
    //     QTextStream stream( &file );
    //     stream << "out" << std::endl;
    // }else{
    //     std::cout << "Could not open gpio" + std::to_string(pin) + "/direction";
    // }
}

// void ControlServer::pwmPin(int pin, int width_signal_usec){
//     QString gpio_path = "/sys/class/gpio/gpio" + std::to_string(pin) + "/value";
//     QFile file(gpio_path);
//     if (file.open(QIODevice::WriteOnly)){
//         std::cout << "PWM on pin " << pin << " started for " << width_signal_usec;
//         QTextStream stream( &file );
//         int counter = 0;
//         QString one = std::to_string(1);
//         QString zero = std::to_string(0);
//         QElapsedTimer timer;
//         qint64 elapsed;
//         while(true){
//             std::cout << "1";
//             timer.restart();
//             stream << one << std::endl;
//             elapsed = timer.nsecsElapsed()/1000;
//             QThread::usleep(width_signal_usec);
//             stream << zero << std::endl;
//             elapsed = timer.nsecsElapsed()/1000;
//             QThread::usleep(20000 - elapsed);
//             counter++;
//             if(counter > 21){
//                 break;
//                 return;
//             }
//         }
//         std::cout << "PWM on pin " << pin << " finished\n";
//     }else{
//         std::cout << "Could not open " << gpio_path << " for pwm\n";
//     }
// }
