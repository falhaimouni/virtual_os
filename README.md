# Virtual OS - CPU Scheduling Simulator

A C-based command-line simulator that implements and demonstrates various CPU scheduling algorithms commonly studied in operating systems courses.

## Overview

This project simulates a process scheduler that allows users to test different scheduling algorithms on a set of processes. Each process has an arrival time, burst time, and priority level. The simulator generates Gantt charts and calculates performance metrics for each algorithm.

## Features

- **5 Scheduling Algorithms:**
  - **FCFS (First Come First Served)**: Non-preemptive, processes execute in arrival order
  - **SJF (Shortest Job First)**: Non-preemptive, shortest burst time first
  - **SRTF (Shortest Remaining Time First)**: Preemptive, shortest remaining time first
  - **Round Robin**: Preemptive, time quantum-based scheduling
  - **Priority Scheduling**: Non-preemptive, based on priority value

- **Performance Metrics:**
  - Completion Time (CT)
  - Turnaround Time (TAT)
  - Waiting Time (WT)
  - Averages for all metrics

- **Gantt Chart Visualization**: Visual representation of process execution timeline

## Building

### Prerequisites
- GCC compiler
- Make utility
- Standard C library

### Compilation

```bash
make
```

This generates the `virtual_os` executable.

To clean object files:
```bash
make clean
```

To rebuild from scratch:
```bash
make re
```

## Usage

### Command Format

```bash
./virtual_os "pid,arrival,burst,priority" ["pid,arrival,burst,priority"] ...
```

### Parameters

- **pid**: Process ID (integer)
- **arrival**: Arrival time (integer)
- **burst**: CPU burst time (integer)
- **priority**: Priority level (integer, lower value = higher priority)

### Example

```bash
./virtual_os "1,0,5,2" "2,1,3,1" "3,2,8,3" "4,3,6,2"
```

This creates 4 processes:
- Process 1: arrives at 0, burst 5, priority 2
- Process 2: arrives at 1, burst 3, priority 1
- Process 3: arrives at 2, burst 8, priority 3
- Process 4: arrives at 3, burst 6, priority 2

### Interactive Menu

After providing processes, you'll see:
```
1.FCFS
2.SJF
3.SRTF
4.Round Robin
5.Priority
0.Exit
Choice: 
```

Select an algorithm (1-5) to run it with your processes. For Round Robin, you'll be prompted to enter a quantum time value.

## Output

For each algorithm, the program displays:

1. **Gantt Chart**: Visual timeline of process execution
2. **Metrics Table**: Individual process metrics
3. **Averages**: Average CT, TAT, and WT across all processes

Example output:
```
Gantt Chart:
| P1 | P2 | P1 | P3 |
0    5    8    11   17

Metrics:
P1 CT=11 TAT=11 WT=6
P2 CT=8 TAT=7 WT=4
P3 CT=17 TAT=15 WT=7

Average WT = 5.67
Average TAT = 11.00
Average CT = 12.00
```

## Project Structure

```
virtual_os/
├── main.c              # Entry point and command-line parsing
├── helpers.c           # Process initialization and utility functions
├── schedual_algo.c     # Scheduling algorithm implementations
├── metrics.c           # Performance metrics calculation
├── gantt.c             # Gantt chart management
├── virtual_os.h        # Header file with data structures
├── Makefile            # Build configuration
└── README.md           # This file
```

## Data Structures

### PCB (Process Control Block)
```c
typedef struct s_pcb
{
    int pid;                // Process ID
    int arrival_time;       // Time when process arrives
    int burst_time;         // Total CPU time required
    int remaining_time;     // Remaining CPU time
    int priority;           // Priority level
    process_state state;    // Current state
    int completion_time;    // Time when process completes
    int turnaround_time;    // Completion - Arrival time
    int waiting_time;       // Turnaround - Burst time
    int started;            // Flag indicating if started
} PCB;
```

## Scheduling Formulas

- **Turnaround Time**: Completion Time - Arrival Time
- **Waiting Time**: Turnaround Time - Burst Time

## Notes

- All algorithms process ready processes in the order they appear in the input list when there are ties
- The simulator handles idle CPU time (when no process has arrived yet)
- Each scheduling run resets process state but retains the original process definitions
- You can test multiple algorithms on the same set of processes without re-entering them

## License

This project is provided as-is for educational purposes.

## Author

Created as an operating systems education project demonstrating CPU scheduling concepts.
