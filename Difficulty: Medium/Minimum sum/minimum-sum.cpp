//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
#define ll long long
class Solution {
  public:
    string minSum(vector<int> &arr) {
        string ans;
        int carry = 0;
        sort(arr.begin(), arr.end());
        for(int i = arr.size() - 1; i >= 0; i -= 2) {
            int curr = arr[i] + carry + (i > 0 ? arr[i - 1] : 0);
            carry = curr/10;
            ans.push_back('0' + curr%10);
        }
        if(carry) ans.push_back('0' + carry);
        while(ans.size() > 1 && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends