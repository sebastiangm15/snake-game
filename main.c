#include "stdio.h"
#include "stdlib.h"
#include "function.h"
#include "termios.h"
#include "time.h"
#include "sys/select.h"
#include "unistd.h"

int kbhit() { //function from windows to see if i read or not a key
    struct timeval tv = {0, 0};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(1, &fds, NULL, NULL, &tv) > 0;
}

void setInputMode() {
    struct termios new_tio;
    tcgetattr(STDIN_FILENO, &new_tio);
    new_tio.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
}

void restore_terminal() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO); // Re-enable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

int main(void)
{

    char c, c_new;
    int n = 15, m = 15, v[100][100] = {0};
    int start_i = n / 2, start_j = m / 2, tail_length = -1;
    
    srand(time(NULL));
    make_random(n, m, v);
    setInputMode();
    int vi_tail[100] = {0}, vj_tail[100] = {0}; 

    while (c != 'q') {
        //int vi_tail[100] = {0}, vj_tail[100] = {0}; 
        //c = getchar();
        if (kbhit()) {
            read(STDIN_FILENO, &c, 1);
        }
        usleep(300000);
        position(n, m, c, &start_i, &start_j, &tail_length, vi_tail, vj_tail);
        printf("\033[H\033[J");  // Clear screen using ANSI escape codes
      
        matrix(n, m, start_i, start_j, v, tail_length, vi_tail, vj_tail);

        verif_pos(n, m, v, start_i, start_j, vi_tail, vj_tail, &tail_length);
        printf("score : %d\n", (tail_length + 1) * 10);


    }
    printf("\n%d\n", tail_length);
    for(int i = 0; i < tail_length; i++) {
        printf("%d %d\n", vi_tail[i], vj_tail[i]);
    }

    restore_terminal();

    return 0;
    

}
 