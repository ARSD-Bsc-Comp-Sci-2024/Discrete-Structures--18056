//Write a Program to accept a directed graph G and compute the in-degree and out-degree of each vertex.

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
			cout<<"\nEnter n if there is an edge from a to b, otherwise 0......"<<"\n[Note: n= number of edges incident from a to b]"<<endl;
			int i,j;
			for(i = 0; i < v; i++){
				for(j = 0; j < v; j++){
						cout<<i+1<<" to "<<j+1<<"->";
						cin>>a[i][j];
				}
			} 
		}
		void calculate(){
			int count=0;
			int in[v], out[v];
			 for (int i = 0; i < v; i++){
              	in[i]=0;
              	out[i]=0;
			 }
			while(count<v){
				for(int i=0; i<v; i++)
				    if (a[i][count]>0){
				    	out[i]+= a[i][count];
				    	in[count]+=a[i][count];
				    }
				count++;
			}
			cout<<"v"<< setw(8)<<" "<<"in-degree"<<setw(8)<<" "<<"out-degree"<<endl;
			for(int k=0; k<v; k++)
				cout<<"\n"<<k+1 << setw(8) <<" "<< in[k] << setw(16)<<" "<<out[k];
				cout<<endl;
		}
	
};

int main(){
	clrscr();
	int v;
	cout<<"Enter the number of vertices: ";
	cin>>v;
	Graph A(v);
	A.input();
	A.calculate();
	getchar();
	return  0;
}
