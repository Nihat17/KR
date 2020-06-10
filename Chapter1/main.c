#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
#define TABSTOP 5        /* fixed tabstop set to 4 */

void detab(void) {
    extern char line[MAXLINE];

    int c, j, i;
    j = i = 0;

    for(i=0; (c = getchar()) != EOF; ++i)
        if(c == '\t') {
            line[i++] = ' ';

            while(i % TABSTOP != 0)
                line[i++] = ' ';
            --i;
        }

        else
            line[i] = c;

}

void exer1_20() {

    /*
        Write a program detab that replaces tabs in the input with the proper number
        of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
        Should n be a variable or a symbolic parameter?

        Meaning whenever program sees \t, it needs to determine how many spaces should put
        For instance if tab stop is 5, if \t is on 0 it should go to the value which is divisible by 5
        which is 5, if cursor is on 7 it should move to 10 since 10 is the next number divisible by 5
    */


    printf("Exercise 1_20...\n");

    extern char line[MAXLINE];
    detab();
    printf("\nConverted: '%s'", line);
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
