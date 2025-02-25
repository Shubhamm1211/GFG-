//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool solve(vector <int> &arr, int k, int maxi){
        int cnt = 1;
        int sum = 0;
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
            if(sum > maxi){
                cnt++;
                sum = arr[i];
            }
        }
        return cnt <= k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int high = accumulate(begin(arr), end(arr), 0);
        int low = *max_element(begin(arr), end(arr));
        int ans = -1;
        if(arr.size() < k) return -1;
        while(low <= high){
            int mid = high - ((high - low) / 2);
            if(solve(arr,k,mid)){
                high = mid - 1;
                ans = mid;
            }
            else low = mid + 1;
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

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends