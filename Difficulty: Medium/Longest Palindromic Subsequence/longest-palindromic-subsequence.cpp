//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    vector <vector <int>> dp;
    int solve(int ind1, int ind2, string &s1, string &s2){
        if(ind1 < 0 or ind2 < 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(s1[ind1] == s2[ind2]){
            return dp[ind1][ind2] = 1 + solve(ind1 - 1, ind2 - 1, s1, s2);
        }
        if(s1[ind1] != s2[ind2]){
            int op1 = solve(ind1 - 1, ind2, s1, s2);
            int op2 = solve(ind1, ind2 - 1, s1, s2);
            return dp[ind1][ind2] = max(op1,op2);
        }
    }
    int longestPalinSubseq(string &s) {
        // code here
        string s1 = s;
        reverse(begin(s), end(s));
        int n = s.size();
        dp.resize(n + 1, vector <int>(n + 1, -1));
        return solve(n - 1, n - 1, s, s1);
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends