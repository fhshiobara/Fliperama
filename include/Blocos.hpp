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


class BlocoL:public Blocos{
public:
    BlocoL(){
        id = 1;
        cells[0] = {CoordI(0,2),CoordI(1,0),CoordI(1,1),CoordI(1,2)};
        cells[1] = {CoordI(0,0),CoordI(0,1),CoordI(1,1),CoordI(2,1)};
        cells[2] = {CoordI(1,0),CoordI(2,0),CoordI(1,1),CoordI(1,2)};
        cells[3] = {CoordI(0,1),CoordI(1,1),CoordI(2,1),CoordI(2,2)};
    }
};


#endif /* Blocos_hpp */
