#ifndef AIRPORT_H_INCLUDED
#define AIRPORT_H_INCLUDED
#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

#define SIZE 10

class Queue{
  private:
  string flights[SIZE];
  string status[SIZE];
  int front, back;

  public:
  Queue();
  bool isempty();
  bool isfull();
  void enqueue(string flight, string stat);
  void dequeue(string& flight, string& stat);
  void display(string title);

};
class Airport{
  private:
  Queue arrivals;
  Queue departure;
  ofstream logFile;

  void logEvent(const string& event);

  public:
  Airport();
  ~Airport();

  void addArrival(string flight);
  void addDeparture(string flight);
  void landPlanes();
  void takeoffPlanes();
  void displayStatus();
};
#endif