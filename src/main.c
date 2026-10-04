#include <stdio.h>
#include "stats.h"

int main()
{

    int grades[6] = {0};
    int size = sizeof(grades) / sizeof(grades[0]);

    char input[100];
    char extra;

    for (int i = 0; i < size; i++)
    {
        printf("Enter grade %d: ", i + 1);

        while (1)
        {
            fgets(input, sizeof(input), stdin);

            // Look inside input. Try to find an integer (%d) and a character (%c). Put the integer into grades[i]
            // and the character into extra. The %d is first so if only int, then its equal to 1.

            if (sscanf(input, "%d %c", &grades[i], &extra) == 1)
                break;

            printf("Only integers are allowed, enter a proper grade: ");
        }
    }

    printf("Average: %.2lf\n", average(grades, size));
    printf("Lowest: %d\n", lowest(grades, size));
    printf("Highest: %d\n", highest(grades, size));

    return 0;
}