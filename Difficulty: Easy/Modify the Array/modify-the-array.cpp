//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        // Complete the function
        int n = arr.size();
        for(int i = 0; i < n - 1; i++){
            if(arr[i] == arr[i + 1] and arr[i] != 0){
                arr[i] = arr[i] * 2;
                arr[i + 1] = 0;
            }
        }
        vector <int> ans;
        for(auto x: arr){
            if(x != 0){
            ans.push_back(x);
            }
        }
        int k = ans.size();
        for(int i = ans.size(); i < n; i++){
            ans.push_back(0);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends