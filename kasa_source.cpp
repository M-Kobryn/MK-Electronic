#include "Kasa.hpp"
using namespace std;
Kasa::Kasa(Produkt p1) {
	p1 = data;
}
Kasa::anulowanie_zakupwow(bool  a) {
	if (a) {
		return 1;
	}
	else {
		return 0;
	}
}
Kasa::skanowanie_produktu(Produkt p1) {
	if (dostepnosc(p1)) { // z klasy Magazyn
		koszt_zamowienia(p1.cena);
		usuniecie_produktu(p1); // z klasy magazyn
		lista_zakupow(p1);
	}
	else {
		cout << "Brak produktu na magazynie !!" << endl;
	}
}
 int Kasa::kod = 12345;
Kasa::wprowadzenie_kodu_rabatowego(int  code) {
	
	if (code = kod) {
		koszt_zamowienia() = koszt_zamowienia() * 0.9;
	}
	else {
		cout << "Nieprawidlowy kod rabatowy !" << endl;
	}
}

Kasa::usuniecie_produktu(Produkt p1) {
	koszt_zamowienia(p1.cena); //nie wiem jak rozwiazac to zeby odjelo
	dodanie_produktu(p1); // zklasy magazyn

}

Kasa::anulowanie_zakupow() {
	usuniecie_produktu(lista_zakupow()); 
	dodanie_produktu(lista_zakupow()); // z klasy maagazyn

	return 0; 
}
Kasa::lista_zakupow() {
	

}
Kasa::koszt_zamowienia(p1) {
	double koszt;
	koszt = koszt +p1.cena;
	return koszt; 
}
Kasa::wydruk_paragonu( ) {
	cout << koszt_zamowienia();


}
Dane_Klienta::Dane_Klienta(string im = " ", string naz = " ", string ad = " ", string dow = " ") :Imie(im), Nazwisko(naz), Adres(ad), Dowod_zakupu(dow) {}

Kasa::rozpoczecie(bool b) {
	if (b) {
		return 1;
	}
	else {
		return 0;
}
	Platnosc::Platnosc(double Cena = 0.) : cena(Cena) {};
	Karta::Karta(int pin = 0) : PIN(pin) {};
	Gotowka::Gotowka(double ile = 0) : ilosc(ile) {};
Platnosc::zatwierdz() {
	cout << "Wcisnij 1 jesli chcesz zaplacic gotowka , 2 jesli placisz karta" << endl;
	int  wybor;
	int ilosc;
	
	switch (wybor)
	{
	case 1:
		cout << "Podaj kwote jaka zamierzasz wplacic" << endl;
		cin >> ilosc;
		if (kwota > cena) {
			Gotowka::zwroc_reszte();
		}
		else if (kwota = cena) {
			return;
		}
		else {
			cout << "Brak wystarczajacej ilosci gotowki " << endl;
		}
		break;
	case 2:
		cout << "WprowadŸ kod PIN" << endl;
		if (pin = PIN) {
			cout << "Poprawna autoryzacja" << endl;
		}
		else {
			cout << "Niepoprawny PIN " << endl;
		}
	}

}

