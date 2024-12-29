//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // code here
        set <int> st1(begin(a), end(a));
        set <int> st2(begin(b), end(b));
        set <int> ans;
        vector <int> v;
        for(int i = 0; i < a.size(); i++){
            if(st2.count(a[i]) and ans.count(a[i]) == 0){
                v.push_back(a[i]);
            }
        }
        for(int i = 0; i < b.size(); i++){
            if(st1.count(b[i]) and ans.count(b[i]) == 0){
                v.push_back(b[i]);
            }
        }
        set <int> t(begin(v), end(v));
        vector <int> aa;
        for(auto it : t){
            aa.push_back(it);
        }
        return aa;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1, arr2;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Solution ob;
        vector<int> res = ob.intersectionWithDuplicates(arr1, arr2);
        sort(res.begin(), res.end());

        if (res.size() == 0) {
            cout << "[]" << endl;
        } else {
            for (auto it : res)
                cout << it << " ";
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends