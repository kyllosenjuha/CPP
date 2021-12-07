#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main()
{
    int luku=0, x=0, arvauskertoja=0;
    char uudestaan='k', temp='a';

    srand(time(NULL));

    x=rand() % 10;

    while(true) {

        printf("Arvaa luku valilta 0-9: ");
        scanf("%d", &luku);
        arvauskertoja++;

        if(luku < x)
            printf("Arvaus oli liian pieni\n");
        else if(luku > x)
            printf("Arvaus oli liian suuri\n");
        else {
            printf("Arvaus oli oikein. Arvauskertoja oli: %d\n", arvauskertoja);

            printf("Haluatko aloittaa uudestaan, k/e: ");

            scanf("%c", &temp);
            scanf("%c", &uudestaan);

            if(!(uudestaan == 'k' || uudestaan == 'K')
 )          {
                printf("Ohjelma paattyi\n");
                break;
            }
            else
            {
                arvauskertoja=0;
                x=rand() % 10;
            }
        }
    }

    return 0;
}
