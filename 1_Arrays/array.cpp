#include <iostream>
using namespace std;

class MyArray{
    private:
        int total_size;
        int used_size;
        int *ptr;

    public:
        //constructer
        MyArray(int tsize, int usize){
            total_size = tsize;
            used_size = usize;
            ptr = new int[tsize];
        }

        //getters
        int get_total_size(){
            return total_size;
        }

        int get_used_size(){
            return used_size;
        }

        int* get_ptr(){
            return ptr;
        }
   
        //takes input for values of array
        void set_array(){
            int i, inp;

            cout<<"Enter values for array"<<endl;
            for(i=0; i<used_size; i++){
                cin >> inp;
                ptr[i] = inp;
            }
        }

        //delete array
        void delet_array(){
            delete ptr;
        }

        //print array
        void traversal(){
            int i;

            cout<<"Current values in array"<<endl;
            for(i=0;i<used_size;i++){
                cout << ptr[i] <<" ";
            }

            cout << endl;
            cout << endl;
        }

        //insert an element into the array
        int insertion(int element, int index){
            int i;
            
            if(used_size >= total_size){
                return -1;
            }
    
            if(index > used_size){
                return -1;
            }

            for(i=used_size; i >= index; i--){
                ptr[i+1] = ptr[i];
            }

            ptr[index] = element;

            used_size += 1;

            return 1;
        }

        //delete and element in an array
        int deletion(int index){
            int i;
            
            if(index >= used_size){
                return -1;
            }

            for(i=index; i < used_size - 1; i++){
                ptr[i] = ptr[i+1];
            }

            used_size -= 1;

            return 1;
        }
};

int main(){
    int max_size, size;
    int x, element, index;
    int status;

    cout << "Enter max size you want for array --> ";
    cin >> max_size;

    cout << "Enter size of array you want to use --> ";
    cin >> size;

    MyArray arr(max_size, size);
    MyArray* arr_ptr = &arr;


    //setting array
    cout << endl;
    (*arr_ptr).set_array();

    cout << endl;
    (*arr_ptr).traversal();

    while(x != -1){
        cout << "1 - Insert element in array " << endl;
        cout << "2 - Delete element in array " << endl;
        cout << "3 - Print element of array " << endl;
        cout << "-1 - EXIT" << endl;
        cout << endl;

        cout << "Enter choice --> ";
        cin >> x;

        cout << endl;
        switch(x){
            case 1:
                //insertion of an element
                cout << endl;
                cout << "Enter element to insert --> ";
                cin >> element;
    
                cout << endl;
                cout << "Enter position(0 - " << (arr_ptr->get_used_size() - 1) << ") --> ";
                cin >> index;

                status = (*arr_ptr).insertion(element, index);
    
                if(status == -1){
                    cout << "Insertion failed - (size limit excedded)";
                    cout << endl;
                    cout << endl;
                }
                else{
                    cout << endl;
                    (*arr_ptr).traversal();
                }

                break;
            case 2:
                //deletion of an element
                cout << endl;
                cout << "Enter position to delete(0 - " << (arr_ptr->get_used_size() - 1) << ") --> ";
                cin >> index;

                status = (*arr_ptr).deletion(index);
                
                if(status == -1){
                    cout << "Deletion failed - (size limit excedded)";
                    cout << endl;
                    cout << endl;
                }
                else{
                    cout << endl;
                    (*arr_ptr).traversal();
                }
                break;

            case 3:
                cout << endl;
                (*arr_ptr).traversal();
                break;
            
            default:
                break;
        }
    }

    (*arr_ptr).delet_array();

    return 0;
}