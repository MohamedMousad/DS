#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *left{};
    Node *right{};
    int data{};
    Node(int data) : data(data), left(nullptr), right(nullptr)
    {
    }
    ~Node()
    {
        cout << "Node with value : " << data << " address : " << this << " deleted" << endl;
    }
};
void print(Node *root)
{
    if (root == nullptr)
        return;
    print(root->left);
    print(root->right);
    cout << root->data << " ";
}

// implementation using nodes
class _BinaryTree
{
private:
    struct Node
    {
        int data{};
        Node *left{};
        Node *right{};
        Node(char data) : data(data) {};
    };
    Node *root{};

public:
    _BinaryTree(int root_value) : root(new Node(root_value)) {};

private:
    void print_inorder(Node *current)
    {
        if (!current)
            return;
        print_inorder(current->left);
        cout << current->data << " ";
        print_inorder(current->right);
    }

public:
    void print_inorder()
    {
        print_inorder(root);
        cout << endl;
    }
};
// implementation using another approach
class BinaryTree
{
private:
    int data{};
    BinaryTree *left{};
    BinaryTree *right{};
    int maxTree(BinaryTree *curr){
        if (!curr) return -INT_MAX;
        return max(max(maxTree(curr->right) , maxTree(curr->left)) , curr->data);
    }
    int get_height(BinaryTree *curr)
    {
        if (!curr) return 0;
        return max(get_height(curr->left) + (int) (curr->left != nullptr), get_height(curr->right) + (int) (curr->right != nullptr));
    }
    int nodes_count(BinaryTree * curr){
        if (!curr) return 0;
        return nodes_count(curr->right) + nodes_count(curr->left) + 1;
    }
    int count_leaf_nodes(BinaryTree * curr){
        if (!curr) return 0;
        if (!curr->right && !curr->left) return 1;
        return count_leaf_nodes(curr->left) + count_leaf_nodes(curr->right);
    }
    bool exists(BinaryTree *curr, int value)
    {
        if (!curr) return 0;
        return (curr->data == value) || exists(curr->left, value) || exists(curr->right, value);
    }
    bool is_perfect1(BinaryTree *curr){
        int h = get_height(curr);
        int n = nodes_count(curr);
        return n == ((1<<h+1) - 1);
    }
    bool is_perfect2(BinaryTree *curr){
        if (!curr) return 0;
        return is_perfect1(curr->right) + 1 == is_perfect2(curr->left) + 1;
    }
    void clearTree(BinaryTree *curr)
    {
        if (!curr) return;
        clearTree(curr->left);
        clearTree(curr->right);
        delete curr;
    }
    // needs to be done
    void print_inorder_iterative(BinaryTree *curr){
        stack<BinaryTree*> s;
        s.push(curr);
        while (!s.empty()){
            while (curr){
                curr = curr->left;
                s.push(curr);
            }
        }
    }
    int get_diamter(BinaryTree *curr){
        if (!curr) return 0;
        int res = get_height(curr->left) + (int)(curr->left != nullptr) + get_height(curr->right) + (int)(curr->right != nullptr);
        if (curr->left)
        res = max(res , get_diamter(curr->left));
        res = max(res , get_diamter(curr->right));
        return res;
    }
    void print_left_boundary(BinaryTree *curr){
        while (curr){
            cout << curr->data << " ";
            if (curr->left)
                curr=curr->left;
            else 
                curr=curr->right;
        }
        cout << '\n';
    }
    void bfs (BinaryTree *curr){
        queue<BinaryTree*> q , q2; q.push(curr);
        while (!q.empty()){
            cout << q.front()->data << " ";
            if(q.front()->left)
                q2.push(q.front()->left);
            if(q.front()->right)
                q2.push(q.front()->right);
            q.pop();
            if (q.empty()){
                cout << endl;
                q.swap(q2);
            }
        }
    }
    void bfs_spiral(BinaryTree *curr){
        deque<BinaryTree*> q , q2; q.push_front(curr);
        bool flip = 0;
        while (!q.empty()){
            if(flip){
                cout << q.back()->data << " ";
                if(q.back()->left)
                    q2.push_front(q.back()->left);
                if(q.back()->right)
                    q2.push_front(q.back()->right);
                q.pop_back();
            }
            else{
                cout << q.front()->data << " ";
                if(q.front()->left)
                    q2.push_back(q.front()->left);
                if(q.front()->right)
                    q2.push_back(q.front()->right);
                q.pop_front();
            }
            if (q.empty()){
                cout << endl;
                q.swap(q2);
                flip = !flip;
            }
        }
    }
    // needs to be done
    void bfs_rec(BinaryTree* curr){
        if (curr == nullptr) return;
        cout << curr->data << ' ';
        bfs_rec(curr->left);
        bfs_rec(curr->right);
    }
    bool is_complete(BinaryTree *curr){
        if (!curr) return 1;
        if (curr->right && !curr->left || curr->left && (curr->left->left) && !curr->right) return 0;
        return is_complete(curr->left) && is_complete(curr->right);
    }
public:
    BinaryTree(int root_value) : data(root_value) {};
    BinaryTree(string postfix){
    }
    ~BinaryTree(){
        if (left) {
            left = nullptr;
            delete left;
        }
        if (right) {
            right = nullptr;
            delete right;
        }
    }
    // bfs recursive 
    void print_inorder()
    {
        if (left)
            left->print_inorder();
        cout << data << " ";
        if (right)
            right->print_inorder();
    }
    // add a path to the tree
    void add_path(string path, vector<int> values)
    {
        BinaryTree *curr = this;
        for (int i = 0; i < path.length(); i++)
        {
            if (path[i] == 'L')
            {
                if (!curr->left)
                    curr->left = new BinaryTree(values[i]);
                else
                    assert(curr->left->data == values[i]);
                curr = curr->left;
            }
            else if (path[i] == 'R')
            {
                if (!curr->right)
                    curr->right = new BinaryTree(values[i]);
                else
                    assert(curr->right->data == values[i]);
                curr = curr->right;
            }
        }
    }
    // get maximum node value in tree 
    int maxTree()
    {
        return maxTree(this);
    }
    // get the height of the tree
    int get_height()
    {
        return get_height(this);
    }
    // get the node counts in tree
    int nodes_count(){
        return nodes_count(this);
    }
    // count leaf nodes in tree 
    int count_leaf_nodes(){
        return count_leaf_nodes(this);
    }
    // see if node value exists in tree
    bool exists(int value){
        return exists(this ,value);
    }
    // checks if the binary tree is perfect
    bool is_perfect1(){
        return is_perfect1(this);
    }
    // checks if the binary tree is perfect with another implementation
    bool is_perfect2(){
        return is_perfect1(this);
    }
    // prints the tree inordere iteratively 
    void print_inorder_iterative(){
        return print_inorder_iterative(this);
    }
    // prints the left boundary of a tree
    void print_left_boundary(){
        return print_left_boundary(this);
    }
    // clear all tree nodes
    void clearTree(){
        return clearTree(this);
    }
    // return the farthest distance between two nodes in binary tree
    int get_diamter(){
        return get_diamter(this);
    }
    // prints the tree in breadth first search order
    void bfs(){
        return bfs(this); 
    }
    // prints the tree in breadth first search order recursively
    void bfs_rec(){
        return bfs_rec(this);
    }
    void bfs_spiral()
    {
        return bfs_spiral(this);
    }
    bool is_complete(){
        return is_complete(this);
    }
};
signed main()
{
    BinaryTree tree(1);
    tree.add_path("LLL", {2, 4, 7});
    tree.add_path("LLR", {2, 4, 8});
    tree.add_path("LRL", {2, 5, 6});
    tree.add_path("LRR", {2, 5, 9});
    tree.add_path("RRR", {3, 6, 10});
    tree.add_path("RRL", {3, 6, 2});
    tree.add_path("RL", {3, 4});
    // tree.add_path("LL", {0 , 1});
    // tree.add_path("LR", {0 , 1});
    // tree.add_path("RL", {4 , 4});
    // tree.add_path("RRR", {4 , 4});
    cout << tree.is_complete() << endl;
    return 0;
}