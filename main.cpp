
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int d, Node *n) { data = d, next = n; }
    explicit Node(int d) { data = d, next = nullptr; }
};

struct ListNode {
    int data;
    ListNode *next;
    ListNode(int d, ListNode *n) { data = d, next = n; }
    explicit ListNode(int d) { data = d, next = nullptr; }
};

Node *segregate(Node *head) {
    Node *zero = nullptr;
    Node *one = nullptr;
    Node *two = nullptr;
    Node *zerogoing = nullptr;
    Node *onegoing = nullptr;
    Node *twogoing = nullptr;
    auto c = head;
    while (c != nullptr) {
        auto n = c->next;
        if (c->data == 0) {
            if (zerogoing == nullptr) {
                zerogoing = c;
                zero = c;
                c->next = nullptr;
            } else {
                zerogoing->next = c;
                zerogoing = zerogoing->next;
                c->next = nullptr;
            }
        } else if (c->data == 1) {
            if (onegoing == nullptr) {
                onegoing = c;
                one = c;
                c->next = nullptr;
            } else {
                onegoing->next = c;
                onegoing = onegoing->next;
                c->next = nullptr;
            }
        } else {
            if (twogoing == nullptr) {
                twogoing = c;
                two = c;
                c->next = nullptr;
            } else {
                twogoing->next = c;
                twogoing = twogoing->next;
                c->next = nullptr;
            }
        }
        c = n;
    }
    if (zero != nullptr) {
        head = zero;
        zerogoing->next = one;
        if (one != nullptr) {
            onegoing->next = two;
        } else if (two != nullptr) {
            zerogoing->next = two;
        }
    } else if (one != nullptr) {
        head = one;
        onegoing->next = two;
    } else {
        head = two;
    }
    return head;
}


int main() {
    Node *head = new Node(1, new Node(2, new Node(
                                          2, new Node(
                                              1, new Node(
                                                  2, new Node(
                                                      0, new Node(
                                                          1, new Node(2, new Node(0, new Node(1, new Node(0)))))))))));
    head = segregate(head);
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}
