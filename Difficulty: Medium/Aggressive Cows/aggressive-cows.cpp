//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool solve(vector <int> &v, int k, int mini){
        int temp = v[0];
        int cnt = 1;
        for(int i = 1; i < v.size(); i++){
            if(v[i] - temp >= mini){
                cnt++;
                temp = v[i];
            }
        }
        return cnt >= k;
    }
    int aggressiveCows(vector<int> &v, int k) {

        // Write your code here
        sort(begin(v), end(v));
        int low = 1;
        int high = v.back();
        int ans = -1;
        while(low <= high){
            int mid = high - ((high - low) / 2);
            if(solve(v,k,mid)){
                low = mid + 1;
                ans = mid;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends