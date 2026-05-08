#include "virtual_os.h"


int parse_process(char *arg, PCB *p)
{
    int i = 0;
    int start = 0;
    int values[4];
    int index = 0;
    char temp[20];
    int j;

    while (arg[i])
    {
        if(!isdigit(arg[i]) && arg[i] != ',' )
        {
            return 0;
        }
        if (arg[i] == ',' || arg[i + 1] == '\0')
        {
            j = 0;
            while (start < i || (arg[i + 1] == '\0' && start <= i))
                temp[j++] = arg[start++];
            temp[j] = '\0';
            values[index++] = atoi(temp);
            start++;
        }
        i++;
    }

    if (index != 4)
        return (0);

    p->pid = values[0];
    p->arrival_time = values[1];
    p->burst_time = values[2];
    p->priority = values[3];

    return (1);
}

int main(int argc, char **argv)
{
    PCB processes[MAX_PROCESS];
    PCB p[MAX_PROCESS];
    int n;
    int i;
    int choice;

    if (argc < 2)
    {
        printf("Usage: ./virtual_os \"pid,arrival,burst,priority\" ...\n");
        return (1);
    }
    n = argc - 1;
    i = 0;
    while (i < n)
    {
        if (!parse_process(argv[i + 1], &processes[i]))
        {
            printf("Invalid input: %s\n", argv[i + 1]);
            return (1);
        }
        i++;
    }

    while (1)
    {
        reset_processes(p, processes, n);
        printf("1.FCFS\n");
        printf("2.SJF\n");
        printf("3.SRTF\n");
        printf("4.Round Robin\n");
        printf("5.Priority\n");
        printf("0.Exit\n");
        printf("Choice: ");
        if(scanf("%d", &choice) != 1)
        {
            printf("choose the algorithm number.\n");
            break;
        }
        if (choice == 0)
            break;
        if (choice == 1)
            fcfs(p, n);
        else if (choice == 2)
            sjf(p, n);
        else if (choice == 3)
            srtf(p, n);
        else if (choice == 4)
        {
            int quantum = 0;
            printf("Put a Quantum time : ");
            if(scanf("%d", &quantum) != 1)
            {
                printf("put the quantum number.\n");
                break;
            }
            round_robin(p, n, quantum);
        }
        else if (choice == 5)
            priority_schedule(p, n);
        else
        {
            printf("Invalid choice\n");
            continue;
        }

        print_gantt();
        print_metrics(p, n);
    }

    return (0);
}
