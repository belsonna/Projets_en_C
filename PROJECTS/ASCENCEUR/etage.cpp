#include"bibliotheque.h"


//Les Methodes de la class etage
//constructeur etage(a=largeur,b=hauteur,c=ligne,d=colonne,e=sens,f=1,g=nbrE,i=nbrP,j=etat_A,k=niv_A,niveauP)
 etage::etage(int a,int b,  int c,int d, int e, int f,int g,int i):porte(a,b,c,d,e,f)
      {
            nbrE=g;
            nbrP=i;
            espaceP =a/3;
            espaceF =largeur/6;
            niveauE=1;
      }


void etage::motif (int htr,int larg ,int x, int y)
{
    int i,j;
    gotoxy(x,y);
     for (i=0;i<30;i++)
        {
             for(j=0;j<20;j++)
                    cout<<"X";
            cout<<endl;
        }
}



void   etage::dessin()
{
      int haut=ligne;
      int grandeur=ligne;
      int i;
      int lg=ligne,col=colonne,lrg=largeur,ht=hauteur;
      int ordB=colonne-hauteur/3;

      for(int j=0;j<nbrE;j++)
      {
            color(0,6);
           dalle(lrg,col,lg,ht);
           porte::dessin();
            //motif(hauteur,largeur,lg,col);
           gotoxy(ligne,colonne);
             couloire();
             bouton B(35,2,ordB);

             if (j==0)
                B.bouton_alarm(1);
             else
                B.bouton_alarm(3);

            porte porte_Ascenseur((largeur/16),(hauteur/3),((largeur/12)+ligne),colonne,1,2);
            porte_Ascenseur.dessin();
           color(0,6);
           for ( i=0;i<=nbrP;i++)
            {

                //cout<<colonne;

              porte porte_bat((largeur/16),(hauteur/3),haut+=espaceP,colonne,1,1);
                porte_bat.dessin();

                porte fenetre((largeur/24),(hauteur/6),(haut+espaceF),(colonne-(hauteur/3)),1,2);
                fenetre.dessin();//  cout<<"porte numero"<<i;

            }

            //ascenseur a((largeur/8),(hauteur/3),((largeur/12)+ligne),colonne,1,1,etat,niveauA);
            //if(niveauE == niveauA)
               //    a.dessi
            niveauE++;
            ordB-=hauteur;
            col=col-ht;
            colonne=colonne-hauteur;
            haut=haut -(i*espaceP);


      }

}

  //fonction qui dessine la cheminée de l'ascenseur
  void etage::couloire()
  {
      color(0,6);
      int i;
      for ( i=0;i<hauteur;i++)
            {
                gotoxy(((largeur/12)+ligne)-2,colonne+i-hauteur+1);
                cout<<static_cast<char>(124)<<setw(largeur/8+4)<<static_cast<char>(124);
            }
  }
// fonction qui dessine la dalle de l'etage
  void etage::dalle(int largdal,int coldal,int lig,int haut )
  {
      int i;
    gotoxy(lig,coldal+1);
    for(i=0; i<largdal+1;i++)
        cout<<static_cast<char>(178);
  }
