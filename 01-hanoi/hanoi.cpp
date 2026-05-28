
#include <iostream>
using namespace std;

void hanoi_ab_rec(int n, int a, int b);

int main() {
    /*n kapszula átvitele az 1-ról a 3-re: 2^n-1 lépés
            n-1 kapszulát átviszek 1-ről, 2-re + 1 (legnagyobb kapszulát átviszem 1-> 3) majd megint n-1 kapszulát átviszek 2-ről 3-ra
            ((...(k(1)*2+1)*2+1)...)*2+1 = 2^(n-1)+2^(n-2)+...+2^1+2^0 = 2^n-1
            
            Miért minimális ez:
            A rudaknak  nincsen különleges szerepük, tehát az 1-es rúdról átpakolni x korongot a 3-as rúdra 
            ugyanannyi lépésszámmal érhető el, mint bármely rúdról bármelyik rúdra x korong átpakolása. 
            Ez igaz akkor, ha ezen x korongon kívül nincsen más korong, vagy csak ezeknél nagyob korong van játékban
                       
            Legyen k(n) = legkevesebb lépésszám amivel n korongot át tudok tenni egy rúdról egy másikra.
            Állítás: k(n) = k(n-1)*2+1 ha n>1
            Biz:
            legyen n korong közül a legnagyobbik neve Róza
                - Rózát minimum egyszer kell mozgatnunk
                - Rózát mozgatni csak olyan rúdról lehet, ahol egyedül van (vagy csak nála nagyobb korong van alatta)
                        csak olyan rúdra, amelyik üres (vagy csak nála nagyobb korong van rajta)
                - tehát kötelező :
                    1.) felszabadítani Rózát, vagyis minden (nála kisebb) korongot lepakolni róla
                    2.) kiüresíteni a cél rudat (vagy csak Rózánál nagyobb korongot hagyni ott), úgy hogy az előző feltétel igaz maradjon
                    3.) átteni Rózát a cél rúdra
                    4.) átpakolni az n-1 korongot a cél rúdra
                Ezek minimális lépésszáma:
                    1+2: k(n-1) ez a kettő lépés azonos n-1 korong átpakolásával egyik rúdról másik rúdra:
                        hiszen ha A csúcsról akarok lepakolni n-1 korongot, majd C csúcsról akarom leszedni ezek közül azokat amik opdakerültek, 
                        anélkül hogy az A csúcsra valamelyiket is visszatenném azt fogja eredményezni hogy az n-1 korong az A csúcsról átkerült mind a B csúcsra
                        
                    3: 1 lépés
                    4: k(n-1) lépés mivel a 3-as lépés után minden Rózánál kisebb korong egy rúdon van         
            
    */

	int n; cin >> n;
    int k = (1 << n) - 1;
    cout<<k<<"\n";
    hanoi_ab_rec(n,1,3);
    return 0;

}

void hanoi_ab_rec(int n, int a, int b){ //n db korong átvitele az a rúdról a b rúdra
    if (n == 1){        
        cout << a <<" "<< b <<"\n";
        return;
    }

    int c = 6-a-b; 
    hanoi_ab_rec(n-1,a,c);
    cout << a <<" "<< b << "\n";
    hanoi_ab_rec(n-1,c,b);
    return;
}