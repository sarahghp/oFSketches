#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    myImg.allocate(1000, 1000, OF_IMAGE_GRAYSCALE);
}

//--------------------------------------------------------------
void ofApp::update(){

    unsigned char * pixel = myImg.getPixels();
    
    for (int i = 0; i < myImg.getWidth() * myImg.getHeight(); i++) {
        pixel[i] = sin(ofGetElapsedTimef()) * ofRandom(254);
    }
    
    myImg.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    myImg.draw(0,0);
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
