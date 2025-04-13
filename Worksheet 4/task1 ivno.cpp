#include <iostream>
using namespace std;

class Node

{

public:

    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
private:

    Node* head;

public:
    LinkedList() : head(nullptr) {}


    void insertAtStart(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // 1. Insert at the end
    void insertAtEnd(int val)
    {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void insertAtPosition(int pos, int val)

     {
        if (pos == 0)

        {

            insertAtStart(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 0; temp && i < pos - 1; ++i)
            temp = temp->next;

        if (!temp)
            {

                cout << "Position out of bounds.\n";
                return;
            }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display()

    {
        Node* temp = head;
        cout << "Linked List: ";

        while (temp)

            {
                cout << temp->data << " ";
                temp = temp->next;
            }

        cout << endl;
    }

    void detectAndRemoveLoop()

    {
        Node *slow = head, *fast = head;

        while (fast && fast->next)

            {

                slow = slow->next;
                fast = fast->next->next;

            if (slow == fast)

                {
                    cout << "Loop is detected. Removing..\n";

                    removeLoop(slow);
                    return;
                }
        }

        cout << "No loop is detected.\n";
    }

    void removeLoop(Node* loopNode)

    {
        Node* ptr1 = head;
        Node* ptr2;

        while (true)

            {
                ptr2 = loopNode;

                while (ptr2->next != loopNode && ptr2->next != ptr1)

                    ptr2 = ptr2->next;

            if (ptr2->next == ptr1)
                break;

            ptr1 = ptr1->next;
        }

        ptr2->next = nullptr;
    }

    void findNthFromEnd(int n)

    {
        Node *mainPtr = head, *refPtr = head;

        for (int i = 0; i < n; ++i)

            {
                if (!refPtr)

                    {
                        cout << "N is greater than list length.\n";

                        return;
                    }

            refPtr = refPtr->next;
        }

        while (refPtr)

            {
                mainPtr = mainPtr->next;
                refPtr = refPtr->next;
            }

        cout << "The " << n << "The node from end is: " << mainPtr->data << endl;
    }

    Node* reverseInGroups(Node* node, int k)

    {
        Node* prev = nullptr;
        Node* curr = node;
        Node* next = nullptr;
        int count = 0;

        while (curr && count < k)

            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;

                count++;
            }

        if (next)

            node->next = reverseInGroups(next, k);

        return prev;
    }

    void reverseGroups(int k)

    {

        head = reverseInGroups(head, k);
        cout << "Reserved lists in groups of " << k << ".\n";
    }

    void createLoop()

    {
        if (!head) return;

        Node* temp = head;

        while (temp->next)
            temp = temp->next;

        temp->next = head->next;
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.insertAtPosition(3, 25);
    list.insertAtStart(5);
    list.display();

    list.findNthFromEnd(3);

    list.reverseGroups(3);
    list.display();

    list.createLoop();
    list.detectAndRemoveLoop();
    list.display();

    return 0;
}

