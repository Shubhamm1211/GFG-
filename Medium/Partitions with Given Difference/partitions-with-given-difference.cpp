//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int solve(int ind,vector<int>& arr,int sum,vector<vector<int>>&dp){
	    if(dp[ind][sum]!=-1)return dp[ind][sum];
	    if(ind==0){
	        if(sum==0 && arr[ind]==0)return 2;
	        if(sum==0 || sum==arr[ind])return 1;
	        return 0;
	    }
	    if(ind==0){
	        if(sum==arr[ind])return 1;
	        else return 0;
	    }
	    int npick=solve(ind-1,arr,sum,dp);
	    int pick=0;
	    if(arr[ind]<=sum){
	        pick=solve(ind-1,arr,sum-arr[ind],dp);
	    }
	    return dp[ind][sum]=(pick+npick)%1000000007;
	}
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int tar=accumulate(arr.begin(),arr.end(),0);
        if(tar-d<0 || (tar-d)%2==1)return 0;
        vector<vector<int>>dp(n+1,vector<int>(tar+1,-1));
        return solve(n-1,arr,(tar-d)/2,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends