#ifndef BIBLIOTHEQUE_H_INCLUDED
#define BIBLIOTHEQUE_H_INCLUDED
#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
# include<windows.h>
#include <conio.h>

using namespace std;

class porte
{
    public:
    //constructeur porte (largeur,hauteur,asbsice,ordonnée,sens,nombre)
            porte(int a=70 ,int b=20, int c=2 , int d=70, int  e=1,int f=1) ;
            porte(int a=10,int b=15,int c=2);
            void dessin(void);
            void ouvrire();
            void fermer();

    protected:
            void rectangle(int,int,int,int);
            int largeur,hauteur,ligne,colonne,sens,nombre;
            void gotoxy (int ,int );
            void color(int couleurDuText, int couleurDeFond);
    //Permet de changer les couleurs du texte et du fond d'ecran
};

class ascenseur:public porte
{
    public:
      //constructeur ascenseur (largeur,hauteur,ligne,colonne,sens,nombre,etat,niveau_ascenseur) etat=1(mouvement) etat=0(statique)
        ascenseur(int ,int,int,int,int,int,int);

        ~ascenseur();//destructeur de l'ascenseur
        void dessin();
        void descente(int destinate,int htE);//fonction qui fait descendre l'ascenseur jusqu'au niveau niv quant eta =1
        void monter(int destination ,int htr);//fonction qui fait monter l'ascenseur jusqu'au niveau niv quant eta =1
        void ouvrire(int x, int y);
        void fermer(int x,int y);
        void A_depose_P(int dest,int htr,int cln);
    private:

        void effacer(int decal);//fonction pour effacer la trace de l'ascenseur lors de son deplacement
        int niveauA;


};


//classe personne
class personne
{
    public:
    //constructeur personne(niveau_P,sens_dp,destination,absice,ordonnee)
            personne(int niveau,int destination,int abs,int ord);
            void dessin();
            void deplacement();
            void appale(ascenseur A,int nivA,int htr,int cln);
            void personne_marche(int niv,int x,int y,int distMar,int sensDp);
            void color(int ,int);


    private:
            int niveauP,distMarche,sensDplce,destination,absP,ordP,couleurF,couleurT;
            void position(int a,int b);
            void pasGauche(int,int);
            void pasDroite(int,int);
            void effacer(int x,int y);
            void effacerPasGD(int x,int y);
            void effacerPasDG(int x,int y);
            void personne_entre(int niv,int x,int y,int distMar,int sensDp);



};

class etage :public porte
{
    public:
    //constructeur etage(largeur,hauteur,ligne,colonne,sens,1,nbrE,nbrP)
            etage(int,int,int,int,int,int,int,int);
            void dessin(void);//redefinition de la fonction dessin adapté a l'étage
    private:
            void couloire(void);
            int nbrE,espaceP,nbrP ,espaceF,niveauE;
            void dalle(int,int,int,int);//la de l'étage
            void motif (int ,int,int ,int );

};
class bouton
{
    public:
        bouton(int etat,int abs,int ord);
        void bouton_dessin(int sign);
        void eface_bouton();
        void bouton_alarm(int signal);

   private:
        int etat,abs,ord,nivB;
        void position(int x,int y);
        void couleur(int text,int fond);

};

#endif // BIBLIOTHEQUE_H_INCLUDED

