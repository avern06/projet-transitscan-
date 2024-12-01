#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <climits>

using namespace std;
void read_parameters(string &display_option, int &nbF, vector<queue<int>> &queues);
void display_initial_state(const vector<queue<int>> &queues);
void print_error(string message);