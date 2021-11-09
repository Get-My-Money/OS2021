#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <linux/input.h>
 

int main(void) {
    char *v = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    int ccc[3] = {-1, -1, -1};
    int f = open(v, O_RDONLY);
    struct input_event e;
    int cc[3][3] = {{-1,  -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
    int ccq[3] = {-1,  -1, -1};
  



    while (1) {
        ssize_t r = read(f, &e, sizeof(e));

        if ((e.type == EV_KEY) && (e.value == 0 || e.value == 1)){
            for (int i = 0; i < 3; i++) {
                int gab = 1;
                for (int j = 0; j < 3; j++) {
                    if (cc[i][j] == 0){
                      if (ccq[j] != cc[i][j]) {
                          gab = 0;
                          break;
                      }
                }

                if (gab) {
                    if (i == 0)
                      printf("I passed the Exam!\n");
                    if (i == 1)
                        printf("Get some cappuccino!\n");
                    if (i == 2)
                        printf("4rtm\n");
                    }
                    break;
                }
            }
            fflush(stdout);
        }
    }
    return -1;
}