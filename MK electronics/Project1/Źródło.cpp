#include <iostream>

using namespace std;

class Kasa {
private: 
	string data;
public:	
	bool skanowanie_produktu();
	bool wprowadznie_kodu_rabatowego();
	void usuniecie_produktu();
	double koszt_zamowienia();
	void anulowanie_zakupow();
	void wydruk_paragonu();
	void rozpoczenie();
};

class Platnosc {
private:
	double cena;
public:
	bool zatwierdz(); //??????????????
};

class Gotowka : public Platnosc {
private:
	double ilosc;
public:
	double zwroc_reszte();
};

class Karta : public Platnosc {
private: 
	int PIN;
public: 
	bool autoryzacja();
};

class Produkt {
private: 
	string nazwa;
	double cena;
	string opis;
public:
	void zmiana_danych();
};

class Magazyn {
private: 
	int pojemnosc;
	string stan;
public: 
	bool dostepnosc();
	void dodanie_produktu();
	void usuniecie_produktu();
};

class Domowienie
{
private:
	int ilosc;
public:
	void spis_potrzebnego_towaru();
	void aktualizacja_stanu_magazynu();
	bool zlozenie_zamowienia_na_towar();
};

class Pracownik
{
public:
	int przeliczenie_towaru();
	bool przekazanie_raportu_remamentu();
	bool przekazanie_formualrza();
	bool przkeazanie_zwrócenego_towaru_na_magazyn();
	double zwrot_pieniedzy();
	bool wydanie_nowego_towaru();
};

class Formularz {
private:
	string status_zgloszenia;
	string data_zgloszenia;
	string stan_towaru;
public:
	void uzupelnienie_danych();
	friend class Dane_Klienta;
};

class Dane_Klienta {
private:
	string imie;
	string nazwisko;
	string adres;
	string dowod_zakupu;
};

class Decyzja {
public:
	bool podjecie_decyzji();
	void przekazanie_decyzji();
	bool odwolanie_od_decyzji();
};

int main() {
	return 0;
}
