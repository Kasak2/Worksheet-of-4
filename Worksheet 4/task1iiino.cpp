#include <iostream>
using namespace std;

#define MAX_SIZE 15

class Queue

{

private:

    int arr[MAX_SIZE];
    int front, rear, size;

public:
    Queue()

    {
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isFull()

    {
        return size == MAX_SIZE;
    }

    bool isEmpty()

    {
        return size == 0;
    }

    void enqueue(int val)

    {
        if (isFull())

            {
                cout << "Queue overflow! Cannot enqueue " << val << endl;
                return;
            }

            rear = (rear + 1) % MAX_SIZE;
            arr[rear] = val;

            size++;
        }

    int dequeue()

    {
        if (isEmpty())

            {
                cout << "Queue underflow! Nothing to dequeue." << endl;
                return -1;
            }

        int val = arr[front];
        front = (front + 1) % MAX_SIZE;
        size--;
        return val;
    }

    void display()

     {
        if (isEmpty())
            {
                cout << "Queue is empty.\n";
                return;
            }

        cout << "Queue: ";

        for (int i = 0; i < size; ++i)

            {

                cout << arr[(front + i) % MAX_SIZE] << " ";
            }

        cout << endl;
    }

    void reverseFirstK(int k)

    {
        if (k > size || k <= 0)

            {

                cout << "Invalid value of K.\n";
                return;

            }

        int temp[MAX_SIZE];
        for (int i = 0; i < k; ++i)
            {

                temp[i] = dequeue();
            }

        for (int i = k - 1; i >= 0; --i)

            {

                enqueue(temp[i]);
            }

        int rotate = size - k;
        for (int i = 0; i < rotate; ++i)

            {

                enqueue(dequeue());
            }

        cout << "First " << k << " elements reversed.\n";
    }

    void interleaveQueue()

    {
        if (size % 2 != 0)

            {

                cout << "Interleave requires even number of elements.\n";

                return;
            }

        int half = size / 2;

        int temp[MAX_SIZE];

        for (int i = 0; i < size; ++i)


        {

            temp[i] = dequeue();
        }

        for (int i = 0; i < half; ++i)

            {

                enqueue(temp[i]);
                enqueue(temp[i + half]);

            }

        cout << "Queue interleaved.\n";
    }
};

int main()

{
    Queue q;

    for (int i = 0; i <= 13; ++i)
        q.enqueue(i);

    q.display();

    q.reverseFirstK(5);
    q.display();

    q.interleaveQueue();
    q.display();

    return 0;
}


