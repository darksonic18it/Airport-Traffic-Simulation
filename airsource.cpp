#include "Airport.h"

Airport::Airport() {
    logFile.open("airport_log.txt", ios::app);
    if (!logFile) {
        cerr << "Error opening log file!" << endl;
    }
}

Airport::~Airport() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Airport::logEvent(const string& event) {
    if (logFile.is_open()) {
        logFile << event << endl;
    }
}

void Airport::addArrival(string flight) {
    Airplane plane(flight, "Arrived");
    arrivals.push(plane);
    cout << "Arrival added: " << flight << endl;
    logEvent("Arrival added: " + flight);
}

void Airport::addDeparture(string flight) {
    Airplane plane(flight, "Ready for Takeoff");
    departures.push_back(plane);
    cout << "Departure added: " << flight << endl;
    logEvent("Departure added: " + flight);
}

void Airport::landPlanes() {
    cout << "\n--- Landing Planes ---" << endl;
    while (!arrivals.empty()) {
        Airplane plane = arrivals.front();
        arrivals.pop();
        plane.status = "Landed";
        cout << plane.flight << " has landed." << endl;
        logEvent(plane.flight + " has landed.");
    }
}

void Airport::takeoffPlanes() {
    cout << "\n--- Taking Off Planes ---" << endl;
    while (!departures.empty()) {
        Airplane plane = departures.front();
        departures.pop_front();
        plane.status = "Took Off";
        cout << plane.flight << " has taken off." << endl;
        logEvent(plane.flight + " has taken off.");
    }
}

void Airport::displayStatus() {
    cout << "\n=== Airport Status ===" << endl;

    cout << "\nArrivals Queue:" << endl;
    if (arrivals.empty()) cout << "No arriving planes." << endl;
    else {
        queue<Airplane> temp = arrivals; // copy to display
        while (!temp.empty()) {
            Airplane plane = temp.front();
            cout << plane.flight << " - Status: " << plane.status << endl;
            temp.pop();
        }
    }

    cout << "\nDepartures Queue:" << endl;
    if (departures.empty()) cout << "No departing planes." << endl;
    else {
        deque<Airplane> temp = departures; // copy to display
        while (!temp.empty()) {
            Airplane plane = temp.front();
            cout << plane.flight << " - Status: " << plane.status << endl;
            temp.pop_front();
        }
    }
}
