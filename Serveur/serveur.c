/** Fichier serveur.c **/
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "../Communication/libcom.h"
#include "../Threads/libthrd.h"

/***********************************************************/
/** Serveur pour le serveur                               **/
/***********************************************************/

/** Fichiers d'inclusion **/

/** Constantes **/
boucleServeur
/** Variables publiques **/
extern char *optarg;
extern int optind, opterr, optopt;

/** Variables statiques **/

/** Procedure principale **/

int gestionClient(int s)
{
	/* Obtient une structure de fichier */
	FILE *dialogue=fdopen(s,"a+");
	if(dialogue==NULL){ perror("gestionClient.fdopen"); exit(EXIT_FAILURE); }

	/* Echo */
	//char ligne[6] = "couco\n";
	//while(fgets(ligne,6,dialogue)!=NULL)
    	fprintf(dialogue,"> coucou\n");

	/* Termine la connexion */
	fclose(dialogue);
	return 0;
}

char *analyseArguments(int argc,char *argv[])
{
    static struct option opt = {"port", 1, 0, 'p'};
    if(getopt_long(argc, argv, "p:", &opt, NULL) == 'p') return optarg; //aqpaq
    else return "80";
}

int main(int argc,char *argv[])
{
	int s;
	 
	/* Lecture des arguments de la commande */
	//analyseArguments(argc,argv);
	char *service = analyseArguments(argc,argv);
    printf("%s\n", service);
    
	/* Initialisation du serveur */
	s=initialisationServeur(service);
	   
	/* Lancement de la boucle d'ecoute */
	boucleServeur(s,gestionClient);
    lanceThread(getionClient, s, 50);
}
