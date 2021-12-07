#include <stdio.h>
#include <stdlib.h>

int main()
{
    float rahamaara=0.0, lihapiirakka=0.0;

    printf("Syota lompakossa oleva rahamaara: ");
    scanf("%f", &rahamaara);

    printf("Syota lihapiirakan hinta: ");
    scanf("%f", &lihapiirakka);

    if(rahamaara >= lihapiirakka)
        printf("Saat ostettua lihapiirakan, sinulle jaa lompakkoon rahaa: %.2f\n", rahamaara-lihapiirakka);
    else
        printf("Sinun pitaa paastota, sinulla on lompakossa rahaa: %.2f\n", rahamaara);

    return 0;
}
