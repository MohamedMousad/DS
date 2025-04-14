#include <iostream>
using namespace std;
class Vector
{
private:
    int *arr = nullptr;
    int size = 0;
    int capacity = 0;

public:
    Vector(int size)
    {
        this->size = size;
        this->capacity = size + 10;
        arr = new int[capacity]{};
    }
    ~Vector()
    {
        delete[] arr;
        arr = nullptr;
    }
    int get(int index)
    {
        // assert(0 <= index && index < size);
        return arr[index];
    }
    void set(int index, int value)
    {
        arr[index] = value;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int find(int value)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                return i;
            }
        }
        return -1;
    }
    int get_front()
    {
        return arr[0];
    }
    int get_back()
    {
        return arr[size - 1];
    }
    void push_back(int value)
    {
        size++;
        if (size == capacity)
            expand_cap();
        arr[size - 1] = value;
    }
    void expand_cap()
    {
        capacity *= 2;
        int *temp = new int[capacity]{};
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        swap(temp, arr);
        delete[] temp;
    }
    void insert(int index, int value)
    {
        size++;
        if (size == capacity)
            expand_cap();
        // first way to move the elements by one to the right 
        for (int i = size - 1; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;

        //second way to do it (my way)
        // int temp = arr[index];
        // int temp2 = 0;
        // arr[index] = value ;
        // for (int i = index + 1 ; i < size;i++){
        //     temp2 = arr[i];
        //     arr[i] = temp;
        //     temp = temp2;
        // }
    }

    //problems' solutions 
    void right_rotate(){
        int temp = arr[size - 1];
        for (int i = size - 1; i > 0; i--){
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
    }
    void left_rotate(){
        int temp = arr[0];
        for (int i = 0; i < size - 1; i--){
            arr[i] = arr[i + 1];
        }
        arr[size-1] = temp;
    }
    void right_rotate(int times){
        times%=size;
        int *temp = new int[times]{};
        for (int i = 0; i < times; i++){
            temp[i] = arr[size - times + i];
        }
        int temp = arr[size - 1];
        for (int i = size - 1; i > times - 1; i--){
            arr[i] = arr[i - 1];
        }
        for (int i = 0; i < times; i++){
            arr[i] = temp[i];
        }
        delete []temp;
    }
    int pop(int index){
        int temp = arr[index];
        size--;
        for (int i = index; i < size; i++){
            arr[i] = arr[i + 1];
        }
        return temp;
    }
    int find_transposition(int value){
        int index = find(value);
        if (index > 0){
            swap(arr[index], arr[index - 1]);
            return index - 1;
        }
    }
};
int main()
{
    Vector v(5);
    v.set(0, 10);
    v.set(1, 20);
    v.set(2, 30);
    v.set(3, 40);
    v.set(4, 50);
    v.push_back(60);
    v.print();
    return 0;
}