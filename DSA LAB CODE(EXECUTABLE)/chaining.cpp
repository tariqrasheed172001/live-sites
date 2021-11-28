/* 
AIM: Implementation of Hashing Techniques.
Chaining
Open hashing  is a collision avoidence method which uses array of 
linked list to resolve the collision.

It is also known as the separate chaining method (each linked list 
is considered as a chain).*/ 

/*AiM: avoid collision.---->actually */


/*ALGORITHEM: 
1. Declare an array of a linked list with the hash table size.

2. Initialize an array of a linked list to NULL.

3. Find hash key.

4. If chain[key] == NULL

     Make chain[key] points to the key node.

5. Otherwise(collision),
Insert the key node at the end of the chain[key]. */  



#include<iostream>

#include<stdlib.h>
using namespace std;

#define size 7

struct node
{
    int data;
    struct node *next;
};

struct node *chain[size];

void init()
{
    int i;
    for(i = 0; i < size; i++)
        chain[i] = NULL;
}

void insert(int value)
{
    //create a newnode with value
    struct node *newNode = new node;
    newNode->data = value;
    newNode->next = NULL;

    //calculate hash key
    int key = value % size;

    //check if chain[key] is empty
    if(chain[key] == NULL)
        chain[key] = newNode;
    //collision
    else
    {
        //add the node at the end of chain[key].
        struct node *temp = chain[key];
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void print()
{
    int i;

    for(i = 0; i < size; i++)
    {
        struct node *temp = chain[i];
        cout<<"chain["<<i<<"]";
        while(temp)
        {
            cout<<temp->data<<"-->";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
}

int main()
{
    //init array of list to NULL
    init();

    insert(7);
    insert(0);
    insert(3);
    insert(10);
    insert(4);
    insert(5);

    print();

    return 0;
}