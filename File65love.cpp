// queue
#include<iostream>
#include<queue>
using namespace std;

class Queue{
    int* arr;
    int qfront;
    int rear;
    int size;

    public:
    Queue()
    {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    // Time Complexity = O(1)
    bool isEmpty()
    {
        if(qfront == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Time Complexity = O(1)
    void enqueue(int data)
    {
        if(rear == size)
        {
            cout<<"Queue is Full"<<endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    // Time Complexity = O(1)
    int dequeue()
    {
        if(qfront == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    // Time Complexity = O(1)
    int front()
    {
        if(qfront == rear)
        {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }



};

int main()
{
    // stl queue
    queue<int> q;
    q.push(11); // pushes 11 in back of queue
    cout<<"front of q is: "<<q.front()<<endl; // gives front element
    q.push(15);
    cout<<"front of q is: "<<q.front()<<endl;
    q.push(13);
    cout<<"front of q is: "<<q.front()<<endl;
    cout<<"size of queue is : "<<q.size()<<endl;
    q.pop();
    cout<<"front of q is: "<<q.front()<<endl;
    cout<<"size of queue is : "<<q.size()<<endl;
    if(q.empty())
    {
        cout<<"Queue is empty "<<endl;
    }
    else
    {
        cout<<"queue is not empty "<<endl;
    }
    return 0;
}