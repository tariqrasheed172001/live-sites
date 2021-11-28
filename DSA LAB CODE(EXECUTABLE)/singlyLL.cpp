/*AIM: Implementation of singly linked list.

ALGORITHEM: using strucure Node having data,next data members 
and implemented Traversal, Insertion, Deletion, Searching
functions of singly linked list.

*/ 

#include <iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *head,*newnode,*temp;

void traversal(struct node *ptr){
    
    if(ptr == NULL)
    {
        cout << "List is empty" << endl;

        return;
    }
    while(ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
void insertion()
{
    newnode = new node();
    cout << "\n Enter data:";
    cin >> newnode->data;
    newnode->next = NULL;

    if (head == NULL)
        head = temp = newnode;
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}
void deletion()
{
    if(head == NULL)
        cout << "\n List is empty";
    else
    {
        temp = head;

        cout << temp->data << "deleted!" << endl;

        head  = head->next;

        delete (temp);
    }
}
int search()
{
    int element;

    cout << "\n Enter element to be searched:";
    cin >> element;

    temp = head;
    int count = 0;
    while (temp != 0){
        count++;
        if (temp->data == element)
            return count;
        temp = temp->next;
    }
    return -1;
}
int main()
{
    char ch;
    int choice;
    head = NULL;
    while (1)
    {
        cout << "\n 1. Traversal \n 2. Insertion \n 3. Deletion \n 4. Searching \n 5.Exit() ";
        cout<< "\n Enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            traversal(head);
            break;
        case 2:
            insertion();
            break;
        case 3:
            deletion();
            break;
        case 4:
            int pos;
            pos = search();
            if (pos == -1)
                cout << "\n Element not found";
            else
                cout << "\n Element is found at Position:" << pos;
            break;
        case 5:exit(1);
                break;
        default:
            cout << "wrong choice";
        }
    }
    return 0;
}