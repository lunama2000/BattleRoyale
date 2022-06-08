#include <iostream>
#include <string>
#include <random>

using namespace std;

struct Player
{
    string nombre;
    int vida, ataque, defensa, armadura;
}player[8];

void LlenarNombres()
{
    for (int i = 0; i < 8; i++)
    {
        cout << "Escribe tu el nombre del jugador " << i + 1 << endl;
        cin >> player[i].nombre;
    }
}

void stats()
{
    for (int i = 0; i < 8; i++)
    {
        player[i].vida = rand() % 10;
        player[i].ataque = rand() % 10;
        player[i].defensa = rand() % 10;
        player[i].armadura = rand() % 10;
        cout << "Stats de " << player[i].nombre << endl;
        cout << "  *Vida: " << player[i].vida << endl;
        cout << "  *Ataque es: " << player[i].ataque << endl;
        cout << "  *Defensa es: " << player[i].defensa << endl;
        cout << "  *Armadura es: " << player[i].armadura << endl;
        cout << endl;
    }
}

void Resultados()
{
  int maxIndex[4] = {0,0,0,0};
  int minIndex[4] = {0,0,0,0};

  for(int i = 0; i < 8; i++){
    if(player[i].vida >= player[maxIndex[0]].vida){
      maxIndex[0] = i;
    }
    if(player[i].ataque >= player[maxIndex[1]].ataque){
      maxIndex[1] = i;
    }
    if(player[i].defensa >= player[maxIndex[2]].defensa){
      maxIndex[2] = i;
    }
    if(player[i].armadura >= player[maxIndex[3]].armadura){
      maxIndex[3] = i;
    }
  } 
cout << "___Ganadores___" << endl;
  cout << player[maxIndex[0]].nombre << " es el jugador con mayor vida" << endl;
  cout << player[maxIndex[1]].nombre << " es el jugador con mayor ataque" << endl;
  cout << player[maxIndex[2]].nombre << " es el jugador con mayor defensa" << endl;
  cout << player[maxIndex[3]].nombre << " es el jugador con mayor armadura"<< endl << endl;

  for(int i = 0; i < 8; i++){
    if(player[i].vida <= player[minIndex[0]].vida){
      minIndex[0] = i;
    }
    if(player[i].ataque <= player[minIndex[1]].ataque){
      minIndex[1] = i;
    }
    if(player[i].defensa <= player[minIndex[2]].defensa){
      minIndex[2] = i;
    }
    if(player[i].armadura <= player[minIndex[3]].armadura){
      minIndex[3] = i;
    }
  } 

cout << "___Perdedores___" << endl;
  cout << player[minIndex[0]].nombre << " es el jugador con menos vida" << endl;
  cout << player[minIndex[1]].nombre << " es el jugador con menos ataque" << endl;
  cout << player[minIndex[2]].nombre << " es el jugador con menos defensa" << endl;
  cout << player[minIndex[3]].nombre << " es el jugador con menos armadura"<< endl << endl;
}

int main()
{
    srand(time(NULL));
    LlenarNombres();
    cout << "Estas son las stats:" << endl << endl;
    stats();
    Resultados();
  return 0;
}