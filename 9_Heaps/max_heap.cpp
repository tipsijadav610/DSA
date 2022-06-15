#include <iostream>
#include <cmath>
using namespace std;

class MaxHeap{
    private:
        int total_size;
        int used_size;
        int *ptr;

    public:
        //constructer
        MaxHeap(int tsize){
            total_size = tsize;
            used_size = 0;
            ptr = new int[tsize];
        }

        //delete max heap
        void delet_max_heap(){
            delete ptr;
        }

        //print max heap
        void traversal(){
            int i;

            cout<<"current values in max heap"<<endl;
            for(i=0;i<used_size;i++){
                cout << ptr[i] <<" ";
            }
        }

        //insert an element into max heap
        int insertion(int element){
            if(used_size == total_size){
                return -1;
            }

            int i, j;

            used_size += 1;

            i = used_size - 1;
            ptr[i] = element;

            while(i > 0){

                j = floor(i/2);

                if(ptr[i] > ptr[j]){
                    swap(ptr[i], ptr[j]);
                }
                else{
                    break;
                }

                i = j;
            }

            return 1;
        }

        //delete root element from max heap
        int deletion(){            
            if(used_size == 0){
                return -1;
            }
        
            int i, l, r, largest;

            ptr[0] = ptr[used_size - 1];

            used_size -= 1;

            i = 0;

            while(i < used_size){
                largest = i;
                l = 2*largest + 1;
                r = 2*largest + 2;

                if(l < used_size && ptr[l] > ptr[largest]){
                    largest = l;
                }
                if(r < used_size && ptr[r] > ptr[largest]){
                    largest = r;
                }

                if(largest != i){
                    swap(ptr[i], ptr[largest]);

                    i = largest;
                }
                else{
                    break;
                }
            }

            return 1;
        }
};

int main(){
    int x, element, index, status, max_size;

    cout << endl;
    cout << "enter max size you want for max heap --> ";
    cin >> max_size;
    cout << endl;

    MaxHeap heap(max_size);
    MaxHeap* heap_ptr = &heap;

    while(x != -1){
        cout << "1 - insert element" << endl;
        cout << "2 - delete root element" << endl;
        cout << "3 - print max heap " << endl;
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

                status = heap_ptr->insertion(element);
    
                if(status == -1){
                    cout << "insertion failed - (size limit excedded)";
                }

                break;
            case 2:
                status = heap_ptr->deletion();
                
                if(status == -1){
                    cout << "no element to delete";
                }

                break;

            case 3:
                cout << endl;
                heap_ptr->traversal();
                
                break;
            
            default:
                break;
        }

        cout << endl;
        cout << endl;
    }

    (*heap_ptr).delet_max_heap();

    return 0;
}