#include"bibliotheque.h"

using namespace std;

//Les methodes de la class porte

 porte::porte(int lg,int ht,int lgn,int col, int s,int n)
{
    largeur=lg; hauteur=ht;
    ligne=lgn; colonne=col ;
    sens=s; nombre=n;
}
//fonction de positionnement sur l'écran
 void porte::gotoxy(int x,int y )
 {
     COORD coordonnees;
     coordonnees.X=x;
     coordonnees.Y=y;
     SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE),coordonnees );

 }
 //fonction qui dessine un rectangle
void porte::rectangle(int larg,int htr, int lig, int col)
{
    gotoxy(lig,col);
    cout<<"\xC0";

    for(int l=0;l<larg;l++)
    {
        //gotoxy()
        cout<<"\xC4";
    }
    cout<<"\b\xD9";
    for(int i=1;i<htr; i++)
    {
        gotoxy(lig,col-i);
        cout<<"\xB3";
    }

    for(int g=1;g<htr;g++)
    {
        gotoxy(lig+larg,col-g);
        cout<<"\xB3";
    }
    gotoxy(lig,col-htr);
    cout<<"\xDA";
    for(int r=0 ;r<larg;r++)
        cout<<"\xC4";
    gotoxy(lig+larg,col-htr);
    cout<<"\xBF";

}
 void porte::dessin()
 {
     int i;
     for(i=0;i<nombre;i++)
        if(sens==1)
            rectangle(largeur ,hauteur,ligne+(i*largeur),colonne);
        else
              rectangle(largeur,hauteur,ligne,colonne+(i*hauteur));
 }

void porte::color(int couleurDeFond,int couleurDuText)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDeFond*16+couleurDuText);
}


void porte::ouvrire()
{
   // colonne-=1;
   color(0,6);
for(int i=0;i<largeur-1;i++)
    {
        for (int j=0;j<hauteur-1;j++)
        {
            gotoxy(ligne+largeur-i-1,colonne-j-1);
             cout<<static_cast<char>(179);
        }
        for(int k=0;k<10000000;k++)
            {}
        if(i<largeur-1)
        {
            for (int j=0;j<hauteur-1;j++)
                {
                gotoxy(ligne+largeur-i-1,colonne-j-1);//effacement du  batant
                cout<<" ";

                }
        }
    }

    //gotoxy(2,2);

}
void porte::fermer()
{
   // colonne-=1;
   color(0,6);

    for(int i=0;i<largeur-1;i++)
        {
            for (int j=0;j<hauteur-1;j++)
            {
                gotoxy(ligne+i+1,colonne-j-1);
                 cout<<static_cast<char>(179);
            }
            for(int k=0;k<10000000;k++)
                {}
            if(i<largeur-1)
            {
                for (int j=0;j<hauteur-1;j++)
                    {
                    gotoxy(ligne+i+1,colonne-j-1);//effacement du  batant
                    cout<<" ";
                    }
            }
        }

    //gotoxy(2,2);

}

