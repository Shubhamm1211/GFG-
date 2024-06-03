//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int ind,vector<int>& h,int k,int n,vector<int>&dp){
        if(ind==0)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int j=INT_MAX;
        for(int i=1;i<=k;i++){
            if(ind-i>=0){
                j=min(j,solve(ind-i,h,k,n,dp)+abs(h[ind]-h[ind-i]));
            }
        }
        return dp[ind]=j;
    }
    int minimizeCost(vector<int>& h, int n, int k) {
        // Code here
        vector<int>dp(n+1,-1);
        return solve(n-1,h,k,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends