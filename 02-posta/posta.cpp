
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
using namespace std;



vector<int> euler(const vector<vector<pair<int,int>>>& graph, int m){
    //csak akkor van meghívha ha létezik körséta (nincs páratlan fokú csúcs, és 0-ás csúcs nem izolált)
    int start_node = 0;
    vector<bool> used(m, false);
    int act_node = start_node;
    vector<int> sol;
    stack<int> st;
    bool unused_edge=true;
    while(unused_edge){


        do {
        // cout << act_node+1 << " " ;
        
            st.push(act_node);
            for(auto p : graph[act_node]){
                int x = p.first;
                int id = p.second;
                if(!used[id]){ //mindig lesz ilyen, hiszen minden csúcs páros bla bla bla
                    //cout<<i++<<". edge: " << act_node+1 << " -> "<<x+1 <<"\n";
                    used[id] = true;
                    act_node = x;
                    break;
                }
            }
        } while(act_node != start_node);

        //itt körbe értünk, de még nem (feltétlen) vagyunk kész
        while(!st.empty()){
            act_node=st.top(); st.pop();
            sol.push_back(act_node);
            unused_edge=false;
            for(auto p : graph[act_node]){
                int id = p.second;
                if(!used[id]){
                    //cout<<act_node+1 << ". csucsank van szabad ele erre: -> "<<x+1 <<"  \n";
                    start_node=act_node;
                    unused_edge = true;
                    break;
                }
            }
            if(unused_edge){

                break;
            }
        }

    }

    reverse(sol.begin(),sol.end());
    sol.push_back(0);
    return sol;
}



int main() {

	int n; cin >> n;
    int m; cin >> m;

    vector<vector<pair<int,int>>> graph (n); //first: szomszéd, second: edge index
    for (int i = 0 ;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;b--; //0-as indexelést nyomok ugye
        graph[a].push_back({b,i});
        graph[b].push_back({a,i});
    }


    if(graph[0].size()==0){
            cout<<"IMPOSSIBLE"; return 0;
        }
    for(int i=0;i<n;i++){
        if(graph[i].size()%2==1){
            cout<<"IMPOSSIBLE"; return 0;
        }
    }

    vector<int> sol = euler(graph,m);
    if(sol.size()< (m+1) ){cout<<"IMPOSSIBLE"; return 0;} 
    for (int x:sol){
        cout<<x+1<<" ";
    }




    return 0;

}