#include"naglowek.h"
void wyczysc() { //usuwa zawartosc konsoli
	if (system("cls"))
	{
		system("clear");
	}
}
string sprawdzenieLitery(string Fraza, string odgadniete, int rozmiar,char litera,int* wsk) {//sprawdza czy litera nalezy do hasla(frazy), jesli nie to zwieksza licznik
	if (Fraza.find(litera) != string::npos) {
		for (int j = 0; j < rozmiar; j++) {
			if (Fraza[j] == litera) {
				odgadniete[j] = litera;
			}
		}
	}
	else {
		*wsk = *wsk + 1;
	}
	return odgadniete;
}
void rysuj(int licznik) {//rysuje wisielca w zaleznosci od ilosci popelnionych bledow
	
	if (licznik == 1) {
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl<<"/";
	}
	if (licznik == 2) {
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl << "/ \\";
	}
	if (licznik == 3) {
		cout << endl;
		cout << endl << " |";
		cout << endl<<" |";
		cout << endl<<" |";
		cout << endl << " |";
		cout << endl << "/ \\";
	}
	if (licznik == 4) {
		cout << endl;
		cout << endl << " |/";
		cout << endl << " |";
		cout << endl << " |";
		cout << endl << " |";
		cout << endl << "/ \\";
	}
	if (licznik == 5) {
		cout << endl<<"________";
		cout << endl << " |/";
		cout << endl << " |";
		cout << endl << " |";
		cout << endl << " |";
		cout << endl << "/ \\";
	}
	if (licznik == 6) {
		cout << endl << "________";
		cout << endl << " |/    |";
		cout << endl << " |";
		cout << endl << " |";
		cout << endl << " |";
		cout << endl << "/ \\";
	}
	if (licznik == 7) {
		cout << endl << "________";
		cout << endl << " |/    |";
		cout << endl << " |    \\";
		cout << endl << " |";
		cout << endl << " |";
		cout << endl << "/ \\";
	}
	if (licznik == 8) {
		cout << endl << "________";
		cout << endl << " |/    |";
		cout << endl << " |    \\O";
		cout << endl << " |";
		cout << endl << " |";
		cout << endl << "/ \\";
	}
	if (licznik == 9) {
		cout << endl << "________";
		cout << endl << " |/    |";
		cout << endl << " |    \\O/";
		cout << endl << " |";
		cout << endl << " |";
		cout << endl << "/ \\";
	}
	if (licznik == 10) {
		cout << endl << "________";
		cout << endl << " |/    |";
		cout << endl << " |    \\O/";
		cout << endl << " |     |";
		cout << endl << " |";
		cout << endl << "/ \\";
	}
	
	if (licznik == 11) {
		cout << endl << "________";
		cout << endl << " |/    |";
		cout << endl << " |    \\O/";
		cout << endl << " |     |";
		cout << endl << " |    /";
		cout << endl << "/ \\";
	}
	if (licznik == 12) {
		cout << endl << "________";
		cout << endl << " |/    |";
		cout << endl << " |    \\O/";
		cout << endl << " |     |";
		cout << endl << " |    / \\";
		cout << endl << "/ \\";
	}
}
string losujZdanie(string zdania[]) {//losuje zdanie
	mt19937 generator(time(nullptr));
	uniform_int_distribution<int> zakres(0, 9);
	return zdania[zakres(generator)];
}
char losujLitere(string alfabet) {//losuje litere z alfabetu
	mt19937 generator(time(nullptr));
	int rozmiar = alfabet.size() - 1;
	
	uniform_int_distribution<int> zakresLiter(0,rozmiar);
	return alfabet[zakresLiter(generator)];
}
char zamienNaMala(char litera) {//zamienia duza litere na mala
	if ((static_cast<int>(litera) >= 65) && (static_cast<int>(litera) <= 90)) {
		litera = static_cast<char>(litera + 32);
	}
	return litera;
}