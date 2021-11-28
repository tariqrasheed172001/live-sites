
/*AIM: Static/Array Implementation of Stack.

ALGORITEHM: using OOPs class stack having size,top,arr,
push,pop,peek,stacktop,isempty,isfull,display members and member function.

*/ 

#include<iostream>
#include<stdlib.h>
using namespace std;

class stack{
    public:
        int size;
        int top;
       stack(int x){
           size = x;
           top= -1;
       }
       int *arr = new int[size];
       void push(int);
       int pop();
       int peek(int);
       int stacktop();
       bool isempty();
       bool isfull();
       void display();
};

void stack :: push(int data){
    if(top == size-1){
        cout<<"-------->Stack oveflow"<<endl;
    }
    else{
        top++;
        arr[top] = data;
    }
}

int stack :: pop(){
    if(top == -1){
        cout<<"------->Stack underflow"<<endl;
        return -1;
    }else{
        int x = arr[top];
        cout<<x<<" ------------>deleted!"<<endl;
        top--;
        return x;
    }
}
int stack :: peek(int position){
    if(top == -1){
        cout<<"--------->Stack is empty"<<endl;
        return -1;
    }else if(top - position + 1 < 0){
        cout<<"------------->Invalid position"<<endl;
        return -1;
    }else{  
        int x = arr[top - position + 1];
        cout<<"------------->Peak element is "<<x<<endl;
        return x;
    }
}
int stack :: stacktop(){
    if(top == -1){
        cout<<"--------->Stack is empty"<<endl;
        return -1;
    }else{
        cout<<"--------->Top most element is "<<arr[top]<<endl;
        return arr[top];
    }
}
bool stack :: isempty(){
    if(top == -1){
        
        return true;
    }else{
        
        return false;
    }
}

bool stack :: isfull(){
    if(top == size-1){
        
        return true;
    }else{
        
        return false;
    }
}
void stack :: display(){
    for(int i = 0; i <= top; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int size;
    cout<<"Enter size: ";
    cin>>size;
    stack st(size);
    while(1){
        int choice;
        cout<<"1.push\n2.pop\n3.peek\n4.top\n5.isEmpty\n6.isFull\n7.Display\n8.exit\nEnter option: ";
        cin>>choice;
        switch(choice){
            case 1: int data;
                    cout<<"Enter element: ";
                    
                    cin>>data;
                    st.push(data);
                    break;
            case 2: st.pop();
                    break;
            case 3: if(!st.isempty()){
                        cout<<"Enter position: ";
                        int pos;
                        cin>>pos;
                        st.peek(pos);
                    }else{
                        cout<<"----------->Stack is empty"<<endl;
                    }
                    break;
            case 4: st.stacktop();
                    break;
            case 5: st.isempty();
                    break;
            case 6: st.isfull();
                    break;
            case 7: st.display();
                    break;
            case 8: exit(1);
                    break;
            default: cout<<"------------------>Invalid option<-----------"<<endl;
                    break;
        }
    }
    return 0;
}