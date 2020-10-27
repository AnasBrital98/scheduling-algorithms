#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RUNNING 0
#define READY 1
#define BLOCKED 2
#define ZOMBIE 3

typedef struct process{
	
	char process_name;
	int exec_time;
	int arrival_date;
	int priorite;
	
	int real_exec_time;
	int process_status;
	int end_date;
} process;

typedef struct processList{
	
	process* allProcess;
	int process_nbr;
	
	char exec_string[100];
	int context_chges_nbr;
} processList;

typedef struct RR{
	 process* liste;
	struct RR *next;
}RR_element;
#endif
