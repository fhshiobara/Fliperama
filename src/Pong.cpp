//
//  Pong.cpp
//  Fliperama
//
//  Created by Edison Shiobara on 19/07/26.
//

#include "Pong.hpp"

Pong::Pong():R1(NULL),R2(NULL),bola(NULL),pGG(Gerenciadores::GerenciadorGrafico::getInstance()),G1(NULL),G2(NULL),pV(NULL),pT(NULL),dt(0){
    R1 = new Raquete(CoordF(5.f,5.f), CoordF(25.f,100.f));
    R2 = new Raquete(CoordF(5.f,5.f), CoordF (25.f,100.f));
    G1 = new Gol(CoordF(1250.f,0.f));
    G2 = new Gol(CoordF(0.f,0.f));
    //pV = new PoderVelocidade;
    bola = new Bola(CoordF(10.f,05.f),8.f);
    bola->setTamJanela(CoordF(1280.f,720.f));
    bola->setRaquete(R1);
    bola->setRaquete(R2);
    bola->setGol(G1);
    bola->setGol(G2);
    
    txtPoderes.setString("?");
    txtPoderes2.setString("?");
    txtTutorial.setString("Bem-vindo ao Pong!\n\n"
                          "O objetivo e simples: acerte a bola no gol do seu\n"
                          "adversario antes que ele acerte o seu. Quem fizer\n"
                          "5 pontos primeiro, vence!\n\n"
                          "Controles:\n"
                          "Raquete da esquerda: W (sobe) e S (desce)\n"
                          "Raquete da direita: seta para cima (sobe) e seta para baixo (desce)\n\n"
                          "Aperte espaco para lancar a bola. Fique de olho nos poderes\n"
                          "que aparecem na tela - eles podem mudar sua velocidade ou\n"
                          "o tamanho da sua raquete!\n\n"
                          "O tempo de jogo sera mostrado no canto superior esquerdo \n\n\n"
                          "Boa sorte, e que venca o melhor.\n\n"
                          "Pressione ENTER para comecar");
    
    
    
    this->setPosInicial();
    
    sf::Font* fonte = pGG->getFont();
    if(fonte != NULL){
        txtG1.setFont(*fonte);
        txtG1.setCharacterSize(48);
        txtG1.setFillColor(sf::Color::White);
        txtG1.setPosition(1280.f/2.f - 80.f, 20.f);
        
        
        txtG2.setFont(*fonte);
        txtG2.setCharacterSize(48);
        txtG2.setFillColor(sf::Color::White);
        txtG2.setPosition(1280.f/2.f + 40.f, 20.f);
        
        txtDt.setFont(*fonte);
        txtDt.setCharacterSize(48);
        txtDt.setFillColor(sf::Color::White);
        txtDt.setPosition(50.f, 20.f);
        
        txtTutorial.setFont(*fonte);
        txtTutorial.setCharacterSize(30);
        txtTutorial.setFillColor(sf::Color::White);
        sf::FloatRect bounds = txtTutorial.getLocalBounds();
                txtTutorial.setOrigin(bounds.left+bounds.width/2.f, bounds.top + bounds.height/2.f);
                txtTutorial.setPosition(1280.f/2.f, 720.f/2.f);
        
    }
    
    
}

Pong::~Pong(){
    if(R1!=NULL){
        delete R1;
        R1 = NULL;
    }
    if(R2!=NULL){
        delete R2;
        R2 = NULL;
    }
    if(bola!=NULL){
        delete bola;
        bola = NULL;
    }
    if(G1!=NULL){
        delete G1;
        G1 = NULL;
    }
    if(G2!=NULL){
        delete G2;
        G2 = NULL;
    }
    if(pV!=NULL){
        delete pV;
        pV = NULL;
    }
    if(pT!=NULL){
        delete pT;
        pT = NULL;
    }
    
}

void Pong::setPosInicial(){
    R1->setPos(CoordF(85.f,360.f));
    R2->setPos(CoordF(1180.f,360.f));
    bola->setPos(CoordF(85.f,300.f));
    
    
    //preciso aleatorizar a posicao de spawn
    //a partir do meio ele vai poder spawnar mais ou menos um valor aleatorio
    //a mesma coisa para cima e para baixo
    
}

void Pong::executar(){
    sf::Event event;
    telaTutorial();
    while(pGG->windowopen()){
  
        while(pGG->getWindow()->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                pGG->closeWindow();
            }
                    
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::W) R1->moveCima = true;
                if(event.key.code == sf::Keyboard::S) R1->moveBaixo = true;
                        //----
                if(event.key.code == sf::Keyboard::Up)   R2->moveCima = true;
                if(event.key.code == sf::Keyboard::Down) R2->moveBaixo = true;
                
                if(event.key.code == sf::Keyboard::Space){
                    int aux = rand()%2; // 0 ou 1;
                    if(aux == 0){
                        aux = -1;
                    }
                    if(bola->getVelocidade().x==0.f && bola->getVelocidade().y==0.f){
                        
                        bola->setVelocidade(CoordF(bola->getVelocidadePadrao().x*aux,bola->getVelocidadePadrao().y*aux));
                    }
                }
                
                if(event.key.code == sf::Keyboard::Escape){
                    pGG->closeWindow();//serve apenas para fechar a janela
                }
            }
                    
            if(event.type == sf::Event::KeyReleased){
                if(event.key.code == sf::Keyboard::W) R1->moveCima = false;
                if(event.key.code == sf::Keyboard::S) R1->moveBaixo = false;
                        //------
                if(event.key.code == sf::Keyboard::Up)   R2->moveCima = false;
                if(event.key.code == sf::Keyboard::Down) R2->moveBaixo = false;
            }
        }
        if(bola->getVelocidade().x!=0.f && bola->getVelocidade().y!=0.f){
            dt = dt+1;
        }
        
        if(dt%501==0){
            int aux = rand()%2;
            if(aux ==1){
                pV = new PoderVelocidade;
                int auxX = (rand()%400)-200;
                int auxY = (rand()%400)-200;
                pV->setTamanho(CoordF(70.f,70.f));
                
                
                pV->setPos(CoordF(640.f+auxX,360.f-auxY));
                bola->setPoderes(pV);
                sf::Font* fonte = pGG->getFont();
                if(fonte != NULL){
                    txtPoderes.setFont(*fonte);
                    txtPoderes.setCharacterSize(48);
                    txtPoderes.setFillColor(sf::Color::White);
                    //nao tenho a menor ideia de porque isso nao esta funcionando, vou fazer no pelo mais uma vez
                    //txtPoderes.setPosition(pT->getPos().x+(pT->getTamanho().x)/2, pT->getPos().y-(pT->getTamanho().y)/2);
                    txtPoderes.setPosition(pV->getPos().x+(pV->getTamanho().x-16)/2,pV->getPos().y);
                }
                
            }
            else if(aux==0){
                    pT = new PoderTamanho;
                    int auxX = (rand()%400)-200;
                    int auxY = (rand()%400)-200;
                    pT->setTamanho(CoordF(70.f,70.f));
                    pT->setPos(CoordF(640.f+auxX,360.f-auxY));
                    bola->setPoderes(pT);
                    
                    sf::Font* fonte = pGG->getFont();
                    if(fonte != NULL){
                        txtPoderes2.setFont(*fonte);
                        txtPoderes2.setCharacterSize(48);
                        txtPoderes2.setFillColor(sf::Color::White);
                        //nao tenho a menor ideia de porque isso nao esta funcionando, vou fazer no pelo mais uma vez
                        //txtPoderes.setPosition(pT->getPos().x+(pT->getTamanho().x)/2, pT->getPos().y-(pT->getTamanho().y)/2);
                        txtPoderes2.setPosition(pT->getPos().x+(pT->getTamanho().x-16)/2,pT->getPos().y);
                    }
                    
                    
                
            }
            
        }
        pGG->clear();
        

        R1->mover();
        R2->mover();
        bola->mover();
        bola->tratarColisaoParede();
        bola->tratarColisaoRaquete();
        bola->tratarColisaoPoderes();
        bola->tratarColisaoGol();
        bola->atualizarPoderes();
        txtG1.setString(std::to_string(G1->getPontos()));
        txtG2.setString(std::to_string(G2->getPontos()));
        txtDt.setString(std::to_string(dt/60));
        if(pV!=NULL){
            if(!pV->getFoiAtivado()){
                pGG->render(pV->getSprite());
                pGG->render(&txtPoderes);
            }
        }
        if(pT!=NULL){
            if(!pT->getFoiAtivado()){
                pGG->render(pT->getSprite());
                pGG->render(&txtPoderes2);
            }
        }
        pGG->render(&txtG1);
        pGG->render(&txtG2);
        pGG->render(R1->getSprite());
        pGG->render(R2->getSprite());
        pGG->render(bola->getSprite());
        pGG->render(&txtDt);
        
        if(G1->getPontos()==5||G2->getPontos()==5){
            pGG->closeWindow();
        }
        
        pGG->display();
    }
}

void Pong::telaTutorial(){
    sf::Event event;
        bool comecar = false;
        
        while(pGG->windowopen() && !comecar){
            while(pGG->getWindow()->pollEvent(event)){
                if(event.type == sf::Event::Closed){
                    pGG->closeWindow();
                }
                if(event.type == sf::Event::KeyPressed){
                    if(event.key.code == sf::Keyboard::Enter){
                        comecar = true;
                    }
                }
            }
            pGG->clear();
            pGG->render(&txtTutorial);
            pGG->display();
        }
}
