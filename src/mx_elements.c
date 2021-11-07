#include "../inc/pathfinder.h"

void mx_elements(char *line, char *result[3]) {
    int i = 0;
    int count = 0;
    int numerator;
    int denominator;
    while (line[i]) {
        if (line[i] == '-') {
            numerator = i;
            char *word = mx_strnew(i);
            int tmp1 = 0; 
            while(line[tmp1] != '-') {
                word[tmp1] = line[tmp1];
                tmp1++;
            }
            result[count] = word;
            count++;
        }
        else if (line[i] == ',') {
            denominator = i;
            char *word = mx_strnew(i - (numerator + 1));
            int tmp2 = numerator + 1;
            int x = 0;
            while(line[tmp2] != ',') {
                word[x] = line[tmp2];
                x++;
                tmp2++;
            } 
            result[count] = word;
            count++;
        }
        else if (mx_isdigit(line[i]) != -1) {
            int tmp3 = denominator + 1;
            int len = 0;
            while (line[denominator])
                len++, denominator++;
            char *word = mx_strnew(len);
            int y = 0;
            while(line[tmp3]) {
                word[y] = line[tmp3];
                y++;
                tmp3++;
            }
            result[count] = word;
            count++;
        }
        i++;
    } 
}
