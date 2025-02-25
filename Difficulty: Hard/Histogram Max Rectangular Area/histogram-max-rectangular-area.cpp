//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        vector <int> nsl(n), nsr(n);
        stack <pair<int,int>> st;
        for(int i = 0; i < n; i++){
            if(st.empty()){
                nsl[i] = -1;
            }
            else{
                while(!st.empty() and st.top().second >= arr[i]){
                    st.pop();
                }
                if(st.empty()) nsl[i] = -1;
                else nsl[i] = st.top().first;
            }
            st.push({i,arr[i]});
        }
        stack <pair<int,int>> st2;
        for(int i = n - 1; i >= 0; i--){
            if(st2.empty()){
                nsr[i] = n;
            }
            else{
                while(!st2.empty() and st2.top().second >= arr[i]){
                    st2.pop();
                }
                if(st2.empty()) nsr[i] = n;
                else nsr[i] = st2.top().first;
            }
            st2.push({i,arr[i]});
        }
        int maxi = 0;
        // for(auto &x : nsr) cout << x << " ";
        // cout << endl;
        // for(auto &x : nsl) cout << x << " ";
        // cout << endl;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, arr[i] * (nsr[i] - nsl[i] - 1));
        }
        return maxi;
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
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends