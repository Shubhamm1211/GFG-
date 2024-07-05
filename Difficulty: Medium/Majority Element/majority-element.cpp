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
    int majorityElement(int arr[], int n)
    {
        int elem,cnt=0,cnt2=0;
        // your code here
        for(int i=0;i<n;i++){
            if(cnt==0){
            elem=arr[i];
            cnt++;
            }
            else if(arr[i]==elem)cnt++;
            else cnt--;
            
        }
        for(int i=0;i<n;i++){
            if(arr[i]==elem)cnt2++;
        }
        if(cnt2>(n/2))return elem;
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