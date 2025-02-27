//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    bool solve(vector <int> &arr, int k, int mid){
        int n = arr.size();
        int cnt = 1;
        int curr = 0;
        for(int i = 0; i < n; i++){
            curr += arr[i];
            if(curr > mid){
                cnt++;
                curr = arr[i];
            }
        }
        return cnt <= k;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        // return minimum time
        int n = arr.size();
        int low = *max_element(begin(arr), end(arr)), high = 1e8;
        int ans = -1;
        while(low <= high){
            int mid = low + ((high - low) / 2);
            if(solve(arr,k,mid)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.minTime(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends