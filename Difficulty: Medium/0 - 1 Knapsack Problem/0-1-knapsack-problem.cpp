//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int solve(vector<int> &val, vector<int> &wt, int w,int ind, vector<vector<int>> &dp){
        if(ind == 0){
            if(wt[0] <= w){
                return val[0];
            }
            else return 0;
        }
        if(ind - 1 < 0){
            return 0;
        }
        if(dp[ind][w] != -1) return dp[ind][w];
        int pick = 0;
        if(wt[ind] <= w){
            pick = val[ind] + solve(val,wt,w - wt[ind],ind - 1, dp);
        }
        int notpick = 0 + solve(val,wt,w, ind - 1, dp);
        
        return dp[ind][w] = max(pick,notpick);
    }
    int knapSack(int w, vector<int>& wt, vector<int>& val) {
        // Your code here
        int n = wt.size();
        vector<vector<int>>dp(n,vector<int>(w+1,-1));
        return solve(val,wt,w,n - 1,dp);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends