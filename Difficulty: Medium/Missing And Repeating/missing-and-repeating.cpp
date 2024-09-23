//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>v (n+1,0);
        for(int i = 0; i < n; i++){
            v[arr[i]]++;
        }
        vector<int>ans;
        for(int i = 1; i <= n; i++){
            if(v[i]==2){
                ans.push_back(i);
            }
        }
        for(int i = 1; i <= n; i++){
            if(v[i]==0){
                ans.push_back(i);
            }
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends