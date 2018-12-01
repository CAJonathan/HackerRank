#include<bits/stdc++.h>

using namespace std;

bool isPreventing(int r, int c, int rq, int cq){
    return (r == rq || c == cq || abs(r - rq) == abs(c - cq));
}

int determineDirection(int r, int c, int rq, int cq){
    if(isPreventing(r, c, rq, cq)){
        if(r > rq){
            if(c > cq){
                return 2;
            } else if(c == cq){
                return 1;
            } else{
                return 0;
            }
        } else if(r == rq){
            if(c > cq){
                return 6;
            } else if(c == cq){
                return -1;
            } else{
                return 7;
            }
        } else{
            if(c > cq){
                return 3;
            } else if(c == cq){
                return 4;
            } else{
                return 5;
            }
        }
    }
    return -1;
}

void updateThePreventing(int * prevented, int r, int c, int rq, int cq){
    int dir = determineDirection(r, c, rq, cq);
    if(dir > -1){
        prevented[dir] = (dir < 3) ? min(prevented[dir], r - 1) : ((dir < 6) ? max(prevented[dir], r + 1) : ((dir < 7) ? min(prevented[dir], c - 1) : max(prevented[dir], c + 1)));
    }
}

int attack(int rq, int cq, int * prevented){
    int sum = 0;
    sum += abs(prevented[0] - rq);
    sum += abs(prevented[1] - rq);
    sum += abs(prevented[2] - rq);
    sum += abs(prevented[3] - rq);
    sum += abs(prevented[4] - rq);
    sum += abs(prevented[5] - rq);
    sum += abs(prevented[6] - cq);
    sum += abs(prevented[7] - cq);
    return sum;
}

int main(){
    int n, k, rq, cq;
    cin >> n >> k >> rq >> cq;
    int * prevented = new int[8];
    prevented[0] = rq + min(n - rq, cq - 1);
    prevented[1] = n;
    prevented[2] = rq + min(n - rq, n - cq);
    prevented[3] = rq - min(rq - 1, n - cq);
    prevented[4] = 1;
    prevented[5] = rq - min(rq - 1, cq - 1);
    prevented[6] = n;
    prevented[7] = 1;
    int r, c;
    for(int i = 0 ; i < k ; i ++){
        cin >> r >> c;
        updateThePreventing(prevented, r, c, rq, cq);
    }

    int totalActack = attack(rq, cq, prevented);
    cout << totalActack;
    
    // for_each(prevented, prevented + 8, [](int i){cout << i << " ";});
    return 0;
}