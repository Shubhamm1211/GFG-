//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector <vector <int>> dp;
    int solve(int ind1, int ind2, string &s1, string &s2){
        if(ind1 < 0 or ind2 < 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(s1[ind1] == s2[ind2]) return dp[ind1][ind2] = 1 + solve(ind1 - 1, ind2 - 1, s1, s2);
        if(s1[ind1] != s2[ind2]) return dp[ind1][ind2] = max(solve(ind1 - 1, ind2,s1,s2), solve(ind1, ind2 - 1, s1, s2));
    }
    int lcs(string &s1, string &s2) {
        // code here
        int n1 = s1.size();
        int n2 = s2.size();
        dp.resize(n1 + 1, vector <int> (n2 + 1, -1));
        return solve(n1 - 1, n2 - 1, s1, s2);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends