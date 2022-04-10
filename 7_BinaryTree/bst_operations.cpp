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

class BinarySearchTree{
    public:
        Node* root;
     
        BinarySearchTree(){
            root = NULL;
        }

        //insertion in BST
        void insertion(int key){
            Node* temp = new Node(key);

            if(root == NULL){
                root = temp;
            }
            else{
                Node* prev = NULL;
                Node* ptr = NULL;

                ptr = root;
                while(ptr != NULL){
                    prev = ptr;  
                    if(ptr->data == key){
                        return;
                    }
                    else{
                        if(key < ptr->data){
                            ptr = ptr->left;
                        }
                        else{
                            ptr = ptr->right;
                        }
                    }
                }

                if(key < prev->data){
                    prev->left = temp;
                }
                else{
                    prev->right = temp;
                }

                return;
            }
        }

        //function to find InOrder Predecessor
        Node* InOrderPredecessor(Node* ptr){
            Node* pre = ptr->left;

            while(pre->right != NULL){
                pre = pre->right;
            }

            return pre;
        }

        Node* delete_node(Node* ptr, int key){
            if(root == NULL){
                NULL;
            }
            
            if(key < ptr->data){
                ptr->left = delete_node(ptr->left, key);
            }
            else if(key > ptr->data){
                ptr->right = delete_node(ptr->right, key);
            }
            else{
                if(ptr->left == NULL && ptr->right == NULL){
                    delete ptr;

                    return NULL;
                    }
                else if(ptr->left == NULL && ptr->right != NULL){
                    Node* temp = ptr->right;
                
                    delete ptr;

                    return temp;
                }
                else if(ptr->left != NULL && ptr->right == NULL){
                    Node* temp = ptr->left;
                
                    delete ptr;

                    return temp;
                }
                else{
                    Node* inPre = InOrderPredecessor(ptr);

                    ptr->data = inPre->data;

                    ptr->left = delete_node(ptr->left, key);
                }
            }

            return ptr;
        }

        //deletion of node from BST
        void deletion(int key){
            root = delete_node(root, key);

            return;
        }

        //InOrder traversal
        void traversal(Node* root){
            if(root == NULL){
                return;
            }

            traversal(root->left);
            cout << root->data << " ";
            traversal(root->right);

            return;
        }  

        //delete entire BST
        void delete_bst(Node* root){
            if(root == NULL){
                return;
            }

            delete_bst(root->left);
            delete_bst(root->right);
            delete root;

            return;
        }      
};

int main(){
    int x, key;

    BinarySearchTree tree;
    BinarySearchTree* tree_ptr = &tree;

    while(x != -1){
        cout << endl;
        cout << "1 - Insert an element in BST" << endl;
        cout << "2 - Delete an element of BST" << endl;
        cout << "3 - Print elements of BST" << endl;
        cout << "-1 - EXIT" << endl;
        cout << endl;

        cout << "Enter choice --> ";
        cin >> x;

        cout << endl;
        switch(x){
            case 1:
                cout << "Enter element to insert --> ";
                cin >> key;

                tree_ptr->insertion(key); 
                break;

            case 2:
                cout << "Enter element to delete --> ";
                cin >> key;

                tree_ptr->deletion(key); 
                break;

            case 3:
                tree_ptr->traversal(tree.root);

                cout << endl;
                break;
 
            default:
                break;
        }
    }    

    tree_ptr->delete_bst(tree.root);

    return 0;
}