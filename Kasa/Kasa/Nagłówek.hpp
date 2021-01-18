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
	void Zapisz(); //nowe
};
extern Magazyn data_global;

class Domowienie
{
	int ilosc;
	Produkt item;
public:
	void zloznie_zamowienia_na_towar();
	void aktualizacja_stanu_magazynu();
	Domowienie(int, Produkt);
};

class Dane_Klienta {
public:
	string Imie;
	string Nazwisko;
	string Adres;
	string Dowod_zakupu;
	Dane_Klienta(string, string, string, string);
	friend class Formularz;
};

class Decyzja {
public:
	bool podjecie_decyzji(Dane_Klienta klient);
	void przekazanie_decyzji(bool decyzja);
	void odwolanie_od_decyzji();
	void zapis_do_pliku(Produkt);
};

class Formularz {
private:
	string status_zgloszenia;
	string data_zgloszenia;
	string stan_towaru;
	static string dowod;
public:
	Dane_Klienta uzupelnienie_danych(string im, string naz, string adres);
};

class Pracownik {
public:
	void przekazanie_formularza();
	void przekazanie_zwroconego_towaru_na_magazyn(Produkt data);
	double zwrot_pieniedzy(double koszt);
	void wydanie_nowego_towaru(Produkt data);
};

class Kasa {
public:
	Produkt data;
	static int kod;
	double cena;
	list<Produkt> lista_zakupow;
	Kasa(Produkt);
	Kasa() = default;
	void skanowanie_produktu(Produkt);
	void  wprowadzenie_kodu_rabatowego(int);
	void usuniecie_produktu(Produkt);
	double koszt_zamowienia(Produkt);
	double koszt_zamowienia(double); /// nowe
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
public:
	static int PIN;
	void autoryzacja();
	friend Platnosc;
};


extern Karta karta_global;

class Gotowka {
	double ilosc;
public:
	Gotowka(double);
	double zwroc_reszte(double, double);
	friend Platnosc;
};
extern Gotowka kwota_global;

//////nowe