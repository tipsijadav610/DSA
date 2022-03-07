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

        void delet_array(){
            delete ptr;
        }

        //print array
        void traversal(){
            int i;

            for(i=0;i<used_size;i++){
                cout << ptr[i] <<" ";
            }

            cout << endl;
        }

        //insertion sort algorithm
        void insertion_sort(){
            int i, j, temp, current;

            for(i=1; i<used_size; i++){   

                j = i - 1;
                current = ptr[i]; 
                while(j>=0 && current < ptr[j]){
                    ptr[j + 1] = ptr[j];
                    
                    j--;  
                }

                ptr[j+1] = current;
            } 

            return;
        }
};

int main(){
    int max_size, size;
    int element, status;
    int low, high;

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
    cout << "Array before sorting" << endl;
    arr_ptr->traversal();

    arr_ptr->insertion_sort();

    cout << endl;
    cout << "Array after sorting" << endl;
    arr_ptr->traversal();

    (*arr_ptr).delet_array();

    return 0;
}