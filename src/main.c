#include <stdio.h>
#include "report.h"

int main()
{

    int grades[6] = {0};
    int size = sizeof(grades) / sizeof(grades[0]);

    char input[100];
    char extra;

    printf("\n=== Student Grade Tracker ===\n");
    printf("Please enter %d grades.\n\n", size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter grade %d: ", i + 1);

        while (1)
        {
            // fgets returns NULL if input runs out (e.g. Ctrl+D or piped input ends).
            // Without this check, the old leftover text in `input` would get re-read
            // forever, causing repeated/stuck grades or an infinite loop.
            if (fgets(input, sizeof(input), stdin) == NULL)
            {
                printf("\nInput ended unexpectedly. Exiting.\n");
                return 1;
            }

            // Look inside input. Try to find an integer (%d) and a character (%c). Put the integer into grades[i]
            // and the character into extra. The %d is first so if only int, then its equal to 1.

            if (sscanf(input, "%d %c", &grades[i], &extra) == 1)
                break;

            printf("Only integers are allowed, enter a proper grade: ");
        }
    }

    print_report(grades, size);

    return 0;
}