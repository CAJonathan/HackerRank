#include<bits/stdc++.h>

using namespace std;

int main(){
    long long sum = 0;
    int n;

    cin >> n;
    for(int i = 0 ; i < n ; i ++){
        long long temp;
        cin >> temp;
        sum += temp;
    }

    cout << sum;
    return 0;
}