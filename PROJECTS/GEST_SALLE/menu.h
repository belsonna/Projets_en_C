#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
int choix_menu_p(void);
void menu_S(void);
void menu_p()
{

    int choix ;
    choix=choix_menu_p();
    while(choix!=7)
    {
        switch (choix)
        {
            case 1:menu_S(); getch(); break;
            case 2:menu_E(); getch(); break;
            case 3:menu_M(); getch(); break;
            case 4:menu_PL(); getch(); break;
            case 5:menu_Pg(); getch(); break;
            case 6:menu_Ep(); getch(); break;
            default: printf("\n La valeur %d  ne fait pas partie des  choix\n ",choix);getch(); break;
        }
        choix=choix_menu_p();
    }
    system("pause");
}

int choix_menu_p(void)
{
    int choix;
    system("cls");
    printf("********************************************\n");
    printf("*          MENU PRINCIPAL                                          *\n");
    printf("********************************************\n");
    printf("*                                                                                     *\n");
    printf("*       1- Gestion  des Salles                                             *\n");
    printf("*       2- Gestion des Enseignants                                     *\n");
    printf("*       3- Gestion des Mati%cre                                       *\n",138);
    printf("*       4- Gestion des Plages horaire                                 *\n");
    printf("*       5- Gestion des Progammations                               *\n");
    printf("*       6- Gestion des Emplois de Temps                          *\n");
    printf("*       7- Quitter                                                              *\n");
    printf("*                                                                                    *\n");
    printf("********************************************\n");

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
            case 1:saveS(); getch(); break;
            case 2:modifS(); getch(); break;
            case 3:supprimS(); getch(); break;
            case 4:listeS(); getch(); break;
            case 5:salle_lib(); getch(); break;
            case 6:choix=choix_menu_p();getch(); break;
            default: printf("\n La valeur %d  ne fait pas partie des  choix\n ",choix);getch(); break;
        }
        choix=choix_menu_S();
    }
    system("pause");
}

int choix_menu_S(void)
{

    int choix;
    system("cls");
    printf("********************************************\n");
    printf("*          GESTION DES SALLES                                  *\n");
    printf("********************************************\n");
    printf("*                                                                                     *\n");
    printf("*       1- Nouvelles salles                                                 *\n");
    printf("*       2- Modifier une salle                                              *\n");
    printf("*       3- Supprimer une salle                                           *\n",138);
    printf("*       4- Liste des Salles                                                 *\n");
    printf("*       5- Salles libres                                                     *\n");
    printf("*       6- Retour                                                             *\n");
    printf("*       7- Quitter                                                              *\n");
    printf("*                                                                                    *\n");
    printf("********************************************\n");

    printf("\n\n Entrez votre choix: ");
    scanf("%d",&choix);
    return choix;
}


void menu_Ep()
{

    int choix ;
    choix=choix_menu_Ep();
    while(choix!=6)
    {
        switch (choix)
        {
            case 1:saveEp(); getch(); break;
            case 2:modifEp(); getch(); break;
            case 3:supprimEp(); getch(); break;
            case 4:listeEp(); getch(); break;
            case 5:choix=choix_menu_p();getch(); break;
            default: printf("\n La valeur %d  ne fait pas partie des  choix\n ",choix);getch(); break;
        }
        choix=choix_menu_Ep();
    }
    system("pause");
}


int choix_menu_Ep(void)
{

    int choix;
    system("cls");
    printf("********************************************\n");
    printf("*          GESTION DES  EMPLOIS DE TEMPS           *\n");
    printf("********************************************\n");
    printf("*                                                                                     *\n");
    printf("*       1- Nouvelle programmation                                        *\n");
    printf("*       2- Modifier une programmation                                    *\n");
    printf("*       3- Supprimer une programmation                             *\n");
    printf("*       4- Liste des programmation                              *\n");
    printf("*       5- Retour                                                               *\n");
    printf("*       6- Quitter                                                              *\n");
    printf("*                                                                                    *\n");
    printf("********************************************\n");

    printf("\n\n Entrez votre choix: ");
    scanf("%d",&choix);
    return choix;
}


void menu_PL()
{

    int choix ;
    choix=choix_menu_PL();
    while(choix!=6)
    {
        switch (choix)
        {
            case 1:savePL(); getch(); break;
            case 2:modifPL(); getch(); break;
            case 3:supprimPL(); getch(); break;
            case 4:listePL(); getch(); break;
            case 5:choix=choix_menu_p();getch(); break;
            default: printf("\n La valeur %d  ne fait pas partie des  choix\n ",choix);getch(); break;
        }
        choix=choix_menu_Pg();
    }
    system("pause");
}

int choix_menu_PL(void)
{

    int choix;
    system("cls");
    printf("********************************************\n");
    printf("*          GESTION DES  PLAGES  HORAIRES            *\n");
    printf("********************************************\n");
    printf("*                                                                                     *\n");
    printf("*       1- Nouvelle plage                                           *\n");
    printf("*       2- Modifier une plage                                     *\n");
    printf("*       3- Supprimer une plage                                 *\n");
    printf("*       4- Liste des plages                                    *\n");
    printf("*       5- Retour                                                               *\n");
    printf("*       6- Quitter                                                              *\n");
    printf("*                                                                                    *\n");
    printf("********************************************\n");

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
            case 2:modifPg(); getch(); break;
            case 3:supprimPg(); getch(); break;
            case 4:listePg(); getch(); break;
            case 5:choix=choix_menu_p();getch(); break;
            default: printf("\n La valeur %d  ne fait pas partie des  choix\n ",choix);getch(); break;
        }
        choix=choix_menu_Pg();
    }
    system("pause");
}


int choix_menu_Pg(void)
{

    int choix;
    system("cls");
    printf("********************************************\n");
    printf("*          GESTION DES  PROGRAMMATIONS           *\n");
    printf("********************************************\n");
    printf("*                                                                                     *\n");
    printf("*       1- Nouvelle programmation                                          *\n");
    printf("*       2- Modifier une programmation                                    *\n");
    printf("*       3- Supprimer une programmation                             *\n");
    printf("*       4- Liste des programmation                              *\n");
    printf("*       5- Retour                                                               *\n");
    printf("*       6- Quitter                                                              *\n");
    printf("*                                                                                    *\n");
    printf("********************************************\n");

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
            case 2:modifM(); getch(); break;
            case 3:supprimM(); getch(); break;
            case 4:listeM(); getch(); break;
            case 5:choix=choix_menu_p();getch(); break;
            default: printf("\n La valeur %d  ne fait pas partie des  choix\n ",choix);getch(); break;
        }
        choix=choix_menu_M();
    }
    system("pause");
}


int choix_menu_M(void)
{

    int choix;
    system("cls");
    printf("********************************************\n");
    printf("*          GESTION DES  MATIERES                            *\n");
    printf("********************************************\n");
    printf("*                                                                                     *\n");
    printf("*       1- Nouvel Matiere                                            *\n");
    printf("*       2- Modifier une matiere                                       *\n");
    printf("*       3- Supprimer une matiere                                  *\n");
    printf("*       4- Liste des matieres                                     *\n");
    printf("*       5- Retour                                                               *\n");
    printf("*       6- Quitter                                                              *\n");
    printf("*                                                                                    *\n");
    printf("********************************************\n");

    printf("\n\n Entrez votre choix: ");
    scanf("%d",&choix);
    return choix;
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
            case 5:choix=choix_menu_p();getch(); break;
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
    printf("********************************************\n");
    printf("*          GESTION DES  ENSEIGNANTS                     *\n");
    printf("********************************************\n");
    printf("*                                                                                     *\n");
    printf("*       1- Nouvel enseignant                                              *\n");
    printf("*       2- Modifier un enseignant                                        *\n");
    printf("*       3- Supprimer un enseignant                                     *\n");
    printf("*       4- Liste des enseignants                                          *\n");
    printf("*       5- Retour                                                               *\n");
    printf("*       6- Quitter                                                              *\n");
    printf("*                                                                                    *\n");
    printf("********************************************\n");

    printf("\n\n Entrez votre choix: ");
    scanf("%d",&choix);
    return choix;
}



#endif // MENU_H_INCLUDED
