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

class Queue{
    private:
        int n;
        Node* front;
        Node* rear;

    public:
        //constructor
        Queue(){
            n = 0;
            front = NULL;
            rear = NULL;
        }

        //getters
        int get_n(){
            return n;
        }

        Node* get_front(){
            return front;
        }

        Node* get_rear(){
            return rear;
        }

        //delete queue
        void delete_queue(){
            if(isEmpty()){
                return;
            }

            Node* current;
            Node* next;

            current = front;
            while(current != NULL){
                next = current->next;

                delete current;

                current = next;
            }

            front = NULL;
            rear = NULL;
        }

        //is queue empty
        bool isEmpty(){
            if(front == NULL && rear == NULL){
                return true;
            }
            else{
                return false;
            }
        }

        //is queue full
        bool isFull(){
            Node* temp = new Node();

            if(temp == NULL){
                return true;
            }
            else{
                return false;
            }
        }

        //enQueue element at the back
        void enQueue(int element){
            if(isFull()){
                cout << endl;
                cout << "Queue is full" << endl;

                return;
            }

            Node* ptr = new Node(element);

            if(isEmpty()){
                front = ptr;
                rear = ptr;
            }
            else{
                rear->next = ptr;
                rear = ptr;
            }

            n += 1;
         
            return;
        }

        //deQueue front element from queue
        int deQueue(){
            if(isEmpty()){
                cout << endl;
                cout << "No element to deQueue" << endl;
                
                return -1;
            }

            Node* ptr = front;
            int val = ptr->data;

            front = front->next;

            if(front == NULL){
                rear = NULL;
            }

            delete ptr;

            n -= 1;

            return val;
        }

        //get first element from queue
        int first_value(){
            if(isEmpty()){
                cout << endl;
                cout << "Queue is empty" << endl;
                
                return -1;
            }

            return front->data;
        }

        //get last element from queue
        int last_value(){
            if(isEmpty()){
                cout << endl;
                cout << "Queue is empty" << endl;
                
                return -1;
            }

            return rear->data;
        }

        //get element at ith position of queue
        int peek(int position){
            if(isEmpty()){
                cout << endl;
                cout << "Stack Underflow" << endl;
            
                return -1;
            }

            int i;
            Node* ptr;

            ptr = front;

            for(i=0; i<position - 1; i++){
                ptr = ptr->next;
            }

            return ptr->data;
        }

       //traverse element of queue one-by-one
        void queue_traversal(){
            if(isEmpty()){
                cout << endl;
                cout << "No element to deQueue" << endl;     

                return;           
            }

            Node* ptr = front;
 
            cout << endl;
            while(ptr != NULL){
                cout << ptr->data << " ";
                ptr = ptr->next;
            }

            cout << endl;

            return;
        }
};

int main(){
    int x, element, position, status, no_elements;

    Queue que;
    Queue* que_ptr = &que;

    x = 0;
    while(x != -1){
        cout << endl;
        cout << "1 - enQueue" << endl;
        cout << "2 - deQueue" << endl;
        cout << "3 - Is Empty?" << endl;
        cout << "4 - Is Full?" << endl;
        cout << "5 - Peek" << endl;
        cout << "6 - Get first element" << endl;
        cout << "7 - Get last element" << endl;
        cout << "8 - Queue traversal" << endl;
        cout << "-1 - EXIT" << endl;
        cout << endl;

        cout << "Enter choice --> ";
        cin >> x;

        switch(x){
            case 1:
                cout << endl;
                cout << "Enter element to enQueue --> ";
                cin >> element;

                que_ptr->enQueue(element);

                break;

            case 2:
                status = que_ptr->deQueue();
                if(status != -1){
                    cout << endl;
                    cout << "Element dequeued from queue = " << status << endl;
                }

                break;

            case 3:
                if(que_ptr->isEmpty()){
                    cout << endl;
                    cout << "Queue is empty" << endl;
                }

                break;

            case 4:
                if(que_ptr->isFull()){
                    cout << endl;
                    cout << "Queue is full" << endl;
                }

                break;
            
            case 5:
                no_elements = (*que_ptr).get_n();

                cout << endl;
                cout << "Enter position to peek(1 - " << no_elements << ") --> ";
                cin >> position;

                status = que_ptr->peek(position);
                if(status != -1){
                    cout << endl;
                    cout << "Peeked element = " << status << endl;
                }

                break;

            case 6:
                status = que_ptr->first_value();
                if(status != -1){
                    cout << endl;
                    cout << "First element from queue = " << status << endl;
                }

                break;

            case 7:
                status = que_ptr->last_value();
                if(status != -1){
                    cout << endl;
                    cout << "Last element from queue = " << status << endl;
                }

               break;

            case 8:
                que_ptr->queue_traversal();

                break;

            default:
                break;
        }
    }

    (*que_ptr).delete_queue();

    return 0;
}