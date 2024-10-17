//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(vector<int>&arr,int k, int ind,vector<int>&dp){
        if(ind == 0){
            return 0;
        }
        if (dp[ind] != -1) return dp[ind];
        int p1 = INT_MAX;
        for(int i = 1; i <= k; i++){
            if(ind - i >= 0){
                int t = solve(arr,k, ind - i,dp) + abs(arr[ind] - arr[ind - i]);
                p1 = min(p1,t);
            }
        }
        return dp[ind] = p1;
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector <int> dp(n + 1,-1);
        return solve(arr,k,n - 1,dp);
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
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends