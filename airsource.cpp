#include "Airport.h"

// Constructor
Airport::Airport() {
    logFile.open("airport_log.txt", ios::app); // open and add to log file
    if (!logFile) { // checks error
        cerr << "Error opening log file!" << endl;
    }
}

// Destructor
Airport::~Airport() {
    if (logFile.is_open()) { // if file is opened
        logFile.close(); // then close it bro
    }
}

// Log events
void Airport::logEvent(const string& event) {
    if (logFile.is_open()) { // if file is open
        logFile << event << endl; // adds event
    }
}

// Add an arriving plane
void Airport::addArrival(string flight) { 
    Airplane plane(flight, "Arrived"); // adds plane to status arrived
    arrivals.push(plane); // add plane to arrivals
    cout << "Arrival queued: " << flight << endl; // cout plane
    logEvent("Arrival queued: " + flight); // put the plane to logfile
}

// Add a departing plane
void Airport::addDeparture(string flight) { 
    Airplane plane(flight, "Ready for Takeoff"); // adds plane to status RFT
    departures.push_back(plane); // push back of deque
    cout << "Departure queued: " << flight << endl; // cout plane
    logEvent("Departure queued: " + flight); // writes to logfile
}

// Display airport status & process runway like traffic
void Airport::displayStatus() { // display function
    cout << "\n=== Airport Status ===" << endl; 
 
    // Process runway traffic automatically
      if (!arrivals.empty()) { // if arrivals not empty
        Airplane plane = arrivals.front(); // gets the front
        arrivals.pop(); // then remove from arrivals queue

        // Step 1: Arriving
        plane.status = "Arriving";
        cout << plane.flight << " is " << plane.status << "..." << endl;
        logEvent(plane.flight + " is Arriving...");

        // Step 2: Landed
        plane.status = "Landed"; // updated status obvs
        cout << plane.flight << " has " << plane.status << "." << endl; // print
        logEvent(plane.flight + " has Landed."); // puts to logfile
    }
    else if (!departures.empty()) { // if departurs not empty
        Airplane plane = departures.front(); // gets the front
        departures.pop_front(); // then remove from deque

        // Step 1: Departing 
        plane.status = "Departing"; // departures status
        cout << plane.flight << " is " << plane.status << "..." << endl; // print departure status
        logEvent(plane.flight + " is Departing..."); // writes to file

        // Step 2: Took Off
        plane.status = "Took Off"; 
        cout << plane.flight << " has " << plane.status << "." << endl;
        logEvent(plane.flight + " has Took Off.");
    }
    else {
        cout << "No planes waiting for runway." << endl;
    }

    // Show arrivals queue
    cout << "\nArrivals Queue:" << endl;
    if (arrivals.empty()) cout << "No arriving planes." << endl; // if no arriving planes 
    else {
        queue<Airplane> temp = arrivals; 
        while (!temp.empty()) {
            cout << temp.front().flight << " - Status: " << temp.front().status << endl;
            temp.pop();
        }
    }

    // Show departures queue
    cout << "\nDepartures Queue:" << endl;
    if (departures.empty()) cout << "No departing planes." << endl;
    else {
        deque<Airplane> temp = departures;
        while (!temp.empty()) {
            cout << temp.front().flight << " - Status: " << temp.front().status << endl;
            temp.pop_front();
        }
    }
}

