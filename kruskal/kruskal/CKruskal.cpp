//#define BOOST_TEST_DYN_LINK
//#define BOOST_TEST_MODULE Hello
//#include <boost/test/unit_test.hpp>

#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <limits.h>
#include <queue>
#include <vector>
#include <set>
#include "Node.cpp"
//#include <boost\timer.hpp>

using namespace std;


class CKruskal
{
	double srednia(double * czasy, int powtorzenia)
	{
		double sum = 0;
		for (int i = 0; i < powtorzenia; i++)
			sum += czasy[i];
		return sum / (double)powtorzenia;
	}

	list<Node> nodes;
	long int** nodesM;
	int maxNode = 0;

	struct compareRandom {
		bool operator()(Node a, Node b)
		{
			if (a.wage < b.wage)
				return true;
			if (a.wage > b.wage)
				return false;
			return a.wage < b.wage;
		}
	};

	bool allNodes(bool * nodes)
	{
		for (int i = 0; i <= maxNode; i++)
		{
			if (!nodes[i])
				return false;
		}
		return true;
	}
public:
	CKruskal(CKruskal * k)
	{
		for (int i = 0; i <= maxNode; i++)
			delete [] nodesM;
		maxNode = k->maxNode;
		nodesM = new long int*[maxNode + 1];
		for (int i = 0; i <= maxNode; i++)
			nodesM[i] = new long int[maxNode + 1];
		for (int i = 0; i <= maxNode; i++)
		for (int j = 0; j <= maxNode; j++)
			nodesM[i][j] = 0;
		for (int i = 0; i < maxNode;i++)
		for (int j = 0; j < maxNode; j++)
		{
			nodesM[i][j] = k->getMatrix()[i][j];
		}
		nodes = k->nodes;
	}

	CKruskal()
	{
		maxNode = 0;
	}

	list<Node> minTree()
	{
		list<Node> tree;
		bool * n = new bool[maxNode + 1];
		for (int i = 0; i <= maxNode; i++)
			n[i] = false;
		sortGraph();
		list<Node>::iterator it;
		it = nodes.begin();
		while (!allNodes(n) && it != nodes.end())
		{
			n[it->start] = true;
			n[it->end] = true;
			tree.push_back(*(it++));
		}
		delete[] n;
		return tree;
	}

	void addEdgesToTree(list<Node> &tree, int p)
	{
		list<Node>::iterator it;
		it = nodes.begin();
		
		while (it != nodes.end())
		{
			if (it->start == p || it->end == p)
			{
				tree.push_back(*(it));
				it = nodes.erase(it);
			}
			else
				it++;
		}
	}

	list<Node> minTree(int p)
	{
		list<Node> tree;
		bool * n = new bool[maxNode + 1];
		for (int i = 0; i <= maxNode; i++)
			n[i] = false;
		list<Node> tree2;
		n[p] = true;
		while (!allNodes(n))
		{
			addEdgesToTree(tree2, p);
			tree2.sort(compareRandom());
			tree.push_front(*(tree2.begin()));
			n[tree.begin()->start] = true;
			addEdgesToTree(tree2, tree.begin()->start);
			p = tree.begin()->end;
			n[tree.begin()->end] = true;
			addEdgesToTree(tree2, tree.begin()->end);
			p = tree.begin()->start;
			tree2.pop_front();
		}
		return tree;
	}

	void readGraph()
	{
		fstream myfile;
		myfile.open("nodes.txt");
		int node1, node2, wage;
		while (!myfile.eof())
		{
			myfile >> node1 >> node2 >> wage;
			Node node;
			node.start = node1;
			node.end = node2;
			node.wage = wage;
			nodes.push_back(node);
			if (node1 > maxNode)
				maxNode = node1;
			if (node2 > maxNode)
				maxNode = node2;
		}
		myfile.close();
	}

	void readGraphM()
	{
		fstream myfile;
		myfile.open("nodes.txt");
		int node1, node2, wage;
		while (!myfile.eof())
		{
			myfile >> node1 >> node2 >> wage;
			if (node1 > maxNode)
				maxNode = node1;
			if (node2 > maxNode)
				maxNode = node2;
		}
		myfile.close();
		nodesM = new long int*[maxNode + 1];
		for (int i = 0; i <= maxNode; i++)
			nodesM[i] = new long int[maxNode + 1];
		for (int i = 0; i <= maxNode; i++)
		for (int j = 0; j <= maxNode; j++)
			nodesM[i][j] = 0;
		myfile.open("nodes.txt");
		while (!myfile.eof())
		{
			myfile >> node1 >> node2 >> wage;
			nodesM[node1][node2] = wage;
			nodesM[node2][node1] = wage;
		}
		myfile.close();
	}

	void writeGraph(list<Node> lista)
	{
		fstream file;
		file.open("out.txt", ios::out);
		list<Node>::iterator it;
		for (it = lista.begin(); it != lista.end(); ++it)
		{
			cout << "wwww";
			file << it->start << " " << it->end << " " << it->wage << endl;
		}
		file.close();
	}

	void sortGraph()
	{
		nodes.sort(compareRandom());
	}

	void showGraph()
	{
		list<Node>::iterator it;
		for (it = nodes.begin(); it != nodes.end(); ++it)
		{
			cout << it->start << " " << it->end << " " << it->wage << endl;
		}
	}

	void showGraphM()
	{
		for (int i = 0; i <= maxNode; i++)
		{
			for (int j = 0; j <= maxNode; j++)
				cout << nodesM[i][j] << " ";
			cout << endl;
		}
	}

	void showGraph(list<Node> lista)
	{
		list<Node>::iterator it;
		for (it = lista.begin(); it != lista.end(); ++it)
		{
			cout << it->start << " " << it->end << " " << it->wage << endl;
		}
	}

	bool DFS(int szukany)
	{
		stack<int> stos;
		bool* V = new bool[maxNode + 1];
		for (int j = 0; j <= maxNode; ++j)V[j] = false;//Wierzcho³ki nie odwiedzone

		stos.push(szukany);//Wrzucamy startuj¹cy wierzcho³ek na stos

		while (!stos.empty())
		{
			szukany = stos.top();
			stos.pop();//Usuwamy odwiedzany element


			V[szukany] = true;//ODwiedziliœmy ju¿ ten

			for (int j = maxNode; j >= 0; --j)
			{
				if (nodesM[j][szukany] != 0 && V[j] == false)
				{
					stos.push(j);//Wrzucamy na stos jego s¹siadów
					V[j] = true;//Znaznaczamy ,¿e go odwiedzimy!(w niedalekiej przysz³oœci)
					//Inaczej bêdziemy mieli np tak¹ sytuacjê w stosie 2,3,4,2 <-- 2x dwójka
				}
			}
		}
		return allNodes(V);
	}

	list<Node> convert(long int ** matrix)
	{
		list<Node> result;
		for (int i = 0; i <= maxNode;i++)
		for (int j = i+1; j <= maxNode; j++)
		{
			Node n;
			n.start = i;
			n.end = j;
			n.wage = matrix[j][i];
			if (n.wage != 0)
				result.push_back(n);
		}
		return result;
	}

	int** convert(list<Node> lista)
	{
		int ** result;
		list<Node>::iterator it;
		maxNode = 0;
		for (int i = 0; i <= maxNode; i++)
		{
			delete[] nodesM;
		}
		for (it = lista.begin(); it != lista.end(); it++)
		{
			if (maxNode < it->start)
				maxNode = it->start;
			if (maxNode < it->end)
				maxNode = it->end;
		}
		nodesM = new long int*[maxNode + 1];
		for (int i = 0; i <= maxNode; i++)
		{
			nodesM[i] = new long int[maxNode + 1];
		}
		for (int i = 0; i <= maxNode;i++)
		for (int j = 0; j <= maxNode; j++)
		{
			nodesM[i][j] = 0;
		}
		for (it = lista.begin(); it != lista.end(); it++)
		{
			nodesM[it->start][it->end] = it->wage;
			nodesM[it->end][it->start] = it->wage;
		}
		return result;
	}

	long int ** getMatrix()
	{
		return nodesM;
	}

	long int** randomGraph(int n, double p)
	{	
			if (nodesM != NULL)
			{
				for (int i = 0; i < n; i++)
					delete[] nodesM[i];
			}
			srand((unsigned int)time(NULL));
			maxNode = n - 1;
			nodesM = new long int*[n];
			for (int i = 0; i < n; i++)
			{
				nodesM[i] = new long int[n];
			}
			for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				nodesM[i][j] = 0;
			}
			while (!DFS(0))
			{
			for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
			{
				double k = rand() / (double)SHRT_MAX;
				if (k < p)
				{
					int l = rand() % 99 + 1;
					nodesM[i][j] = l;
					nodesM[j][i] = l;
				}
			}
			nodes = convert(nodesM);
		}
		return nodesM;
	}
	double liczKruskal(int powtorzenia, int n, double p)
	{
		clock_t start, koniec;
		double* times = new double[powtorzenia];
		CKruskal* k = new CKruskal();
		k->randomGraph(n, p);
		for (int i = 0; i < powtorzenia; i++)
		{
			cout << i + 1 << " ";
			CKruskal* k2 = new CKruskal(k);
			start = clock();
			k2->minTree();
			koniec = clock();
			times[i] = (long)(koniec - start);
			delete k2;
		}
		double result = srednia(times, powtorzenia);
		//cout << srednia(times, powtorzenia) << endl;
		return result;
	}
	double liczPrime(int powtorzenia, int n, double p)
	{
		clock_t start, koniec;
		double* times = new double[powtorzenia];
		CKruskal* k = new CKruskal();
		k->randomGraph(n, p);
		for (int i = 0; i < powtorzenia; i++)
		{
			cout << i + 1 << " ";
			CKruskal* k2 = new CKruskal(k);
			start = clock();
			k2->minTree(0);
			koniec = clock();
			times[i] = (long)(koniec - start);
			delete k2;
		}
		double result = srednia(times, powtorzenia);
		return result;
	}

	
};
