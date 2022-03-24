#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  shader.load("shader");

  float planeScale = 0.75;
  int planeWidth = ofGetWidth() * planeScale;
  int planeHeight = ofGetHeight() * planeScale;
  int planeGridSize = 20;
  int planeColumns = planeWidth / planeGridSize;
  int planeRows = planeHeight / planeGridSize;

  plane.set(planeWidth, planeHeight, planeColumns, planeRows, OF_PRIMITIVE_TRIANGLES);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  shader.begin();

  // center screen.
  float cx = ofGetWidth() / 2.0;
  float cy = ofGetHeight() / 2.0;

  // the plane is being positioned in the middle of the screen,
  // so we have to apply the same offset to the mouse coordinates before passing into the shader.
  float mx = mouseX / ofGetScreenWidth();
  float my = mouseY / ofGetScreenHeight();


  // we can pass in two values into the shader at the same time by using the setUniform2 function.
  // inside the shader these two values are set inside a vec2 object.
  shader.setUniform2f("mouse", mx, my);  // SET A UNIFORM
  shader.setUniform1f("time", ofGetElapsedTimef());
  shader.setUniform2f("resolution", ofGetScreenWidth(), ofGetScreenHeight() );  // SET A UNIFORM

  ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

  shader.end();
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
