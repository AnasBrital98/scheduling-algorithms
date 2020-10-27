#include "structures.h"
#include<string.h>

void initprocessList (processList* L)
{
	L->process_nbr = 5;
	L->context_chges_nbr = 0;
	L->allProcess = (process*) malloc(L->process_nbr * sizeof (process));
	
	for(int i=0; i < L->process_nbr; i++ )
	{
		L->allProcess[i].real_exec_time = 0;
		L->allProcess[i].process_status = -1;
		L->allProcess[i].end_date = -1;
	}
	
	L->allProcess[0].process_name='A'; L->allProcess[0].exec_time = 3; L->allProcess[0].arrival_date = 0;L->allProcess[0].priorite=1;
	L->allProcess[1].process_name='B'; L->allProcess[1].exec_time = 6; L->allProcess[1].arrival_date = 1;L->allProcess[1].priorite=2;
	L->allProcess[2].process_name='C'; L->allProcess[2].exec_time = 4; L->allProcess[2].arrival_date = 4;L->allProcess[2].priorite=5;
	L->allProcess[3].process_name='D'; L->allProcess[3].exec_time = 2; L->allProcess[3].arrival_date = 6;L->allProcess[3].priorite=4;
	L->allProcess[4].process_name='E'; L->allProcess[4].exec_time = 1; L->allProcess[4].arrival_date = 7;L->allProcess[4].priorite=3;
	strcpy(L->exec_string," ");
}


void update_all_ready_process(processList* L, int clock)
{
	for(int i=0; i < L->process_nbr; i++ )
	{
		if( L->allProcess[i].arrival_date <= clock && 
			L->allProcess[i].real_exec_time < L->allProcess[i].exec_time ) 
			{
				L->allProcess[i].process_status = READY;
			}
	}
}

int is_all_process_end (processList* L)
{
	for(int i=0; i < L->process_nbr; i++ )
	{
		if( L->allProcess[i].process_status != ZOMBIE ) 
		return 0;
	}
	return 1;
}


float TRM (processList* L)
{
	int s = 0;
	
	for(int i=0; i < L->process_nbr; i++ )
	{
		s += (L->allProcess[i].end_date - L->allProcess[i].arrival_date);
	}
	
	return s/(float)L->process_nbr;
}

float TAM (processList* L)
{
	int s = 0;
	
	for(int i=0; i < L->process_nbr; i++ )
	{
		s += (L->allProcess[i].end_date - L->allProcess[i].arrival_date - L->allProcess[i].exec_time );
	}
	
	return s/(float)L->process_nbr;
}


void afficher_allprocess(processList* L)
{
	for(int i=0; i < L->process_nbr; i++ )
	{
		printf("Process %c : \nD. execution = %d, arrivee = %d, execution reelle = %d, statut = %d, date fin = %d , Priorité = %d \n \n", 
		L->allProcess[i].process_name, L->allProcess[i].exec_time, 
		L->allProcess[i].arrival_date, L->allProcess[i].real_exec_time,
		L->allProcess[i].process_status, L->allProcess[i].end_date,L->allProcess[i].priorite);
	}
}

void afficher(processList* L)
{
	printf("Chaine d'execution = %s, Nombre de changement contexte = %d, \nTRM = %.1f, TAM = %.1f \n\n", 
	L->exec_string,  L->context_chges_nbr, TRM(L), TAM(L));
	
//	afficher_allprocess(L);
}
