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

class LinkedList{
    public:
        int n;
        Node* head;
     
        //default constructor
        LinkedList(){
            n = 0;
            head = NULL;
        }

        //traversal
        void traversal(){
            Node* ptr;

            if(head == NULL){
                cout << "List is empty" << endl;
                cout << endl;
                
                return;
            }

            ptr = head;

            cout << "Current elements in linked list"<< endl;
            do{
                cout << ptr->data << " ";
                ptr = ptr->next;
            }while(ptr != head);

            cout << endl;
            cout << endl;

            return;
        }
       
        //insertion
        void insertion(int data, char c){
            int i, index;
            
            Node* newNode = new Node(data);
            Node* ptr;

            if(head == NULL){
                head = newNode;

                newNode->next = newNode;

                n += 1;

                return;
            }
            
            if(c == 'a'){
                ptr = head;

                do{
                    ptr = ptr->next;
                }while(ptr->next != head);

                newNode->next = head;

                ptr->next = newNode;
                head = newNode;

            }
            else if(c == 'b'){
                cout << "Enter position(1 - "<< n - 1 <<") --> ";
                cin >> index;

                ptr = head;
                for(i=0 ; i < index - 1 ; i++){
                    ptr = ptr->next;
                }

                newNode->next = ptr->next;
                ptr->next = newNode;
            }
            else{
                ptr = head;

                do{
                    ptr = ptr->next;
                }while(ptr->next != head);

                ptr->next = newNode;
                newNode->next = head;
            }

            n += 1;

            return;
        }

        //deletion
        void deletion(char c){
            int i, index;
            
            Node* ptr;
            Node* temp;

            if(head == NULL){
                cout << "List is empty" << endl;
                cout << endl;
                
                return;
            }

            if(c == 'a'){
                ptr = head;

                do{
                    ptr = ptr->next;
                }while(ptr->next != head);

                temp = head;

                ptr->next = head->next;
                head = head->next;

                delete temp;
            }
            else if(c == 'b'){
                cout << "Enter position(1 - "<< n - 2 <<") --> ";
                cin >> index;

                ptr = head;
                for(i=0 ; i < index - 1; i++){
                    ptr = ptr->next;
                }

                temp = ptr->next;
                ptr->next = temp->next;

                delete temp;
            }
            else{
                ptr = head;
                do{
                    temp=ptr;
                    ptr = ptr->next;
                }while(ptr->next != head);

                temp->next = head;

                delete ptr;
            }
            
            n -= 1;

            return;
        }

        //deletion of circular linked list
        void delete_linked_list(){
            Node* current;
            Node* next;

            current = head;
            do{
                next = current->next;

                delete current;

                current = next;
            }while(current != head);

            head = NULL;
        }
};

int main(){
    int x, data, index;
    char c;
    
    LinkedList list;
    LinkedList* list_ptr = &list;

    while(x != -1){
        cout << "1 - Insert an element in linked list " << endl;
        cout << "2 - Delete an element of linked list " << endl;
        cout << "3 - Delete linked list " << endl;
        cout << "4 - Print elements of linked list " << endl;
        cout << "-1 - EXIT" << endl;
        cout << endl;

        cout << "Enter choice --> ";
        cin >> x;

        cout << endl;
        switch(x){
            case 1:
                cout << "a - Insert at beginning" << endl;
                cout << "b - Insert in between" << endl;
                cout << "c - Insert at end" << endl;
                cout << endl;

                cout << "Enter condition of insertion --> ";
                cin >> c;

                cout << "Enter element to insert --> ";
                cin >> data;

                list_ptr->insertion(data, c); 
              
                cout << endl;
                break;
            case 2:
                cout << "a - Delete at beginning" << endl;
                cout << "b - Delete in between" << endl;
                cout << "c - Delete at end" << endl;
                cout << endl;

                cout << "Enter condition of deletion --> ";
                cin >> c;

                list_ptr->deletion(c);

                cout << endl;
                break;

            case 3:
                list_ptr->delete_linked_list();

                break;

            case 4:
                list_ptr->traversal();

                break;
 
            default:
                break;
        }
    }

    return 0;
}
