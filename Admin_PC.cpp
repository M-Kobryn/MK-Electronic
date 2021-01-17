#include "Nag³ówek.hpp";
using namespace std; 


int main() {

	// 1
	string nazwa;
	double cena;
	string opis;
	Produkt* glob_prod;
	Domowienie* glob_dom;
	Decyzja zapis;
	int liczba;
	int ilosc;

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
	int choice1;
	Dane_Klienta* klient;
	string nazwa2;
	double cena2;
	string opis2;

	int choice_pracownik;
	int choice_kierownik;

		string login_k = "admin";
		string haslo_k = "12345";

		string podane_l;
		string podane_h;

		cout << "Podaj login: ";
		cin >> podane_l;
		cout << "Podaj haslo: ";
		cin >> podane_h;
		cout << endl;

		if (podane_l == login_k && podane_h == haslo_k) {
			do {
				cout << "===================================" << endl;
				cout << "\t PANEL KIEROWNIKA" << endl;
				cout << "===================================" << endl << endl;
				cout << "DOMOWIENIE TOWARU = 1" << endl;
				cout << "SPRAWDZENIE DOSTEPNOSCI TOWARU = 2 " << endl;
				cout << "USUNIECIE TOWARU = 3 " << endl;
				cout << "WYSWIETLENIE MAGAZYNU = 4 " << endl;
				cout << "PRZEKAZANIE TOWARU NA MAGAZYN = 5 " << endl;
				cout << "KONIEC PRACY = 0 " << endl;
				cout << endl;

				cin >> choice_kierownik;
				system("cls");
				switch (choice_kierownik) {
					zgoda = false;
				case 1:
					cout << "Podaj ilosc towaru " << endl;
					cin >> ilosc;
					cout << "Podaj nazwe, cene oraz opis zamawianego produktu" << endl;
					cin >> nazwa >> cena >> opis;
					glob_prod = new Produkt(nazwa, cena, opis);
					//zapis.zapis_do_pliku(*glob_prod);
					glob_dom = new Domowienie(ilosc, *glob_prod);
					glob_dom->zloznie_zamowienia_na_towar();
					glob_dom->aktualizacja_stanu_magazynu();
					data_global.Zaktualizuj();
					data_global.Print_list();
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
					//data_global.Zaktualizuj();
					break;
				case 4:
					data_global.Print_list();
					break;
				case 5:
					Pracownik pracownik;
					cout << "Podaj nazwe, cene, opis produktu, ktory zostal zwrocony" << endl;
					cin >> nazwa1 >> cena1 >> opis1;
					zwrot = new Produkt(nazwa1, cena1, opis1);
					pracownik.przekazanie_zwroconego_towaru_na_magazyn(*zwrot);
					//data_global.Zaktualizuj();
					break;
				}
				if ((choice_kierownik >= 1) && (choice_kierownik <= 6)) {
					cout << endl;
					system("pause");
				}
			} while (choice_kierownik);
		}
			///////////////////////////////////////////////////////////////////////////////////

		else {
			do {
				cout << "==================================" << endl;
				cout << "\t PANEL PRACOWNIKA" << endl;
				cout << "==================================" << endl << endl;
				cout << "PRZEKAZANIE TOWARU NA MAGAZYN = 1 " << endl;
				cout << "FORMULARZ = 2 " << endl;
				cout << "WYSWIETLENIE MAGAZYNU = 3 " << endl;
				cout << "SPRAWDZENIE DOSTEPNOSCI TOWARU = 4 " << endl;
				cout << "KONIEC PRACY = 0 " << endl;
				cout << endl;

				cin >> choice_pracownik;
				switch (choice_pracownik) {

				case 1:
					Pracownik pracownik;
					cout << "Podaj nazwe, cene, opis produktu, ktory zostal zwrocony" << endl;
					cin >> nazwa1 >> cena1 >> opis1;
					zwrot = new Produkt(nazwa1, cena1, opis1);
					pracownik.przekazanie_zwroconego_towaru_na_magazyn(*zwrot);
					break;

				case 2:
					cout << "Podaj nazwe, cene i opis produktu, ktorego dotyczy formularz: " << endl;
					cin >> nazwa2;
					cin >> cena2;
					cin >> opis2;
					glob_prod = new Produkt(nazwa2, cena2, opis2);

					while (zgoda == false && licznik < 3) {
						cout << "Podaj dane klienta: " << endl;
						cin >> imie >> nazwisko >> adres;

						klient = new Dane_Klienta(formularz.uzupelnienie_danych(imie, nazwisko, adres));

						bool tmp;
						tmp = decyzja.podjecie_decyzji(*klient);
						decyzja.przekazanie_decyzji(tmp);

						if (tmp == false) {
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
								zgoda = true;
								break;
							}
						}
						else {
							zgoda = true;
						}
					}
					cout << "Podaj forme rekompensaty:  1=Zwrot pieniedzy  2=Nowy towar" << endl;
					cin >> choice1;
					switch (choice1) {
					case 1:
						cout << "Kwota zwrocona: ";
						cout << glob_prod->cena << endl;
						break;
					case 2:
						if (data_global.Dostepnosc(*glob_prod) == true) {
							data_global.Usuwanie_Produktu(nazwa2, cena2, opis2);
							cout << "Nowy towar wydany" << endl;
						}
						else {
							cout << "Domowienie towaru" << endl;
							glob_dom = new Domowienie(1, *glob_prod);
							glob_dom->zloznie_zamowienia_na_towar();
							glob_dom->aktualizacja_stanu_magazynu();
							cout << "Nowy towar wydany" << endl;
							data_global.Usuwanie_Produktu(nazwa2, cena2, opis2);
						}
						break;
					}
					break;
				case 3:
					data_global.Print_list();
					break;
				case 4:
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
				}
				//system("cls");
				if ((choice_pracownik >= 1) && (choice_pracownik <= 6)) {
					cout << endl;
					system("pause");
				}

			} while (choice_pracownik);
		}

	return 0;
}

