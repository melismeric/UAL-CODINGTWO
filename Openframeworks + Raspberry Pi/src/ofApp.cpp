#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundAuto(false); // Stop the background from being redrawn each frame

	// We still want to draw on a black background, so we need to draw
	// the background before we do anything with the brush
	ofBackground(0);
	gpio17.setup("17");
	gpio17.export_gpio();
	gpio17.setdir_gpio("in");
}

//--------------------------------------------------------------
void ofApp::update(){
	gpio17.getval_gpio(state_button);
	ofLog()<<state_button;
	usleep(50000);
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (state_button == "1") {
		// Randomness!
		ofColor aqua(0, 252, 255, 150);
		ofColor purple(198, 0, 205, 150);
		ofColor inbetween = aqua.getLerped(purple, ofRandom(1.0));
		ofSetColor(inbetween);
		
		ofSetRectMode(OF_RECTMODE_CENTER); // Draw rect by specifying the center
		ofDrawRectangle(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), 50, 50); // Draw a 50 x 50 rect centered over the mouse
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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


