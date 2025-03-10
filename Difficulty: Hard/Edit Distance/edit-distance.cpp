//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  vector <vector <int>> dp;
  int n1,n2;
    // Function to compute the edit distance between two strings
    int solve(int ind1, int ind2, string &s1, string &s2){
        if(ind1 == n1){
            return n2 - ind2;
        }
        if(ind2 == n2){
            return n1 - ind1;
        }
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(s1[ind1] == s2[ind2]){
            return dp[ind1][ind2] = solve(ind1 + 1, ind2 + 1, s1, s2);
        }
        else if(s1[ind1] != s2[ind2]){
            int op1 = 1 + solve(ind1 + 1, ind2, s1,s2);
            int op2 = 1 + solve(ind1 + 1, ind2 + 1,s1,s2);
            int op3 = 1 + solve(ind1, ind2 + 1, s1,s2);
            return dp[ind1][ind2] = min({op1,op2,op3});
        }
    }
    int editDistance(string& s1, string& s2) {
        // code here
        n1 = s1.size();
        n2 = s2.size();
        dp.resize(n1 + 1, vector <int>(n2 + 1, -1));
        return solve(0,0,s1,s2);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends