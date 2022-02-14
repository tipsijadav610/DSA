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

    //Entering string
    int parenthesis_matching(string expression){
        int i;

        for(i=0 ; i<expression.size() ; i++){
            if(expression[i] == '(' || expression[i] == '[' || expression[i] == '{'){
                push(expression[i]);
            }
            if(expression[i] == ')' || expression[i] == ']' || expression[i] == '}'){
                if(isEmpty()){
                    return -1;
                }

                char val = pop();

                switch(expression[i]){
                    case ')':
                        if(val == '[' || val == '{'){
                            return -1;
                        }

                        break;  

                    case ']':
                        if(val == '(' || val == '{'){
                            return -1;
                        }

                        break;
           
                    case '}':
                        if(val == '(' || val == '['){
                            return -1;
                        }

                        break;
                 }
            }
        }

        if(!isEmpty()){
            return -1;
        }

        return 1;
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
        char val = ptr[top];
        
        top = top - 1;

        return val;
    }
};

int main(){
    int max_size, status;

    cout << "Enter max size you want for array --> ";
    cin >> max_size;

    Stack stk(max_size);
    Stack* stk_ptr = &stk;
    
    string expression;

    cout << endl;

    cout << "Enter expression --> ";
    cin >> expression;
    
    status = stk_ptr->parenthesis_matching(expression);

    cout << endl;
    if(status == -1){
        cout << "Parenthesis aren't balanced" << endl;
    }
    else{
        cout << "Parenthesis are balanced" << endl;
    }

    (*stk_ptr).delete_stack();

    return 0;
}