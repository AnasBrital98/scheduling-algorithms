# Scheduling Algorithms

This Repository Contains The Implementation Of Scheduling Algorithms in C Programming Language .


### First Come First Served (FCFS):

```c
void start_FCFS_processor (processList* L)
{
	int clock = 0;
	process* runningprocess = NULL;
	
	while(!is_all_process_end (L))
	{
		update_all_ready_process(L , clock);
		
		if( runningprocess != choose_FCFS_Process (L))
		{
			L->context_chges_nbr++;
			runningprocess = choose_FCFS_Process (L);
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
```

### Shortest Job First (SJF):

```c
void start_SPF_processor (processList* L)
{
	int clock = 0;
    process* runningprocess = NULL;
	while(!is_all_process_end (L))
	{
		update_all_ready_process(L , clock);
		if( runningprocess != choose_SPF_Process(L))
		{
			if(runningprocess){
				if(runningprocess->process_status==ZOMBIE){
							L->context_chges_nbr++;
			                runningprocess = choose_SPF_Process(L);
			     }
			}else{
                            L->context_chges_nbr++;
			                runningprocess = choose_SPF_Process(L);			     	
			}
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
```

### Shortest Remaining Time (SRT):

```c
void start_SRT_processor (processList* L)
{
	int clock = 0;
	process* runningprocess = NULL;
	
	while(!is_all_process_end (L))
	{
		update_all_ready_process(L , clock);
		
		if( runningprocess != choose_SRT_Process(L))
		{
			L->context_chges_nbr++;
			runningprocess = choose_SRT_Process(L);
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
```
### Round Robin :

```c
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
```
### Priority Scheduling :

```c
void start_PRIO_processor (processList* L)
{
	int clock = 0;
	process* runningprocess = NULL;
	
	while(!is_all_process_end (L))
	{
		update_all_ready_process(L , clock);
		
		if( runningprocess != choose_PRIO_Process(L))
		{
			L->context_chges_nbr++;
			runningprocess = choose_PRIO_Process(L);
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
```
### Multi-Level Queue Scheduling :

Not Implemented Yet .
```c

```

