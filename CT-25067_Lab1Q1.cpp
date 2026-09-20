#include<iostream>
using namespace std;
int main(){

int A[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
int B[9];
int a=0;

	for(int j=0;j<3;j++ )
	{
		for(int i=0;i<3;i++){
		B[a] = A[i][j];
		a++;
	}
	}

for(int j=0;j<9;j++ )
		 cout<<B[j]<<" ";
	cout<<endl;
	
	return 0;
}