//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int solve(int arr[], int ind, int sum, vector <vector<int>> &dp){
	   // if(sum == 0 && arr[0] == 0)return 2;
	    if(ind == 0){
	        if(sum == 0 and arr[0] == 0){
	            return 2;
	        }
	        if(arr[ind] == sum or sum == 0){
	            return 1;
	        }
	        return 0;
	    }
	    if(dp[ind][sum] != -1) return dp[ind][sum];
	    int pick = 0;
	    if(arr[ind] <= sum){
	        pick = solve(arr, ind - 1, sum - arr[ind],dp);
	    }
	    int notpick = solve(arr,ind - 1, sum, dp);
	    
	    return dp[ind][sum] = (pick + notpick) % 1000000007;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector <vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return solve(arr, n - 1, sum, dp);
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