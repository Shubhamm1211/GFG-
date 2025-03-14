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
                return sum / coins[ind];
            }
            else return 1e9;
        }
        if(ind < 0) return 1e9;
        if(sum == 0) return 0;
        if(dp[ind][sum] != -1) return dp[ind][sum];
        int pick = 1e9;
        int npick = solve(ind - 1, coins, sum);
        if(coins[ind] <= sum){
            pick = 1 + solve(ind, coins, sum - coins[ind]);
        }
        return dp[ind][sum] = min(pick,npick);
    }
    int minCoins(vector<int> &coins, int sum) {
        // code here
        int n = coins.size();
        dp.resize(n + 1, vector <int>(sum + 1, -1));
        int ans = solve(n - 1, coins, sum);
        return (ans == 1e9) ? -1 : ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends