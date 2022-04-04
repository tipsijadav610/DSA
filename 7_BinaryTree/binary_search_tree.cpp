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

        //searching in BST
        bool searching_bst_rec(Node* root, int element){
            if(root == NULL){
                return false;
            }
            else{
                if(root->data == element){
                    return true;
                }
                else{
                    if(element < root->data){
                        return searching_bst_rec(root->left, element); 
                    }
                    else{
                        return searching_bst_rec(root->right, element);
                    }
                }
            }
        }

        bool searching_bst_iter(int element){
            Node* temp = root;

            while(temp != NULL){
                if(temp->data == element){
                    return true;
                }
                else{
                    if(element < temp->data){
                        temp = temp->left;
                    }
                    else{
                        temp = temp->right;
                    }
                }
            }

            return false;
        }
};

int main(){
    int x, element;
    char choice;

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

    while(true){
        //To continue loop or not
        cout << "1 - Continue " << endl;
        cout << "-1 - Exit Loop" << endl;
        cout << endl;

        cout << "Enter choice --> ";
        cin >> x;

        if(x == -1){
            break;
        }        

        //Entering number to search
        cout << endl;
        cout << "Enter number to find --> ";
        cin >> element;
        
        cout << endl;

        //Entering method
        cout << "a - Recursion" << endl;
        cout << "b - Iteration" << endl;
        cout << endl;

        cout << "Enter Method --> ";
        cin >> choice;

        cout << endl;
        if(choice == 'a'){
            if(tree_ptr->searching_bst_rec(e0, element)){
                cout << "Element is found" << endl;
            }
            else{
                cout << "Element is not found" << endl;
            }
        }
        else{
            if(tree_ptr->searching_bst_iter(element)){
                cout << "Element is found" << endl;
            }
            else{
                cout << "Element is not found" << endl;
            }            
        }

        cout << endl;
    }   

    delete e0;
    delete e1;
    delete e2;
    delete e3;
    delete e4;

    return 0;
}