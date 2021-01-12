#include <iostream>
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

class Magazyn {
public:
	bool dostepnosc();
	void dodanie_produktu();
	void usuniecie_produktu();
};

class Decyzja {
public:
	bool podjecie_decyzji(string dowod_zakupu);
	void przekazanie_decyzji(string dowod_zakupu);
	bool odwolanie_od_decyzji();
};

class Formularz {
private:
	string status_zgloszenia;
	string data_zgloszenia;
	string stan_towaru;
public:
	void uzupelnienie_danych(string im, string naz, string adres);
};

class Dane_klienta {
private:
	string imie;
	string nazwisko;
	string adres;
	string dowod_zakupu;
};

class Pracownik {
public:
	int przeliczenie_towaru(Produkt baza);
	void przekazanie_raportu_remamentu();
	bool przekazanie_formularza();
	void przekazanie_zwroconego_towaru_na_magazyn(Produkt data);
	double zwrot_pieniedzy(double koszt);
	bool wydanie_nowego_towaru(Produkt data);
};
class Kasa {
	Produkt data;
	static int kod;

public:
	bool skanowanie_produktu(bool);
	bool  wprowadzenie_kodu_rabatowego();
	void usuniecie_produktu();
	double koszt_zamowienia();
	void anulowanie_zakupow();
	void wydruk_paragonu();
	void rozpoczecie(bool);
	Produkt lista_zakupow();
	friend class Magazyn;
	friend class Produkt;
};

class Platnosc {
	double cena;
public:
	bool zatwierdz();
};

class Karta {
	int PIN;
public:
	bool autoryzacja();
	friend Platnosc;
};

class Gotowka {
	double ilosc;
public:
	double zwroc_reszte(double);
	friend Platnosc;
};


class Dane_Klienta {
	string Imie;
	string Nazwisko;
	string Adres;
	string Dowod_zakupu;
public:
	friend class Formularz;
};
