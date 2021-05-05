#include <bits/stdc++.h>
using namespace std;
char table[10][10] ;
bool black = true;
int m = 8;

int main(){
    int n;
    scanf("%d",&n);
    table[4][4] = table[5][5] = 'w';
    table[4][5] = table[5][4] = 'b';
    while(n--){
        char cc;
        int l,c;
        scanf(" %c %d",&cc,&l);
        c = cc - 'a' + 1;
        char point,npoint;
        if(black){
            point = 'b';
            npoint = 'w';
            black = false;
        }else{
            point = 'w';
            npoint = 'b';
            black = true;
        }
        bool pass;
        if(table[l][c] == 'b' || table[l][c] == 'w' || l > m || l < 1 || c > m || c < 1){
            continue;
        }
        int i=l,j=c;
        bool can = false;
        if(l - 1 > 1 && c - 1 > 1){ // up left
            int ii=l,jj=c;
            if(table[l-1][c-1] == npoint){
                table[i][j] = point;
                ii -= 1;
                jj -= 1;
                while(table[ii][jj] == npoint && ii > 1 && jj > 1){
                    ii -= 1;
                    jj -= 1;
                }
                if(table[ii][jj] == point){
                    while(ii != i || jj != j){
                        table[ii][jj] = point;
                        ii += 1;
                        jj += 1;
                    }
                    pass = true;
                }
            }
        }
        if(l - 1 > 1){ // up
            int ii=l,jj=c;
            if(table[l-1][c] == npoint){
                table[i][j] = point;
                ii -= 1;
                while(table[ii][jj] == npoint && ii > 1){
                    ii -= 1;
                }
                if(table[ii][jj] == point){
                    while(ii != i || jj != j){
                        table[ii][jj] = point;
                        ii += 1;
                    }
                    pass = true;
                }
            }
        }
        if(c - 1 > 1){ // left
            int ii = l,jj = c;
            if(table[l][c-1] == npoint){
                table[i][j] = point;
                jj -= 1;
                while(table[ii][jj] == npoint && jj > 1){
                    jj -= 1;
                }
                if(table[ii][jj] == point){
                    while(ii != i || jj != j){
                        table[ii][jj] = point;
                        jj += 1;
                    }
                    pass = true;
                }
            }
        }
        if(l + 1 < m && c + 1 < m){ // down right
            int ii = l,jj = c;
            if(table[l+1][c+1] == npoint){
                table[i][j] = point;
                ii += 1;
                jj += 1;
                while(table[ii][jj] == npoint && ii < m && jj < m){
                    ii += 1;
                    jj += 1;
                }
                if(table[ii][jj] == point){
                    while(ii != i || jj != j){
                        table[ii][jj] = point;
                        ii -= 1;
                        jj -= 1;
                    }
                    pass = true;
                }
            }
        }
        if(l + 1 < m){ // down
            int ii = l,jj = c;
            if(table[l+1][c] == npoint){
                table[i][j] = point;
                ii += 1;
                while(table[ii][jj] == npoint && ii < m){
                    ii += 1;
                }
                if(table[ii][jj] == point){
                    while(ii != i || jj != j){
                        table[ii][jj] = point;
                        ii -= 1;
                    }
                    pass = true;
                }
            }
        }
        if(c + 1 < m){ // right
            int ii = l,jj = c;
            if(table[l][c+1] == npoint){
                table[i][j] = point;
                jj += 1;
                while(table[ii][jj] == npoint && jj < m){
                    jj += 1;
                }
                if(table[ii][jj] == point){
                    while(ii != i || jj != j){
                        table[ii][jj] = point;
                        jj -= 1;
                    }
                    pass = true;
                }
            }
        }
        if(l + 1 < m && c - 1 > 0){ // down left
            int ii = l,jj = c;
            if(table[l+1][c-1] == npoint){
                table[i][j] = point;
                ii += 1;
                jj -= 1;
                while(table[ii][jj] == npoint && ii < m && jj > 0){
                    ii += 1;
                    jj -= 1;
                }
                if(table[ii][jj] == point){
                    while(ii != i || jj != j){
                        table[ii][jj] = point;
                        ii -= 1;
                        jj += 1;
                    }
                    pass = true;
                }
            }
        }
        if(c + 1 < m && l - 1 > 0){ // up right
            int ii = l,jj = c;
            if(table[l-1][c+1] == npoint){
                table[i][j] = point;
                ii -= 1;
                jj += 1;
                while(table[ii][jj] == npoint && ii > 1 && jj < m){
                    ii -= 1;
                    jj += 1;
                }
                if(table[ii][jj] == point){
                    while(ii != i || jj != j){
                        table[ii][jj] = point;
                        ii += 1;
                        jj -= 1;
                    }
                    pass = true;
                }
            }
        }
    }

    for(int i = 1 ; i <= m ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            if(table[i][j] == 'b'){
                printf("X");
            }else if(table[i][j] == 'w'){
                printf("O");
            }else{
                printf(".");
            }
        }printf("\n");
    }

    return 0;
}
