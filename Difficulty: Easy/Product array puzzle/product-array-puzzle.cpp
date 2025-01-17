//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n = arr.size();
        int cnt0 = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == 0) cnt0++;
        }
        if(cnt0 >= 2){
            vector <int> ans(n,0);
            return ans;
        }
        if(cnt0 == 1){
            int pro = 1;
            int ind = -1;
            for(int i = 0; i < n; i++){
                if(arr[i] == 0){
                    ind = i;
                    continue;
                }
                pro *= arr[i];
            }
            vector <int> ans(n,0);
            ans[ind] = pro;
            return ans;
        }
        vector <int> ans(n);
        int pro = 1;
        for(int i = 0; i < n; i++){
            pro *= arr[i];
        }
        for(int i = 0; i < n; i++){
            ans[i] = pro / arr[i];
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

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
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends