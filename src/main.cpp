#include "Pong.hpp"
#include "Mapa.hpp"
#include "Tetris.hpp"

void sementear(){
    srand(static_cast<unsigned int>(time(NULL)));
}
int main(){
    sementear();
    //Pong jogo;
    //jogo.executar();
    
    Tetris tetris;
    tetris.executar();
    
    return 0;
}
