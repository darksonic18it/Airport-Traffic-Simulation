#ifndef AIRPORT_H_INCLUDED
#define AIRPORT_H_INCLUDED

#include <iostream>
#include <queue>
#include <deque>
#include <fstream>
#include <string>

using namespace std;

// Airplane structure for storing details
struct Airplane {
    string flight;
    string status; // "Arrived", "Ready for Takeoff", etc.

    Airplane(string f, string s) : flight(f), status(s) {}
};

class Airport {
private:
    queue<Airplane> arrivals;   // FIFO for arriving planes
    deque<Airplane> departures; // Deque for flexible takeoff scheduling
    ofstream logFile;

    void logEvent(const string& event);

public:
    Airport();
    ~Airport();

    void addArrival(string flight);
    void addDeparture(string flight);
    void landPlanes();
    void takeoffPlanes();
    void displayStatus();
};

#endif
