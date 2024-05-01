//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    bool isv(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')return true;
        else return false;
    }
    struct Node* arrangeCV(Node* head) {
        // Code here
        Node*n=head;
        vector<char>v;
        vector<char>c;
        while(n!=NULL){
            if(isv(n->data))v.push_back(n->data);
            else c.push_back(n->data);
            n=n->next;
        }
        int i=0,j=0;
        int t=v.size()+c.size();
        Node*n2=head;
        while(i<v.size()&&n2!=NULL){
            n2->data=v[i];
            i++;
            n2=n2->next;
        }
        while(j<c.size()&&n2!=NULL){
            n2->data=c[j];
            j++;
            n2=n2->next;
        }
        return head;
        
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends