/*
 *
 */

#ifndef _BOID
#define _BOID
#include <vector>
#include "ofMain.h"

class Boid
{
// all the methods and variables after the
// private keyword can only be used inside
// the class
private:
    ofVec3f position;
    ofVec3f velocity;

    
// all the methods and variables after the
// public keyword can only be used by anyone
public:
    
    float separationThreshold;
    float neighbourhoodSize;
    
    float separationWeight;
    float cohesionWeight;
    float alignmentWeight;
    
    ofVec3f separation(std::vector<Boid *> &otherBoids);
    ofVec3f cohesion(std::vector<Boid *> &otherBoids);
    ofVec3f alignment(std::vector<Boid *> &otherBoids);
    
    Boid();
    Boid(ofVec3f &pos, ofVec3f &vel);
    
    virtual ~Boid();
    
    ofVec3f getPosition();
    ofVec3f getVelocity();
    
    float getSeparationWeight();
    float getCohesionWeight();
    float getAlignmentWeight();
    
    float getSeparationThreshold();
    float getNeighbourhoodSize();
    
    void setSeparationWeight(float f);
    void setCohesionWeight(float f);
    void setAlignmentWeight(float f);
    
    void setSeparationThreshold(float f);
    void setNeighbourhoodSize(float f);
    
    void update(std::vector<Boid *> &otherBoids, std::vector<Boid *> &otherFlock, ofVec3f &min, ofVec3f &max, bool circular);
    ofVec3f separationFlock(std::vector<Boid *> &otherFlock);
        
    void walls(ofVec3f &min, ofVec3f &max);
    
    virtual void draw();
    virtual void setColor(ofColor clr){};
    virtual void setSize(int mySize){};
    
    void changePosition(int key);
};

#endif
