//
//  Blocos.hpp
//  Fliperama
//
//  Created by Edison Shiobara on 04/08/26.
//

#ifndef Blocos_hpp
#define Blocos_hpp

#include <stdio.h>
#include "VectorTL.hpp"
#include <map>
#include <vector>
#include "Mapa.hpp"

class Blocos{
protected:
    int id;
    short int estado; // isso que vai dizer o estado de rotacao do objeto
    int cellSize;
    Mapa* pM;
    
public:
    
    std::map<int,std::vector<CoordI>> cells;
    Blocos();
    ~Blocos();
    int getId();
    void setId(int i);
    int getEstado();
    void setEstado(int i);
    void draw();
    
    void setMapa(Mapa *m);
    Mapa* getMapa();
};

class BlocoJ:public Blocos{
public:
    BlocoJ(){
        id = 1;
        cells[0] = {CoordI(4,2),CoordI(5,0),CoordI(5,1),CoordI(5,2)};
        cells[1] = {CoordI(4,0),CoordI(4,1),CoordI(5,1),CoordI(6,1)};
        cells[2] = {CoordI(4,0),CoordI(5,0),CoordI(4,1),CoordI(4,2)};
        cells[3] = {CoordI(4,0),CoordI(5,0),CoordI(6,0),CoordI(6,1)};
    }
};

class BlocoQ:public Blocos{
public:
    BlocoQ(){
        id =2;
        cells[0] = {CoordI(4,0),CoordI(4,1),CoordI(5,0),CoordI(5,1)};
        cells[1] = {CoordI(4,0),CoordI(4,1),CoordI(5,0),CoordI(5,1)};
        cells[2] = {CoordI(4,0),CoordI(4,1),CoordI(5,0),CoordI(5,1)};
        cells[3] = {CoordI(4,0),CoordI(4,1),CoordI(5,0),CoordI(5,1)};
        
    }
};
class BlocoL:public Blocos{
public:
    BlocoL(){
        id = 3;
        cells[0] = {CoordI(4,0),CoordI(4,1),CoordI(4,2),CoordI(5,2)};//
        cells[1] = {CoordI(4,0),CoordI(4,1),CoordI(5,0),CoordI(6,0)};
        cells[2] = {CoordI(4,0),CoordI(5,0),CoordI(5,1),CoordI(5,2)};
        cells[3] = {CoordI(4,1),CoordI(5,1),CoordI(6,1),CoordI(6,0)};
    }
};

class BlocoI:public Blocos{
public:
    BlocoI(){
        id = 4;
        cells[0] = {CoordI(5,0),CoordI(5,1),CoordI(5,2),CoordI(5,3)};
        cells[1] = {CoordI(3,2),CoordI(4,2),CoordI(5,2),CoordI(6,2)};
        cells[2] = {CoordI(4,0),CoordI(4,1),CoordI(4,2),CoordI(4,3)};
        cells[3] = {CoordI(3,1),CoordI(4,1),CoordI(5,1),CoordI(6,1)};
    }
};

class BlocoT:public Blocos{
public:
    BlocoT(){
        id = 5;
        cells[0] = {CoordI(4,1),CoordI(5,0),CoordI(5,1),CoordI(5,2)};
        cells[1] = {CoordI(4,1),CoordI(5,1),CoordI(5,2),CoordI(6,1)};
        cells[2] = {CoordI(5,0),CoordI(5,1),CoordI(5,2),CoordI(6,1)};
        cells[3] = {CoordI(4,1),CoordI(5,0),CoordI(5,1),CoordI(6,1)};
    }
};

class BlocoS:public Blocos{
public:
    BlocoS(){
        id = 6;
        cells[0] = {CoordI(4,1),CoordI(4,2),CoordI(5,0),CoordI(5,1)};
        cells[1] = {CoordI(4,1),CoordI(5,1),CoordI(5,2),CoordI(6,2)};
        cells[2] = {CoordI(4,1),CoordI(4,2),CoordI(5,0),CoordI(5,1)};
        cells[3] = {CoordI(4,1),CoordI(5,1),CoordI(5,2),CoordI(6,2)};
    }
};

class BlocoZ:public Blocos{
public:
    BlocoZ(){
        id = 7;
        cells[0] = {CoordI(4,0),CoordI(4,1),CoordI(5,1),CoordI(5,2)};
        cells[1] = {CoordI(4,2),CoordI(5,1),CoordI(5,2),CoordI(6,1)};
        cells[2] = {CoordI(4,0),CoordI(4,1),CoordI(5,1),CoordI(5,2)};
        cells[3] = {CoordI(4,2),CoordI(5,1),CoordI(5,2),CoordI(6,1)}; 
    }
};



#endif /* Blocos_hpp */
