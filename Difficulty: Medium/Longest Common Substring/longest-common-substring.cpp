//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int solve(int ind1,int ind2,string &text1,string &text2,vector<vector<int>>&dp){
        if(ind1<0 || ind2<0)return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(text1[ind1]==text2[ind2]){
            return dp[ind1][ind2]=1+solve(ind1-1,ind2-1,text1,text2,dp);
        }
        else dp[ind1][ind2]=0;
        solve(ind1-1,ind2,text1,text2,dp);
        solve(ind1,ind2-1,text1,text2,dp);
        return dp[ind1][ind2];
                                 
    }
    int longestCommonSubstr (string text1, string text2)
    {
        // your code here
        int l1=text1.size();
        int l2=text2.size();
        vector<vector<int>>dp(l1,vector<int>(l2,-1));
        int ans=0;
        for(int i=0;i<l1;i++){
            for(int j=0;j<l2;j++){
                solve(i,j,text1,text2,dp);
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends