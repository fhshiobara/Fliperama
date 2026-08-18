
#include "Pong.hpp"
#include "Mapa.hpp"
#include "Tetris.hpp"
#include "Menu.hpp"
#include "MapaSnake.hpp"

void sementear(){
    srand(static_cast<unsigned int>(time(NULL)));
}

int main(){
    sementear();
    MapaSnake mapa;
    mapa.print();
    

    Gerenciadores::GerenciadorGrafico* pGG = Gerenciadores::GerenciadorGrafico::getInstance();

    while(pGG->windowopen()){
        /*Menu menu;
        EscolhaJogo escolha = menu.executar();

        if(escolha == EscolhaJogo::TETRIS){
            Tetris tetris;
            tetris.executar();
        } else if(escolha == EscolhaJogo::PONG){
            Pong jogo;
            jogo.executar();
        } else {
            break; // SAIR, ou janela fechada no próprio menu
        }*/
        mapa.draw();
    }


    return 0;
}
