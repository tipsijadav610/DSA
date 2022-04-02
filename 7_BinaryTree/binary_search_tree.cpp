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

        //Is BST
        bool IsBST(Node* root){
            static Node* prev = NULL;

            if(root == NULL){
                return true;
            }
            else{
                if(!IsBST(root->left)){
                    return false;
                }
                if(prev != NULL && root->data <= prev->data){
                    return false;
                }
                prev = root;

                return IsBST(root->right);
            }
        }
};

int main(){
    int x;

    BinaryTree tree;
    BinaryTree* tree_ptr = &tree;

    Node* e0 = tree_ptr->insertion(7, NULL, 'l');
    Node* e1 = tree_ptr->insertion(5, e0, 'l');
    Node* e2 = tree_ptr->insertion(9, e0, 'r');
    Node* e3 = tree_ptr->insertion(3, e1, 'l');
    Node* e4 = tree_ptr->insertion(6, e1, 'r');

    cout << endl;
    if(tree_ptr->IsBST(e0)){
        cout << "Is BST" << endl;
    }
    else{
        cout << "Is not BST" << endl;
    }

    cout << endl;
    tree_ptr->InOrder(e0);
    cout << endl;
    cout << endl;

    delete e0;
    delete e1;
    delete e2;
    delete e3;
    delete e4;

    return 0;
}