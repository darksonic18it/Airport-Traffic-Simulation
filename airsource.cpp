#include "Airport.h"

// Constructor
Airport::Airport() {
    logFile.open("airport_log.txt", ios::app);
    if (!logFile) {
        cerr << "Error opening log file!" << endl;
    }
}

// Destructor
Airport::~Airport() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

// Log events
void Airport::logEvent(const string& event) {
    if (logFile.is_open()) {
        logFile << event << endl;
    }
}

// Add an arriving plane
void Airport::addArrival(string flight) {
    Airplane plane(flight, "Arrived");
    arrivals.push(plane);
    cout << "Arrival queued: " << flight << endl;
    logEvent("Arrival queued: " + flight);
}

// Add a departing plane
void Airport::addDeparture(string flight) {
    Airplane plane(flight, "Ready for Takeoff");
    departures.push_back(plane);
    cout << "Departure queued: " << flight << endl;
    logEvent("Departure queued: " + flight);
}

// Display airport status & process runway like traffic
void Airport::displayStatus() {
    cout << "\n=== Airport Status ===" << endl;

    // Process runway traffic automatically
    if (!arrivals.empty()) {
        Airplane plane = arrivals.front();
        arrivals.pop();

        // Step 1: Arriving
        plane.status = "Arriving";
        cout << plane.flight << " is " << plane.status << "..." << endl;
        logEvent(plane.flight + " is Arriving...");

        // Step 2: Landed
        plane.status = "Landed";
        cout << plane.flight << " has " << plane.status << "." << endl;
        logEvent(plane.flight + " has Landed.");
    }
    else if (!departures.empty()) {
        Airplane plane = departures.front();
        departures.pop_front();

        // Step 1: Departing
        plane.status = "Departing";
        cout << plane.flight << " is " << plane.status << "..." << endl;
        logEvent(plane.flight + " is Departing...");

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
    if (arrivals.empty()) cout << "No arriving planes." << endl;
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
