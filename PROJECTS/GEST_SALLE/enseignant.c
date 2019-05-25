#include"bibliotheque.h"
typedef struct
{
    int id; //indentifiant et capacité
    char nomEns[20],phone[20],email[20];
}Tenseignant;
FILE *f;
Tenseignant tabE[20];
int nbrE=0;
char *fichierE="fichier_enseignant.txt";
void saveE(void);
int contro_nbrE(void);
void listeE(void);
void supprimE(void);
void modifE(void);
int choix_menu_E(void);
void menu_E();

void saveE(void)
{
    int n,i;
    Tenseignant E;

    if((f=fopen(fichierE,"a+"))==NULL)
    {
        printf("Impossible d'ouvrir le fichier %s",fichierE);
        exit(1);
    }
    else
    {
           nbrE=contro_nbrE();
           printf("nbS=%d\n",nbrE);
           printf("Entrez le nombre d\'enseignant %c enregistrer: \n",160);
           scanf("%d",&n);

           printf("Entregistrement.....\n");

            for (i=0;i<n;i++)
            {
                E.id= nbrE+1;
                printf("nom de l\'enseignant:\t");
                scanf("%s",E.nomEns);
                printf("Contact t%cl%cphonique:\t",130,130);
                scanf("%s",E.phone);
                printf("Email:\t");
                scanf("%s",E.email);
                fprintf(f,"%2d\t %15s\t%15s\t%15s",E.id,E.nomEns,E.phone,E.email);
                fprintf(f,"\n");

                nbrE++;
            }
            printf("FIN...\n");
            fclose(f);
        }

}

void modifE(void)
{
    printf("la fonction n'est pas implement%ce",130);
}


int contro_nbrE(void)
{
    int n=0;
    int ide=0;
    Tenseignant E;

    while ((nb=fgets (ch,256,f))!=NULL)
    {
        sscanf(ch, "%d %s %s %s",&E.id,E.nomEns,E.phone,E.email);
        n++;
    }
    if (n==0)
        ide=0;
    else
        ide=E.id;

    return ide;
}


void listeE()
{
    int i=0,j;
     if((f=fopen(fichierE,"r"))==NULL)
    {
        printf("Impossible d'ouvrir le fichier %s",fichierE);
        exit(1);
    }
    else
    {
         while ((nb=fgets (ch,256,f))!=NULL)
        {
            sscanf(ch, "%d %s %s %s",&tabE[i].id,tabE[i].nomEns,tabE[i].phone,tabE[i].email);
            i++;
        }
        printf("---------Listes des salles des enseignants-------\n\n");
          printf("__________________________________________________\n");
        printf("id| Noms  \t  |telephone\t  |Email                    |\n");
          printf("__|_______________|_______________|_______________|\n");
        for (j=0; j<i; j++)
        {
            printf("%2d|%-15s|%-15s|%-15s|",tabE[j].id,tabE[j].nomEns,tabE[j].phone,tabE[j].email);
            printf("\n");
        }
      printf("__|_______________|_______________|_______________|\n");
    }
    fclose(f);
    getchar();
}


void supprimE()
{
    int idsup,i=0,j;
    listeE();
    printf("\n\n Entrez l'id de la classe %c supprimer",160);
    scanf("%d",&idsup);
     if((f=fopen(fichierE,"r"))==NULL)
    {
        printf("Impossible d'ouvrir le fichier %s",fichierE);
        exit(1);
    }
    else
    {
         while ((nb=fgets (ch,256,f))!=NULL)
        {
            sscanf(ch, "%d %s %s %s",&tabE[i].id,tabE[i].nomEns,tabE[i].phone,tabE[i].email);
            i++;

        }
        fclose(f);
        if((f=fopen(fichierE,"w+"))==NULL)
        {
            printf("Impossible d'ouvrir le fichier %s",fichierE);
            exit(1);
        }
        else
        {

           for (j=0; j<i; j++)
            {
                 if (tabE[j].id==idsup)
                    j++;
                fprintf(f,"%2d\t %15s\t%15s\t%15",tabE[j].id,tabE[j].nomEns,tabE[j].phone,tabE[j].email);
                fprintf(f,"\n");
            }

        }


    }
    fclose(f);
}


