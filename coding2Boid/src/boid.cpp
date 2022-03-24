#include "boid.hpp"
#include "ofMain.h"

Boid::Boid()
{
    separationWeight = 1.0f;
    cohesionWeight = 2.2f;
    alignmentWeight = 2.1f;
    
    separationThreshold = 15;
    neighbourhoodSize = 100;
    
    position = ofVec3f(ofRandom(0, ofGetWidth()/2), ofRandom(0, ofGetHeight()/2), ofRandom(100, 200));
    velocity = ofVec3f(ofRandom(-2, 2), ofRandom(-2, 2), ofRandom(-2, 2));
}

Boid::Boid(ofVec3f &pos, ofVec3f &vel)
{
    separationWeight = 1.0f;
    cohesionWeight = 2.2f;
    alignmentWeight = 2.1f;
    
    separationThreshold = 15;
    neighbourhoodSize = 100;
    
    position = pos;
    velocity = vel;
}

Boid::~Boid()
{
    
}

float Boid::getSeparationWeight()
{
    return separationWeight;
}
float Boid::getCohesionWeight()
{
    return cohesionWeight;
}

float Boid::getAlignmentWeight()
{
    return alignmentWeight;
}


float Boid::getSeparationThreshold()
{
    return separationThreshold;
}

float Boid::getNeighbourhoodSize()
{
    return neighbourhoodSize;
}


void Boid::setSeparationWeight(float f)
{
    separationWeight = f;
}
void Boid::setCohesionWeight(float f)
{
    cohesionWeight = f;
}

void Boid::setAlignmentWeight(float f)
{
    alignmentWeight = f;
}


void Boid::setSeparationThreshold(float f)
{
    separationThreshold = f;
}

void Boid::setNeighbourhoodSize(float f)
{
    neighbourhoodSize = f;
}


ofVec3f Boid::getPosition()
{
    return position;
}

ofVec3f Boid::getVelocity()
{
    return velocity;
}

ofVec3f Boid::separation(std::vector<Boid *> &otherBoids)
{
    // finds the first collision and avoids that
    // should probably find the nearest one
    // can you figure out how to do that?
    for (int i = 0; i < otherBoids.size(); i++)
    {
        if(position.distance(otherBoids[i]->getPosition()) < separationThreshold)
        {
            ofVec3f v = position - otherBoids[i]->getPosition();
            v.normalize();
            return v;
        }
    }
}

ofVec3f Boid::separationFlock(std::vector<Boid *> &otherFlock)
{
    for (int i = 0; i < otherFlock.size(); i++)
    {
        if(getPosition().distance(otherFlock[i]->getPosition()) < 20.0f)
        {
            ofVec3f v = getPosition() -  otherFlock[i]->getPosition();
            v.normalize();
            return v;
        }
    }
}

ofVec3f Boid::cohesion(std::vector<Boid *> &otherBoids)
{
    ofVec3f average(0,0,0);
    int count = 0;
    for (int i = 0; i < otherBoids.size(); i++)
    {
        if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
        {
            average += otherBoids[i]->getPosition();
            count += 1;
        }
    }
    average /= count;
    ofVec3f v =  average - position;
    v.normalize();
    return v;
}

ofVec3f Boid::alignment(std::vector<Boid *> &otherBoids)
{
    ofVec3f average(0,0,0);
    int count = 0;
    for (int i = 0; i < otherBoids.size(); i++)
    {
        if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
        {
            average += otherBoids[i]->getVelocity();
            count += 1;
        }
    }
    average /= count;
    ofVec3f v =  average - velocity;
    v.normalize();
    return v;
}

void Boid::update(std::vector<Boid *> &otherBoids, std::vector<Boid *> &otherFlock, ofVec3f &min, ofVec3f &max, bool circular)
{
    velocity += 1.5*separationFlock(otherFlock);
    velocity += separationWeight*separation(otherBoids);
    velocity += cohesionWeight*cohesion(otherBoids);
    velocity += alignmentWeight*alignment(otherBoids);
    
    velocity += separationWeight*separation(otherBoids);
    if(circular){
        velocity += cohesionWeight*cohesion(otherFlock);
        velocity += alignmentWeight*alignment(otherBoids);
    }
    
    walls(min, max);
    position += velocity;
}

void Boid::walls(ofVec3f &min, ofVec3f &max)
{
    if (position.x < min.x){
        position.x = min.x;
        velocity.x *= -1;
    } else if (position.x > max.x){
        position.x = max.x;
        velocity.x *= -1;
    }
    
    if (position.y < min.y){
        position.y = min.y;
        velocity.y *= -1;
    } else if (position.y > max.y){
        position.y = max.y;
        velocity.y *= -1;
    }
    
    if (position.z < min.z){
        position.z = min.z;
        velocity.z *= -1;
    } else if (position.z > max.z){
        position.z = max.z;
        velocity.z *= -1;
    }
    
    
}

void Boid::changePosition(int key)
{
    if (key == 'd') //right
    {
        position.x = position.x + 70.0 ;
    }
    else if (key == 'a') //left
    {
        position.x = position.x - 70.0 ;
    }
    else if (key == 'w') //up
    {
        position.y = position.y + 70.0 ;
    }
    else if (key == 's') //down
    {
        position.y = position.y - 70.0 ;
    }
}


void Boid::draw()
{
    ofSetColor(0, 255, 255);
    ofCircle(position.x, position.y, 5);
}

