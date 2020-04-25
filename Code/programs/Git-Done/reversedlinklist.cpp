/*
 * File: 
 */


#include <iostream>
#include <cmath>

using namespace std;

struct node {
    int data;
    node *next;
};

void firstnode(node *root) {
    cout << "Enter the list: " << endl;
    cin >> root->data;
    root->next = NULL;
}

void l(node *root, node *current, int n) {
    current = root;
    for ( int i=0; i<n-1 ; i++) {
        current->next = new node;
        current = current->next; 
        cin >> current->data;
    }
    current->next=NULL;
}

void reversel(node **head_ref)
{
    node *prev = NULL;
    node *current = *head_ref;
    node *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void print(node *root, node *current) {
    current = root;
    while ( current->next != NULL) {
        cout << current->data << "  ";
        current = current->next;
    }
    cout << current->data << endl;
}

int main() {
    node *root;
    root = new node;
    node *current;
    cout << "Please enter the number of nodes in your linked list: " << endl;
    int n;
    cin >> n;
    if (n <= 0) {
        cout << "The number of nodes in a linked list should be greater than zero. Please enter the number again: " << endl;
        cin >> n;
    }
    cout << endl;
    firstnode(root);
    l(root, current, n);
    cout << endl << "This is the current list: " << endl;
    print(root, current);
    reversel(&root);
    cout << endl << "This is the reversed list: " << endl;
    print(root, current);
}
