#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup() override;
    void update() override;
    void draw() override;
    
    void keyPressed(int key) override;
    void keyReleased(int key) override;
    void mouseMoved(int x, int y ) override;
    void mouseDragged(int x, int y, int button) override;
    void mousePressed(int x, int y, int button) override;
    void mouseReleased(int x, int y, int button) override;
    void mouseEntered(int x, int y) override;
    void mouseExited(int x, int y) override;
    void windowResized(int w, int h) override;
    void dragEvent(ofDragInfo dragInfo) override;
    void gotMessage(ofMessage msg) override;
    
    // For drawing
    float waveform[4096]; //make this bigger, just in case
    int waveIndex;
    
    ofSoundStream soundStream;
    
    /* ofxMaxi*/
    void audioIn(ofSoundBuffer& input) override; // not used in this example
    void audioOut(ofSoundBuffer& output) override;
    maxiSample mySample;
    
    // Shader
    ofShader shader;
    ofShader shader2;
    ofShader shader3;

    // Arduino Input
    bool serialMessage;            // a flag for sending serial
    char receivedData[10];        // for storing incoming data
    char sendData = 1;    // for sending data

    ofSerial    serial;
    float vOut=0.04;
    float vOut2=0.04;
    
    // GUI
    ofxPanel gui;
    ofxFloatSlider floatSlider;
    ofxIntSlider intSlider;

    

};
