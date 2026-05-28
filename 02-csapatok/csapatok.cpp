
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


bool bfs(const vector<vector<int>>& graph, vector<bool>& group){
    int n= graph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=true; q.push(i); group[i] = 1; //hiszen ez egy új komponens kezdete
            while(!q.empty()){
                int v = q.front();q.pop();
                bool nextcolor = !group[v];
                for(int x: graph[v]){
                    if(visited[x]){
                        if(group[x] != nextcolor) return false;
                    }else{
                        q.push(x);
                        group[x] = nextcolor;
                        visited[x] = true;
                    }
                }
            }
        }
    }

    return true;


}




int main() {

	int n; cin >> n;
    int m; cin >> m;

    vector<vector<int>> graph (n);
    for (int i = 0 ;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;b--; //0-as indexelést nyomok ugye
        graph[a].push_back(b);
        graph[b].push_back(a);  
    }

    vector<bool> group(n);
    if(bfs(graph,group)){
        for(int i=0;i<n;i++)
        cout<<(group[i]?"1 ":"2 ");

    }else cout << "IMPOSSIBLE";







    return 0;

}