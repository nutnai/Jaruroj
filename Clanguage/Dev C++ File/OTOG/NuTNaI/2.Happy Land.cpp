#include <bits/stdc++.h>
using namespace std;

double ka[3][3];

int kit(int i,int j,int x,int y){
    if(i<0 || j<0 || i>3 || j>3)
        return 2e9;

    return min(kit(i-1,j),
            min(kit(i-1,j-1),
            min(kit(i+1,j),
            min(kit(i+1,j+1),
            min(kit(i+1,j-1),
            kit(i-1,j+1)))))) + ka[i][j]+ka[x][y]*0.1;
}
