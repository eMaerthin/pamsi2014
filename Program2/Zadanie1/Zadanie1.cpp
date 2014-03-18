#include <iostream>


using namespace std;

template <class T>
class Stos {

        Stos *next;		//zmienna wskaznikowa wskazujaca na nastepny element
        T dana; 		//zmienna okreslonego typu przechowujaca wartosc
		int rozmiar;	//zmienna sluzaca do lczenia rozmiaru stosu
		


    public:
		void DodajElementNaPoczatek(T item);		
        void WyswietlListe();						//metody pozwalajace na podstawowe operacje na stosie
        void UsunElementZPrzodu();
		void menu();

 		Stos(){next=0;}  //konstruktor bezparametryczny zerujacy zmienna wskaznikowa
        Stos(T item, Stos* n){dana=item; next=n;}  //konstruktor parametryczny inicjalizujacy zmienne zadanymi parametrami
		virtual ~Stos(){}  //destruktor
    };


template <class T>
void Stos<T>::DodajElementNaPoczatek(T item)
{
    
    if(next==0)
        next=new Stos(item,0);		//gdy dodajemy pierwszy element
    else
        next=new Stos(item,next);	//gdy kolejny
	
	rozmiar++;	//inkrementacja licznika
}




template <class T>
void Stos<T>::UsunElementZPrzodu()
{
	
    if(next!=0)
    {
        Stos *wsk=next;			//tworzymy zmienna wskaznikowa, dzieki ktorej mozna przesunac drugi elemnt na pierwsza pozycje
        Stos *usuwany=wsk->next;

        wsk->next=usuwany->next;
        delete usuwany;
    }else{
        cout<<"Stos jest pusty "<<endl;
		 }

	rozmiar--;	//dekrementacja licznika
}


template <class T>
void Stos<T>::WyswietlListe()
{
    for(Stos *s=next; s!=0; s=s->next)	//zaczynamy od pierwwzego elementu i po przejsciu petli przechodzimy do nastepnego
        if(next!=0)
		{
           cout<< s->dana <<endl;
		}
        else
            cout<<"Stos jest pusty"<<endl;

}

template <class T>
void Stos<T>::menu()
{
	int opcja;
	rozmiar=0;

	do{
		cout << "\n1.Dodaj element na poczatek"<<endl;
		cout << "2.Usun element z poczatku"<<endl;
		cout << "3.Wyswietl stos"<<endl;
		cout << "0.Koniec"<<endl;

		cout << "Wybierz opcje\n";
		cin >> opcja;

		switch(opcja)
		{
			case 0: break;
			case 1:
				T n;
                cout << "\nWpisz element, ktory chcesz dodac:"<<endl;
                cin >> n;
                DodajElementNaPoczatek(n);
                break;
			case 2:
				UsunElementZPrzodu(); 
				break;
			case 3:
				cout<<"\nZawartosc stosu: "<<endl;
				WyswietlListe();
				cout<<"Rozmiar stosu: "<<rozmiar<<endl;
				break;
		}

	}while(opcja !=0);

}



int main()
{
	
    Stos<int> st;	//tworzymy instancje klasy, przez ktora wywolujemy funkcje

    st.menu();		//wywolanie menu




    return 0;
}


