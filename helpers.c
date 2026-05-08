#include "virtual_os.h"

void init_processes(PCB *p, int n)
{
    int i = 0;

    while (i < n)
    {
        p[i].remaining_time = p[i].burst_time;
        p[i].state = NEW;
        p[i].completion_time = 0;
        p[i].turnaround_time = 0;
        p[i].waiting_time = 0;
        p[i].started = 0;
        i++;
    }
}

void reset_processes(PCB *p, PCB *processes, int n)
{
    int i = 0;

    while (i < n)
    {
        p[i] = processes[i];
        i++;
    }
    init_processes(p, n);
}

void print_processes(PCB *p, int n)
{
    int i = 0;

    printf("\nProcesses:\n");
    while (i < n)
    {
        printf("P%d AT=%d BT=%d PR=%d\n",
            p[i].pid,
            p[i].arrival_time,
            p[i].burst_time,
            p[i].priority);
        i++;
    }
}
