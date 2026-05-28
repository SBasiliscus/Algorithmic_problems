
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

size_t cnt = 0;

vector<int> two_arr_merg(const vector <int>& a,const vector <int>& b);
vector<int> arg_merg_rec(const vector <int>& og){
    if(og.size()==1) return og;
    
    size_t mid=og.size()/2;
    vector<int> ag(og.begin(),og.begin()+mid);
    vector<int> bg(og.begin()+mid,og.end());
    vector<int> nag = arg_merg_rec(ag);
    vector<int> nbg = arg_merg_rec(bg);
    return two_arr_merg(nag,nbg);
}


vector<int> two_arr_merg(const vector <int>& a,const vector <int>& b){
    vector<int> merged;
    int ai=0;
    int bi=0;
    while (ai<a.size()&&bi<b.size()){
        if (a[ai] > b[bi]){ //az eset amikor egy számot előre "viszek"
            merged.push_back(b[bi++]);
            cnt += a.size()-ai;
        }else
            merged.push_back(a[ai++]);
    }
    if(ai<a.size()){
        for(;ai<a.size();ai++) merged.push_back(a[ai]);
    }else if(bi<b.size()){
        for(;bi<b.size();bi++) merged.push_back(
            b[bi]);
    }
    return merged;
}


int main() {

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> solut = arg_merg_rec(arr);
    //for(int i=0;i<solut.size();i++){
    //   cout << solut[i] << " ";
    //}
    cout << "\n" << cnt;


    
    return 0;

}


