#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

class Produkt
{
public:
	friend bool operator==(const Produkt& T1, const Produkt& T2)
	{
		return(T1.nazwa == T2.nazwa && T1.cena == T2.cena && T1.opis == T2.opis);
	}
	string nazwa;
	double cena;
	string opis;
	string stan;
	friend bool operator==(const Produkt& T1, const Produkt& T2);
	Produkt();
	Produkt(string nazwa, double cena, string opis);
	void zmiana_danych(string nazwa, double cena, string opis);
	void Print();
};

class Magazyn
{
public:
	int pojemnosc;
	string stan;
	list<Produkt> spis;
	Magazyn(int pojemnosc, string stan);
	void Zaktualizuj();
	bool Dostepnosc(Produkt przedmiot);
	void Dodanie_Produktu(string nazwa, double cena, string opis);
	void Dodanie_Produktu(Produkt przedmiot);
	void Usuwanie_Produktu(string nazwa, double cena, string opis);
	void Usuwanie_Produktu(Produkt przedmiot);
	void Print_list();
};
Magazyn data_global;

class Domowienie
{
	int ilosc;
	Produkt item;
public:
	void zloznie_zamowienia_na_towar();
	void aktualizacja_stanu_magazynu();
};


class Decyzja {
public:
	bool podjecie_decyzji(string dowod_zakupu);
	void przekazanie_decyzji(string dowod_zakupu);
	void odwolanie_od_decyzji();
};

class Formularz {
private:
	string status_zgloszenia;
	string data_zgloszenia;
	string stan_towaru;
public:
	void uzupelnienie_danych(string im, string naz, string adres);
};

class Pracownik {
public:
	int przeliczenie_towaru(Produkt baza);
	void przekazanie_raportu_remamentu();
	bool przekazanie_formularza();
	void przekazanie_zwroconego_towaru_na_magazyn(Produkt data);
	double zwrot_pieniedzy(double koszt);
	void wydanie_nowego_towaru(Produkt data);
};

class Kasa {
	Produkt data;
	static int kod;
	double cena;
	list<Produkt> lista_zakupow;

public:
	Kasa(Produkt);
	void skanowanie_produktu(Produkt);
	void  wprowadzenie_kodu_rabatowego(int);
	void usuniecie_produktu(Produkt);
	double koszt_zamowienia(Produkt);
	void anulowanie_zakupow(bool);
	void wydruk_paragonu();
	bool rozpoczecie(bool);
	friend class Magazyn;
	friend class Produkt;
};

class Platnosc {
	double cena;
public:
	Platnosc(double);
	bool zatwierdz();
};


class Karta {
	static int PIN;
public:
	void autoryzacja();
	friend Platnosc;
};
Karta karta_global;
int Karta::PIN = 1542;

class Gotowka {
	double ilosc;
public:
	Gotowka(double);
	double zwroc_reszte(double,double);
	friend Platnosc;
};
Gotowka kwota_global;


class Dane_Klienta {
	string Imie;
	string Nazwisko;
	string Adres;
	string Dowod_zakupu;
public:
	Dane_Klienta(string, string, string, string);
	friend class Formularz;
};


