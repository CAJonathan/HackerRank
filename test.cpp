#include<bits/stdc++.h>

using namespace std;

bool isBeautifullDay(int day, int k){
    int temp = day;
    int reverse = 0;
    while(temp > 0){
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
    }
    
    int delta = abs(reverse - day);
    if(delta % k == 0){
        return true;
    } else{
        return false;
    }

}

int main(){
    int i, j, k;
    cin >> i >> j >> k;
    int count = 0;
    for(int idx = i ; idx <= j ; idx ++){
        if(isBeautifullDay(idx, k)){
            count ++;
        }
    }

    cout << count;

    return 0;
}