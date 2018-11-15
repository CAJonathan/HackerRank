#include<iostream>

using namespace std;

int LOL(int n, int c, int m){
    int result = n/c;
    int wrappers = result;
    while(wrappers >= m){
        result += wrappers/m;
        wrappers = wrappers/m + wrappers%m;
    }
    return result;
}

int main(){
    int t;
    cin >> t;
    int ** testCases = new int * [t];
    for(int i = 0 ; i < t ; i ++){
        testCases[i] = new int[3];
        cin >> testCases[i][0] >> testCases[i][1] >> testCases[i][2];
    }
    for(int i = 0 ; i < t ; i ++){
        int n = testCases[i][0];
        int c = testCases[i][1];
        int m = testCases[i][2];

        cout << LOL(n, c, m) << endl;
    }

    return 0;
}