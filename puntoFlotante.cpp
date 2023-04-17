#include <iostream>
#include <bitset>
using namespace std;

int obtenCExpo(string baseTr, int nExponen){
    int i = 0;
    while(i < baseTr.length()){
        if (baseTr[i] == '1'){
            return nExponen;
        }
        nExponen--;
        i++;   
    }
    return 0;
}

template <class T>
void real_to_bin(T n, int conversor=0){
	if (sizeof(n)==4 || sizeof(n)==8){
		string output, bstring;
		int n_exponent, n_significand;
		if (n < 0){
			output = "1 ";
			n *= -1;
		}else output = "0 ";
		
		if (n<256.0 && conversor==0){
			bitset<8> binary_32(n);
			bstring = binary_32.to_string();
			n_significand = 23;
			n_exponent = obtenCExpo(bstring, 7);
			bstring = bstring.substr(8-n_exponent);
			
			if (n_exponent!=0) n_exponent += 127;
			
			binary_32 = n_exponent;
			output += binary_32.to_string();
		}
		else if ((n>255.0 && n<2048.0) || conversor==1){
			bitset<11> binary_64(n);
			bstring = binary_64.to_string();
			n_significand = 52;
			n_exponent = obtenCExpo(bstring, 10);
			bstring = bstring.substr(11-n_exponent);
			
			if (n_exponent!=0) n_exponent += 1023;

			binary_64 = n_exponent;
			output += binary_64.to_string();
		}
		else if((n>2047.0 && n<32768.0) || conversor==2){
			bitset<15> binary_128(n);
			bstring = binary_128.to_string();
			n_significand = 112;
			n_exponent = obtenCExpo(bstring, 14);
			bstring = bstring.substr(15-n_exponent);
			
			if (n_exponent!=0) n_exponent += 16383;

			binary_128 = n_exponent;
			output += binary_128.to_string();
		}
		
		output += ".";
		output += bstring;
		
		int int_n = n;
		T significand = n - int_n;
		n_significand -= bstring.length();
        
        int i = 0;
        while (i<n_significand){
			significand *= 2.0;
			if (significand>=1.0){
				output += "1";
				significand -= 1.0;
			}
			else output += "0";
			i++;
		}
		cout<<output<<endl;
	}else{
        cout<< "Ingreso de varible Erroneo."<<endl;
    }
}

int main(){
	float A = 25.72;
	cout<<" bin("<<A<<") = ";real_to_bin(A);cout<<endl;

	double B = 150.41, BA = A;
    cout<<" bin("<<BA<<") = "; real_to_bin(BA, 1);cout<<endl;
	cout<<" bin("<<BA<<") = "; real_to_bin(BA, 2);cout<<endl;
	cout<<" bin("<<B<<") = "; real_to_bin(B);cout<<endl;

    char C = 'A';
	cout<<" bin("<<C<<") = ";real_to_bin(C);cout<<endl;

	int D = 15;	
	cout<<" bin("<<D<<") = "; real_to_bin(D);cout<<endl;

    float E=11300.15;
	cout<<" bin("<<E<<") = "; real_to_bin(E);cout<<endl;

    return 0;
}
