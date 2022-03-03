#include <iostream>
using namespace std;

class Queue{
    private:
        int front1;
        int rear1;
        int front2;
        int rear2;
        int max_size;
        int* ptr;

    public:
        //constructor
        Queue(int max_size){
            this->max_size = max_size;
            front1 = -1;
            rear1 = -1;
            front2 = -1;
            rear2 = -1;
            ptr = new int[max_size];
        }

        //getters
        int get_front1(){
            return front1;
        }

        int get_rear1(){
            return rear1;
        }

        int get_front2(){
            return front2;
        }

        int get_rear2(){
            return rear2;
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
            if(front1 == rear1 && front2 == rear2){
                return true;
            }
            else{
                return false;
            }
        }

        //is queue full
        bool isFull_front(){
            if(front1 == -1 && rear1 == 0){
                cout << 1 << endl;
                return true;
            }
            else{
                return false;
            }
        }

        bool isFull_rear(){
            if(front2 == max_size && rear2 == max_size - 1){
                cout << 1 << endl;
                return true;
            }
            else{
                return false;
            }
        }

        //enQueue element at the back
        void enQueue_front(int element){
            if(isFull_front()){
                cout << endl;
                cout << "Queue is full from front" << endl;

                return;
            }

            if(isEmpty()){
                rear1 += 1;
                rear2 += 1;
                front2 = rear2 + 1;
            }
            else{
                rear1 -= 1;
                front1 = rear1 - 1;
            }

            ptr[rear1] = element;

            return;
        }

        void enQueue_rear(int element){
            if(isFull_rear()){
                cout << endl;
                cout << "Queue is full from back" << endl;

                return;
            }

            if(isEmpty()){
                rear1 += 1;
                rear2 += 1;
                front2 = rear2 + 1;
            }
            else{
                rear2 += 1;
                front2 = rear2 + 1;
            }

            ptr[rear2] = element;

            return;
        }

        //deQueue front element from queue
        int deQueue_front(){
            if(isEmpty()){
                cout << endl;
                cout << "No element to deQueue" << endl;
                
                return -1;
            }

            int val = ptr[front1 + 1];

            front1 += 1;
            rear1 += 1;

            return val;
        }

        int deQueue_rear(){
            if(isEmpty()){
                cout << endl;
                cout << "No element to deQueue" << endl;
                
                return -1;
            }

            int val = ptr[front2 - 1];

            front2 -= 1;
            rear2 -= 1;

            return val;
        }

        //get first element from queue
        int first_value_front(){
            if(isEmpty()){
                cout << endl;
                cout << "Queue is empty" << endl;
                
                return -1;
            }

            return ptr[front1 + 1];
        }

        int first_value_rear(){
            if(isEmpty()){
                cout << endl;
                cout << "Queue is empty" << endl;
                
                return -1;
            }

            return ptr[front2 - 1];
        }

        //get last element from queue
        int last_value_front(){
            if(isEmpty()){
                cout << endl;
                cout << "Queue is empty" << endl;
                
                return -1;
            }

            return ptr[rear1];
        }

        int last_value_rear(){
            if(isEmpty()){
                cout << endl;
                cout << "Queue is empty" << endl;
                
                return -1;
            }

            return ptr[rear2];
        }

        //get element at ith position of queue
        int peek_front(int position){
            if(isEmpty()){
                cout << endl;
                cout << "Stack Underflow" << endl;
            
                return -1;
            }

            return ptr[front1 + position];
        }

        int peek_rear(int position){
            if(isEmpty()){
                cout << endl;
                cout << "Stack Underflow" << endl;
            
                return -1;
            }

            return ptr[front2 - position];
        }

       //traverse element of queue one-by-one
        void queue_traversal_front(){
            if(isEmpty()){
                cout << endl;
                cout << "No element to deQueue" << endl;     

                return;           
            }

            int i;

            cout << endl;
            for(i=front1+1 ; i <= rear2 ; i++){
                cout << ptr[i] << " ";
            }

            cout << endl;

            return;
        }

        void queue_traversal_rear(){
            if(isEmpty()){
                cout << endl;
                cout << "No element to deQueue" << endl;     

                return;           
            }

            int i;

            cout << endl;
            for(i=front2-1 ; i >= rear1 ; i--){
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
        cout << "1 - enQueue from front" << endl;
        cout << "2 - enQueue from rear" << endl;
        cout << "3 - deQueue from front" << endl;
        cout << "4 - deQueue from rear" << endl;
        cout << "5 - Is Empty?" << endl;
        cout << "6 - Is Full from front?" << endl;
        cout << "7 - Is Full from rear?" << endl;
        cout << "8 - Peek from front" << endl;
        cout << "9 - Peek from rear" << endl;
        cout << "10 - Get first element from front" << endl;
        cout << "11 - Get first element from rear" << endl;
        cout << "12 - Get last element from front" << endl;
        cout << "13 - Get last element from rear" << endl;
        cout << "14 - Queue traversal from front" << endl;
        cout << "15 - Queue traversal from rear" << endl;
        cout << "-1 - EXIT" << endl;
        cout << endl;

        cout << "Enter choice --> ";
        cin >> x;

        switch(x){
            case 1:
                cout << endl;
                cout << "Enter element to enQueue --> ";
                cin >> element;

                que_ptr->enQueue_front(element);

                break;

            case 2:
                cout << endl;
                cout << "Enter element to enQueue --> ";
                cin >> element;

                que_ptr->enQueue_rear(element);

                break;               

            case 3:
                status = que_ptr->deQueue_front();
                if(status != -1){
                    cout << endl;
                    cout << "Element dequeued from queue = " << status << endl;
                }

                break;

            case 4:
                status = que_ptr->deQueue_rear();
                if(status != -1){
                    cout << endl;
                    cout << "Element dequeued from queue = " << status << endl;
                }

                break;

            case 5:
                if(que_ptr->isEmpty()){
                    cout << endl;
                    cout << "Queue is empty" << endl;
                }

                break;

            case 6:
                if(que_ptr->isFull_front()){
                    cout << endl;
                    cout << "Queue is full from front" << endl;
                }

                break;

            case 7:
                if(que_ptr->isFull_rear()){
                    cout << endl;
                    cout << "Queue is full from rear" << endl;
                }

                break;
            
            case 8:
                no_elements = (*que_ptr).get_rear2() - (*que_ptr).get_front1();

                cout << endl;
                cout << "Enter position to peek(1 - " << no_elements << ") --> ";
                cin >> position;

                status = que_ptr->peek_front(position);
                if(status != -1){
                    cout << endl;
                    cout << "Peeked element = " << status << endl;
                }

                break;

            case 9:
                no_elements = (*que_ptr).get_front2() - (*que_ptr).get_rear1();

                cout << endl;
                cout << "Enter position to peek(1 - " << no_elements << ") --> ";
                cin >> position;

                status = que_ptr->peek_rear(position);
                if(status != -1){
                    cout << endl;
                    cout << "Peeked element = " << status << endl;
                }

                break;

            case 10:
                status = que_ptr->first_value_front();
                if(status != -1){
                    cout << endl;
                    cout << "First element from front = " << status << endl;
                }

                break;

            case 11:
                status = que_ptr->first_value_rear();
                if(status != -1){
                    cout << endl;
                    cout << "First element from rear = " << status << endl;
                }

                break;

            case 12:
                status = que_ptr->last_value_front();
                if(status != -1){
                    cout << endl;
                    cout << "Last element from front = " << status << endl;
                }

               break;

            case 13:
                status = que_ptr->last_value_rear();
                if(status != -1){
                    cout << endl;
                    cout << "Last element from rear = " << status << endl;
                }

               break;

            case 14:
                que_ptr->queue_traversal_front();

                break;

            case 15:
                que_ptr->queue_traversal_rear();

                break;

            default:
                break;
        }
    }

    (*que_ptr).delete_queue();

    return 0;
}