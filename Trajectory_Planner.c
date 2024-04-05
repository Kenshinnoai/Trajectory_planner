#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Spline
{
    double x0, v0, x1, v1, DestTime, rate;
    double a0, a1, a2, a3;
};

static struct Spline CoeffCount(struct Spline spl);

static void DispValues(struct Spline spl);


int main(int argc, char* argv[])
{
    /* Are there enough arguments check */

    if ((argc < 7) || (argc > 7))
    {
        printf("Not enough arguments\n");
        printf("Remember, you have to put 6 values\n");

        return 1;
    }

    /* Initialization of structure to put there entered into main() values */

    struct Spline s1;

    s1.x0 = atof(argv[1]);
    s1.v0 = atof(argv[2]);

    s1.x1 = atof(argv[3]);
    s1.v1 = atof(argv[4]);

    s1.DestTime = atof(argv[5]);
    s1.rate = atof(argv[6]);

    s1 = CoeffCount(s1);

    DispValues(s1);

    return 0;
}

static struct Spline CoeffCount(struct Spline spl)
{
    spl.a0 = spl.x0;
    spl.a1 = spl.v0;
    spl.a2 = (3 * (spl.x1 - spl.x0) + spl.DestTime * (2 * spl.v0 - spl.v1)) / pow(spl.DestTime, 2);
    spl.a3 = (spl.DestTime * (spl.v1 - 3 * spl.v0) - 2 * (spl.x1 - spl.x0)) / pow(spl.DestTime, 3);

    return spl;
}

static void DispValues(struct Spline spl)
{
    /* Displaying all arguments every "rate" second */

    printf("time        x0     v0,     x1,     v1\n");

    for (double T = 0; T <= spl.DestTime; T += spl.rate)
    {
        printf("\n%.3lf sec %8.3lf, %4.3lf, %4.3lf, %4.3lf\n", T, spl.x0, spl.v0, spl.x1, spl.v1);

        spl.x0 = spl.x1;
        spl.v0 = spl.v1;

        /* Solving values for x1 and v1 for current second */

        spl.x1 = spl.a0 + spl.a1 * T + spl.a2 * pow(T, 2) + spl.a3 * pow(T, 3);
        spl.v1 = spl.a1 + 2 * spl.a2 * T + 3 * spl.a3 * pow(T, 2);
    }

}
