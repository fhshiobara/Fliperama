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

class Blocos{
protected:
    int id;
    short int estado; // isso que vai dizer o estado de rotacao do objeto
    int cellSize;
public:
    
    std::map<int,std::vector<CoordI>> cells;
    Blocos();
    ~Blocos();
    int getId();
    void setId(int i);
    int getEstado();
    void setEstado(int i);
};
#endif /* Blocos_hpp */
