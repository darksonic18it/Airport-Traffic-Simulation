#ifndef AIRPORT_H_INCLUDED
#define AIRPORT_H_INCLUDED

#include <iostream>
#include <queue> // queue for arrivals
#include <deque> // deque for departures
#include <fstream> // for file management
#include <string>

using namespace std;

// Airplane structure
struct Airplane { 
    string flight; // flight code
    string status; // Arrived, Landed, Ready for Takeoff, Took Off

    Airplane(string f, string s) : flight(f), status(s) {} // constructor
};

class Airport {
private:
    queue<Airplane> arrivals;   // Planes waiting to land
    deque<Airplane> departures; // Planes waiting to take off
    ofstream logFile; // file to record

    void logEvent(const string& event); // to add text to logfile

public:
    Airport(); // cosntructor
    ~Airport(); // destructor

    void addArrival(string flight); // add arrivals
    void addDeparture(string flight); // add departures
    void displayStatus();  // now processes one plane at a time
};

#endif

