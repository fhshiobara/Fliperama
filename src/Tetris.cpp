//
//  Tetris.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 02/08/26.
//

#include "Tetris.hpp"
#include <string>
Tetris::Tetris():pGG(Gerenciadores::GerenciadorGrafico::getInstance()),fundo(NULL),grid(NULL),indicePeca(0),intervaloQueda(0.5f),gameOver(false),ponto(NULL),pts(0),voltarMenu(false){
    criarCenario();
    criarPecas();
    criarTextos();
}

Tetris::~Tetris(){
    if(fundo!=NULL){
        delete fundo;
        fundo = NULL;
        
    }
    if(grid!=NULL){
        delete grid;
        grid = NULL;
    }
    for(it = pecas.begin();it!=pecas.end();it++){
        delete (*it);
    }
    if(ponto!=NULL){
        delete ponto;
        ponto = NULL;
    }
    pecas.clear();
}

void Tetris::criarCenario(){
    sf::Color corFundo(58,47,85);
        fundo = new sf::RectangleShape;
        fundo->setOrigin(0.f,0.f);
        fundo->setSize(sf::Vector2f(1280.f,720.f));
        fundo->setFillColor(corFundo);
        
        grid = new sf::RectangleShape;
        grid->setOrigin(0.f,0.f);
        grid->setSize(sf::Vector2f(300.f,600.f));
        grid->setPosition(490.f,61.f);
        grid->setFillColor(sf::Color(43,26,74));
    
        ponto = new sf::RectangleShape;
        ponto->setOrigin(0.f,0.f);
        ponto->setSize(sf::Vector2f(120.f,120.f));
        ponto->setPosition(800.f,61.f);
        ponto->setFillColor(sf::Color(20,10,46));

}
void Tetris::criarPecas(){
    pecas.push_back(new BlocoJ()); // tecla 1
    pecas.push_back(new BlocoQ()); // tecla 2
    pecas.push_back(new BlocoL()); // tecla 3
    pecas.push_back(new BlocoI()); // tecla 4
    pecas.push_back(new BlocoT()); // tecla 5
    pecas.push_back(new BlocoS()); // tecla 6
    pecas.push_back(new BlocoZ()); // tecla 7
    
    for(it = pecas.begin();it!=pecas.end();it++){
        (*it)->setMapa(&mapa);
    }
}

void Tetris::tratarEventos(){
    sf::Event event;
    while(pGG->getWindow()->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            pGG->closeWindow();
        }
        if(event.type == sf::Event::KeyPressed){

            if(event.key.code == sf::Keyboard::Escape){
                voltarMenu = true;
                continue;
            }

            if(gameOver){
                if(event.key.code == sf::Keyboard::Enter){
                    reiniciar();
                }
                continue;
            }

            switch(event.key.code){
                    /*
                                    case sf::Keyboard::Num1:
                                        indicePeca = 0;
                                        pecas[indicePeca]->resetOffset();
                                        pecas[indicePeca]->setEstado(0);
                                        break;
                                    case sf::Keyboard::Num2:
                                        indicePeca = 1;
                                        pecas[indicePeca]->resetOffset();
                                        pecas[indicePeca]->setEstado(0);
                                        break;
                                    case sf::Keyboard::Num3:
                                        indicePeca = 2;
                                        pecas[indicePeca]->resetOffset();
                                        pecas[indicePeca]->setEstado(0);
                                        break;
                                    case sf::Keyboard::Num4:
                                        indicePeca = 3;
                                        pecas[indicePeca]->resetOffset();
                                        pecas[indicePeca]->setEstado(0);
                                        break;
                                    case sf::Keyboard::Num5:
                                        indicePeca = 4;
                                        pecas[indicePeca]->resetOffset();
                                        pecas[indicePeca]->setEstado(0);
                                        break;
                                    case sf::Keyboard::Num6:
                                        indicePeca = 5;
                                        pecas[indicePeca]->resetOffset();
                                        pecas[indicePeca]->setEstado(0);
                                        break;
                                    case sf::Keyboard::Num7:
                                        indicePeca = 6;
                                        pecas[indicePeca]->resetOffset();
                                        pecas[indicePeca]->setEstado(0);
                                        break;*/
                case sf::Keyboard::R:{
                    int estadoAtual = pecas[indicePeca]->getEstado();
                    pecas[indicePeca]->setEstado((estadoAtual+1)%4);
                    break;
                }
                case sf::Keyboard::Left:
                    if(pecas[indicePeca]->podeMover(0,-1)) pecas[indicePeca]->mover(0,-1);
                    break;
                case sf::Keyboard::Right:
                    if(pecas[indicePeca]->podeMover(0,1)) pecas[indicePeca]->mover(0,1);
                    break;
                case sf::Keyboard::Down:
                    if(pecas[indicePeca]->podeMover(1,0)) pecas[indicePeca]->mover(1,0);
                    break;
                default: break;
            }
        }
    }
}

void Tetris::atualizar(){
    if(gameOver) return;

    mapa.copiarFixoParaMapa();

    if(clockQueda.getElapsedTime().asSeconds() >= intervaloQueda){
        Blocos* pecaAtual = pecas[indicePeca];
        if(pecaAtual->podeMover(1,0)){
            pecaAtual->mover(1,0);
        } else {
            mapa.fixarCelulas(pecaAtual->getCellPositions(), pecaAtual->getId());
            int linhasRemovidas = mapa.limparLinhasCompletas();
            if(linhasRemovidas > 0){
                atualizarPontuacao(linhasRemovidas);
            }

            pecaAtual->resetOffset();
            pecaAtual->setEstado(0);

            pecaAtual->resetOffset();
            pecaAtual->setEstado(0);

            indicePeca = proximaPeca();
            Blocos* proxima = pecas[indicePeca];
            proxima->resetOffset();
            proxima->setEstado(0);

            if(!proxima->podeMover(0,0)){
                gameOver = true;
            }
        }
        clockQueda.restart();
    }
}
void Tetris::desenhar(){
    pGG->clear();
    pGG->render(fundo);
    pGG->render(grid);
    pGG->render(ponto);
    pGG->render(&pontos);

    if(!gameOver){
        pecas[indicePeca]->draw();
    }
    mapa.draw();

    if(gameOver){
        pGG->render(&txtGameOver);
        pGG->render(&txtReiniciar);
    }

    pGG->display();
}

void Tetris::executar(){
    while(pGG->windowopen() && !voltarMenu){
        tratarEventos();
        atualizar();
        desenhar();
    }
}

void Tetris::criarTextos(){
    sf::Font* fonte = pGG->getFont();
    if(fonte != NULL){
        txtGameOver.setFont(*fonte);
        txtGameOver.setString("GAME OVER");
        txtGameOver.setCharacterSize(40);
        txtGameOver.setFillColor(sf::Color::White);
        txtGameOver.setPosition(500.f, 320.f);

        txtReiniciar.setFont(*fonte);
        txtReiniciar.setString("Pressione ENTER para reiniciar");
        txtReiniciar.setCharacterSize(18);
        txtReiniciar.setFillColor(sf::Color::White);
        txtReiniciar.setPosition(465.f, 380.f);

        pontos.setFont(*fonte);
        pontos.setString("PONTOS\n0");
        pontos.setCharacterSize(18);
        pontos.setFillColor(sf::Color::White);
        pontos.setPosition(ponto->getPosition().x + 10.f, ponto->getPosition().y + 10.f);
    }
}

void Tetris::reiniciar(){
    mapa.inicializarFixo();
    for(it = pecas.begin(); it!=pecas.end(); it++){
        (*it)->resetOffset();
        (*it)->setEstado(0);
    }
    indicePeca = proximaPeca();
    gameOver = false;
    pts = 0;
    pontos.setString("PONTOS\n0");
    clockQueda.restart();
}


void Tetris::reabastecerSaco(){
    saco.clear();
    for(int i=0; i<(int)pecas.size(); i++) saco.push_back(i);
    for(int i=(int)saco.size()-1; i>0; i--){
        int j = rand()%(i+1);
        std::swap(saco[i], saco[j]);
    }
}

int Tetris::proximaPeca(){
    if(saco.empty()){
        reabastecerSaco();
    }
    int prox = saco.back();
    saco.pop_back();
    return prox;
}
void Tetris::atualizarPontuacao(int linhas){
    switch(linhas){
        case 1: pts += 40;   break;
        case 2: pts += 100;  break;
        case 3: pts += 300;  break;
        case 4: pts += 1200; break; // Tetris de 4 linhas
        default: break;
    }
    pontos.setString("PONTOS\n" + std::to_string(pts));
}
