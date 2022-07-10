/*Given an adjacency matrix of a graph, write a program to check whether a given set of vertices {v1,v2,v3.....,vk}
forms an Euler path / Euler Circuit (for circuit assume vk=v1).
*/

#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class Graph
{
  private:
	int v;
	int **a;

  public:
	Graph(int ver)
	{
		v = ver;
		a = new int *[v];
		for (int i = 0; i < v; i++)
		{
			a[i] = new int[v];
		}
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < v; j++)
			{
				a[i][j] = 0;
			}
		}
	}
	void input()
	{
		cout << "\nEnter 1 if vertices are adjacent, otherwise 0......" << endl;
		int i, j;
		for (i = 0; i < v; i++)
		{
			for (j = i; j < v; j++)
			{
				if (i != j)
				{
					cout << i + 1 << " and " << j + 1 << "->";
					cin >> a[i][j];
					a[j][i] = a[i][j];
				}
				else
					a[i][j] = 0;
			}
		}
	}
	int isPath(int s[], int l)
	{
		int vs[l][2];
		for (int i = 0; i < l-1; i++)
		{
			int m = s[i]-1;
			int n=s[i+1]-1;
			if (a[m][n] == 1){
				vs[i][0]=m;
				vs[i][1]=n;
			//	cout<<m<<" "<<n<<endl;
				continue;
			}else {
				cout<<"\nPath missing between two vertices."<<endl;
				exit(0);
			}
		}
		return 1;
	}
	void euler(int s[], int l)
	{
		int check = 1;
		if (isPath(s, l))
		{
			for (int i = 0; i < l; i++)
			{
				for (int j = i + 2; j < l; j++)
				{
					if (s[i] == s[j] )
						if(s[i + 1] == s[j + 1]||s[i-1]==s[j+1])
							check = 0;
				}
			}
		}
	if (check == 1 && s[0] == s[l-1])
		check = 2;
	if (check == 1)
		cout << "\nThis is an Euler path."<<endl;
	else if (check == 2)
		cout << "\nThis is an Euler circuit."<<endl;
	else
		cout << "\nThis is not a Euler path."<<endl;
}
}
;

int main()
{
	clrscr();
	int v;
	cout << "Enter the number of vertices: ";
	cin >> v;
	Graph A(v);
	A.input();
	int len;
	cout << "\nEnter the length of path: ";
	cin >> len;
	int set[len + 1];
	cout << "\nEnter the vertices of path: ";
	for (int i = 0; i < len + 1; i++)
	{
		cin >> set[i];
	}
	A.euler(set, len + 1);
	getchar();
	return 0;
}
