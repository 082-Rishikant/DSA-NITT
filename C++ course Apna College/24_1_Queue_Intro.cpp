#include <iostream>
using namespace std;

#define n 6
class queue
{
    int front = -1;
    int back = -1;
    // int arr[n];
    int* arr=new int[n];

public:
    void enqueue(int d)
    {
        if (back==n-1)
        {
            cout<<"ENQUEUE FULL!\n";
            return;
        }
        back++;
        arr[back]=d;
    }
    void dequeue()
    {
        if(front>=back)
        {
            cout<<"DEQUEUE EMPTY!\n";
            return;
        }
        cout<<"DELETED!\n";
        front++;
    }
    int peek()
    {
        if(front>=back)
        {
            cout<<"PEEK EMPTY!\n";
            return -1;
        }
        return arr[front+1];
    }
    bool empty()
    {
        if(front>=back)
        {
            return 1;
        }
        return 0;
    }
};

int main()
{
    queue q;
    // q.enqueue(6);
    // q.enqueue(3);
    // q.enqueue(1);
    // q.enqueue(1);
    // q.enqueue(10);
    
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    cout<<q.peek()<<endl;

    cout<<q.empty()<<endl;
    return 0;
}