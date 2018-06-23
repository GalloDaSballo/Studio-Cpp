/**
 *  Alessandro Valerani 758717 a.valerani@campus.unimib.it
 */

#include <iostream> //cout
#include <iterator> //categorie degli iterator
#include <algorithm> //Swap

#ifndef MATRICE2DLINEAR_H
#define MATRICE2DLINEAR_H

template
<class T>
class Matrice2D
{
  private:
    T* arrayFisico; //Array è flat
    int l_x;
    int l_y;

  public:

    /**
     * @brief Costruttore di default
     */
    Matrice2D(){
      l_x = l_y = 3;
      arrayFisico = new T[l_x * l_y];
    }

    /**
     * @brief Costruttore di copia
     */
     Matrice2D(const Matrice2D &other){
       l_x = other.l_x;
       l_y = other.l_y;
       arrayFisico = new T[l_x * l_y];

       for(int i = 0; i < l_x * l_y; i++){
         arrayFisico[i] = other.arrayFisico[i];
       }
     }

     /**
      * Costruttore Secondario
      * @param arr  [description]
      * @param il_x [description]
      * @param il_y [description]
      *
      * @brief A partire da un arr di altro tipo, costruisce la matrice 3d.
      * Usato anche per convertire una matrice da un tipo (compatibile) ad un altro
      */
    template<class T2>
    Matrice2D(T2* arr, int il_x, int il_y){
      #ifdef DEBUG
        std::cout << "Inizia template<class T2> Matrice2D(T2* arr, int il_x, int il_y)" << std::endl;
      #endif
      l_x = il_x;
      l_y = il_y;
      arrayFisico = new T[l_x * l_y];

      #ifdef DEBUG
        std::cout << "arr[0];" << std::endl;
        std::cout << arr[0] << std::endl;
        std::cout << "arr[0];" << std::endl;
      #endif

      for(int xy = 0; xy < l_x * l_y; xy++){
        #ifdef DEBUG
          std::cout << "Stampo Prima" << std::endl;
          std::cout << arr[xy] << std::endl;
        #endif
        arrayFisico[xy] = arr[xy];
        #ifdef DEBUG
          std::cout << "Stampo Dopo" << std::endl;
          std::cout << arrayFisico[xy] << std::endl;
        #endif
      }
    }

    /**
     * Operatore di Conversione
     */
    template<class T2>operator Matrice2D<T2>();

    /**
  	 * Operatore di assegnamento
  	 * @param other Matrice2D da copiare
  	 * @return reference a this
  	 * @throw eccezione di allocazione di memoria
  	*/
  	Matrice2D& operator=(const Matrice2D &other) {
      /** Copiato da DBUFFER */
      if (this != &other) {
        // Proviamo a copiare i nuovi dati in un Matrice di appoggio
        // Se la copia fallisce, viene lanciata una eccezione e l'esecuzione
        // torna al chiamante (non la stiamo gestendo)
        Matrice2D tmp(other);
        // Se la copia riesce, scambiamo i dati di this con quelli del dbuffer di appoggio
        this->swap(tmp);
        // All'uscita dell'if, tmp viene automaticamente distrutto e quindi vengono
        //  rimossi i vecchi dati di this che ora si trovano dentro tmp!
      }
      #ifdef DEBUG
        std::cout << "Matrice2D::operator=(const Matrice2D&)" << std::endl;
      #endif
      return *this;
  	}

    /**
     * @brief Distruttore, distrugge l'array
     */
    ~Matrice2D(){
      delete[] arrayFisico;
    }

    /**
     * @brief Scambia il contenuto di due Matrici2D
     * Scambia il contenuto di due Matrici2D.
     * @param other Matrice2D con il quale scambiare i dati
    **/
    	void swap(Matrice2D &other);

    /**
     * @return il valore alla cella (y,x)
     */
    T& operator()(int y, int x){
        return arrayFisico[y * l_y + x];
    }


    /**
     * Class: iterator
     *
     * @brief Permette l'accesso in sola lettura ai dati ordinati
     */
    class iterator{
        Matrice2D* mat;
        int index;
        friend class Matrice2D;
    public:
      typedef std::bidirectional_iterator_tag iterator_category;
      typedef T value_type;
      typedef std::ptrdiff_t difference_type;
      typedef T* pointer;
      typedef T& reference;


        /**
         * Costruttore di Copia
         */
        iterator(const iterator &other) : mat(other.mat), index(other.index){}

        /*
         * Costruttore di default
         */
        iterator() : mat(NULL), index(0) {};

        /**
         * Costruttore Secondario
         * @brief usato per inizializzare un iteratore da un indice specifico
         * @param matrice La matrice da cui partire
         * @param indice  da quale indice iniziare
         */
        iterator(Matrice2D<T>* matrice, int indice): mat(matrice), index(indice) { }

        /**
         * Operatore di Disuguaglianza
         * @brief Effettua il paragone sugli indici
         */
        const bool operator!=(const iterator &other){
          #ifdef DEBUG
            std::cout << "Iterator IN OPERATOR !=" << std::endl;
          #endif
          return index != other.index;
        }

        /**
         * Operatore di Uguaglianza
         * @brief Effettua il paragone sugli indici
         */
        const bool operator==(const iterator &other){
          #ifdef DEBUG
            std::cout << "Iterator IN OPERATOR ==" << std::endl;
          #endif
          return index == other.index;
        }

        /**
         * Operatore di Dereference
         * @brief Effettua il paragone sugli indici
         */
        reference operator*(){
          #ifdef DEBUG
            std::cout << "IN OPERATOR*" << std::endl;
          #endif
          return (mat->arrayFisico[index]);
        }

        /**
         * Operatore freccia
         * @brief Effettua il paragone sugli indici
         */
        pointer operator->(){
          #ifdef DEBUG
            std::cout << "Iterator IN OPERATOR ->" << std::endl;
          #endif
          return *mat->arrayFisico[index];
        }

        /**
         * Operatore post-incremento
         */
        const iterator operator++(int) {
          #ifdef DEBUG
            std::cout << "Iterator IN OPERATOR POST INCREMENTO" << std::endl;
          #endif
          iterator temp = *this;
          ++*this;
          return temp;
        }

        /**
         * Operatore pre-incremento
         */
        iterator& operator++() {
          #ifdef DEBUG
            std::cout << "Iterator IN OPERATOR PRE INCREMENTO" << std::endl;
          #endif
          ++index;
          return *this;
        }

        /**
         * Operatore post-decremento
         */
        const iterator operator--(int) {
          #ifdef DEBUG
            std::cout << "Iterator IN OPERATOR POST INCREMENTO" << std::endl;
          #endif
          iterator temp = *this;
          --*this;
          return temp;
        }

        /**
         * Operatore pre-decremento
         */
        iterator& operator--() {
          #ifdef DEBUG
            std::cout << "Iterator IN OPERATOR PRE INCREMENTO" << std::endl;
          #endif
          --index;
          return *this;
        }
    };

    /**
     * Restituisce l'iteratore di inizio
     */
    iterator begin(){
        return iterator(this,0);
    }

    /**
     * Restituisce l'iteratore di fine
     */
    iterator end(){
        return iterator(this, l_x * l_y);
    }

/** DEBUG METHODS **/
  /**
   * Riempie la matrice di numeri sequenziali a partire da count
   * @param count numero da cui cominciare
   */
    void test_init(int count =0){
      #ifdef DEBUG
        std::cout << "Test Initi" << std::endl;
      #endif
      for(int x = 0; x <l_x; x++){
        for(int y = 0; y <l_y; y++){
            arrayFisico[x * l_x + y] = count++;
            #ifdef DEBUG
              std::cout << count << std::endl;
            #endif
        }
      }
    }
    /**
     * Stampa a schermo tutti i valori della matrice
     */
    void test_print(){
      #ifdef DEBUG
        std::cout << "Test Print" << std::endl;
        std::cout << "LX LY LZ" << std::endl;
        std::cout << l_x << l_y << std::endl;
      #endif
      for(int x = 0; x < l_x; x++){
        for(int y = 0; y < l_y; y++){
            std::cout << arrayFisico[x * l_x + y] << std::endl;
        }
      }
      #ifdef DEBUG
        std::cout << "END Test Print" << std::endl;
      #endif
    }
}; //Class Matrice2D


template<class T>
template<class T2>
Matrice2D<T>::operator Matrice2D<T2>(){
  #ifdef DEBUG
    std::cout << "Inizia Matrice2D<T>::operator Matrice2D<T2>()" << std::endl;
    std::cout << arrayFisico[0] << std::endl;
    std::cout << "Array0" << std::endl;
  #endif
  return Matrice2D<T2>(arrayFisico, l_x, l_y);
}

/**
 * Scambia i contenuti tra due matrici
 */
template <class T> void Matrice2D<T>::swap(Matrice2D &other) {
  std::swap(other.arrayFisico, this->arrayFisico);
	std::swap(other.l_x, this->l_x);
  std::swap(other.l_y, this->l_y);
}
#endif
