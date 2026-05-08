#include "virtual_os.h"

static Gantt gantt[MAX_GANTT];
static int count = 0;

void add_gantt(int pid, int start, int end)
{
    gantt[count].pid = pid;
    gantt[count].start = start;
    gantt[count].end = end;
    count++;
}

void print_gantt(void)
{
    int i = 0;
    printf("\nGantt Chart:\n");
    while (i < count)
    {
        printf("| P%d ", gantt[i].pid);
        i++;
    }
    printf("|\n");
    i = 0;
    while (i < count)
    {
        printf("%d    ", gantt[i].start);
        i++;
    }
    printf("%d\n", gantt[count - 1].end);
}

void reset_gantt(void)
{
    count = 0;
}
