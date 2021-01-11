#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <algorithm>
#include <list>
class Produkt 
{
	string nazwa;
	double cena;
	string opis;
public:
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
};

class Magazyn 
{
	int pojemnosc;
	string stan;
	list<Produkt> spis;
public:
	Magazyn(int pojemnosc, string stan) 
	{
		this->pojemnosc = pojemnosc;
		this->stan = stan;
	}
	void Zaktualizuj() 
	{
		ifstream f;
		f.open("Magazyn.txt");
		f.is_open();
		string line;
		int x = 0;
		while (getline(f, line, ';'))
		{
			spis.
		}
	}
	void Dodanie_Produktu(string nazwa, double cena, string opis)
	{

	}
};
void main() 
{
	new Magazyn(100, "cokolwiek");
}