# include <stdio.h>
# include <string.h>

int main(int argc, char const *argv[])
{
    int array[10];
    array[0] = 1;
    array[1] = 1;
    array[2] = 1;
    memmove(array + 3, array, sizeof(int) * 3);

    for (int i = 0; i < 10;i++){
        printf("%d\n", array[i]);
    }
        
    return 0;
}
