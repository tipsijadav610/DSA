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

        //heapify algorithm
        void heapify(int i, int n){
            int l, r, largest;

            largest = i;
            l = 2*largest + 1;
            r = 2*largest + 2;

            if(l < n && ptr[l] > ptr[largest]){
                largest = l;
            }
            if(r < n && ptr[r] > ptr[largest]){
                largest = r;
            }

            if(largest != i){
                swap(ptr[i], ptr[largest]);

                heapify(largest, n);
            }
        }

        //heap sort algorithm
        void heap_sort(){
            int i;

            for(i = used_size - 1 ; i >= 0 ; i--){
                heapify(i, used_size);
            }

            for(i = used_size - 1 ; i >= 0 ; i--){
                swap(ptr[0], ptr[i]);

                heapify(0, i);
            }
        }
};

int main(){
    int max_size, size;
    int element, status;
    int low, high;

    cout << endl;

    cout << "Enter max size you want for array --> ";
    cin >> max_size;

    cout << endl;

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

    arr_ptr->heap_sort();

    cout << endl;
    cout << "Array after sorting" << endl;
    arr_ptr->traversal();

    (*arr_ptr).delet_array();

    return 0;
}