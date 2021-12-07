#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1=0, num2=0;
    printf("Syota kokonaisluku1: ");
    scanf("%d", &num1);

    printf("Syota kokonaisluku2: ");
    scanf("%d", &num2);

    if(num1%num2==0)
        printf("BINGO\n");
    else
        printf("BONGO\n");

    return 0;
}
