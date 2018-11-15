#include<bits/stdc++.h>

using namespace std;

const int ENTRY = 5;

long viralAdvertising(int day){
    long shared = ENTRY;
    long liked = shared / 2;
    long cumulative = liked;
    while(day > 1){
        shared = liked * 3;
        cumulative = cumulative + shared / 2;
        liked = shared / 2;
        day --;
    }

    return cumulative;
}

int main(){
    int n;
    cin >> n;

    cout << viralAdvertising(n);

    return 0;
}