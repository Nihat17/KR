#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

#define SIGNED      0
#define UNSIGNED    1

void exer1_2();

int atoi2(char[]);

int lower2(char);

int htoi(char[]);

int main()
{
    exer2_1();

    printf("\nDecimal value of 0xFee7A9 = %d", htoi("0xFee7A9"));
    return 0;
}

void compute_size(int, int);

void exer2_1() {
    printf("Range of signed char %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Range of unsigned char 0 to %d\n\n", UCHAR_MAX);

    printf("Range of signed short int %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Range of unsigned short int 0 to %d\n\n", USHRT_MAX);

    printf("Range of signed int %d to %d\n", INT_MIN, INT_MAX);
    printf("Range of unsigned int 0 to %lu\n\n", UINT_MAX);

    printf("Range of signed long int %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Range of unsigned long int 0 to %lu\n\n", ULONG_MAX);

    printf("Range of float %e to %e\n", FLT_MIN, FLT_MAX);
    printf("Range of double %e to %e\n", DBL_MIN, DBL_MAX);
    printf("Range of long double %e to %e\n", LDBL_MIN, LDBL_MAX);

    printf("\nSize range of char is ");
    compute_size(sizeof(char), SIGNED);

    printf("Size range of signed char is ");
    compute_size(sizeof(char), SIGNED);

    printf("Size range of unsigned char is ");
    compute_size(sizeof(char), UNSIGNED);

    printf("Size range of int is ");
    compute_size(sizeof(int), SIGNED);

    printf("Size range of signed int is ");
    compute_size(sizeof(int), SIGNED);

    printf("Size range of unsigned int is ");
    compute_size(sizeof(int), UNSIGNED);

    printf("Size range of signed short is ");
    compute_size(sizeof(short), SIGNED);

    printf("Size range of unsigned short is ");
    compute_size(sizeof(short), UNSIGNED);
}

long long pow(int val, int power);

void compute_size(int n_byte, int state) {

    int n_bits = n_byte * 8;

    if(state == UNSIGNED) {
        printf("0 to %lld\n", pow(2 ,n_bits) - 1);
    }
    else{
        long long val = pow(2, n_bits);
        printf("%lld to %lld\n", -val + val / 2, (val - val / 2) - 1);
    }
}

long long pow(int val, int power) {
    if(power == 0)
        return 1;
    return pow(val, power - 1) * val;
}

/* implementation of atoi function */

int atoi2(char s[]) {
    int i, n;

    n = 0;
    for(i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

/*
    implementation of lower function
    between each lower and corresponding capital letter difference is 32
*/
int lower2(char c) {
    if(c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    return c;
}

/*
    Write a function htoi(s) , which converts a string of hexadecimal digits
    (including an optional 0x or 0X ) into its equivalent integer value. The allowable digits are 0
    through 9 , a through f , and A through F .
*/
int getStrLen(char[]);

int htoi(char s[]) {

    if(s[0] != '0' && s[1] != 'x' || s[0] != '0' && s[1] != 'X')
        return -1;

    char hex_vals[6];
    int i;

    int output = 0;

    for(i = 0; i < 6; ++i)
        hex_vals[i] = i + 10;

    int power = getStrLen(s) - 3;
    int x = 0;

    for(i = 2; s[i] != '\0'; ++i) {
        if(s[i] >= 'A' && s[i] <= 'Z')
            x = hex_vals[s[i] - 65];
        else if(s[i] >= 'a' && s[i] <= 'z')
            x = hex_vals[s[i] - 97];
        else if(s[i] >= '0' && s[i] <= '9')
            x = s[i] - 48;
        else
            return -1;

        output += x * pow(16, power--);
    }

    return output;
}

int getStrLen(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; ++i)
        ;
    return i;
}
