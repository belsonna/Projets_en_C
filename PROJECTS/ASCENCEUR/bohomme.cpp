#include"bibliotheque.h"

//Les methodes de la classe personne


//constructeur personne(niveau_P,numero_porte,etat_P,sens_dp,destination
personne::personne(int niveau,int destinate,int abs,int ord)
{
        srand(time(0));
        couleurT=1+rand()%14;
        couleurF=0;
        color(couleurF,couleurT);
        niveauP=niveau;
        destination=destinate;
        absP=abs;
        ordP=ord;
}

//methode gotoxy
void personne::position(int a,int  b)
{
    //porte::gotoxy(a,b);//on appele la fonction gotoxy definie dans la classe porte
    COORD coordonnees;
     coordonnees.X=a;
     coordonnees.Y=b;
     SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE),coordonnees);
}

//methode qui dessine une personne
void personne::dessin()
{
    color(couleurF,couleurT);
    position(absP,ordP+1);
    cout<<static_cast<char>(2);//<<static_cast<char>(177);
    position(absP,ordP+2);
   cout<<static_cast<char>(287);
    //position(x,y+2);
   // cout<<static_cast<char>(179);//<<static_cast<char>(17);
    position(absP,ordP+3 );
    cout<<static_cast<char>(178);//<<static_cast<char>(178);
     position(absP,ordP+4);
    cout<<static_cast<char>(178);//<<static_cast<char>(178);

    //main gauche
     //position(x,y+2);
    //cout<<static_cast<char>(260);
     position(absP-1,ordP+3);
    cout<<static_cast<char>(260);
    position(absP-2,ordP+4);
    cout<<static_cast<char>(260);

    //pied droite
    position(absP,ordP+5);
    cout<<static_cast<char>(260);
     position(absP-1,ordP+6);
    cout<<static_cast<char>(260);
     position(absP-1,ordP+7);
    cout<<static_cast<char>(260);

    //main droite
    position(absP+1,ordP+3);
    cout<<static_cast<char>(260);
     position(absP+2,ordP+4);
    cout<<static_cast<char>(260);

     //pied gauche
    position(absP,ordP+5);
    cout<<static_cast<char>(260);
     position(absP+1,ordP+6);
    cout<<static_cast<char>(260);
     position(absP+1,ordP+7);
    cout<<static_cast<char>(260);
    // position(x+4,y+5);
    //cout<<static_cast<char>(260);
     color(0,6);

}

void personne::personne_marche(int niv,int x,int y,int distMar,int sensDp)
{

    int i;
    color(couleurF,couleurT);
    //y=niv;
    if (sensDp==1)
    {
        for(i=0;i<distMar;i++)
        {
            pasDroite(x-i,y);
            for(int k=0;k<10000000;k++)
            {}
            if (i<distMar-1)
                effacerPasGD(x-i,y);
             if (i<distMar-1)
             {
                pasGauche(x-i,y);
                for(int k=0;k<10000000;k++)
                {}
                effacerPasDG(x-i,y);
            }
        }
        color(0,6);
    }
    else
    if (sensDp==2)
        {
              for(i=0;i<distMar;i++)
            {
                pasDroite(x+i,y);
                 for(int k=0;k<10000000;k++)
                {}
                if (i<distMar-1)
                    effacerPasGD(x+i,y);
                 if (i<distMar-1)
                 {
                    pasGauche(x+i,y);
                    for(int k=0;k<10000000;k++)
                    {}
                    effacerPasDG(x+i,y);
                }
            }
         }
         color(0,6);
}


//fonction qui efface une personne a position initiale
void personne::effacer(int x,int y)
{
     position(x,y+1);
    cout<<" ";
    position(x,y+2);
   cout<<" ";
    //position(x,y+2);

    position(x,y+3);
    cout<<static_cast<char>(178);//<<static_cast<char>(178);
     position(x,y+4);
    cout<<static_cast<char>(178);//<<static_cast<char>(178);

    //main gauche

     position(x-1,y+3);
    cout<<" ";
    position(x-2,y+4);
    cout<<" ";

    //pied droite
    position(x,y+5);
    cout<<" ";
     position(x-1,y+6);
    cout<<" ";
    position(x-1,y+7);
   cout<<" ";

    //main droite
    position(x+1,y+3);
    cout<<" ";
     position(x+2,y+4);
    cout<<" ";

     //pied gauche
    position(x,y+5);
    cout<<" ";
     position(x+1,y+6);
    cout<<" ";
     position(x+1,y+7);
    cout<<" ";
}


//main gauche devant et pied droit derière
void personne::pasGauche(int x,int y)
{
    position(x,y+1);
    cout<<static_cast<char>(81);//<<static_cast<char>(177);
    position(x,y+2);
   cout<<static_cast<char>(287);
    //position(x,y+2);
   // cout<<static_cast<char>(179);//<<static_cast<char>(17);
    position(x,y+3);
    cout<<static_cast<char>(178);//<<static_cast<char>(178);
     position(x,y+4);
    cout<<static_cast<char>(178);//<<static_cast<char>(178);

    //main gauche
     //position(x,y+2);
    //cout<<static_cast<char>(260);
     position(x-1,y+3);
    cout<<static_cast<char>(260);
    position(x-1,y+4);
    cout<<static_cast<char>(260);

    //pied droite
    position(x,y+5);
    cout<<static_cast<char>(260);
     position(x-1,y+6);
    cout<<static_cast<char>(260);
     position(x-2,y+7);
    cout<<static_cast<char>(260);

    //main droite
    position(x+1,y+3);
    cout<<static_cast<char>(260);
     position(x+2,y+4);
    cout<<static_cast<char>(260);

     //pied gauche
    position(x,y+5);
    cout<<static_cast<char>(260);
     position(x+1,y+6);
    cout<<static_cast<char>(260);
     position(x+2,y+7);
    cout<<static_cast<char>(260);
}


//
void personne::pasDroite(int x,int y)
{
     position(x,y+1);
    cout<<static_cast<char>(81);//<<static_cast<char>(177);
    position(x,y+2);
   cout<<static_cast<char>(287);
    //position(x,y+2);
   // cout<<static_cast<char>(179);//<<static_cast<char>(17);
    position(x,y+3);
    cout<<static_cast<char>(178);//<<static_cast<char>(178);
     position(x,y+4);
    cout<<static_cast<char>(178);//<<static_cast<char>(178);

    //main gauche
     //position(x,y+2);
    //cout<<static_cast<char>(260);
     position(x-1,y+3);
    cout<<static_cast<char>(260);
    position(x-2,y+3);
    cout<<static_cast<char>(260);

    //pied droite
    position(x,y+5);
    cout<<static_cast<char>(260);
     position(x-1,y+6);
    cout<<static_cast<char>(260);
     position(x-1,y+7);
    cout<<static_cast<char>(260);

    //main droite
    position(x+1,y+3);
    cout<<static_cast<char>(260);
     position(x+1,y+4);
    cout<<static_cast<char>(260);

     //pied gauche
    position(x,y+5);
    cout<<static_cast<char>(260);
     position(x+1,y+6);
    cout<<static_cast<char>(260);
     position(x+1,y+7);
    cout<<static_cast<char>(260);
}



void personne::effacerPasDG(int x,int y)
{
    position(x,y+1);
    cout<<" ";//<<static_cast<char>(177);
    position(x,y+2);
   cout<<" ";
    //position(x,y+2);
   // cout<<static_cast<char>(179);//<<static_cast<char>(17);
    position(x,y+3);
    cout<<" ";//<<static_cast<char>(178);
     position(x,y+4);
    cout<<" ";//<<static_cast<char>(178);

    //main gauche
     //position(x,y+2);
    //cout<<static_cast<char>(260);
     position(x-1,y+3);
    cout<<" ";
    position(x-1,y+4);
    cout<<" ";

    //pied droite
    position(x,y+5);
    cout<<" ";
     position(x-1,y+6);
   cout<<" ";
     position(x-2,y+7);
    cout<<" ";

    //main droite
    position(x+1,y+3);
    cout<<" ";
     position(x+2,y+4);
    cout<<" ";

     //pied gauche
    position(x,y+5);
    cout<<" ";
     position(x+1,y+6);
    cout<<" ";
     position(x+2,y+7);
    cout<<" ";
}
 void personne::effacerPasGD(int x,int y)
{
    position(x,y+1);
    cout<<" ";
    position(x,y+2);
   cout<<" ";
    position(x,y+3);
    cout<<" ";
     position(x,y+4);
    cout<<" ";

    //main gauche
     //position(x,y+2);
    //cout<<static_cast<char>(260);
     position(x-1,y+3);
   cout<<" ";
    position(x-2,y+3);
    cout<<" ";

    //pied droite
    position(x,y+5);
    cout<<" ";
     position(x-1,y+6);
    cout<<" ";
     position(x-1,y+7);
    cout<<" ";

    //main droite
    position(x+1,y+3);
    cout<<" ";
     position(x+1,y+4);
    cout<<" ";

     //pied gauche
    position(x,y+5);
    cout<<" ";
     position(x+1,y+6);
    cout<<" ";
     position(x+1,y+7);
    cout<<" ";

}
void personne::appale(ascenseur A,int nivA,int htr,int cln)
{
    if (nivA<niveauP)
    {
        bouton b(35,15,cln-(nivA-1)*htr-(htr/3));
        b.bouton_alarm(3);

        bouton b1(35,15,cln-(niveauP-1)*htr-(htr/3));
        b1.bouton_alarm(2);

         A.monter(niveauP,htr);

        bouton b2(35,15,cln-(niveauP-1)*htr-(htr/3));
        b2.bouton_alarm(1);
        cout<<"\a";
    }

    else
        if (nivA>niveauP)
        {
            bouton b(35,15,cln-(nivA-1)*htr-(htr/3));
            b.bouton_alarm(3);

            bouton b1(35,15,cln-(niveauP-1)*htr-(htr/3));
            b1.bouton_alarm(2);

            A.descente(niveauP,htr);

            bouton b2(35,15,cln-(niveauP-1)*htr-(htr/3));
            b2.bouton_alarm(1);
            cout<<"\a";
        }

        else
            {}
}
 void personne ::personne_entre(int niv,int x,int y,int distMar,int sensDp)
 {
     personne_marche(niv,x,y,distMar,sensDp);
     dessin();
 }
void personne::color(int couleurDeFond,int couleurDuText)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDeFond*16+couleurDuText);
}
