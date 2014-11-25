#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    
    
    myNode.setGlobalPosition( ofPoint(ofGetWidth()/2,ofGetHeight()/2,400));
    myNode2.setParent(myNode);
    myNode2.setPosition(100,0,0);
    myNode3.setParent(myNode2);
    myNode3.setPosition(0,100,0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    myNode.setGlobalPosition( ofPoint(0, 0, 0));
    myNode.pan(1.0);
    myNode2.setPosition(50 + 50 * sin(ofGetElapsedTimef()),0,0);
    myNode2.tilt(1.7);
    
    line.addVertex(myNode3.getGlobalPosition());
    if (line.size() > 1000){
        line.getVertices().erase(line.getVertices().begin());
    }
    //myNode.lookAt( ofPoint(mouseX, mouseY, 0));
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    //ofPushMatrix();
    
    //ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    //ofRotateX(mouseX);
    
    cam.begin();
    ofEnableDepthTest();
    myNode.draw();
    myNode2.draw();
    myNode3.draw();
    line.draw();
    cam.end();
    
    //ofPopMatrix();
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
