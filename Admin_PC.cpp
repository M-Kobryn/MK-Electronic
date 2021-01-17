#include "Nag³ówek.hpp";
using namespace std; 


int main() {
	// 1
	string nazwa;
	double cena;
	string opis;
	Produkt* glob_prod;
	Domowienie* glob_dom;

	// 2
	string nazwa1;
	double cena1;
	string opis1;
	Produkt* zwrot;
	string imie;
	string nazwisko;
	string adres;
	string dowod_zakupu;
	Formularz formularz;
	Decyzja decyzja;
	string linia;
	bool zgoda = false;
	int licznik=0;

	int choice;
	do {
		cout << "==================================" << endl;
		cout << "\t\t\t ADMIN PANEL" << endl;
		cout << "==================================" << endl << endl;
		cout << "DOMOWIENIE TOWARU = 1" << endl;
		cout << "SPRAWDZENIE DOSTEPNOSCI TOWARU = 2 " << endl;
		cout << "USUNIECIE TOWARU = 3 " << endl;
		cout << "PRZEKAZANIE TOWARU NA MAGAZYN = 4 " << endl;
		cout << "FORMULARZ = 5 " << endl;

		cin >> choice;

		switch (choice) {
			case 1:
				int ilosc;
				cout << "Podaj ilosc towaru " << endl;
				cin >> ilosc;
				cout << "Podaj nazwe , cene oraz opis zamawianego produktu" << endl;
				cin >> nazwa >> cena >> opis;
				glob_prod = new Produkt(nazwa, cena, opis);
				glob_dom = new Domowienie(ilosc, *glob_prod);
				glob_dom->zloznie_zamowienia_na_towar();
				glob_dom->aktualizacja_stanu_magazynu();
				data_global.Zaktualizuj();
				//data_global.Dodanie_Produktu(nazwa, cena, opis);
				//data_global.Zaktualizuj();
				break;
			case 2:
				cout << "Podaj nazwe, cene oraz opis produktu " << endl;

				cin >> nazwa >> cena >> opis;
				glob_prod = new Produkt(nazwa, cena, opis);
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
				glob_prod = new Produkt(nazwa, cena, opis);

				data_global.Usuwanie_Produktu(nazwa, cena, opis); 
				//albo
				//data_global.Usuwanie_Produktu(*glob_prod);
				data_global.Zaktualizuj();
				break;
		case 4:
			Pracownik pracownik;
			cout << "Podaj nazwe, cene, opis produktu, ktory zostal zwrocony" << endl;
			cin >> nazwa1 >> cena1 >> opis1;
			zwrot = new Produkt(nazwa1, cena1, opis1);
			pracownik.przekazanie_zwroconego_towaru_na_magazyn(*zwrot);
			data_global.Zaktualizuj();
			break;
		case 5:
			while (zgoda == false && licznik < 3) {
				cout << "Podaj dane klienta wraz z dowodem zakupu" << endl;
				cin >> imie >> nazwisko >> adres >> dowod_zakupu;
				formularz.uzupelnienie_danych(imie, nazwisko, adres);
				pracownik.przekazanie_formularza();
				decyzja.podjecie_decyzji(dowod_zakupu);
				decyzja.przekazanie_decyzji(dowod_zakupu);
				if (decyzja.podjecie_decyzji(dowod_zakupu) == false) {
					licznik += 1;
					cout << "Czy chcesz odwolac sie od decyzji? Tak=1, Nie=2" << endl;
					int wybor;
					cin >> wybor;
					switch (wybor) {
					case 1:
						decyzja.odwolanie_od_decyzji();
						break;
					case 2:
						cout << "Dziekujemy za odpowiedz :)" << endl;
						break;
					}
				}
				else {
					zgoda = true;
				}
			}
			break;
		case 6:
			ifstream magazyn;
			magazyn.open("Magazyn.txt");
			if (magazyn.is_open())
			{
				while (getline(magazyn, linia)) {
					cout << linia << endl;
				}
			}
			else {
				cout << "Nie mozna otworzyc pliku!" << endl;
			}
			magazyn.close();
			break;
		}
		if ((choice >= 1) && (choice <= 6)) {
			cout << endl;
			system("pause");
		}
		
	} while (choice);
	
	return 0;
}

