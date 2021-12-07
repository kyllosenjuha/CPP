#include <stdio.h>
#include <stdlib.h>

int main()
{
    const double PI=3.1415926536;
    double sade=0.0;

    printf("Syota ympyran sade: ");
    scanf("%lf", &sade);

    printf("Ympyran kehan pituus on: %lf\n", 2*PI*sade);
    return 0;
}
