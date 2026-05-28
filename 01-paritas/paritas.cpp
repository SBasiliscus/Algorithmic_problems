
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    
/*  első leglassabb megoldásom

    for (int x = 0;x<n;x++) {
        for (int y = x+1;y<n;y++){
            if( arr[x]%2==arr[y]%2 && arr[x]>arr[y]){
                swap(arr[x],arr[y]);
            }
        }
    }

    bool sorted=true;
    for (int x = 0;x<n;x++) {
        for (int y = x+1;y<n;y++){
            if(arr[x]>arr[y]) sorted = false;
        }
    }
    printf(sorted?"IGEN":"NEM");*/ 
    
    /* második, még mindig túl lassú emgoldásom
    bool sorted=true;
    bool contin =true;
    for (int x = 0;x<n&&contin;x++) {
        int min = arr[x];
        int mindind = x;
        for (int y = x+1;y<n;y++){
            if (arr[y]<min){
                min = arr[y]; mindind = y;
            }     
        }
        if(mindind!=x){
            if(min%2==arr[x]%2)
                swap(arr[x],arr[mindind]);
            else{
                sorted = false; contin = false; break;
            }
        }
        
    } 
    printf(sorted?"IGEN":"NEM");    */

    vector<int> sortedarr = arr;
    sort(sortedarr.begin(),sortedarr.end());

    bool sortable = true;

    for (int i = 0;i<n;i++){
        if (arr[i]%2!=sortedarr[i]%2){
            sortable = false;
            break;
        } 
    }
    cout << (sortable?"IGEN":"NEM");
    
    return 0;

}