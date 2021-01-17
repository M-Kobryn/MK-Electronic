#include "Nag³ówek.hpp"

using namespace std;



int main() {
	cout << "==================================" << endl;
	cout << "ADMIN PANEEEL" << endl;
	cout << "==================================" << endl;
	cout << "DOMOWIENIE TOWARU = 1" << endl;
	cout << "SPRAWDZENIE DOSTEPNOSCI TOWARU= 2 " << endl;
	cout << "USUNIECIE TOWARU = 3 " << endl;
	int choice;
	string nazwa;
	double cena;
	string opis;
	cin >> choice;
	Produkt *glob_prod;
	Domowienie* glob_dom;
	switch (choice) {
	case 1:
		int ilosc;
		cout << "Podaj ilosc towaru " << endl;
		cin >> ilosc;
		cout << "Podaj nazwe , cene oraz opis zamawianego produktu" << endl;
		cin >> nazwa >> cena >> opis;
		glob_prod=new Produkt(nazwa,cena,opis);
		glob_dom=new Domowienie (ilosc,*glob_prod);
		glob_dom->zloznie_zamowienia_na_towar();
		glob_dom->aktualizacja_stanu_magazynu();
		data_global.Zaktualizuj();
		//data_global.Dodanie_Produktu(nazwa, cena, opis); 
		//data_global.Zaktualizuj();
		break;
	case 2:
		cout << "Podaj nazwe, cene oraz opis produktu " << endl;
		
		cin >> nazwa >> cena >> opis;
		glob_prod=new Produkt(nazwa,cena,opis);
		if (data_global.Dostepnosc(*glob_prod)) {
			cout << "PRODUKT JEST DOSTEPNY" << endl;
		}
		else
		{
			cout << "PRODUKT NIEDOSTEPNY!!!!!" << endl;
		}
		
		break;
	case 3:
		cout << "Podaj nazwe produktu, opis oraz cene " << endl;
		cin >> nazwa >> cena >> opis;
		glob_prod=new Produkt(nazwa, cena, opis);

		data_global.Usuwanie_Produktu(nazwa, cena, opis); //albo
		data_global.Usuwanie_Produktu(*glob_prod);
		data_global.Zaktualizuj();

		break;

	}
	system("pause");
	return 0;
}