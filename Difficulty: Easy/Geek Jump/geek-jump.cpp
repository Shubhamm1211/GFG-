//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(vector<int> &h,int ind,vector<int> &dp){
        if(ind == 0){
            return 0;
        }
        if(dp[ind] != -1)return dp[ind];
        int p1 = solve(h,ind - 1,dp) + abs(h[ind] - h[ind - 1]);
        int p2 = INT_MAX;
        if(ind - 2 >= 0){
            p2 = solve(h,ind - 2,dp) + abs(h[ind] - h[ind - 2]);
        }
        return dp[ind] = min(p1,p2);
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector <int> dp(n + 1,-1);
        return solve(height,n - 1,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends