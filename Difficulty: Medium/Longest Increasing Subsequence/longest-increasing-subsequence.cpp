//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  vector <vector <int>> dp;
    int solve(vector <int> &arr, int ind, int prev){
        if(ind == arr.size()){
            return 0;
        }
        if(dp[ind][prev + 1] != -1) return dp[ind][prev + 1];
        int nottake = solve(arr,ind + 1, prev);
        int take = 0;
        if(prev == -1 or arr[ind] > arr[prev]){
            take = 1 + solve(arr,ind + 1, ind);
        }
        return dp[ind][prev + 1] = max(take,nottake);
    }
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        dp.resize(n + 1,vector <int> (n + 1, -1));
        return solve(arr,0,-1);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends