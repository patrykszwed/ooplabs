#include <iostream>

using namespace std;

template <typename T>
class Node{
private:
    T value;

public:
    Node *left; // left child
    Node *right; //right child

    Node(T value) : value(value),  right(nullptr), left(nullptr){}

    T getValue() const {
        return value;
    }
};

template <typename T>
class BST{
private:
    Node<T> *root;

    void insertElem(Node<T> *node, T value){
        if(node->getValue() > value){
            if(!node->left)   // if there's nothing on the left and the element is smaller
                node->left = new Node<T>(value);
            else
                insertElem(node->left, value);
        }
        else{   // new element is greater, so move it to the right
            if(!node->right)
                node->right = new Node<T>(value);
            else
                insertElem(node->right, value);
        }
    }

    bool searchValue(Node<T> *node, T value){
        if(node->getValue() == value)
            return true;

        bool right = false, left = false;

        if(node->right)
            right = searchValue(node->right, value);
        if(node->left)
            left = searchValue(node->left, value);
        return right || left;
    }

    void showInorder(Node<T> *node){
        if(!node)
            return;

        showInorder(node->left);
        cout << "(" << node->getValue() << "),";
        showInorder(node->right);
    }

public:

    BST(){
        root = NULL;
    }

    void insertValue(T value){
        if(!root)   // if the tree is empty
            root = new Node<T>(value);
        else
            insertElem(root, value);
    }

    bool isValue(T value){
        if (!root)  // tree is empty
            return false;
        return searchValue(root, value);
    }

    void showInorder(){
        if (!root)
            cout << "\nTree is empty!\n";
        else
            showInorder(root);
    }
};

int main() {

    BST<int> bstInt;
    BST<string> bstString;
    int temp;
    string stringTemp;

    // == int BST ==

    bstInt.insertValue(45);
    bstInt.insertValue(75);
    bstInt.insertValue(25);
    bstInt.insertValue(35);
    bstInt.insertValue(15);
    bstInt.insertValue(7);
    bstInt.insertValue(11);

    cout << "\nInorder traversal: ";
    bstInt.showInorder();

    cout << "\nWhich value are you looking for?";
    cin >> temp;

    if(bstInt.isValue(temp))
        cout << "\nValue " << temp << " is in that BST";
    else
        cout << "\nThere is no such value.";

    // == String BST ==

    bstString.insertValue("Karen");
    bstString.insertValue("Tom");
    bstString.insertValue("Bob");
    bstString.insertValue("Alan");
    bstString.insertValue("Ellen");
    bstString.insertValue("Karen");
    bstString.insertValue("Wendy");


    cout << "\nInorder traversal: ";
    bstString.showInorder();

    cout << "\nWhich value are you looking for?";
    cin >> stringTemp;

    if(bstString.isValue(stringTemp))
        cout << "\nValue " << stringTemp << " is in that BST";
    else
        cout << "\nThere is no such value.";

    return 0;
}