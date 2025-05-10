#include <iostream> 
using namespace std;
// class Stack
class Stack{
    private:
    int size = 0;
    int capacity = 0;
    int top = -1; 
    int *arr = nullptr;
    public:
    Stack(){
        this->size = 10;
        this->capacity = size;
        arr = new int[capacity]{};
    }
    ~Stack(){
        delete[] arr;
        arr = nullptr;
    }
    bool isFull (){
        return (top+1 >= capacity);
    }
    bool isEmpty (){
        return (top == -1);
    }
    void push(int value){
        if (!isFull()){
            arr[++top] = value;
        }
        else {
            int *arr2 = new int[2*capacity]{};
            size++;
            for (int i = 0 ; i < size ; i++){
                arr2[i] = arr[i];
            }
            arr2[++top] = value;
            swap(arr , arr2); 
            capacity*=2;
            delete[] arr2;
            arr2 = nullptr;
        }
    }
    int pop(){
        if (!isEmpty()){
            top--;
            return arr[top];
        }
        //means empty stack
        return -1;
    }
    int Top(){
        if  (!isEmpty())
            return arr[top];
        //means empty stack
        return -1;
    }
    void print(){
        for (int i = 0 ; i <= top ; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
class Stack2{
    private:
    int size = 0;
    int added_elements = 0; 
    int *arr = nullptr;
    public:
    Stack2(){
        this->size = 10;
        arr = new int[size]{};
    }
    ~Stack2(){
        delete[] arr;
        arr = nullptr;
    }
    bool isFull (){
        return (added_elements == size);
    }
    bool isEmpty (){
        return (added_elements == 0);
    }
    void push(int value){
        if (!isFull()){
            arr[size - added_elements] = value;
        }
        else {
            int *arr2 = new int[2*size]{};
            for (int i = 0 ; i < added_elements ; i++){
                arr2[2*size - 1 - i] = arr[size - 1 - i];
            }
            arr2[2*size - added_elements] = value;
            size*=2;
            swap(arr , arr2); 
            delete[] arr2;
            arr2 = nullptr;
        }
        added_elements++;
    }
    int pop(){
        if (!isEmpty()){
            added_elements--;
            return arr[size - added_elements - 1];
        }
        //means empty stack
        return -1;
    }
    int Top(){
        if  (!isEmpty())
            return arr[size - added_elements];
        //means empty stack
        return -1;
    }
    void print(){
        for (int i = size-1 ; i >=  size - added_elements ; i--){
            cout << arr[size - added_elements] << " ";
        }
        cout << endl;
    }
};
int main(){
    Stack2 st; 
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    st.print();
}