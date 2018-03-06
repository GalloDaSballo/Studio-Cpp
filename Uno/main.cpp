/*
 Primo programma C++. Illustra come includere la libreria standard per usare le
 relative funzionalita'. L'esempio mostra come leggere caratteri da console e come scrivere
 sequenza di caratteri su console.


 Per creare l'eseguibile del programma sono necessarie le seguenti istruzioni nella console:

 Compilazione dei file (creazione dei file oggetto):
 g++ -c main.cpp -o main.o
 g++ -c functs.cpp -o functs.o

 Linking dei file oggetto (creazione dell'eseguibile):
 g++ main.o functs.o -o main.exe
*/

#include <iostream> // necessario per poter usare std::cout, std::endl
#include <string>   // necessario per poter usare std::string
#include "functs.h" // necessario per poter usare le funzioni scritte da noi

using namespace std; // rimuove il namespace std:: dalle istruzioni/oggetti
                 		// della libreria standard. Usare con attenzione.

int main() { // entry point di un programma C++. E' una funzione globale.
             // Deve esistere una e una sola funzione main.

	std::string tmp; // istanziamo oggetto stringa
	int tmp2; // istanziamo un dato di tipo int

	cin >> tmp;   // usiamo tmp per leggere una stringa
	cin >> tmp2;  // usiamo tmp2 per leggere un intero

	cout << "hello world" << endl; // scriviamo su console la stringa
	                               // endl corrisponde a endline/newline

	cout << tmp << endl; // scriviamo la stringa contenuta in tmp

	cout << tmp2 << endl; // scriviamo l'intero sulla console

	funct(9); // chiamiamo func che e' definito nel file functs.cpp
	          // e' necessario includere il file header (.h) di functs
	          // per far conoscere al compilatore la funzione


	//cout<<COSTANTE<<endl; // scriviamo su console la variabile COSTANTE che
	                                // e' definita nel file functs.cpp
	                                // La sua dichiarazione e' nel file functs.h

	//COSTANTE = 0; // errore perche' il dato e' const (non modificabile, vedere il file .h)

	return 0; // il main DEVE ritornare in intero
	          // 0 = tutto ok
	          // errore altrimenti
}


void funct(int i) {
	cout << "Numero= " + i << endl;
}
