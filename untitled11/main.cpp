#include <iostream>
#include <fstream>
#include <string>
#include "flightAdjList.h"
using namespace std;
int main(){
    ifstream paths;
    ifstream requests;
    ofstream out("output.txt");
    flightAdjList f;
    //read in the data into the adjacency list
    paths.open("FlightD.txt");
    requests.open("RequestedFlightData.txt");
    int lines;
    paths >> lines;
    paths.ignore();
    string src, dest, t, c;
    int time;
    double cost;
    for (int i = 0; i < lines; i++) {
        getline(paths, src, '|');
        getline(paths, dest, '|');
        getline(paths, c, '|');
        cost = static_cast<double>(stoi(c));
        getline(paths, t);
        time = stoi(t);

        f.addFlight(src, dest, time,cost);
        cout << src << " " << dest << " " << cost << " " << time << endl;
    }
    f.printFlightAdjList();
    //read in the requests and put them in the output
    int x;
    requests >> x;
    requests.ignore();
    for (int i = 0; i < x; ++i) {
        getline(requests, src, '|');
        getline(requests, dest, '|');
        getline(requests, t);
        if(t == "T") {
            out << "Flight " << i + 1 << ": "<<src<<", " << dest<< " (Time)\n";
            f.printFlights(src, dest, out);
            out << endl;
        }else{
            out << "Flight " << i + 1 << ": "<<src<<", " << dest<< " (Cost)\n";
            f.printFlights(src, dest, out);
            out << endl;
        }
    }
    paths.close();
    requests.close();
    out.close();
    return 0;
}
