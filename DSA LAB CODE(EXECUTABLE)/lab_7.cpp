/*AIM: Implementation of tree traversals.
Pre-order
In-order
Post-order

ALGORITHEM:

Algorithm Preorder(tree)
   1. Visit the root.
   2. Traverse the left subtree, i.e., call Preorder(left-subtree)
   3. Traverse the right subtree, i.e., call Preorder(right-subtree) 
Algorithm Inorder(tree)
   1. Traverse the left subtree, i.e., call Inorder(left-subtree)
   2. Visit the root.
   3. Traverse the right subtree, i.e., call Inorder(right-subtree)
Algorithm Postorder(tree)
   1. Traverse the left subtree, i.e., call Postorder(left-subtree)
   2. Traverse the right subtree, i.e., call Postorder(right-subtree)
   3. Visit the root.
*/ 

#include <iostream>
using namespace std;
 
/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void preOrder(Node * root){
    if(!root) return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node * root){
    if(!root) return;

    
    preOrder(root->left);
    cout<<root->data<<" ";
    preOrder(root->right);
}
void postOrder(Node * root){
    if(!root) return;

    
    preOrder(root->left);
    preOrder(root->right);
    cout<<root->data<<" ";
}
int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
 
    cout << "\nPreorder traversal of binary tree is \n";
    preOrder(root);
 
    cout << "\nInorder traversal of binary tree is \n";
    inOrder(root);
 
    cout << "\nPostorder traversal of binary tree is \n";
    postOrder(root);

    cout<<endl;
    return 0;
}