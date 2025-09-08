#include "runwaymanager.h" // include header file
#include <fstream>
#include <sstream>

int main() {
    RunwayManager runway; // create object of RunwayManager
    ifstream file("runwayinput.txt"); // open input file
 
    if (!file) { // error checking
        cerr << "Cannot open runwayinput.txt" << endl;
        return 1; // exit with error
    }

    string line; // to hold each line from file
    while (getline(file, line)) { // read each line
        stringstream ss(line); // create stringstream from line
        string command, flight, type; // to hold command, flight, and type
        getline(ss, command, ','); // get command
        
        cout << "\nCommand: " << command << endl; // display command

        if (command == "arrive") { // arrive command
            getline(ss, flight, ','); // get flight
            getline(ss, type, ','); // landing or takeoff
            if (type == "landing") { // if landing
                runway.addArrival(flight); // add to landing queue
            } else if (type == "takeoff") { // if takeoff
                runway.addDeparture(flight); // add to takeoff deque
            }
        }
        else if (command == "serve") { // serve command
            runway.serve(); // serve next plane
        }
        else if (command == "serve_all") { // serve_all command
            runway.serveAll(); // serve all planes
        }
        else if (command == "priority_takeoff") { // priority_takeoff command
            getline(ss, flight, ','); // get flight
            runway.priorityTakeoff(flight); // priority takeoff
        }
        else if (command == "status") { // status command
            runway.displayStatus(); // display current status
        }
    }

    return 0;
}
