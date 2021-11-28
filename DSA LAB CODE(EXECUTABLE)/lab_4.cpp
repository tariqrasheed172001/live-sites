/*AIM: Implementation of postfix expression evaluation using stack.

ALGORITHEM: 

1) Create a stack to store operands (or values). 
2) Scan the given expression and do the following for every scanned element. 
-->a) If the element is a number, push it into the stack 
-->b) If the element is an operator, pop operands for the operator from the stack. Evaluate the operator and push the result back to the stack 
3) When the expression is ended, the number in the stack is the final answer 

*/ 
#include <iostream>
using namespace std;
 
// Stack type
class Stack
{
    public:
    int top;
    unsigned capacity;
    int* array;
};
 
// Stack Operations
Stack* createStack( unsigned capacity )
{
    Stack* stack = new Stack();
 
    if (!stack) return NULL;
 
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = new int[(stack->capacity * sizeof(int))];
 
    if (!stack->array) return NULL;
 
    return stack;
}
 
int isEmpty(Stack* stack)
{
    return stack->top == -1 ;
}
 
int peek(Stack* stack)
{
    return stack->array[stack->top];
}
 
int pop(Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}
 
void push(Stack* stack,int op)
{
    stack->array[++stack->top] = op;
}
 
 

int evaluatePostfix(char* exp)
{

    Stack* stack = createStack(strlen(exp));
    int i;
 

    if (!stack) return -1;
 

    for (i = 0; exp[i]; ++i)
    {
     
        if(exp[i] == ' ')continue;
         
        
        else if (isdigit(exp[i]))
        {
            int num=0;
             
           
            while(isdigit(exp[i]))
            {
            num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            i--;
             
          
            push(stack,num);
        }
         
  
        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);
             
            switch (exp[i])
            {
            case '+': push(stack, val2 + val1); break;
            case '-': push(stack, val2 - val1); break;
            case '*': push(stack, val2 * val1); break;
            case '/': push(stack, val2/val1); break;
             
            }
        }
    }
    return pop(stack);
}
 

int main()
{
    char exp[] = "100 200 + 2 / 5 * 7 +";
    cout <<"Result is "<< evaluatePostfix(exp)<<endl;
    return 0;
}