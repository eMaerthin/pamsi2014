#include <iostream>

using namespace std;
template <class type>
struct Element
{
	type value;
	Element* next;
	Element* prev;
};

template <class type>
class Stack
{
	Element<type>* first;
	Element<type>* last;
	
	public:
		Stack()
		{
			first = NULL;
			last = NULL;
		}
		
		// dodaj element na poczatek listy
		void addFirstElement(type el)
		{
			Element<type>* e = new Element<type>();
			
			e->value = el;
			e->next = first;
			e->prev = NULL;
			if(first)
				first->prev = e;
			else
				last = e;
			first = e;
		}
		
		//dodawanie elemntu na koniec listy
		void addLastElement(type el)
		{
			Element<type>* e = new Element<type>();
			
			e->value = el;
			e->next = NULL;
			e->prev = last;
			if(last)
				last->next = e;
			else
				first = e;
			last = e;
		}
		
		//usuniecie pierwszego elementu z przodu listy
		void removeFirstElement()
		{
			Element<type>* k = first;
			if(first)
			{
				first = first->next;
				if(first)
					first->prev = NULL;
			}
			delete k;
		}
		
		//usuniecie elementu z konca listy
		void removeLastElement()
		{
			Element<type>* k = last;
			if(last)
			{
				last = last->prev;
				if(last)
					last->next = NULL;
			}
			delete k;
		}
		
		//wyswietlenie listy
		void showList()
		{
			Element<type>* k = first;
			while(k != NULL)
			{
				cout<<k->value<<endl;
				k = k->next;
			}
		}
		
		//wyswietlenie rozmiaru listy
		int getSize()
		{
			Element<type>* k = first;
			int size = 0;
			while(k != NULL)
			{
				size++;
				k = k->next;
			}
			return size;
		}
};

int main()
{
	Stack<float> s;
	s.addFirstElement(3.5);
	s.addLastElement(8);
	s.addFirstElement(5);
	s.removeFirstElement();
	s.addFirstElement(11);
	//s.removeLastElement();
	cout<<"Rozmiar: "<<s.getSize()<<endl;
	s.showList();
	
	system("PAUSE");
	return 0;
}
