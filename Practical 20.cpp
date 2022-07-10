//Given a full m-ary tree with i internal vertices, Write a Program to find the number of leaf nodes.
/*This program inputs the value of m of the full m-ary tree and no of vertex of the tree. 
It calculates internal vertices i, and then calculate no of leaves.
 Formula used: l=(m-1)i+1*/

#include <iostream>
using namespace std;

 int leaf(int m, int v){
	int i=(v-1)/m;
	int l=(m-1)*i+1;
	return l;
 }
 
 int main(){
 	int m, n;
 	cout<<"This program calculates the leaves of a m-ary tree ........."<<endl;
 	cout<<"\nEnter m: ";
 	cin>>m;
 	cout<<"Enter the number of vertices of the tree: ";
 	cin>>n;
 	cout<<"\nNumber of leaves: "<<leaf(m,n);
 }
