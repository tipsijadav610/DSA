#include <iostream>
using namespace std;

class Queue{
    private:
        int front;
        int rear;
        int max_size;
        int* ptr;

    public:
        //constructor
        Queue(int max_size){
            this->max_size = max_size;
            front = -1;
            rear = -1;
            ptr = new int[max_size];
        }

        //getters
        int get_front(){
            return front;
        }

        int get_rear(){
            return rear;
        }

        int get_max_size(){
            return max_size;
        }

        int* get_ptr(){
            return ptr;
        }
        
        //delete queue
        void delete_queue(){
            delete ptr;

            return;
        }

        //is queue empty
        bool isEmpty(){
            if(front == rear){
                return true;
            }
            else{
                return false;
            }
        }

        //is queue full
        bool isFull(){
            if(rear == max_size -1){
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

            rear += 1;
            ptr[rear] = element;

            return;
        }

        //deQueue front element from queue
        int deQueue(){
            if(isEmpty()){
                cout << endl;
                cout << "No element to deQueue" << endl;
                
                return -1;
            }

            front += 1;
            return ptr[front];
        }

        //get first element from queue
        int first_value(){
            if(isEmpty()){
                cout << endl;
                cout << "Queue is empty" << endl;
                
                return -1;
            }

            return ptr[front + 1];
        }

        //get last element from queue
        int last_value(){
            if(isEmpty()){
                cout << endl;
                cout << "Queue is empty" << endl;
                
                return -1;
            }

            return ptr[rear];
        }

        //get element at ith position of queue
        int peek(int position){
            if(isEmpty()){
                cout << endl;
                cout << "Stack Underflow" << endl;
            
                return -1;
            }

            return ptr[front + position];
        }

       //traverse element of queue one-by-one
        void queue_traversal(){
            if(isEmpty()){
                cout << endl;
                cout << "No element to deQueue" << endl;     

                return;           
            }

            int i;

            cout << endl;
            for(i=front+1 ; i <= rear ; i++){
                cout << ptr[i] << " ";
            }

            cout << endl;

            return;
        }
};

int main(){
    int x, max_size, element, position, status, no_elements;

    cout << "Enter max size you want for array --> ";
    cin >> max_size;

    Queue que(max_size);
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
                no_elements = (*que_ptr).get_rear() - (*que_ptr).get_front();

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