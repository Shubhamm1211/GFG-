//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int arr[], int n)
    {
        // code here 
        int cz=0,co=0,ct=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0)cz++;
            else if(arr[i]==1)co++;
            else ct++;
        }
        int i;
        for(i=0;i<cz;i++){
            arr[i]=0;
        }
        for(;i<co+cz;i++){
            arr[i]=1;
        }
        for(;i<ct+co+cz;i++){
            arr[i]=2;
        }
        
        
        
    }
    
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends