#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

#define SIGNED      0
#define UNSIGNED    1

void exer1_2();
int atoi2(char[]);
int lower2(char);

int main()
{
    exer1_2();

    printf("\nConverted number: %d", atoi2("12345"));

    printf("\nlower value of J is %c", lower2('J'));

    return 0;
}

void compute_size(int, int);

void exer1_2() {
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
    return pow(val, power - 1) * 2;
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
