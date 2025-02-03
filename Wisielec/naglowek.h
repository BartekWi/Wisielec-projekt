#pragma once
#include<random>
#include<string>
#include<iostream>
using namespace std;
void wyczysc();//usuwa zawartosc konsoli
char zamienNaMala(char litera);//zamienia duza litere na mala
char losujLitere(string alfabet);//losuje litere z alfabetu
string sprawdzenieLitery(string Fraza, string odgadniete, int rozmiar,char litera,int* wsk);//sprawdza czy litera nalezy do hasla(frazy), jesli nie to zwieksza licznik
void rysuj(int licznik);//rysuje wisielca w zaleznosci od ilosci popelnionych bledow
string losujZdanie(string zdania[]);//losuje zdanie