
/*AIM: Implementation of infix to postfix expression using stack.

LGORITHEM: 
1. Scan the infix expression from left to right. 
2. If the scanned character is an operand, output it. 
3. Else, 
      1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty or the stack contains a ‘(‘ ), push it. 
      2 Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
4. If the scanned character is an ‘(‘, push it to the stack. 
5. If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
6. Repeat steps 2-6 until infix expression is scanned. 
7. Print the output 
8. Pop and output from the stack until it is not empty.
*/

#include<iostream>
#include<stack>
using namespace std;
 

int prec(char c) {
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}
 

void infixToPostfix(string s) {
 
    stack<char> st; //For stack operations, we are using C++ built in stack(STL)
    string result;
 
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
 
        
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;
 
       
        else if(c == '(')
            st.push('(');
        else if(c == ')') {
            while(st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while(!st.empty() && prec(s[i]) <= prec(st.top())) {
                result += st.top();
                st.pop(); 
            }
            st.push(c);
        }
    }
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }
 
    cout << result << endl;
}
 
int main() {

    string exp;
    cout<<"Enter infix string : ";
    cin>>exp;
    infixToPostfix(exp);
    return 0;
}