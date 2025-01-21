//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void solve(string ip, string op, vector <string> &ans){
    if(ip.size() == 0){
        ans.push_back(op);
        return;
    }
    set <char> st;
    for(int i = 0; i < ip.size(); i++){
        if(st.find(ip[i]) != st.end()) continue; // Controled recursion
        string opi = op;
        string ipi = ip;
        opi += ipi[i];
        ipi.erase(ipi.begin() + i);
        st.insert(ip[i]);
        solve(ipi,opi,ans);
    }
}
    vector<string> findPermutation(string &s) {
        // Code here there
        vector <string> ans;
        string op = "";
        solve(s,op,ans);
        return ans;
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