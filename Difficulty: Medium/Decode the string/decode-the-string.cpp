//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack <string> st;
        stack <int> stnum;
        int i = 0;
        while(i < s.size()){
            if(s[i] <= '9' and s[i] >= '0'){
                int curr = i;
                string temp = "";
                while(s[curr] <= '9' and s[curr] >= '0'){
                    temp += s[curr];
                    curr++;
                }
                int num = stoi(temp);
                stnum.push(num);
                i = curr;
            }
            else if((s[i] <= 'z' and s[i] >= 'a') or s[i] == '['){
                st.push(string(1,s[i]));
                i++;
            }
            else{
                string temp = "";
                while(!st.empty() and st.top() != "["){
                    temp = st.top() + temp;
                    st.pop();
                }
                string ans = "";
                int t = (!stnum.empty()) ? stnum.top() : 0;
                stnum.pop();
                for(int i = 0; i < t; i++){
                    ans = ans + temp;
                }
                st.pop();
                st.push(ans);
                i++;
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends