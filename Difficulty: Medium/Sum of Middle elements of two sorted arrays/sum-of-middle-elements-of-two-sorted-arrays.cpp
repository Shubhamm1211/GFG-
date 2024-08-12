//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        int i=0,j=0;
        int n1=arr1.size(),n2=arr2.size();
        vector<int>temp;
        while(i<n1 and j<n2){
            if(arr1[i]<arr2[j]){
                temp.push_back(arr1[i]);
                i++;
            }
            else if(arr1[i]>arr2[j]){
                temp.push_back(arr2[j]);
                j++;
            }
            else {
                temp.push_back(arr2[j]);
                temp.push_back(arr1[i]);
                i++;
                j++;
            }
        }
        while(i<n1){
                temp.push_back(arr1[i]);
                i++;
            }
            while(j<n2){
                temp.push_back(arr2[j]);
                j++;
            }
            // for(auto x:temp)cout<<x<<" ";// 1 2 4 5 6 9 10 12 5
        int mid=temp.size()/2;
            return (temp[mid]+temp[mid-1]);
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends