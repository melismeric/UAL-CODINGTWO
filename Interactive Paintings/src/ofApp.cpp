#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Arduino
    serialMessage = false;
    
    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    
    // this should be set to whatever com port your serial device is connected to.
    // (ie, COM4 on a pc, /dev/tty.... on linux, /dev/tty... on a mac)
    // arduino users check in arduino app....
    int baud = 9600;
    serial.setup(0, baud); //open the first device
    
    // Shaders
    shader.load("shader.vert", "shader.frag");
    shader2.load("oilColor.vert", "oilColor.frag");
    shader3.load("simple.vert", "simple.frag");
        
    // Audio
    //Initialize the drawing variables
    for (int i = 0; i < ofGetWidth()/2.0; ++i) {
        waveform[i] = 0;
    }
    waveIndex = 0;
    
    // Maximilian audio
    int sampleRate = 44100;
    int bufferSize= 512;
    ofxMaxiSettings::setup(sampleRate, 2, bufferSize);

    //mySample.load(ofToDataPath("sounds/büyükev.wav"));
    mySample.load(ofToDataPath("sounds/standbyme.wav"));
    
    // Setup ofSound
    ofSoundStreamSettings settings;
    settings.setOutListener(this);
    settings.sampleRate = sampleRate;
    settings.numOutputChannels = 2;
    settings.numInputChannels = 0;
    settings.bufferSize = bufferSize;
    soundStream.setup(settings);
    

    gui.setup();
    
    gui.add(floatSlider.setup("details", 5.0, 0.0, 7.0));
    gui.add(intSlider.setup("change painting", 1, 1, 3));
    
}

//--------------------------------------------------------------


void ofApp::update(){
    if (serial.available() > 0) {
        serial.readBytes(receivedData, 10); // Getting the data from Arduino
        vOut = (float)stof(receivedData, NULL);
    } else { // if the arduino is not connected use a default sensor value
        vOut = 50.0;
    }

    //cout << vOut << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){    
    ofBackground(0);
    gui.draw();
    
    ofSetColor(0, 255, 0);
    ofFill();
    ofDrawLine(0, 0, 1, waveform[1] * ofGetHeight()/2); //first line
    for(int i = 1; i < (ofGetWidth()- 1); ++i) {
        ofDrawLine(i, waveform[i] * ofGetHeight()/2 , i + 1, waveform[i+1] * ofGetHeight()/2);
    }
    
    // Frame
    ofNoFill();
    ofDrawRectangle(100, 80,ofGetWidth()/1.2, ofGetHeight()/1.2);

    
    if (intSlider == 1) {
        // Shader
        shader.begin();
        
        for(int i = 1; i < (ofGetWidth()/2.0 - 1); ++i) {
            shader.setUniform1i("sound", waveform[i] * 100 );
        
            //cout << "WAWE:" << waveform[i] * 1000 << endl;
        }

        shader.setUniform1f("u_sensor", vOut);  // SET UNIFORM
        
        shader.setUniform1f("value", floatSlider);

        shader.setUniform1f("u_time", ofGetElapsedTimef());

        shader.setUniform2f("u_resolution", ofGetScreenWidth(), ofGetScreenHeight() );
        
        ofFill();
        ofDrawRectangle(130, 100, ofGetWidth()/1.3, ofGetHeight()/1.3);

        shader.end();
    } else if (intSlider == 2){
        shader2.begin();

           shader2.setUniform1f("u_sensor", vOut);  // SET UNIFORM
           
           shader2.setUniform1f("value", floatSlider);

           shader2.setUniform1f("u_time", ofGetElapsedTimef());

           shader2.setUniform2f("u_resolution", ofGetScreenWidth(), ofGetScreenHeight() );
           
           ofFill();
           ofDrawRectangle(130, 100, ofGetWidth()/1.3, ofGetHeight()/1.3);
           
           shader2.end();
    } else if (intSlider == 3){
        shader3.begin();

           shader3.setUniform1f("u_sensor", vOut);  // SET UNIFORM
    
           shader3.setUniform1f("value", floatSlider);

           shader3.setUniform1f("u_time", ofGetElapsedTimef());

           shader3.setUniform2f("u_resolution", ofGetScreenWidth(), ofGetScreenHeight() );
           
           ofFill();
           ofDrawRectangle(130, 100, ofGetWidth()/1.3, ofGetHeight()/1.3);
           
           shader3.end();
    }

    
}

//--------------------------------------------------------------
void ofApp::audioIn(ofSoundBuffer& input){

}
//--------------------------------------------------------------
void ofApp::audioOut(ofSoundBuffer& output){
    std::size_t outChannels = output.getNumChannels();
    for (int i = 0; i < output.getNumFrames(); ++i){
        
        if(vOut > 500){
            output[i * outChannels] = mySample.play();
        }
        
        output[i * outChannels] = mySample.play();
        output[i * outChannels + 1] = output[i * outChannels];
        
        waveform[waveIndex] =  output[i * outChannels];
        if (waveIndex < (ofGetWidth() - 1)) {
            ++waveIndex;
        } else {
            waveIndex = 0;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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
