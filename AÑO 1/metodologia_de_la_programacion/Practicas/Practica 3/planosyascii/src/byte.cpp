#include <iostream>
#include "byte.h"

using namespace std;

void on(byte &b, int pos){
	byte mask;
	if(pos>=0 && pos<8){
		mask=0x1 << pos;
		b = b | mask;
	}
}

void off(byte &b, int pos){
	byte mask;
	if(pos>=0 && pos<8){
		mask=0x1 << pos;
		mask=~mask;
		b = b & mask;
	}
}

bool getbit(byte b, int pos){
	byte mask;
	bool correcto=false;
	if(pos>=0 && pos<8){
		mask=0x1 << pos;
		b=b&mask;
		if(b>0)
			correcto=true;
	}
	return correcto;
}

void encender(byte &b){
	b=0x0;
	b=~b;
}

void apagar(byte &b){
	byte mask=0x0;
	b=b & mask;
}

void asignar(byte &b, const bool v[]){
	for(int i=0;i<8;i++){
		if(v[i])
			on(b,7-i);
	}
}

void volcar(byte b, bool v[]){
	for(int i=7;i>=0;i--){
		if(getbit(b,i))
			v[7-i]=1;
		else
			v[7-i]=0;
	}
}

void encendidos(byte b, int posic[], int &cuantos){
	cuantos=0;
	for(int i=0;i<8;i++){
		if(getbit(b,i)){
			posic[cuantos]=i;
			cuantos++;
		}
	}
}

string byteToString(byte b){
	string resultado;
	for(int i=7;i>=0;i--){
		if(getbit(b,i))
			resultado+="1";
		else
			resultado+="0";
	}
	return resultado;
}
