#ifndef VIRTUAL_OS_H
# define VIRTUAL_OS_H

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h> 

# define MAX_PROCESS 100
# define MAX_GANTT 1000

typedef enum e_state
{
    NEW,
    READY,
    RUNNING,
    WAITING,
    TERMINATED
} process_state;

typedef struct s_pcb
{
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int priority;

    process_state state;

    int completion_time;
    int turnaround_time;
    int waiting_time;
    int started;
} PCB;

typedef struct s_gantt
{
    int pid;
    int start;
    int end;
} Gantt;

void    init_processes(PCB *p, int n);
void    reset_processes(PCB *p, PCB *processes, int n);
void    print_processes(PCB *p, int n);
void    fcfs(PCB *p, int n);
void    sjf(PCB *p, int n);
void    srtf(PCB *p, int n);
void    round_robin(PCB *p, int n, int quantum);
void    priority_schedule(PCB *p, int n);
void    calculate_metrics(PCB *p, int n);
void    print_metrics(PCB *p, int n);
void    add_gantt(int pid, int start, int end);
void    print_gantt(void);
void    reset_gantt(void);

#endif
