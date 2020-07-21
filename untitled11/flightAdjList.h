#include <utility>
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include "linkedList.h"
#include "stack.cpp"
#include "linkedList.cpp"
using namespace std;

struct city{
    string name;
    struct city *next;
    struct flight *first;
    city() {
        name = "";
        next = nullptr;
        first = nullptr;
    }
    explicit city(string n) {
        name = std::move(n);
        next = nullptr;
        first = nullptr;
    }
};
struct flight{
    string destination;
    int time;
    double cost;
    city *head;
    struct flight *next;
    //default constructor
    flight() {
        destination = "";
        time = 0;
        cost = 0.0;
        head = nullptr;
        next = nullptr;
    }
    //new flight constructor
    flight(city *srcCity, string dest, int t, double c) {
        this->destination = std::move(dest);
        time = t;
        cost = c;
        head = srcCity;
        next = nullptr;
    }
};
class flightAdjList {
    city *head;
    int V;
    int flightCounter;
public:
    flightAdjList() {
        head = nullptr;
        V = 0;
    }

    void addCity(string n) {
        if (!head) head = new city(n);
        else {
            city *ptr = head;
            if (!containsCity(n)) {
                //traverse and add to end
                while (ptr->next)ptr = ptr->next;
                ptr->next = new city(n);
            }
        }
    }

    void printV() { cout << V; }

    void addFlight(string source, string destination, int time, double cost) {
        // adds the cities if they are not present in the graph
        if (!containsCity(source)) {
            addCity(source);
            V++;
        }
        if (!containsCity(destination)) {
            addCity(destination);
            V++;
        }
        // connect the city
        city *srcCity = findCity(source);
        flight *ptr = srcCity->first;
        if (!ptr)
            srcCity->first = new flight(srcCity, destination, time, cost);
        else {
            while (ptr->next)
                ptr = ptr->next;
            ptr->next = new flight(srcCity, destination, time, cost);
        }
        srcCity = findCity(destination);
        ptr = srcCity->first;
        if (!ptr)
            srcCity->first = new flight(srcCity, source, time, cost);
        else {
            while (ptr->next)
                ptr = ptr->next;
            ptr->next = new flight(srcCity, source, time, cost);
        }
    }

    bool containsCity(string n) {
        city *ptr = head;
        while (ptr) {
            if (ptr->name == n) return true;
            ptr = ptr->next;
        }
        return false;
    }

    city *findCity(string n) {
        city *ptr = head;
        while (ptr) {
            if (ptr->name == n) return ptr;
            ptr = ptr->next;
        }
        return nullptr;
    }
    int findIndex(string name)
    {
        int index, counter = 0;
        city* nptr = head;
        while (nptr)
        {
            if (nptr->name == name) index = counter;
            counter++;
            nptr = nptr->next;
        }
        return index;
    }
    city* findCity(int i) {
        city *ptr = head;
        while (ptr) {
            if (findIndex(ptr->name) == i) return ptr;
            ptr = ptr->next;
        }
        return NULL;
    }
    void printFlightAdjList() {
        cout << "POSSIBLE PATHS" << endl;
        city *nptr = head;
        flight *ptr;
        while (nptr) {
            cout << "[" << nptr->name << "] -> ";
            ptr = nptr->first;
            while (ptr) {
                cout << ptr->destination;
                if (ptr->next)
                    cout << " -> ";
                ptr = ptr->next;
            }
            cout << endl;
            nptr = nptr->next;  // go to next city node
        }
    }
void printFlights(string src, string dest, ofstream& file) {
    flightCounter = 0;
    int time=0;
    double cost=0;
    // mark all vertices visited in here
    bool *visited = new bool[V];
    // create an array to store paths
    int *path = new int[V];
    int pathI = 0;
    // initialize all vertices as false
    for (int i=0; i<V; i++) {
        visited[i] = false;
    }
    // recursive function to help print the flight
    printFlightsR(src, dest, visited, path, pathI, file, time, cost);
}
void printFlightsR(string cur, string dest, bool visited[], int path[], int &pathI, ofstream& file, int time, double cost) {
    city *currentCity = findCity(cur);
    visited[findIndex(cur)] = true;
    path[pathI] = findIndex(cur);
    pathI++;
    if(flightCounter==3)return;
    // if current vertex is same as destination, then print the flight
    if (cur == dest) {
        flightCounter++;
        file << "Path " << flightCounter << ": ";
        for (int i=0; i<pathI-1; i++) {
            file << findCity(path[i])->name << " -> ";
        }
        file << findCity(path[pathI-1])->name;
        city *nptr = findCity(path[0]);
        flight *ptr = nptr->first;
        bool d;
        for (int i=1;i<pathI; i++) {
            d = true;
            // finds pathNode and adds time or cost to sum
            while (ptr && d) {
                if (ptr->destination == findCity(path[i])->name) {
                    time += ptr->time;
                    cost += ptr->cost;
                    ptr = findCity(path[i])->first;
                    d = false;
                }
                else
                    ptr = ptr->next;
            }
        }
        file << " Time: " << time << " Cost: " << cost << endl;
    } else {
        // recur to unvisited along the flight
        flight *ptr = currentCity->first;
        while (ptr) {
            if (!visited[findIndex(ptr->destination)]) {
                printFlightsR(ptr->destination, dest, visited, path, pathI, file, time, cost);
            }
            ptr = ptr->next;
        }
    }
    pathI--;
    visited[findIndex(cur)] = false;
}
};

#pragma once