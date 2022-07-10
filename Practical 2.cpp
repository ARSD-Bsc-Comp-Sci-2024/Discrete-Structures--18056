/*Create a class SET and take two sets as input from user to perform following SET Operations:
a) Subset: Check whether one set is a subset of other or not.
b) Union and Intersection of two Sets.
c) Complement: Assume Universal Set as per the input elements from the user.
d) Set Difference and Symmetric Difference between two SETS
e) Cartesian Product of Sets.*/

#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

class Set
{
	vector<int> set;
  public:
	Set(){
		set={};
	}
	void input()
	{
		int size=0;
		int num;
		cout << "Enter the element (Enter -1 to stop) : ";
		cin >> num;
		int check = 1;
		while (check)
		{
			if (num < 0)
				break;
			set.push_back(num);
			size++;
			cout << "Enter the element (Enter -1 to stop) : ";
			cin >> num;
		}
	}
	
	void display(vector<int>* v)
	{
		cout << "{ ";
		for (auto i = v->begin(); i != v->end(); ++i)
			cout << *i << " ";
		cout << "}";
	}
	
	void subset(Set a, Set b){
		int check=1;
		for (auto i = b.set.begin(); i != b.set.end();i++) {
				if(std::find(a.set.begin(), a.set.end(), *i) != a.set.end())
					continue;
				else
					check=0;
		}
		if(check)
			cout<<"\nSet 2 is subset of Set 1";
		else
			cout<<"\nSet 2 is not subset of Set 1";
	}
	
	void unions(Set a, Set b){
		vector<int> unionset;
		unionset=a.set;
		for (auto i = b.set.begin(); i != b.set.end();i++) {
			if(std::find(a.set.begin(), a.set.end(), *i) != a.set.end())
				continue;
			else
				unionset.push_back(*i);
		}
		cout<<"\n\nUnion Set= " ;
		display(&unionset);
	}
	
	void intersection(Set a, Set b){
		vector<int> intr;
		for( auto i=b.set.begin(); i != b.set.end(); ++i){
			for(auto j=a.set.begin(); j != a.set.end(); ++j){
				if(*i==*j)
					intr.push_back(*i);
			}
		}
		cout<<"\n\nIntersection of sets=" ;
		display(&intr);
	}
	
	void setdiff(Set a, Set b){
		vector<int> diff;
		for (auto i = a.set.begin(); i != a.set.end();i++) {
			if(std::find(b.set.begin(), b.set.end(), *i) != b.set.end())
				continue;
			else
				diff.push_back(*i);
		}
		cout<<"\n\nSet Difference[set1 - set2]=" ;
		display(&diff);
	}
	
	void symdifference(Set a, Set b){
		vector<int> symdiff;
		for (auto i = a.set.begin(); i != a.set.end();i++) {
			if(std::find(b.set.begin(), b.set.end(), *i) != b.set.end())
				continue;
			else
				symdiff.push_back(*i);
		}
		for (auto i = b.set.begin(); i != b.set.end();i++) {
			if(std::find(a.set.begin(), a.set.end(), *i) != a.set.end())
				continue;
			else
				symdiff.push_back(*i);
		}
		cout<<"\n\nSymmectric Difference[set1 ⊕ set2]=" ;
		display(&symdiff);
	}
	
	void cartesianP(Set a, Set b){
		vector<vector<int>> cp;
		for( auto i=a.set.begin(); i != a.set.end(); ++i){
			for(auto j=b.set.begin(); j != b.set.end(); ++j){
				vector<int> sub;
				sub.push_back(*i);
				sub.push_back(*j);
				cp.push_back(sub);
			}
		}
		cout<<"\n\nCartesian product of sets=" ;
		for (int i = 0; i < cp.size(); i++) { 
		cout<<"\n{ ";
			for (int j = 0; j < cp[i].size(); j++) 
				cout << cp[i][j] << " "; 
			cout <<"}";
		}
	}
	
	void complement(Set b, Set universal){
		vector<int> complement;
		for (auto i = universal.set.begin(); i != universal.set.end();i++) {
			if(std::find(b.set.begin(), b.set.end(), *i) != b.set.end())
				continue;
			else
				complement.push_back(*i);
		}
	//	cout<<"\n\nComplement =" ;
		display(&complement);
	}
};

int main()
{
	Set s1;
	Set s2;
	Set res;
	cout<<"Set A: "<<endl;
	s1.input();
	cout<<"\n\nSet B: "<<endl;
	s2.input();
	res.subset(s1, s2);
	res.unions(s1, s2);
	res.intersection(s1, s2);
	res.setdiff(s1, s2);
	res.symdifference(s1, s2);
	res.cartesianP(s1, s2);
	Set universal;
	cout<<"\n\nEnter the universal set: "<<endl;
	universal.input();
	cout<<"\n\nComplement of Set A= ";
	res.complement(s1, universal);
	cout<<"\n\nComplement of Set B= ";
	res.complement(s2, universal);
	return 0;
}
