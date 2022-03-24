//
//  ChildBoid.cpp
//  coding2Boid
//
//

#include "ChildBoid.hpp"

void ChildBoid::draw(){
    ofSetColor(color);
    ofDrawSphere(getPosition().x, getPosition().y, size);
}

void ChildBoid::setColor(ofColor clr)
{
    color = clr;
}

void ChildBoid::setSize(int mySize)
{
    size = mySize;
}
