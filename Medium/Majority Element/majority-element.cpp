//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
int majorityElement(int arr[], int size)
    {
        int l,max=0;
    unordered_map<int, int> mp;
    for (int i = 0; i < size; i++)
        mp[arr[i]]++;
    for (auto x : mp)
        {
            if(x.second>max){
                max=x.second;
                l=x.first;
            }
        }
        if(max>(size/2))
        return l;
        else 
        return -1;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends