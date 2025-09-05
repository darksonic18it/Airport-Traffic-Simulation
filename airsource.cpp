#include "airport.h"

// Queue implementation
Queue::Queue() {
    front = -1;
    back = -1;
}

bool Queue::isempty() {
    return (front == -1 || front > back);
}

bool Queue::isfull() {
    return (back == SIZE - 1);
}

void Queue::enqueue(string flight, string stat) {
    if (isfull()) {
        cout << "Queue is full" << endl;
        return;
    }
    if (front == -1) {
        front = 0; // initialize front on first insert
    }
    flights[++back] = flight;
    status[back] = stat;
}

void Queue::dequeue(string &flight, string &stat) {
    if (isempty()) {
        cout << "Queue is empty" << endl;
        flight = "";
        stat = "";
        return;
    }
    flight = flights[front];
    stat = status[front];
    front++;
}

void Queue::display(string title) {
    cout << title << endl;
    if (isempty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    for (int i = front; i <= back; i++) {
        cout << flights[i] << " - " << status[i] << endl;
    }
}

// Airport implementation
Airport::Airport() {
    logFile.open("airport_log.txt", ios::out);
    if (logFile.is_open()) {
        logFile << "=== Airport Traffic Log ===" << endl;
    }
}

Airport::~Airport() {
    if (logFile.is_open()) {
        logFile << "=== End of Log ===" << endl;
        logFile.close();
    }
}

void Airport::logEvent(const string &event) {
    if (logFile.is_open()) {
        logFile << event << endl;
    }
}

void Airport::addArrival(string flight) {
    arrivals.enqueue(flight, "waiting to land");
    logEvent("Flight " + flight + " scheduled for arrival.");
}

void Airport::addDeparture(string flight) {
    departure.enqueue(flight, "waiting to take off");
    logEvent("Flight " + flight + " scheduled for departure.");
}

void Airport::landPlanes() {
    string flight, stat;
    arrivals.dequeue(flight, stat);
    if (flight != "") {
        logEvent("Flight " + flight + " has landed.");
        cout << flight << " has landed." << endl;
    } else {
        cout << "No planes waiting to land." << endl;
    }
}

void Airport::takeoffPlanes() {
    string flight, stat;
    departure.dequeue(flight, stat);
    if (flight != "") {
        cout << flight << " is taking off." << endl;
        logEvent("Flight " + flight + " has taken off.");
    } else {
        cout << "No planes waiting to take off." << endl;
    }
}

void Airport::displayStatus() {
    cout << "--- Airport Status ---" << endl;
    arrivals.display("Arrivals Queue:");
    departure.display("Departure Queue:");
}
