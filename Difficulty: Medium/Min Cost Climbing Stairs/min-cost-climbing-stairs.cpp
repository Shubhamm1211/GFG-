//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    vector <int> dp;
    int n;
    int solve(int ind, vector <int> &cost){
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];
        int op1 = cost[ind] + solve(ind + 1, cost);
        int op2 = cost[ind] + solve(ind + 2, cost);
        return dp[ind] = min(op1,op2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        n = cost.size();
        dp.resize(n + 1, -1);
        return min(solve(0,cost),solve(1,cost));
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends