#include <stdio.h>
#include <stdlib.h>

int main()
{
    float tyylipisteet[5], summa=0.0, pienin=20.0, suurin=0.0, pituus=0.0, pituuspisteet=0.0;

    printf("Anna hypyn pituus K200: ");
    scanf("%f", &pituus);

    pituuspisteet=60+1.8*(pituus-200);

    for(int i=0; i<5; i++)
    {
        do {
        printf("Anna tuomarin %d pisteet: ", i+1);
        scanf("%f", &tyylipisteet[i]);

        if(tyylipisteet[i] < 0 || tyylipisteet[i] > 20 || (tyylipisteet[i] - (int)tyylipisteet[i] != 0.0 && tyylipisteet[i] - (int)tyylipisteet[i] != 0.5))
            printf("Tyylipisteet pitaa olla valilla 0-20, 0.5-valein\n");


        } while(tyylipisteet[i] < 0 || tyylipisteet[i] > 20 || (tyylipisteet[i] - (int)tyylipisteet[i] != 0.0 && tyylipisteet[i] - (int)tyylipisteet[i] != 0.5));

        if(tyylipisteet[i] < pienin)
            pienin=tyylipisteet[i];

        if(tyylipisteet[i] > suurin)
            suurin=tyylipisteet[i];

        summa += tyylipisteet[i];
    }

    printf("Tyylipisteiden summa on: %.1f\n", summa-pienin-suurin);
    printf("Lopulliset pisteet ovat: %.1f\n", summa-pienin-suurin+pituuspisteet);

    return 0;
}
