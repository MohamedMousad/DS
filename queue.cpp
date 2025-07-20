#include <bits/stdc++.h>
using namespace std;
class Queue
{
private:
    int size{};
    int front{};
    int rear{};
    int added_elements{};
    int *array{};

public:
    Queue(int size) : size(size)
    {
        array = new int[size];
    }
    ~Queue()
    {
        delete[] array;
    }
    int front_val()
    {
        return array[front];
    }
    int prev(int pos)
    {
        added_elements--;
        if (pos == 0)
            return size - 1;
        return pos - 1;
    }
    int next(int pos)
    {
        return (pos + 1) % size;
    }
    bool is_empty()
    {
        return added_elements == 0;
    }
    bool is_full()
    {
        return added_elements == size;
    }
    void enqueue(int value)
    {
        assert(!is_full());
        array[rear] = value;
        rear = next(rear);
        added_elements++;
    }
    int dequeue()
    {
        assert(!is_empty());
        int value = array[front];
        front = next(front);
        added_elements--;
        return value;
    }
    void display()
    {
        cout << "Front: " << front << ", Rear: " << rear << "\t";
        if (is_full())
            cout << "Full ";
        else if (is_empty())
        {
            cout << "Empty\n";
            return;
        }
        cout << '\n';
        for (int i = front, step = 0; step < added_elements; i = next(i))
        {
            cout << array[i] << " ";
        }
        cout << "\n\n";
    }
    void enqueue_front(int value)
    {
        assert(!is_full());
        front--;
        array[front] = value;
        added_elements++;
    }
    int dequeue_rear()
    {
        assert(!is_empty());
        int value = array[rear];
        prev(rear);
        return value;
    }
};
class Stack
{
    Queue queue;
    int added_elements{};

public:
    void push(int value)
    {
        queue.enqueue_front(value);
        added_elements++;
    }
    int peek()
    {
        return queue.front_val();
    }
    int pop()
    {
        assert(!queue.is_empty());
        added_elements--;
        return queue.dequeue();
    }
};
class Priority_queue
{
    Queue queue1, queue2, queue3;

public:
    Priority_queue(int size) : queue1(size), queue2(size), queue3(size)
    {
    }
    void enqueue(int value, int priority)
    {
        if (priority == 1)
        {
            queue1.enqueue(value);
        }
        else if (priority == 2)
        {
            queue2.enqueue(value);
        }
        else if (priority == 3)
        {
            queue3.enqueue(value);
        }
    }
    int dequeue()
    {
        assert(!queue1.is_empty() || !queue2.is_empty() || !queue3.is_empty());
        if (!queue3.is_empty())
            return queue3.dequeue();
        else if (!queue2.is_empty())
            return queue2.dequeue();
        else
            return queue1.dequeue();
    }
};
// implementing queue without added elements variable
class Queue2
{
    int front = 0;
    int rear = 0;
    int *arr {};
    int size = 0;

public:
    Queue2(int size) : size(size)
    {
        arr = new int[size];
        arr[0] = -INT_MAX;
    }
    ~Queue2()
    {
        delete[] arr;
    }
    bool is_empty()
    {
        return arr[front] == -INT_MAX && front == rear;
    }
    bool is_full()
    {
        return arr[front] != -INT_MAX && front == rear;
    }
    int front_val()
    {
        if (!is_empty())
            return arr[front];
    }
    int next(int pos)
    {
        if (pos == size-1)
            return 0;
        else 
            return pos+1;
    }
    void enqueue(int value)
    {
        assert(!is_full());
        arr[rear] = value;
        rear = next(rear);
    }
    int dequeue()
    {
        assert(!is_empty());
        int value = arr[front];
        arr[front] = -INT_MAX;
        front = next(front);
        return value;
    }
    void display()
    {
        cout << "Front: " << front << ", Rear: " << rear << "\t";
        if (is_full())
            cout << "Full ";
        else if (is_empty())
        {
            cout << "Empty\n";
            return;
        }
        cout << '\n';
        if (rear <= front)
        {
            for (int i = front; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            for (int i = 0; i < rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        else
        {
            for (int i = front; i < rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        cout << "\n\n";
    }
};
class last_k_numbers_sum_stream{
    int sum = 0;
    Queue queue;
public:
    last_k_numbers_sum_stream(int k) : queue(k) {
    }
    int next(int new_num){
        
        if (queue.is_full()) {
            sum-=queue.dequeue();
        }
        sum+=new_num;
        queue.enqueue(new_num);
        return sum;
    }
};
int main() {
    last_k_numbers_sum_stream processor(4);
    int num;
    while(cin >> num)
        cout << processor.next(num) << endl;
}