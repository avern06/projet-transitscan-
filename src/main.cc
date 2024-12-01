#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <climits>
#include <input.h>
#include <NEQLI.h>
#include <FANEQLI.h>

using namespace std;

int main() {
    string display_option;
    int nbF;
    vector<queue<int>> queues;

    // Read parameters from standard input
    read_parameters(display_option, nbF, queues);

    // Display the initial state of the queues
    display_initial_state(queues);

    // Save the original queues for FANEQLI
    vector<queue<int>> original_queues = queues;

    // Run NEQLI algorithm
    int neqli_cycles = 0, neqli_moves = 0;
    vector<double> neqli_avg_wait(nbF, 0);
    run_NEQLI(display_option, queues, neqli_cycles, neqli_moves, neqli_avg_wait);

    // Restore the original queues for FANEQLI
    queues = original_queues;

    // Run FANEQLI algorithm
    int faneqli_cycles = 0, faneqli_moves = 0;
    vector<double> faneqli_avg_wait(nbF, 0);
    run_FANEQLI(display_option, queues, faneqli_cycles, faneqli_moves, faneqli_avg_wait);

    // Display statistics
    cout << "Nombre de cycles" << endl;
    cout << neqli_cycles << "\t" << faneqli_cycles << endl;
    cout << "Deplacement total" << endl;
    cout << neqli_moves << "\t" << faneqli_moves << endl;
    cout << "Attente moyenne" << endl;
    for (int i = 0; i < nbF; ++i) {
        cout << i;
        if (neqli_avg_wait[i] != 0 || faneqli_avg_wait[i] != 0) {
            cout << "\t" << fixed << setprecision(2) << neqli_avg_wait[i] << "\t" << faneqli_avg_wait[i];
        }
        cout << endl;
    }

    return 0;
}

