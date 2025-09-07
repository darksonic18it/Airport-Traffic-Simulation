#ifndef RUNWAYMANAGER_H
#define RUNWAYMANAGER_H

#include <iostream>
#include <queue>
#include <deque>
#include <string>
#include <fstream>
using namespace std;

struct Airplane {
    string flight;
    string status;
    Airplane(string f, string s) : flight(f), status(s) {}
};

class RunwayManager {
private:
    queue<Airplane> landingQueue;
    deque<Airplane> takeoffDeque;
    ofstream logFile;

    void logEvent(const string& event);

public:
    RunwayManager();
    ~RunwayManager();

    void addArrival(const string& flight);
    void addDeparture(const string& flight);
    void serve();
    void serveAll();
    void priorityTakeoff(const string& flight);
    void displayStatus();
};

#endif
