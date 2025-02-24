//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        int n = arr.size();
        vector <int> ans;
        stack <pair <int,int>> st;
        st.push({arr[0],1});
        ans.push_back(1);
        for(int i = 1; i < n; i++){
            int cnt = 1;
            while(!st.empty() and st.top().first <= arr[i]){
                cnt += st.top().second;
                st.pop();
            }
            st.push({arr[i],cnt});
            ans.push_back(cnt);
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
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends