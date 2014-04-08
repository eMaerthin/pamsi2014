#include <iostream>

using namespace std;
template <class type>
struct Element
{
	type value;
	Element* next;
};

template <class type>
class Stack
{
	Element<type>* first;
	
	public:
		Stack()
		{
			first = NULL;
		}
		
		//dodaj element na poczatku
		void addElement(type el)
		{
			Element<type>* e = new Element<type>();
			e->value = el;
			e->next = first;
			first = e;
		}
		
		//usun element na poczatku
		void removeElement()
		{
			Element<type>* k = first;
				
				if(!first)
				else 
					first = first->next;
				
			delete k;
		}
		
		//wyswietl liste
		void showList()
		{
			Element<type>* k = first;
			while(k != NULL)
			{
				cout<<k->value<<endl;
				k = k->next;
			}
		}
		
		//oblicz rozmiar
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
//	s.addElement(3.5);
//	s.addElement(5);
//	s.addElement(8);
	s.removeElement();
	//s.addElement(11);
	cout<<"Rozmiar: "<<s.getSize()<<endl;
	s.showList();
	
	system("PAUSE");
	return 0;
}
