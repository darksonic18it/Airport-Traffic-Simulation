#include "runwaymanager.h"

// Constructor
RunwayManager::RunwayManager() {
    logFile.open("airport_log.txt", ios::app);
    if (!logFile) cerr << "Error opening log file!" << endl;
}

// Destructor
RunwayManager::~RunwayManager() {
    if (logFile.is_open()) logFile.close();
}

// Log an event to the file
void RunwayManager::logEvent(const string& event) {
    if (logFile.is_open()) logFile << event << endl;
}

// Add an arriving plane to the landing queue
void RunwayManager::addArrival(const string& flight) {
    Airplane plane(flight, "Waiting to Land");
    landingQueue.push(plane);
    cout << "Plane " << flight << " requests landing. Added to Landing Queue." << endl;
    logEvent("Landing queued: " + flight);
}

// Add a departing plane to the back of the takeoff deque
void RunwayManager::addDeparture(const string& flight) {
    Airplane plane(flight, "Waiting to Takeoff");
    takeoffDeque.push_back(plane);
    cout << "Plane " << flight << " requests takeoff. Added to Takeoff Deque (rear)." << endl;
    logEvent("Takeoff queued: " + flight);
}

// Serve the next plane, prioritizing landing over takeoff
void RunwayManager::serve() {
    if (!landingQueue.empty()) {
        Airplane plane = landingQueue.front();
        landingQueue.pop();
        plane.status = "Landing";
        cout << "Now serving " << plane.flight << " from Landing Queue." << endl;
        logEvent(plane.flight + " is Landing");
    }
    else if (!takeoffDeque.empty()) {
        Airplane plane = takeoffDeque.front();
        takeoffDeque.pop_front();
        plane.status = "Taking Off";
        cout << "Now serving " << plane.flight << " from Takeoff Deque." << endl;
        logEvent(plane.flight + " is Taking Off");
    }
    else {
        cout << "No planes waiting for runway." << endl;
    }
    
    displayStatus(); // Show queues after each serve
}

// Serve all planes until both queues are empty
void RunwayManager::serveAll() {
    while (!landingQueue.empty() || !takeoffDeque.empty()) {
        serve();
    }
}

// Give a specific plane priority for takeoff
void RunwayManager::priorityTakeoff(const string& flight) {
    for (auto it = takeoffDeque.begin(); it != takeoffDeque.end(); ++it) {
        if (it->flight == flight) {
            Airplane plane = *it;
            takeoffDeque.erase(it);
            takeoffDeque.push_front(plane);
            cout << "Plane " << flight << " prioritized for takeoff. Moved to front of Takeoff Deque." << endl;
            logEvent(flight + " prioritized for Takeoff");
            return;
        }
    }
    cout << "Plane " << flight << " not found in Takeoff Deque." << endl;
}

// Display the current status of both queues
void RunwayManager::displayStatus() {
    cout << "\nLanding Queue: ";
    if (landingQueue.empty()) cout << "[]";
    else {
        queue<Airplane> temp = landingQueue;
        cout << "[";
        while (!temp.empty()) {
            cout << temp.front().flight;
            temp.pop();
            if (!temp.empty()) cout << ", ";
        }
        cout << "]";
    }

    cout << " | Takeoff Deque: ";
    if (takeoffDeque.empty()) cout << "[]";
    else {
        cout << "[";
        for (size_t i = 0; i < takeoffDeque.size(); ++i) {
            cout << takeoffDeque[i].flight;
            if (i != takeoffDeque.size() - 1) cout << ", ";
        }
        cout << "]";
    }
    cout << "\n-----------------------------\n";
}
