//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

int solve(vector<int>& arr, int curr, int k) {
    if (arr.size() == 1) {
        return arr[0]; // Base case: only one element left
    }
    curr = (curr + k) % arr.size(); // Calculate the index of the element to remove
    arr.erase(arr.begin() + curr); // Remove the element
    return solve(arr, curr, k);    // Recursive call with updated `curr`
}

int safePos(int n, int k) {
    vector<int> arr;
    for (int i = 1; i <= n; i++) {
        arr.push_back(i); // Populate the array with 1 to n
    }
    return solve(arr, 0, k - 1); // Start the recursion
}

};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends