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

        int partition(int low, int high){
            int p = low;
            int i, j, temp;

            i = p + 1;
            j = high;
            
            do{
                while(ptr[i] <= ptr[p]){
                    i++;
                }
                
                while(ptr[j] > ptr[p]){
                    j--;
                }
                
                if(i < j){
                    temp = ptr[i];
                    ptr[j] = ptr[i];
                    ptr[i] = temp;
                }
            }while(i < j);

            temp = ptr[j];
            ptr[j] = ptr[p];
            ptr[p] = temp;

            return j;
        }

        void sorting(int low, int high){
            if(low < high){
                int pivot = partition(low, high);

                sorting(low, pivot - 1);
                sorting(pivot + 1, high);
            }

            return;
        }

        //quick sort algorithm
        void quick_sort(){

            sorting(0, used_size - 1);

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

    arr_ptr->quick_sort();

    cout << endl;
    cout << "Array after sorting" << endl;
    arr_ptr->traversal();

    (*arr_ptr).delet_array();

    return 0;
}