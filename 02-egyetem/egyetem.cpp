
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;



//itt a dfs-t a bsz2-es jegyzetes pszeudokód alapján készítettem el

vector<int> dfs(const vector<vector<int>>& graph){
    int n = graph.size();
    vector<int> mszam (n,-1);
    vector<int> bszam (n,-1);
    vector<int> mod_bszam (n,-1);
    vector<int> parent (n,-1);
    int dn = 1;int fn = 0;
    int act_node = 0;
    mszam[0] = dn;
    while(1){
        bool finished = true;
        for(int x: graph[act_node]){
            if(mszam[x]==-1){
                mszam[x] = ++dn;
                parent[x] = act_node;
                act_node = x;
                finished = false;
                break;
            }else if(mszam[act_node] > mszam[x] && bszam[x]==-1)  //visszaél => kör
            {   
                //cout<<"act_n: " << act_node <<" x: " << x <<"\nmszam(act): "<<mszam[act_node] <<"  mszam(x): "<<mszam[x]<<"\nbszam(x: )"<<bszam[x];
                return {};
            }
                
        }
        if(finished){
            mod_bszam[fn] = act_node;
            bszam[act_node] = ++fn;
            if(parent[act_node]!=-1){
                act_node = parent[act_node];
            }else{
                auto it = find(mszam.begin(),mszam.end(),-1);
                if(it!=mszam.end()){
                    act_node = it - mszam.begin();
                    mszam[act_node] = ++dn;
                }else  return mod_bszam;

            }
        }


    }


}



int main() {

	int n; cin >> n;
    int m; cin >> m;

    vector<vector<int>> graph (n);
    for (int i = 0 ;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;b--; //0-as indexelést nyomok ugye
        if (a==b){
            cout<<"IMPOSSIBLE";
            return 0;
        }
        graph[a].push_back(b);   
    }

    vector<int> bszam = dfs(graph);
    if(bszam.empty()) cout<<"IMPOSSIBLE";
    else    for(int i = n-1 ; i>=0; i--) cout<<bszam[i]+1<<" ";
    



    return 0;

}