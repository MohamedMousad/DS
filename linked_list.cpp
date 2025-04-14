#include <iostream>
#include <sstream>
#include <stack>
#include <map>
using namespace std;
// Node structure
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
    ~Node()
    {
        cout << "Node with value " << data << " and address : " << this << " has been deleted\n";
    }
};
// print with while loop
void print1(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << '\n';
}
// print with recursion
void print2(Node *head)
{
    if (head == nullptr)
    {
        cout << '\n';
        return;
    }
    cout << head->data << " ";
    print2(head->next);
}
// print with recursion in reverse order
void print3_reversed(Node *head)
{
    if (head == nullptr)
    {
        return;
    }
    print3_reversed(head->next);
    cout << head->data << " ";
}
// print with for loop
void print4(Node *head)
{
    for (Node *curr = head; curr != nullptr; curr = curr->next)
    {
        cout << curr->data << " ";
    }
    cout << '\n';
}
// find a node with a specific value
Node *find(Node *head, int value)
{
    for (Node *curr = head; curr != nullptr; curr = curr->next)
    {
        if (curr->data == value)
        {
            return curr;
        }
    }
    return nullptr;
}
// linked list with head , tail and length
class linked_list
{
private:
    Node *head = nullptr;
    Node *tail = nullptr;
    int length = 0;

public:
    // destruct all linkedlist nodes
    ~linked_list()
    {
        Node *curr = head;
        while (curr)
        {
            Node *temp = curr->next;
            delete curr;
            curr = temp;
        }
    }
    // get node of the nth element
    Node *get_nth(int idx)
    {
        Node *curr = head;
        for (int i = 0; i < idx - 1 && curr; i++, curr = curr->next)
        {
            // do nothing
        }
        return curr;
    }
    // get positiion of a value
    int get_position(int value)
    {
        int pos = 0;
        for (Node *curr = head; curr; curr = curr->next)
        {
            if (curr->data == value)
                return pos;
            pos++;
        }
        return -1;
    }
    // get a position of a value and change it's posision 1 to the left
    int get_position_sl(int value)
    {
        int pos = 0;
        for (Node *curr = head; curr->next; curr = curr->next)
        {
            if (curr->next->data == value)
            {
                swap(curr->data, curr->next->data);
                return pos;
            }
            else if (curr->data == value && pos == 0)
            {
                return pos;
            }
            pos++;
        }
        return -1;
    }
    // printing the whole list
    void print()
    {
        for (Node *curr = head; curr; curr = curr->next)
        {
            cout << curr->data << " ";
        }
        cout << '\n';
    }
    // checking correctness of linked list when debugging
    void verify_linked_list()
    {
        cout << "length: " << length << '\n';
        if (head == nullptr && tail == nullptr)
        {
            cout << "The linked list is empty.\n";
        }
        else
        {
            cout << "The linked list is not empty.\n";
        }
        cout << "head: " << head->data << '\n';
        cout << "tail: " << tail->data << '\n';
        int idx = 0;
        for (Node *curr = head; curr; curr = curr->next)
        {
            cout << curr->data << " ";
            idx++;
        }
        cout << idx << '\n';
    }
    // convert the whole list to string
    string debug_to_string()
    {
        if (length == 0)
            return "";
        ostringstream oss;
        for (Node *curr = head; curr; curr = curr->next)
        {
            oss << curr->data;
            if (curr->next)
                oss << "";
        }
        return oss.str();
    }
    // get the nth element from the back
    Node *get_nth_from_back(int idx)
    {
        if (idx > length)
            return nullptr;
        return get_nth(length - idx - +1);
    }
    // is the same list
    bool is_same(linked_list &list)
    {
        Node *curr = list.head, *curr2 = head;
        for (; curr && curr2; curr = curr->next, curr2 = curr->next)
        {
            if (curr->data != curr2->data)
            {
                return 0;
            }
        }
        return !curr && !curr2;
    }
    // 2nd implementation with length variable
    bool is_same2(linked_list &list)
    {
        if (list.length != length)
            return 0;
        for (Node *curr = list.head, *curr2 = head; curr && curr2; curr = curr->next, curr2 = curr->next)
        {
            if (curr->data != curr2->data)
            {
                return 0;
            }
        }
        return 1;
    }
    // delete new node in front of the list
    int delete_front()
    {
        if (head == nullptr)
            return -1;
        Node *temp = head;
        int value = head->data;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        length--;
        if (!head)
            tail = nullptr;
        return value;
    }
    // delete last node
    int delete_last()
    {
        return delete_nth(length);
    }
    // delete nth element
    int delete_nth(int idx)
    {
        Node *curr = head;
        int value = -1;
        if (idx == 1)
            return delete_front();
        while (curr && idx > 2)
        {
            curr = curr->next;
            idx--;
        }
        if (curr->next)
            delete_node(curr);
        return value;
    }
    // delete node with previous element
    int delete_node(Node *prev)
    {
        if (!head)
            return -1;
        Node *temp = prev->next;
        int value = temp->data;
        prev->next = prev->next->next;
        if (temp == tail)
            tail = prev;
        delete temp;
        length--;
        return value;
    }
    // delete a node with a specific value
    int delete_node_with_key(int value)
    {
        if (!head && value == head->data)
        {
            return this->delete_front();
        }
        for (Node *prev = head; prev->next; prev = prev->next)
        {
            if (prev->next->data == value)
            {
                return delete_node(prev);
            }
        }
        return -1;
    }
    // swapping the values of every pair of linked list
    void swap_pairs()
    {
        for (Node *curr = head; curr->next && curr; curr = curr->next->next)
            swap(curr->data, curr->next->data);
    }
    // reverse elements of all linked list
    void reverse()
    {
        Node *next = head->next, *curr = head, *prev = nullptr;
        while (curr)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (!curr)
                break;
            next = next->next;
        }
        swap(head, tail);
        next = curr = prev = nullptr;
    }
    // delete all even positions nodes
    void delete_even_positions()
    {
        for (Node *curr = head; curr->next; curr = curr->next)
        {
            delete_node(curr);
            if (curr->next == tail)
            {
                tail = curr;
            }
        }
    }
    // insert element after a node
    void insert(Node *curr, int value)
    {
        Node *new_node = new Node(value);
        new_node->next = curr->next;
        curr->next = new_node;
        length++;
        return;
    }
    // insert a node at the end of the linked list
    void insert_end(int value)
    {
        Node *new_node = new Node(value);
        if (!head)
        {
            head = tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = tail->next;
        }
        length++;
    }
    // insert new node in front of the list
    void insert_front(int value)
    {
        Node *new_node = new Node(value);
        new_node->next = head;
        head = new_node;
        if (!tail)
            tail = new_node;
    }
    // insert element to be in order of the list (ascending)
    void insert_sorted(int value)
    {
        if (value < head->data)
            return insert_front(value);
        for (Node *curr = head; curr->next; curr = curr->next)
        {
            if (curr->next->data > value)
                return insert(curr, value);
        }
        return insert_end(value);
    }
    // return the element on the left of any node
    Node *prev(Node *node)
    {
        for (Node *curr = head; curr->next; curr = curr->next)
        {
            if (curr->next == node)
            {
                return curr;
            }
        }
        return nullptr;
    }
    // swap head and tail of the linked list(nodes itself not the values)
    void tail_head()
    {
        if (length <= 2)
            return swap(head, tail);
        prev(tail)->next = head;
        tail->next = head->next;
        head->next = nullptr;
        swap(head, tail);
    }
    // rotate k elements to the end of the linked list and move the others to left
    void left_rotate(int k)
    {
        k %= length;
        if (k)
        {
            Node *nth = get_nth(k);
            tail->next = head;
            head = nth->next;
            tail = nth;
            nth->next = nullptr;
        }
    }
    // delete last element in the list of a specified value
    int delete_last_occurrnce(int value)
    {
        Node *last = nullptr;
        if (!head)
            return -1;
        if (head->data == value)
            last = head;
        for (Node *curr = head; curr->next; curr = curr->next)
        {
            if (curr->next->data == value)
                last = curr;
        }
        if (head == last && head)
            return delete_front();
        else if (last)
            return delete_node(last);
        return -1;
    }
    // move all ocurrences of a value to the end of the list
    void move_all_ocuurences(int value)
    {
        int cnt = 0;
        if (!head)
            return;
        for (Node *curr = head; curr->next;)
        {
            if (curr->next->data == value)
            {
                delete_node(curr);
                cnt++;
            }
            else
            {
                curr = curr->next;
            }
        }
        if (head->data == value && head)
        {
            delete_front();
            cnt++;
        }
        for (int i = 0; i < cnt; i++)
        {
            insert_end(value);
        }
    }
    // delete all duplicated elements except first one
    void delete_duplicates()
    {
        if (!head)
            return;
        map<int, short> frequency;
        frequency[head->data]++;
        for (Node *curr = head; curr->next;)
        {
            frequency[curr->next->data]++;
            if (frequency[curr->next->data] > 1)
            {
                delete_node(curr);
            }
            else
            {
                curr = curr->next;
            }
        }
    }
    // getting maximum of the linked list (if it's empty returning -INT_MAX)
    int max(bool first = true, Node *node = nullptr)
    {
        if (!head)
            return -INT_MAX;
        if (first)
            return max(false, head);
        else
        {
            if (!node->next)
                return node->data;
            return std::max(node->data, max(false, node->next));
        }
    }
    // arrange odd positions first then even positions
    void arrange_odd_even()
    {
        if (length <= 2)
            return;
        int cnt = 1;
        Node *next = head, *first_even = head->next, *last_odd = nullptr;
        for (Node *curr = head; curr->next->next; curr = next, cnt++)
        {
            next = curr->next;
            if (cnt == length - 2)
            {
                if (length & 1)
                {
                    last_odd = tail;
                    tail = curr->next;
                }
                else
                {
                    last_odd = curr->next;
                }
            }
            curr->next = curr->next->next;
        }
        last_odd->next = first_even;
        tail->next = nullptr;
    }
    // insert elemnts of a linked list in between elements of another
    void insert_alternating(linked_list &another)
    {
        Node *curr = head, *other = another.head;
        if (!curr || !other)
            return;
        while (curr && other)
        {
            Node *temp1 = curr->next, *temp2 = other->next;
            curr->next = other;
            if (temp1)
            {
                other->next = temp1; // curr->next
            }
            curr = temp1;
            other = temp2;
        }

        // Update the tail pointer if necessary
        if (!curr)
        {
            // If we've reached the end of the first list
            // The last node from the second list is our new tail
            Node *last = head;
            while (last && last->next)
            {
                last = last->next;
            }
            if (last)
            {
                tail = last;
            }
        }
        // Set the other list's head to nullptr to prevent double deletion
        another.head = nullptr;
        // Update the length to reflect the combined list
        length += another.length;
        another.length = 0;
        another.tail = nullptr;
    }
};
// linked list with head only (has limitations)
class linked_list2
{
private:
    Node *head = nullptr;

public:
    void print()
    {
        for (Node *curr = head; curr; curr = curr->next)
            cout << (curr->data) << " ";
        cout << endl;
    }
    void add_element(int value)
    {
        Node *new_node = new Node(value);
        new_node->next = head;
        head = new_node;
    }
    Node *get_tail()
    {
        if (!head)
            return nullptr;
        return head;
    }
    Node *get_head()
    {
        if (!head)
            return nullptr;
        Node *curr = head;
        while (curr->next)
            curr = curr->next;
        return curr;
    }
};
int main()
{
    linked_list list1, list2;
    list1.insert_end(1);
    list2.insert_end(2);
    list1.insert_alternating(list2);
    list1.print();
    return 0;
}