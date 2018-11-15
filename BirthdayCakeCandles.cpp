/*
You are in charge of the cake for your niece's birthday and have decided the cake will have one candle for each year of her total age. 
When she blows out the candles, she’ll only be able to blow out the tallest ones. Your task is to find out how many candles she can successfully blow out.

For example, if your niece is turning 4 years old, and the cake will have candles of height 4, 4, 1, 3, she will be able to blow out 2 candles successfully, 
since the tallest candles are of height 4 and there are 2 such candles.
*/

#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int ar[n];
    for(int i = 0 ; i < n ; i ++){
        cin >> ar[i];
    }

    int min = ar[0];
    int count = 1;
    for(int i = 1 ; i < n ; i ++){
        if(ar[i] > min){
            count = 1;
            min = ar[i];
        } else if(ar[i] == min){
            count ++;
        } 
    }
    cout << count;
    return 0;
}