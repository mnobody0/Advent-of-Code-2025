#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILENAME "input1.txt"

int main(void){
    FILE* input = fopen(FILENAME, "r");
    char dir;
    int steps;
    int cur = 50;
    int total = 0;

    while(fscanf(input, " %c%d", &dir, &steps) == 2){
        while(steps > 100){
            steps -= 100;
        }
        if(dir == 'L'){
//printf("L:%d\n", steps);
            cur -= steps;
            if(cur < 0){
                cur += 100;
            }
//printf("C:%d\n", cur);
        } else if(dir == 'R'){
//printf("R:%d\n", steps);
            cur += steps;
            if(cur > 99){
                cur -= 100;
            }
//printf("C:%d\n", cur);
        } else {
            printf("erorr reading direction\n");
        }
        if(cur == 0){
            total ++;
        }
    }
    printf("%d\n", total);
    fclose(input);
    return 0;
}