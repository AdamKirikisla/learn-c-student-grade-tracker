#include <stdio.h>
#include "stats.h"
#include "report.h"

static void print_line(void)
{
    printf("==========================\n");
}

void print_report(int grades[], int count)
{
    printf("\n\n");
    print_line();
    printf("    GRADE REPORT\n");
    print_line();
    printf("    AVERAGE  : %.2lf\n", average(grades, count));
    printf("    Highest  : %d\n", highest(grades, count));
    printf("    Lowest   : %d\n", lowest(grades, count));
    print_line();
    printf("\n\n");
}