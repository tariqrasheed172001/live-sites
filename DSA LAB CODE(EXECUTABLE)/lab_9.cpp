/* AIM: Implementation of Binary Search Tree operations.
Insert
Delete
Search

Binary Search Tree is a node-based binary tree data structure 
which has the following properties:  

The left subtree of a node contains only nodes with keys lesser than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
The left and right subtree each must also be a binary search tree. 
There must be no duplicate nodes.*/

/*ALGORITHEM:
For searching a value, if we had a sorted array we could 
have performed a binary search. Let’s say we want to search
 a number in the array what we do in binary search is we 
 first define the complete list as our search space, the 
 number can exist only within the search space. Now we 
 compare the number to be searched or the element to be
searched with the mid element of the search space or 
the median and if the record being searched is lesser
we go searching in the left half else we go searching
in the right half, in case of equality we have found 
the element. In binary search we start with ‘n’ elements 
in search space and then if the mid element is not the 
element that we are looking for, we reduce the search 
space to ‘n/2’ and we go on reducing the search space 
till we either find the record that we are looking for or we 
get to only one element in search space and be done with this whole reduction.
Search operation in binary search tree will be very similar. Let’s say we want to 
search for the number, what we’ll do is we’ll start at the root, and then we will 
compare the value to be searched with the value of the root if it’s equal we are 
done with the search if it’s lesser we know that we need to go to the left subtree 
because in a binary search tree all the elements in the left subtree are lesser and 
all the elements in the right subtree are greater. Searching an element in the binary
 search tree is basically this traversal in which at each step we will go either 
 towards left or right and hence in at each step we discard one of the sub-trees. 
 If the tree is balanced, we call a tree balanced if for all nodes the difference 
 between the heights of left and right subtrees is not greater than one, we will 
 start with a search space of ‘n’nodes and when we will discard one of the sub-trees 
 we will discard ‘n/2’ nodes so our search space will be reduced to ‘n/2’ and then in 
 the next step we will reduce the search space to ‘n/4’ and we will go on reducing 
 like this till we find the element or till our search space is reduced to only one 
 node. The search here is also a binary search and that’s why the name binary search 
 tree. */ 


#include <iostream>
using namespace std;
 
struct node {
    int key;
    struct node *left, *right;
};

struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        cout << root->key;
        inorder(root->right);
    }
}
 
struct node* insert(struct node* node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}
 
struct node* minValueNode(struct node* node)
{
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
 
struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;
    
    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}

struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL)
        return root;
 
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left==NULL and root->right==NULL)
            return NULL;
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
int main()
{
    /* Let us create following BST
            50
        /     \
        30     70
        / \ / \
    20 40 60 80 */
    struct node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
    cout << "Inorder traversal of the given tree \n";
    inorder(root);
 
    cout << "\nDelete 20\n";
    root = deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
 
    cout << "\nDelete 30\n";
    root = deleteNode(root, 30);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);


    cout<<"\nsearched succufully "<<(search(root,70))->key<<endl;

    cout << "\nDelete 50\n";
    root = deleteNode(root, 50);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
    cout<<endl;
    return 0;
}