/*
In questo file sono definite delle funzioni giocattolo che vengono richiamate
in vari punti del codice

Ad ogni file .cpp che contiene definizioni (funzioni, variabili, ecc...) e' bene che
corrisponda un file .h che contiene le rispettive dichiarazioni (funzioni, variabili, ecc...)
*/

#include "functs.h" // includiamo il corrispondente file header

const int COSTANTE=900; // Definizione di una variabile intera non modificabile

void funct(int i) {
// ....
	funct2(); // Richiamabile perche' la signature e' dichiarata nel .h
}

void funct2(void) {
//....
// funct3(); // NON richiamabile perche' la signature non e' dichiarata nel .h e la funzione
	         // e' definita dopo funct2
}
// 
// void funct3(void) {
// //....
// }
//
// void funct4(void) {
// 	funct3(); // Richiamabile perche' funct3 e' definita (e quindi nota) prima di funct4
// }
