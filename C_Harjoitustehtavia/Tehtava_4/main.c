#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num1=0, num2=0;
    printf("Syota luku1: ");
    scanf("%f", &num1);

    printf("Syota luku2: ");
    scanf("%f", &num2);

    printf("summa=%f\n", num1+num2);
    printf("erotus=%f\n", num1-num2);
    printf("osamaara=%f\n", num1/num2);
    printf("keskiarvo=%f\n", (num1+num2)/2);
    return 0;
}
