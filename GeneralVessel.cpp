#include <algorithm>
#include "GeneralVessel.h"

bool GeneralVessel::burnFuel(real_t df) {
	//return true;//
	fuel -= df;
	if (fuel <= 0) {
		fuel = 0;
		return false;
	} else {
		return true;
	}
}

void GeneralVessel::accelerateByUpdate(real_t df) {
	df *= getMaxAcc();
	if (burnFuel(df))
		BasicVessel::accelerateByUpdate(df);
}
