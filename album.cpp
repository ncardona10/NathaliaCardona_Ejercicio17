#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Album{
public:
  //metodos
  void CompraSobre(int n_en_sobre);
  void Status(void);
  bool esta_lleno();
  void SobresComprados(void);
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
};
//declarar un metodo de la clase album
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



int main(){
  //se inicializa el srand que genera los numeros aleatorios
  srand(time(0));
  //inicializa album con el numero de espacios para llenar
  /*
  Album A(660);
  for(int i=0;i<160;i++){
    A.CompraSobre(5);
    A.Status();
  }
  */
  Album A(660);
  while(!A.esta_lleno()){
    A.CompraSobre(5);
  }
  A.SobresComprados();

}
