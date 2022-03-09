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

        void merge_arrays(int low, int mid, int high){
            int i, j, k;
            int temp[high - low + 1];

            i = k = low;
            j = mid + 1;
            while(i<=mid && j<=high){
                if(ptr[i] <= ptr[j]){
                    temp[k] = ptr[i];

                    i++;
                }
                else{
                    temp[k] = ptr[j];

                    j++;
                }

                k++;
            }

            while(i <= mid){
                temp[k] = ptr[i];

                i++;
                k++;
            }

            while(j <= high){
                temp[k] = ptr[j];

                j++;
                k++;
            }

            for(i=low ; i<=high ; i++){
                ptr[i] = temp[i];
            }

            return;
        }

        void sorting(int low, int high){
            if(low < high){
                int mid = (low + high)/2;

                sorting(low, mid);
                sorting(mid + 1, high);

                merge_arrays(low, mid, high);
            }

            return;
        }
        
        //merge sort algorithm
        void merge_sort(){

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

    arr_ptr->merge_sort();

    cout << endl;
    cout << "Array after sorting" << endl;
    arr_ptr->traversal();

    (*arr_ptr).delet_array();

    return 0;
}