//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int solve(int w,vector<int>&wt,vector<int>&val,int ind){
        if(ind==0){
            if(wt[ind]<=w){
                return val[ind];
            }
            else return 0;
        }
        int npick=solve(w,wt,val,ind-1);
        int pick=INT_MIN;
        if(wt[ind]<=w){
            pick=val[ind]+solve(w-wt[ind],wt,val,ind-1);
        }
        return max(pick,npick);
    }
    int knapSack(int w, vector<int>& wt, vector<int>& val) {
        // Your code here
        int n=val.size();
        return solve(w,wt,val,n-1);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends