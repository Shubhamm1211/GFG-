//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector <int> dp;
    int solve(int ind, vector <int> &arr){
        int n = arr.size();
        if(ind == n - 1){
            return 0;
        }
        if(ind >= n) return 1e8;
        if(dp[ind] != -1) return dp[ind];
        int pick = 1e8;
        for(int i = 1; i <= arr[ind]; i++){
            pick = min(pick, 1 + solve(ind + i, arr));
        }
        return dp[ind] = pick;
    }
    int minJumps(vector<int>& arr) {
        // code here
        dp.resize(arr.size() + 1, -1);
        int ans = solve(0,arr);
        if(ans == 1e8) return -1;
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends