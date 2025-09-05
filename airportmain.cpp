#include "airport.h"
int main(){

  Airport airport;

  airport.addArrival("PAL123");
  airport.addDeparture("MNL234");
  airport.addDeparture("CEB456");
  airport.addArrival("AAS789");
  cout << endl;

  cout << "Initial Status:" << endl;
  airport.displayStatus();
  cout << endl;

  cout << "Traffic Control First Arrival Lands...." << endl;
  airport.landPlanes();
  airport.displayStatus();
  cout << endl;
  
  cout << "Traffic Control First Departure Takes Off...." << endl;
  airport.takeoffPlanes();
  airport.displayStatus();
  cout << endl;

  cout << "Traffic Control Next Arrival Lands...." << endl;
  airport.landPlanes();
  airport.displayStatus();
  cout << endl;

  cout << "Traffic Control Next Departure Takes Off...." << endl;
  airport.takeoffPlanes();
  cout << endl;

  cout << "Final Status:" << endl;
  airport.displayStatus();

  return 0;
}