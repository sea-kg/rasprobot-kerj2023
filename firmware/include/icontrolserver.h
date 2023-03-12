#ifndef ICONTROLSERVER_H
#define ICONTROLSERVER_H


#include "isettings.h"

class IControlServer {
	public:
		virtual ISettings * settings() = 0;
		virtual void turnleft() = 0;
		virtual void turnright() = 0;
		virtual void forward() = 0;
		virtual void backward() = 0;
		virtual void stop() = 0;
		virtual void comb_up() = 0;
		virtual void comb_down() = 0;
		virtual void stop_auto() = 0;
		virtual void send_auto_stopped() = 0;
};

#endif // INTERFACES_ICONTROLSERVER_H
