#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int arvosanat[6] = {0, 0, 0, 0, 0, 0}, temp=0, arvosanojen_summa=0, arvosanojen_maara=0;
    float keskihajonta=0.0, keskiarvo=0.0;

    do {
        printf("Syota arvosana 0-5 (kokonaisluku), -1=lopetus: ");
        scanf("%d", &temp);

        switch (temp)
        {
            case 0:
                arvosanat[0]++;
                break;
            case 1:
                arvosanat[1]++;
                break;
            case 2:
                arvosanat[2]++;
                break;
            case 3:
                arvosanat[3]++;
                break;
            case 4:
                arvosanat[4]++;
                break;
            case 5:
                arvosanat[5]++;
                break;
            case -1:
                printf("Lopetus\n");
                break;
            default:
                printf("Syotit epakelvon arvosanan\n");
        }
    } while(temp != -1);

    for(int i=0; i<6; i++)
    {
            arvosanojen_summa += i*arvosanat[i];
            arvosanojen_maara += arvosanat[i];
    }

    keskiarvo=(float)arvosanojen_summa/arvosanojen_maara;
    printf("Arvosanojen keskiarvo: %.2f\n", keskiarvo);

    printf("Arvosanojen jakauma:\n");

    for(int i=0; i<6; i++)
    {
        printf("%d: ", i);
        for(int j=0; j<arvosanat[i]; j++)
            printf("*");
        printf("\n");
    }

    for(int i=0; i<6; i++)
    {
        for(int j=0; j<arvosanat[i]; j++)
        {
            keskihajonta += pow(i - keskiarvo, 2);
        }
    }

    keskihajonta=sqrt(keskihajonta/arvosanojen_maara);

    printf("Keskihajonta: %.3f\n", keskihajonta);

    return 0;
}
