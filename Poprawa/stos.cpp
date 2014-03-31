#include<iostream>

using namespace std;

template <class T> class stos
{
public : 
	T *a; 
	int top = NULL;
	int rozmiar;

	stos()
	{
		top=-1;
		cout<<"\n Wprowadz rozmiar stosu :"<<endl; 
		cin>>rozmiar; a=new T[rozmiar];
	}

	// Sprawdza czy stos jest pelny
	//------------------------------------------------------------
	int czyPelny() 
	{
		if(top==(rozmiar-1))
			return 1; 
		else return 0;
	}

	// Sprawdza czy stos jest pusty
	//--------------------------------------------------------------
	int czyPusty()
	{
		if(top==-1)
			return 1; 
		else return 0;
	}

	// Umieszcza element na stosie
	//----------------------------------------------------------------
	void push()
	{
		T n;
		if(czyPelny())
			cout<<"\n Stos przepelniony"<<endl;
		else 
		{
			cout<<"\n Wprowadz element"<<endl; 
			cin >> n;
			a[top++] = n;
			cout << "\nElement umieszczony na stosie" << endl;
		}
	}

	// Sciaga element ze stosu
	//----------------------------------------------------------------
	void pop() 
	{
		if(czyPusty()) 
			cout<<"\n Stos jest pusty!"<<endl;
		else top=top-1;
		cout<<"\n Element sciagniety ze stosu"<<endl; 
	}

	//Wyswietla stos
	//---------------------------------------------------------------
	void Wyswietl()
	{
		int rozmiar2;
		rozmiar2 = rozmiar;
		cout << "Elementy stosu: " << " ";
		for (int i = rozmiar2; i > 0; i--)
		{
			cout << a[top-1] << " ";
			top = top - 1;
			rozmiar2--;
			if (rozmiar2 == 0) cout << endl;
		}
	}

};

int main()
{
	stos <int>s; 
	int i=0,k;
	while(i!=1)
	{
		cout<<"\n******************M E N U**************\n"; 
		cout<<"1. Poloz\n2. Sciagnij\n3. Wyswietl\n4. Koniec\n";
		cout<<"\n***************************************\n";
		cout<<"\n Wybierz opcje "; 
		cin>>k;
		switch(k)
		{
		case 1: s.push();
			break;
		case 2: s.pop(); 
			break; 
		case 3: s.Wyswietl();
			break;
		case 4: i=1;
			break; 
		default : cout<<"\n------- Zla opcja -------\n";
			break;
		}
	} return 0;
}