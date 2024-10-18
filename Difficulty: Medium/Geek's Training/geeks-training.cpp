//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(vector<vector<int>>& arr, int ind, int last,vector<vector<int>> &dp){
        if(dp[ind][last] != -1) return dp[ind][last];
        
        if(ind == 0){
            int maxi = INT_MIN;
            for(int i = 0; i < 3; i++){
                if(i != last){
                    maxi = max(maxi, arr[0][i]);
                }
            }
            return maxi;
        }
        int maxi = INT_MIN;
        for(int i = 0; i < 3; i++){
            if(i != last)
            maxi = max(maxi, arr[ind][i] + solve(arr,ind - 1, i,dp));
        }
        return dp[ind][last] = maxi;
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>> dp(n + 1, vector<int>(4, -1));
        return solve(arr, n - 1, 3,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends