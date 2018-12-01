#include<bits/stdc++.h>

using namespace std;

int conflict(int u, int k){
    return (u == 0 ? 0 : (k - u));
}

int main(){
    int n, k;
    cin >> n >> k;

    int * balance = new int[k];
    int * reduce = new int[k];
    for_each(balance, balance + k, [balance](int & i) {i = &i - balance;});
    for_each(reduce, reduce + k, [reduce](int & i) {i = 0;});
    int x;
    for(int i = 0 ; i < n ; i ++){
        cin >> x;
        reduce[x%k] ++;
    }
    for_each(reduce, reduce + k, [&reduce, k](int & i) {swap(i, reduce[conflict(&i - reduce, k)]);});
    sort(balance, balance + k, [reduce](int i, int j)->bool{return reduce[i] < reduce[j];});
    
    int subLength = n;
    for_each(balance, balance + k, [&reduce, &subLength, k](int i){
        int conf = conflict(i, k);
        if(reduce[conf] > 0){
            subLength -= i == conf ? reduce[i] - 1 : reduce[i];
            reduce[i] = 0;
        }
    });
    cout << subLength;
    return 0;
}