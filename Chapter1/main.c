#include <stdio.h>
#include <stdlib.h>

#define TABSTOP 8        /* fixed tabstop set to 4 */
#define MAXLINE 1000     /* Size of the input */
#define MAXWIDTH 5       /* WIDTH that each line should have */

#define IN 1             /* state for being inside comment */
#define OUT 0

int main()
{
    exer1_24();
    return 0;
}

char line[MAXLINE];

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
    char line_n[len];
    for(i = 0; i < len; ++i){
        tabs[i] = 0;
        line_n[i] = 'a';
    }


    for(i = 0; i < len; ++i) {
        if(i != 0 && line[i - 1] == ' ' && i % TABSTOP == 0 && sp != -1) {
            tabs[sp] = 1;
            sp = (line[i] == ' ') ? i : -1;
        }
        if(line[i] == ' ' && sp == -1)
            sp = i;
        else if(line[i] != ' ')
            sp = -1;
    }

    int flag = 0, k = 0;

    for(i = 0; i < len; ++i) {
        if(flag == 1 && i % TABSTOP == 0 && i != len - 1 || flag == 1 && line[i] != ' ')
            flag = 0;

        if(tabs[i] == 1) {
            line_n[k++] = '\\t';
            flag = 1;
        }
        else if(flag == 0)
            line_n[k++] = line[i];

    }
    line_n[k] = '\0';
    printf("\n'%s'", line_n);
}


void exer1_22() {
    printf("Exercise 1.22...\n");

    int input_len = getinput();

    char output[MAXLINE];
    extern char line[MAXLINE];          /* input array */

    int c, i, ptr_i = -1, ptr_k = -1, k = 0, flag = -1;
    int output_counter = 0, lim = -1;

    for(i = 0; i < input_len; ++i) {
        if(output_counter < MAXWIDTH) {
            if(line[i] != '\t'){
                if(line[i] == ' ') {
                    ptr_i = i;
                    ptr_k = k;
                    flag = 1;
                }
                else if(flag == -1 || line[i + 1] == ' ' && output_counter + 1 < MAXWIDTH) {
                    ptr_i = i;
                    ptr_k = k;
                }
                output[k++] = line[i];
                ++output_counter;
            }
            else {
                ptr_k = k;
                while(output_counter != TABSTOP) {
                    if(output_counter >= MAXWIDTH) {
                        lim = 1;
                        break;
                    }

                    output[k++] = ' ';
                    ++output_counter;
                }
            }
        }
        if(output_counter >= MAXWIDTH || lim == 1){
            k = ++ptr_k;
            output_counter = 0;
            i = (ptr_i != -1) ? ptr_i : i;
            if(lim == 1) {
                while(++output_counter < TABSTOP)
                    output[k++] = ' ';
                ptr_k = k;
                lim = -1;
                output_counter = 0;
                ++i;
            }
            output[k++] = '\n';
            flag = -1;
        }
    }
    output[k] = '\0';

    printf("\n%s", output);
}

void exer1_23() {

    /*
        Write a program to remove all comments from a C program. Don't forget to
        handle quoted strings and character constants properly. C comments don't nest.
    */

    printf("Exercise 1.23...\n");

    int state = OUT;
    int c, com_type = 0, flag = 0, k = 0;

    char output[MAXLINE];

    while((c = getchar()) != EOF && k < MAXLINE) {
        if(state == OUT) {
            output[k++] = c;

            if(flag == 1 && c == '/' || flag == 1 && c == '*') {
                state = IN;
                com_type = (c == '/') ? 0 : 1;
                flag = 0;
                k -= 2; // might be 3
            }
            else if(c == '/')
                flag = 1;

        }
        else {
            if(com_type == 0 && c == '\n')
                state = OUT;
            else if(com_type == 1){
                if(flag == 1 && c == '/') {
                    state = OUT;
                    flag = 0;
                }
                else if(flag == 0 && c == '*')
                    flag = 1;
            }
        }
    }
    output[k] = '\0';
    printf("\nConverted:\n%s", output);
}

int contain(char c, char arr[]);
int bugcheck();

void exer1_24() {
    /*  Write a program to check a C program for rudimentary syntax errors like
        unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
        double, escape sequences, and comments. (This program is hard if you do it in full generality.)
    */
    // printf("%d %d %d %d %d %d", '(', '{', '[', '\'', '\"', '`');
    printf("Exercise 1.24...\n");

    printf("\nBug found: %d", bugcheck());

}
int contain(char c, char arr[]) {
    for(int i = 0; i < 5; ++i)
        if(c == arr[i])
            return i;
    return -1;
}

int bugcheck() {

    char op_arr[5];
    op_arr[0] = '[';
    op_arr[1] = '{';
    op_arr[2] = '(';
    op_arr[3] = '\'';
    op_arr[4] = '\"';

    char cl_arr[5];
    cl_arr[0] = ']';
    cl_arr[1] = '}';
    cl_arr[2] = ')';
    cl_arr[0] = '\'';
    cl_arr[0] = '\"';

    printf("%c", b);

    int stack[MAXLINE];

    int ptr = 0, c, index, i, input_size, state = -1;

    // Out -1 -> close
    // IN (*) -> open

    for(i = 0; i < MAXLINE; ++i)
        stack[i] = -1;

    for(input_size = 0; (c = getchar()) != EOF; ++input_size) {
        if(state == -1 && (index = contain(c, op_arr)) != -1) {
            stack[ptr++] = index;
            state = (index > 2) ? index : -1;
        }
        else if((index = contain(c, cl_arr)) != -1) {
            if(ptr != 0 && stack[ptr - 1] == index){
                stack[ptr--] = -1;
                stack[ptr] = -1;
                state = (state == IN) ? OUT : IN;
            }
            else
                return 1;
        }
    }

    for(i = 0; i < input_size; ++i)
        if(stack[i] != -1)
           return 1;
    return 0;
    printf("Hello");
}
