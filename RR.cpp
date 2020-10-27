#include "structures.h"
#include "Fonctions.h"
#include<stdio.h>
process* choose_RR_Process (processList* L)
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
	
	if(selectedprocess == NULL){
	  return NULL;	
	}
	
	for(int i=0; i < L->process_nbr; i++ )
	{
		if (L->allProcess[i].process_status == READY)
			selectedprocess = L->allProcess+i;
			//break;
	}
	
	
	return selectedprocess;
}
void start_RR_processor (processList* L)
{
	int clock = 0;
	process* runningprocess = NULL;
	RR_element* liste_element = NULL;
	while(!is_all_process_end (L))
	{
		update_all_ready_process(L , clock);
		RR_element *nv=(RR_element*)malloc(sizeof(RR_element));
		if( runningprocess != choose_RR_Process(L))
		{
			nv->liste = choose_RR_Process(L);
			if(liste_element==NULL){
				nv->next=nv;
				liste_element=nv;
			}else{
				nv->next=liste_element;
				liste_element=nv;
			}
			L->context_chges_nbr++;
			runningprocess = liste_element->liste;
			
			}/*else{
			do{
				runningprocess = choose_RR_Process(L);
			}while(choose_RR_Process(L)!=runningprocess);
			nv->liste = runningprocess;
			if(liste_element==NULL){
				nv->next=nv;
				liste_element=nv;
			}else{
				nv->next=liste_element;
				liste_element=nv;
			}
			L->context_chges_nbr++;
			runningprocess = liste_element->liste;
		}*/
		
				
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
				RR_element *tmp1,*tmp2;
				tmp1=liste_element;
				if(tmp1->liste == runningprocess){
					liste_element = tmp1->next;
					free(tmp1);
				}else{
					tmp2=tmp1->next;
					while(tmp2!=tmp1){
						if(tmp2->liste == runningprocess){
							tmp1->next = tmp2->next;
							free(tmp2);
						}
						tmp1 = tmp2 ;
						tmp2 = tmp2->next ;
					}
				}
			}
		/*	do{
				liste_element=liste_element->next;
			}while(liste_element->liste==runningprocess);
			if((process*)liste_element->next==runningprocess){
				do{
					liste_element = liste_element->next;
				}while(liste_element->liste==runningprocess);
				runningprocess = liste_element->liste;
			}else{
				runningprocess = (process*)liste_element->liste;
			}*/
			runningprocess = (process*)liste_element->next;
		}
		else
		{
			clock++;
		}
	}
}
