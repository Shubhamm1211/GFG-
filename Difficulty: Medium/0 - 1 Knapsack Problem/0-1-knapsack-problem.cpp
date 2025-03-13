//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector <vector <int>> dp;
    int n;
    // Function to return max value that can be put in knapsack of capacity.
    int solve(int ind, vector <int> &val, vector <int> &wt, int w){
        if(ind == n){
            return 0;
        }
        if(dp[ind][w] != -1) return dp[ind][w];
        int pick = 0, npick = 0;
        if(wt[ind] <= w) pick = val[ind] + solve(ind + 1, val, wt, w - wt[ind]);
        npick = solve(ind + 1, val, wt, w);
        return dp[ind][w] = max(pick,npick);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        n = val.size();
        int ind = 0;
        dp.resize(n + 1, vector <int>(W + 1, -1));
        return solve(ind,val,wt,W);
    }
};




//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends