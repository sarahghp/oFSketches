#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    center.x = ofGetWidth()/2;
    center.y = ofGetHeight()/2 + ofGetHeight() * .09;
    
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
        float rad = i * (10 - .04 * i);
        float maxRad = 30;
        float diff = (center.y + maxRad * sin(ofDegToRad(90))) - (center.y + (.35 * maxRad) * sin(ofDegToRad(90)));
        
        weeArc.moveTo(center.x, center.y - rad);
        weeArc.arc(center, rad, rad, 270, 90);
        weeArc.arc(center.x - 30, center.y - diff * 2, rad, rad, 92, 190);
        weeArc.arc(center.x - 40, center.y - diff * 6,  1.18 * rad, 1.18 * rad, 180, 260);
        
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
