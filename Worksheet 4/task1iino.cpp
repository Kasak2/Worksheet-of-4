#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

class SmartStack
 {
    int data[MAX_SIZE];
    int top;

public:
    SmartStack() {
        top = -1;
    }

    void push(int value)
    {
        if (top < MAX_SIZE - 1) {
            top++;
            data[top] = value;
            cout << "Pushed: " << value << endl;
        } else {
            cout << "Stack is full" << endl;
        }
    }

    void pop()
    {
        if (top >= 0) {
            cout << "Popped: " << data[top] << endl;
            top--;
        } else {
            cout << "Stack is empty" << endl;
        }
    }

    void show()
     {
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void findMiddle()
    {
        if (top >= 0) {
            int mid = top / 2;
            cout << "Middle Element: " << data[mid] << endl;
        } else {
            cout << "Stack is empty" << endl;
        }
    }

    void reverseBottomHalf()
     {
        if (top < 1) {
            cout << "Not enough elements to reverse bottom half" << endl;
            return;
        }
        int mid = top / 2;
        for (int i = 0, j = mid; i < j; i++, j--) {
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
        cout << "Bottom half reversed" << endl;
    }
};

int main()
{
    SmartStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.push(70);
    stack.push(80);
    stack.push(90);
    stack.push(100);

    stack.show();

    stack.findMiddle();
    stack.reverseBottomHalf();
    stack.show();

    stack.pop();
    stack.show();

    return 0;
}

