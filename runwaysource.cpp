#include "runwaymanager.h"

// Constructor
RunwayManager::RunwayManager() {
    logFile.open("airport_log.txt", ios::app); //open file in append mode
    if (!logFile) cerr << "Error opening log file!" << endl; // error checking
}

// Destructor
RunwayManager::~RunwayManager() { // close file if open
    if (logFile.is_open()) logFile.close();
}

// Log an event to the file
void RunwayManager::logEvent(const string& event) { // log event to file
    if (logFile.is_open()) logFile << event << endl;
}

// Add an arriving plane to the landing queue
void RunwayManager::addArrival(const string& flight) { // add to landing queue
    Airplane plane(flight, "Waiting to Land"); // create airplane object
    landingQueue.push(plane); // add to landing queue
    cout << "Plane " << flight << " requests landing. Added to Landing Queue." << endl;
    logEvent("Landing queued: " + flight); // record event
}

// Add a departing plane to the back of the takeoff deque
void RunwayManager::addDeparture(const string& flight) { // add to takeoff deque
    Airplane plane(flight, "Waiting to Takeoff"); // create airplane object
    takeoffDeque.push_back(plane); // add to back of deque
    cout << "Plane " << flight << " requests takeoff. Added to Takeoff Deque (rear)." << endl;
    logEvent("Takeoff queued: " + flight); // record event
}

// Serve the next plane, prioritizing landing over takeoff
void RunwayManager::serve() { 
    if (!landingQueue.empty()) { // if landing queue not empty  
        Airplane plane = landingQueue.front(); // gets front plane
        landingQueue.pop(); // pops it from queue
        plane.status = "Landing"; // change status
        cout << "Now serving " << plane.flight << " from Landing Queue." << endl; // display
        logEvent(plane.flight + " is Landing"); // log event
    }
    else if (!takeoffDeque.empty()) { // if landing queue empty but takeoff deque not empty
        Airplane plane = takeoffDeque.front(); // gets front plane
        takeoffDeque.pop_front(); // pops it from deque
        plane.status = "Taking Off"; // change status
        cout << "Now serving " << plane.flight << " from Takeoff Deque." << endl; // display
        logEvent(plane.flight + " is Taking Off"); // log event
    }
    else {
        cout << "No planes waiting for runway." << endl; // if both queues empty
    }
    
    displayStatus(); // Show queues after each serve
}

// Serve all planes until both queues are empty
void RunwayManager::serveAll() { // optional function to serve all planes
    while (!landingQueue.empty() || !takeoffDeque.empty()) { // if both queues not empty
        serve(); // serve next plane
    }
}

void RunwayManager::priorityTakeoff(const string& flight) {
    for (size_t i = 0; i < takeoffDeque.size(); ++i) { // loop through deque
        if (takeoffDeque[i].flight == flight) { // copy plane if found in deque
            Airplane plane = takeoffDeque[i]; // copy plane
            takeoffDeque.erase(takeoffDeque.begin() + i); // remove from current position
            takeoffDeque.push_front(plane); //move to front
            cout << "Plane " << flight << " prioritized for takeoff. Moved to front of Takeoff Deque." << endl;
            logEvent(flight + " prioritized for Takeoff"); // log event
            return; // exit function
        }
    }
    cout << "Plane " << flight << " not found in Takeoff Deque." << endl; // error if not found
}

// Display the current status of both queues
void RunwayManager::displayStatus() {
    cout << "\nLanding Queue: "; // display landing queue
    if (landingQueue.empty()) cout << "[]"; // if landing queue is empty prints []
    else {
        queue<Airplane> temp = landingQueue; // temporary copy for display
        cout << "["; 
        while (!temp.empty()) { // loops through queue if not empty
            cout << temp.front().flight; // gets front flight
            temp.pop(); // then pops it
            if (!temp.empty()) cout << ", "; // if queue not empty adds comma
        }
        cout << "]";
    }

    cout << " | Takeoff Deque: "; // display takeoff deque
    if (takeoffDeque.empty()) cout << "[]"; // same as above if empty print []
    else {
        cout << "[";
        for (size_t i = 0; i < takeoffDeque.size(); ++i) { // loops through deque
            cout << takeoffDeque[i].flight; // gets flight at index i
            if (i != takeoffDeque.size() - 1) cout << ", "; // if flight is not last adds comma
        }
        cout << "]"; // closes bracket
    }
    cout << "\n-----------------------------\n";
}
