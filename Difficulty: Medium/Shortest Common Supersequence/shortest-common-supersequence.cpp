//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int solve(int ind1,int ind2,string x,string y,vector<vector<int>>&dp){
        if(ind1<0 || ind2<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(x[ind1]==y[ind2]){
            return dp[ind1][ind2]=1+solve(ind1-1,ind2-1,x,y,dp);
        }
        return dp[ind1][ind2]=max(solve(ind1-1,ind2,x,y,dp),solve(ind1,ind2-1,x,y,dp));
    }
    int shortestCommonSupersequence(string x, string y, int m, int n)
    {
        //code here
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int lcs=solve(m-1,n-1,x,y,dp);
        // cout<<lcs<<endl;
        int t=m+n;
        t=t-lcs;
        return t;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends