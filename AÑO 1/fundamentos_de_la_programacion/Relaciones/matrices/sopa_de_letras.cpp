/*

Sopa de letras para buscar un nombre en las diagonales

*/

#include <iostream>
#include <string>

using namespace std;

class Sopa_De_Letras{
	private:
		static const int MAX_FILAS=50, MAX_COL=50;
		int total_filas,total_col;
		char sopa[MAX_FILAS][MAX_COL];	
	public:
		Sopa_De_Letras (int n_filas, int n_col){
			total_filas=n_filas;
			total_col=n_col;
		}
		void Aniade(int i,int j,char letra){
			if(i>=0 && i<total_filas && j>=0 && j<total_col)
				sopa[i][j]=letra;
		}
		char Elemento(int i, int j){
			char caracter;
			if(i>=0 && i<total_filas && j>=0 && j<total_col)
				return sopa[i][j];
		}
		int Posicion_palabra(Sopa_De_Letras aux,string palabra){
			// Este metodo recibe una matriz de 2x[total_col] del metodo Existe_palabra y se encarga de buscar la palabra 
			// deseada de manera norma e inversa, para ver en que posicion se encuentra la palabra o si no se encuentra.
			// Devuelve la posicion de la palabra desde 0 a 3 o -1 en caso de que la palabra no exista.
			bool existe_palabra=false;
			int x=0,posicion=-1;
			for(int i=0;i<2 && !existe_palabra;i++){
				for(int j=0;j<total_col && !existe_palabra;j++){
					if(palabra[x]==aux.Elemento(i,j)){
						x++;
						if(x==palabra.length()){
							existe_palabra=true;
							posicion=i;
						}
					}
					else{
						x=0;
					}	
				}
			}
			if(posicion==-1){
				for(int i=0;i<2 && !existe_palabra;i++){
				for(int j=total_col-1;j>=0 && !existe_palabra;j--){
					if(palabra[x]==aux.Elemento(i,j)){
						x++;
						if(x==palabra.length()){
							existe_palabra=true;
							posicion=i+2;
						}
					}
					else{
						x=0;
					}	
				}
			}	
			}
			return posicion;	
		}
		int Existe_palabra(string palabra){
			// Este metodo se encarga de crear una matriz con las dos diagonales de la matriz, desde la posicion [0][0] 
			// hasta la posicion [total_filas][total_col] y desde la [total_filas][0] hasta la [total_col][0].
			// Dicha matriz la pasara al metodo Posicion_palabra.
			int diagonal=-1;
			if(palabra.length()<=total_col){
				Sopa_De_Letras aux(2,total_col);
				for(int i=0;i<total_filas;i++)
					aux.Aniade(0,i,sopa[i][i]);
				for(int i=total_filas-1;i>=0;i--)
					aux.Aniade(1,(total_filas-1)-i,sopa[i][(total_filas-1)-i]);
				diagonal=Posicion_palabra(aux,palabra);
			}
			return diagonal;
		}
		
};

int main(){
	
	int num_filas=5,num_columnas=5;
	char letra;
	string palabra="JUAN";
	
	Sopa_De_Letras nueva_sopa(num_filas,num_columnas);
	
	for(int i=0;i<num_filas;i++)
		for(int j=0;j<num_columnas;j++){
			cout << "Introduce la letra en [" << i << "][" << j << "]: ";
			letra=cin.get();
			if(letra!='\n')
				nueva_sopa.Aniade(i,j,letra);
			else
				j--;
		}

	cout << "\n";
	
	for(int i=0;i<num_filas;i++){
		for(int j=0;j<num_columnas;j++)
			cout << nueva_sopa.Elemento(i,j) << "  ";
		cout << "\n";	
	}
	
	switch(nueva_sopa.Existe_palabra(palabra)){
		case 0:
			cout << "\nLa palabra se encuentra en la diagonal principal";
		break;
		case 1:
			cout << "\nLa palabra se encuentra en la diagonal inversa";
		break;
		case 2:
			cout << "\nLa palabra se encuentra en la diagonal principal de forma inversa";
		break;
		case 3:
			cout << "\nLa palabra se encuentra en la diagonal inversa de forma inversa";
		break;
		default:
			cout << "\nLa palabra " << palabra << " no existe en la sopa de letras";
	}
		
}
