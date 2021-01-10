#include <iostream>
#include <string>
using namespace std;

class Produkt {
public:
	string nazwa;
	double cena;
	string opis;
	void zmiana_danych();
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

bool Decyzja::podjecie_decyzji(string dowod_zakupu) {
	string prove = "dowod";
	int choice;
	if (dowod_zakupu == prove) {
		cout << "Czy istnieja widoczne wady wynikajace ze zlego uzywania?";
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

void Decyzja::przekazanie_decyzji(string dowod) {
	if (podjecie_decyzji(dowod) == true) {
		cout << "Twoja formularz zostal rozpatrzony pozytywnie!" << endl;
	}
	else {
		cout << "Twoj formularz zostal rozpatrzony negatywnie!" << endl;
		cout << "Czy chcesz odwolac sie od decyzji? Tak=1, Nie=2" << endl;
		int choice;
		switch (choice) {
		case 1:
			odwolanie_od_decyzji();
			break;
		case 2:
			cout << "Dziekujemy za odpowiedz :)" << endl;
			break;
		}
	}
}

bool Decyzja::odwolanie_od_decyzji() {
	string odwolanie;
	cout << "Napisz odwolanie: ";
	cin >> odwolanie;
}

void Formularz::uzupelnienie_danych(string im, string naz, string adres) {
	string dowod;
	cout << "Imie: ";
	cin >> im;
	cout << endl;
	cout << "Nazwisko: ";
	cin >> naz;
	cout << endl;
	cout << "Adres: ";
	cin >> adres;
	cout << endl;
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
		break;
	default:
		break;
	}
	
};
// ???
int Pracownik::przeliczenie_towaru(Produkt baza) {
	if (Magazyn::dostepnosc(baza)==false) {

	}
}

void Pracownik::przekazanie_zwroconego_towaru_na_magazyn(Produkt data) {
	Magazyn::dodanie_produktu(data);
}

void Pracownik::przekazanie_raportu_remamentu(Produkt baza) {
	return przeliczenie_towaru(Produkt baza);
}

double Pracownik::zwrot_pieniedzy(double koszt) {
	return koszt;
}

bool wydanie_nowego_towaru(Produkt data) {
	if (Magazyn::usuniecie_produktu(data) == true) {
		return true;
	}
	else {
		return false;
	}
}