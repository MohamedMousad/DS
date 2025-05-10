#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// class Stack
class Stack
{
private:
    int size = 0;
    int top = -1;
    int *arr = nullptr;
public:
    Stack()
    {
        this->size = 10;
        arr = new int[size]{};
    }
    ~Stack()
    {
        delete[] arr;
        arr = nullptr;
    }
    bool isFull()
    {
        return (top + 1 >= size);
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    void push(int value)
    {
        if (!isFull())
        {
            arr[++top] = value;
        }
        else
        {
            int *arr2 = new int[2 * size]{};
            for (int i = 0; i <= top; i++)
            {
                arr2[i] = arr[i];
            }
            arr2[++top] = value;
            size *= 2;
            swap(arr, arr2);
            delete[] arr2;
            arr2 = nullptr;
        }
    }
    int pop()
    {
        if (!isEmpty())
        {
            return arr[top--]; // Return current element at top, then decrement
        }
        // means empty stack
        return -1;
    }
    int Top()
    {
        if (!isEmpty())
            return arr[top];
        // means empty stack
        return -1;
    }
    void print()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void insert_at_bottom(int x, int idx = 0 , bool flag = true ){
        if (flag){
            flag = false;
            push(x);
            insert_at_bottom(x , top , false);
        }
        else{
            if (idx == 0){ 
                arr[0] = x;
                return;
            }
            else{
                arr[idx] = arr[--idx];
                insert_at_bottom(x, idx, false);
            }
        }
    }
    // takes n*n time and n space
    void reverse_stack (){
        if (top == -1)
            return;
        int x = pop();
        reverse_stack();
        insert_at_bottom(x);
    }
    // takes n time and n space
    void reverse_stack2 (int start = 0 , int end = 0 ,bool flag = true){
        if (end == 0)
            end = top;
        if (start == end)
            return;
        swap(arr[start] , arr[end]);
        reverse_stack2(++start , --end);
    } 

};
class Stack2
{
private:
    int size = 0;
    int added_elements = 0;
    int *arr = nullptr;

public:
    Stack2()
    {
        this->size = 10;
        arr = new int[size]{};
    }
    ~Stack2()
    {
        delete[] arr;
        arr = nullptr;
    }
    bool isFull()
    {
        return (added_elements == size);
    }
    bool isEmpty()
    {
        return (added_elements == 0);
    }
    void push(int value)
    {
        if (!isFull())
        {
            arr[size - added_elements - 1] = value;
        }
        else
        {
            int *arr2 = new int[2 * size]{};
            for (int i = 0; i < added_elements; i++)
            {
                arr2[2 * size - 1 - i] = arr[size - 1 - i];
            }
            arr2[2 * size - added_elements] = value;
            size *= 2;
            swap(arr, arr2);
            delete[] arr2;
            arr2 = nullptr;
        }
        added_elements++;
    }
    int pop()
    {
        if (!isEmpty())
        {
            added_elements--;
            return arr[size - added_elements - 1];
        }
        // means empty stack
        return -1;
    }
    int Top()
    {
        if (!isEmpty())
            return arr[size - added_elements];
        // means empty stack
        return -1;
    }
    void print()
    {
        for (int i = size - 1; i >= size - added_elements; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
// reverse a number using stack
int reverse_num(int num)
{
    int ans = 0, mul = 1;
    Stack s;
    while (num)
    {
        s.push(num % 10);
        num /= 10;
    }
    while (!s.isEmpty())
    {
        ans += s.Top() * mul;
        mul *= 10;
        s.pop();
    }
    return ans;
}
// reverse the words in a line string using stack
void reverse_words(string s)
{
    vector<stack<char>> stacks;
    // string s = "abc de fg";
    // getline(cin , s);
    for (int i = 0; i < s.length(); i++)
    {
        if (i == 0 || s[i - 1] == ' ')
        {
            stacks.push_back(stack<char>());
        }
        if (s[i] != ' ')
            stacks.back().push(s[i]);
    }
    for (int i = 0; i < stacks.size(); i++)
    {
        while (!stacks[i].empty())
        {
            cout << stacks[i].top();
            stacks[i].pop();
        }
        cout << " ";
    }
    cout << endl;
}
// find if the string of parantheses have them matching or not
bool is_valid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (!st.empty() && (s[i] == ']' && st.top() == '[' || s[i] == ')' && st.top() == '(' || s[i] == '}' && st.top() == '{'))
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    return st.empty();
}
// remove adjacent duplicates using a stack
string remove_duplicates(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (!st.empty() && s[i] == st.top())
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    string ans = "";
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
// two stack in one array
class Stack3
{
private:
    int size = 0;
    int *arr = nullptr;
    int top1 = -1;
    int top2 = size;

public:
    Stack3()
    {
        this->size = 10;
        top2 = size;
        arr = new int[size]{};
    }
    ~Stack3()
    {
        delete[] arr;
        arr = nullptr;
    }
    bool isFull()
    {
        return abs(-1 - top1) + abs(size - top2) >= size;
    }
    bool isEmpty(int id)
    {
        if (id == 1)
        {
            return top1 == -1;
        }
        return top2 == size;
    }
    void push(int id, int value)
    {
        // move two stacks into new array
        if (isFull())
        {
            int *arr2 = new int[2 * size]{};
            // Copy elements from first stack
            for (int i = 0; i <= top1; i++)
            {
                arr2[i] = arr[i];
            }
            // Copy elements from second stack, adjusting indices for new size
            for (int i = size - 1; i >= top2; i--)
            {
                arr2[i + size] = arr[i];
            }
            // Update top2 pointer to new position
            top2 += size;
            // Clean up old array and update pointers
            delete[] arr;
            arr = arr2;
            size *= 2;
        }
        // Add new element to appropriate stack
        if (id == 1)
        {
            arr[++top1] = value;
        }
        else if (id == 2)
        {
            arr[--top2] = value;
        }
    }
    int pop(int id)
    {
        if (!isEmpty(id))
        {
            if (id == 1)
            {
                return arr[top1--];
            }
            return arr[top2++];
        }
        return -INT_MAX;
    }
    int Top(int id)
    {
        if (!isEmpty(id))
        {
            if (id == 1)
            {
                return arr[top1];
            }
            return arr[top2];
        }
        return -INT_MAX;
    }
    void print(int id)
    {
        if (id == 1)
        {
            for (int i = 0; i <= top1; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {
            for (int i = size - 1; i >= top2; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        return;
    }
};

// Medium problems
// find remaining asteroids in a row which - sign means moving left and + is means moving right (biggest asteroid lives and if equal both explode)
vector<int> stack_to_vec(Stack& st)
{
    vector<int> ans;
    while (!st.isEmpty())
    {
        ans.push_back(st.Top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
vector<int> remaining_asteroids(vector<int> asteroids)
{
    Stack remains;
    for (int i = 0; i < asteroids.size(); i++)
    {
        if (!remains.isEmpty() && asteroids[i] < 0 && remains.Top() > 0)
        {
            int lastPop = -INT_MAX;
            while (!remains.isEmpty() && asteroids[i] < 0 && remains.Top() > 0)
            {
                if (abs(asteroids[i]) > remains.Top())
                {
                    remains.pop();
                }
                else if (abs(asteroids[i]) == remains.Top())
                {
                    lastPop = remains.Top();
                    remains.pop();
                    break;
                }
                else
                {
                    break;
                }
            }
            if (remains.isEmpty() && lastPop != asteroids[i] || !remains.isEmpty() && remains.Top() < 0)
            {
                remains.push(asteroids[i]);
            }
        }
        else
            remains.push(asteroids[i]);
    }
    return stack_to_vec(remains);
}
// find score of balanced parantheses as () = 1 and (()) = 2 and ((()) = 4 and so on
int paranthesesScore(string s){
    int ans= 0; stack <char> st; stack<int> scores;
    for (int i = 0 ; i < s.length(); i++){
        int sum = 0;
        if (!st.empty()&& st.top() == '(' && s[i] == ')'){
            int sum = 0 ; bool flag = 0;
            st.pop();
            while (!scores.empty() && scores.top() != 0){
                sum+=scores.top();
                flag = 1;
                scores.pop();
            }
            // won't be empty but just checking
            if (!scores.empty())
                scores.pop();
            if (flag) scores.push((sum<<1));
            else scores.push(1);
        }
        else {
            st.push(s[i]);
            scores.push(0);
        }
    }
    while (!scores.empty()){
        ans+=scores.top();
        scores.pop();
    }
    return ans;
}
// find the next greater element for each element in the array (if not found -1)(nearest element on the right not greatest on the right) 
vector<int> next_greater(vector<int>& a){
    vector<int> ans(a.size() , -1);
    stack<pair<int,int>> st;
    for (int i = 0 ; i < a.size();i++){
        while (!st.empty() && a[i] > st.top().first){
            ans[st.top().second] = a[i];
            st.pop();
        }
        st.push({a[i] , i});
    }
    return ans ;
}
int factorial_stack(int n){
    stack<pair<int,int>> st;
    for (int i = n ; i > 1; i--){
        if (i == 2)
            st.push({i , 2});
        else 
            st.push({i , -1});
    }
    int val = 0;
    while (!st.empty()){
        if (st.size() == 1)
            break;
        val = st.top().second;
        st.pop();
        st.top().second = st.top().first * val;
    }
    return st.top().second;
}
// linked-list-based stack
class StackLL{
    private :
    struct Node{
        int data;
        Node* next;
        Node(int val){
            data = val;
            next = nullptr;
        }
    };
    Node *head;
public :
    void push(int val){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    int pop(){
        if (head == nullptr)
            return -1;
        Node* temp = head;
        head = head->next;
        int val = temp->data;
        delete temp;
        return val;
    }
    int peek(){
        if (head == nullptr)
            return -1;
        return head->data;
    }
    bool isEmpty(){
        return head == nullptr;
    }
};
string postfix(string evaluate){
    stack<char> operators;
    string ans = "";
    for (int i=0;i < evaluate.length();i++){
        if (evaluate[i] >= '0' && evaluate[i] <= '9'){
            ans.push_back(evaluate[i]);
        }
        else {
            if (!operators.empty() && evaluate[i] != '('){
                if (evaluate[i] == '+' || evaluate[i] == '-' || operators.top() == '*' || operators.top() == '/' || evaluate[i] == ')'){
                    while(!operators.empty() && operators.top() != '('){
                        ans.push_back(operators.top());
                        operators.pop();
                    }
                    if (!operators.empty() && operators.top() == '(') operators.pop();
                }
            }
            if (evaluate[i] != ')')
                operators.push(evaluate[i]);
        }
    }
    while (!operators.empty()){
        ans.push_back(operators.top());
        operators.pop();
    }
    return ans;
}

signed main()
{
    cout << postfix("(2+3)*4") << endl;
}