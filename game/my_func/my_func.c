#include "my_func.h"

void my_error(char *str)
{
    perror(str);
    exit(EXIT_FAILURE);
}

int my_random(int min, int max)
{
    static int i = 0;
    if (i == 0)
        srand(time(NULL));
    i++;

    return rand() % (max - min + 1) + min;
}

// size是数组元素个数，num是每行有几个
void my_array_print(int a[], int size, int num)
{
    int flag = 0;
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
        flag = (flag + 1) % num;
        if (flag == 0)
            printf("\n");
    }
}

bool is_in_range(int a, int min, int max)
{
    return (a >= min) && (a <= max);
}

int my_getn(int min, int max)
{
    char s[2] = {0};
    char c;
    while (1) {
        int j = 0;
        while ((c = getchar()) != '\n') {
            s[j] = c;
            if (j == 0)
                j++;
        }

        int num = s[0] - '0';
        if (s[0] == '\0')
            printf("please input one num\n");
        else if (s[1] != '\0') {
            printf("please input only one num\n");
            // for (int i = 0; i < 2; i++)     // 卧槽，这句注释掉会出现输入一个字符也会进入这里的情况，太神奇了!
            //     printf("%d: %d\n", i, s[i]);
        }
        else if (num < min || num > max)
            printf("please input one num from %d to %d\n", min, max);
        else
            return num;

        memset(s, 0, 2);
    }
}
