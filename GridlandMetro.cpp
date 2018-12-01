#include<bits/stdc++.h>

using namespace std;

struct TRACK{
    int c1 = -1;
    int c2 = -1;
};
typedef struct TRACK track;



int main(){
    long n, m;
    int k;
    cin >> n >> m >> k;

    track * trainTrack = new track[k];
    int r, c1, c2;
    for(int i = 0 ; i < k ; i ++){
        cin >> r;
        cin >> c1 >> c2;

        trainTrack[r].c1 = trainTrack[r].c1 > c1 ? c1 : trainTrack[r].c1;
        trainTrack[r].c2 = trainTrack[r].c2 < c2 ? c2 : trainTrack[r].c2;
    }

    long sum = n * m;
    for(int i = 0 ; i < n ; i ++){
        sum -= long(trainTrack[i].c2 - trainTrack[i].c1 + (trainTrack[i].c1 != -1 ? 1 : 0));
    }

    cout << sum;
    return 0;
}