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
            while(ptr != NULL){
                cout << ptr->data << " ";
                ptr = ptr->next;
            }

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

                n += 1;

                return;
            }
            
            if(c == 'a'){
                newNode->next = head;
                head = newNode;
            }
            else if(c == 'b'){
                cout << "Enter position(1 - "<< n - 1<<") --> ";
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
                while(ptr->next != NULL){
                    ptr = ptr->next;
                }

                ptr->next = newNode;
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
                head = head->next;

                delete ptr;
            }
            else if(c == 'b'){
                cout << "Enter position(0 - "<< n - 1 <<") --> ";
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
                while(ptr->next != NULL){
                    temp = ptr;
                    ptr = ptr->next;
                }

                temp->next = NULL;

                delete ptr;
            }
            
            n -= 1;

            return;
        }

        //delete linked list
        void delete_linked_list(){
            Node* current;
            Node* next;

            current = head;
            while(current != NULL){
                next = current->next;

                delete current;

                current = next;
            }

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