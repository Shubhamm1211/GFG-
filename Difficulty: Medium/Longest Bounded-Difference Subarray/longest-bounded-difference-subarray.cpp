//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
    int n = arr.size();
    int i = 0, j = 0;
    int start = -1;
    int maxi = 0; // Use 0 since empty subarrays shouldn't be considered
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minpq;
    priority_queue<pair<int,int>> maxpq;

    while (j < n) {
        minpq.push({arr[j], j});
        maxpq.push({arr[j], j});

        // Calculate the current difference between max and min in window
        int diff = maxpq.top().first - minpq.top().first;

        // Shrink window if diff exceeds x
        while (!minpq.empty() && !maxpq.empty() && diff > x) {
            i++;
            while (!minpq.empty() && minpq.top().second < i) {
                minpq.pop();
            }
            while (!maxpq.empty() && maxpq.top().second < i) {
                maxpq.pop();
            }
            if (!minpq.empty() && !maxpq.empty()) {
                diff = maxpq.top().first - minpq.top().first;
            }
        }

        // Update maximum length subarray
        int len = j - i + 1;
        if (len > maxi) {
            maxi = len;
            start = i;
        }
        j++;
    }

    // Build the result array
    vector<int> ans;
    for (int k = start; k < start + maxi; k++) {
        ans.push_back(arr[k]);
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends