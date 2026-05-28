
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>



using namespace std;




bool javito(const vector<vector<int>>& graphM, const vector<vector<int>>& graphF, vector<int>& parA, vector<int>& parB){
    int n = graphM.size();
    int m = graphF.size();
    vector<bool> visited(m, false);
    queue<int> q;
    vector<int> parentB(m, -1);

    for(int i=0; i<n;i++){
        if(parA[i]==-1){ 
            q.push(i);
            while(!q.empty()){
                int fi = q.front();q.pop();
                for(int la: graphM[fi]){
                    if(!visited[la]){
                        visited[la] = true;
                        parentB[la] = fi;
                        if(parB[la]==-1){
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

//sry Viki, copy pasteltem csak 
vector<pair<int, int>> javito_after(const vector<vector<int>>& graphM, const vector<vector<int>>& graphF, vector<int>& parA, vector<int>& parB){
    int n = graphM.size();
    vector<bool> visited(n, false);
    vector<bool> goodA(n, true);
    queue<int> q;
    vector<int> parentB(n, -1);

    for(int i=0; i<n;i++){
        if(parA[i]==-1){
            goodA[i] = false; 
            q.push(i);
            while(!q.empty()){
                int fi = q.front();q.pop();
                for(int la: graphM[fi]){
                    if(!visited[la]){
                        visited[la] = true;
                        parentB[la] = fi;
                        //sosem fogunk találni javítóutat, mert csak utána hívom meg ezt a methódust 
                        q.push(parB[la]);
                        
                    }
                }
            }
            
        }
    }
    vector<pair<int,int>> result;
    for(int i = 0 ;i<n;i++){
        if(visited[i]){
            goodA[parB[i]] = false;
            result.push_back({2,i});
        }
    }
    for(int i = 0 ;i<n;i++){
        if(goodA[i]){
            result.push_back({1,i});
        }
    }
    return result;


}


int main() {

	int n; cin >> n;

    vector<vector<int>> graphM (n);
    vector<vector<int>> graphF (n); 
    vector<int> parA (n, -1); 
    vector<int> parB (n, -1);
    for(int ro=0;ro<n;ro++){
        for(int co=0;co<n;co++){
            char cell;
            cin >> cell;
            if(cell=='o'){
                graphM[ro].push_back(co);
                graphF[co].push_back(ro);
            }
        }
    }


    //kezdetleges párosítás
    vector<bool> visited(n,false);
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

    int rst = n-( count(parA.begin(), parA.end(), -1));

    cout << rst << '\n';

    vector<pair<int,int>> rest = javito_after(graphM,graphF,parA,parB);
    for(const auto& r: rest){
        cout << r.first << " " << r.second + 1 << "\n";
    }

    

    


   




    return 0;

}