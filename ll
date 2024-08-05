#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int d, Node *n) {
        data = d;
        next = n;
    }

    explicit Node(int d) {
        data = d;
        next = nullptr;
    }
};

bool searchKey(int n, struct Node *head, int key) {
    while(head != nullptr) {
        if(key == head->data)return true;
        head = head->next;
    }
    return false;
}


int main() {
    Node *a = new Node(2200);
    Node *current = a;
    current->next = new Node(8800);
    current = current->next;
    cout << a->next->data << " " << current->data << endl;
    cout << searchKey(2, a, 2200) << " " << searchKey(2, a, 2209);
    return 0;
}
