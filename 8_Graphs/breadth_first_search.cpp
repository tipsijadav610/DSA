#include <iostream>
#include <queue>
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

//BFS implementation
void BFS_adj_list(list<int> adj_list[]){
    int i=4, u;
    int V[7] = {0};    
    queue<int> E;

    V[i] = 1;
    E.push(i);

    cout << i << " ";

    while(!E.empty()){
        u = E.front();
        E.pop();

        list<int> :: iterator it;
        for(it=adj_list[u].begin() ; it!=adj_list[u].end() ; ++it){
    
            if(V[*it] != 1){
                cout << *it << " ";

                V[*it] = 1;
                E.push(*it);
            }
        }
    }
}

void BFS_adj_mat(int adj_mat[][7]){
    int i=4, j, u;
    int V[7] = {0};
    queue<int> E;

    V[i] = 1;
    E.push(i);

    cout << i << " ";

    while(!E.empty()){
        u = E.front();
        E.pop();

        for(j=0 ; j<7 ; j++){
    
            if(adj_mat[u][j] == 1 && V[j] != 1){
                cout << j << " ";

                V[j] = 1;
                E.push(j);
            }
        }
    }
}

int main(){
    // BFS implementation using adjacency list
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
    
    cout << endl;
    cout << "Using adjacency list:" << endl;
    BFS_adj_list(adj_list);    

    // BFS implementation using adjacency matrix
    int adj_mat[7][7] = {{0,1,1,1,0,0,0},
                         {1,0,1,0,0,0,0},
                         {1,1,0,1,1,0,0},
                         {1,0,1,0,1,0,0},
                         {0,0,1,1,0,1,1},
                         {0,0,0,0,1,0,0},
                         {0,0,0,0,1,0,0}};
    
    cout << endl;
    cout << endl;
    cout << "Using adjacency matrix:" << endl;
    BFS_adj_mat(adj_mat);  

    return 0;
}