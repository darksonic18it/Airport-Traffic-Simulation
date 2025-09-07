#include "runwaymanager.h"
#include <fstream>
#include <sstream>

int main() {
    RunwayManager runway;
    ifstream file("runwayinput.txt");

    if (!file) {
        cerr << "Cannot open runwayinput.txt" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string command, flight;
        getline(ss, command, ',');
        
        cout << "\nCommand: " << command << endl;

        if (command == "arrive") {
            getline(ss, flight, ',');
            runway.addArrival(flight);
        }
        else if (command == "depart") {
            getline(ss, flight, ',');
            runway.addDeparture(flight);
        }
        else if (command == "serve") {
            // FIX: This now serves just one plane at a time.
            // This is the correct logic to see the priority command in action.
            runway.serve();
        }
        else if (command == "serve_all") {
            // You can use this command to serve all planes at once
            runway.serveAll();
        }
        else if (command == "priority_takeoff") {
            getline(ss, flight, ',');
            runway.priorityTakeoff(flight);
        }
        else if (command == "status") {
            runway.displayStatus();
        }
    }

    return 0;
}
