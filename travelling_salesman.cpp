#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// n = number of cities (max ~20 is realistic for exact TSP)
int n;
vector<vector<int>> dist;           // dist[i][j] = distance from i to j
vector<vector<int>> dp;             // dp[mask][pos] = min cost to visit mask, ending at pos
vector<vector<int>> parent;         // to reconstruct path

// mask = bitmask of visited cities
// pos  = current city
int tsp(int mask, int pos) {
    // Base case: visited all cities → return to start (city 0)
    if (mask == (1 << n) - 1) {
        return dist[pos][0];
    }

    // Already computed
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;
    int best_next = -1;

    // Try going to every unvisited city
    for (int next = 0; next < n; next++) {
        if ((mask & (1 << next)) == 0) {     // not visited
            int new_mask = mask | (1 << next);
            int cost = dist[pos][next] + tsp(new_mask, next);

            if (cost < ans) {
                ans = cost;
                best_next = next;
            }
        }
    }

    // Save best next city for path reconstruction
    parent[mask][pos] = best_next;

    return dp[mask][pos] = ans;
}

// Reconstruct the actual path
vector<int> getPath() {
    vector<int> path;
    int mask = 1;           // start from city 0
    int pos = 0;

    path.push_back(0);

    while (parent[mask][pos] != -1) {
        int next = parent[mask][pos];
        path.push_back(next);
        mask |= (1 << next);
        pos = next;
    }

    // Close the cycle
    path.push_back(0);
    return path;
}

int main() {
    cout << "Enter number of cities (n <= 20): ";
    cin >> n;

    if (n > 20) {
        cout << "n is too large for exact TSP (use approximation for n > 20)\n";
        return 1;
    }

    dist.assign(n, vector<int>(n));
    cout << "\nEnter distance matrix (use " << INF << " for no direct road):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
            // Make it symmetric if needed (undirected graph)
            // if (dist[i][j] == INF) dist[j][i] = INF;
        }
    }

    // Initialize DP table
    dp.assign(1 << n, vector<int>(n, -1));
    parent.assign(1 << n, vector<int>(n, -1));

    // Start from city 0, mask = 1 (only 0 is visited)
    int min_cost = tsp(1, 0);

    if (min_cost >= INF) {
        cout << "\nNo possible tour exists.\n";
        return 0;
    }

    cout << "\n====================================\n";
    cout << "Minimum tour cost = " << min_cost << endl;
    cout << "====================================\n";

    vector<int> path = getPath();

    cout << "Optimal tour: ";
    for (int city : path) {
        cout << city;
        if (city != path.back()) cout << " -> ";
    }
    cout << "\n\n";

    // Optional: show total cost step by step
    cout << "Path cost breakdown:\n";
    int total = 0;
    for (size_t i = 0; i + 1 < path.size(); i++) {
        int u = path[i], v = path[i+1];
        cout << u << " → " << v << " = " << dist[u][v] << "\n";
        total += dist[u][v];
    }
    cout << "Total = " << total << " (should match " << min_cost << ")\n";

    return 0;
}