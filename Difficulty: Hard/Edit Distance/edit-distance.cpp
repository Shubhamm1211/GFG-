//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int ind1,int ind2,string s1,string s2,vector<vector<int>>&dp){
        if(ind2<0)return ind1+1;
        if(ind1<0)return ind2+1;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2]){
            return dp[ind1][ind2]=solve(ind1-1,ind2-1,s1,s2,dp);
        }
        else{
            return dp[ind1][ind2]=1+min({solve(ind1,ind2-1,s1,s2,dp),solve(ind1-1,ind2,s1,s2,dp),solve(ind1-1,ind2-1,s1,s2,dp)});
        }
    }
    int editDistance(string str1, string str2) {
        // Code here
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n-1,m-1,str1,str2,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends