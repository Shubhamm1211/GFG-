//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    int solve(int n,vector<int>&dp){
	        if(n==0)return 1;
	        if(n<0)return 0;
	        if(dp[n]!=-1)return dp[n];
	        int os=1+solve(n-1,dp);
	        int ts=INT_MAX;
	        if(n-2>=0){
	            ts=1+solve(n-2,dp);
	        }
	        return dp[n]=min(os,ts);
	    }
		int nthStair(int n){
		    //  Code here
		    vector<int>dp(n+1,-1);
		    return solve(n-1,dp);
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends