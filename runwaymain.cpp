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
        string command, flight, type;
        getline(ss, command, ',');
        
        cout << "\nCommand: " << command << endl;

        if (command == "arrive") {
            getline(ss, flight, ',');
            getline(ss, type, ','); // landing or takeoff
            if (type == "landing") {
                runway.addArrival(flight);
            } else if (type == "takeoff") {
                runway.addDeparture(flight);
            }
        }
        else if (command == "serve") {
            runway.serve();
        }
        else if (command == "serve_all") {
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
