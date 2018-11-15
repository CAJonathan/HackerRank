#include<bits/stdc++.h>

using namespace std;

int magicMatrix1 [3][3] = {2, 7, 6, 9, 5, 1, 4, 3, 8};
int magicMatrix2 [3][3] = {4, 3, 8, 9, 5, 1, 2, 7, 6};
int magicMatrix3 [3][3] = {2, 9, 4, 7, 5, 3, 6, 1, 8};
int magicMatrix4 [3][3] = {6, 1, 8, 7, 5, 3, 2, 9, 4};
int magicMatrix5 [3][3] = {6, 7, 2, 1, 5, 9, 8, 3, 4};
int magicMatrix6 [3][3] = {8, 3, 4, 1, 5, 9, 6, 7, 2};
int magicMatrix7 [3][3] = {8, 1, 6, 3, 5, 7, 4, 9, 2};
int magicMatrix8 [3][3] = {4, 9, 2, 3, 5, 7, 8, 1, 6};

int costCalculating(int matric[3][3], int matrixInput[3][3]){
    int cost = 0;
    for(int i = 0 ; i < 3 ; i ++){
        for(int j = 0 ; j < 3 ; j ++){
            cost += matric[i][j] != matrixInput[i][j] ? abs(matric[i][j] - matrixInput[i][j]) : 0;
        }
    }

    return cost;
}

int main(){
    int inputMatrix [3][3];
    for(int i = 0 ; i < 3 ; i ++){
        for(int j = 0 ; j < 3 ; j ++){
            cin >> inputMatrix[i][j];
        }
    }

    int minCost = 100;
    minCost = min(costCalculating(magicMatrix1, inputMatrix), minCost);
    minCost = min(costCalculating(magicMatrix2, inputMatrix), minCost);
    minCost = min(costCalculating(magicMatrix3, inputMatrix), minCost);
    minCost = min(costCalculating(magicMatrix4, inputMatrix), minCost);
    minCost = min(costCalculating(magicMatrix5, inputMatrix), minCost);
    minCost = min(costCalculating(magicMatrix6, inputMatrix), minCost);
    minCost = min(costCalculating(magicMatrix7, inputMatrix), minCost);
    minCost = min(costCalculating(magicMatrix8, inputMatrix), minCost);

    cout << minCost;

    return 0;
}