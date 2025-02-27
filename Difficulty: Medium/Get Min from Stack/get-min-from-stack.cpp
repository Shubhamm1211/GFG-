//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    Solution() {
        // code here
    }
    stack <pair<int,int>> st;
    // Add an element to the top of Stack
    void push(int x) {
        // code here
        if(st.empty()){
            st.push({x,x});
        }
        else{
            int temp = st.top().second;
            st.push({x,min(x,temp)});
        }
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(!st.empty()) st.pop();
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if(!st.empty()){
            return st.top().first;
        }
        else return -1;
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(!st.empty()){
            return st.top().second;
        }
        else return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends