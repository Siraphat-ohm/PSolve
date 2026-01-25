#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];

void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void remove_edge(int u, int v) {
    for (int i = 0; i < adj[u].size(); i++) {
        if (adj[u][i] == v) {
            adj[u].erase(adj[u].begin() + i);
            break;
        }
    }

    for (int i = 0; i < adj[v].size(); i++) {
        if (adj[v][i] == u) {
            adj[v].erase(adj[v].begin() + i);
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L, N;
    cin >> L >> N;

    int current_id = 1;
    for (int i = 0; i < L; i++) {
        int len;
        cin >> len;
        for (int j = 0; j < len - 1; j++) {
            add_edge(current_id + j, current_id + j + 1);
        }
        current_id += len;
    }

    int robot_curr = 1;
    int robot_prev = 0;

    for (int i = 0; i < N; i++) {
        char cmd;
        cin >> cmd;

        if (cmd == 'F') {
            int next_node = -1;
            for (int neighbor : adj[robot_curr]) {
                if (neighbor != robot_prev) {
                    next_node = neighbor;
                    break;
                }
            }

            if (next_node != -1) {
                robot_prev = robot_curr;
                robot_curr = next_node;
            }
        }
        else if (cmd == 'B') {
            if (robot_prev != 0) {
                int target_node = robot_prev;

                int new_prev = 0;
                for (int neighbor : adj[target_node]) {
                    if (neighbor != robot_curr) {
                        new_prev = neighbor;
                        break;
                    }
                }

                robot_curr = target_node;
                robot_prev = new_prev;
            }
        }
        else if (cmd == 'C') {
            int X;
            cin >> X;

            int forward_node = -1;
            for (int neighbor : adj[robot_curr]) {
                if (neighbor != robot_prev) {
                    forward_node = neighbor;
                    break;
                }
            }

            if (forward_node != -1) {
                remove_edge(robot_curr, forward_node);
            }

            add_edge(robot_curr, X);

            robot_prev = robot_curr;
            robot_curr = X;
        }

        cout << robot_curr << "\n";
    }

    return 0;
}
