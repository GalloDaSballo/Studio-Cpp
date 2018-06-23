/**
 *  Alessandro Valerani 758717 a.valerani@campus.unimib.it
 */

#include <iostream> //cout
#include <iterator> //categorie degli iterator
#include <algorithm> //Swap
#include "mat2D.h" //Per la slice


#ifndef MAT3DLIN_H
#define MAT3DLIN_H

template
<class T>
class Matrice3D
{
  private:
    T* arrayFisico; //Array è flat
    int l_x;
    int l_y;
    int l_z; //z è unico alla 3d

  public:

    /**
     * @brief Costruttore di default
     */
    Matrice3D(){
      l_x = l_y = l_z = 2;
      arrayFisico = new T[l_x * l_y * l_z];
    }


    /**
     * Costruttore secondario
     * @brief costruisce una matrice vuota
     *
     * @param il_x lunghezza asse x
     * @param il_y lunghezza asse y
     * @param il_z lunghezza asse z
     */
    Matrice3D(int il_z, int il_y, int il_x){
      l_z = il_z;
      l_y = il_y;
      il_x = il_x;
      arrayFisico = new T[l_x * l_y * l_z];
    }

    /**
     * @brief Costruttore di copia
     */
    Matrice3D(const Matrice3D &other){
      l_x = other.l_x;
      l_y = other.l_y;
      l_z = other.l_z;
      arrayFisico = new T[l_z * l_y * l_x];

      for(int i = 0; i < l_z * l_y * l_x; i++){
        arrayFisico[i] = other.arrayFisico[i];
      }
    }

    // /**
    //  * @brief Costruttore secondario
    //  * A partire da un array costruisce la matrice associata
    //  *
    //  * @param arr flat array di elementi da copiare
    //  * @param il_x lunghezza asse x
    //  * @param il_y lunghezza asse y
    //  * @param il_z lunghezza asse z
    //  */
    //  Matrice3D(T* arr, int il_x, int il_y, int il_z){
    //    l_x = il_x;
    //    l_y = il_y;
    //    l_z = il_z;
    //    std::cout << "Var locali" << std::endl;
    //    std::cout << l_z << std::endl;
    //    arrayFisico = new T[l_z * l_y * l_x];
    //    std::cout << "Var locali" << std::endl;
    //
    //    std::cout << "arr[0];" << std::endl;
    //    std::cout << arr[0] << std::endl;
    //    std::cout << "arr[0];" << std::endl;
    //    for (int z = 0; z < l_z; z++){
    //      for (int y = 0; y < l_y; y++){
    //        for (int x = 0; x < l_x; x++){
    //          std::cout << "Stampo Prima" << std::endl;
    //          std::cout << arr[z][y][x] << std::endl;
    //          arrayFisico[z * l_z * l_y + y * l_y + x] = arr[z][y][x];
    //          std::cout << "Stampo Dopo" << std::endl;
    //          std::cout << arrayFisico[z * l_z * l_y + y * l_y + x] << std::endl;
    //        }
    //      }
    //    }
    //  }


    /**
     * @brief Costruttore secondario
     * A partire da un array piatto (monodimensionale) costruisce la matrice associata
     *
     * @param arr flat array di elementi da copiare
     * @param il_x lunghezza asse x
     * @param il_y lunghezza asse y
     * @param il_z lunghezza asse z
     */
    template<class T2>
    Matrice3D(T2* arr, int il_x, int il_y, int il_z){
      #ifdef DEBUG
        std::cout << "Inizia template<class T2> Matrice3D(T2* arr, int il_x, int il_y)" << std::endl;
      #endif
      l_x = il_x;
      l_y = il_y;
      l_z = il_z;

      #ifdef DEBUG
        std::cout << "Var locali" << std::endl;
        std::cout << l_z << std::endl;
      #endif

      arrayFisico = new T[l_z * l_y * l_x];

      #ifdef DEBUG
        std::cout << "Var locali" << std::endl;
        std::cout << "arr[0];" << std::endl;
        std::cout << arr[0] << std::endl;
        std::cout << "arr[0];" << std::endl;
      #endif
      for(int xyz = 0; xyz < l_x * l_y * l_z; xyz++){
        #ifdef DEBUG
          std::cout << "Stampo Prima" << std::endl;
          std::cout << arr[xyz] << std::endl;
        #endif

        arrayFisico[xyz] = arr[xyz];

        #ifdef DEBUG
          std::cout << "Stampo Dopo" << std::endl;
          std::cout << arrayFisico[xyz] << std::endl;
        #endif
      }
    }

    /**
     * Operatore di Conversione
     */
    template<class T2>operator Matrice3D<T2>();

    /**
  	 * Operatore di assegnamento
  	 * @param other Matrice3D da copiare
  	 * @return reference a this
  	 * @throw eccezione di allocazione di memoria
  	*/
  	Matrice3D& operator=(const Matrice3D &other) {
      if (this != &other) {
        Matrice3D tmp(other);
        this->swap(tmp);
      }
      #ifdef DEBUG
        std::cout << "Matrice3D::operator=(const Matrice3D&)" << std::endl;
      #endif
      return *this;
  	}

    ~Matrice3D(){
      delete[] arrayFisico;
    }

    /**
     * @brief Scambia il contenuto di due Matrici3D
     * Scambia il contenuto di due Matrici3D.
     * @param other Matrice3D con il quale scambiare i dati
    **/
  	void swap(Matrice3D &other);

    /**
     * @return il valore alla cella (y,x)
     */
    T& operator()(int z, int y, int x){
        return arrayFisico[z * l_z * l_y + y * l_y + x];
    }


    /**
     * @brief Seziona dal piano z e restiuisce la matrice2D
     * @param  z il piano lungo il quale tagliare
     * @return   la matrice2D del piano corrispondente
     */
    Matrice2D<T> slice(int z){
      #ifdef DEBUG
        std::cout << "Slice Test" << std::endl;
      #endif

      T tempArr[l_y * l_x];
      int counter = 0;
      for(int x = 0; x < l_x; x++){
        for(int y = 0; y < l_y; y++){
          #ifdef DEBUG
            //Non c'è loop per Z perché ce né solo uno ad ogni loop
            std::cout << arrayFisico[x * l_x * l_y + y * l_y] << std::endl;
          #endif
          tempArr[counter++] = arrayFisico[x * l_x * l_y + y * l_y];
         }
       }
      return Matrice2D<T>(tempArr, l_x, l_y);
     }

     /**
      * Class: iterator
      *
      * @brief Permette l'accesso in sola lettura ai dati ordinati
      */
    class iterator{
        Matrice3D* mat;
        int index;
        friend class Matrice3D;
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
        iterator(Matrice3D<T>* matrice, int indice): mat(matrice), index(indice) { }

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
        return iterator(this, l_x * l_y * l_z);
    }

/** DEBUG METHODS **/
    /**
     * Riempie la matrice di numeri sequenziali a partire da count
     * @param count numero da cui cominciare
     */
    void test_init(){
      #ifdef DEBUG
        std::cout << "Test Initi" << std::endl;
      #endif
      int count =8;
      for(int x = 0; x <l_x; x++){
        for(int y = 0; y <l_y; y++){
          for(int z = 0; z < l_z; z++){
            arrayFisico[x * l_x * l_y + y * l_y + z] = count;
            #ifdef DEBUG
              std::cout << count << std::endl;
            #endif
            count++;
          }
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
        std::cout << l_x << l_y << l_z << std::endl;
      #endif
      for(int x = 0; x < l_x; x++){
        for(int y = 0; y < l_y; y++){
          for(int z = 0; z < l_z; z++){
            std::cout << arrayFisico[x * l_x * l_y + y * l_y + z] << std::endl;
          }
        }
      }
      #ifdef DEBUG
        std::cout << "END Test Print" << std::endl;
      #endif
    }



}; //Class Matrice3D


template<class T>
template<class T2>
Matrice3D<T>::operator Matrice3D<T2>(){
  #ifdef DEBUG
    std::cout << "Inizia Matrice3D<T>::operator Matrice3D<T2>()" << std::endl;
    std::cout << arrayFisico[0] << std::endl;
    std::cout << "Var locali" << std::endl;
    std::cout << l_x << l_z << l_y << std::endl;
  #endif
  return Matrice3D<T2>(arrayFisico, l_x, l_y, l_z);
}

/**
 * Scambia i contenuti tra due matrici
 */
template <class T> void Matrice3D<T>::swap(Matrice3D &other) {
	std::swap(other.arrayFisico, this->arrayFisico);
	std::swap(other.l_x, this->l_x);
  std::swap(other.l_y, this->l_y);
  std::swap(other.l_z, this->l_z);
}




/** CONVERSIONE **/
/**
 * Funtore di conversione che applica il casting della matrice da un tipo T ad un tipo T2
 * @brief Funtore di conversione da tipo T a tipo T2
 * @return una Matrice3D<T2>
 */
template <typename T2, typename T>
struct funtore {
    Matrice3D<T2> operator()(Matrice3D<T> a) {
        return (Matrice3D<T2>)a;
    }
};

/**
 * @brief Converte una matrice da un tipo ad un altro tramite un Funtore
 * @param mat Matrice3D da convertire
 * @param fun il funtore da applicare
 */
template <class T, class T2, class F>
 Matrice3D<T2> trasforma(Matrice3D<T> A, F fun){
  return fun(A);
}
#endif
