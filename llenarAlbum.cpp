#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void cambiaSobre(Album A, Album B);
class Album{
public:
  //metodos
  void CompraSobre(int n_en_sobre);
  void Status(void);
  bool esta_lleno();
  void SobresComprados(void);
  int n_repetidas(void);
  int n_total(void);
  int n_en_album(void);
  void modificarTotal(void);
  void modificarRepetidas(void);
  bool en_album(int lamina);
  //constructor
  Album(int n);
  //atributos
  int n_sobres_comprados;
private:
  //atributos
  int n_total;
  int n_repetidas;
  int n_en_album;
  //punteros, se usan con array
  int *album;
  int *repetidas;
}
//metodos qu retornan atributos
void Album::modificarRepetidas(){
  n_repetidas--;
}
void Album::modificarTotal(){
  n_total++;
}
int Album::n_repetidas(void){
  return n_repetidas;
}
int Album::n_total(void){
  return n_total;
}
int Album::n_en_album(void){
  return n_en_album;
}
//metodos de la clase

bool Album::en_album(int lamina){
  if (album[lamina]==0){
    return true;
  }
  else{
    return false;
  }
}

void Album::Status(void){
  cout <<n_en_album << " "<<n_repetidas << endl;
}

void Album::SobresComprados(void){
  cout << "Sobres comprados " << n_sobres_comprados << endl;
}

void Album::CompraSobre(int n_en_sobre){
  int lamina;
  n_sobres_comprados++;
  for(int i=0;i<n_en_sobre;i++){
    lamina = rand()%n_total;
    if(album[lamina]==0){
      album[lamina] = 1;
      n_en_album++;
    }else{
      repetidas[lamina] +=1;
      n_repetidas++;
    }
  }
}

//verifica si el album esta lleno
bool Album::esta_lleno(void){
  if(n_total==n_en_album){
    return true;
  }
  else{
    return false;
  }
}

//inicializa el Album con todos los valores de los atributos
Album::Album(int n){
  album = new int[n];
  repetidas = new int[n];
  n_total = n;
  n_repetidas = 0;
  n_en_album = 0;
  n_sobres_comprados=0;

  for (int i=0;i<n_total;i++){
    album[i] = 0;
    repetidas[i] = 0;
  }
}
//main
int main(){
  //se inicializa el srand que genera los numeros aleatorios
  srand(time(0));

  Album A(660);
  Album B(660);

  while(!A.esta_lleno() and !B.esta_lleno()){
    A.CompraSobre(5);
    B.CompraSobre(5);
    A.cambiaSobre(A,B);
  }
  A.SobresComprados();
  B.SobresComprados();

}

//metodos
void cambiaSobre(Album A, Album B){
  int lamina;
  while (i <= 5){
    lamina = rand()%n_total;
    if (!A.en_album(lamina) and B.en_album(lamina)){
      A.modificarRepetidas();
      B.modificarTotal();
    }
    if(A.en_album(lamina) and !B.en_album(lamina)){
      B.modificarRepetidas();
      A.modificarTotal();
    }
  }






















}
