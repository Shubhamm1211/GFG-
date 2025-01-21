//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node* solve(Node* head, int k, int tot, bool lastGrp = false) {
    // Base case
    if(!head) return head;
    if(tot == 0 && !lastGrp) return head;
    
    // Store the next group's head
    Node *curr = head;
    Node *next_group = NULL;
    int count = 0;
    
    // Move k steps to find next group's head
    while(curr && count < k) {
        next_group = curr->next;
        curr = curr->next;
        count++;
    }
    
    // Reverse current group
    Node *prev = NULL;
    curr = head;
    count = 0;
    while(curr && count < k) {  // This will handle the last group automatically
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    // Connect with next reversed group
    if(next_group) {
        head->next = solve(next_group, k, tot-1, lastGrp);
    }
    
    return prev;  // prev is new head of reversed group
}

Node* reverseKGroup(Node* head, int k) {
    if(!head || k == 1) return head;
    
    // Count total nodes
    int n = 0;
    Node* temp = head;
    while(temp) {
        n++;
        temp = temp->next;
    }
    
    int tot = n/k;  // Number of groups to reverse
    int left = n % k;
    
    // Get to last complete group
    Node* last = head;
    temp = head;
    for(int i = 0; i < tot*k; i++) {
        last = temp;
        temp = temp->next;
    }
    
    // If remaining nodes exist, reverse them too
    if(left > 0) return solve(head, k, tot, true);
    
    return solve(head, k, tot, false);
}
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends