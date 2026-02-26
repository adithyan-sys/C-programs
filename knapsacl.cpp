#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    // dp[i][w] = max value using first i items with capacity w
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build table dp[][] in bottom-up manner
    for (int i = 1; i <= n; i++) {          // items
        for (int w = 0; w <= W; w++) {      // capacity
            // If current item weight > current capacity → skip it
            if (wt[i-1] > w) {
                dp[i][w] = dp[i-1][w];
            }
            // Else take maximum of two cases:
            // 1. not including current item
            // 2. including current item
            else {
                dp[i][w] = max(
                    dp[i-1][w],                   // exclude
                    dp[i-1][w - wt[i-1]] + val[i-1] // include
                );
            }
        }
    }

    return dp[n][W];
}

// Optional: Print the selected items (backtracking)
void printSelectedItems(int W, vector<int>& wt, vector<int>& val, int n, vector<vector<int>>& dp) {
    cout << "\nSelected items:\n";
    int w = W;
    for (int i = n; i > 0 && w > 0; i--) {
        // If this item is included
        if (dp[i][w] != dp[i-1][w]) {
            cout << "Item " << i << " (weight=" << wt[i-1] 
                 << ", value=" << val[i-1] << ")\n";
            w = w - wt[i-1];
        }
    }
}

int main() {
    int n;          // number of items
    int W;          // knapsack capacity

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> val(n), wt(n);

    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << (i+1) << " (value weight): ";
        cin >> val[i] >> wt[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;

    // Create dp table (needed for printing selected items)
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i-1] > w)
                dp[i][w] = dp[i-1][w];
            else
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - wt[i-1]] + val[i-1]);
        }
    }

    int maxValue = dp[n][W];

    cout << "\n========================================\n";
    cout << "Maximum value we can achieve = " << maxValue << endl;
    cout << "========================================\n";

    printSelectedItems(W, wt, val, n, dp);

    // Optional: Show small table if capacity is reasonable
    if (W <= 20 && n <= 10) {
        cout << "\nDP Table (rows = items, columns = capacity):\n";
        for (int i = 0; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                cout << setw(4) << dp[i][w] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}