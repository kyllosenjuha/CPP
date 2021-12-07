#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAX_LKM 10
#define MAX_NIMEN_PITUUS 30



int main()
{
    int NIMIA=0;

    int jaettava_raha=25000, arpa_numero=1, voittosumma=0, arvotut=0, aiemmat_arvat[MAX_LKM], voitot[MAX_LKM];
    char jatko, temp, nimet[MAX_LKM][MAX_NIMEN_PITUUS];

    printf("Arvontaan osallistujien nimet MAX: %d\n", MAX_LKM);

    do {
        printf("Syota %d. nimi: ", NIMIA+1);
        fgets(nimet[NIMIA], sizeof(nimet[NIMIA]), stdin);

        printf("Haluatko lopettaa? (k/e): ");
        scanf("%c", &jatko);
        scanf("%c", &temp);
        if(jatko == 'k' || jatko == 'K')
        {
            NIMIA++;
            break;
        }
        else
            NIMIA++;

        if(NIMIA == MAX_LKM)
            break;

    } while(true);

    for(int i=0; i<MAX_LKM; i++)
    {
        aiemmat_arvat[i] = 0;
    }
    srand(time(NULL));

    do {

    voittosumma=rand() % jaettava_raha + 1;
    voitot[arvotut] = voittosumma;
    jaettava_raha -= voittosumma;

    arpa_numero=rand() % NIMIA + 1;

    for(int k=0; k<arvotut+1;)
    {
        if(arpa_numero == aiemmat_arvat[k])
        {
            arpa_numero=rand() % NIMIA + 1;
            k=0;
        }
        else
            k++;
    }

    aiemmat_arvat[arvotut] = arpa_numero;

    printf("Voittajan nimi: %s", nimet[aiemmat_arvat[arvotut] - 1]);
    printf("Voittosumma: %5d eur, Arpanumero: %2d\n\n" ,voitot[arvotut], aiemmat_arvat[arvotut]);
    arvotut++;

    if(arvotut == NIMIA)
    {
        printf("Hyvantekevaisyyteen menee: %5d eur\n", jaettava_raha);
        break;
    }

    } while(jaettava_raha > 0);

    return 0;
}
