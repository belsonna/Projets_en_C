#include"bibliotheque.h"

typedef struct
{
    int id,nb_heure; //indentifiant et capacité
    char intitule[20],code_matiere[8];
}Tmatiere;
FILE *f;
Tmatiere tabM[20];
int nbrM=0;
char *fichierM="fichier_matiere.txt";
void saveM(void);
int contro_nbrM(void);
void listeM(void);
void supprimM(void);
void modifM(void);
void salle_lib(void);
int choix_menu_M(void);
void menu_M();

void saveM()
{
    int n,i;
    Tmatiere M ;

    if((f=fopen(fichierM,"a+"))==NULL)
    {
        printf("Impossible d'ouvrir le fichier %s",fichierM);
        exit(1);
    }
    else
    {
           nbrM=contro_nbrM();
           printf("nbS=%d\n",nbrM);
           printf("Entrez le nombre de classe %c enregistrer: \n",160);
           scanf("%d",&n);

           printf("Entregistrement.....\n");

            for (i=0;i<n;i++)
            {
                M.id= nbrM+1;
                printf("Code de matiere:\t");
                scanf("%s",M.code_matiere);
                printf("Intitul%c:\t",130);
                scanf("%s",M.intitule);
                printf("Nombre d\'heure:\t",130);
                scanf("%d",&M.nb_heure);
                fprintf(f,"%2d\t %15s\t%15s\t%2d",M.id,M.code_matiere,M.intitule,M.nb_heure);
                fprintf(f,"\n");
                nbrM++;
            }
            printf("FIN...\n");
            fclose(f);

        }
}
void modifM(void)
{
    printf("la fonction n'est pas implement%ce",130);
}


int contro_nbrM(void)
{
    int n=0;
    Tmatiere M;
   //printf("ici.......");
    while ((nb=fgets (ch,256,f))!=NULL)
    {
        sscanf(ch, "%d %s %s %d",&M.id,M.code_matiere,M.intitule,&M.nb_heure);
       // printf("%d",n);
        n++;
    }
    return n;
}


void listeM()
{

    int i=0,j;
     if((f=fopen(fichierM,"r"))==NULL)
    {
        printf("Impossible d'ouvrir le fichier %s",fichierM);
        exit(1);
    }
    else
    {
         while ((nb=fgets (ch,256,f))!=NULL)
        {
            sscanf(ch, "%d %s %s %d",&tabM[i].id,tabM[i].code_matiere,tabM[i].intitule,&tabM[i].nb_heure);
            i++;

        }
         printf("\n------Listes des salles de Matieres---------\n\n");

        printf("___________________________________________\n");
        printf("id| Code  \t  |Intitul%c\t  |nb heurs                  |\n",130);
        printf("__|_______________|_______________|________|\n");
        for (j=0; j<i; j++)
        {
            printf("%2d|%-15s|%-15s|\t %2d|",tabM[j].id,tabM[j].code_matiere,tabM[j].intitule,tabM[j].nb_heure);
            printf("\n");
        }
        printf("__|_______________|_______________|________|\n");
    }
    fclose(f);
    getchar();
}

void supprimM()
{
    int idsup,i=0,j;
    listeM();
    printf("\nEntrez l'id de la classe %c supprimer",160);
    scanf("%d",&idsup);
     if((f=fopen(fichierM,"r"))==NULL)
    {
        printf("Impossible d'ouvrir le fichier %s",fichierM);
        exit(1);
    }
    else
    {
         while ((nb=fgets (ch,256,f))!=NULL)
        {
            sscanf(ch, "%d %s %s %d",&tabM[i].id,tabM[i].code_matiere,tabM[i].intitule,&tabM[i].nb_heure);
            i++;
        }
        fclose(f);
        if((f=fopen(fichierM,"w+"))==NULL)
        {
            printf("Impossible d'ouvrir le fichier %s",fichierM);
            exit(1);
        }
        else
        {

           for (j=0; j<i; j++)
            {
               // printf("id=%d",tabS[j].id);
                if (tabM[j].id==idsup)
                    j++;
                fprintf(f,"%2d\t %-15s\t%-15s\t%2d",tabM[j].id,tabM[j].code_matiere,tabM[j].intitule,tabM[j].nb_heure);
                 fprintf(f,"\n");
            }

        }
    }
    fclose(f);
}
