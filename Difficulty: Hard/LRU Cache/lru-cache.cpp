//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  private:
  public:
    int n;
    list <int> dll;
    map <int, pair <list <int> :: iterator, int >> mp;
    
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        // code here
        n = cap;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // your code here
        if(mp.find(key) == mp.end()){
            return -1;
        }
        else{
            dll.erase(mp[key].first);
            dll.push_front(key);
            mp[key].first = dll.begin();
            return mp[key].second;
        }
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
        if(mp.find(key) != mp.end()){
            mp[key].second = value;
            dll.erase(mp[key].first);
            dll.push_front(key);
            mp[key].first = dll.begin();
        }
        else{
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;
        }
        if(n < 0){
            int delkey = dll.back();
            mp.erase(delkey);
            dll.pop_back();
            n++;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends