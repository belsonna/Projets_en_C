#include"bibliotheque.h"
//definition du type salle
typedef struct
{
    int id,capa,etat; //indentifiant et capacité
    char nom[20];
}Tsalle;

FILE *f;
Tsalle tabS[20];
int  idS,nbrS=0;
char *fichierS="fichier_salle.txt";


void saveS(void)
{
    int n,i;
    Tsalle S ;

    if((f=fopen(fichierS,"a+"))==NULL)
    {
        printf("Impossible d'ouvrir le fichier %s",fichierS);
        exit(1);
    }
    else
    {
          idS= contro_nbrS();
           printf("nbS=%d\n",nbrS);
            printf("Entrez le nombre de classe %c enregistrer: \n",160);
           scanf("%d",&n);
           printf("Entregistrement.....\n");

            for (i=0;i<n;i++)
            {
                S.id= idS+1;
                S.etat=1;
                printf("nom salle:\t");
                scanf("%s",S.nom);
                printf("Capacit%c:\t",130);
                scanf("%d",&S.capa);
                fprintf(f,"%2d\t %15s\t%4d\t%2d",S.id,S.nom,S.capa,S.etat);
                fprintf(f,"\n");
                nbrS++;
            }
            printf("Enregistrement termin%c...\n",130);
            fclose(f);
        }
}
void modifS(void)
{
    printf("la fonction n'est pas implement%ce",130);
}

void salle_lib(void)
{
    int i=0,j;

     if((f=fopen(fichierS,"r"))==NULL)
    {
        printf("Impossible d'ouvrir le fichier %s",fichierS);
        exit(1);
    }
    else
    {

         while ((nb=fgets (ch,256,f))!=NULL)
        {
            sscanf(ch, "%d %s %d %d",&tabS[i].id,tabS[i].nom,&tabS[i].capa,&tabS[i].etat);
            i++;
        }
         fclose(f);



        printf("Listes des salles non utilis%ces:\n",130);
        printf("id\t | Noms \t |Capacites |\n");
        for (j=0; j<i; j++)
        {
            if (tabS[j].etat==1)
            {
                  printf("%2d|\t%-15s|\t%-4d|",tabS[j].id,tabS[j].nom,tabS[j].capa);
                  printf("\n");
            }

        }

    }

    getchar();


}
int contro_nbrS(void)
{
    int id;
    nbrS=0;
    Tsalle S;
     while ((nb=fgets (ch,256,f))!=NULL)
    {
        sscanf(ch, "%d %s %d %d",&S.id,S.nom,&S.capa,&S.etat);
         nbrS++;
    }
    if(nbrS==1)
    {
        id=0;
    }
    id=S.id;
    return id;
}


void listeS()
{
    int i=0,j;

     if((f=fopen(fichierS,"r"))==NULL)
    {
        printf("Impossible d'ouvrir le fichier %s",fichierS);
        exit(1);
    }
    else
    {
         while ((nb=fgets (ch,256,f))!=NULL)
        {
            sscanf(ch, "%d %s %d %d",&tabS[i].id,tabS[i].nom,&tabS[i].capa,&tabS[i].etat);
            i++;
        }
        printf("\n------Listes des salles de cours----------------\n\n");
           printf("_______________________________\n");
        printf("id| Noms \t  |Capacites   |\n");
         printf("__|_______________|____________|\n");
        for (j=0; j<i; j++)
        {
            printf("%2d|%-15s|%-4d        |",tabS[j].id,tabS[j].nom,tabS[j].capa);
            printf("\n");
        }
        printf("__|_______________|____________|\n");
    }
    fclose(f);
    getchar();
}

void supprimS()
{
    int idsup,i=0,j;
    listeS();
    printf("Entrez l'id de la classe %c supprimer",160);
    scanf("%d",&idsup);
     if((f=fopen(fichierS,"r"))==NULL)
    {
        printf("Impossible d'ouvrir le fichier %s",fichierS);
        exit(1);
    }
    else
    {
         while ((nb=fgets (ch,256,f))!=NULL)
        {
            sscanf(ch, "%d %s %d %d",&tabS[i].id,tabS[i].nom,&tabS[i].capa,&tabS[i].etat);
            i++;

        }
        fclose(f);
        if((f=fopen(fichierS,"w+"))==NULL)
        {
            printf("Impossible d'ouvrir le fichier %s",fichierS);
            exit(1);
        }
        else
        {

           for (j=0; j<i; j++)
            {
                if (tabS[j].id==idsup)
                    j++;
                fprintf(f,"%2d\t %15s\t%4d\t%2d",tabS[j].id,tabS[j].nom,tabS[j].capa,tabS[j].etat);
                 fprintf(f,"\n");
            }

        }


    }
    fclose(f);
}


