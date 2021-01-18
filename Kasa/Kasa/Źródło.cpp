#include "Nag³ówek.hpp"
using namespace std;

int Kasa::kod = 12345;
int Karta::PIN = 1234;
string Formularz::dowod = "dowod";

Produkt::Produkt()
{
	nazwa = "";
	cena = 0;
	opis = "";
}

Produkt::Produkt(string nazwa, double cena, string opis)
{
	this->nazwa = nazwa;
	this->cena = cena;
	this->opis = opis;
}

void Produkt::zmiana_danych(string nazwa, double cena, string opis)
{
	this->nazwa = nazwa;
	this->cena = cena;
	this->opis = opis;
}

Magazyn::Magazyn(int pojemnosc, string stan)
{
	this->pojemnosc = pojemnosc;
	this->stan = stan;
}

Magazyn data_global(1000, "");


void Magazyn::Zaktualizuj()
{
	ifstream f;
	f.open("Magazyn.txt");
	f.is_open();
	string line;
	int x = 0;
	while (getline(f, line))
	{
		int pos1 = line.find(';') + 1;
		int pos2 = line.substr(pos1).find(';') + pos1;
		string a = line.substr(0, pos1 - 1);
		string b = line.substr(pos1, pos2 - pos1);
		string c = line.substr(pos2 + 1);
		spis.push_back(Produkt(a, stod(b), c));
	}
	f.close();
}

//
//void Decyzja::zapis_do_pliku(Produkt p) {
//	fstream plik;
//	plik.open("Magazyn.txt", ios::out | ios::app);
//	if (plik.good() == true)
//	{
//		plik << endl;
//		plik << p.nazwa << ";";
//		plik << p.cena << ";";
//		plik << p.opis;
//		plik.close();
//	}
//}

bool Magazyn::Dostepnosc(Produkt przedmiot)
{
	list<Produkt>::iterator it;
	for (it = spis.begin(); it != spis.end(); it++)
	{
		if ((*it) == przedmiot)
		{
			return true;
		}
	}
	return false;
}

void Magazyn::Dodanie_Produktu(string nazwa, double cena, string opis)
{
	spis.push_back(Produkt(nazwa, cena, opis));
}


void Magazyn::Dodanie_Produktu(Produkt przedmiot)
{
	spis.push_back(przedmiot);
}


void Magazyn::Usuwanie_Produktu(string nazwa, double cena, string opis)
{
	//int licznik=0;
	list<Produkt>::iterator it;
	for (it = spis.begin(); it != spis.end(); it++)
	{
		if ((*it).nazwa == nazwa) {
			spis.erase(it);
			break;
		}
	}
	//licznik--;
	//spis.remove(Produkt(nazwa, cena, opis));
	//for (int x = 0; x < licznik; x++)
	//{
		//spis.push_back(Produkt(nazwa, cena, opis));
	//}
}

void Magazyn::Usuwanie_Produktu(Produkt przedmiot)
{
	spis.remove(przedmiot);
}


void Magazyn::Print_list()
{
	list<Produkt>::iterator it;
	for (it = spis.begin(); it != spis.end(); it++)
	{
		(*it).Print();
	}
}
Domowienie::Domowienie(int ILOSC, Produkt p) : ilosc(ILOSC), item(p) {};

void Domowienie::zloznie_zamowienia_na_towar()
{
	cout << "Zamowiono!" << endl;
}

void Domowienie::aktualizacja_stanu_magazynu()
{
	for (int x = 0; x < ilosc; x++)
	{
		data_global.Dodanie_Produktu(item);
	}
}

void Produkt::Print()
{
	cout << "Nazwa: " << nazwa << " Cena: " << cena << " Opis: " << opis << endl;
}

Kasa::Kasa(Produkt p1) {
	p1 = data;
}

void Karta::autoryzacja() {
	cout << "Transakcja zaakceptowana!" << endl;
}

double Kasa::koszt_zamowienia(Produkt p1) {
	cena = cena + p1.cena;
	return cena;
}

void Kasa::skanowanie_produktu(Produkt p1) {
	if (data_global.Dostepnosc(p1)) { // z klasy Magazyn
		koszt_zamowienia(p1);
		usuniecie_produktu(p1); // z klasy magazyn
		lista_zakupow.push_back(p1);
	}
	else {
		cout << "Brak produktu na magazynie !!" << endl;
	}
}

void Kasa::wprowadzenie_kodu_rabatowego(int  code) {
	if (code == kod) {
		cena = cena * 0.9;
	}
	else {
		cout << "Nieprawidlowy kod rabatowy !" << endl;
	}
}
void Kasa::usuniecie_produktu(Produkt p1) {
	koszt_zamowienia(p1); //nie wiem jak rozwiazac to zeby odjelo
	data_global.Dodanie_Produktu(p1); //z klasy magazyn
}

void Kasa::anulowanie_zakupow(bool) {
	list<Produkt>::iterator it;
	for (it = data_global.spis.begin(); it != data_global.spis.end(); it++)
	{
		usuniecie_produktu(*it);
	}
}

void Kasa::wydruk_paragonu() {
	cout << cena;
}

Dane_Klienta::Dane_Klienta(string im = " ", string naz = " ", string ad = " ", string dow = " ") :Imie(im), Nazwisko(naz), Adres(ad), Dowod_zakupu(dow) {}

bool Kasa::rozpoczecie(bool b) {
	if (b) {
		return 1;
	}
	else {
		return 0;
	}
}
Platnosc::Platnosc(double Cena = 0.) : cena(Cena) {};
Gotowka::Gotowka(double ile = 0) : ilosc(ile) {};
Gotowka kwota_global(0);

double Gotowka::zwroc_reszte(double koszt, double gotowka) {
	double reszta;
	reszta = gotowka - koszt;
	return reszta;
}

bool Platnosc::zatwierdz() {
	cout << "Wcisnij 1 jesli chcesz zaplacic gotowka , 2 jesli placisz karta" << endl;
	int  wybor;
	cin >> wybor;
	double ilosc;
	int pin;
	switch (wybor)
	{
	case 1:
		cout << "Podaj kwote jaka zamierzasz wplacic" << endl;
		cin >> ilosc;
		if (ilosc > cena) {
			kwota_global.zwroc_reszte(cena, ilosc);
			return false;
		}
		else if (ilosc == cena) {
			return true;
		}
		else {
			cout << "Brak wystarczajacej ilosci gotowki " << endl;
			return false;
		}
	case 2:
		for (int i = 0; i < 3; i++) {
			cout << "WprowadŸ kod PIN" << endl; // podawanie pinu w petli
			cin >> pin;
			if (pin == karta_global.PIN) {
				cout << "Poprawna autoryzacja" << endl;
				return true;
			}
			else {
				cout << "Niepoprawny PIN " << endl;
			}
		}
		return false;
	}
}

bool Decyzja::podjecie_decyzji(Dane_Klienta klient) {

	string prove = "dowod";

	int choice;
	if (klient.Dowod_zakupu == prove) {
		cout << "Czy istnieja widoczne wady wynikajace ze zlego uzywania? 1=Nie 2=Tak" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			return true;
			break;
		case 2:
			return false;
			break;
		}
	}
	else {
		return false;
	}
}

void Decyzja::przekazanie_decyzji(bool decy) {
	if (decy == true) {
		cout << "Twoja formularz zostal rozpatrzony pozytywnie!" << endl;
		
	}
	else {
		cout << "Twoj formularz zostal rozpatrzony negatywnie!" << endl;
	}
}

void Decyzja::odwolanie_od_decyzji() {
	string odwolanie;
	cout << "Napisz odwolanie: ";
	cin >> odwolanie;
}

Dane_Klienta Formularz::uzupelnienie_danych(string im, string naz, string adres) {
	string dowod;
	int choice;
	cout << "Czy klient posiada dowod zakupu?   1=Tak   2=Nie" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "Dowod zakupu: ";
		cin >> dowod;
		cout << endl;
		break;
	case 2:
		cout << "Brak mozliwosci zlozenia formularza" << endl;
		break;
	}
	Dane_Klienta* dane;
	dane = new Dane_Klienta(im, naz, adres, dowod);
	return *dane;
};

void Pracownik::przekazanie_zwroconego_towaru_na_magazyn(Produkt data) {
	data_global.Dodanie_Produktu(data);
}

double Pracownik::zwrot_pieniedzy(double koszt) {
	return koszt;
}

void Pracownik::wydanie_nowego_towaru(Produkt data) {
	data_global.Usuwanie_Produktu(data);
}
void Pracownik::przekazanie_formularza() {
	cout << "Formularz zostal przekazany kierownikowi" << endl;
}

////nowe
double Kasa::koszt_zamowienia(double p1) {
	cena = cena + p1;
	return cena;
}

void Magazyn::Zapisz()
{
	ofstream f;
	f.open("magazyn.txt", ofstream::trunc);
	if (f.good() == true)
	{
		list<Produkt>::iterator it;
		for (it = spis.begin(); it != spis.end(); it++)
		{
			f << (*it).nazwa << ";" << (*it).cena << ";" << (*it).opis << endl;
		}
	}
	f.close();
}