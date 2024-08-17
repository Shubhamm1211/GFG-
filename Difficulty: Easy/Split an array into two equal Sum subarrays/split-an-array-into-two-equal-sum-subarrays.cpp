//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    bool canSplit(vector<int>& arr) {
    int n = arr.size();
    if (n < 2) return false;  // If the array has less than 2 elements, it cannot be split

    int i = 0, j = n - 1;
    int lsum = arr[i], rsum = arr[j];

    while (i < j) {
        if (lsum == rsum && i + 1 == j) return true;  // If sums are equal and pointers are adjacent
        if (lsum < rsum) {
            i++;
            lsum += arr[i];
        } else {
            j--;
            rsum += arr[j];
        }
    }

    return false;
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends