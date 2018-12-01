#include<bits/stdc++.h>

using namespace std;

int findPosition(int * scores, int n, int aliceScore){
    int start = 0;
    int end = n;
    int middle = end / 2;

    if(aliceScore < scores[n - 1]){
        return n + 1;
    } else if(aliceScore > scores[0]){
        return 1;
    }

    while(!(aliceScore >= scores[middle] && aliceScore < scores[middle - 1])){
        if(aliceScore >= scores[middle]){
            end = middle;
        } else{
            start = middle;
        }
        middle = (start + end) / 2;
    }

    return middle + 1;
}

int main(){
    int n, m;

    cin >> n;
    int * scores = new int[n];
    cin >> scores[0];
    int x, length = 1;
    for(int i = 1 ; i < n ; i ++){
        cin >> x;
        if(x < scores[length - 1]){
            scores[length ++] = x;
        }
    }

    cin >> m;
    int * alice = new int[m];
    for(int i = 0 ; i < m ; i ++){
        cin >> alice[i];
    }

    for(int i = 0 ; i < m ; i ++){
        int rank = findPosition(scores, length, alice[i]);
        cout << rank << endl;
    }
    return 0;
}