// Statistic Methods

// Static sum
static double sum(int grades[], int count)
{
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += grades[i];
    }
    return sum;
}

// Average

double average(int grades[], int count)
{
    return sum(grades, count) / count;
}

// Lowest
double lowest(int grades[], int count)
{
    double lowest = grades[0];
    for (int i = 0; i < count; i++)
    {
        if (grades[i] < lowest)
            lowest = grades[i];
    }
    return lowest;
}

// Highest
double highest(int grades[], int count)
{
    double highest = grades[0];
    for (int i = 0; i < count; i++)
    {
        if (grades[i] > highest)
            highest = grades[i];
    }
    return highest;
}