/*AIM: Static/Array Implementation of Queue.

ALGORITEHM: using OOPs class queue having front,rear,size,arr,
enQueue,deQueue,isempty,isfull,display members and member function.

*/ 



#include<iostream>
using namespace std;

class queue{
    private:
        int front,rear,size;
    public:
        queue(int x){
            size = x;
            front = rear = -1;
        }
        int *arr = new int[size];
        void enQueue(int);
        int deQueue();
        bool isEmpty();
        bool isFull();
        void display();
};
void queue :: enQueue(int data){
    if(rear == size-1){
        cout<<"Queue overflow"<<endl;
    }else{
        if(rear == -1 && front == -1){
            rear = front = 0;
            rear++;
            arr[rear] = data;
        }else{
            rear++;
            arr[rear] = data;
        }
        
    }
}
int queue :: deQueue(){
    if(rear == front){
        cout<<"Queue is empty"<<endl;
        return -1;
    }else{
        cout<<arr[front]<<" dequeued!"<<endl;
        front++;
        if(front == rear){
            front = rear = -1;
        }
    }
}
bool queue :: isEmpty(){
    if(rear == front){
        cout<<"Queue is empty"<<endl;
        return true;
    }else{
        return false;
    }
}
bool queue :: isFull(){
    if(rear == size-1){
        cout<<"Queue is full"<<endl;
        return true;
    }else{
        return false;
    }
}
void queue :: display(){
    for(int i = front; i < rear; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int size;
    cout<<"Enter size: ";
    cin>>size;
    queue q(size);
    while(1){
        int choice;
        cout<<"1.enQueue\n2.deQueue\n3.isEmpty\n4.isFll\n5.Display\n6.exit\nChoose your option: ";
        cin>>choice;
        switch(choice){
            case 1: int data;
                    cout<<"Enter element: ";
                    cin>>data;
                    q.enQueue(data);
                    break;
            case 2: q.deQueue();
                    break;
            case 3: q.isEmpty();
                    break;
            case 4: q.isFull();
                    break;
            case 5: q.display();
                    break;
            case 6:exit(1); 
                    break;
            default: cout<<"Invalid option"<<endl;
        }
    }
    return 0;
}