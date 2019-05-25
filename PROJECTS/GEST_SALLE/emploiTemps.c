#include"bibliotheque.h"
int nbEp=0;

//structure emploi de temps
typedef struct EmploitTemps
{
    int id;
    Tdate debutP, finP;
    char Rp[20],Rn[20];
    Tprogram Plundi[3],Pmardi[3],Pmercredi[3],Pjeudi[3],Pvendredi[3],Psamedi[3];
}emploitTemps;

char *fichierEp="fichier_emp.txt";
void afficherEp()
{
    printf("Pas disponible");
}
void genererEp()
{
     int i=0,j=0,k=0,m=0;
     Tdate djr;
    Tprogram tabEp[20];
    emploitTemps Ep;
    gotoxy(8,15);printf("G%cnecration de l'emploi de temps p%criode du __/__/____ au __/__/____ ",130,130);
    gotoxy(52,15);scanf("%d",&Ep.debutP.jr);
    gotoxy(55,15);scanf("%d",&Ep.debutP.ms);
    gotoxy(58,15);scanf("%d",&Ep.debutP.an);

    gotoxy(66,15);scanf("%d",&Ep.finP.jr);
    gotoxy(69,15);scanf("%d",&Ep.finP.ms);
    gotoxy(72,15);scanf("%d",&Ep.finP.an);

    printf("\nResponssable p%cdagogique :\t",130);
    scanf("%s",Ep.Rp);
     printf("\nResponssable de niveau :\t");
    scanf("%s",Ep.Rn);

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
            i++;
        }
        fclose(f);


   //recencer les programmation des different jours
        system("cls");

        gotoxy(8,2);printf("Entrez la date de lundi ");
        gotoxy(8,4);printf("le __/__/____");
        gotoxy(11,4);scanf("%d",&djr.jr);
        gotoxy(14,4);scanf("%d",&djr.ms);
        gotoxy(17,4);scanf("%d",&djr.an);
         printf("\n d= %d /%d /%d",djr.jr,djr.ms,djr.an);
        while(j<i )
        {
            if ( tabPg[j].date.jr==djr.jr && tabPg[j].date.ms==djr.ms && tabPg[j].date.an==djr.an )
            {
                strcpy(Ep.Plundi[k].salle,tabPg[j].salle);
                strcpy(Ep.Plundi[k].Ens,tabPg[j].Ens);
                strcpy(Ep.Plundi[k].Matiere,tabPg[j].Matiere);
                strcpy(Ep.Plundi[k].Plage,tabPg[j].Plage);
                k++;
            }
            j++;
        }

        j=0;
        k=0;
        system("cls");
        gotoxy(8,2);printf("Entrez la date de Mardi ");
        gotoxy(8,4);printf("le __/__/____");
        gotoxy(11,4);scanf("%d",&djr.jr);
        gotoxy(14,4);scanf("%d",&djr.ms);
        gotoxy(17,4);scanf("%d",&djr.an);
         printf("\n d= %d /%d /%d",djr.jr,djr.ms,djr.an);
        while(j<i )
        {
            if (  tabPg[j].date.jr==djr.jr && tabPg[j].date.ms==djr.ms && tabPg[j].date.an==djr.an)
            {
                strcpy(Ep.Pmardi[k].salle,tabPg[j].salle);
                strcpy(Ep.Pmardi[k].Ens,tabPg[j].Ens);
                strcpy(Ep.Pmardi[k].Matiere,tabPg[j].Matiere);
                strcpy(Ep.Pmardi[k].Plage,tabPg[j].Plage);
                k++;
            }
            j++;
        }
        j=0;
        k=0;
         system("cls");
        gotoxy(8,2);printf("Entrez la date de Mercredi ");
        gotoxy(8,4);printf("le __/__/____");
        gotoxy(11,4);scanf("%d",&djr.jr);
        gotoxy(14,4);scanf("%d",&djr.ms);
        gotoxy(17,4);scanf("%d",&djr.an);
         printf("\n d= %d /%d /%d",djr.jr,djr.ms,djr.an);
        while(j<i )
        {
            if (  tabPg[j].date.jr==djr.jr && tabPg[j].date.ms==djr.ms && tabPg[j].date.an==djr.an )
            {
                strcpy(Ep.Pmercredi[k].salle,tabPg[j].salle);
                strcpy(Ep.Pmercredi[k].Ens,tabPg[j].Ens);
                strcpy(Ep.Pmercredi[k].Matiere,tabPg[j].Matiere);
                strcpy(Ep.Pmercredi[k].Plage,tabPg[j].Plage);
                k++;
            }
            j++;
        }

         j=0;
        k=0;
         system("cls");
        gotoxy(8,2);printf("Entrez la date de Jeudi ");
        gotoxy(8,4);printf("le __/__/____");
        gotoxy(11,4);scanf("%d",&djr.jr);
        gotoxy(14,4);scanf("%d",&djr.ms);
        gotoxy(17,4);scanf("%d",&djr.an);
         printf("\n d= %d /%d /%d",djr.jr,djr.ms,djr.an);
        while(j<i )
        {
            if ( tabPg[j].date.jr==djr.jr && tabPg[j].date.ms==djr.ms && tabPg[j].date.an==djr.an )
            {
                strcpy(Ep.Pjeudi[k].salle,tabPg[j].salle);
                strcpy(Ep.Pjeudi[k].Ens,tabPg[j].Ens);
                strcpy(Ep.Pjeudi[k].Matiere,tabPg[j].Matiere);
                strcpy(Ep.Pjeudi[k].Plage,tabPg[j].Plage);
                k++;
            }
            j++;
        }

        j=0;
        k=0;
         system("cls");
        gotoxy(8,2);printf("Entrez la date de Vendredi ");
        gotoxy(8,4);printf("le __/__/____");
        gotoxy(11,4);scanf("%d",&djr.jr);
        gotoxy(14,4);scanf("%d",&djr.ms);
        gotoxy(17,4);scanf("%d",&djr.an);
        printf("\n d= %d /%d /%d",djr.jr,djr.ms,djr.an);
        while(j<i )
        {
            if (  tabPg[j].date.jr==djr.jr && tabPg[j].date.ms==djr.ms && tabPg[j].date.an==djr.an)
            {
                strcpy(Ep.Pvendredi[k].salle,tabPg[j].salle);
                strcpy(Ep.Pvendredi[k].Ens,tabPg[j].Ens);
                strcpy(Ep.Pvendredi[k].Matiere,tabPg[j].Matiere);
                strcpy(Ep.Pvendredi[k].Plage,tabPg[j].Plage);
                k++;
            }
            j++;
        }

          j=0;
        k=0;
         system("cls");
        gotoxy(8,2);printf("Entrez la date de Samedi ");
        gotoxy(8,4);printf("le __/__/____");
        gotoxy(11,4);scanf("%d",&djr.jr);
        gotoxy(14,4);scanf("%d",&djr.ms);
        gotoxy(17,4);scanf("%d",&djr.an);
        printf("\n d= %d /%d /%d",djr.jr,djr.ms,djr.an);
        while(j<i )
        {
            if (  tabPg[j].date.jr==djr.jr && tabPg[j].date.ms==djr.ms && tabPg[j].date.an==djr.an )
            {
                strcpy(Ep.Psamedi[k].salle,tabPg[j].salle);
                strcpy(Ep.Psamedi[k].Ens,tabPg[j].Ens);
                strcpy(Ep.Psamedi[k].Matiere,tabPg[j].Matiere);
                strcpy(Ep.Psamedi[k].Plage,tabPg[j].Plage);
                k++;
            }
            j++;
        }
system("cls");
    printf("\n\n______________EMPLOI DE TEMPS DU %d/%d/%4d AU %d/%d/%4d______________________\n\n",Ep.debutP.jr,Ep.debutP.ms,Ep.debutP.an,Ep.finP.jr,Ep.finP.ms,Ep.finP.an);
    printf("___________________________________________________________________________________________________________________\n");
    printf(" Lundi   | %-20s  (%-6s) |    %-20s  (%-6s) |  %-20s  (%-6s) |\n",Ep.Plundi[0].Matiere,Ep.Plundi[0].Plage,Ep.Plundi[1].Matiere,Ep.Plundi[1].Plage,Ep.Plundi[2].Matiere,Ep.Plundi[2].Plage);
    printf("         | %-20s  (%-6s) |    %-20s  (%-6s) |  %-20s  (%-6s) |\n",Ep.Plundi[0].Ens,Ep.Plundi[0].salle,Ep.Plundi[1].Ens,Ep.Plundi[1].salle,Ep.Plundi[2].Ens,Ep.Plundi[2].salle);
    printf("___________________________________________________________________________________________________________________\n");
    printf(" Mardi   | %-20s  (%-6s) |    %-20s  (%-6s) |  %-20s  (%-6s) |\n",Ep.Pmardi[0].Matiere,Ep.Pmardi[0].Plage,Ep.Pmardi[1].Matiere,Ep.Pmardi[1].Plage,Ep.Pmardi[2].Matiere,Ep.Pmardi[2].Plage);
    printf("         | %-20s  (%-6s) |    %-20s  (%-6s) |  %-20s  (%-6s) |\n",Ep.Pmardi[0].Ens,Ep.Pmardi[0].salle,Ep.Pmardi[1].Ens,Ep.Pmardi[1].salle,Ep.Pmardi[2].Ens,Ep.Pmardi[2].salle);
    printf("___________________________________________________________________________________________________________________\n");
    printf("Mercredi | %-20s  (%-6s) |    %-20s  (%-6s) |  %-20s  (%-6s) |\n",Ep.Pmercredi[0].Matiere,Ep.Pmercredi[0].Plage,Ep.Pmercredi[1].Matiere,Ep.Pmercredi[1].Plage,Ep.Pmercredi[2].Matiere,Ep.Pmercredi[2].Plage);
    printf("         | %-20s  (%-6s) |    %-20s  (%-6s) |  %-20s  (%-6s) |\n",Ep.Pmercredi[0].Ens,Ep.Pmercredi[0].salle,Ep.Pmercredi[1].Ens,Ep.Pmercredi[1].salle,Ep.Pmercredi[2].Ens,Ep.Pmercredi[2].salle);
    printf("___________________________________________________________________________________________________________________\n");
    printf(" Jeudi   | %-20s  (%-6s) |    %-20s  (%-6s) |  %-20s  (%-6s) |\n",Ep.Pjeudi[0].Matiere,Ep.Pjeudi[0].Plage,Ep.Pjeudi[1].Matiere,Ep.Pjeudi[1].Plage,Ep.Pjeudi[2].Matiere,Ep.Plundi[2].Plage);
    printf("         | %-20s  (%-6s) |    %-20s  (%-6s) |  %-20s  (%-6s) |\n",Ep.Pjeudi[0].Ens,Ep.Pjeudi[0].salle,Ep.Pjeudi[1].Ens,Ep.Pjeudi[1].salle,Ep.Pjeudi[2].Ens,Ep.Pjeudi[2].salle);
    printf("___________________________________________________________________________________________________________________\n");
    printf("Vendredi | %-20s  (%-6s) |    %-20s  (%-6s) |  %-20s  (%-6s) |\n",Ep.Pvendredi[0].Matiere,Ep.Pvendredi[0].Plage,Ep.Pvendredi[1].Matiere,Ep.Pvendredi[1].Plage,Ep.Pvendredi[2].Matiere,Ep.Pvendredi[2].Plage);
    printf("         | %-20s  (%-6s) |    %-20s  (%-6s) |  %-20s  (%-6s) |\n",Ep.Pvendredi[0].Ens,Ep.Pvendredi[0].salle,Ep.Pvendredi[1].Ens,Ep.Pvendredi[1].salle,Ep.Pvendredi[2].Ens,Ep.Pvendredi[2].salle);
    printf("___________________________________________________________________________________________________________________\n");
    printf(" Samedi  | %-20s  (%-6s) |    %-20s  (%-6s) |  %-20s  (%-6s) |\n",Ep.Psamedi[0].Matiere,Ep.Psamedi[0].Plage,Ep.Psamedi[1].Matiere,Ep.Psamedi[1].Plage,Ep.Plundi[2].Matiere,Ep.Plundi[2].Plage);
    printf("         | %-20s  (%-6s) |    %-20s  (%-6s) |  %-20s  (%-6s) |\n",Ep.Psamedi[0].Ens,Ep.Psamedi[0].salle,Ep.Psamedi[1].Ens,Ep.Psamedi[1].salle,Ep.Psamedi[2].Ens,Ep.Psamedi[2].salle);
    printf("___________________________________________________________________________________________________________________\n\n");
    printf("RP:  %s\t\t \t\tRN:  %s\n",Ep.Rp,Ep.Rn);
    printf("___________________________________________________________________________________________________________________\n\n");
    char ch[30]="imprim_emp.txt";


    f=fopen(ch,"a+");
    fprintf(f,"\n\n______________EMPLOI DE TEMPS DU %d/%d/%4d AU %d/%d/%4d______________________\n\n",Ep.debutP.jr,Ep.debutP.ms,Ep.debutP.an,Ep.finP.jr,Ep.finP.ms,Ep.finP.an);
    fprintf(f,"____________________________________________________________________________________________________________________\n");
    fprintf(f," Lundi   | %-20s  (%-6s) |    %-20s  (%-6s) |  %-20s  (%-6s) |\n",Ep.Plundi[0].Matiere,Ep.Plundi[0].Plage,Ep.Plundi[1].Matiere,Ep.Plundi[1].Plage,Ep.Plundi[2].Matiere,Ep.Plundi[2].Plage);
    fprintf(f,"         | %-20s  (%-6s) |    %-20s  (%-6s) |  %-20s  (%-6s) |\n",Ep.Plundi[0].Ens,Ep.Plundi[0].salle,Ep.Plundi[1].Ens,Ep.Plundi[1].salle,Ep.Plundi[2].Ens,Ep.Plundi[2].salle);
    fprintf(f,"___________________________________________________________________________________________________________________\n");
    fprintf(f," Mardi   | %-20s  (%-6s) |    %-20s  (%-6s) |  %-20s  (%-6s) |\n",Ep.Pmardi[0].Matiere,Ep.Pmardi[0].Plage,Ep.Pmardi[1].Matiere,Ep.Pmardi[1].Plage,Ep.Pmardi[2].Matiere,Ep.Pmardi[2].Plage);
    fprintf(f,"         | %-20s  (%-6s) |    %-20s  (%-6s) |  %-20s  (%-6s) |\n",Ep.Pmardi[0].Ens,Ep.Pmardi[0].salle,Ep.Pmardi[1].Ens,Ep.Pmardi[1].salle,Ep.Pmardi[2].Ens,Ep.Pmardi[2].salle);
    fprintf(f,"___________________________________________________________________________________________________________________\n");
    fprintf(f,"Mercredi | %-20s  (%-6s) |    %-20s  (%-6s) |  %-20s  (%-6s) |\n",Ep.Pmercredi[0].Matiere,Ep.Pmercredi[0].Plage,Ep.Pmercredi[1].Matiere,Ep.Pmercredi[1].Plage,Ep.Pmercredi[2].Matiere,Ep.Pmercredi[2].Plage);
    fprintf(f,"         | %-20s  (%-6s) |    %-20s  (%-6s) |  %-20s  (%-6s) |\n",Ep.Pmercredi[0].Ens,Ep.Pmercredi[0].salle,Ep.Pmercredi[1].Ens,Ep.Pmercredi[1].salle,Ep.Pmercredi[2].Ens,Ep.Pmercredi[2].salle);
    fprintf(f,"___________________________________________________________________________________________________________________\n");
    fprintf(f," Jeudi   | %-20s  (%-6s) |    %-20s  (%-6s) |  %-20s  (%-6s) |\n",Ep.Pjeudi[0].Matiere,Ep.Pjeudi[0].Plage,Ep.Pjeudi[1].Matiere,Ep.Pjeudi[1].Plage,Ep.Pjeudi[2].Matiere,Ep.Plundi[2].Plage);
    fprintf(f,"         | %-20s  (%-6s) |    %-20s  (%-6s) |  %-20s  (%-6s) |\n",Ep.Pjeudi[0].Ens,Ep.Pjeudi[0].salle,Ep.Pjeudi[1].Ens,Ep.Pjeudi[1].salle,Ep.Pjeudi[2].Ens,Ep.Pjeudi[2].salle);
    fprintf(f,"___________________________________________________________________________________________________________________\n");
    fprintf(f,"Vendredi | %-20s  (%-6s) |    %-20s  (%-6s) |  %-20s  (%-6s) |\n",Ep.Pvendredi[0].Matiere,Ep.Pvendredi[0].Plage,Ep.Pvendredi[1].Matiere,Ep.Pvendredi[1].Plage,Ep.Pvendredi[2].Matiere,Ep.Pvendredi[2].Plage);
    fprintf(f,"         | %-20s  (%-6s) |    %-20s  (%-6s) |  %-20s  (%-6s) |\n",Ep.Pvendredi[0].Ens,Ep.Pvendredi[0].salle,Ep.Pvendredi[1].Ens,Ep.Pvendredi[1].salle,Ep.Pvendredi[2].Ens,Ep.Pvendredi[2].salle);
    fprintf(f,"___________________________________________________________________________________________________________________\n");
    fprintf(f," Samedi  | %-20s  (%-6s) |    %-20s  (%-6s) |  %-20s  (%-6s) |\n",Ep.Psamedi[0].Matiere,Ep.Psamedi[0].Plage,Ep.Psamedi[1].Matiere,Ep.Psamedi[1].Plage,Ep.Plundi[2].Matiere,Ep.Plundi[2].Plage);
    fprintf(f,"         | %-20s  (%-6s) |    %-20s  (%-6s) |  %-20s  (%-6s) |\n",Ep.Psamedi[0].Ens,Ep.Psamedi[0].salle,Ep.Psamedi[1].Ens,Ep.Psamedi[1].salle,Ep.Psamedi[2].Ens,Ep.Psamedi[2].salle);
    fprintf(f,"___________________________________________________________________________________________________________________\n\n\n");
    fprintf(f,"RP:  %s\t\t\t\t RN:  %s\n",Ep.Rp,Ep.Rn);
    fprintf(f,"___________________________________________________________________________________________________________________\n\n");

    fclose(f);

    printf("\n\nLe fichier a %ct%c imprim%c..............\n\n",130,130,130);


            system("PAUSE");

    }
}


