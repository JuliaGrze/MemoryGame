#include <iostream>
#include <vector>
#include <random>
#include "plansza.h"
using namespace std;

Plansza::Plansza(const int w, const int k)
:wiersze(w), kolumny(k){}

void Plansza::zwolenieniePamieci2D(int **&TAB) {
    for(int i=0; i<wiersze; i++)
        delete []TAB[i];
    delete [] TAB;
}

Plansza::~Plansza() {
    cout << "KONIEC GRY" << endl;
    zwolenieniePamieci2D(tab);
    zwolenieniePamieci2D(tabDlaGracza);
}

const void Plansza::stworzPustaPlansze(int **&TAB) {
    TAB = new int * [wiersze];
    for(int i=0; i<wiersze; i++)
        TAB[i] = new int [kolumny];
}

const void Plansza::wypelnijPlansze() {
    stworzPustaPlansze(tab);
    int ileEl = wiersze * kolumny; // laczna ilosc elementow w tablicy
    falsz = ileEl;
    int indeks, liczba;
    srand(time(NULL));

    //tworzenie vectora wypelnionego podwojnie liczbami od 0 do ileEl/2
    vector<int> v;
    for (int i = 0; i < ileEl; i++) {
        if (i % 2 == 0)
            v.push_back(i);
        else
            v.push_back(i - 1);
    }

    //wypelnienienie losowo tablicy dwuwymiarowej liczbami z vectora
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            indeks = rand() % (v.size()); //wylosowanie indeksu z vectora
            liczba = v[indeks]; //pobranie wartosci z v[indeks]
            tab[i][j] = liczba; //przypisanie do tablicy liczby z vectora
            v.erase(v.begin() + indeks); //usuniecie z vectora liczby użytej
        }
    }

}
const void Plansza::wypelnijPlanszaGracza() {
    stworzPustaPlansze(tabDlaGracza);
    int x = 1;
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            tabDlaGracza[i][j] = x;
            x++;
        }
    }
}

const void Plansza::podstawowaPlansza() {
    cout << "PIERWOTNA PLANSZA GRACZA" << endl;
    int x = 1;
    for(int i=0; i<wiersze; i++){
        for(int j=0; j< kolumny; j++){
            cout << x;
            if(x < 10)
                cout << "   ";
            else if(x < 100)
                cout << "  ";
            else
                cout << " ";
            x++;}
        cout << endl;
    }
    cout << endl;
}


const void Plansza::konwersja2Dna1D() {
    wypelnijPlansze();
    wypelnijPlanszaGracza();
    int x = 0;
    for(int i=0;i<wiersze;i++){
        for(int j=0;j<kolumny;j++){
            vec1.push_back(tab[i][j]);
        }}
}


const void Plansza::PlanszaNiePokazuj() {
    cout << "TWOJA PLANSZA MEMORIES:" << endl;
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++)
            cout << left << tab[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

const void Plansza::wyswietlPlansze() {
    podstawowaPlansza();
    cout << "TWOJA PLANSZA MEMORIES:" << endl;
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++)
        {
            cout << left << tabDlaGracza[i][j];
            if(tabDlaGracza[i][j] < 10)
                cout << "   ";
            else if(tabDlaGracza[i][j] < 100)
                cout << "  ";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

const int Plansza::wysietlWskazanyElem(int numerek) {
    return vec1[numerek-1];
}

void Plansza::zmiana(int numerek1, int numerek2) {
    cout << endl;
    cout << "Odkryty przez ciebie element pod numerekiem: " << numerek1 << " = " << vec1[numerek1-1] << endl;
    cout << "Odkryty przez ciebie element pod numerekiem: " << numerek2 << " = " << vec1[numerek2-1] << endl;

    if(wysietlWskazanyElem(numerek1) == wysietlWskazanyElem(numerek2)) {
        cout << "Brawo znalazles pasujace do siebie elemnty, karty zostaja odwracone" << endl;
        for (int i = 0; i < wiersze; i++) {
            for (int j = 0; j < kolumny; j++)
                if (tabDlaGracza[i][j] == numerek1)
                    //tabDlaGracza[i][j] = wysietlWskazanyElem(numerek1);
                    tabDlaGracza[i][j] = 999;
                else if (tabDlaGracza[i][j] == numerek2)
                    tabDlaGracza[i][j] = 999;
        }
        falsz -= 2;
    }
    else
        cout << "Niestety elemnty nie sa takie same, karty nie zostana odwrocone" << endl;
    cout << endl;
}

bool Plansza::czyCalaOdkryta() {
    if(falsz == 0)
        return true;
    else
        return false;
}







