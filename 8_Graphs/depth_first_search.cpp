#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void display_graph(list<int> adj_list[]){
    int i;
    
    for(i=0 ; i<7 ; i++){

        cout << i << " ---> ";

        list<int> :: iterator it;
        for(it=adj_list[i].begin() ; it!=adj_list[i].end() ; ++it){
            cout << *it << " ";
        }

        cout << endl;
    }
}

void add_edge(list<int> adj_list[], int u, int v){
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}

//DFS implementation
void DFS_adj_list(list<int> adj_list[], int i, int V[]){
    int j;

    cout << i << " ";
    V[i] = 1;

    list<int> :: iterator it;
    for(it=adj_list[i].begin() ; it!=adj_list[i].end() ; ++it){
        if(V[*it] == 0){
            DFS_adj_list(adj_list, *it, V); 
        }
    }
}

void DFS_adj_mat(int adj_mat[][7], int i, int V[]){
    int j;

    cout << i << " ";
    V[i] = 1;

    for(j=0 ; j<7 ; j++){
        if(adj_mat[i][j] == 1 && V[j] == 0){
            DFS_adj_mat(adj_mat, j, V); 
        }
    }
}

int main(){
    // DFS implementation using adjacency list
    list<int> adj_list[7];

    add_edge(adj_list, 0, 1);
    add_edge(adj_list, 0, 2);
    add_edge(adj_list, 0, 3);
    add_edge(adj_list, 1, 3);
    add_edge(adj_list, 2, 3);
    add_edge(adj_list, 2, 4);
    add_edge(adj_list, 3, 4);
    add_edge(adj_list, 4, 5);
    add_edge(adj_list, 4, 6);

    // display_graph(adj_list);

    int V1[7] = {0,0,0,0,0,0,0};

    cout << endl;
    cout << "Using adjacency list:" << endl;
    DFS_adj_list(adj_list, 4, V1);    

    // DFS implementation using adjacency matrix
    int adj_mat[7][7] = {{0,1,1,1,0,0,0},
                         {1,0,1,0,0,0,0},
                         {1,1,0,1,1,0,0},
                         {1,0,1,0,1,0,0},
                         {0,0,1,1,0,1,1},
                         {0,0,0,0,1,0,0},
                         {0,0,0,0,1,0,0}};

    int V2[7] = {0,0,0,0,0,0,0};

    cout << endl;
    cout << endl;
    cout << "Using adjacency matrix:" << endl;
    DFS_adj_mat(adj_mat, 4, V2);   

    return 0;
}