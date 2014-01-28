#ifndef XBeeStrategy_h
#define XBeeStrategy_h
#include <ControllerStrategy.h>
#include <XBee.h>

class XBeeStrategy: public ControllerStrategy{

	public:
		XBeeStrategy(Sputnik _sputnik);
		void run();
	protected:
	
	private:

};

#endif
