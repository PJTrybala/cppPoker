#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;


struct Karta0
{
    char kolor;
    string figura;
    int wartosc;
};

bool karty_rowne(Karta0 a, Karta0 b)
{
	if (a.kolor == b.kolor && a.figura == b.figura && a.wartosc == b.wartosc)
	{
		return true;
	}
	else
	{ 
		return false;
	}
}

Karta0 losowanie()
{
	Karta0 karta;
	int z;
	char x;
	z = rand() % 12;
	//string figury[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"};
	int w = rand() % 13 + 1;
	int y = rand() % 4;
	switch(y)
	{
		case 0:
			x = 'T';
			break;
		case 1:
			 x = 'K';
			break;
		case 2:
			 x = 'k';
			break;
		case 3:
			 x = 'P';
			break;
	}
	//karta = x + figury[z];
	
	karta.kolor = x;
	karta.wartosc = w;
	switch(w)
	{
		case 2:
			karta.figura = "2";
			break;
		case 3:
			karta.figura = "3";
			break;
		case 4:
			karta.figura = "4";
			break;
		case 5:
			karta.figura = "5";
			break;
		case 6:
			karta.figura = "6";
			break;
		case 7:
			karta.figura = "7";
			break;
		case 8:
			karta.figura = "8";
			break;
		case 9:
			karta.figura = "9";
			break;
		case 10:
			karta.figura = "T";
			break;
		case 11:
			karta.figura = "J";
			break;
		case 12:
			karta.figura = "Q";
			break;
		case 13:
			karta.figura = "K";
			break;
		case 1:
			karta.figura = "A";
			karta.wartosc = 14;
			break;
	}
	
	return karta;
}

char ruch_pc()
{
	srand(time(NULL));
	int x = rand() % 10 + 0;
	if (x>=0 && x<5)
	{
		return 'Z';
	}
	else if (x>=5 && x<10)
	{
		return 'S';
	}
	else if (x=10)
	{
		return 'P';
	}
}

char ruch_pc1()
{
	srand(time(NULL));
	int x = rand() % 10 + 0;
	if (x>=1 && x<6)
	{
		return 'S';
	}
	else if (x<=10 && x>=6)
	{
		return 'P';
	}
}

int tura(int &monety_gracza, int &monety_pc1, int &monety_pc2, int &pula)
{
	srand(time(NULL));
	int stawka = 0;
	int akcja;
	int akcja1;
	int akcja2;
	int akcja3;
	char akcja_gracza;
	char akcja_pc1='N';
	char akcja_pc2='N';
	
	while(akcja!='S')
	{
		if (akcja_gracza!='P')
		{
			cout << "Co robisz? (Z - zwiekszenie, S - sprawdzenie, P -  pas): ";
			cin >> akcja_gracza;
		}
		while (akcja_gracza == 'Z')
		{
			akcja1=0;
			if (akcja_pc1=='z' && akcja_pc2=='z' && monety_gracza>=3)
			{
				stawka++;
				pula+=3;
				monety_gracza-=3;
				cout << "Dolozyles 3 (aktualna stawka: " << stawka << ")" << endl;
				akcja_gracza = 'z';
			}
			else if ((akcja_pc1=='z' || akcja_pc2=='z') && monety_gracza>=2)
			{
				stawka++;
				pula+=2;
				monety_gracza-=2;
				cout << "Dolozyles 2 (aktualna stawka: " << stawka << ")" << endl;
				akcja_gracza = 'z';
			}
			else if (akcja_pc1=='s' && akcja_pc2=='s' && monety_gracza>=1)
			{
				stawka++;
				pula++;
				monety_gracza--;
				cout << "Dolozyles 1 (aktualna stawka: " << stawka << ")" << endl;
				akcja_gracza = 'z';
			}
			else if((akcja_pc1=='P' || akcja_pc2=='P' || akcja_pc1=='N' || akcja_pc2=='N') && monety_gracza>=1)
			{
				stawka++;
				pula++;
				monety_gracza--;
				cout << "Dolozyles 1 (aktualna stawka: " << stawka << ")" << endl;
				akcja_gracza = 'z';
			}
			else
			{
				cout << "Brakuje ci monet, (" << monety_gracza << ") wybierz jeszcze raz: ";
				cin >> akcja_gracza;
			}
		}
		while (akcja_gracza == 'S')
		{
			akcja1=1;
			if (akcja_pc1=='z' && akcja_pc2=='z' && monety_gracza>=2)
			{
				pula+=2;
				monety_gracza-=2;
				cout << "Dolozyles 2 (aktualna stawka: " << stawka << ")" << endl;
				akcja_gracza = 's';
			}
			else if ((akcja_pc1=='z' || akcja_pc2=='z') && monety_gracza>=1)
			{
				pula++;
				monety_gracza--;
				cout << "Dolozyles 1 (aktualna stawka: " << stawka << ")" << endl;
				akcja_gracza = 's';
			}
			else if (akcja_pc1=='s' && akcja_pc2=='s')
			{
				cout << "Czekasz (aktualna stawka: " << stawka << ")" << endl;
				akcja_gracza = 's';
			}
			else if(akcja_pc1=='P' || akcja_pc2=='P' || akcja_pc1=='N' || akcja_pc2=='N')
			{
				cout << "Czekasz (aktualna stawka: " << stawka << ")" << endl;
				akcja_gracza = 's';
			}
			else
			{
				cout << "Brakuje ci monet, (" << monety_gracza << ") wybierz jeszcze raz: ";
				cin >> akcja_gracza;
			}
		}
		if (akcja_gracza == 'P')
		{
			akcja1=1;
			cout << "Spasowales"<< endl;
		}
		
		if (akcja1==1 && akcja2==1 && akcja3==1)
		{
			return stawka;
		}
		

		if (akcja_pc1!='P')
		{
			akcja_pc1 = ruch_pc();
		}
		
		while (akcja_pc1 == 'Z')
		{
			akcja2=0;
			if (akcja_gracza=='z' && akcja_pc2=='z' && monety_pc1>=3)
			{
				stawka++;
				pula+=3;
				monety_pc1-=3;
				cout << "Komputer 1 dolozyl 3 (aktualna stawka: " << stawka << ")" << endl;
				akcja_pc1 = 'z';
			}
			else if ((akcja_gracza=='z' || akcja_pc2=='z') && monety_pc1>=2)
			{
				stawka++;
				pula+=2;
				monety_pc1-=2;
				cout << "Komputer 1 dolozyl 2 (aktualna stawka: " << stawka << ")" << endl;
				akcja_pc1 = 'z';
			}
			else if (akcja_gracza=='s' && akcja_pc2=='s' && monety_pc1>=1)
			{
				stawka++;
				pula++;
				monety_pc1--;
				cout << "Komputer 1 dolozyl 1 (aktualna stawka: " << stawka << ")" << endl;
				akcja_pc1 = 'z';
			}
			else if((akcja_gracza=='P' && akcja_pc2=='s' || akcja_pc2=='P' && akcja_gracza=='s' || akcja_gracza=='N' || akcja_pc2=='N') && monety_pc1>=1)
			{
				stawka++;
				pula++;
				monety_pc1--;
				cout << "Komputer 1 dolozyl 1 (aktualna stawka: " << stawka << ")" << endl;
				akcja_pc1 = 'z';
			}
			else
			{
				akcja_pc1 = ruch_pc();
			}
		}
		while (akcja_pc1 == 'S')
		{
			cout << monety_pc1 << " ";
			akcja2=1;
			if (akcja_gracza=='z' && akcja_pc2=='z' && monety_pc1>=2)
			{
				pula+=2;
				monety_pc1-=2;
				cout << "Komputer 1 dolozyl 2 (aktualna stawka: " << stawka << ")" << endl;
				akcja_pc1 = 's';
			}
			else if ((akcja_gracza=='z' || akcja_pc2=='z') && monety_pc1>=1)
			{
				pula++;
				monety_pc1--;
				cout << "Komputer 1 dolozyl 1 (aktualna stawka: " << stawka << ")" << endl;
				akcja_pc1 = 's';
			}
			else if (akcja_gracza=='s' && akcja_pc2=='s')
			{
				cout << "Komputer 1 czeka (aktualna stawka: " << stawka << ")" << endl;
				akcja_pc1 = 's';
			}
			else if(akcja_gracza=='P' && akcja_pc2=='S' || akcja_pc2=='P' && akcja_gracza=='S' || akcja_pc2=='N' && akcja_gracza=='S')
			{
				cout << "Komputer 1 czeka (aktualna stawka: " << stawka << ")" << endl;
				akcja_pc1 = 's';
			}
			else
			{
				akcja_pc1 = ruch_pc1();
			}
		}
		if (akcja_pc1== 'P')
		{
			akcja2=1;
			cout << "Komputer 1 spasowal" << endl;
		}
		
		if (akcja1==1 && akcja2==1 && akcja3==1)
		{
			return stawka;
		}
		
		if (akcja_pc2!='P')
		{
			akcja_pc2 = ruch_pc();
		}
		
		while (akcja_pc2 == 'Z')
		{
			akcja3=0;
			if (akcja_pc1=='z' && akcja_gracza=='z' && monety_pc2>=3)
			{
				stawka++;
				pula+=3;
				monety_pc2-=3;
				cout << "Komputer 2 dolozyl 3 (aktualna stawka: " << stawka << ")" << endl;
				akcja_pc2 = 'z';
			}
			else if ((akcja_pc1=='z' || akcja_gracza=='z') && monety_pc2>=2)
			{
				stawka++;
				pula+=2;
				monety_pc2-=2;
				cout << "Komputer 2 dolozyl 2 (aktualna stawka: " << stawka << ")" << endl;
				akcja_pc2 = 'z';
			}
			else if (akcja_pc1=='s' && akcja_gracza=='s' && monety_pc2>=1)
			{
				stawka++;
				pula++;
				monety_pc2--;
				cout << "Komputer 2 dolozyl 1 (aktualna stawka: " << stawka << ")" << endl;
				akcja_pc2 = 'z';
			}
			else if((akcja_pc1=='P' || akcja_gracza=='P' || akcja_pc1=='N') && monety_pc2>=1)
			{
				stawka++;
				pula++;
				monety_pc2--;
				cout << "Komputer 2 dolozyl 1 (aktualna stawka: " << stawka << ")" << endl;
				akcja_pc2 = 'z';
			}
			else
			{
				akcja_pc2 = ruch_pc();
			}
		}
		while (akcja_pc2 == 'S')
		{
			akcja3=1;
			if (akcja_pc1=='z' && akcja_pc2=='z' && monety_pc2>=2)
			{
				pula+=2;
				monety_pc2-=2;
				cout << "Komputer 2 dolozyl 2 (aktualna stawka: " << stawka << ")" << endl;
				akcja_pc2 = 's';
			}
			else if ((akcja_pc1=='z' || akcja_pc2=='z') && monety_pc2>=1)
			{
				pula++;
				monety_pc2--;
				cout << "Komputer2 dolozyl 1 (aktualna stawka: " << stawka << ")" << endl;
				akcja_pc2 = 's';
			}
			else if (akcja_pc1=='s' && akcja_pc2=='s')
			{
				cout << "Komputer 2 czeka (aktualna stawka: " << stawka << ")" << endl;
				akcja_pc2 = 's';
			}
			else if(akcja_gracza=='P' && akcja_pc1=='S' || akcja_pc1=='P' && akcja_gracza=='S' || akcja_pc1=='N' && akcja_gracza=='S')
			{
				cout << "Komputer 2 czeka (aktualna stawka: " << stawka << ")" << endl;
				akcja_pc2 = 's';
			}
			else
			{
				akcja_pc2 = ruch_pc1();
			}
		}
		if (akcja_pc2=='P')
		{
			akcja3=1;
			cout << "Komputer 2 spasowal" << endl;
		}
		
		if (akcja1==1 && akcja2==1 && akcja3==1)
		{
			return stawka;
		}
		cout << endl;
	}
	return stawka;
}

void sortowanie_babelkowe(Karta0 tab[5])
{
	for(int i=0;i<5;i++)
		for(int j=1;j<5-i;j++) //pêtla wewnêtrzna
		if(tab[j-1].wartosc>tab[j].wartosc)
			//zamiana miejscami
			swap(tab[j-1], tab[j]);
}

int main()
{
	Karta0 tab[5];
	srand(time(NULL));
	Karta0 karta;
	Karta0 twoje_karty[5];
	Karta0 pc1_karty[5];
	Karta0 pc2_karty[5];
	Karta0 stol_karty[3];
	Karta0 wylosowane[9];
	int monety_gracza = 30;
	int monety_pc1 = 30;
	int monety_pc2 = 30;
	int stawka = 0;
	int pula =0;
	int j=0;
	int k=0;
	int twoj_uklad=0;
	int pc1_uklad=0;
	int pc2_uklad=0;
	
	for (int i=0; i<=1; i++)
	{
		twoje_karty[i] = losowanie();
		for (j=0; j<9; j++)
		{
			while (karty_rowne(wylosowane[j], twoje_karty[i]))
			{
		    	twoje_karty[i] = losowanie();
			}
		}
		wylosowane[k]=twoje_karty[i];
		k++;
	}
	
	for (int i=0; i<=1; i++)
	{
		pc1_karty[i] = losowanie();
		for (j=0; j<9; j++)
		{
			while (karty_rowne(wylosowane[j], pc1_karty[i]))
			{
			pc1_karty[i] = losowanie();
			}
		}
		wylosowane[k]=pc1_karty[i];
		k++;
	}
	
	for (int i=0; i<=1; i++)
	{
		pc2_karty[i] = losowanie();
		for (j=0; j<9; j++)
		{
			while (karty_rowne(wylosowane[j], pc2_karty[i]))
			{
			pc2_karty[i] = losowanie();
			}
		}
		wylosowane[k]=pc2_karty[i];
		k++;
	}
	
	
	for (int i=0; i<=2; i++)
	{
		stol_karty[i] = losowanie();
		for (j=0; j<9; j++)
		{
			while (karty_rowne(wylosowane[j], stol_karty[i]))
			{
			stol_karty[i] = losowanie();
			}
		}
		wylosowane[k]=stol_karty[i];
		k++;
	}
	

	cout << "Twoje karty: " << twoje_karty[0].kolor << twoje_karty[0].figura << ", " << twoje_karty[1].kolor << twoje_karty[1].figura << endl;
	
	for (int i=2; i<5; i++)
	{
		twoje_karty[i]=stol_karty[i-2];
		pc1_karty[i]=stol_karty[i-2];
		pc2_karty[i]=stol_karty[i-2];
	}
	
	//sortowanie();
	
	stawka = tura(monety_gracza, monety_pc1, monety_pc2, pula);
	
	cout << "Karty na stole: " << stol_karty[0].kolor << stol_karty[0].figura << ", " << stol_karty[1].kolor << stol_karty[1].figura << ", " << stol_karty[2].kolor << stol_karty[2].figura << endl;
	
	stawka = stawka+tura(monety_gracza, monety_pc1, monety_pc2, pula);
	
//	tab = twoje_karty;
	
	sortowanie_babelkowe(twoje_karty);
	sortowanie_babelkowe(pc1_karty);
	sortowanie_babelkowe(pc2_karty);
	
	
	for(int i=0; i<5; i++)
	{
		cout << twoje_karty[i].kolor << twoje_karty[i].figura << " " <<twoje_karty[i].wartosc << endl;
	}
	
	
	
	
	
	if(twoje_karty[0].kolor==twoje_karty[1].kolor&&twoje_karty[0].kolor==twoje_karty[2].kolor&&twoje_karty[0].kolor==twoje_karty[3].kolor&&twoje_karty[0].kolor==twoje_karty[4].kolor)
	{
		twoj_uklad=5; //kolor
		if(twoje_karty[0].wartosc+twoje_karty[1].wartosc+twoje_karty[2].wartosc+twoje_karty[3].wartosc+twoje_karty[4].wartosc==60)
		{
	    	twoj_uklad=1; //poker krolewski
		}
		else if (twoje_karty[0].wartosc+1==twoje_karty[1].wartosc&&twoje_karty[1].wartosc+1==twoje_karty[2].wartosc&&twoje_karty[2].wartosc+1==twoje_karty[3].wartosc&&twoje_karty[3].wartosc+1==twoje_karty[4].wartosc)
		{
			twoj_uklad=2; // strit w kolorze
		}
	}
	else if(twoje_karty[0].wartosc==twoje_karty[1].wartosc&&twoje_karty[1].wartosc==twoje_karty[2].wartosc&&twoje_karty[2].wartosc==twoje_karty[3].wartosc||twoje_karty[1].wartosc==twoje_karty[2].wartosc&&twoje_karty[2].wartosc==twoje_karty[3].wartosc&&twoje_karty[3].wartosc==twoje_karty[4].wartosc)
	{
		twoj_uklad=3; //kareta
	}
	else if(twoje_karty[0].wartosc==twoje_karty[1].wartosc&&twoje_karty[1].wartosc==twoje_karty[2].wartosc||twoje_karty[1].wartosc==twoje_karty[2].wartosc&&twoje_karty[2].wartosc==twoje_karty[3].wartosc||twoje_karty[2].wartosc==twoje_karty[3].wartosc&&twoje_karty[3].wartosc==twoje_karty[4].wartosc)
	{
		twoj_uklad=7; //trojka
		
		if(twoje_karty[0].wartosc==twoje_karty[1].wartosc&&twoje_karty[1].wartosc==twoje_karty[2].wartosc&&twoje_karty[3].wartosc==twoje_karty[4].wartosc||twoje_karty[1].wartosc==twoje_karty[2].wartosc&&twoje_karty[2].wartosc==twoje_karty[3].wartosc&&twoje_karty[4].wartosc==twoje_karty[0].wartosc||twoje_karty[2].wartosc==twoje_karty[3].wartosc&&twoje_karty[3].wartosc==twoje_karty[4].wartosc&&twoje_karty[0].wartosc==twoje_karty[1].wartosc)
		{
			twoj_uklad=4; //full
		}
	}
	else if(twoje_karty[0].wartosc==twoje_karty[1].wartosc)
	{
		twoj_uklad=9; //para
		if(twoje_karty[2].wartosc==twoje_karty[3].wartosc||twoje_karty[3].wartosc==twoje_karty[4].wartosc)
		{
			twoj_uklad=8; //dwie pary
		}
	}
	else if(twoje_karty[1].wartosc==twoje_karty[2].wartosc)
	{
		twoj_uklad=9; //para
		if(twoje_karty[3].wartosc==twoje_karty[4].wartosc)
		{
			twoj_uklad=8; //dwie pary
		}
	}
	else if(twoje_karty[2].wartosc==twoje_karty[3].wartosc)
	{
		twoj_uklad=9; //para
	}
	else if(twoje_karty[3].wartosc==twoje_karty[4].wartosc)
	{
		twoj_uklad=9; //para
	}
	else if(twoje_karty[0].wartosc+1==twoje_karty[1].wartosc&&twoje_karty[1].wartosc+1==twoje_karty[2].wartosc&&twoje_karty[2].wartosc+1==twoje_karty[3].wartosc&&twoje_karty[3].wartosc+1==twoje_karty[4].wartosc)
	{
		twoj_uklad=6; //strit
	}
	else
	{
		twoj_uklad=10; //wysoka karta
	}
	
	cout << twoj_uklad<<endl;
	
		
	if(pc1_karty[0].kolor==pc1_karty[1].kolor&&pc1_karty[0].kolor==pc1_karty[2].kolor&&pc1_karty[0].kolor==pc1_karty[3].kolor&&pc1_karty[0].kolor==pc1_karty[4].kolor)
	{
		pc1_uklad=5; //kolor
		if(pc1_karty[0].wartosc+pc1_karty[1].wartosc+pc1_karty[2].wartosc+pc1_karty[3].wartosc+pc1_karty[4].wartosc==60)
		{
	    	pc1_uklad=1; //poker krolewski
		}
		else if (pc1_karty[0].wartosc+1==pc1_karty[1].wartosc&&pc1_karty[1].wartosc+1==pc1_karty[2].wartosc&&pc1_karty[2].wartosc+1==pc1_karty[3].wartosc&&pc1_karty[3].wartosc+1==pc1_karty[4].wartosc)
		{
			pc1_uklad=2; // strit w kolorze
		}
	}
	else if(pc1_karty[0].wartosc==pc1_karty[1].wartosc&&pc1_karty[1].wartosc==pc1_karty[2].wartosc&&pc1_karty[2].wartosc==pc1_karty[3].wartosc||pc1_karty[1].wartosc==pc1_karty[2].wartosc&&pc1_karty[2].wartosc==pc1_karty[3].wartosc&&pc1_karty[3].wartosc==pc1_karty[4].wartosc)
	{
		pc1_uklad=3; //kareta
	}
	else if(pc1_karty[0].wartosc==pc1_karty[1].wartosc&&pc1_karty[1].wartosc==pc1_karty[2].wartosc||pc1_karty[1].wartosc==pc1_karty[2].wartosc&&pc1_karty[2].wartosc==pc1_karty[3].wartosc||pc1_karty[2].wartosc==pc1_karty[3].wartosc&&pc1_karty[3].wartosc==pc1_karty[4].wartosc)
	{
		pc1_uklad=7; //trojka
		
		if(pc1_karty[0].wartosc==pc1_karty[1].wartosc&&pc1_karty[1].wartosc==pc1_karty[2].wartosc&&pc1_karty[3].wartosc==pc1_karty[4].wartosc||pc1_karty[1].wartosc==pc1_karty[2].wartosc&&pc1_karty[2].wartosc==pc1_karty[3].wartosc&&pc1_karty[4].wartosc==pc1_karty[0].wartosc||pc1_karty[2].wartosc==pc1_karty[3].wartosc&&pc1_karty[3].wartosc==pc1_karty[4].wartosc&&pc1_karty[0].wartosc==pc1_karty[1].wartosc)
		{
			pc1_uklad=4; //full
		}
	}
	else if(pc1_karty[0].wartosc==pc1_karty[1].wartosc)
	{
		pc1_uklad=9; //para
		if(pc1_karty[2].wartosc==pc1_karty[3].wartosc||pc1_karty[3].wartosc==pc1_karty[4].wartosc)
		{
			pc1_uklad=8; //dwie pary
		}
	}
	else if(pc1_karty[1].wartosc==pc1_karty[2].wartosc)
	{
		pc1_uklad=9; //para
		if(pc1_karty[3].wartosc==pc1_karty[4].wartosc)
		{
			pc1_uklad=8; //dwie pary
		}
	}
	else if(pc1_karty[2].wartosc==pc1_karty[3].wartosc)
	{
		pc1_uklad=9; //para
	}
	else if(pc1_karty[3].wartosc==pc1_karty[4].wartosc)
	{
		pc1_uklad=9; //para
	}
	else if(pc1_karty[0].wartosc+1==pc1_karty[1].wartosc&&pc1_karty[1].wartosc+1==pc1_karty[2].wartosc&&pc1_karty[2].wartosc+1==pc1_karty[3].wartosc&&pc1_karty[3].wartosc+1==pc1_karty[4].wartosc)
	{
		pc1_uklad=6; //strit
	}
	else
	{
		pc1_uklad=10; //wysoka karta
	}
	
	for(int i=0; i<5; i++)
	{
		cout << pc1_karty[i].kolor << pc1_karty[i].figura << " " <<pc1_karty[i].wartosc << endl;
	}
	cout << pc1_uklad<<endl;
	
		
	if(pc2_karty[0].kolor==pc2_karty[1].kolor&&pc2_karty[0].kolor==pc2_karty[2].kolor&&pc2_karty[0].kolor==pc2_karty[3].kolor&&pc2_karty[0].kolor==pc2_karty[4].kolor)
	{
		pc2_uklad=5; //kolor
		if(pc2_karty[0].wartosc+pc2_karty[1].wartosc+pc2_karty[2].wartosc+pc2_karty[3].wartosc+pc2_karty[4].wartosc==60)
		{
	    	pc2_uklad=1; //poker krolewski
		}
		else if (pc2_karty[0].wartosc+1==pc2_karty[1].wartosc&&pc2_karty[1].wartosc+1==pc2_karty[2].wartosc&&pc2_karty[2].wartosc+1==pc2_karty[3].wartosc&&pc2_karty[3].wartosc+1==pc2_karty[4].wartosc)
		{
			pc2_uklad=2; // strit w kolorze
		}
	}
	else if(pc2_karty[0].wartosc==pc2_karty[1].wartosc&&pc2_karty[1].wartosc==pc2_karty[2].wartosc&&pc2_karty[2].wartosc==pc2_karty[3].wartosc||pc2_karty[1].wartosc==pc2_karty[2].wartosc&&pc2_karty[2].wartosc==pc2_karty[3].wartosc&&pc2_karty[3].wartosc==pc2_karty[4].wartosc)
	{
		pc2_uklad=3; //kareta
	}
	else if(pc2_karty[0].wartosc==pc2_karty[1].wartosc&&pc2_karty[1].wartosc==pc2_karty[2].wartosc||pc2_karty[1].wartosc==pc2_karty[2].wartosc&&pc2_karty[2].wartosc==pc2_karty[3].wartosc||pc2_karty[2].wartosc==pc2_karty[3].wartosc&&pc2_karty[3].wartosc==pc2_karty[4].wartosc)
	{
		pc2_uklad=7; //trojka
		
		if(pc2_karty[0].wartosc==pc2_karty[1].wartosc&&pc2_karty[1].wartosc==pc2_karty[2].wartosc&&pc2_karty[3].wartosc==pc2_karty[4].wartosc||pc2_karty[1].wartosc==pc2_karty[2].wartosc&&pc2_karty[2].wartosc==pc2_karty[3].wartosc&&pc2_karty[4].wartosc==pc2_karty[0].wartosc||pc2_karty[2].wartosc==pc2_karty[3].wartosc&&pc2_karty[3].wartosc==pc2_karty[4].wartosc&&pc2_karty[0].wartosc==pc2_karty[1].wartosc)
		{
			pc2_uklad=4; //full
		}
	}
	else if(pc2_karty[0].wartosc==pc2_karty[1].wartosc)
	{
		pc2_uklad=9; //para
		if(pc2_karty[2].wartosc==pc2_karty[3].wartosc||pc2_karty[3].wartosc==pc2_karty[4].wartosc)
		{
			pc2_uklad=8; //dwie pary
		}
	}
	else if(pc2_karty[1].wartosc==pc2_karty[2].wartosc)
	{
		pc2_uklad=9; //para
		if(pc2_karty[3].wartosc==pc2_karty[4].wartosc)
		{
			pc2_uklad=8; //dwie pary
		}
	}
	else if(pc2_karty[2].wartosc==pc2_karty[3].wartosc)
	{
		pc2_uklad=9; //para
	}
	else if(pc2_karty[3].wartosc==pc2_karty[4].wartosc)
	{
		pc2_uklad=9; //para
	}
	else if(pc2_karty[0].wartosc+1==pc2_karty[1].wartosc&&pc2_karty[1].wartosc+1==pc2_karty[2].wartosc&&pc2_karty[2].wartosc+1==pc2_karty[3].wartosc&&pc2_karty[3].wartosc+1==pc2_karty[4].wartosc)
	{
		pc2_uklad=6; //strit
	}
	else
	{
		pc2_uklad=10; //wysoka karta
	}
	
	for(int i=0; i<5; i++)
	{
		cout << pc2_karty[i].kolor << pc2_karty[i].figura << " " <<pc2_karty[i].wartosc << endl;
	}
	
	cout << pc2_uklad;
	
	if(twoj_uklad>pc1_uklad&&twoj_uklad>pc2_uklad)
	{
		monety_gracza+=pula;
		cout<<"Wygrales!!! Masz teraz: "<< monety_gracza << endl;
	}
	
	else if(pc1_uklad>twoj_uklad&&pc1_uklad>pc2_uklad)
	{
		monety_pc1+=pula;
		cout<<"Wygral komputer 1. Ma teraz: "<< monety_pc1 << endl;
	}
	
	else if(pc2_uklad>twoj_uklad&&pc2_uklad>pc1_uklad)
	{
		monety_pc2+=pula;
		cout<<"Wygral komputer 2. Ma teraz: "<< monety_pc2 << endl;
	}
	else if(twoj_uklad=pc1_uklad)
	{
		if(twoje_karty[4].wartosc>pc1_karty[4].wartosc)
		{
			monety_gracza+=pula;
			cout<<"Wygrales!!! Masz teraz: "<< monety_gracza << endl;
		}
		else if(twoje_karty[4].wartosc<pc1_karty[4].wartosc)
		{
		monety_pc1+=pula;
		cout<<"Wygral komputer 1. Ma teraz: "<< monety_pc1 << endl;
		}
		else
		{
			monety_gracza+=pula/2;
			monety_pc1+=pula/2;
			cout << "Remis gracza z komputerem 1, dzielicie pule na pol, masz teraz: "<< monety_gracza;
		}
	}
	else if(twoj_uklad=pc2_uklad)
	{
		if(twoje_karty[4].wartosc>pc2_karty[4].wartosc)
		{
			monety_gracza+=pula;
			cout<<"Wygrales!!! Masz teraz: "<< monety_gracza << endl;
		}
		else if(twoje_karty[4].wartosc<pc2_karty[4].wartosc)
		{
		monety_pc2+=pula;
		cout<<"Wygral komputer 2. Ma teraz: "<< monety_pc2 << endl;
		}
		else
		{
			monety_gracza+=pula/2;
			monety_pc2+=pula/2;
			cout << "Remis gracza z komputerem 2, dzielicie pule na pol, masz teraz: "<< monety_gracza;
		}
	}
	else if(pc2_uklad=pc1_uklad)
	{
		if(pc2_karty[4].wartosc>pc1_karty[4].wartosc)
		{
			monety_pc2+=pula;
			cout<<"Wygral komputer 2. Ma teraz: "<< monety_pc2 << endl;
		}
		else if(pc2_karty[4].wartosc<pc1_karty[4].wartosc)
		{
		monety_pc1+=pula;
		cout<<"Wygral komputer 1. Ma teraz: "<< monety_pc1 << endl;
		}
		else
		{
			monety_pc2+=pula/2;
			monety_pc1+=pula/2;
			cout << "Remis komputera 1 z komputerem 2, dziela pule na pol, maja teraz: "<< monety_pc2;
		}
	}
	
	return 0;
}
