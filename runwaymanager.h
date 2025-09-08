#ifndef RUNWAYMANAGER_H
#define RUNWAYMANAGER_H

#include <iostream>
#include <queue> // for landing queue
#include <deque> // for takeoff deque
#include <string> // for string handling
#include <fstream> // for file logging
using namespace std;

struct Airplane {
    string flight; // flight identifier
    string status; // status (e.g., "Waiting to Land", "Landing", "Waiting to Takeoff", "Taking Off")
    Airplane(string f, string s) : flight(f), status(s) {} // constructor
};

class RunwayManager {
private:
    queue<Airplane> landingQueue; // landing queue
    deque<Airplane> takeoffDeque; // takeoff deque
    ofstream logFile; // log file stream

    void logEvent(const string& event); // log events to file

public:
    RunwayManager(); // constructor
    ~RunwayManager(); // destructor

    void addArrival(const string& flight); // add arriving plane
    void addDeparture(const string& flight); // add departing plane
    void serve(); // serve next plane
    void serveAll(); // serve all planes
    void priorityTakeoff(const string& flight); // priority takeoff
    void displayStatus(); // display current status
};

#endif
