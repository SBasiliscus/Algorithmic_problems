
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>



using namespace std;


struct unio_tree{
    int size;
    int parent;

    unio_tree() : size(1), parent(-1) {}
};

int holvan(int v, vector<unio_tree>& nodes){
    int act=v;
    while(nodes[act].parent!=-1) act = nodes[act].parent;
    int root = act;
    act=v;
    while(nodes[act].parent!=-1){
        int ne_act = nodes[act].parent;
        nodes[act].parent = root;
        act = ne_act;
    } 
    return root;
}

void unio(int u1, int u2, vector<unio_tree>& nodes){
    //itt u1, és u2 már gyökér
    if(nodes[u1].size>=nodes[u2].size){
        nodes[u1].size += nodes[u2].size;
        nodes[u2].parent = u1;
    }else{
        nodes[u2].size += nodes[u1].size;
        nodes[u1].parent = u2;
    }
}


int main() {

	int n; cin >> n;
    int m; cin >> m;

    vector<tuple<int,int,int>> edges; 
    for (int i = 0 ;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        a--;b--; //0-as indexelést nyomok ugye
        edges.push_back({a,b,w});
    }
    
    sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
        return get<2>(a) < get<2>(b);
    });

    vector<unio_tree> nodes(n);

    int cnt = 0;
    long long min_w = 0;
    for (const auto& e : edges) {
        int a = get<0>(e);
        int b = get<1>(e);
        int w = get<2>(e);
        int root_a = holvan(a,nodes);
        int root_b = holvan(b,nodes);
        if(root_a != root_b){
            cnt++; min_w += w;
            unio(root_a, root_b, nodes);
        }
        if(cnt == n-1) break;
        
    }

    if( cnt == n-1 ){
        cout << min_w; return 0;
    }
    cout << "IMPOSSIBLE";





    return 0;

}