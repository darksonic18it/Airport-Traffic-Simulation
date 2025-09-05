#include "Airport.h"
using namespace std;

int main() {
    Airport airport;

    airport.addArrival("PAL123");
    airport.addDeparture("CEB456");
    airport.addArrival("AIR789");
  
    airport.displayStatus();

    airport.landPlanes();
    airport.takeoffPlanes();

    airport.displayStatus();

    return 0;
}
