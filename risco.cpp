#include <iostream>
#include <algorithm>

int main() {

 std::cout << "solo puedo ingesar 5 elementos \n";   

 std::cout << "ingrese el minimo de calorias :" ;
 float calorias;
 std::cin >> calorias;
 float peso;
 std::cout << "ingrese el peso maximo:" ;
 std::cin >> peso;  
  
 float arrayPeso[5]{5,3,5,1,2};
 float arrayCalorias[5]{3,5,2,8,3};
/*
 std::cout << "ingrese el peso del primer elemento:";
 std::cin  >> arrayPeso[0];
 std::cout << "ingrese las calorias del primer elemento:";
 std::cin  >> arrayCalorias[0];
 std::cout << "ingrese el peso del segundo elemento:";
 std::cin  >> arrayPeso[1];
 std::cout << "ingrese las calorias del segundo elemento:";
 std::cin  >> arrayCalorias[1];
 std::cout << "ingrese el peso del tercer elemento:";
 std::cin  >> arrayPeso[2];
 std::cout << "ingrese las calorias del tercer elemento:";
 std::cin  >> arrayCalorias[2];
 std::cout << "ingrese el peso del cuarto elemento:";
 std::cin  >> arrayPeso[3];
 std::cout << "ingrese las calorias del cuarto elemento:";
 std::cin  >> arrayCalorias[3];
 std::cout << "ingrese el peso del quinto elemento:";
 std::cin  >> arrayPeso[4];
 std::cout << "ingrese las calorias del quinto elemento:";
 std::cin  >> arrayCalorias[4];
*/

 float proporcion[5];
 float posiciones[5];

 
 std::transform(arrayPeso,arrayPeso+5,arrayCalorias,proporcion,std::divides<float>());

 std::sort(proporcion, proporcion+5);
    
 int sumaPeso     = 0;
 int sumaCalorias = 0;
 int y=0;
 for(int i =0; i<5;i++){ 
    for(int j=0; j<5; j++){
     if(arrayPeso[i]/arrayCalorias[i] == proporcion[j]){
         posiciones[i]= j;
         if (sumaPeso <peso){
             sumaPeso += arrayPeso[j];
             sumaCalorias += arrayCalorias[j];
              if( sumaPeso > peso){
                 sumaPeso -= arrayPeso[j];
                 sumaCalorias -= arrayCalorias[j];
                 y++;
                }
           }
      }
    }
  }
   std::cout << "los elementos viables serian "; 
  for(int i=0; i < 5-y; i++){
    std::cout << "E" << posiciones[i] + 1 << ' ' ;
    }
    std::cout << "ya que su peso seria " << sumaPeso << " y brindan " << sumaCalorias << " calorias \n"; 

}
