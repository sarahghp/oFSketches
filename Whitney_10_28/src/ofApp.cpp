#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetVerticalSync(true);
    
    ofBackground(40,40,61);
    
    ofSetCircleResolution(100);
    
    l = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    l += (ofGetElapsedTimef() * 10);
    l = (int)l % (int)(ofGetHeight()/1);
}

//--------------------------------------------------------------
void ofApp::draw(){

    float modulator = ofMap( sin(ofGetElapsedTimef()*4), -1, 1, 0, 1);
    
    ofColor myColor;
    myColor.setHsb( int(ofGetElapsedTimef() * 1000) % 255,255 ,255 );
    
    ofSetColor(myColor);
    float ypos = 5;
    
    for (int i = 0; i < 1000 ; i++) {
        float xpos = ofMap( sin(ofGetElapsedTimef()*3 + i) * modulator, -1, 1, 0, ofGetWidth());
        for (int j = 0; j < 40; j++) {
            float ypos = (int)(j * 20 + l) ;
            ofCircle(xpos, ypos, 2);
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
