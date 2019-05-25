#ifndef BIBLIOTHEQUE_H_INCLUDED
#define BIBLIOTHEQUE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>
#define taille 30
void viderBuffer(void);
int id_Emp;
FILE *f;
char *nb;
char ch[256];
void rectangleX(int largeur,int hauteur,int ligne,int colonne,int sens,int nombre);
void gotxy (int ligne, int colonne);

typedef struct dat
{
    int jr,ms,an;
}Tdate;

void gotoxy(int x,int y)
 {
     COORD coordonnees;
     coordonnees.X=x;
     coordonnees.Y=y;
     SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE),coordonnees);

 }

void rectangle (int largeur,int hauteur,int ligne,int colonne)
{
    int h;
    int l;
    gotoxy(ligne,colonne);
    printf("\xDA");
    for(l=1;l<=largeur;l++)
        printf("\xC4");
    printf("\b\xBF");
    for(h=1;h<hauteur;++h)
    {
      gotoxy(ligne,colonne+h);
      printf("\xB3");
    }
    for(h=1;h<hauteur;h++)
    {
      gotoxy(ligne+largeur,colonne+h);
         printf("\xB3");
    }
    gotoxy(ligne,colonne+h);
       printf("\xC0");
    for(l=1;l<=largeur;l++)
        printf("\xC4");
    printf("\b\xD9");
}

 void rectangleX(int largeur,int hauteur,int ligne,int colonne,int sens,int nombre)
 {
     int i;
     for(i=0;i<nombre;i++)
        if(sens==1)
            rectangle(largeur ,hauteur,ligne+(i*largeur),colonne);
        else
            rectangle(largeur,hauteur,ligne,colonne+(i*hauteur));
 }


 void rectangle1(int largeur,int hauteur, int ligne,int colonne)
{
    int h,l;
    gotoxy(ligne,colonne);
    printf("\xDA");
    for (l=1;l<largeur;l++)
        printf("\xC4");
    printf("\xBF");
    for (h=1;h<hauteur;h++)
    {
        gotoxy(ligne+h,colonne+largeur);//h est modifier
        printf("\xB3");
    }
    gotoxy(ligne+hauteur,colonne+largeur);
    printf("\xD9");
    for (l=1;l<=largeur;l++)
    {
        gotoxy(ligne+hauteur,(colonne+largeur)-l);
        printf("\xC4");
    }
    gotoxy(ligne+hauteur,colonne);
    printf("\xC0");
    for (h=1;h<hauteur;h++)
    {
        gotoxy((ligne+hauteur)-h,colonne);
        printf("\xB3");
    }
}


int choix_menu_p(void)
{
    int choix;
    system("cls");
    printf("____________________________________________\n");
    printf("             MENU PRINCIPAL                                            \n");
    printf("____________________________________________\n");
    printf("                                                                                        \n");
    printf("         1- Gestion  des Salles                                              \n");
    printf("         2- Gestion des Enseignants                                      \n");
    printf("         3- Gestion des Mati%cre                                        \n",138);
    printf("         4- Gestion des Plages horaire                                 \n");
    printf("         5- Gestion des Progammations                               \n");
    printf("         6- Gestion des Emplois de Temps                          \n");
    printf("         7- Quitter                                                              \n");
    printf("                                                                                   \n");
    printf("___________________________________________\n");

    printf("\n\n Entrez votre choix: ");
    scanf("%d",&choix);
    return  choix;
}

int choix_menu_S(void)
{

    int choix;
    system("cls");
    printf("____________________________________________\n");
    printf("            GESTION DES SALLES                                   \n");
    printf("____________________________________________\n");
    printf("                                                                                     \n");
    printf("         1- Nouvelles salles                                                 \n");
    printf("         2- Modifier une salle                                              \n");
    printf("         3- Supprimer une salle                                           \n");
    printf("         4- Liste des Salles                                                 \n");
    printf("         5- Salles Nom utilis%ces                                                   \n",130);
    printf("         6- Retour                                                             \n");
    printf("         7- Quitter                                                                \n");
    printf("                                                                                    \n");
    printf("____________________________________________\n");

    printf("\n\n Entrez votre choix: ");
    scanf("%d",&choix);
    return choix;
}



void menu_S()
{

    int choix ;
    choix=choix_menu_S();
    while(choix!=7)
    {
        switch (choix)
        {
            case 1:saveS(); getchar(); break;
            case 2:modifS(); getchar(); break;
            case 3:supprimS(); getchar(); break;
            case 4:listeS(); getchar(); break;
            case 5:salle_lib(); getchar();break;
            case 6:menu_p();getchar(); break;
            default: printf("\n La valeur %d  ne fait pas partie des  choix\n ",choix);getchar(); break;
        }
        choix=choix_menu_S();
    }
     system("pause");
      exit(1);
}


int choix_menu_Ep(void)
{

    int choix;
    system("cls");
    printf("________________________________________________\n");
    printf("          GESTION DES  EMPLOIS DE TEMPS                     \n");
    printf("________________________________________________\n");
    printf("                                                                                     \n");
    printf("       1- G%cnere un emploi de temps                            \n",130);
    printf("       2- Retour                                                               \n");
    printf("       3- Quitter                                                              \n");
    printf("                                                                                    \n");
    printf("________________________________________________\n");

    printf("\n\n Entrez votre choix: ");
    scanf("%d",&choix);
    return choix;
}


void menu_Ep()
{

    int choix ;
    choix=choix_menu_Ep();
    while(choix!=3)
    {
        switch (choix)
        {
            case 1:genererEp();  break;
            case 2:menu_p();getchar(); break;
            default: printf("\n La valeur %d  ne fait pas partie des  choix\n ",choix); break;
        }
        choix=choix_menu_Ep();
    }
      system("pause");
      exit(1);
}


int choix_menu_Pg(void)
{

    int choix;
    system("cls");
    printf("_________________________________________________\n");
    printf("          GESTION DES     PROGRAMMATIONS                  \n");
    printf("________________________________________________\n");
    printf("                                                                                     \n");
    printf("         1- Nouvelle programmation                                             \n");
    printf("         2- Modifier une programmation                                   \n");
    printf("         3- Supprimer une programmation                                   \n");
    printf("         4- Liste des programmations                                        \n");
    printf("         5- Retour                                                               \n");
    printf("         6- Quitter                                                              \n");
    printf("                                                                                    \n");
    printf("________________________________________________\n");

    printf("\n\n Entrez votre choix: ");
    scanf("%d",&choix);
    return choix;
}


void menu_Pg()
{

    int choix ;
    choix=choix_menu_Pg();
    while(choix!=6)
    {
        switch (choix)
        {
            case 1:savePg(); getch(); break;
            case 2:modifPg(); getchar(); break;
            case 3:supprimPg(); getchar(); break;
            case 4:listePg(); getchar(); break;
            case 5:menu_p();getchar(); break;
            default: printf("\n La valeur %d  ne fait pas partie des  choix\n ",choix);getchar(); break;
        }
        choix=choix_menu_Pg();
    }
    system("pause");
      exit(1);
}


int choix_menu_PL(void)
{

    int choix;
    system("cls");
    printf("_________________________________________________\n");
    printf("          GESTION DES  PLAGES HORAIRES                     \n");
    printf("_________________________________________________\n");
    printf("                                                                                     \n");
    printf("         1- Nouvelle plage                                           \n");
    printf("         2- Modifier une plage                                     \n");
    printf("         3- Supprimer une plage                                 \n");
    printf("         4- Liste des plages                                    \n");
    printf("         5- Consulter une  plage                                  \n");
    printf("         6- Retour                                                               \n");
    printf("         7- Quitter                                                              \n");
    printf("                                                                                    \n");
    printf("________________________________________________\n");

    printf("\n\n Entrez votre choix: ");
    scanf("%d",&choix);
    return choix;
}


void menu_PL()
{
    int choix ;
    choix=choix_menu_PL();
    while(choix!=7)
    {
        switch (choix)
        {
            case 1:savePL(); getchar(); break;
            case 2:modifPL(); getchar(); break;
            case 3:supprimPL(); getchar(); break;
            case 4:listePL(); getchar(); break;
            case 5: plage_lib();break;
            case 6:menu_p();getchar(); break;
            default: printf("\n La valeur %d  ne fait pas partie des  choix\n ",choix);getch(); break;
        }
        choix=choix_menu_PL();
    }
    system("pause");
      exit(1);
}


void menu_E()
{

    int choix ;
    choix=choix_menu_E();
    while(choix!=6)
    {
        switch (choix)
        {
            case 1:saveE(); getch(); break;
            case 2:modifE(); getch(); break;
            case 3:supprimE(); getch(); break;
            case 4:listeE(); getch(); break;
            case 5:menu_p(); getch();break;
            default: printf("\n La valeur %d  ne fait pas partie des  choix\n ",choix);getch(); break;
        }
        choix=choix_menu_E();
    }
    system("pause");
}


int choix_menu_E(void)
{

    int choix;
    system("cls");
    printf("_____________________________________________\n");
    printf("          GESTION DES  ENSEIGNANTS                     \n");
    printf("_____________________________________________\n");
    printf("                                                                                     \n");
    printf("         1- Nouvel enseignant                                              \n");
    printf("         2- Modifier un enseignant                                        \n");
    printf("         3- Supprimer un enseignant                                     \n");
    printf("         4- Liste des enseignants                                          \n");
    printf("         5- Retour                                                               \n");
    printf("         6- Quitter                                                              \n");
    printf("                                                                                    \n");
    printf("___________________________________________\n");
    printf("\n\n Entrez votre choix: ");
    scanf("%d",&choix);
    return choix;
}

int choix_menu_M(void)
{

    int choix;
    system("cls");
    printf("_____________________________________________\n");
    printf("               GESTION DES  MATIERES                   \n");
    printf("_____________________________________________\n");
    printf("                                                                                     \n");
    printf("         1- Nouvel Matiere                                            \n");
    printf("         2- Modifier une matiere                                       \n");
    printf("         3- Supprimer une matiere                                   \n");
    printf("         4- Liste des matieres                                      \n");
    printf("         5- Retour                                                               \n");
    printf("         6- Quitter                                                              \n");
    printf("                                                                                   \n");
    printf("____________________________________________\n");

    printf("\n\n Entrez votre choix: ");
    scanf("%d",&choix);
    return choix;
}


void menu_M()
{

    int choix ;
    choix=choix_menu_M();
    while(choix!=6)
    {
        switch (choix)
        {
            case 1:saveM(); getch(); break;
            case 2:modifM(); getchar(); break;
            case 3:supprimM(); getchar(); break;
            case 4:listeM(); getchar(); break;
            case 5:menu_p();getchar(); break;
            default: printf("\n La valeur %d  ne fait pas partie des  choix\n ",choix);getchar(); break;
        }
        choix=choix_menu_M();
    }
       system("pause");
      exit(1);
}





void menu_p()
{

    int choix ;
     system("color  2F");
    choix=choix_menu_p();
    while(choix!=7)
    {
        switch (choix)
        {
            case 1:menu_S();  break;
            case 2:menu_E();  break;
            case 3:menu_M();  break;
            case 4:menu_PL();  break;
            case 5:menu_Pg(); break;
            case 6:menu_Ep(); break;
            default: printf("\n La valeur %d  ne fait pas partie des  choix\n ",choix);getchar(); break;
        }
        viderBuffer();
        choix=choix_menu_p();
    }
    system("pause");
     exit(1);

}
void viderBuffer(void)
{
    int c = 0;
    while((c = getchar()) !='\n' && c!=EOF);
}


#endif // BIBLIOTHEQUE_H_INCLUDED
