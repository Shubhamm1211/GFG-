//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      unordered_set<int>st;
      int maxi=INT_MIN,cnt=0;
      for(int i=0;i<n;i++){
          st.insert(arr[i]);
      }
      for(auto x:st){
          if(st.find(x-1)==st.end()){
              cnt=1;
              int t2=x;
              while(st.find(t2+1)!=st.end()){
                  cnt++;
                  t2++;
              }
              maxi=max(maxi,cnt);
          }
      }
      return maxi;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends