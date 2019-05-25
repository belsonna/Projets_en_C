#include"bibliotheque.h"
#include"bohomme.cpp"
#include"porte.cpp"
#include"ascenseur.cpp"
#include"etage.cpp"
#include"boutton.cpp"
//
void simulation (int largeurE,int hauteurE,int ligneE,int colonneE,int sensE,int nomberE,int nbrE,int nbrP,int numP,int nivP,int etat_porte_A,int etatp)
{
    //definitions des variables pour manipuler les portes
    int espaceP=largeurE/3;
    int nivPort=1,
        numPort=2,
        largPort=largeurE/16,
        hautPort=hauteurE/3,
        colPort=colonneE-((nivPort-1)*hauteurE),
        lignPort=ligneE+espaceP;
        numPort=1;
    //definition des variables pour la manipulation de l'ascenseur
    int niv_A=1,
        larg_A=largeurE/8,
        haut_A=hauteurE/3,
        lign_A=(largeurE/12)+ligneE,
        colon_A=colonneE-((niv_A-1)*hauteurE),
        dest_A=1,
        x_ouvre=lign_A,
        y_ouvre=colonneE-(niv_A+1-dest_A)*hauteurE;

        //definition des variables pour la manipulation de le bohomme

    int  nivPer=1,
         absP=ligneE+espaceP+5,
         ordP=colonneE-((nivPer-1)*hauteurE+8),
         dest_p=3,
         distanceP=larg_A;

    int d_entrer=15;

     //constructeur etage(largeur,hauteur,ligne,colonne,sens,1,nbrE,nbrP,numP,nivP)
     etage ET(largeurE,hauteurE,ligneE,colonneE,sensE,nomberE,nbrE,nbrP);
    ET.dessin();


    int i;

    //on initialise à chaque fois le parametre de rand à 0
    srand(time(0));

    //on commence la simlation
    for(i=0;i<3;i++)
    {
        //on position l'ordonnee de l'ascenseur par raport à son niveau et celui de l'étage
                numPort=1+rand()%2;
                if(numPort==2)
                {
                    int l=lignPort+espaceP;
                    distanceP=larg_A+espaceP;
                    absP=ligneE+2*espaceP+5;
                   lignPort=l;
                }
                colon_A=colonneE-((niv_A-1)*hauteurE);
                 ascenseur a(larg_A,haut_A,lign_A,colon_A,1,1,niv_A);
                 if(i==0)
                    a.dessin();
                    if(i>0)
                        nivPer=1+rand()%nbrE;//on randomise le niveau dde la personne a partie de la deuxieme simulation

                 dest_p=1+rand()%nbrE;//on randomise la desti,ation de la personne

                ordP=colonneE-((nivPer-1)*hauteurE+8);//on position l'ordonnee de la personne par rapot à son niveau
                personne bonhome(nivPer,dest_p,absP,ordP);
                nivPort=nivPer;
                colPort=colonneE-((nivPort-1)*hauteurE);

                porte Prt(largPort,hautPort,lignPort,colPort,1,1);//on cree une porte au même niveau qu'on a creer la personne
                Prt.ouvrire();
                for(int k=0;k<100000000;k++)
                {}
                bonhome.dessin();
                for(int k=0;k<100000000;k++)
                {}

                   bonhome.personne_marche(nivPer,absP ,ordP,distanceP,1);//le bohome marche jusqu'à l'ascenseur
                   Prt.dessin();//on restitue la porte effacer par le bohomme
                   if(numPort==2)
                   {
                       porte d(largPort,hautPort,lignPort-espaceP,colPort,1,1);
                       d.dessin();
                   }
                   absP-=distanceP-1;
                   bonhome.appale(a,niv_A,hauteurE,colonneE);

                   niv_A=nivPer;//on met le niveau de l'ascensur au niveau de la personne
                   colon_A=colonneE-((niv_A-1)*hauteurE);

                   ascenseur a1(larg_A,haut_A,lign_A,colon_A,1,1,niv_A);
                   a1.ouvrire(lign_A,colon_A);
                   bonhome.personne_marche(nivPer,absP,ordP,d_entrer,1);//le bohomme entre dans l'ascenseur
                   a1.dessin();
                   a1.fermer(lign_A,colon_A);

                   ascenseur b(larg_A,haut_A,lign_A,colon_A,1,1,niv_A);
                   b.A_depose_P(dest_p,hauteurE,colonneE);//l'ascenseur depose la personne
                   niv_A=dest_p; //on recupere le niveau de destination de la personne pour dessiner l'ascenseur
                   colon_A=colonneE-((niv_A-1)*hauteurE);


                   ascenseur c(larg_A,haut_A,lign_A,colon_A,1,1,niv_A);
                   c.ouvrire(lign_A,colon_A);

                   bonhome.personne_marche(nivPer,absP-d_entrer,colon_A-8,d_entrer,2);//le bohomme sort de l'ascenseur vers la porte
                   c.dessin();
                   c.fermer(lign_A,colon_A);
                   bonhome.personne_marche(nivPer,absP-1,colon_A-8,distanceP,2);//le bohonne entre dans la porte


                   nivPort=dest_p;//on recupere le niveau de destination pour dessiner et ouvrir la porte
                   colPort=colonneE-((nivPort-1)*hauteurE);

                    if(numPort==2)
                   {
                       porte d(largPort,hautPort,lignPort-espaceP,colPort,1,1);
                       d.dessin();
                   }
                   porte prt1(largPort,hautPort,lignPort,colPort,1,1);
                   prt1.dessin();

                   prt1.fermer();
                   absP+=distanceP;
                  // a.ouvrire(x_ouvre,y_ouvre);
                  // a.fermer(x_ouvre,y_ouvre);
                   if(numPort==2)
                   {
                       lignPort-=espaceP;

                   }
    }


    //a.monter(4,hauteurE);


}
