#include "stdio.h"
#include "stdlib.h"
#include "function.h"
#include "termios.h"
#include "time.h"
#include "unistd.h"



int death_condition(int i, int j, int tail_length, int vi[100], int vj[100], int n, int m)
{
    if (i == 0 || j == 0)
        return 1;
    for (int k = 1; k < tail_length; k++) {
        if (vi[k] == i && vj[k] == j)
            return 1;
    }
    if (i == n - 1 || j == m - 1)
        return 1;
    
    return 0;

}

int search(int vi_tail[100], int vj_tail[100], int i, int j, int tail_length, int v[100][100]) 
{
    
    for (int k = 0; k <= tail_length; k++) {
        if (vi_tail[k] == i && vj_tail[k] == j) {
            return 1;
        }
    }
    
    return 0;
}

void matrix(int n, int m, int pos_i, int pos_j, int v[100][100], int tail_length, int vi_tail[100], int vj_tail[100]) 
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == m - 1) 
                printf("|\n");
            else if (i == 0 && j != 0) {
                printf("-");
            } else if (j == 0) {
                printf("|");
            } else if (i == n - 1) {
                printf("-");
            } else if (i == pos_i && j == pos_j) {
                printf("@");
            } else if (search(vi_tail, vj_tail, i, j, tail_length, v) == 1) {
                printf("o");
            } else if (v[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
    }
}

void position(int n, int m, char c, int *pos_i, int *pos_j, int *tail_length, int vi_tail[100], int vj_tail[100]) 
{
    
    if (*tail_length > 0) {
        for (int i = (*tail_length) ; i > 0; i--) {
            vi_tail[i] = vi_tail[i - 1];
            vj_tail[i] = vj_tail[i - 1];
        }
        vi_tail[0] = *pos_i;
        vj_tail[0] = *pos_j;
    }  else if (*tail_length == 0) {
        vi_tail[0] = *pos_i;
        vj_tail[0] = *pos_j;
    }
    

    if (c == 'w') {
        (*pos_i)--;
    }
    if (c == 'd') {
        (*pos_j)++;
    }
    if (c == 's') {
        (*pos_i)++;
    }
    if (c == 'a') {
        (*pos_j)--;
    }
}

void make_random(int n, int m, int v[100][100]) 
{

    for (int i = 0; i < n / 2; i++) {

        
        int numi = rand() % (n);
        if(numi == 0)
            numi++;

        if(numi == n - 1)
            numi--;

        int numj = rand() % (m);
        if(numj == 0)
            numj++;

        if(numj == m - 1)
            numj--;

        v[numi][numj] = 1;
    }

}

int make_one_random(int n) 
{
    int numi = rand() % (n);
        if (numi == 0)
            numi++;

        if (numi == n - 1)
            numi--;
    return numi;
}

void verif_pos(int n, int m, int v[100][100], int pos_i, int pos_j, int vi_tail[100], int vj_tail[100], int *tail_length)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (v[i][j] == 1 && pos_i == i && pos_j == j) {
                int k = make_one_random(n);
                int l = make_one_random(n);

                v[i][j] = 0;
                
                if(*tail_length == -1) {
                    *tail_length = 0;
                } else {
                (*tail_length)++;
                }
                for (int i = (*tail_length) - 1; i > 0; i--) {
                    vi_tail[i] = vi_tail[i - 1];
                    vj_tail[i] = vj_tail[i - 1];
                    
                }
                vi_tail[0] = pos_i;
                vj_tail[0] = pos_j;
                
                int ok = 0;
                while(ok != 1) {
                    if(v[l][k] == 0)
                        ok = 1;
                     k = make_one_random(n);
                     l = make_one_random(n);
                }
                v[l][k] = 1;
            }
                
}



