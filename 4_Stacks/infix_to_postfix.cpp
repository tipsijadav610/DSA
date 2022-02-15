#include <iostream>
#include <string.h>
using namespace std;

class Stack{
    private:
        int max_size;
        int top;
        char* ptr;

    public:
    //constructor
    Stack(int max_size){
        this->max_size = max_size;
        top = -1;
        ptr = new char[max_size];
    }

    //delete stack
    void delete_stack(){
        delete ptr;

        return;
    }

    //is empty
    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

    //is full
    bool isFull(){
        if(top == max_size - 1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isOperator(char x){
        if(x == '+'){
            return true;
        }
        if(x == '-'){
            return true;
        }
        if(x == '*'){
            return true;
        }
        if(x == '/'){
            return true;
        }

        return false;
    }

    int precedence(char x){
        if(x == '*' || x == '/'){
            return 3;
        }
        if(x == '+' || x == '-'){
            return 2;
        }

        return 0;
    }

    string infix_to_postfix(string expression){
        int i;
        char val;
        string result = "";

        i = 0;
        while(expression[i] != '\0'){
            if(isOperator(expression[i])){
                if(!isEmpty()){
                    if(precedence(expression[i]) > precedence(stack_top())){
                        push(expression[i]);

                        i++;
                    }
                    else{
                        val = pop();
                        result = result + "" + val;
                    }
                }
                else{
                    push(expression[i]);
                    
                    i++;
                }

            }
            else{
                result = result + "" + expression[i];

                i++;
            }
        }

        while(!isEmpty()){
            val = pop();
            result = result + "" + val;
        }

        result = result + '\0';

        return result;
    }

    //stack traversal
    void stack_traversal(){
        if(isEmpty()){
            cout << endl;
            cout << "Stack Underflow" << endl;
        
            return;
        }

        int i;
 
        cout << endl;
        cout<<"Current elements in stack"<<endl;
        for(i=top ; i>=0 ; i--){
            cout << ptr[i] <<" ";
        }

        cout << endl;

        return;
    }

    //stack top
    char stack_top(){
        if(isEmpty()){
            cout << endl;
            cout << "Stack Underflow" << endl;
        
            return -1;
        }

        return ptr[top];
    }

    //push
    void push(char element){
        if(isFull()){
            cout << endl;
            cout << "Stack Overflow" << endl;

            return;
        }

        top += 1;
        ptr[top] = element;

        return;
    }

    //pop
    char pop(){
        if(isEmpty()){
            cout << endl;
            cout << "Stack Underflow" << endl;
        
            return -1;
        }

        char val = ptr[top];
        
        top = top - 1;

        return val;
    }
};

int main(){
    int max_size;
    string result;

    cout << "Enter max size you want for array --> ";
    cin >> max_size;

    Stack stk(max_size);
    Stack* stk_ptr = &stk;
    
    string expression;

    cout << endl;

    cout << "Enter infix expression --> ";
    cin >> expression;
    
    result = stk_ptr->infix_to_postfix(expression);

    cout << "Post expression --> " << result << endl;

    (*stk_ptr).delete_stack();

    return 0;
}