#include <stdio.h>
#include <stdlib.h>

int main()
{
    double sade=0;
    const double PI=3.1415926536;

    printf("Syota ympyran sade: ");
    scanf("%lf", &sade);

    printf("Ympyran ala on: %.6lf\n", PI*sade*sade);

    return 0;
}
