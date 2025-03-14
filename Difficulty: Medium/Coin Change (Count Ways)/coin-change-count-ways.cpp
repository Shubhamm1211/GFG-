//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector <vector <int>> dp;
    int solve(int ind, vector <int> &coins, int sum){
        if(ind == 0){
            if(sum % coins[ind] == 0){
                return 1;
            }
            return 0;
        }
        if(sum == 0){
            return 1;
        }
        if(dp[ind][sum] != -1) return dp[ind][sum];
        int pick = 0;
        if(sum - coins[ind] >= 0) pick = solve(ind, coins, sum - coins[ind]);
        int npick = solve(ind - 1, coins, sum);
        return dp[ind][sum] = pick + npick;
    }
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        dp.resize(n + 1, vector <int>(sum + 1, -1));
        return solve(n - 1, coins, sum);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends