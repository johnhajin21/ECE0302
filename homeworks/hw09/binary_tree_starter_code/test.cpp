#include <iostream>
using std::cout;
using std::endl;

#include "BinaryTree.h"

typedef std::string ItemType;
typedef void (*FunctionType)(ItemType& anItem);

void PrintNode(ItemType& i) { cout << i << endl; };

int main(int argc, char** argv)
{
    BinaryTree<ItemType, FunctionType> T1("1");
    BinaryTree<ItemType, FunctionType> T2("2");
    BinaryTree<ItemType, FunctionType> T3("3");
    BinaryTree<ItemType, FunctionType> T4("4");
    BinaryTree<ItemType, FunctionType> T5("5");
    BinaryTree<ItemType, FunctionType> T6("6");
    BinaryTree<ItemType, FunctionType> T7("7");
    
    BinaryTree<ItemType, FunctionType> T8("8");
    BinaryTree<ItemType, FunctionType> T9("9");
    BinaryTree<ItemType, FunctionType> T10("10");
    BinaryTree<ItemType, FunctionType> T11("11");
    BinaryTree<ItemType, FunctionType> T12("12");
    BinaryTree<ItemType, FunctionType> T13("13");
    BinaryTree<ItemType, FunctionType> T14("14");
    BinaryTree<ItemType, FunctionType> T15("15");
    

    //Left subtree


    T4.attachLeftSubtree(T8);
    T4.attachRightSubtree(T9);
    T5.attachLeftSubtree(T10);
    T5.attachRightSubtree(T11);

    T2.attachLeftSubtree(T4);
    T2.attachRightSubtree(T5);
    
    
    //right subtree
    T6.attachLeftSubtree(T12);
    T6.attachRightSubtree(T13);
    T7.attachLeftSubtree(T14);
    T7.attachRightSubtree(T15);

    T3.attachLeftSubtree(T6);
    T3.attachRightSubtree(T7);

    
    
    
    //main subtree
    T1.attachLeftSubtree(T2);
    T1.attachRightSubtree(T3);
    


    cout << "Postorder Transversal: " << endl;
    T1.postorderTraverse(&PrintNode);
    cout << endl;
    cout << "Preorder Transversal: " << endl;
    T1.preorderTraverse(&PrintNode);
    cout << endl;
    cout << "Inorder Transversal: " << endl ;
    T1.inorderTraverse(&PrintNode);
    cout << endl;
    

    // now T1 and T2 are no longer trees, but empty objects

    return 0;
};
