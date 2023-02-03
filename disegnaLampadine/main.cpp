#include "drawing.h"

using namespace std;

int const MAX = 500;

void disegnaLampadina(int x, int y,int radius, bool onOff);
void disegnaSerieLampadine(int x, int y, int radius,int nel_elementi, bool lampadina[]);
void inizializzazione(bool vet[], int nel_elementi);
void vettoreInverti(bool vet[], int nel_elementi);
void inizializzazioneCoordinate(int xIniziale, int yIniziale,int radius, int x[], int y[], int NEl);

void main() {
	int nel_lampadina = MAX;
	bool lampadina[MAX];
	int xLampadine[MAX];
	int yLampadine[MAX];


	int NLampadine = 10;
	int x = 20;
	int y = 20;
	int radius = 10;
	
	//inizializzazione
	inizializzazione(lampadina, nel_lampadina);
	inizializzazioneCoordinate(x,y,radius,xLampadine, yLampadine,nel_lampadina);
	disegnaSerieLampadine(x, y, radius, NLampadine, lampadina);
	
	while (true) {
		Wait(66);
		if (LeftMousePressed()) {
			
			int xMouse = MouseX();
			int yMouse = MouseY();

			/*
			if (xMouse >= x - radius && xMouse <= x + (radius * 3 * NLampadine) - radius * 2 && yMouse <= y + radius + radius / 2 && yMouse >= y - radius) {
				Clear();
				vettoreInverti(lampadina, nel_lampadina);
				disegnaSerieLampadine(x, y, radius, NLampadine, lampadina);
			}
			*/
			for (int cont = 0; cont < nel_lampadina; cont++) {
				if (xMouse >= xLampadine[cont] - radius && xMouse <= xLampadine[cont] + radius && yMouse <= yLampadine[cont] + radius+radius/2 && yMouse >= yLampadine[cont] - radius) {
					lampadina[cont] = !lampadina[cont];
					Clear();

					disegnaSerieLampadine(x, y, radius, NLampadine, lampadina);
				}
			}
			while (LeftMousePressed());
		}
	}
}

void inizializzazione(bool vet[], int nel_elementi) {
	//inizializzazione vettore 
	for (int cont = 0; cont < nel_elementi; cont++) {
		if (cont % 2 == 0) {
			vet[cont] = true;
		}
		else {
			vet[cont] = false;
		}
	}
}
void inizializzazioneCoordinate(int xIniziale, int yIniziale, int radius, int x[], int y[], int NEl){
	int spazio = 0;
	int altezza = 0;
	for (int cont = 0; cont < NEl && NEl <= MAX; cont++) {
		x[cont] = xIniziale + spazio;
		y[cont] = yIniziale + altezza;
		spazio = spazio + radius * 3;
		//va a capo se raggiunge il limite dello schermo
		if (spazio > Width - xIniziale - radius * 3) {
			spazio = 0;
			altezza += radius * 3;
		}
	}
}
void vettoreInverti(bool vet[], int nel_elementi) {
	for (int cont = 0; cont < nel_elementi; cont++) {
		vet[cont] = !vet[cont];
	}
}

void disegnaSerieLampadine(int x, int y, int radius, int nel_elementi, bool lampadina[]) {
	int spazio = 0;
	int altezza = 0;
	for (int cont = 0; cont < nel_elementi && nel_elementi<=MAX; cont++) {
		disegnaLampadina(x + spazio, y+altezza, radius, lampadina[cont]);
		spazio = spazio +radius*3;

		//va a capo se raggiunge il limite dello schermo
		if (spazio > Width-x-radius*3) {
			spazio = 0;
			altezza += radius * 3;
		}
	}
}

void disegnaLampadina(int x, int y,int radius, bool onOff) {
	DrawCircle(x, y, radius, Yellow, onOff);
	DrawRectangle(x - radius/2, y + radius, radius, radius / 2, LightGray, true);
}
