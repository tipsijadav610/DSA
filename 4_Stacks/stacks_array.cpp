#include <iostream>
using namespace std;

class Stack{
    private:
        int max_size;
        int top;
        int *ptr;

    public:

    //constructor
    Stack(int max_size){
        this->max_size = max_size;
        top = -1;
        ptr = new int[max_size];
    }

    //getters
    int get_max_size(){
        return max_size;
    }

    int get_top(){
        return top;
    }

    int* get_ptr(){
        return ptr;
    }

    //delete stack
    void delet_stack(){
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

    //push
    void push(int element){
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
    int pop(){
        if(isEmpty()){
            cout << endl;
            cout << "Stack Underflow" << endl;
        
            return -1;
        }
        int val = ptr[top];
        
        top -= 1;

        return val;
    }

    //peek
    int peek(int position){
        if(isEmpty()){
            cout << endl;
            cout << "Stack Underflow" << endl;
            
            return -1;
        }

        return ptr[top - position + 1];
    }

    //stack top
    int stack_top(){
        if(isEmpty()){
            cout << endl;
            cout << "Stack Underflow" << endl;
        
            return -1;
        }

        return ptr[top];
    }

    //stack bottom
    int stack_bottom(){
        if(isEmpty()){
            cout << endl;
            cout << "Stack Underflow" << endl;
        
            return -1;
        }

        return ptr[0];
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
};

int main(){
    int x, max_size, element, position, status;

    cout << "Enter max size you want for array --> ";
    cin >> max_size;

    Stack stk(max_size);
    Stack* stk_ptr = &stk;

    x = 0;
    while(x != -1){
        cout << endl;
        cout << "1 - Push " << endl;
        cout << "2 - Pop " << endl;
        cout << "3 - Is Empty? " << endl;
        cout << "4 - Is Full? " << endl;
        cout << "5 - Peek " << endl;
        cout << "6 - Get top most element " << endl;
        cout << "7 - Get bottom most element " << endl;
        cout << "8 - Stack traversal " << endl;
        cout << "-1 - EXIT" << endl;
        cout << endl;

        cout << "Enter choice --> ";
        cin >> x;

        switch(x){
            case 1:
                cout << endl;
                cout << "Enter element to push --> ";
                cin >> element;

                stk_ptr->push(element);

                break;

            case 2:
                status = stk_ptr->pop();
                if(status != -1){
                    cout << endl;
                    cout << "Popped element from stack = " << status << endl;
                }

                break;

            case 3:
                if(stk_ptr->isEmpty() == 1){
                    cout << endl;
                    cout << "Stack Underflow" << endl;
                }

                break;

            case 4:
                if(stk_ptr->isFull() == 1){
                    cout << endl;
                    cout << "Stack Overflow" << endl;
                }

                break;
            
            case 5:
                cout << endl;
                cout << "Enter position to peek(1 - " << (*stk_ptr).get_top() + 1<< ") --> ";
                cin >> position;

                status = stk_ptr->peek(position);
                if(status != -1){
                    cout << endl;
                    cout << "Peeked element = " << status << endl;
                }

                break;

            case 6:
                status = stk_ptr->stack_top();
                if(status != -1){
                    cout << endl;
                    cout << "Top most element from stack = " << status << endl;
                }

                break;

            case 7:
                status = stk_ptr->stack_bottom();
                if(status != -1){
                    cout << endl;
                    cout << "Bottom most element from stack = " << status << endl;
                }

               break;

            case 8:
                stk_ptr->stack_traversal();

                break;

            default:
                break;
        }
    }

    (*stk_ptr).delet_stack();

    return 0;
}