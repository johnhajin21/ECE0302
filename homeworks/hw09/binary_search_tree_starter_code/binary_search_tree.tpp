#include "binary_search_tree.h"

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
    clone(rhs.root);
}

// this is an alternative implementation using a stack to simulate the recursion
template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::clone(Node<KeyType, ItemType>* rhs)
{
    Node<KeyType, ItemType>** lhs = &root;

    std::stack<stackvar<KeyType, ItemType>> s;

    stackvar<KeyType, ItemType> rootvar;
    rootvar.rhs = rhs;
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
BinarySearchTree<KeyType, ItemType>& BinarySearchTree<KeyType, ItemType>::
operator=(const BinarySearchTree<KeyType, ItemType>& rhs)
{
    if (&rhs == this)
        return *this;

    destroy();

    root = 0;
    clone(rhs.root);

    return *this;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree()
{
    destroy();
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::insert(
    const KeyType& key, const ItemType& item)
{
    // TODO 
    //Creating a new node
    Node<KeyType, ItemType>* newNode = new Node<KeyType, ItemType>();
    newNode -> key = key;
    newNode -> data = item;
    newNode -> left = 0;
    newNode -> right = 0;

    

    //ALWAYS INSERT AS A LEAF

    //If it is the first node inserted
    if(isEmpty()){

        root = newNode;
        return true;
    }
    
    else{
        //Finding where to insert at
        Node<KeyType, ItemType>* curr;
        Node<KeyType, ItemType>* curr_parent;
        search(key, curr, curr_parent);

        //Error checking that it doesnt have the same key
        if(key == curr->key){
            return false;
        }

        //If lesser
        else if(key < curr->key){
            curr->left = newNode;
        }

        //If greater

        else if(key > curr->key){
            curr->right = newNode;
        }
    
    }
    return true;

    
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

    // TODO


    // case one thing in the tree Deleting the root node
    if(root->left == 0 && root->right == 0){
        delete root;
        root = 0; //Tree should be empty at this point
        return true; 
    }

    //Finding where to insert at
    Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    search(key, curr, curr_parent);

    // case, found deleted item at leaf
    //Doesnt have a left or right child
    if(curr->left == 0 && curr->right == 0){
        if(curr_parent->left == curr){
            curr_parent->left = 0;
        }

        else if(curr_parent->right == curr){
            curr_parent->right = 0;
        }
        delete curr;//Deleting the node
        return true;
    }

    // case, item to delete has only a right child
    else if(curr->left == 0 && curr->right != 0){
        //If there is no parent at all aka was the root parent
        if(curr_parent == 0){
            root = curr->right;
            
        }
        //If current node to be deleted is left child of parent
        else if(curr_parent->left == curr){
            curr_parent->left = curr->right;
        }

        //If current node to be deleted is right child of parent
        else if(curr_parent->right == curr){
            curr_parent->right = curr->right;
        }

        delete curr;//Deleting the node
        return true;
    }

    // case, item to delete has only a left child
      else if(curr->left == 0 && curr->right != 0){
        //If there is no parent at all aka was the root parent
        if(curr_parent == 0){
            root = curr->left;
            
        }
        //If current node to be deleted is left child of parent
        else if(curr_parent->left == curr){
            curr_parent->left = curr->left;
        }

        //If current node to be deleted is right child of parent
        else if(curr_parent->right == curr){
            curr_parent->right = curr->left;
        }

        delete curr;//Deleting the node
        return true;
    }

    // case, item to delete has two children
    else if(curr->left !=0 && curr->right !=0){
        //Find the lowest key in the right subtree
        Node<KeyType, ItemType>* lowest;
        inorder(curr,lowest,curr_parent);

        //Make temporary values to hold the data
        ItemType dataHolder = lowest -> data;
        KeyType keyHolder = lowest -> key;

        //Recursively call this function to delete this new node called lowest
        remove(lowest->key);

        //Make the node that is going to be deleted replaced with the lowest value node
        curr -> key = keyHolder;
        curr -> data = dataHolder;

    }

    return false; // Goes here if node doesnt exist
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorder(Node<KeyType, ItemType>* curr,
    Node<KeyType, ItemType>*& in, Node<KeyType, ItemType>*& parent)
{
    // TODO 
    // move right once
    // move left as far as possible

    in = curr->right; ////Brings it to the right subtree 
        //Then go to the left as far as possible to find the lowest value
        while(in->left != 0){
            in = in->left;
        }
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
void BinarySearchTree<KeyType, ItemType>::treeSort(ItemType arr[], int size) {
    destroy();

    // TODO: check for duplicate items in the input array
    for(int i=0;i<size;i++){
        insert(arr[i],arr[i]);
    }

    //Created a new function in private because thought it would be easier
    // TODO: use the tree to sort the array items
    int ok = 0;
    inorders(arr,root,ok);

    // TODO: overwrite input array values with sorted values
    
    
    
}
