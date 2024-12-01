#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <climits>

using namespace std;

void run_NEQLI(const string &display_option, vector<queue<int>> &queues, int &total_cycles, int &total_moves, vector<double> &avg_wait) {
    cout << "NEQLI" << endl;
    int nbF = queues.size();
    int scanner_position = 0; // Start the scanner at floor 0 initially
    int cycle_count = 0;
    int move_count = 0;
    vector<int> wait_times(nbF, 0);
    vector<int> initial_sizes(nbF);

    for (int i = 0; i < nbF; ++i) {
        initial_sizes[i] = queues[i].size();
    }

    while (true) {
        // Find the next non-empty queue starting from the beginning each time
        int next_queue = -1;
        for (int i = 0; i < nbF; ++i) {
            if (!queues[i].empty()) {
                next_queue = i;
                break;
            }
        }

        // If all queues are empty, we're done
        if (next_queue == -1) {
            break;
        }

        // Move scanner to the next non-empty queue
        move_count += abs(scanner_position - next_queue);
        scanner_position = next_queue;
        int departure = queues[scanner_position].front();
        queues[scanner_position].pop();
        cycle_count++;

        // Update wait times for all non-empty queues except the current one
        for (int i = 0; i < nbF; ++i) {
            if (!queues[i].empty() && i != scanner_position) {
                wait_times[i]++;
            }
        }

        // Determine exit and enter states
        bool exit = true; // Since we always pop from the current queue
        bool enter = !queues[scanner_position].empty();

        // Display cycle if required
        if (display_option == "SHOW_CYCLES") {
            cout << scanner_position << "\t" << departure << "\t" << (exit ? 1 : 0) << " " << (enter ? 1 : 0) << endl;
        }
    }

    total_cycles = cycle_count;
    total_moves = move_count;
    for (int i = 0; i < nbF; ++i) {
        if (initial_sizes[i] > 0) {
            avg_wait[i] = static_cast<double>(wait_times[i]) / initial_sizes[i];
        }
    }
}
