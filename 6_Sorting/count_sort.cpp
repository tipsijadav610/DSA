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

        //count sort algorithm
        void count_sort(){
            int i, j, max;

            max = ptr[0];
            for(i=1 ; i < used_size ; i++){
                if(ptr[i] > max){
                    max = ptr[i];
                }
            }

            int *A = new int[max + 1];

            for(i=0 ; i < used_size ; i++){
                A[ptr[i]]++;
            }

            i = j = 0;
            while(i <= max){
                if(A[i] > 0){
                    ptr[j] = i;
                    A[i]--;

                    j++;
                }
                else{
                    i++;
                }
            }

            delete A

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

    arr_ptr->count_sort();

    cout << endl;
    cout << "Array after sorting" << endl;
    arr_ptr->traversal();

    (*arr_ptr).delet_array();

    return 0;
}