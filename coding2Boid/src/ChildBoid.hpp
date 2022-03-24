//
//  ChildBoid.hpp
//  coding2Boid
//
//

#ifndef ChildBoid_hpp
#define ChildBoid_hpp

#include <stdio.h>
#include "boid.hpp"

class ChildBoid:public Boid
{
    private:
        ofVec3f position;
        ofVec3f velocity;
    
    public:
        ChildBoid():Boid(){};
        void draw();
    
        ofColor color;
        void setColor(ofColor clr);
    
        int size;
        void setSize(int mySize);
};


#endif
