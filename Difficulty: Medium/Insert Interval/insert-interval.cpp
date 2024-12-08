//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &arr,
                                       vector<int> &neww) {
        // code here
        arr.push_back(neww);
        int n = arr.size();
        sort(begin(arr),end(arr));
        vector<vector<int>> ans;
        ans.push_back({arr[0][0], arr[0][1]});
        for(int i = 1;i < n; i++){
            int st = arr[i][0];
            int et = arr[i][1];
            
            if(ans.back()[1] >= st){
                ans.back()[1] = max(ans.back()[1], et);
            }
            else{
                ans.push_back({st,et});
            }
        }
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
        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        vector<int> newInterval(2);
        cin >> newInterval[0] >> newInterval[1];

        Solution obj;
        vector<vector<int>> ans = obj.insertInterval(intervals, newInterval);
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[" << ans[i][0] << ',' << ans[i][1] << ']';
            if (i != (ans.size() - 1))
                cout << ",";
        }
        cout << "]" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends