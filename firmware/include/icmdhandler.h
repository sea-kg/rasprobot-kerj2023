#ifndef ICMDHANDLER_H
#define ICMDHANDLER_H

#include "icontrolserver.h"

class ICmdHandler {
	public:
		virtual std::string cmd() = 0;
		virtual void handle(QWebSocket *pClient, IControlServer *pControlServer, QJsonObject obj) = 0;
};

#endif // ICMDHANDLER_H
