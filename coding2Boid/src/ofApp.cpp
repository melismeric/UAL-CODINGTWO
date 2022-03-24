#include "ofApp.h"

ofApp::~ofApp()
{
 
    for (int i = 0; i < blueBoids.size(); i++)
    {
        delete blueBoids[i];
    }
    
    for (int i = 0; i < bigBoid.size(); i++)
    {
       delete bigBoid[i];
    }
    
    for (int i = 0; i < lightBoids.size(); i++)
    {
       delete lightBoids[i];
    }
    
}
//--------------------------------------------------------------
void ofApp::setup(){
    // GUI
    gui.setup();
    gui.add(sepWeightBlueBoid.setup("Seperation Weight Blue Boids", 1.0, 0.0, 10.0));
    gui.add(cohWeightBlueBoid.setup("Cohesion Weight Blue Boids", 2.2, 0.0, 10.0));
    //gui.add(alignWeightBlueBoid.setup("Alignment Weight Blue Boids", 2.1, 0.0, 10.0));
    
    gui.add(sepWeightLightBoid.setup("Seperation Weight Light Boid", 1.0, 0.0, 10.0));
    gui.add(cohWeightLightBoid.setup("Cohesion Weight Light Boids", 2.2, 0.0, 10.0));
    //gui.add(alignWeightLightBoid.setup("Alignment Weight Light Boids", 2.1, 0.0, 10.0));
    
    // To turn circular interaction mode on
    gui.add(circular.set("circular mode", false));
    
    //Boids
    int screenW = ofGetScreenWidth();
    int screenH = ofGetScreenHeight();

    ofBackground(0,0,50);
    
    
    for (int i = 0; i < 15; i++){
        Boid *temp = new ChildBoid;
        blueBoids.push_back(temp);
        /*birds[i]->setSeparationWeight(1.2f);
        birds[i]->setCohesionWeight(0.5f);*/
    }
    
    for (int i = 0; i < 1; i++){
        Boid *temp2 = new ChildBoid;
        bigBoid.push_back(temp2);
        /*coloredBirds[i]->setSeparationWeight(0.0f);
        coloredBirds[i]->setCohesionWeight(0.0f);
        coloredBirds[i]->setAlignmentWeight(0.0f);*/
    }
    

    for (int i = 0; i < 10; i++){
        Boid *temp3 = new ChildBoid;
        lightBoids.push_back(temp3);
        /*lightBirds[i]->setSeparationWeight(1.2f);
        lightBirds[i]->setCohesionWeight(0.5f);*/
    }
    
    light.setDirectional();
    light.setSpecularColor(ofColor(255));
    light.setDiffuseColor(ofColor(255));
    light.setAmbientColor(ofColor(100));
}

//--------------------------------------------------------------
void ofApp::update(){
    ofVec3f min(-ofGetWidth()/2, -ofGetHeight()/2, -100);
    ofVec3f max(ofGetWidth()/2, ofGetHeight()/2, 100);

    for (int i = 0; i < blueBoids.size(); i++)
    {
        blueBoids[i]->update(blueBoids, lightBoids, min, max, circular);
        blueBoids[i]->update(blueBoids, bigBoid, min, max, circular);
        blueBoids[i]->setSeparationWeight(sepWeightBlueBoid);
        blueBoids[i]->setCohesionWeight(cohWeightBlueBoid);
    }

    for (int i = 0; i < bigBoid.size(); i++)
    {
        bigBoid[i]->update(bigBoid,blueBoids, min, max, circular);
        bigBoid[i]->update(bigBoid,lightBoids, min, max, circular);
    }
    
    for (int i = 0; i < lightBoids.size(); i++)
    {
        lightBoids[i]->update(lightBoids, blueBoids, min, max, circular);
        lightBoids[i]->update(lightBoids, bigBoid, min, max, circular);
        lightBoids[i]->setSeparationWeight(sepWeightLightBoid);
        lightBoids[i]->setCohesionWeight(cohWeightLightBoid);

    }
    
    const ofVec3f mousePos(mouseX, mouseY);
    const ofVec3f centerPos(ofGetWidth()/2, ofGetHeight()/2, 0);
    
    light.setPosition(mousePos);
    light.lookAt(centerPos);
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    
     ofEnableDepthTest();
     light.enable();
     cam.begin();
     
     for (int i = 0; i < blueBoids.size(); i++)
     {
         ofColor randomColor2;
         randomColor2.setHsb(ofRandom(130,150), 100, 255);
         blueBoids[i]->setColor(randomColor2);
         blueBoids[i]->setSize(6);
         blueBoids[i]->draw();
     }
     
    for (int i = 0; i < bigBoid.size(); i++)
     {
         ofColor randomColor;
         randomColor.setHsb(ofRandom(180,200), 255, 255);
         bigBoid[i]->setColor(randomColor);
         bigBoid[i]->setSize(35);
         bigBoid[i]->draw();
     }
     
     for (int i = 0; i < lightBoids.size(); i++)
     {
         ofColor randomColor;
         randomColor.setHsb(ofRandom(340,350), 255, 255);
         lightBoids[i]->setColor(randomColor);
         lightBoids[i]->setSize(7);
         lightBoids[i]->draw();
     }
     
     
     cam.end();
     light.disable();
     ofDisableDepthTest();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    for (int i = 0; i < bigBoid.size(); i++)
    {
        bigBoid[i]->changePosition(key);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
