#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>



 
int main(void){
    
    int r = 1;
    char* v = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    struct input_event e;
    int f = open(v, O_RDONLY);
    

    while(1){
        ssize_t r = read(f, &e, sizeof(e));

        if (e.type != EV_KEY && (e.value == 0 || e.value == 1)){
            if(e.value == 1)
                printf("PRESSED ");
            if(e.value == 0)
                printf("RELEASED ");

            printf("%x (%d)\n", e.code, e.code);
        }
        fflush(stdout);
    }
    return 0;
}