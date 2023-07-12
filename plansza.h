#ifndef MEMORY_PLANSZA_H
#define MEMORY_PLANSZA_H
#include <iostream>
#include <vector>
using namespace std;

class Plansza {
    const int wiersze, kolumny;
    int falsz;
    int **tab, **tabDlaGracza;
    vector<int> vec1;

    void zwolenieniePamieci2D(int **& TAB); //usuwanie i zwalnianie pamieci tablicy dwuwymiarowej

    //tworzenie tablicy gry
    const void stworzPustaPlansze(int **&TAB); //tworzenie Pustej planszy o rozmiarze: wiersze x kolumny = przydzielanie pamieci tablciy 2 wymiarowej
    const void wypelnijPlansze(); //stworzenie planszy wypełnionej liczbami = Memories
    const void wypelnijPlanszaGracza(); //stworzenie planszy jaka bedzie widzial gracz
    const void podstawowaPlansza(); //wypisanie numerkow planszy gracza

    //etap gry
    const int wysietlWskazanyElem(int numerek); //wysietla liczbe w tablicy pod indeksem = numerek-1

public:
    Plansza(const int w, const int k);
    ~Plansza();

    //Tablica gry

    const void konwersja2Dna1D(); //konwersja tablicy 2 wymiarowej memories na vector
    const void PlanszaNiePokazuj(); // plansza widoczna dla mnie
    const void wyswietlPlansze(); //wyswitelenie planszy dla gracza

    //etap gry
    void zmiana(int numerek1, int numerek2); //zamienia indeksy tablicy na poprawnie odkryte elementy
    bool czyCalaOdkryta(); //zwraca czy cala tablica zotsala odkryta
};


#endif //MEMORY_PLANSZA_H
