#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right; 
        int height;       

        Node(){
            data = 0;
            left = NULL;
            right = NULL;
            int height = 1;
        }

        Node(int data){
            this->data = data;
            this->right = NULL;
            this->left = NULL;
            int height = 1;
        }
};

class AVLTree{
    public:
        Node* root;
     
        AVLTree(){
            root = NULL;
        }

        //get max element
        int max(int a, int b){
            if(a > b){
                return a;
            }
            else{
                return b;
            }
        }

        //get height of tree
        int get_height(Node* n){
            if(n == NULL){
                return 0;
            }
            else{
                return n->height;
            }
        }

        //get balance factor
        int get_balance_factor(Node* n){
            if(n == NULL){
                return 0;
            }
            else{

                return get_height(n->left) - get_height(n->right);
            }
        }

        //right rotate 
        Node* right_rotate(Node* y){
            Node* x = y->left;
            Node* T2 = x->right;

            x->right = y;
            y->left = T2;

            y->height = max(get_height(y->left), get_height(y->right)) + 1;
            x->height = max(get_height(x->left), get_height(x->right)) + 1;

            return x;
        }

        //left rotate 
        Node* left_rotate(Node* x){
            Node* y = x->right;
            Node* T2 = y->left;

            y->left = x;
            x->right = T2;

            y->height = max(get_height(y->left), get_height(y->right)) + 1;
            x->height = max(get_height(x->left), get_height(x->right)) + 1;

            return y;
        }

        //insertion in BST
        Node* insertion(Node* ptr, int key){
            if(ptr == NULL){
                Node* temp = new Node(key); 

                return temp;
            }
            
            if(key < root->data){

                ptr->left = insertion(ptr->left, key);
            }
            if(key > root->data){
                ptr->right = insertion(ptr->right, key);
            }
            if(key == root->data){
                return ptr;
            }
            
            ptr->height = max(get_height(ptr->left), get_height(ptr->right)) + 1;
            
            int bf =  get_balance_factor(ptr);
            
            //left-left
            if(bf > 1 && key < (ptr->left)->data){
                return right_rotate(ptr);
            }

            //right-right
            if(bf < -1 && key > (ptr->right)->data){
                return left_rotate(ptr);
            }

            //left-right
            if(bf > 1 && key > (ptr->left)->data){
                ptr->left = left_rotate(ptr->left);
                return right_rotate(ptr);
            }

            //right-left
            if(bf < -1 && key < (ptr->right)->data){
                ptr->right = right_rotate(ptr->right);
                return left_rotate(ptr);
            }   

            return ptr;
        }

        void insert_key(int key){
            root = insertion(root, key);
        }

        //In order traversal
        void traversal(Node* ptr){
            if(ptr == NULL){
                return;
            }

            traversal(ptr->left);
            cout << ptr->data << " ";
            traversal(ptr->right);

            return;
        }
};

int main(){
    int x, key;

    AVLTree tree;
    AVLTree* tree_ptr = &tree;

    while(x != -1){
        cout << endl;
        cout << "1 - Insert an element in BST" << endl;
        cout << "2 - Print elements of BST" << endl;
        cout << "-1 - EXIT" << endl;
        cout << endl;

        cout << "Enter choice --> ";
        cin >> x;

        cout << endl;
        switch(x){
            case 1:
                cout << "Enter element to insert --> ";
                cin >> key;

                tree_ptr->insert_key(key); 
                break;

            case 2:
                tree_ptr->traversal(tree.root);

                cout << endl;
                break;
 
            default:
                break;
        }
    }  

    return 0;
}