#include <iostream>
#include <bitset>
using namespace std;

int main(){
    const int n = 10;
    int A = 0, M=13, Q=598, cOnt = n;
    bitset<n> B_q(Q), B_a(A);
    for (; cOnt != 0; cOnt--){
        B_a <<= 1;
        B_a[0] = B_q[n-1];
        A = B_a.to_ulong();
        B_q <<= 1;
        A-= M;
        if (A>=0){
            B_q[0] = 1;
        }else{
            A+=M;
        }
        bitset<n> tmp(A);
        B_a = tmp;
    }
    Q = B_q.to_ulong();
    cout<<"------------------------------------------------"<<endl;
    cout<<"| \t\tBinario\t\t Decimales \t|"<<endl;
    cout<<"|------------------------------------------------"<<endl;
	cout<<"| Cociente\t"<<B_q<<"\t  "<<Q<<"\t\t|"<<endl;
    cout<<"|------------------------------------------------"<<endl;
	cout<<"| Residuo\t"<<B_a<<"\t  "<<A<<"\t\t|"<<endl;
    cout<<"|-----------------------------------------------|"<<endl;
    return 0;
}