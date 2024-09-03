//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solve(string s1,string s2,int ind1,int ind2,vector<vector<int>>&dp){
	    if (ind1 == 0) return ind2; 
        if (ind2 == 0) return ind1;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
	    if(s1[ind1-1]==s2[ind2-1]){
	        return dp[ind1][ind2]=solve(s1,s2,ind1-1,ind2-1,dp);
	    }
	    else{
	        return dp[ind1][ind2]=1+min(solve(s1,s2,ind1-1,ind2,dp),solve(s1,s2,ind1,ind2-1,dp));
	    }
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n1=str1.size();
	    int n2=str2.size();
	    vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
	    int ans=solve(str1,str2,n1,n2,dp);
	    return ans;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends