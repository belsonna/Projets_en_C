#include"bibliotheque.h"

bouton::bouton(int a,int b,int c)
{
    etat=a;
    abs=a;
    ord=c;

}

void bouton::bouton_dessin (int sign)
{

    position(abs,ord);//les coordonnees su boutton
    if(sign==1)
        {
            couleur(1,2);
            cout<<static_cast<char>(178);//le caractere representant le boutton
            couleur(0,6);
        }
        else
        if(sign==2)
        {
            couleur(1,14);
            cout<<static_cast<char>(178);
            couleur(0,6);
        }
          else
        {
            couleur(1,12);
            cout<<static_cast<char>(178);
            couleur(0,6);
        }
}
 void bouton::bouton_alarm(int signal)
 {
     bouton_dessin(signal);
 }

void bouton::position(int a,int b)
{
    //porte::gotoxy(a,b);//on appele la fonction gotoxy definie dans la classe porte
    COORD coordonnees;
     coordonnees.X=a;
     coordonnees.Y=b;
     SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE),coordonnees);
}
void bouton::couleur(int couleurDeFond,int couleurDuText)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDeFond*16+couleurDuText);
}
