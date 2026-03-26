#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    
    vector<int> weight(n), value(n);
    
    cout << "Enter weights: ";
    for(int i = 0; i < n; i++) cin >> weight[i];
    
    cout << "Enter values: ";
    for(int i = 0; i < n; i++) cin >> value[i];
    
    cout << "Enter knapsack capacity (W): ";
    cin >> W;

    // dp[i][w] = max value using first i items with capacity w
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            // Don't take current item
            dp[i][w] = dp[i-1][w];
            
            // Take current item if possible
            if(weight[i-1] <= w) {
                dp[i][w] = max(dp[i][w], 
                               dp[i-1][w - weight[i-1]] + value[i-1]);
            }
        }
    }

    cout << "\nMaximum value in Knapsack = " << dp[n][W] << endl;

    // Optional: Print DP Table
    cout << "\nDP Table:\n";
    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            cout << setw(4) << dp[i][w] << " ";
        }
        cout << endl;
    }

    return 0;
}