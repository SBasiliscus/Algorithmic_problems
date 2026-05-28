
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>



using namespace std;




int main() {

	int n; cin >> n;

    vector<queue<int>> prefs(n);
    for(int i=0;i<n;i++){
        int cnt = n;
        while(cnt--){
            int a; cin >> a; a--;
            prefs[i].push(a);
        }
    }

    vector<int> result(n,-1);
    vector<int> prizes_neg(n);
    int prize_neg = 0;
    int done_cnt=0;
    while(done_cnt < n){
        stack<int> route;
        vector<bool> visited(n,false);
        int act_node;
        for(int i=0;i<n;i++){
            if(result[i] == -1){
                act_node = i; break;
            }
        }
        while(1){ //ciklus ami keres kört és amentén cserél egyet
            route.push(act_node);
            while(result[prefs[act_node].front()] != -1 ){ //egy márkész csúcsba mutat           
                prefs[act_node].pop();
            }
            act_node = prefs[act_node].front();
            if(visited[act_node]){
                //találtunk egy kört,ami mentén csinálunke gy cserét
                int strt = act_node;
                result[route.top()] = act_node;
                prizes_neg[route.top()] = prize_neg;               
                done_cnt++;
                act_node = route.top();
                while(strt != act_node){
                    route.pop();
                    result[route.top()] = act_node;
                    prizes_neg[route.top()] = prize_neg;
                    done_cnt++;
                    act_node = route.top();
                }
                prize_neg++;
                break;


            }else{
                visited[act_node] = true;
            }

        }
    }

    
    for(int i=0;i<n;i++){
        //cout << result[i] + 1 << "\n";
        cout << prize_neg - prizes_neg[i]<< "\n";
    }




    return 0;

}