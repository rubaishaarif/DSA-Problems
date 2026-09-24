#include<iostream>
using namespace std;

float CalculateGPA(string name, float GP[5]){

	float GPA = (GP[0]+GP[1]+GP[2]+GP[3]+GP[4])/5;
	return GPA;
	
}
int main(){
	float GP[5];
	string name;	
	cout<<"Student : "<<name<<endl;
	cin>>name;
	for(int i=0;i<5;i++){	
	cout<<"\nenter GP :\n ";
	cin>>GP[i];
	}
	float result = CalculateGPA(name,  GP);

	cout<<"\nGPA of 5 subjects : ";
	cout<<result;
	
	
	return 0;
}