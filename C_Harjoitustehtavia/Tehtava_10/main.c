#include <stdio.h>
#include <stdlib.h>

int main()
{
    int luvut[15], summa=0;

    for(int i=0; i<(sizeof(luvut)/sizeof(luvut[0])); i++)
    {
        do {
        printf("Syota positiivinen kokonaisluku %d: ", i+1);
        scanf("%d", &luvut[i]);
            if(luvut[i] > 0)
            {
                summa = summa+luvut[i];
            }
            else
            {
                printf("virheellinen syote\n");
            }


        } while(luvut[i] <= 0);
    }


    printf("Lukujen summa on: %d\n", summa);

    return 0;
}
