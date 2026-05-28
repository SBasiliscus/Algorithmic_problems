
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <climits>



using namespace std;


void lanykero(vector<queue<int>>& graphM,vector<vector<int>>& graphF){
    int n = graphM.size(); int m = graphF.size();
    //vector<bool> fiu_done(n, false);
    vector<int> best_option(m,INT_MAX);
    bool done =false;
    while(!done){
        done = true;
        for(int i=0;i<n;i++){
            if(!graphM[i].empty()){
                int megkert_lany = graphM[i].front();
                if(best_option[megkert_lany]==INT_MAX){//még senki sem kérte meg a lányt
                    best_option[megkert_lany] = i;
                    done = false;
                }
                else if(graphF[megkert_lany][best_option[megkert_lany]] < graphF[megkert_lany][i]){ //van már jobban preferált kérője
                    graphM[i].pop();
                    done = false;

                }else if(graphF[megkert_lany][best_option[megkert_lany]] != graphF[megkert_lany][i]){//ő a legpreferáltabb kérője
                    graphM[best_option[megkert_lany]].pop(); //kikosarazza az eddigi (legjobb) ajánlatát
                    best_option[megkert_lany] = i;                        
                    done = false;
                }
            }
        }
    }

}



int main() {

	int n; cin >> n; //fiúk
    int m; cin >> m; //lányok

    vector<queue<int>> graphM (n); //fiúkhoz párok prioritási sorrendben
    vector<vector<int>> graphF (m, vector<int>(n,-1)); //lányokhoz

    for (int i = 0 ;i<n;i++){
        int k; cin >> k;
        for(int j=0;j<k;j++){
            int a; cin >> a;
            a--;
            graphM[i].push(a);

        }
    }
    for (int i = 0 ;i<m;i++){
        int k; cin >> k;
        for(int j=0;j<k;j++){
            int a; cin >> a;
            a--;
            graphF[i][a] = j; 

        }
    }

    lanykero(graphM, graphF);
    vector<pair<int,int>> result;
    for(int i=0; i<n; i++){
        if(!graphM[i].empty()){
            result.push_back({i, graphM[i].front()});
        }
    }
    cout << result.size() <<"\n";
    for(auto r: result){
        cout << r.first + 1  << " " << r.second + 1 << "\n";
    }
    
   




    return 0;

}