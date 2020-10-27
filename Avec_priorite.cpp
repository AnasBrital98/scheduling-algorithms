#include "structures.h"
#include "Fonctions.h"
process* choose_Priorite_Process (processList* L)
{
	process* selectedprocess = NULL;
	
	for(int i=0; i < L->process_nbr; i++ )
	{
		if(L->allProcess[i].process_status == READY)
		{
			selectedprocess = L->allProcess+i;
			break;
		}	
	}
	
	if(selectedprocess == NULL)
		return NULL;
	
	for(int i=0; i < L->process_nbr; i++ )
	{
		if (L->allProcess[i].process_status == READY && L->allProcess[i].priorite < selectedprocess->priorite && L->allProcess[i].arrival_date < selectedprocess->arrival_date)
			selectedprocess = L->allProcess+i;
	}
	
	
	return selectedprocess;
}

void start_Priorite_processor (processList* L)
{
	int clock = 0;
	process* runningprocess = NULL;
	
	while(!is_all_process_end (L))
	{
		update_all_ready_process(L , clock);
		
		if( runningprocess != choose_Priorite_Process(L))
		{
			L->context_chges_nbr++;
			runningprocess = choose_Priorite_Process(L);
		}
		
				
		if(runningprocess)
		{
			clock++;
			runningprocess->real_exec_time ++;
			runningprocess->process_status = RUNNING;
			
			L->exec_string[strlen(L->exec_string)+1] = '\0';
			L->exec_string[strlen(L->exec_string)] = runningprocess->process_name;
			
			
						
			if(runningprocess->real_exec_time == runningprocess->exec_time )
			{
				runningprocess->process_status = ZOMBIE;
				runningprocess->end_date = clock;
			}
		}
		else
		{
			clock++;
		}
	}
}
