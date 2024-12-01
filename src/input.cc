
#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <climits>

using namespace std;
const string BAD_DISPLAY_TYPE("Error: must be SHOW_CYCLES or SHOW_NO_CYCLE");
const string BAD_QUEUE_NB("Error: the number of queues must be strictly positive");
const string BAD_QUEUE_INDEX("Error: invalid queue index");

void print_error(string message) {
    cout << message << endl;
    exit(0);
}

void read_parameters(string &display_option, int &nbF, vector<queue<int>> &queues) {
    // Read display option
    cin >> display_option;
    if (display_option != "SHOW_CYCLES" && display_option != "SHOW_NO_CYCLE") {
        print_error(BAD_DISPLAY_TYPE);
    }

    // Read number of queues
    cin >> nbF;
    if (nbF <= 0) {
        print_error(BAD_QUEUE_NB);
    }

    // Initialize queues
    queues.clear();
    queues.resize(nbF);

    // Read transit requests
    int arrival, departure;
    while (cin >> arrival >> departure) {
        if (arrival < 0 || departure < 0) {
            break; // End of requests
        }
        if (arrival >= nbF || departure >= nbF) {
            print_error(BAD_QUEUE_INDEX);
        }
        queues[arrival].push(departure);
    }
}