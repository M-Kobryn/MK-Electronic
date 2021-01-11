#pragma once
#include <iostream>
using namespace std;


class Kasa {
	Produkt data;
	static int kod;

public :
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
	bool zatwierdz( );
};

class Karta {
	int PIN;
public :
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