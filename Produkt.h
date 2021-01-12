#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <list>
using namespace std;

class Produkt
{
	string nazwa;
	double cena;
	string opis;
public:
	friend bool operator==(const Produkt& T1, const Produkt& T2);
	Produkt();
	Produkt(string nazwa, double cena, string opis);
	void zmiana_danych(string nazwa, double cena, string opis);
	void Print();
};

class Magazyn
{
	int pojemnosc;
	string stan;
	list<Produkt> spis;
public:
	list<Produkt> get_spis();
	Magazyn(int pojemnosc, string stan);
	void Zaktualizuj();
	bool Dostepnosc(Produkt przedmiot);
	void Dodanie_Produktu(string nazwa, double cena, string opis);
	void Dodanie_Produktu(Produkt przedmiot);
	void Usuwanie_Produktu(string nazwa, double cena, string opis);
	void Print_list();
};
class Domowienie
{
	int ilosc;
	Produkt item;
public:
	bool zloznie_zamowienia_na_towar();
	void aktualizacja_stanu_magazynu(Magazyn Mag);
};