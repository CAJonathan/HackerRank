#include<iostream>
#include<algorithm>

using namespace std;

struct petrolPump{
    int index;
    int petrol;
    int distance;
};
typedef struct DATA data;

bool cmp(petrolPump p1, petrolPump p2){
    return (p1.petrol > p1.distance && p1.petrol - p1.distance > p2.petrol - p2.distance);
}

bool check(petrolPump * pumps, int n, int index){
    int len = sizeof(pumps)/sizeof(pumps[0]);
    int petrol = 0;
    for(int i = index ; i < n ; i ++){
        petrol += pumps[i].petrol - pumps[i].distance;
        if(petrol < 0){
            return false;
        }
    }

    for(int i = 0 ; i < index ; i ++){
        petrol += pumps[i].petrol - pumps[i].distance;
        if(petrol < 0){
            return false;
        }
    }
    return true;
}

int main(){
    int N;
    cin >> N;

    petrolPump * pumps = new petrolPump[N];
    for(int i = 0 ; i < N ; i ++){
        cin >> pumps[i].petrol >> pumps[i].distance;
        pumps[i].index = i;
    }

    sort(pumps, pumps + N, cmp);
    int i = 0;
    while(!check(pumps, N, i) && i < N){
        i++;
    }
    cout << pumps[i].index;
    return 0;
}