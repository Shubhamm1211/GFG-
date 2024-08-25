//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    bool solve(string s1,string s2,int ind1,int ind2,vector<vector<int>>&dp){
        if(ind1>=0 and ind2<0){
            for(int i=ind1;i>=0;i--){
                if(s1[i]!='*')return false;
            }
            return true;
        }
        if(ind1<0 and ind2>=0){
            return false;
        }
        if(ind1<0 and ind2<0)return true;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2] || s1[ind1]=='?'){
            return dp[ind1][ind2]=solve(s1,s2,ind1-1,ind2-1,dp);
        }
        if(s1[ind1]=='*'){
            return dp[ind1][ind2]=solve(s1,s2,ind1-1,ind2,dp) || solve(s1,s2,ind1,ind2-1,dp);
        }
        return dp[ind1][ind2]=false;
    }
    int wildCard(string pattern, string str) {
        // code here
        int n=pattern.size();
        int m=str.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        bool f=solve(pattern,str,n-1,m-1,dp);
        if(f)return 1;
        else return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends