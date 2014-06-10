#include <iostream>
#include <list>
#include <fstream>
#define MAXINT 2147483647

using namespace std;

class CKappa
{
	struct TNode
{
  int v_1, v_2, w;
};

int v;
int e;
int s, u;
list <TNode> *L;
int *p,*cfp;
// int fmax = 0;
  
  public:
  	void readFile(char* nazwa)
  	{
  		fstream file;
  		file.open(nazwa);
  		file >> v >> e >> s >> u;
  		L = new list<TNode>[v+1];
  		p = new int[v+1];
  		cfp = new int[v+1];
  		 for(int i = 1; i <= e; i++)
  {
    int x, y, v_2;
 
    file >> x >> y >> v_2;
    TNode z;
    z.v_1 = y; z.v_2 = v_2; z.w = 0;
    L[x].push_back(z);
  }
  	}
  	
  	int maksPrzeplyw()
  	{
  		int fmax;
  		for(int u = 1; u <= v; u++)
  {
    for(list<TNode>::iterator x = L[u].begin(); x != L[u].end(); x++)
    {
      bool test = false;
      for(list<TNode>::iterator y = L[x->v_1].begin(); y != L[x->v_1].end(); y++)
        if((test = (y->v_1 == u))) break;
      if(!test)
      {
        TNode z;
        z.v_1 = u; z.v_2 = z.w = 0;
        L[x->v_1].push_front(z);         
      }
    }
  }
  
   do
  {
    for(int i = 1; i <= v; i++) p[i] = 0;
    p[s] = -1;
    cfp[s] = MAXINT;
    list <int> q;
    q.push_back(s);
    bool esc = false;
 
    while(q.size())
    { 
      int u = q.front(); q.pop_front();
      for(list<TNode>::iterator x = L[u].begin(); x != L[u].end(); x++)
      {
        int cp = x->v_2 - x->w;
        if(cp && !p[x->v_1])
        {
          p[x->v_1] = u;
          cfp[x->v_1] = (cp < cfp[u]) ? cp : cfp[u];
          if(x->v_1 == u)
          {
            fmax += cfp[u];
            int v_1 = u;
            while(v_1 != s)
            {
              int u = p[v_1];
              for(list<TNode>::iterator i = L[u].begin(); i != L[u].end(); i++)
                if(i->v_1 == v_1)
                {
                  i->w += cfp[u]; break;
                }
              for(list<TNode>::iterator i = L[v_1].begin(); i != L[v_1].end(); i++)
                if(i->v_1 == u)
                {
                  i->w -= cfp[u]; break;
                }
              v_1 = u;      
            }            
            esc = true; break;        
          }
          q.push_back(x->v_1);
        } 
      } 
      if(esc) break;
    }
    if(!esc) break;
  } while(true);
  	return fmax;
  	}
};
