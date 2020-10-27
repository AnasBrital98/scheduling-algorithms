#include "structures.h"
#include "Fonctions.h"
#include "FCFS.h"
#include "SRT.h"
#include "SPF.h"
#include "Priorite.h"
#include "RR.h"
#include "Avec_priorite.h"

int main(int argv,char* argc[]) 
{
	system("color 0A");
	processList list;
	/*printf("\n\nFCFS     :  \n");
	initprocessList(&list);
	start_FCFS_processor(&list);
	afficher(&list);
	printf("\n\nSRT      :   \n");
	initprocessList(&list);
	start_SRT_processor(&list);
	afficher(&list);
	printf("\n\nSPF      :    \n");
	initprocessList(&list);
	start_SPF_processor(&list);
	afficher(&list);
	printf("\n\nPlus prioriaire En Premiaire    :   \n");
	initprocessList(&list);
	start_PRIO_processor(&list);
	afficher(&list);
	printf("\n\nROUND ROBIN       :   \n");
	initprocessList(&list);
	start_RR_processor(&list);
	afficher(&list);*/
	int choix;
	bool sortie= false;
	do{
		printf(" 						Menu\n");
		printf("         1 - FCFS\n");
		printf("         2 - SRT\n");
		printf("         3 - SPF\n");
		printf("         4 - Plus prioritaire en premaire \n");
		printf("         5 - ROUND ROBIN \n");
		printf("         6 - Quiter\n");
		printf("Votre choix   :    ");
		scanf("%d",&choix);
		switch(choix){
			case 1 : //FCFS
			        initprocessList(&list);
				 	start_FCFS_processor(&list);
	                afficher(&list);
				break;
			case 2 : //SRT
			        initprocessList(&list);
			        start_SRT_processor(&list);
			        afficher(&list);
			    break;
			case 3 : //SPF
			    initprocessList(&list);
				start_SPF_processor(&list);
				afficher(&list);
				break;
			case 4 :
			    initprocessList(&list);
			    start_PRIO_processor(&list);
			    afficher(&list);
				break;
			case 5 :
				initprocessList(&list);
				start_RR_processor(&list);
				afficher(&list);
				break;
			case 6 :
				sortie=true;
				break;
			default : printf("Donnez un bonne choix \n");
		}
	}while(!sortie);
	return 0;
}
