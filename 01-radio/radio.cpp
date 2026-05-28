#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	int n; cin >> n;
    vector<int> tmp_arr;    
    unordered_map<int,int> index;
    int first;
    cin >> first;
    tmp_arr.push_back(first);
    index[first] = 0;
    int max_cnt = 1;
    for (int i = 1;i<n;i++){
        int item; cin >> item;
        if (index.count(item)){ //van már egy azonos elem a temp_vectorban, ezért tmp vector elejét törlüm, indexeket frissítem
            
            tmp_arr.erase(tmp_arr.begin(),tmp_arr.begin()+index[item]+1);
            tmp_arr.push_back(item);
            index.clear();
            for (int j = 0; j < tmp_arr.size();j++) index[tmp_arr[j]]=j;
        }else{ // ilyen elem még nincs a vectorban
            index[item] = tmp_arr.size();
            tmp_arr.push_back(item);

            if(tmp_arr.size()>max_cnt) max_cnt=tmp_arr.size();

        }

        
        
    }
    cout << max_cnt;

    return 0;
}