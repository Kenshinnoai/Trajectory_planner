#include <stdio.h>
#include <math.h>
#include <locale.h>

static int dispValues(double T, double x0, double v0, double x1, double v1)
{
            /* объявление переменных для дополнения данных */

    double rate;
    double T1 = 0;

            /* объявлене и инициализация необходимых констаант */

    const double a0 = x0;
    const double a1 = v0;
    const double a2 = (3 * (x1 - x0) + T * (2 * v0 - v1)) / pow(T, 2);
    const double a3 = (T * (v1 - 3 * v0) - 2 * (x1 - x0)) / pow(T, 3);

            /* первый стандартный вывод для T = 0 */

    printf("время        x0     v0,     x1,     v1\n");
    printf("\n%.3lf сек %8.3lf, %4.3lf, %4.3lf, %4.3lf\n", T1, x0, v0, x1, v1);

            /* инициализация интервалов вывода */
    printf("Введите значение интервала времени, через который будут выводиться данные (прим. 1 (сек), 0.5 (сек) и тд)\t");

    if (!scanf("%lf", &rate))
        return 1;

            /* далее вывод данных по rate секундам */

    for (; T1 <= T; T1 += rate)
    {
        x1 = a0 + a1 * T1 + a2 * pow(T1, 2) + a3 * pow(T1, 3);
        v1 = a1 + 2 * a2 * T1 + 3 * a3 * pow(T1, 2);

        printf("\n%.3lf сек %8.3lf, %4.3lf, %4.3lf, %4.3lf\n", T1, x0, v0, x1, v1);
    }
}

int main()
{
            /* Объявление переменных для хранения начальных значений */

    setlocale(LC_ALL, "Rus");
    double x0, v0, x1, v1;
    double T = 0;

            /* инициализация начальных значений переменных */

    printf("Введите начальные и конечные данные графика\n\n");

    printf("Сначала начальное положение:\t");
    if (!scanf("%lf", &x0))
        return 1;

    printf("Теперь начальную скорость:\t");
    if(!scanf("%lf", &v0))
        return 1;

    printf("\nА теперь конечное положение:\t");
    if(!scanf("%lf", &x1))
        return 1;

    printf("Теперь конечную скорость:\t");
    if(!scanf("%lf", &v1))
        return 1;

    printf("А тут время конца движения:\t");
    if(!scanf("%lf", &T))
        return 1;

            /* передача аргументов функции для их последующего отображения */

    dispValues(T, x0, v0, x1, v1);

    return 0;
}
