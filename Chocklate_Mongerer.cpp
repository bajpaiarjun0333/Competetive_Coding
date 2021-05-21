#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unsigned long long int solve(unsigned long long int N, unsigned long long int X, unsigned long long int *arr){
    set<unsigned long long int> s;
    for(unsigned long long int i=0;i<N;i++){
        s.insert(arr[i]);
    }
    int variety = s.size();
    if((N-X)>variety){
        return variety;
    }else{
        return (N-X);
    }
}
int main() {
	unsigned long long int test_cases;
	cin>>test_cases;
	while(test_cases--){
	    unsigned long long int N,X;
	    cin>>N>>X;
	    unsigned long long int arr[N];
	    for(unsigned long long int i=0;i<N;i++){
	        cin>>arr[i];
	    }
	    cout<<solve(N,X,arr)<<endl;
	}
	return 0;
}
