#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;
int main()
{
	int x, k;
	int a[20] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4 };
	int n = 20;
	vector < int > v(a, a + 20);

	make_heap(v.begin(), v.end());
	cout << "\n\n";

	for (int i = 0; i < n; i++){
		cout << v[i] << " ";
	}
	cout << endl << endl;

	x = n / 2; k = 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < x ; j++) cout << "  ";
		cout << v[i];
		for (int j = 1; j <= x; j++) cout << "  ";		
		if (i + 2 == k)
		{
			cout << "   ";
			k += k; 
			x /= 2; 
			cout << "  " << endl;
		} 
	}

	cout << endl << endl;

	pop_heap(v.begin(), v.end());
	n--;

	for (int i = 0; i<n; i++){
		cout << v[i] << " ";
	}

	cout << endl << endl;


	return 0;
}