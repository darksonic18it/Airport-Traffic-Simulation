#ifndef AIRPORT_H_INCLUDED
#define AIRPORT_H_INCLUDED

#include <iostream>
#include <queue>
#include <deque>
#include <fstream>
#include <string>

using namespace std;

// Airplane structure
struct Airplane {
    string flight;
    string status; // Arrived, Landed, Ready for Takeoff, Took Off

    Airplane(string f, string s) : flight(f), status(s) {}
};

class Airport {
private:
    queue<Airplane> arrivals;   // Planes waiting to land
    deque<Airplane> departures; // Planes waiting to take off
    ofstream logFile;

    void logEvent(const string& event);

public:
    Airport();
    ~Airport();

    void addArrival(string flight);
    void addDeparture(string flight);
    void displayStatus();  // now processes one plane at a time
};

#endif
