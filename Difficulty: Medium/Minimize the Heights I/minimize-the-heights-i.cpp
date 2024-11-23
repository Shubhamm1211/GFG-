//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
        int getMinDiff(int k, vector<int> &arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int ans = INT_MAX;
        for(int x = 0;x < n;x++){
            int maxi = 1000000,mini = -1000000;
            if(x+1 < n)mini = min(arr[x+1]-k,arr[0]+k);
            maxi = max(arr[x]+k,arr[n-1]-k);
            
            ans = min(ans,maxi-mini);
        }
        ans = min(ans,arr[n-1] - arr[0]);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();

    while (t--) {
        int k;
        cin >> k;
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.getMinDiff(k, arr);
        cout << res;

        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends