//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector <int> pre(n), suff(n);
        pre[0] = arr[0];
        suff[n - 1] = arr[n - 1];
        for(int i = 1; i < n; i++){
            pre[i] = pre[i - 1] + arr[i];
        }
        for(int i = n - 2; i >= 0; i--){
            suff[i] = suff[i + 1] + arr[i]; 
        }
        for(int i = 0; i < n; i++){
            if(pre[i] == suff[i]){
                return i;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends