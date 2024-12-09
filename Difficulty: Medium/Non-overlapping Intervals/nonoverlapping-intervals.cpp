//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1]; 
}
class Solution {
  public:
  
    int minRemoval(vector<vector<int>> &v) {
        // code here
        int n = v.size();
        sort(v.begin(), v.end(), cmp);
        int st = v[0][0];
        int et = v[0][1];
        int ans = 0;
        for(int i = 1; i < n; i++){
            int cst = v[i][0];
            int cet = v[i][1];
            if(cst < et){
                ans++;
            }
            else{
                st = cst;
                et = cet;
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
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends