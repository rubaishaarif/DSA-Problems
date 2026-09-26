#include<iostream>
using namespace std;

int BinarySearch(int arr[], int N, int t){
	int s=0,e=N-1,m;
	while(s<=e){
	
	m = s +(e-s)/2;
	if(t==arr[m])
	return m;
	else if(t<arr[m])
	e = m-1;
	else
	s =m+1;
}
return -1;
}
int main(){
	int N,target;
	cout<<"Enter size : ";
	cin>>N;
	int nums[N];
	cout<<"\nenter nums : \n";
	for(int i=0;i<N;i++){
		cin>>nums[i];
	}
	cout<<"\n enter target : ";
	cin>>target;
	int result = BinarySearch(nums, N, target);
	if(result==-1)
	cout<<"\nTarget not found\n";
	cout<<"Target found at "<<result;
	
	return 0;
	
}