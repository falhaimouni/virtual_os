#include "virtual_os.h"

void calculate_metrics(PCB *p, int n)
{
    int i = 0;

    while (i < n)
    {
        p[i].turnaround_time =
            p[i].completion_time - p[i].arrival_time;

        p[i].waiting_time =
            p[i].turnaround_time - p[i].burst_time;
        i++;
    }
}

void print_metrics(PCB *p, int n)
{
    int i = 0;
    float avg_wt = 0;
    float avg_tat = 0;
    float avg_ct = 0;

    printf("\nMetrics:\n");

    while (i < n)
    {
        printf("P%d CT=%d TAT=%d WT=%d\n",
            p[i].pid,
            p[i].completion_time,
            p[i].turnaround_time,
            p[i].waiting_time);

        avg_wt += p[i].waiting_time;
        avg_tat += p[i].turnaround_time;
        avg_ct += p[i].completion_time;
        i++;
    }

    printf("\nAverage WT = %.2f\n", (avg_wt / n));
    printf("Average TAT = %.2f\n", (avg_tat / n));
    printf("Average CT = %.2f\n", (avg_ct / n));
}
