#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define TABSTOP 5

int main()
{
    exer1_21();
    return 0;
}

void exer1_21() {
    /*
        Write a program entab that replaces strings of blanks by the minimum number
        of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab . When
        either a tab or a single blank would suffice to reach a tab stop, which should be given
        preference?
    */
    printf("Exercise 1.21...\n");

    int input_len = getinput();

    detab_local(input_len);

}

char line[MAXLINE];

int getinput() {
    extern char line[MAXLINE];
    int c, i;

    for(i = 0; (c = getchar()) != EOF && i < MAXLINE; ++i)
        line[i] = c;
    return i;
}

void detab_local(int len) {
    extern char line[MAXLINE];
    int sp = -1, i;

    int tabs[len];
    for(i = 0; i < len; ++i)
        tabs[i] = 0;

    char line_n[len];

    for(i = 0; i < len; ++i) {
        if(i != 0 && line[i - 1] == ' ' && i % TABSTOP == 0 && sp != -1) {
            tabs[sp] = 1;
            sp = (line[i] == ' ') ? i : -1;
        }
        if(line[i] == ' ' && sp == -1)
            sp = i;
    }

    int flag = 0, k = 0;

    for(i = 0; i < len; ++i) {
        if(flag == 1 && i % TABSTOP == 0 || flag == 1 && line[i] != ' ')
            flag = 0;

        if(tabs[i] == 1) {
            line_n[k++] = '\\t';
            flag = 1;
        }
        else if(flag == 0)
            line_n[k++] = line[i];
    }
    // line_n[i] = '\0';
    printf("\n'%s'", line_n);
}

