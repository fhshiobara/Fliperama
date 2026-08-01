#include "Pong.hpp"

void sementear(){
    srand(static_cast<unsigned int>(time(NULL)));
}
int main(){
    sementear();
    Pong jogo;
    
    jogo.executar();
    
    return 0;
}
