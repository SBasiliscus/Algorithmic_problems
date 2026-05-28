
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;


bool dfs_one_comp(const vector<vector<int>>& graph, int v, vector<int>& visited, stack<int>& route){
    //vector<int>& visited   0: not visited   1: in stack      2: finished
    route.push(v);
    visited[v] = 1;
    for(int x: graph[v]){
        if(visited[x]==0){
            if(dfs_one_comp(graph, x, visited, route)) return true;
        }else if(visited[x]==1){ route.push(x); return true;}
    }
    route.pop();
    visited[v] = 2;    
    return false;
    


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
    }

    vector<int> visited(n,0);
    int visited_cnt = 0;
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            stack<int> route;
            if(dfs_one_comp(graph,i,visited,route)){//hurray
                vector<int> circle; int circleN=1;
                circle.push_back(route.top()); route.pop();
                while(true){
                    int v = route.top(); route.pop();
                    circle.push_back(v);
                    circleN++;
                    if(circle[0]==v) break; 
                }
                cout << circleN << "\n";
                for(int x=circleN-1;x>=0;x--) cout << circle[x]+1 << " ";
                return 0;
            }
            

            visited_cnt = 0;
            for(int a: visited) if(a==2) visited_cnt++;
        }
    }

    cout << "IMPOSSIBLE";







    return 0;

}