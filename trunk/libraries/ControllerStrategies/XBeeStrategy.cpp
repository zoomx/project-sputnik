#include <XBeeStrategy.h>
XBee xbee = XBee();

XBeeStrategy::XBeeStrategy(Sputnik _sputnik) : ControllerStrategy( _sputnik){
	xbee.begin(9600);
	Serial.println( "XbeeStrategy Initialized");
}

void XBeeStrategy::run(){


	xbee.readPacket();

	if (xbee.getResponse().isAvailable()) {
		// got something

		if (xbee.getResponse().getApiId() == RX_16_RESPONSE) {
			// got a rx packet
			Rx16Response rx16 = Rx16Response();
			xbee.getResponse().getRx16Response(rx16);

			Serial.println( "**** Incoming transmission ***");
			char destination = rx16.getData(0);
			if(destination == 'a'){

				Serial.println( "Triggering us...");
				char mode = rx16.getData(1);
				if(mode == 'm'){
					Serial.println( "Changing direction");
					int direction = rx16.getData(2);
					int on = rx16.getData(3);
					switch(direction){
						case  'w':
							sputnik.stopMoving();
							sputnik.forward();
							break;
						case  'a':
							sputnik.stopMoving();
							sputnik.turn(1000, 0);
							break;
						case  's':
							sputnik.stopMoving();
							sputnik.backward();
							break;
						case  'd':
							sputnik.stopMoving();
							sputnik.turn(1000, 1);
							break;
						default:
							break;
					}

				}
			}
		}
	}
}
