
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Edge{
    int node;
    Edge* next;
};

void pushFront(Edge*& head, int val){
    Edge* newedge = new Edge{val,head};
    head = newedge;
}


vector<int> bfs_a_b(vector<Edge*>& edges, int a, int b){
    int n = edges.size();
    vector<bool> visited(n,false);
    vector<int> parent(n,-1);

    queue<int> q;

    q.push(a);
    visited[a] = true;

    while(!q.empty()){
        int actnod = q.front(); q.pop();
        if(actnod == b) break; //done

        Edge* current = edges[actnod];
        while(current!=nullptr){
            if(!visited[current->node ]){
                parent[current->node ] = actnod;
                q.push(current->node);
                visited[current->node]=true;
            }

            
            current = current -> next;
        }

    }

    

    if(!visited[b]) return vector<int> {-1};
    vector<int> route;
    route.push_back(b);
    while(true){
        int x = parent[route.back()];
        route.push_back(x);
        if(x==a) break;

    }
    return route;
}




int main() {

	int n; cin >> n;
    int m; cin >> m;

    vector<Edge*> edges(n, nullptr); //index a kiindulási csúcs

    for (int i = 0 ;i<m;i++){
        int a,b;
        cin >> a >> b;
        pushFront(edges[a-1],b-1);
        pushFront(edges[b-1],a-1);
        
    }

    vector<int> route = bfs_a_b(edges,0,n-1);
    if(route[0]==-1){
        cout << "IMPOSSIBLE";
    } else {
        reverse(route.begin(),route.end());
        cout << route.size()<<"\n";
        for (int i : route){
            cout << i+1 << " ";
        }


    }






    return 0;

}