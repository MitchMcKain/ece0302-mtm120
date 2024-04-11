#include "binary_search_tree.hpp"

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree()
{
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(
    const BinarySearchTree<KeyType, ItemType>& rhs)
{
    root = 0;
    Node<KeyType, ItemType>** lhs = &root;

    std::stack<stackvar<KeyType, ItemType>> s;

    stackvar<KeyType, ItemType> rootvar;
    rootvar.rhs = rhs.root;
    rootvar.lhs = lhs;
    s.push(rootvar);

    while (!s.empty()) {
        stackvar<KeyType, ItemType> currentvar = s.top();
        s.pop();

        Node<KeyType, ItemType>* curr_rhs = currentvar.rhs;
        Node<KeyType, ItemType>** curr_lhs = currentvar.lhs;

        if (curr_rhs == 0)
            continue;

        // allocate new node and copy contents
        Node<KeyType, ItemType>* temp = new Node<KeyType, ItemType>;
        temp->key = curr_rhs->key;
        temp->data = curr_rhs->data;
        temp->left = 0;
        temp->right = 0;
        *curr_lhs = temp;

        // push left subtree
        currentvar.rhs = curr_rhs->left;
        currentvar.lhs = &((*curr_lhs)->left);
        s.push(currentvar);

        // push right subtree
        currentvar.rhs = curr_rhs->right;
        currentvar.lhs = &((*curr_lhs)->right);
        s.push(currentvar);
    }
}


template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>& BinarySearchTree<KeyType, ItemType>::
operator=(BinarySearchTree<KeyType, ItemType> rhs)
{
    swap(rhs);
    return *this;
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::swap(BinarySearchTree<KeyType, ItemType>& rhs)
{
    std::swap(root, rhs.root);
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree()
{
    destroy();
}


template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroy()
{
    std::stack<Node<KeyType, ItemType>*> s;
    s.push(root);

    while (!s.empty()) {
        Node<KeyType, ItemType>* curr = s.top();
        s.pop();

        if (curr != 0) {
            s.push(curr->left);
            s.push(curr->right);
            delete curr;
        }
    }
    root = 0;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::insert(
    const KeyType& key, const ItemType& item)
{
    //create a node with key and new item
    Node<KeyType, ItemType>* itemNode = new Node<KeyType, ItemType>;
    itemNode->key = key;
    itemNode->data = item;
    Node<KeyType, ItemType>* curNode;
    Node<KeyType, ItemType>* parNode;

    //check for an empty tree
    if (isEmpty())
        { 
            root = itemNode;
            return true; 
        }
    //if not empty, find correct spot and insert
    else
        {
            search(key, curNode, parNode);
            
            if (key < curNode->key)
                {
                    curNode->left = itemNode;
                    return true;
                }
            else if (key > curNode->key)
                {
                    curNode->right = itemNode;
                    return true;
                }
            else
                {
                    delete itemNode;
                    return false;
                }
        }
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty()
{
    return (root == 0);
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::retrieve(
    const KeyType& key, ItemType& item)
{
    Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    search(key, curr, curr_parent);

    if (curr == 0)
        return false;

    if (curr->key == key) {
        item = curr->data;
        return true;
    }

    return false;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::remove(KeyType key)
{
    if (isEmpty())
        return false; // empty tree

    //search for key
    Node<KeyType, ItemType>* curNode;
    Node<KeyType, ItemType>* parNode;
    search(key, curNode, parNode);

    // case one thing in the tree
    if (curNode == root && curNode->left == nullptr && curNode->right == nullptr)
        {
            root = nullptr;
            return true;
        }

    // case, found deleted item at leaf
    else if (curNode->left == nullptr && curNode->right == nullptr)
        {
            if (curNode == parNode->left) //removing the left leaf
                {
                    parNode->left = nullptr;
                    curNode = 0;
                    return true;
                }
            if (curNode == parNode->right) //removing the right leaf
                {
                    parNode->right = nullptr;
                    curNode = 0;
                    return true;
                }
        }

    // case, item to delete has only a right child
    else if (curNode->left == nullptr && curNode->right != nullptr)
        {
            curNode->data = curNode->right->data;
            curNode->key = curNode->right->key;
            curNode->right = 0;
            return true;
        }

    // case, item to delete has only a left child
    else if (curNode->left != nullptr && curNode->right == nullptr)
        {
            curNode->data = curNode->left->data;
            curNode->key = curNode->left->key;
            curNode->left = 0;
            return true;
        }

    // case, item to delete has two children
    else 
        {
            Node<KeyType, ItemType>* newNode = new Node<KeyType, ItemType>;
            Node<KeyType, ItemType>* oldcurNode = curNode;
            inorder(curNode, newNode, parNode);
            oldcurNode->data = newNode->data;
            oldcurNode->key = newNode->key;
            delete newNode;
            return true;
        } 

    return false;
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorder(Node<KeyType, ItemType>* curr,
    Node<KeyType, ItemType>*& in, Node<KeyType, ItemType>*& parent)
{
    // TODO: find inorder successor of "curr" and assign to "in"
    curr = curr->right;
    while(curr->left != nullptr)
        {
            parent = curr;
            curr = curr->left;
        }
    parent->data = parent->data;
    parent->key = parent->key;
    in->data = curr->data;
    in->key = curr->key;
    curr = 0;
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::search(KeyType key,
    Node<KeyType, ItemType>*& curr, Node<KeyType, ItemType>*& parent)
{
    curr = root;
    parent = 0;

    if (isEmpty())
        return;

    while (true) {
        if (key == curr->key) {
            break;
        } else if (key < curr->key) {
            if (curr->left != 0) {
                parent = curr;
                curr = curr->left;
            } else
                break;
        } else {
            if (curr->right != 0) {
                parent = curr;
                curr = curr->right;
            } else
                break;
        }
    }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::treeSort(KeyType arr[], int size) {
    // TODO: check for duplicate items in the input array  
    KeyType value;
    for (int i = 0; i < size; i++)
        {
           value = arr[i];
            for (int j = 0; j < size; j++)
                {
                    if (value == arr[j])
                        {
                            exit(EXIT_FAILURE);
                        }
                }
        }
    // TODO: use the tree to sort the array items
    for (int i = 0; i < size; i++)
        { insert(arr[i], 1); }

    Node<KeyType, ItemType>* curNode = root;
    Node<KeyType, ItemType>* parNode;

    KeyType newarr[size];
    int currentSize = 0;
    while (root != nullptr)
        {
            while(curNode->left != nullptr)
                {
                    curNode = curNode->left;
                }
            newarr[currentSize] = curNode->key;
            remove(curNode->key);
            currentSize++;
        }

    // TODO: overwrite input array values with sorted values
    for (int i = 0; i < size; i++)
        { arr[i] = newarr[i]; }

    return;
}
