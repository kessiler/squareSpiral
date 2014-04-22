#include <iostream>
#include <cmath>
using namespace std;

void squareOn(int valor) {
	int x = 0; // coord X
	int	y = 0; // coord Y
	int caminho = 1; // way of points
	int repeticao = -1; // qtd way repeats
	int operacao  = 0; // operation execute
	int noIncrement = 0;
	for(int i = 0; i <= valor; i++) {
		if(caminho*2 == repeticao) {
			caminho++;
			repeticao = 0;
			noIncrement = 1;
		} else {
			repeticao++;
		}
		if(operacao > 4) operacao = 4;
		switch(operacao) {
			case 1 : y++; break;
 			case 2 : x--; break;
			case 3 : y--; break;
			case 4 : x++; break;
		}
		if(!noIncrement) {
			operacao++;
		} else {
			noIncrement = 0;
		}
	}
	cout << "Coords: (" << x << "," << y << ")" << endl;
}

void squareO1(int valor) {
	int x = 0, y = 0;
	int Lado, LadoEspiralEsq, LadoEspiralDir;
	int Passos;
	if(int(sqrt(float(valor)))%2==0) { 
		Lado = (int)sqrt((float)valor);
		LadoEspiralEsq = (int)pow((float)Lado, 2);
		LadoEspiralDir = (int)pow((float)Lado+1, 2);
	
		if(valor <= (LadoEspiralDir+LadoEspiralEsq)/2) {
			x  = -1*Lado/2;
			y  = x;
			Passos = valor - LadoEspiralEsq;
			x += Passos;
		} else {
			y  = -1*Lado/2+(Lado+1);
			x  = -1*Lado/2+Lado;
			Passos = valor - LadoEspiralDir;
			y += Passos;
		}
	} else {
		Lado = (int)sqrt((float)valor)+1;
		LadoEspiralDir = (int)pow((float)Lado-1, 2);
		LadoEspiralEsq = (int)pow((float)Lado, 2);
	
		if(valor <= (LadoEspiralDir+LadoEspiralEsq)/2) {
			y  = -1*Lado/2+Lado;
			x  = -1*Lado/2+(Lado-1);
			Passos = valor - LadoEspiralDir;
			x += Passos;
		} else {
			y  = -1*Lado/2;
			x  = y;
			Passos = valor - LadoEspiralEsq;
			y -= Passos;
		}
	}
	cout << "Coords: (" << x << "," << y << ")" << endl;
}

int main() {
	cout << "Point 0: ";
	squareOn(0);
	cout << "Point 0: ";
	squareO1(0);
	cout << "Point 3: ";
	squareOn(3);
	cout << "Point 3: ";
	squareO1(3);
	cin.get();
	return 0;
}
