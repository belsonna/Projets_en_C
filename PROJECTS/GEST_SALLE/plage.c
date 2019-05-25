#include"bibliotheque.h"
typedef struct
{
    int id; //indentifiant et capacité
    char debut[20];
    char fin[20];
}Tplage;
typedef struct
{
    int id_pg,ids,idpl;
    char salle[20],Ens[20],Matiere[20],Plage[12];

    Tdate date;
}Tprog;

FILE *fpg;
Tprog tabP[20];
FILE *f;
Tplage tabPL[20];
int nbrPL=0;
char *fichierPL="fichier_plage.txt";
void savePL(void);
int contro_nbrPL(void);
void listePL(void);
void supprimPL(void);
void modifPL(void);
void salle_lib(void);
int choix_menu_PL(void);
void menu_PL();

void savePL(void)
{
    int n,i;
    Tplage P ;

    if((f=fopen(fichierPL,"a+"))==NULL)
    {
        printf("Impossible d'ouvrir le fichier %s",fichierPL);
        exit(1);
    }
    else
    {
           nbrPL=contro_nbrPL();
           printf("nbS=%d\n",nbrPL);
           printf("Entrez le nombre de plage %c enregistrer: \n",160);
           scanf("%d",&n);

           printf("Entregistrement.....\n");

            for (i=0;i<n;i++)
            {
                P.id= nbrPL+1;

                printf("debut:\t");
                scanf("%s",P.debut);
                printf("fin:\t");
                scanf("%s",P.fin);

                fprintf(f,"%2d\t  %15s\t%15s\t",P.id,P.debut,P.fin);
                fprintf(f,"\n");
                nbrPL++;
            }
            printf("FIN...\n");
            fclose(f);

        }

}
void modifPL(void)
{
    printf("la fonction n'est pas implement%ce",130);
}


int contro_nbrPL(void)
{
    int n=0;
    int idpl=0;
    Tplage P;
    while ((nb=fgets (ch,256,f))!=NULL)
    {
        sscanf(ch, "%d %s %s ",&P.id,P.debut,P.fin);
        n++;
    }
    if (n==0)
        idpl=0;
    else
        idpl=P.id;

    return idpl;
}


void listePL()
{

    int i=0,j;
     if((f=fopen(fichierPL,"r"))==NULL)
    {
        printf("Impossible d'ouvrir le fichier %s",fichierPL);
        exit(1);
    }
    else
    {
         while ((nb=fgets (ch,256,f))!=NULL)
        {
            sscanf(ch, "%d %s %s ",&tabPL[i].id,tabPL[i].debut,tabPL[i].fin);
            i++;

        }

        printf("\n---------Listes des salles des plage------------\n\n\n");
          printf("_______________________________________\n");
        printf("id|\tDebut plage |\t      Fin plage|\n");
         printf("__|_________________|__________________|\n");
        for (j=0; j<i; j++)
        {
            printf("%2d|  %15s|\t%15s|",tabPL[j].id,tabPL[j].debut,tabPL[j].fin);
            printf("\n");
        }
         printf("__|_________________|__________________|\n");
    }
    fclose(f);
    getchar();
}

void supprimPL()
{
    int idsup,i=0,j;
    printf("Entrez l'id de la classe %c supprimer",160);
    scanf("%d",&idsup);
     if((f=fopen(fichierPL,"r"))==NULL)
    {
        printf("Impossible d'ouvrir le fichier %s",fichierPL);
        exit(1);
    }
    else
    {
         while ((nb=fgets (ch,256,f))!=NULL)
        {
            sscanf(ch, "%d %s %s ",&tabPL[i].id,tabPL[i].debut,tabPL[i].fin);
            i++;

        }
        fclose(f);
        if((f=fopen(fichierPL,"w+"))==NULL)
        {
            printf("Impossible d'ouvrir le fichier %s",fichierPL);
            exit(1);
        }
        else
        {

           for (j=0; j<i; j++)
            {
               // printf("id=%d",tabS[j].id);
                if (tabPL[j].id==idsup)
                    j++;
                fprintf(f,"%2d\t %15s\t%15s",tabPL[j].id,tabPL[j].debut,tabPL[j].fin);
                 fprintf(f,"\n");
            }
        }
    }
    fclose(f);
}

void verifPlage(int s,int p,Tdate d)
{
    int l=0,c=0,  trover=0;

    printf("s=%d\n",s);
     if((fpg=fopen("fichier_programs.txt","r"))==NULL)
    {
        printf("Impossible d'ouvrir le fichier \"fichier_programs.txt\"");
        exit(1);
    }
    else
    {
         while ((nb=fgets (ch,256,fpg))!=NULL)
            {
               sscanf(ch,"%d  %d %s %s %s  %d %s %d %d %d",&tabP[l].id_pg,&tabP[l].ids,tabP[l].salle,tabP[l].Ens,tabP[l].Matiere,&tabP[l].idpl,tabP[l].Plage,&tabP[l].date.jr,&tabP[l].date.ms,&tabP[l].date.an);
                l++;
            }

        while(c<l  &&   trover==0)
            {
                if ((tabP[c].ids==s) && (tabP[c].idpl==p) && (tabP[c].date.jr==d.jr )&& (tabP[c].date.ms==d.ms )&& (tabP[c].date.an==d.an))
                    trover=1;
                c++;
            }
          //  printf("id salle =%d",tabP[c].ids);

        if (trover==1)
            printf("\nla salle %s est programm%ce le %d/%d/%d %c %s pour la matiere %s \n", tabP[c-1].salle,130,tabP[c-1].date.jr,tabP[c-1].date.ms,tabP[c-1].date.an,160,tabP[c-1].Plage,tabP[c-1].Matiere);
        else
           printf("la salle %s est libre  le %d/%d/%d dans la plage %s \n\n ", tabP[c-1].salle,d.jr,d.ms,d.an,tabP[c-1].Plage);

    }
}

void plage_lib()
{
    Tdate d;
   int s,p;
    gotoxy(8,16);printf("Pour quelle date ?:");
    gotoxy(8,18);printf("le __/__/____");
    gotoxy(11,18);scanf("%d",&d.jr);
    gotoxy(14,18);scanf("%d",&d.ms);
    gotoxy(17,18);scanf("%d",&d.an);

    listeS();
     printf("\n\nPour quelle salle?:\t");
    scanf("%d",&s);
    printf("\n\n");
    listePL();
    printf("\nPour quelle plage?:\t");
    scanf("%d",&p);
//    putc(s);

    verifPlage(s,p,d);
    system("PAUSE");
}
