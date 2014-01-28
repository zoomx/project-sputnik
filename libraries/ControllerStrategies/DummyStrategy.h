#ifndef DummyStrategy_h
#define DummyStrategy_h
#include <ControllerStrategy.h>
class DummyStrategy: public ControllerStrategy{

	public:
		DummyStrategy(Sputnik _sputnik);
		void run();
	protected:
	
	private:

};

#endif
