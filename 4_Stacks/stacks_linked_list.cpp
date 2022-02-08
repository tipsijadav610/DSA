#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        

        Node(){
            data = 0;
            next = NULL;
        }

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class Stack{
    public:
        int n;
        Node* top;

        //constructos
        Stack(){
            n = 0;
            top = NULL;
        }

        //delete stack
        void delete_stack(){
            if(isEmpty()){
                return;
            }

            Node* current;
            Node* next;

            current = top;
            while(current != NULL){
                next = current->next;

                delete current;

                current = next;
            }

            top = NULL;
        }

        //is empty 
        bool isEmpty(){
            if(top == NULL){
                return true;
            }
            else{
                return false;
            }
        }

        //is full
        bool isFull(){
            Node* ptr = new Node;

            if(ptr ==  NULL){
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

            Node* ptr = new Node(element);

            ptr->next = top;

            top = ptr;

            n += 1;

            return;
        }

        //pop
        int pop(){
            if(isEmpty()){
                cout << endl;
                cout << "Stack Underflow" << endl;
        
                return -1;
            }

            int val;
            Node* ptr;

            ptr = top;

            val = ptr->data;
            top = top->next;

            delete ptr;

            n -= 1; 

            return val;
        }

        //peek
        int peek(int position){
            if(isEmpty()){
                cout << endl;
                cout << "Stack Underflow" << endl;
        
                return -1;
            }

            int i;
            Node* ptr;

            ptr = top;
            for(i=0 ; i<position - 1 ; i++){
                ptr = ptr->next;
            }

            return ptr->data;
        }

        //stack top
        int stack_top(){
            if(isEmpty()){
                cout << endl;
                cout << "Stack Underflow" << endl;
        
                return -1;
            }

            return top->data;
        }

        //stack bottom
        int stack_bottom(){
            if(isEmpty()){
                cout << endl;
                cout << "Stack Underflow" << endl;
        
                return -1;
            }

            Node* ptr;

            ptr = top;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }

            return ptr->data;
        }

        //stack traversal
        void stack_traversal(){
            if(isEmpty()){
                cout << endl;
                cout << "Stack Underflow" << endl;
        
            }

            Node* ptr = top;

            cout << endl;
            cout<<"Current elements in stack"<<endl;
            while(ptr != NULL){
                cout << ptr->data << " ";
                ptr = ptr->next;
            }

            cout << endl;

            return;
        }
};

int main(){
    int x, element, position, status;

    Stack stk;
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
                cout << "Enter position to peek(1 - " << (*stk_ptr).n<< ") --> ";
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

    (*stk_ptr).delete_stack();

    return 0;
}