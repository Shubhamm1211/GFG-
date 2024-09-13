//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int>pos,neg;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=0)pos.push_back(arr[i]);
            else neg.push_back(arr[i]);
        }
        int p=0;
        int n=0;
        vector<int>ans;
        while(p<pos.size() and n<neg.size()){
            ans.push_back(pos[p]);
            ans.push_back(neg[n]);
            p++;
            n++;
        }
        while(p<pos.size()){
            ans.push_back(pos[p]);
            p++;
        }
        while(n<neg.size()){
            ans.push_back(neg[n]);
            n++;
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=ans[i];
        }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends