//Write a Program to represent Graphs using the Adjacency Matrices and check if it is a complete graph.

#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;

class Graph{
	private:
		int v;
		int **a;
	public:
		Graph(int ver){
			v=ver;
			a=new int*[v];
			for (int i = 0; i < v; i++)
            {
                a[i]=new int[v];
            }
            for (int i = 0; i < v; i++)
            {
                for(int j=0;j<v;j++)
                {
                    a[i][j]=0;
                }
            }
		}
		void input(){
			cout<<"\nEnter 1 if vertices are adjacent, otherwise 0......"<<endl;
			int i,j;
			for(i = 0; i < v; i++){
				for(j = i; j < v; j++){
					if(i != j)
					{
						cout<<i+1<<" and "<<j+1<<"->";
						cin>>a[i][j];
						a[j][i] = a[i][j];
					}
					else
						a[i][j] = 0;
				}
			} 
		}
		void display()
		{
			int i, j;
			cout<<"\n\n"<<setw(4)<<"";
			for(i = 0; i < v; i++)
				cout<<setw(3)<<"("<<i+1<<")";
			cout<<"\n\n";
			for(i = 0; i < v; i++)
			{
				cout<<setw(3)<<"("<<i+1<<")";
				for(j = 0; j < v; j++)
				{
					cout<<setw(4)<<a[i][j];
				}
				cout<<"\n\n";
			}
		}
		int check()
        {
            for (int i = 0; i < v; i++)
            {
                for(int j=0;j<v;j++)
                {
                    if(i!=j && a[i][j]==0)
                    {
                        return -1;
                    }
                }
            }
            return 0;
        }
};

int main(){
	clrscr();
	int v;
	cout<<"Enter the number of vertices: ";
	cin>>v;
	Graph A(v);
	A.input();
	A.display();
	int res= A.check();
	if (res<0){
		cout<<"\nGraph is not complete."<<endl;
	} else{
		cout<<"\nGraph is complete."<<endl;
	}
	getchar();
	return  0;
}
