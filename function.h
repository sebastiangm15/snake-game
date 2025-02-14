void matrix(int n, int m, int pos_i, int pos_j, int v[100][100], int tail_length, int vi_tail[100], int vj_tail[100]);

void position(int n, int m, char c, int *pos_i, int *pos_j, int *tail_length, int vi_tail[100], int vj_tail[100]);

void make_random(int n, int m, int v[100][100]);

int make_one_random(int n);

void verif_pos(int n, int m, int v[100][100], int pos_i, int pos_j, int vi_tail[100], int vj_tail[100], int *tail_length);

int search(int vi_tail[100], int vj_tail[100], int i, int j, int tail_length, int v[100][100]);

int death_condition(int i, int j, int tail_length, int vi[100], int vj[100], int n, int m);

