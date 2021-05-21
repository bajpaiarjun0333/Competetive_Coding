#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unsigned long long int bit_freq[32];
long long int form_Number(){
    long long ans=0;
    if(bit_freq[31]==0){
        ans =0;
    }else{
        ans =1;
    }
    for(long long int i=30;i>=0;i--){
        ans=2*ans;
        if(bit_freq[i]==0){
            continue;
        }else{
            ans++;
        }
    }
    return ans;
}

long long int init(unsigned long long int N, unsigned long long int *arr){
    long long int ans;
    for(unsigned long long int i=0;i<N;i++){
        long long int number= arr[i];
        for(unsigned long long int j=0;j<32;j++){
            if(number&1){
                bit_freq[j]++;
            }
            number>>=1;
        }//end of inner for loop
    }
    ans = form_Number();
    return ans;
}

long long int solveQuery(unsigned long long int index, unsigned long long int replacement, unsigned long long int *arr){
    //update bit_freq array
    long long int number=arr[index-1];
    arr[index-1]=replacement;
    for(int i=0;i<32;i++){
        if(number&1){
            bit_freq[i]--;
        }
        if(replacement&1){
            bit_freq[i]++;
        }
        number>>=1;
        replacement>>=1;
    }
    return form_Number();
}

int main() {
	unsigned long long int test_cases;
	cin>>test_cases;
	while(test_cases--){
	    //clear the bit_freq
	    for(int i=0;i<32;i++){
	        bit_freq[i]=0;
	    }
	    unsigned long long int N, Q;
	    cin>>N>>Q;
	    unsigned long long arr[N];
	    for(unsigned long long int i=0;i<N;i++){
	        cin>>arr[i];
	    }
	    cout<<init(N,arr)<<endl;
	    unsigned long long int index, replacement;
	    for(unsigned long long int i=0;i<Q;i++){
	        cin>>index>>replacement;
	        cout<<solveQuery(index,replacement,arr)<<endl;
	    }
	    
	}
	return 0;
}
