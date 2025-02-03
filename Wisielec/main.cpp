#include"naglowek.h"
int main() {
	
	char cyfra{ '0' };
			string hasla[10] = {
			"Bez pracy nie ma kolaczy",
			"Co dwie glowy to nie jedna",
			"Lepszy rydz niz nic",
			"Raz na wozie raz pod wozem",
			"Zdrowy jak ryba",
			"Idzie luty podkuj buty",
			"Co dwie glowy, to nie jedna",
			"I wilk syty, i owca cala",
			"Smiech to zdrowie",
			"Serce nie sluga" };
	while (cyfra != '5') {
		cyfra = '0';//menu
		cout << "1. Gra z drug¹ osoba" << endl;
		cout << "2. Gra z komputerem" << endl;
		cout << "3. Gra przeciwko komputerowi" << endl;
		cout << "4. Zasady gry" << endl;
		cout << "5. Koniec" << endl;
		while ((cyfra != '1') && (cyfra != '2') && (cyfra != '3') && (cyfra != '4') && (cyfra != '5')) {
			cout << "Wpisz cyfre od 1 do 5: ";
			cin >> cyfra;
		}
		cin.get();
		wyczysc();
		int licznik{ 0 };
		int licznikKomputera = 0;
		int* wsk2 = &licznikKomputera;
		int* wsk = &licznik;
		string Haslo;
		string HasloKomputera;
		string odgadnieteLitery;
		string odgadnieteLiteryKomputera;
		char litera{};
		if (cyfra == '1') //gra z graczem
		{
			while (Haslo.size() == 0) {//pobiera haslo od gracza
				cout << "podaj haslo (bez polskich znakow): ";
				getline(cin, Haslo);
				cout << endl;
			}
			int rozmiar = Haslo.size();
			for (int i = 0; i < rozmiar; i++) {//wypelnia odgadnieteLitery znakiem "_"
				odgadnieteLitery.push_back('_');
			}
			for (int g = 0; g < rozmiar; g++) {
				if (Haslo[g] == ' ') {//jesli w hasle jest spacja to w to samo miejsce uzupelnia spacje w odgadnietychLiterach
					odgadnieteLitery[g] = ' ';
				}
				if ((static_cast<int>(Haslo[g]) >= 65) && (static_cast<int>(Haslo[g]) <= 90)) {//zamienia duze litery na male
					Haslo[g] = static_cast<char>(Haslo[g] + 32);
				}
			}
			string zgadnijHaslo;
			cout << "jesli chcesz odgadnac haslo wpisz znak \"`\"";
			while ((odgadnieteLitery != Haslo) && (licznik < 12)) {

				cout << endl << "podaj litere: ";
				cin >> litera;

				litera = zamienNaMala(litera);

				cin.get();
				if (litera == '`') {//gdy gracz chce zgadnac haslo 
					cout << "zgadnij haslo: ";
					getline(cin, zgadnijHaslo);
					if (zgadnijHaslo == Haslo) {
						odgadnieteLitery = zgadnijHaslo;
						cout << "Wygrales, haslem bylo " << odgadnieteLitery;
						break;
					}
					else {
						licznik++;
						cout << "niepoprawne haslo";
						continue;
					}
				}
				else {// jesli gracz wpisal zwykla litere
					odgadnieteLitery = sprawdzenieLitery(Haslo, odgadnieteLitery, rozmiar, litera, wsk);//sprawdza czy litera nalezy do hasla
				}
				wyczysc();
				rysuj(licznik);
				cout << endl;
				cout << odgadnieteLitery;

			}
			if (Haslo == odgadnieteLitery) {//gdy gracz zdal wszystkie litery
				cout << endl << "Wygrales, haslem bylo " << odgadnieteLitery << endl;
			}
		}
		else if (cyfra == '2') //gra z komputerem
		{

			string alfabet = "abcdefghijklmnopqrstuvwxyz";


			Haslo = losujZdanie(hasla);
			int rozmiar = Haslo.size();
			for (int i = 0; i < rozmiar; i++) {
				odgadnieteLitery.push_back('_');
			}
			for (int g = 0; g < rozmiar; g++) {
				if (Haslo[g] == ' ') {
					odgadnieteLitery[g] = ' ';
				}
				if ((static_cast<int>(Haslo[g]) >= 65) && (static_cast<int>(Haslo[g]) <= 90)) {
					Haslo[g] = static_cast<char>(Haslo[g] + 32);
				}
			}
			string zgadnijHaslo;
			cout << "jesli chcesz odgadnac haslo wpisz znak \"`\"";
			while ((odgadnieteLitery != Haslo) && (licznik < 12)) {

				cout << endl << "podaj litere: ";
				
				cin >> litera;
				litera = zamienNaMala(litera);


				cin.get();
				if (litera == '`') {
					cout << "zgadnij haslo: ";
					getline(cin, zgadnijHaslo);
					if (zgadnijHaslo == Haslo) {
						odgadnieteLitery = zgadnijHaslo;
						cout << "Wygrales, haslem bylo " << odgadnieteLitery;
						break;
					}
					else {
						licznik++;
						cout << "niepoprawne haslo";
						continue;
					}
				}
				else {
					odgadnieteLitery = sprawdzenieLitery(Haslo, odgadnieteLitery, rozmiar, litera, wsk);
				}
				wyczysc();
				rysuj(licznik);
				cout << endl;
				cout << odgadnieteLitery;
				if (Haslo == odgadnieteLitery) {
					cout << endl << "Wygrales, haslem bylo " << odgadnieteLitery << endl;
					break;
				}
				//tura komputera
				if (alfabet.find(litera) != string::npos) {//sprawdza czy gracz wpisal litere z alfabetu

					alfabet.erase(alfabet.find(litera), 1);//usuwa litere uzyta przez gracza
				}

				litera = losujLitere(alfabet);

				alfabet.erase(alfabet.find(litera), 1);//usuwa litere uzyta przez komputer
				odgadnieteLitery = sprawdzenieLitery(Haslo, odgadnieteLitery, rozmiar, litera, wsk);
				wyczysc();
				rysuj(licznik);
				cout << endl;
				cout << odgadnieteLitery;
				if (Haslo == odgadnieteLitery) {//sprawdza czy komputer zgadl wszystkie litery 

					cout << endl << "Wygral komputer, a haslem bylo: " << odgadnieteLitery << endl;
					break;
				}
			}


		}
		else if (cyfra == '3') //gra przeciwko komputerowi
		{
			
			
			
			
			string alfabet = "abcdefghijklmnopqrstuvwxyz";
			HasloKomputera= losujZdanie(hasla);
			Haslo = losujZdanie(hasla);
			int rozmiar = Haslo.size();
			for (int i = 0; i < rozmiar; i++) {
				odgadnieteLitery.push_back('_');
			}
			for (int g = 0; g < rozmiar; g++) {
				if (Haslo[g] == ' ') {
					odgadnieteLitery[g] = ' ';
				}
				if ((static_cast<int>(Haslo[g]) >= 65) && (static_cast<int>(Haslo[g]) <= 90)) {
					Haslo[g] = static_cast<char>(Haslo[g] + 32);
				}
			}
			for (int i = 0; i < rozmiar; i++) {
				odgadnieteLiteryKomputera.push_back('_');
			}
			for (int g = 0; g < rozmiar; g++) {
				if (HasloKomputera[g] == ' ') {
					odgadnieteLiteryKomputera[g] = ' ';
				}
				if ((static_cast<int>(HasloKomputera[g]) >= 65) && (static_cast<int>(HasloKomputera[g]) <= 90)) {
					HasloKomputera[g] = static_cast<char>(Haslo[g] + 32);
				}
			}
			//gracz
			string zgadnijHaslo;
			cout << "jesli chcesz odgadnac haslo wpisz znak \"`\"";
			while ((odgadnieteLitery != Haslo) && (licznik < 12) && (licznikKomputera < 12) && (odgadnieteLiteryKomputera != HasloKomputera)) {

				cout << endl << "podaj litere: ";
				
				cin >> litera;
				litera = zamienNaMala(litera);


				cin.get();
				if (litera == '`') {
					cout << "zgadnij haslo: ";
					getline(cin, zgadnijHaslo);
					if (zgadnijHaslo == Haslo) {
						odgadnieteLitery = zgadnijHaslo;
						cout << "Wygrales, haslem bylo " << odgadnieteLitery;
						break;
					}
					else {
						licznik++;
						cout << "niepoprawne haslo";
						continue;
					}
				}
				else {
					odgadnieteLitery = sprawdzenieLitery(Haslo, odgadnieteLitery, rozmiar, litera, wsk);
				}
				wyczysc();
				cout << "gracz"<<endl;
				rysuj(licznik);
				cout << endl;
				cout << odgadnieteLitery;
				if (Haslo == odgadnieteLitery) {//sprawdza czy gracz zgadl wszystkie litery 
					cout << endl << "Wygrales, haslem bylo " << odgadnieteLitery << endl;
					cout << "A haslem komputera bylo: " << HasloKomputera<<endl;
					break;
				}
				//komputer
				
				litera = losujLitere(alfabet);//wybiera litere z tych ktore nie zosta³y uzyte
				alfabet.erase(alfabet.find(litera), 1);//usuwa uzyte litery
				odgadnieteLiteryKomputera = sprawdzenieLitery(HasloKomputera, odgadnieteLiteryKomputera, rozmiar, litera, wsk2);//sprawdza czy litera wylosowana 
				cout<<endl<<endl << "komputer" << endl;                                                                        //przez komputer nalezy do hasla
				rysuj(licznikKomputera);
				cout << endl;
				cout << odgadnieteLiteryKomputera;
				if (HasloKomputera == odgadnieteLiteryKomputera) {//sprawdza czy komputer zgadl wszystkie litery 

					cout << endl << "Wygral komputer, a haslem bylo: " << odgadnieteLiteryKomputera << endl;
					cout << "Twoim haslem bylo: " << Haslo<<endl;
					break;
				}
			}
		}
		else if (cyfra == '4') {//zasady
			char czyDalej = '0';
			cout << "Zasady" << endl;
			cout << "Gra w wisielca polega na odgadnieciu hasla zanim caly \"wisielec\" bedzie narysowany, hasla nie zawieraja polskich znakow." << endl;
			cout << "Aby odgadnac wczesniej haslo wpisz znak \"`\" i uzyj tylko malych liter." << endl;
			cout << "W pierwszym trybie jeden gracz podaje haslo a drugi probuje je odgadnac." << endl;
			cout << "W drugim trybie gracz i komputer na zmiane zgaduja wylosowane haslo." << endl;
			cout << "W trzecim trybie gracz i komputer maja osobne hasla i wygrywa ten kto szybciej zgadnie." << endl<<endl;
			cout << "Aby przejsc dalej wpisz 1"<<endl;
			while (czyDalej != '1') {
				cin >> czyDalej;
				cin.get();
			}
			wyczysc();
		}
		else {
			break;
		}
		if (licznikKomputera == 12) {//Gdy przegral komputer
			wyczysc();
			rysuj(licznikKomputera);
			cout << endl << "Komputer przegral,jego haslo to: " << HasloKomputera << endl;
			cout << "ty zgadles te litery: " << odgadnieteLitery << endl;

		}
		if (licznik == 12) {//gdy przegral gracz
			wyczysc();
			rysuj(licznik);
			cout << endl << "przegrales, haslo to: " << Haslo << endl;
			cout << "ty zgadles te litery: " << odgadnieteLitery << endl;

		}
		cout << endl;
	}
}