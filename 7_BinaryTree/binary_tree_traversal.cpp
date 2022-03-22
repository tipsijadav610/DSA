#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;        

        Node(){
            data = 0;
            left = NULL;
            right = NULL;
        }

        Node(int data){
            this->data = data;
            this->right = NULL;
            this->left = NULL;
        }
};

class BinaryTree{
    public:
        int n;
        Node* root;
     
        BinaryTree(){
            n = 0;
            root = NULL;
        }

        //insertion 
        Node* insertion(int data, Node* parent, char choice){

            Node* temp = new Node(data);

            if(root == NULL){

                root = temp;
            }
            else{
                if(choice == 'l'){
                    if(parent->left == NULL){
                        parent->left = temp;
                    }
                }
                if(choice == 'r'){
                    if(parent->right == NULL){
                        parent->right = temp;
                    }
                }
            }
 
            n++; 

            return temp;
        }

        //Pre order traversal
        void PreOrder(Node* root){
            if(root == NULL){
                return;
            }

            cout << root->data << " ";
            PreOrder(root->left);
            PreOrder(root->right);

            return;
        }
       
        //In order traversal
        void InOrder(Node* root){
            if(root == NULL){
                return;
            }

            InOrder(root->left);
            cout << root->data << " ";
            InOrder(root->right);

            return;
        }

        //Pre order traversal
        void PostOrder(Node* root){
            if(root == NULL){
                return;
            }

            PostOrder(root->left);
            PostOrder(root->right);
            cout << root->data << " ";

            return;
        }
};

int main(){
    int x;

    BinaryTree tree;
    BinaryTree* tree_ptr = &tree;

    Node* e0 = tree_ptr->insertion(10, NULL, 'l');
    Node* e1 = tree_ptr->insertion(11, e0, 'l');
    Node* e2 = tree_ptr->insertion(12, e0, 'r');
    Node* e3 = tree_ptr->insertion(13, e1, 'l');
    Node* e4 = tree_ptr->insertion(14, e1, 'r');
    Node* e5 = tree_ptr->insertion(15, e2, 'l');
    Node* e6 = tree_ptr->insertion(16, e2, 'r');

    while(x != -1){
        cout << "1 - Pre Order " << endl;
        cout << "2 - In Order " << endl;
        cout << "3 - Post Order " << endl;
        cout << "-1 - EXIT" << endl;
        cout << endl;

        cout << "Enter choice --> ";
        cin >> x;

        cout << endl;
        switch(x){
            case 1:
                tree_ptr->PreOrder(e0);

                break;
            case 2:
                tree_ptr->InOrder(e0);

                break;

            case 3:
                tree_ptr->PostOrder(e0);

                break;
            
            default:
                break;
        }
 
        cout << endl;
        cout << endl;
    }    

    delete e0;
    delete e1;
    delete e2;
    delete e3;
    delete e4;
    delete e5;
    delete e6;

    return 0;
}