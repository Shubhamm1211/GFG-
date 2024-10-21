//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp, int &ans){
    if(i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
     int len = 0;
    if (s[i] == t[j]) len = 1 + solve(i - 1, j - 1, s, t, dp, ans);
     ans = max(ans, len);
    solve(i - 1, j, s, t, dp, ans);
    solve(i, j - 1, s, t, dp, ans);
    return dp[i][j] = len;
}

public:
    int longestCommonSubstr(string str1, string str2) {
        int ans = 0;
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    solve(n-1, m-1, str1, str2, dp, ans);
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