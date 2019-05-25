#include"bibliotheque.h"

//Les methodes de la class ascenseur

//Le constructeur
ascenseur::ascenseur(int larg,int ht,int lign,int  col,int s,int nbr,int niv)
:porte(larg,ht, lign,col,s,nbr)
{

    niveauA=niv;
   // niv_Dep=niv_dep;
   // niv_Arriv=niv_arriv;
}
// redefinition de la fonction dessin
void ascenseur::dessin()
{
    color(0,3);
    porte::dessin();
}
void ascenseur::ouvrire(int x, int y)
{
  color(0,6);
// porte::ouvrire(0);
       int  c=largeur/2;
            for(int i=0;i<c;i++)
            {

                for(int j=0;j<hauteur-1;j++)
                {
                    gotoxy(x+c-i,y-j-1);
                    cout<<static_cast<char>(179);
                    gotoxy(x+c+i,y-j-1);
                    cout<<static_cast<char>(179);
                }
                for(int k=0;k<10000000;k++)
                 {}
                for(int j=0;j<hauteur-1;j++)
                {
                    gotoxy(x+c-i,y-j-1);//effacement du premier batant
                    cout<<" ";
                    gotoxy(x+c+i,y-j-1);//effacement du deuxieme batant
                    cout<<" ";
                }
            }
}

void ascenseur::fermer(int x, int y)
{
  color(0,6);
// porte::ouvrire(0);
       int  i,c=largeur/2;
            for(i=0;i<c;i++)
            {

                for(int j=0;j<hauteur-1; j++)
                {
                    gotoxy(x+i+1,y-j-1);
                    cout<<static_cast<char>(179);
                    gotoxy(x+largeur-i-1,y-j-1);
                    cout<<static_cast<char>(179);
                }
                for(int k=0;k<10000000;k++)
                 {}
                 if(i<c-1)
                 {
                     for(int j=0;j<hauteur-1;j++)
                    {
                        gotoxy(x+i+1,y-j-1);//effacement du premier batant
                        cout<<" ";
                        gotoxy(x+largeur-i-1,y-j-1);//effacement du deuxieme batant
                        cout<<" ";
                    }
                 }

            }
}
ascenseur::~ascenseur()
{

}

void ascenseur::descente(int destinate,int htE)
{
    int parcours=(niveauA-destinate)*htE;
    int e=(hauteur+1);
        for(int i=0;i<=parcours-hauteur-1;i++)
            {
            for(int k=0;k<100000000;k++)
            {}
                ascenseur d(largeur,hauteur,ligne,colonne+e,sens,nombre,0);

                d.effacer(0);
                 d.dessin();


                    if(i%htE==0)
                {
                        color(0,6);
                        porte p(largeur/2,hauteur,ligne,colonne+i,sens,2);
                        p.dessin();
                }

                if(i==(parcours-hauteur-2))
                {
                        color(0,6);
                        porte p(largeur/2,hauteur,ligne,colonne+parcours,sens,2);
                        p.dessin();
                        ascenseur d(largeur,hauteur,ligne,colonne+parcours,sens,nombre,0);
                        d.dessin();
                }
                e++;
            }
}/*
void ascenseur::monter(int destination ,int htr)
{
    int ecart=(destination-niveauA)*htr,i;
    int e=hauteur +1,k,p,saut=0;
    for (i=0;i<ecart/hauteur;i++)
    {

            for (p=0;p<hauteur;p++,saut++)
            {
                for(int k=0;k<100000000;k++)
                {}
                ascenseur d(largeur,saut,ligne,colonne-e,sens,nombre,0);
                d.effacer(1);
                d.dessin();
                e++;
            }
            for (p=0;p<hauteur;p++,saut--)
            {


                ascenseur d1(largeur,saut,ligne,colonne-e,sens,nombre,0);
                d1.effacer(1);
                d1.dessin();
                e++;
            }


    }
}*/

void ascenseur::monter(int destination ,int htr)
{
    int ecart=(destination-niveauA)*htr;

    int e=hauteur +1;
    int h=hauteur/3,i;

        for(int i=0 ;i<ecart-hauteur;i++)
        {
            for(int k=0;k<100000000;k++)
            {}

                ascenseur d(largeur,hauteur,ligne,colonne-e,sens,nombre,0);
                d.effacer(1);
                d.dessin();
                if(i%htr==0)
                {
                        color(0,6);

                        porte p(largeur/2,hauteur,ligne,colonne-i,sens,2);
                        p.dessin();
                }


               if(i==(ecart-2-hauteur))
                {
                        color(0,6);
                        porte p(largeur/2,hauteur,ligne,colonne-ecart+1,sens,2);
                        p.dessin();

                }
        e++;
        }


}

void ascenseur::effacer(int decal)
{
    int y;
    if (decal==0)
        y=-1;
    else
        y=+1;
    gotoxy(ligne,colonne+y);
    cout<<" ";

    for(int l=0;l<largeur;l++)
    {
        //gotoxy()
        cout<<" ";
    }
    cout<<" ";
    for(int i=1;i<hauteur;i++)
    {
        gotoxy(ligne,colonne-i+y);
        cout<<" ";
    }

    for(int g=1;g<hauteur;g++)
    {
        gotoxy(ligne+largeur,colonne-g+y);
        cout<<" ";
    }
    gotoxy(ligne,colonne-hauteur+y);
    cout<<" ";
    for(int r=0 ;r<largeur;r++)
        cout<<" ";
    gotoxy(ligne+largeur,colonne-hauteur+y);
    cout<<" ";

}
void ascenseur::A_depose_P(int dest,int htr,int cln)
{
    if(dest<niveauA)
    {
        bouton b(35,15,cln-(htr/3)-(niveauA-1)*htr);
        b.bouton_alarm(3);

        bouton b1(35,15,cln-(htr/3)-(dest-1)*htr);
        b1.bouton_alarm(2);

        descente(dest,htr);

        bouton b2(35,15,cln-(htr/3)-(dest-1)*htr);
        b2.bouton_alarm(1);
        cout<<"\a\a";

    }

    else
        if(dest>niveauA)
        {
            bouton b(35,15,cln-(htr/3)-(niveauA-1)*htr);
            b.bouton_alarm(3);

             bouton b1(35,15,cln-(htr/3)-(dest-1)*htr);
            b1.bouton_alarm(2);

            monter(dest,htr);


            bouton b2(35,15,cln-(htr/3)-(dest-1)*htr);
            b2.bouton_alarm(1);
            cout<<"\a\a";
        }

        else
            {}

}
