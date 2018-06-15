#include <iostream>
#include "bloqueLed.h"

using namespace std;

void on(bloqueLed &b, int pos){
	bloqueLed mask;
	if(pos>=0 && pos<8){
		mask=0x1 << pos;
		b = b | mask;
	}
}

void off(bloqueLed &b, int pos){
	bloqueLed mask;
	if(pos>=0 && pos<8){
		mask=0x1 << pos;
		mask=~mask;
		b = b & mask;
	}
}

bool get(bloqueLed b, int pos){
	bloqueLed mask;
	bool correcto=false;
	if(pos>=0 && pos<8){
		mask=0x1 << pos;
		b=b&mask;
		if(b>0)
			correcto=true;
	}
	return correcto;
}

void encender(bloqueLed &b){
	b=0x0;
	b=~b;
}

void apagar(bloqueLed &b){
	bloqueLed mask=0x0;
	b=b & mask;
}

void asignar(bloqueLed &b, const bool v[]){
	for(int i=0;i<8;i++){
		if(v[i])
			on(b,7-i);
	}
}

void volcar(bloqueLed b, bool v[]){
	for(int i=7;i>=0;i--){
		if(get(b,i))
			v[7-i]=1;
		else
			v[7-i]=0;
	}
}

void encendidos(bloqueLed b, int posic[], int &cuantos){
	cuantos=0;
	for(int i=0;i<8;i++){
		if(get(b,i)){
			posic[cuantos]=i;
			cuantos++;
		}
	}
}

string bloqueLedToString(bloqueLed b){
	string resultado;
	for(int i=7;i>=0;i--){
		if(get(b,i))
			resultado+="1";
		else
			resultado+="0";
	}
	return resultado;
}
