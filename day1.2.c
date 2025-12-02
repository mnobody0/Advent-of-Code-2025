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
            total++;
        }
        if(dir == 'L'){
            cur -= steps;
            if(cur < 0){
                cur += 100;
                if(cur - 100 != steps*-1){
                    total++;
                }
            } else if(cur == 0){
                total ++;
            }
        } else if(dir == 'R'){
            cur += steps;
            if(cur > 99){
                cur -= 100;
                if(cur != steps*-1){
                    total++;
                }
            } else if(cur == 0){
                total ++;
            }
        } else {
            printf("error reading direction\n");
        }
    }
    printf("%d\n", total);
    fclose(input);
    return 0;
}