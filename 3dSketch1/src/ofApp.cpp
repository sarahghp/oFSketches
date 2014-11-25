#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(127);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255);
    
    ofEnableDepthTest();
    
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++) {
            
            ofPushMatrix();
            ofTranslate(0, 0, -mouseX*10);
            ofRect(i*100, j *100,50,50);
            ofPopMatrix();
        }
    }
   
    
    ofSetColor(255,0,0);
    ofRect(ofGetWidth()/2 + 300 * cos(ofGetElapsedTimef()), ofGetHeight()/2 + 300 * sin(ofGetElapsedTimef()), 50,50);
    
    
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
