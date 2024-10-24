//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(vector<int> &arr, int &sum, int ind, vector<int> &ans){
        for(int j = ind; j < arr.size(); j++){
            sum += arr[j];
            solve(arr,sum, j + 1, ans);
            sum -= arr[j];
        }
        ans.push_back(sum);
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector <int> ans;
        int sum = 0;
        solve(arr, sum, 0, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends