
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>


using namespace std;




int main() {

	int n, q_size; cin >> n >> q_size;

    vector<long long> claims (n);
    vector<long long> assets (q_size);
    for(long long& i:claims) cin >> i, i/=2; //lefelezett követelések, kihasznlva hogy mindig párosak
    for(long long& i:assets) cin >> i;
    sort(claims.begin(), claims.end()); 
    
    vector<long long> levels(2*n); //egyszer megállípom hogy mindegyik edényél milyen víz mennysigénél "változás" [n-1]: n-edik edény, [n]:n-edik egény felső fele, [n+1]: n-1-edik edény felső fele 
    
    // i<n : levels[i] = legkevesebb víz mennyisség, amivel a i-edik edény (alsó fele) megtelik vízzel 
    // i>=n : levels[i] = a legkevesebb víz mennyiség, amivel az i-edik edény felső felét eléri a vízszint

    long long act_lv=n*claims[0];
    levels[0] = act_lv;
    for(int i= 1; i<n;i++){ //edénrendszer alsó fele        
        act_lv += (claims[i]-claims[i-1])*(n-i);
        levels[i]=act_lv;
    }
    for(int i=n;i<(2*n)-1;i++){ //edényrendszer felső fele: a (2*n-i-1)-edik edénnyel foglalkozom
        act_lv += (claims[2*n-i-1]-claims[2*n-i-2]) * (i-n+1);
        levels[i] = act_lv;
    }
    levels[2*n-1] = act_lv + n*claims[0];

    for(long q: assets){ //végig megyek minden összpénz esetén
        auto it = lower_bound(levels.begin(), levels.end(), q);
        int index;
        double result;
        if (it == levels.end() ) { //tele van a rendszer
            result = 2*claims[n-1];
        }else {
            index = it - levels.begin();
            //index-edik edénnyél van a léyneg
        
            if(index == 0)
                result = (double)q/n;            
            else if(index<n) 
                result = claims[index-1]+(double)(q - levels[index-1])/(n-index);
            else //if (index < 2*n) // (2*n-index-1)-edik edénnyel foglalkozom
                result = 2*claims[n-1] - claims[2*n-index-1] + (double)(q-levels[index-1])/(n-(2*n-index-1));
            

        }


        
        



        cout << fixed << setprecision(6) << result <<"\n";
    }
    

    return 0;

}