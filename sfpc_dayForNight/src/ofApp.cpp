#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    center.x = ofGetWidth()/2;
    center.y = ofGetHeight()/2;
    
    weeArc.setCircleResolution(1000);
    weeArc.setFilled(false);
    weeArc.setStrokeColor(ofColor(0,0,255));
    weeArc.setStrokeWidth(1);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 1; i < 31; i++){
        int rad = i * (8 - .04 * i);
        
        weeArc.moveTo(center.x, center.y - rad);
        weeArc.arc(center, rad, rad, 270, 90);
        weeArc.lineTo(center.x - (.086 * rad), center.y + .95 * rad);
        
        weeArc.arc(center, .95 * rad, .95 * rad, 96, 190);
        
        weeArc.lineTo(center.x - 1.18 * rad, center.y - 62);
        weeArc.arc(center, 1.2 * rad, 1.2 * rad, 190, 265);
        
        weeArc.close();
        weeArc.draw();

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
