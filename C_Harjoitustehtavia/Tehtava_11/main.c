#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int lukuja=0, summa=0, pistemaara=0, pienin=INT_MAX;
    float keskiarvo=0.0;

    do {
        printf("Syota postiivinen pistemaara, (lopetus=0): ");
        scanf("%d", &pistemaara);

        if(pistemaara < pienin && pistemaara > 0)
        {
            pienin=pistemaara;
        }

        if(pistemaara > 0)
        {
            summa += pistemaara;
            lukuja++;
        }

        if(pistemaara < 0)
        {
            printf("Syotit negatiivisen pistemaaran!\n");
        }

    } while(pistemaara != 0);

    if(lukuja == 0)
        printf("Et syottanyt yhtaan pistemaaraa\n");
    else
        keskiarvo=(float)summa/lukuja;

    printf("Lukujen keskiarvo on: %.3f\n", keskiarvo);
    printf("Pienin pistemaara on: %d\n", pienin);

    return 0;
}
