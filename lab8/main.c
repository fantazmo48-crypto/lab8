#include <stdio.h>
#include <locale.h>
#include <math.h>
#define M_PI 3.14159265358979323846

int main()
{
    setlocale(LC_ALL, ".UTF-8");
	Work0Symbols();
	Work1Sum();
	Work1APow();
	Work2Tabu();
	HomeWork();
    return 0;
}

int Work0Symbols()
{
    int count;
    char first, second, endSymbol;
    puts("Задание 0\n");
    printf_s("Введите количество символов: ");
    if (scanf_s("%d", &count) != 1 || count < 1) {
        printf_s("Ошибка: введите положительное целое число.\n");
        return 1;
    }

    printf_s("Введите первый символ: ");
    scanf_s(" %c", &first, 1);

    printf_s("Введите второй символ: ");
    scanf_s(" %c", &second, 1);

    printf_s("Введите завершающий символ: ");
    scanf_s(" %c", &endSymbol, 1);

    printf("\nРезультат:\n");

    for (int i = 1; i <= count; i++) {
        // Первая половина — первый символ, вторая половина — второй.
        // Если количество нечётное, центральное место занимает первый символ.
        char current = (i <= count / 2) ? first : second;

        // В начале и в конце добавляется '+',
        // после каждого символа печатается введённый завершающий знак.
        putchar('+');
        putchar(current);
        putchar(endSymbol);
    }

    putchar('+');
    putchar('\n');
	puts("\n\n\n");
    return 0;
}

int Work1Sum()
{
    int m, n;
    int i;
    int count = 0;
    long long sum = 0;
    puts("Задание 1\n");
    printf_s("Введите m и n (m должно быть не меньше n): ");

    if (scanf_s("%d %d", &m, &n) != 2) {
        printf_s("Ошибка: введите два целых числа.\n");
        return 1;
    }

    if (m < n) {
        printf_s("Ошибка: для этого варианта m должно быть не меньше n.\n");
        return 1;
    }

    for (i = m; i >= n; i--) {
        sum += i;
        count++;

        printf_s("Выполнено %d раз(а), текущее число: %d, сумма: %lld\n",
            count, i, sum);
    }

    printf_s("Сумма целых чисел от %d до %d включительно равна %lld.\n\n\n\n",
        m, n, sum);

    return 0;
}

int Work1APow()
{
    int n;
    int m;
    double value = 1.0;
    puts("Задание 1A\n");
    printf_s("Введите степень n (от 0 до 1023): ");
    if (scanf_s("%d", &n) != 1 || n < 0 || n > 1023) {
        printf_s("Ошибка: введите целое число от 0 до 1023.\n");
        return 1;
    }

    printf_s("\nСтепени двойки до n = %d:\n", n);

    // Выводим 2^0, 2^1, ..., 2^n
    for (int i = 0; i <= n; i++) {
        printf_s("%4d^%d = %20.0f\n", 2, i, value);
        value *= 2.0;
    }

    // После цикла value равно 2^(n+1),
    // поэтому для 2^n делим его на 2.
    value /= 2.0;
    printf_s("\nРезультат: %.0fK\n", value / 1024.0);

    printf_s("\nВведите целое число m (от 0 до 1023): ");
    if (scanf_s("%d", &m) != 1 || m < 0 || m > 1023) {
        printf_s("Ошибка: введите целое число от 0 до 1023.\n");
        return 1;
    }

    printf_s("\nСтепени двойки до m = %d:\n", m);

    value = 1.0;

    for (int i = 0; i <= m; i++) {
        printf_s("%4d^%d = %20.0f\n", 2, i, value);
        value *= 2.0;
    }

    value /= 2.0;
    printf_s("\nРезультат: %.1fK\n\n\n\n", value / 1024.0);

    return 0;
}

int Work2Tabu()
{
    double start = 1.0;
    double end = 3.0;
    double step;
    double x, y;
	puts("Задание 2\n");
    printf_s("Функция для вычисления: y = x^2 - cos^2(pi * x)\n");
    printf_s("Введите шаг табуляции: ");
    scanf_s("%lf", &step);

    if (step <= 0) {
        printf_s("Ошибка: шаг должен быть положительным числом.\n");
        return 1;
    }

    printf_s("\n---------------------\n");
    printf_s("|   x   |   f(x)    |\n");
    printf_s("---------------------\n");

    for (x = start; x <= end + (step / 2); x += step) {
        // Вычисляем значение функции
        // cos(M_PI * x) возводится в квадрат
        y = pow(x, 2) - pow(cos(M_PI * x), 2);

        printf_s("| %5.2f | %9.4f |\n", x, y);
    }

    printf_s("---------------------\n\n\n\n");

    return 0;
}

int HomeWork()
{
        int N;
        double prod = 1.0;
		puts("Домашнее задание\n");
        printf_s("Введите целое число N: ");
        scanf_s("%d", &N);

        for (double i = 1.1; i <= N; i += 0.1) {
            prod *= i;
        }

        printf_s("Произведение: %lf\n", prod);
        return 0;
}