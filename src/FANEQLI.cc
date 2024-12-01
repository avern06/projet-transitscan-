#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <climits>

using namespace std;

void run_FANEQLI(const string &display_option, vector<queue<int>> &queues, int &total_cycles, int &total_moves, vector<double> &avg_wait) {
    cout << "FANEQLI" << endl;
    int nbF = queues.size();
    int scanner_position = 0;
    int cycle_count = 0;
    int move_count = 0;
    vector<int> wait_times(nbF, 0);
    vector<int> initial_sizes(nbF);
    vector<bool> done(nbF, false);

    for (int i = 0; i < nbF; ++i) {
        initial_sizes[i] = queues[i].size();
    }

    while (true) {
        bool all_done = true;
        int next_queue = -1;
        int min_queue_size = INT_MAX;

        // Find the non-empty queue with the smallest size and closest to the scanner position
        for (int i = 0; i < nbF; ++i) {
            if (!queues[i].empty() && !done[i]) {
                if (queues[i].size() < min_queue_size) {
                    next_queue = i;
                    min_queue_size = queues[i].size();
                }
                all_done = false;
            }
        }

        // If all queues are done, reset for a new tour
        if (all_done) {
            fill(done.begin(), done.end(), false);
            continue;
        }

        // Move scanner to the selected queue
        if (scanner_position != next_queue) {
            move_count += abs(scanner_position - next_queue);
        }
        scanner_position = next_queue;
        int departure = queues[scanner_position].front();
        queues[scanner_position].pop();
        done[scanner_position] = true;
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