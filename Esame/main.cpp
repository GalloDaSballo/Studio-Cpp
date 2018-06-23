/**
 *  Alessandro Valerani 758717 a.valerani@campus.unimib.it
 * Main per i test metodi fondamentali di Matrice3d
 */


#include "mat3D.h" //Flatten 3d
// #include "matrice2Dlinear.h" //Incluso da mat3D
#include <iostream>
#include <cassert>
using namespace std;

template <typename T, typename P2>
struct aChar {
    Matrice3D<char> operator()(Matrice3D<P2> a) const {
        return (Matrice3D<char>)a;
    }
};

void test_metodi_fondamentali() {
  cout << "TEST METODI FONDAMENTALI" << endl;
  int con_array[3][3][3] = { {0,1,2}, {3,4,5}, {6,7,8}, };
  int i = 0;
  for(int x = 0; x < 3; x++){
    for(int y = 0; y < 3; y++){
      for(int z = 0; z < 3; z++){
        con_array[x][y][z] = i++;
        std::cout << con_array[x][y][z] << std::endl;
      }
    }
  }

  Matrice3D<int> mat;
  // Con i metodi di test
  mat.test_init();
  mat.test_print();
  // Con i metodi di test

  // Con le parentesi
  Matrice3D<char> abc;
  abc(0,0,0) = 'a'; cout << abc(0,0,0) << endl;
  abc(0,0,1) = 'b'; cout << abc(0,0,1) << endl;
  abc(0,1,0) = 'c'; cout << abc(0,1,0) << endl;
  abc(0,1,1) = 'd'; cout << abc(0,1,1) << endl;
  abc(1,0,0) = 'e'; cout << abc(1,0,0) << endl;
  abc(1,0,1) = 'f'; cout << abc(1,0,1) << endl;
  abc(1,1,0) = 'g'; cout << abc(1,1,0) << endl;
  abc(1,1,1) = abc(0,0,0); cout << abc(0,0,0) << endl;

  char array[2][2][2];
  array[0][0][0] = 'a';
  array[0][0][1] = 'b';
  array[0][1][0] = 'c';
  array[0][1][1] = 'd';
  array[1][0][0] = 'e';
  array[1][0][1] = 'f';
  array[1][1][0] = 'g';
  array[1][1][1] = 'a';

  cout << "Assetions per verificare indici funzionanti" << endl;
  int coutino = 0;
  for(int z = 0; z < 2; z++){
    for(int y = 0; y < 2; y++){
      for(int x = 0; x < 2; x++){
        cout << coutino++ << endl;
        cout << "Array" << endl;
        cout << array[x][y][z] << endl;
        cout << "Abc" << endl;
        cout << abc(x,y,z) << endl;
        assert(array[z][y][x] == abc(z,y,x));
      }
    }
  }

  i = 0;
  Matrice3D<int> gino;
  for(int x = 0; x < 2; x++){
    for(int y = 0; y < 2; y++){
      for(int z = 0; z < 2; z++){
        gino(x,y,z) = i++;
      }
    }
  }
  int ar[2][2][2];
  int a = 0;
  for(int x = 0; x < 2; x++){
    for(int y = 0; y < 2; y++){
      for(int z = 0; z < 2; z++){
        ar[x][y][z] = a++;
      }
    }
  }

  int counter = 0;
  for(int x = 0; x < 2; x++){
    for(int y = 0; y < 2; y++){
      for(int z = 0; z < 2; z++){
        cout << counter++ << endl;
        assert(gino(x,y,z) == ar[x][y][z]);
        assert(gino(z,y,x) == ar[z][y][x]);
      }
    }
  }

  abc.test_print();




  abc(0,0,0) = 109;
  cout << "abc(0,0) = 109" << endl;
  cout << abc(0,0,0) << endl;

  Matrice3D<int> matInt = abc;


  cout << "O la va o la Spacca" << endl;
  cout << "O la va o la Spacca" << endl;
  cout << "O la va o la Spacca" << endl;
  cout << "O la va o la Spacca" << endl;

  cout << matInt(0,0,0) << endl;
  cout << matInt(0,1,1) << endl;
  cout << matInt(0,1,0) << endl;
  cout << matInt(1,1,1) << endl;
  cout << matInt(1,0,0) << endl;
  cout << matInt(1,0,1) << endl;
  cout << matInt(1,1,0) << endl;
  cout << matInt(1,1,1) << endl;

  matInt(0,0,0) = 'm';
  assert(matInt(0,0,0) == 109);

  cout << "DA Mat Int a Mat Char tramite funzione Trasforma" << endl;
  // //DA Mat Int a Mat Char tramite funzione Trasforma
  Matrice3D<char> gin = trasforma<char, int, aChar<char,int> >(matInt, aChar<char,int>() );
  gin.test_print();

  cout << "TEST METODI FONDAMENTALI FINE" << endl;
}

void test_trasforma_converti(){
  cout << "TEST TRASFORMA E CONVERTI FINE" << endl;
  Matrice2D<char> ssud;
  ssud.test_init();

  ssud(0,0) = 'a';
  ssud(0,0) = 'b';
  ssud(0,1) = 'c';
  ssud(0,1) = 'd';
  ssud(1,0) = 'e';
  ssud(1,0) = 'f';
  ssud(1,1) = 'g';
  ssud(1,1) = ssud(0,0);
  ssud.test_print();

  cout << "**Assegnamento Trasforma******" << endl;
  Matrice2D<int> dds;
  dds = ssud;
  dds.test_print();


  cout << "**Test Trasforma**" << endl;
  // Matrice2D<int> anm = trasforma<char, int, aChar<char,int> >(dds, aChar<char,int>() );
  Matrice2D<int> anm = dds;
  anm.test_print();

  cout << "**Test Converti**" << endl;
  Matrice2D<int> mau = ssud;
  cout << "Mau Test Print" << endl;
  mau.test_print();
  cout << "Mat Test Print" << endl;
  ssud.test_print();

  Matrice2D<int>::iterator a, ab;
  a = anm.begin();
  ab = anm.end();

  int random_int = 123;
  while(!(a==ab)){
    *a = random_int++;
    cout << *a << endl;
    ++a;
  }
  anm.test_print();
  cout << "TEST TRASFORMA E CONVERTI FINE" << endl;
}

void test_slice_e_2D(){
  cout << "TEST SLICE E 2D" << endl;
  Matrice3D<int>ts;
  ts.test_init();
  ts.test_print();

  cout << "*** TS Test Slice 0 ***" << endl;
  Matrice2D<int>dueD = ts.slice(0);
  dueD.test_print();

  Matrice2D<int>dueDue = ts.slice(1);
  dueDue.test_print();
  cout << "*** Iteratori 2D ***" << endl;
  Matrice2D<int>::iterator i, ie;
  i = dueDue.begin();
  ie = dueDue.end();
  while(i != ie){
    cout << *i << endl;
    i++;
  }
  cout << "*** Fine test 2D ***" << endl;
  cout << "TEST SLICE E 2D FINE" << endl;
}

void test_iteratori(){
  cout << "TEST ITERATORI" << endl;
  Matrice3D<int>ts;
  ts.test_init();
  ts.test_print();


  cout << "**TS Test ITERATORI Loop **" << endl;
  Matrice3D<int>::iterator i,ie;
  Matrice3D<int>::iterator inizio;
  i = ts.begin();
  ie = ts.end();

  inizio = i; //Copia


  int counter = 0;
  while(i!=ie){
    cout << "Counter " << ++counter << endl;
    cout << "Pre incremento" << endl;
    cout << *i << endl;
    ++i;
    cout << "Post per incremento" << endl;
  }

  Matrice3D<int>::iterator fine = ie; //Copia

  while(inizio!=fine){
    cout << "Counter " << ++counter << endl;
    cout << "Pre incremento" << endl;
    cout << *inizio << endl;
    ++inizio;
    cout << "Post per incremento" << endl;
  }
  cout << "TEST ITERATORI FINE" << endl;
}

void test_slice_iteratore(){
  cout << "TEST SLICE ITERATOR" << endl;
  Matrice3D<int> cd;
  cd.test_init();

  Matrice2D<int> pc = cd.slice(0);
  pc.test_print();

  Matrice2D<int>::iterator i,ie;
  i = pc.begin();
  ie = pc.end();
  --ie;
  ie--;
  bool usato = false;
  int coutn = 0;
  while(i!=ie){
    cout << "Pre incremento" << endl;
    cout << *i << endl;
    ++i;
    coutn++;
    if(usato==false && coutn){
      // --ie;
      // ie--;
      usato = true;
    }
    cout << "Post per incremento" << endl;
  }
  cout << "TEST SLICE ITERATORE FINE" << endl;
}

int main(){
  test_metodi_fondamentali(); //Passa tutto
  test_trasforma_converti(); //Passa tutto
  test_slice_e_2D(); //Passa tutto
  test_iteratori(); //Passa tutto
  test_slice_iteratore(); //Passa tutto
  return 0;
}
