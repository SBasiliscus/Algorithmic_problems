
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>



using namespace std;


void lanykero(vector<queue<int>>& graphM,vector<vector<int>>& graphF, vector<int>& fiu_legjobb, vector<int>& lany_legrossz){
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
                    lany_legrossz[megkert_lany] = graphF[megkert_lany][i];
                    done = false;
                }
                else if(graphF[megkert_lany][best_option[megkert_lany]] < graphF[megkert_lany][i]){ //van már jobban preferált kérője
                    graphM[i].pop();
                    fiu_legjobb[i]++;
                    done = false;

                }else if(graphF[megkert_lany][best_option[megkert_lany]] != graphF[megkert_lany][i]){//ő a legpreferáltabb kérője
                    graphM[best_option[megkert_lany]].pop(); //kikosarazza az eddigi (legjobb) ajánlatát
                    fiu_legjobb[best_option[megkert_lany]]++;
                    best_option[megkert_lany] = i;
                    lany_legrossz[megkert_lany] = graphF[megkert_lany][i];                        
                    done = false;
                }
            }else{ //ennek a fiúnak nincs már opciója
                fiu_legjobb[i] = -1;
            }
        }
    }

}



int main() {

	int n; cin >> n; //fiúk
    int m; cin >> m; //lányok

//Ocsmány megoldást választottam, tudom hogy lenne ennél elegánsabb megoldás de így ezt gyorsan tudtam "leprogramozni" (duplikálni majdnme mindent) és futás idpben szerintem nem olyan boirzalmas ez sem (memóriában kcsit rosszabb midnt egy elegánsabb)

    vector<queue<int>> MOgraphM (n); //fiúkhoz párok prioritási sorrendben a fiú opti megtalálsához
    vector<vector<int>> MOgraphF (m, vector<int>(n,-1)); //lányokhoz
    vector<int> fiu_legjobb (n, 0);
    vector<int> fiu_legrossz(n,-1);
    
    vector<queue<int>> FOgraphF (m); //lányokhoz párok prioritási sorrendben a lány opti megtaláláshoz
    vector<vector<int>> FOgraphM (n, vector<int>(n,-1)); //fiúkhoz
    vector<int> lany_legjobb(m, 0);
    vector<int> lany_legrossz(m,-1);

    for (int i = 0 ;i<n;i++){
        int k; cin >> k;
        for(int j=0;j<k;j++){
            int a; cin >> a;
            a--;
            MOgraphM[i].push(a);
            FOgraphM[i][a] = j;

        }
    }
    for (int i = 0 ;i<m;i++){
        int k; cin >> k;
        for(int j=0;j<k;j++){
            int a; cin >> a;
            a--;
            MOgraphF[i][a] = j;
            FOgraphF[i].push(a);

        }
    }

    lanykero(MOgraphM, MOgraphF,fiu_legjobb,lany_legrossz);
    vector<int> MO_result_M(n,-1);
    vector<int> MO_result_F(m,-1);
    for(int i=0; i<n; i++){
        if(!MOgraphM[i].empty()){
            MO_result_M[i] = MOgraphM[i].front();
            MO_result_F[MOgraphM[i].front()] = i;
        }
    }
    lanykero(FOgraphF, FOgraphM,lany_legjobb,fiu_legrossz);
    vector<int> FO_result_F(m,-1);
    vector<int> FO_result_M(n,-1);
    for(int i=0; i<m; i++){
        if(!FOgraphF[i].empty()){
            FO_result_F[i] = FOgraphF[i].front();
            FO_result_M[FOgraphF[i].front()] = i;
        }
    }



    for(int i =0; i<n; i++){
        cout << (fiu_legjobb[i] ==- 1?-1:(fiu_legrossz[i] - fiu_legjobb[i] ))<< "\n";
    }
    for(int i=0;i<m;i++){
        cout << (lany_legjobb[i]==-1?-1:(lany_legrossz[i] - lany_legjobb[i])) << "\n";
    }
    
   




    return 0;

}