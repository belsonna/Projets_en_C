#include"bibliotheque.h"
typedef struct
{
    int id_pg,ids,idpl;
    char salle[20],Ens[20],Matiere[20],Plage[12];

    Tdate date;
}Tprogram;

FILE *fpg;
Tprogram tabPg[20];
int nbrPg=0;
char *fichierPg="fichier_programs.txt";

int contro_nbrPg(void);
void listePg(void);
void supprimPg(void);
void modifPg(void);
int choix_menu_Pg(void);
void menu_Pg();
int n;

void modifPg(void)
{
    printf("la fonction n'est pas implement%ce",130);
}




void blocSalle()
{

    int j=0;
    int i=0;

    Tsalle s;
     if((f=fopen(fichierS,"r"))==NULL)
    {
        printf("Impossible d'ouvrir le fichier %s",fichierS);
        exit(1);
    }
    else
    {
         while ((nb=fgets (ch,256,f))!=NULL)
        {

                  sscanf(ch, "%d %s %d %d",&s.id,s.nom,&s.capa,&s.etat);
                      if(s.etat==1)
                  {
                      tabS[i].id=s.id;
                      strcpy(tabS[i].nom,s.nom);
                      tabS[i].capa=s.capa;
                      tabS[i].etat=s.etat;
                         i++;
                  }

        }

    }
    n=i;
    fclose(f);
    system("cls");
    printf("la liste des salles libre (s)");
    rectangleX (15,3,1,1,1,4);
    gotoxy(6,2);
    printf("Numero");
    gotoxy(19,2);
    printf("Nom");
    gotoxy(36,2);
    printf("Capacite");
    gotoxy(51,2);
    printf(" Etat");
    int k=0,m=0;


    for(j=0;j<n;j++)
        {
                gotoxy(3,5+m);printf("%d",j+1);
                gotoxy(20,5+m);printf("%s",tabS[j].nom);
                gotoxy(33,5+m);printf("%d",tabS[j].capa);
                gotoxy(48,5+m);printf("disponible");
                m=m+3;

        }

}
void blocEnseignant()
{

    int j;
    int i=0;

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

    }
    n=i;
    fclose(f);
    if (n==1)
         printf("la liste des Enseignant Vide (s)");
    else
    {
         printf("la liste des Enseignant (s)");

        rectangleX (15,3,1,1,1,4);
        gotoxy(6,2);
        printf("Numero");
        gotoxy(19,2);
        printf("Noms ");
        gotoxy(36,2);
        printf("Telephone");
        gotoxy(51,2);
        printf(" Email");
        gotoxy(64,2);
        int k,m=0;

    for (j=0;j<n;j++)
        {

            gotoxy(3,5+m);printf("%d",tabE[j].id);
            gotoxy(20,5+m);printf("%s",tabE[j].nomEns);
            gotoxy(33,5+m);printf("%s",tabE[j].phone);
            gotoxy(48,5+m);printf("%s",tabE[j].email);
            m=m+3;

        }

    }

}


void blocMatiere()
{

    int j;
    int i=0;

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
    }
    n=i;
    fclose(f);
     printf("la liste des Matiere (s)");

 if (n==1)
      printf("Liste vide");
  else
      {
            rectangleX (15,3,1,1,1,4);
            gotoxy(6,2);
            printf("Numero");
            gotoxy(19,2);
            printf("Code");
            gotoxy(36,2);
            printf("Intitules");
            gotoxy(51,2);
            printf(" Heurs");
            int k,m=0;

    for (j=0;j<n;j++)
        {

                gotoxy(3,5+m);printf("%d",tabM[j].id);
                gotoxy(20,5+m);printf("%s",tabM[j].code_matiere);
                gotoxy(33,5+m);printf("%s",tabM[j].intitule);
                gotoxy(48,5+m);printf("%d",tabM[j].nb_heure);
                m=m+3;
        }

}



 }

void blocPlage()
{

    int j;
    int i=0;

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
    }
    n=i;
    fclose(f);
     printf("la liste des Plage(s)");
 if (n==1)
      printf("Liste vide");
  else
      {
            rectangleX (15,3,1,1,1,3);
            gotoxy(6,2);
            printf("Numero");
            gotoxy(19,2);
            printf("Debut");
            gotoxy(36,2);
            printf("Fin");
            int k,m=0;

    for (j=0;j<n;j++)
        {
                gotoxy(3,5+m);printf("%d",tabPL[j].id);
                gotoxy(20,5+m);printf("%s",tabPL[j].debut);
                gotoxy(33,5+m);printf("%s",tabPL[j].fin);
                m=m+3;
        }

}

 }


void occupeSalle(int idocup)
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
        if((f=fopen(fichierS,"w+"))==NULL)
        {
            printf("Impossible d'ouvrir le fichier %s",fichierS);
            exit(1);
        }
        else
        {

           for (j=0; j<i; j++)
            {
                if (tabS[j].id==idocup)
                {
                    tabS[j].etat=0;
                }
                fprintf(f,"%2d\t %15s\t%4d\t%2d",tabS[j].id,tabS[j].nom,tabS[j].capa,tabS[j].etat);
                fprintf(f,"\n");
            }

        }


    }
    fclose(f);

}

void freeSalle()
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
            if((f=fopen(fichierS,"w+"))==NULL)
            {
                printf("Impossible d'ouvrir le fichier %s",fichierS);
                exit(1);
            }
            else
            {
               for (j=0; j<i; j++)
               {
                       tabS[j].etat=1;
                       fprintf(f,"%2d\t %15s\t%4d\t%2d",tabS[j].id,tabS[j].nom,tabS[j].capa,tabS[j].etat);
                       fprintf(f,"\n");
               }

            }
              fclose(f);
        }

}



int contro_nbrPg(void)
{
    int n=0,idpg;
    Tprogram Pg;

    while ((nb=fgets (ch,256,fpg))!=NULL)
    {
         sscanf(ch, "%d  %s %s %s  %s %d %d %d",&Pg.id_pg,Pg.salle,Pg.Ens,Pg.Matiere,Pg.Plage,&Pg.date.jr,&Pg.date.ms,&Pg.date.an);
         n++;
    }
    if(n==0 )
        idpg=0;
    else
        idpg=Pg.id_pg;

    printf("\n   n=%d",n);
     return idpg;
}



void savePg(void)
{
    int n,i,rep;
    int ids,idens,idmat,idpl;
    Tprogram Pg;
    system("cls");
    if((fpg=fopen(fichierPg,"a+"))==NULL)
    {
        printf("Impossible d'ouvrir le fichier %s",fichierPg);
        exit(1);
    }
    else
    {
           nbrPg=contro_nbrPg();
         //  printf("nbrPg=%d\n",nbrPg);
           gotoxy(8,2);printf("Entrez la date jour que vous voulez programmer ");
           gotoxy(8,4);printf("le __/__/____");
            gotoxy(11,4);scanf("%d",&Pg.date.jr);
            gotoxy(14,4);scanf("%d",&Pg.date.ms);
            gotoxy(17,4);scanf("%d",&Pg.date.an);
           printf("\nEntrez le nombre de programation %c enregistrer: \n",160);
           scanf("%d",&n);

            for (i=0;i<n;i++)
            {
                system("cls");
                printf("\n\nEntregistrement du la programmation  %d.....\n\n",i+1);
                system("PAUSE");
                Pg.id_pg= nbrPg+1;
                 system("cls");

                blocEnseignant();
                printf("\n\nEntrez le num%cro de l' enseignant :\t",130);
                scanf("%d",&idens);
                strcpy(Pg.Ens,tabE[idens-1].nomEns);

                system("cls");
                 blocMatiere();
                printf("\n\nEntrez le num%cro  de la matiere :\t",130);
                scanf("%d",&idmat);
                strcpy(Pg.Matiere,tabM[idmat-1].intitule);

                position:
                system("cls");
                 blocSalle();
                printf("\n\nEntrez l'id de la salle :\t");
                scanf("%d",&ids);
                Pg.ids=ids;
                strcpy(Pg.salle,tabS[ids-1].nom);


                system("cls");
                blocPlage();
                printf("\n\nEntrez l'num%cro de la  plage horaire :\t",130);
                scanf("%d",&idpl);
                Pg.idpl=idpl;
                strcpy(Pg.Plage,tabPL[idpl-1].debut);
                strcat(Pg.Plage,"-");
                strcat(Pg.Plage,tabPL[idpl-1].fin);
                rep=verifProg(ids,idpl,Pg.date);
                if (rep==1)
                {
                    printf("\n\nLa salle %s est deja programm%ce pour le %2d/%2d/%4d  %c %s \n\n",tabS[ids-1].nom,130,Pg.date.jr,Pg.date.ms,Pg.date.an,160,Pg.Plage);
                    system("PAUSE");
                    goto position;
                }
              //  occupeSalle(ids);
            //    printf("rep =%d",rep);
                fprintf(fpg,"%2d\t   %d %-20s\t   %-20s\t   %-20s\t   %d %-12s \t %-2d %-2d %-4d ",Pg.id_pg,Pg.ids,Pg.salle,Pg.Ens,Pg.Matiere,Pg.idpl,Pg.Plage,Pg.date.jr,Pg.date.ms,Pg.date.an);
                fprintf(fpg,"\n");

                nbrPg++;
            }
            printf("Enregistrement termin%c...\n",130);
            freeSalle();
            fclose(fpg);
        }

}





void listePg()
{

    int i=0,j;
    char *n="Numero",*s="Salles",*e="Enseignat",*m="Matieres",*p="Plages",*d="Dates";
     if((f=fopen(fichierPg,"r"))==NULL)
    {
        printf("Impossible d'ouvrir le fichier %s",fichierPg);
        exit(1);
    }
    else
    {
         while ((nb=fgets (ch,256,f))!=NULL)
        {
            sscanf(ch, "%d  %d %s %s %s  %d %s %d %d %d",&tabPg[i].id_pg,&tabPg[i].ids,tabPg[i].salle,tabPg[i].Ens,tabPg[i].Matiere,&tabPg[i].idpl,tabPg[i].Plage,&tabPg[i].date.jr,&tabPg[i].date.ms,&tabPg[i].date.an);
        //   printf("jr=%d ms=%d an=%d \n",tabPg[i].date.jr,tabPg[i].date.ms,tabPg[i].date.an);
            i++;
        }
        if (i==1)
            printf("Le fichier de programmation est vide\n");
        else
        {
             printf("\n\n=======================LISTE DES PROGRAMMATIONS========================================\n");
            printf("_______________________________________________________________________________________\n");
            printf("%-8s|%-10s|%-20s|%-20s|%-12s |%-11s|\n",n,s,e,m,p,d);
            printf("________|__________|____________________|____________________|_____________|___________|\n");
            for (j=0; j<i; j++)
            {
                printf("%8d|%-10s|%-20s|%-20s|%-12s |%2d/%2d/%-4d |\n",tabPg[j].id_pg,tabPg[j].salle,tabPg[j].Ens,tabPg[j].Matiere,tabPg[j].Plage,tabPg[j].date.jr,tabPg[j].date.ms,tabPg[j].date.an);
            }
             printf("________|__________|____________________|____________________|_____________|___________|\n");
        }

    }
    fclose(f);
    getchar();
}

void supprimPg()
{
    int idsup,i=0,j;
    printf("Entrez l'id de la classe %c supprimer",160);
    scanf("%d",&idsup);
     if((f=fopen(fichierPg,"r"))==NULL)
    {
        printf("Impossible d'ouvrir le fichier %s",fichierPg);
        exit(1);
    }
    else
    {
         while ((nb=fgets (ch,256,f))!=NULL)
        {
            sscanf(ch,"%d %s %s %s %s ",&tabPg[i].id_pg,tabPg[i].salle,tabPg[i].Ens,tabPg[i].Matiere,tabPg[i].Plage);
            i++;

        }
        fclose(f);
        if((f=fopen(fichierPg,"w+"))==NULL)
        {
            printf("Impossible d'ouvrir le fichier %s",fichierPg);
            exit(1);
        }
        else
        {

           for (j=0; j<i; j++)
            {
               // printf("id=%d",tabS[j].id);
                if (tabPg[j].id_pg==idsup)
                    j++;
                fprintf(f,"%2d\t %20s\t%20s\t %20s\t%12s",tabPg[i].id_pg,tabPg[i].salle,tabPg[i].Ens,tabPg[i].Matiere,tabPg[i].Plage);
                fprintf(f,"\n");
            }

        }


    }
    fclose(f);
}

int verifProg(int s,int p,Tdate d)
{
    int l=0,c=0,  trover=0;
    fseek(fpg, 0, SEEK_SET);

     while ((nb=fgets (ch,256,fpg))!=NULL)
        {
           sscanf(ch,"%d  %d %s %s %s  %d %s %d %d %d",&tabPg[l].id_pg,&tabPg[l].ids,tabPg[l].salle,tabPg[l].Ens,tabPg[l].Matiere,&tabPg[l].idpl,tabPg[l].Plage,&tabPg[l].date.jr,&tabPg[l].date.ms,&tabPg[l].date.an);
           //printf("l=%d  plage=%d \n",l,tabPg[l].id_pg);

            l++;
        }
     //printf(" date=%d,%d %d,%d,%d",s,p,d.jr,d.ms,d.an);
    while(c<l  &&   trover==0)
    {
        if ((tabPg[c].ids==s) && (tabPg[c].idpl==p) && (tabPg[c].date.jr==d.jr )&& (tabPg[c].date.ms==d.ms )&& (tabPg[c].date.an==d.an))
            trover=1;
        c++;
    }
        return trover;

}
