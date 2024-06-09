//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
	public:
	int solve(int ind,int arr[],int sum,vector<vector<int>>&dp){
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
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(n-1,arr,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends