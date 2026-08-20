#include "Pong.hpp"
#include "Mapa.hpp"
#include "Tetris.hpp"
#include "Menu.hpp"
#include "SnakeGame.hpp"
#include <ctime>
#include <cstdlib>

void sementear(){
    srand(static_cast<unsigned int>(time(NULL)));
}

int main(){
    sementear();

    Gerenciadores::GerenciadorGrafico* pGG = Gerenciadores::GerenciadorGrafico::getInstance();

    while(pGG->windowopen()){
        Menu menu;
        EscolhaJogo escolha = menu.executar();

        if(escolha == EscolhaJogo::TETRIS){
            Tetris tetris;
            tetris.executar();
        } else if(escolha == EscolhaJogo::PONG){
            Pong jogo;
            jogo.executar();
        } else if(escolha == EscolhaJogo::SNAKE){
            SnakeGame snake;
            snake.executar();
        } else {
            break; // SAIR ou janela fechada
        }
    }

    return 0;
}
