#include <iostream>
#include "plansza.h"

using namespace std;

void menu(int *w, int *k); //wypisanie poczatkowego interefjsu i wybranir rozmiaru planszy

int main() {
    int *wiersze = new int;
    int *kolumny = new int;
    menu(wiersze, kolumny);

    const int w = *wiersze;
    const int k = *kolumny;

    Plansza plan(w, k);
    plan.konwersja2Dna1D();
    //plan.PlanszaNiePokazuj(); //plansza tylko dla tworcy
    plan.wyswietlPlansze();

    //rozgrywka
    int x, y, licznik = 0;
    while (!plan.czyCalaOdkryta()) {
        do {
            cout << "Podaj numerek 1 karty: ";
            cin >> x;
            cout << "Podaj numerek 2 karty: ";
            cin >> y;
            cout << endl;
        }while((x>w*k || y>w*k) || x==y);

        plan.zmiana(x, y);
        plan.wyswietlPlansze();
        licznik++;
    }
    cout << "Przeszedles gre w ciagu ilosci krokow = " << licznik << endl;
    return 0;
}

void menu(int *w, int *k) //wypisanie poczatkowego interefjsu i wybranie rozmiaru planszy
{
    int wi = 1, ko = 1;
    cout << "WITAMY W GRZE MEMORIES" << endl;
    do {
        cout << "Wybierz rozmiar planszy(conajmneij jedna musi byc parzysta i max 10x10):" << endl;
        cout << "Liczba wierszy: ";
        cin >> wi;
        cout << "Liczba kolumn: ";
        cin >> ko;
    } while ((wi % 2 != 0 && ko % 2 != 0) || (wi > 10 || ko > 10));
    *w = wi;
    *k = ko;
    cout << endl << "Plansza ma wymiary = " << *w << " x " << *k << endl;
    cout << "ZASADY: " << endl << "1 wybierasz dwie karty, ktore sa sprawdzane czy sa takie same" << endl
         << "2 Jesli karty byly dobrze dopasowane to zamieniaja sie w numerki 999, ktorych juz nie sprawdzasz" << endl
         << "3 Jesli karty nie byly dobrze dopasowane to zostaja takie jakie byly" << endl;
}