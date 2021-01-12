#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <list>
using namespace std;
class Produkt 
{
	string nazwa;
	double cena;
	string opis;
public:
	friend bool operator==(const Produkt& T1, const Produkt& T2) 
	{
		return(T1.nazwa == T2.nazwa && T1.cena == T2.cena && T1.opis == T2.opis);
	}
	Produkt() 
	{
		nazwa = "";
		cena = 0;
		opis = "";
	}
	Produkt(string nazwa, double cena, string opis)
	{
		this->nazwa = nazwa;
		this->cena = cena;
		this->opis = opis;
	}
	void zmiana_danych(string nazwa, double cena, string opis) 
	{
		this->nazwa = nazwa;
		this->cena = cena;
		this->opis = opis;
	}
	void Print() 
	{
		cout << "Nazwa " + nazwa + " Cena: " << cena << " Opis " + opis<<endl;
	}
};

class Magazyn 
{
	int pojemnosc;
	string stan;
	list<Produkt> spis;
public:
	list<Produkt> get_spis() 
	{
		return spis;
	}
	Magazyn(int pojemnosc, string stan) 
	{
		this->pojemnosc = pojemnosc;
		this->stan = stan;
		Zaktualizuj();
	}
	void Zaktualizuj() 
	{
		ifstream f;
		f.open("Magazyn.txt");
		f.is_open();
		string line;
		int x = 0;
		while (getline(f, line))
		{
			int pos1 = line.find(';')+1;
			int pos2 = line.substr(pos1).find(';')+pos1;
			string a = line.substr(0, pos1-1);
			string b = line.substr(pos1, pos2-pos1);
			string c = line.substr(pos2+1);
			spis.push_back(Produkt(a, stod(b), c));
		}
	}
	bool Dostepnosc(Produkt przedmiot) 
	{
		list<Produkt>::iterator it;
		for (it = spis.begin(); it != spis.end(); it++)
		{
			if((*it) == przedmiot)
			{
				return true;
			}
		}
		return false;
	}
	void Dodanie_Produktu(string nazwa, double cena, string opis)
	{
		spis.push_back(Produkt(nazwa,cena,opis));
	}
	void Dodanie_Produktu(Produkt przedmiot)
	{
		spis.push_back(przedmiot);
	}
	void Usuwanie_Produktu(string nazwa, double cena, string opis)
	{
		spis.remove(Produkt(nazwa, cena, opis));
	}
	void Print_list() 
	{
		list<Produkt>::iterator it;
		for (it = spis.begin(); it != spis.end(); it++) 
		{
			(*it).Print();
		}
	}
};
class Domowienie
{
	int ilosc;
	Produkt item;
public:
	bool zloznie_zamowienia_na_towar() 
	{
		///?
	}
	void aktualizacja_stanu_magazynu(Magazyn Mag) 
	{
		for (int x = 0; x < ilosc; x++) 
		{
			Mag.Dodanie_Produktu(item);
		}
	}
};
//test
//void main() 
//{
//	Magazyn m(100, "cokolwiek");
//	m.Dodanie_Produktu("AAa", 21, "kkk");
//	m.Print_list();
//	list<Produkt> a = m.get_spis();
//	m.Usuwanie_Produktu("AAa", 21, "kkk");
//	m.Print_list();
//
//}