#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5+2;
bool vis[N];
vector<int> adj[N];

void DFS(int node){

    //preOrder
    vis[node] = 1;
    cout<<node<<endl;

    vector<int> :: iterator it;
    for(it = adj[node].begin(); it != adj[node].end(); it++){

            if(vis[*it]){
            }else{
                DFS(*it);
            }
    }

}
int main(){
    int n,m;
    cout<<"Enter no. of vertices and edges: ";
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        vis[i] = 0;
    }
    cout<<"Enter data(adjacency): ";
    int x,y;
    for(int i = 0; i < m; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<"DFS is "<<endl;
    DFS(1);
    return 0;
}