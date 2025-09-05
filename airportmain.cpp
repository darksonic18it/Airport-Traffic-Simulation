#include "Airport.h"
using namespace std;

int main() {
    Airport airport;

    // Predefined flights
    airport.addArrival("PAL123");
    airport.addDeparture("CEB456");
    airport.addArrival("AIR789");
    airport.addDeparture("QTR012");

    // Simulate traffic step by step
    airport.displayStatus(); // PAL123 lands
    airport.displayStatus(); // CEB456 takes off
    airport.displayStatus(); // AIR789 lands
    airport.displayStatus(); // QTR012 takes off
    airport.displayStatus(); // nothing left

    return 0;
}
