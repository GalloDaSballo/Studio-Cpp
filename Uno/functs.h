#ifndef FUNCTS_H // guardie del file header
#define FUNCTS_H // Evitano che il file .h venga incluso piu' volte
                 // durante la compilazione

void funct(int i); // Dichiarazione della funzione funct
void funct2(void); // Dichiarazione della funzione funct2

extern const int COSTANTE; // Dichiarazione di una variabile intera non modificabile

// Le dichiarazioni servono a far conoscere al compilatore che esistono delle funzioni e/o variabili
// che possono essere richiamate/usate in altri file .cpp
// In questo esempio,non abbiamo messo la dichiarazione di funct3 che e' definita nel file .cpp.
// Altri file .cpp non potranno richiamarla perche' per quei file la sua signature e' sconosciuta. 

#endif
