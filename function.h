void matrix(int n, int m, int pos_i, int pos_j, int v[100][100], int tail_length, int vi_tail[100], int vj_tail[100]);
//print the matrix in the terminal

void position(int n, int m, char c, int *pos_i, int *pos_j, int *tail_length, int vi_tail[100], int vj_tail[100]);
//move the tail and move the head

void make_random(int n, int m, int v[100][100]);
//add in the v[100][100] number randoms

int make_one_random(int n);
//make one number random

void verif_pos(int n, int m, int v[100][100], int pos_i, int pos_j, int vi_tail[100], int vj_tail[100], int *tail_length);
//verify if the head is on the star and add one new on the map, make bigger the tail

int search(int vi_tail[100], int vj_tail[100], int i, int j, int tail_length, int v[100][100]);
//this function verify where the tail is to print

int death_condition(int i, int j, int tail_length, int vi[100], int vj[100], int n, int m);
//function to verify if the game continue or end

