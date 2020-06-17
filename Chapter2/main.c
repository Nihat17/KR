#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main()
{
    exer1_2();
    return 0;
}

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
}

int pow(int val, int powe);

int compute_size(int n_bits) {
    int result = 0, i;

    for(i = 0; i < n_bits; ++i)
        result += pow(2, i);

    return result;
}

int pow(int val, int power) {
    if(power == 0)
        return 1;
    return pow(val, pow - 1) * 2;
}
