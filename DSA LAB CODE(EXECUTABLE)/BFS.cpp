# include <iostream>
#include<vector>
# include <queue>
using namespace std;
const int N= 1e5+2;
bool visit[N];
vector<int> adj[N];
int main(){
    for(int i  = 0; i < N; i++)
    visit[i]=0;
    int n,m;
    cout<<"Enter number of vertices and edges : ";
    cin>>n>>m;
    int x,y;
    cout<<"Enter data(adjacency)"<<endl;
    for(int i = 0; i < m; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<"BFS is "<<endl;
    queue<int> q;
    q.push(1);
    visit[1] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<endl;

        vector<int> :: iterator it;
        for(it = adj[node].begin(); it != adj[node].end(); it++){
            if(!visit[*it]){
                visit[*it] = 1;
                q.push(*it);
            }
        }
    }
    return 0;
}
