//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:


string roundToNearest(string str) 
{
    int n = str.size() - 1;
    int last = str[n] - '0';

    if(last == 0) {
        return str;
    }

    if(last <= 5) {
        str[n] = '0';
        return str;
    }

    str[n] = '0';
    int i = 1;

    while(n - i >= 0 && str[n - i] == '9') {
        str[n - i] = '0';
        i++;
    }

    if(n - i < 0) {
        str = '1' + str;
    } else {
        str[n - i] = str[n - i] + 1;
    }

    return str;
}

};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends