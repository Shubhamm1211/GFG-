//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int solve(vector<int>&arr,int l,int r,vector<vector<int>>&dp){
        if(l>r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        int left=arr[l]+min(solve(arr,l+1,r-1,dp),solve(arr,l+2,r,dp));
        int right=arr[r]+min(solve(arr,l+1,r-1,dp),solve(arr,l,r-2,dp));
        return dp[l][r]=max(left,right);
    }
    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	    vector<vector<int>>dp(n,vector<int>(n,-1));
	    return solve(A,0,n-1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}

// } Driver Code Ends