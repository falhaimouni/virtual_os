#include "virtual_os.h"

//non-preemption
void fcfs(PCB *p, int n)
{
    int time = 0;
    int i = 0;

    reset_gantt();

    while (i < n)
    {
        if (time < p[i].arrival_time)
            time = p[i].arrival_time;
        add_gantt(p[i].pid, time, time + p[i].burst_time);
        time += p[i].burst_time;
        p[i].completion_time = time;
        i++;
    }

    calculate_metrics(p, n);
}


void sjf(PCB *p, int n)
{
    int completed = 0;
    int time = 0;
    int shortest;
    int i;

    reset_gantt();

    while (completed < n)
    {
        shortest = -1;
        i = 0;

        while (i < n)
        {
            if (p[i].arrival_time <= time
                && p[i].remaining_time > 0)
            {
                if (shortest == -1
                    || p[i].burst_time < p[shortest].burst_time)
                    shortest = i;
            }
            i++;
        }

        if (shortest == -1)
        {
            time++;
            continue;
        }
        add_gantt(shortest + 1,
            time,
            time + p[shortest].burst_time);

        time += p[shortest].burst_time;
        p[shortest].remaining_time = 0;
        p[shortest].completion_time = time;

        completed++;
    }

    calculate_metrics(p, n);
}

void srtf(PCB *p, int n)
{
    int completed = 0;
    int time = 0;
    int shortest;
    int i;

    reset_gantt();

    while (completed < n)
    {
        shortest = -1;
        i = 0;

        while (i < n)
        {
            if (p[i].arrival_time <= time
                && p[i].remaining_time > 0)
            {
                if (shortest == -1
                    || p[i].remaining_time <=
                    p[shortest].remaining_time)
                    shortest = i;
            }
            i++;
        }

        if (shortest == -1)
        {
            time++;
            continue;
        }

        if (!p[shortest].started)
            p[shortest].started = 1;

        add_gantt(p[shortest].pid, time, time + 1);

        p[shortest].remaining_time--;
        time++;

        if (p[shortest].remaining_time == 0)
        {
            p[shortest].completion_time = time;
            completed++;
        }
    }

    calculate_metrics(p, n);
}


void round_robin(PCB *p, int n, int quantum)
{
    int time = 0;
    int completed = 0;
    int i;

    reset_gantt();

    while (completed < n)
    {
        i = 0;

        while (i < n)
        {
            if (p[i].remaining_time > 0
                && p[i].arrival_time <= time)
            {
                if (!p[i].started)
                    p[i].started = 1;

                if (p[i].remaining_time > quantum)
                {
                    add_gantt(p[i].pid,
                        time,
                        time + quantum);

                    p[i].remaining_time -= quantum;
                    time += quantum;
                }
                else
                {
                    add_gantt(p[i].pid,
                        time,
                        time + p[i].remaining_time);

                    time += p[i].remaining_time;
                    p[i].remaining_time = 0;
                    p[i].completion_time = time;
                    completed++;
                }
            }
            i++;
        }
    }

    calculate_metrics(p, n);
}


void priority_schedule(PCB *p, int n)
{
    int completed = 0;
    int time = 0;
    int highest;
    int i;

    reset_gantt();

    while (completed < n)
    {
        highest = -1;
        i = 0;

        while (i < n)
        {
            if (p[i].arrival_time <= time
                && p[i].remaining_time > 0)
            {
                if (highest == -1
                    || p[i].priority < p[highest].priority)
                    highest = i;
            }
            i++;
        }

        if (highest == -1)
        {
            time++;
            continue;
        }
        add_gantt(p[highest].pid,
            time,
            time + p[highest].burst_time);

        time += p[highest].burst_time;
        p[highest].remaining_time = 0;
        p[highest].completion_time = time;

        completed++;
    }

    calculate_metrics(p, n);
}

