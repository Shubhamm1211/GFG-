//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void rotate(std::vector<int>& arr) {
    if(arr.size() > 1) {
        int temp = arr.back();  
        arr.pop_back();         
        arr.insert(arr.begin(), temp);  
    }
}
    void del(vector<int>&arr, int k){
        int n = arr.size();
        int ind = n - k;
        if(ind < 0){
            ind = 0;
        }
        arr.erase(arr.begin() + ind);
    }
    int rotateDelete(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        int k = 1;
        while(n > 1){
            rotate(arr);
            del(arr,k);
            k++;
            n--;
        }
        return arr[0];
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
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends