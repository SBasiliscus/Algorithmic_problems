
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>



using namespace std;




bool javito(const vector<vector<int>>& graphM, const vector<vector<int>>& graphF, vector<int>& parA, vector<int>& parB){
    int n = graphM.size();
    int m = graphF.size();
    vector<bool> visited(m, false); //csak a lányokat kell számon tartani
    queue<int> q;
    vector<int> parentB(m, -1); // 

    for(int i=0; i<n;i++){
        if(parA[i]==-1){ // fedetlen fiú
            q.push(i);
            while(!q.empty()){
                int fi = q.front();q.pop();
                for(int la: graphM[fi]){
                    if(!visited[la]){
                        visited[la] = true;
                        parentB[la] = fi;
                       // cout<<"parent la: " << la+1 << " -> " << fi+1 << "\n";
                        if(parB[la]==-1){ //találtunk eg yjavítoutat
                            //cout << "yeah fiu: " << i+1 << "  lany: " << la+1 << '\n';
                            int actF = la;
                            int actM = fi;

                            while(1){

                                parB[actF] = actM;
                                int NactF = parA[actM];
                                
                                parA[actM] = actF;
                                actF = NactF;
                                actM = parentB[actF];
                                if(NactF == -1) break;

                            }
                            return true;

                        }else{
                            q.push(parB[la]);
                        }
                    }
                }
            }
            
        }
    }
    return false;
}


int main() {

	int n; cin >> n;
    int m; cin >> m;
    int k; cin >> k;

    vector<vector<int>> graphM (n); //fiúkhoz pársítva
    vector<vector<int>> graphF (m); //lányokhoz
    vector<int> parA (n, -1); // -1 ha fedetlen, ha fedett akkor a párja sorszáma (0-val kezdve)
    vector<int> parB (m, -1);
    for (int i = 0 ;i<k;i++){
        int a,b;
        cin >> a >> b;
        a--;b--; //0-as indexelést nyomok ugye
        graphM[a].push_back(b);
        graphF[b].push_back(a);
    }


    //kezdetleges párosítás
    vector<bool> visited(m,false);
    for(int i=0;i<n;i++){
        for(int j: graphM[i]){
            if(!visited[j]){
                visited[j] = true;
                parA[i] = j;
                parB[j] = i;
                break;
            }
            
        }
    }

    while(javito(graphM,graphF,parA,parB));

    cout << n-( count(parA.begin(), parA.end(), -1)) << '\n';

    for(int i = 0 ; i < n; i++){
        if(parA[i]!=-1) cout << i+1 << " " << parA[i]+1 << '\n';
    }

    


   




    return 0;

}