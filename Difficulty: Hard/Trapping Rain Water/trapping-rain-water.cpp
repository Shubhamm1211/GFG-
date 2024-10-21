//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

    // Function to find the trapped water between the blocks.
  public:
    long long trappingWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> rmax(n) , lmax(n);
        lmax[0] = arr[0];
        rmax[n - 1] = arr[n - 1];
        for(int i = 1; i < n; i++){
            lmax[i] = max(lmax[i - 1], arr[i]);
        }
        for(int i = n - 2; i >= 0; i--){
            rmax[i] = max(rmax[i + 1], arr[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += abs(min(rmax[i],lmax[i]) - arr[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        long long res = ob.trappingWater(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends