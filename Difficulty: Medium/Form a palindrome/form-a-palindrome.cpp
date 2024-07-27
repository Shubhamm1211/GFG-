//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int solve(int ind1,int ind2,string &org,string &rev,vector<vector<int>>&dp){
        
        if(ind1<0 || ind2<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(org[ind1]==rev[ind2]){
            return dp[ind1][ind2]=1+solve(ind1-1,ind2-1,org,rev,dp);
        }
        else{
            return dp[ind1][ind2]=max(solve(ind1-1,ind2,org,rev,dp),solve(ind1,ind2-1,org,rev,dp));
        }
    }
    int countMin(string str){
    //complete the function here
    string org=str;
    reverse(str.begin(),str.end());
    string rev=str;
    int n=org.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    int lps=solve(n-1,n-1,org,rev,dp);
    return n-lps;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends