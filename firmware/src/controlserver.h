#ifndef CONTROLSERVER_H
#define CONTROLSERVER_H

// #include "icmdhandler.h"
#include <icontrolserver.h>

class ControlServer : public IControlServer {

    public:
        ControlServer(ISettings *pSett);
        ~ControlServer();

        virtual ISettings * settings();
        virtual void turnleft();
        virtual void turnright();
        virtual void forward();
        virtual void backward();
        virtual void stop();
        virtual void comb_up();
        virtual void comb_down();
        
        bool hasError();

    private:
        bool m_bHasError;
        void unexportPin(int pin);
        void exportPin(int pin);
        void setPinValue(int pin, int value);
        void directionOutPin(int pin);

        // QWebSocketServer *m_pWebSocketServer;
        // QList<QWebSocket *> m_clients;
        // QMap<QString, ICmdHandler *> m_mapCmdHandlers;
        
        ISettings *m_pSettings;
};

#endif // CONTROLSERVER_H
