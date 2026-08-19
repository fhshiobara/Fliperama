//
//  Cobra.hpp
//  Fliperama
//
//  Created by Edison Shiobara on 19/08/26.
//

#ifndef Cobra_hpp
#define Cobra_hpp

#include <stdio.h>

class Cobra{
protected:
    int x;
    int y;
    Cobra* corpo;
public:
    Cobra();
    ~Cobra();
    Cobra* getCorpo();
    void setCorpo(Cobra* cobra);
};

#endif /* Cobra_hpp */
