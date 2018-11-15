#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int p, d, m, s;
    cin >> p >> d >> m >> s;

    int n = ceil((p - m)/float(d));
    int middle = n / 2;
    int cost = (2 * p - d * (n - 1)) * middle + ((n % 2 == 0) ? (0) : (p - d * middle));
    
    int remind = s - cost;
    if(remind > 0){
        int k = (remind - m) % m == 0 ? (remind - m)/m + 1 : ceil((remind - m)/float(m));
        cout << (n + k);
    } else{
        int k = n;
        int low = p - d * (n - 1);
        int i = 0;
        while(remind < 0 && i < n){
            remind += low + i * d;
            cout << k << " " << remind << endl;
            k --;
            i ++;
        }
        cout << ((remind < 0 || i == n) ? 0 : k);
    }

    return 0;
}