//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int ind , int price[], int w,vector <vector<int>> &dp){
        if(ind == 0){
            return w  * price[0];
        }
        if(dp[ind][w] != -1) return dp[ind][w];
        int pick = INT_MIN;
        if(ind + 1 <= w){
            pick = price[ind] + solve(ind, price, w - (ind + 1),dp);
        }
        int notpick = solve(ind - 1, price, w,dp);
        return dp[ind][w] = max(pick, notpick);
    }
    int cutRod(int price[], int n) {
        // code here
        vector <vector<int>> dp(n , vector<int>(n + 1, -1));
        return solve(n - 1, price, n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends