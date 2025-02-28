//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int n1, int n2, string op){
        if(op == "+"){
            return n2 + n1;
        }
        else if(op == "*"){
            return n2 * n1;
        }
        else if(op == "-"){
            return n2 - n1;
        }
        else return n2 / n1;
    }
    int evaluate(vector<string>& arr) {
        // code here
        stack <string> st;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == "+" or arr[i] == "-" or arr[i] == "*" or arr[i] == "/"){
                int st1 = stoi(st.top());
                st.pop();
                int st2 = stoi(st.top());
                st.pop();
                int ans = solve(st1,st2,arr[i]);
                st.push(to_string(ans));
            }
            else st.push(arr[i]);
        }
        int ans = stoi(st.top());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends