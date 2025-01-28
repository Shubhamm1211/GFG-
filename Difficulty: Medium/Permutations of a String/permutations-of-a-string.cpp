//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(string &s,int ind, set <string> &ans){
        if(ind == s.size() - 1){
            ans.insert(s);
            return;
        }
        for(int i = ind; i < s.size(); i++){
            swap(s[i],s[ind]);
            solve(s,ind + 1,ans);
            swap(s[ind],s[i]);
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        set <string> ans;
        solve(s,0,ans);
        vector <string> res;
        for(auto &x : ans){
            res.push_back(x);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends