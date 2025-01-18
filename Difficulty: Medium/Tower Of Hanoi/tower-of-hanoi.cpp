//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // You need to complete this function
    void solve(int n, int from, int to, int aux, int &ans){
        if(n == 0){
            return;
        }
        if(n == 1){
            ans++;
            return;
        }
        solve(n - 1, from,aux,to,ans);
        ans++;
        solve(n - 1, aux, to, from,ans);
    }
    int towerOfHanoi(int n, int from, int to, int aux) {
        // Your code here
        int ans = 0;
        solve(n,from,to,aux,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T; // testcases
    while (T--) {

        int N;
        cin >> N; // taking input N

        // calling toh() function
        Solution ob;

        cout << ob.towerOfHanoi(N, 1, 3, 2) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends