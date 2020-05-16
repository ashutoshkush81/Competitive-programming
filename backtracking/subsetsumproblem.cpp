#include<bits/stdc++.h>
using namespace std;
bool flag = false;

//! TODO : Stop printing unique solution multiple time.

void print(int* solution,int* arr,int n){
	flag = true;
	for(int i=0;i<n;i++){
		if(solution[i]==1){
			cout << arr[i] <<" " ;
		}
	}
	cout << endl;
}

bool issafe(int* solution,int n,int target,int i,int *arr,int current){
	if(solution[i]){
		return false;
	}
	if(current+arr[i]>target){
		return false;
	}
	return true;
}

void subsetsum(int n,int target,int current,int pos,int *arr,int *solution){
	if(current==target){
		print(solution,arr,n);
		return ;
	}
	solution[pos]=true;
	for(int i=0;i<n;i++){
		if(issafe(solution,n,target,i,arr,current)){
			subsetsum(n,target,current+arr[pos],i,arr,solution);
		}
	}
	solution[pos]=false;
}

void solve(int n,int target, int arr[]){
	int solution[n];
	for(int i=0;i<n;i++){
		solution[i]=0;
	}
	for(int i=0;i<n;i++){
		subsetsum(n,target,0,i,arr,solution);
	}
	if(!flag){
		cout << "No solution exits" << endl;
	}
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int target;
	cin >> target;
	// Constraints on input (All element of array should be unique.
	solve(n,target,arr);
	return 0;
}
