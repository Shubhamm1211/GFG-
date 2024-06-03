//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int ind,vector<int>&h,int n,vector<int>&dp){
        if(ind==0)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int j1=solve(ind-1,h,n,dp)+abs(h[ind]-h[ind-1]);
        int j2=INT_MAX;
        if(ind>1){
            j2=solve(ind-2,h,n,dp)+abs(h[ind]-h[ind-2]);
        }
        return dp[ind]=min(j1,j2);
    }
    int minimumEnergy(vector<int>& h, int n) {
        // Code here
        vector<int>dp(n+1,-1);
        return solve(n-1,h,n,dp);
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