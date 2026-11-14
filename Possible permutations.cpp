#include<iostream>
#include<vector>
using namespace std;
void Permutation(vector<int> &arr, int idx)
{
	int nums = arr.size();
	//base case
	if(idx == nums)
	{
		for(int i=0;i<nums;i++)
		cout<<arr[i]<<" ";
		cout<<endl;
		return;
	}
	//recursive case
	for(int i=idx;i<nums;i++){ //i starts from idx and not from 0 to make combinatiosn of rest of values
	swap(arr[idx], arr[i]);
	Permutation(arr, idx + 1); //call
	swap(arr[idx], arr[i]); } //backtracking
}
int main(){
	vector<int> a1 = {1,2,3};
	Permutation(a1,0);
	vector<int> a2 = {0,1};
	Permutation(a2,0);
	return 0;
}