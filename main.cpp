#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node() : val(0), next(nullptr), random(nullptr) {
    };

    explicit Node(int x) : val(x), next(nullptr), random(nullptr) {
    }

    Node(int x, Node *nextNode, Node *randomNode) : val(x), next(nextNode), random(randomNode) {
    }
};

void insertcopy(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        Node *nextElement = temp->next;
        Node *copy = new Node(temp->val);
        copy->next = nextElement;
        temp->next = copy;
        temp = nextElement;
    }
}

void connectrandompointers(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        Node *copyNode = temp->next;
        if (temp->random) {
            copyNode->random = temp->random->next;
        } else {
            copyNode->random = nullptr;
        }
        temp = temp->next->next;
    }
}

Node *getDeepCopyList(Node *head) {
    Node *temp = head;
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;

    while (temp != nullptr) {
        res = res->next;
        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dummyNode->next;
}

Node *copyRandomList(Node *head) {
    if (!head) return nullptr;
    insertcopy(head);
    connectrandompointers(head);
    return getDeepCopyList(head);
}

void printClonedLinkedList(Node *head) {
    while (head != nullptr) {
        cout << "Data: " << head->val;
        if (head->random != nullptr) {
            cout << ", Random: " << head->random->val;
        } else {
            cout << ", Random: nullptr";
        }
        cout << endl;
        head = head->next;
    }
}

int main() {
    Node *head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;
    cout << "Original Linked List with Random Pointers:" << endl;
    printClonedLinkedList(head);
    Node *clonedList = cloneLL(head);

    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printClonedLinkedList(clonedList);

=======
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
