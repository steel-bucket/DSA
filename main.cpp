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

    return 0;
}
