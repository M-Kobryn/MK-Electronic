#include "Nag³ówek.hpp"

int main() 
{
	data_global.Zaktualizuj();
	Kasa kasa;
	cout <<"Aby zaczac zakupy nacisnij dowolny przycisk"<<endl;
	system("pause");
	int b = 0;
	while (b !=5)
	{
		cout << " WYBIERZ NUMER BY WYKONAC OPERACJE:" << endl;
		cout << " 1: Zeskanuj produkt" << endl;
		cout << " 2: Usun produkt z koszyka" << endl;
		cout << " 3: Anulowanie zakupow" << endl;
		cout << " 4: Wyswietl liste zakupow" << endl;
		cout << " 5: Zakoncz i zaplac" << endl;
		cin >> b;
		if (b == 1)
		{
			string a1;
			cout << "podaj nazwe produktu" << endl;
			cin >> a1;
			list<Produkt>::iterator it;
			for (it = data_global.spis.begin(); it != data_global.spis.end(); it++)
			{
				if ((*it).nazwa == a1)
				{
					kasa.lista_zakupow.push_back(*it);
					kasa.koszt_zamowienia(*it);
					data_global.Usuwanie_Produktu(*it);
					break;
				}	
			}
		}
		if (b == 2)
		{
			cout << "podaj nazwe produktu do usuniecia" << endl;
			string a2;
			cin >> a2;
			list<Produkt>::iterator it2;
			for (it2 = kasa.lista_zakupow.begin(); it2 != kasa.lista_zakupow.end(); it2++)
			{
				if ((*it2).nazwa == a2)
				{
					kasa.koszt_zamowienia(-(*it2).cena);
					kasa.lista_zakupow.erase(it2);
					data_global.Dodanie_Produktu(*it2);
					break;
				}
			}
		}
		if (b == 3)
		{
			cout << "czy na pewno? Wpisz: Tak 1 / Nie = 0" << endl;
			int a3;
			cin >> a3;
			if (a3 == 1)
			{
				list<Produkt>::iterator it;
				for (it = kasa.lista_zakupow.begin(); it != kasa.lista_zakupow.end(); it++)
				{
					data_global.Dodanie_Produktu(*it);
				}
				kasa.cena = 0;
			}
			data_global.Zapisz();
			return 0;
		}
		if (b == 4) 
		{
			list<Produkt>::iterator it;
			for (it = kasa.lista_zakupow.begin(); it != kasa.lista_zakupow.end(); it++)
			{
				(*it).Print();
			}
		}
	}
	cout << "Czy posiadasz kod rabatowy? Wpisz: Tak = 1 / Nie = 0"<<endl;
	int d;
	cin >> d;
	if (d == 1) 
	{
		cout << "Podaj kod rabatowy"<<endl;
		int a4;
		cin >> a4;
		kasa.wprowadzenie_kodu_rabatowego(a4);
	}
	cout << "Cena koncowa: " << kasa.cena << endl;
	Platnosc plat(kasa.cena);
	plat.zatwierdz();
	system("pause");
	data_global.Zapisz();
	return 1;
}