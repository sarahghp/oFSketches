#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0,0,40);
    
    node.setGlobalPosition(ofPoint(ofGetWidth()/2, ofGetHeight()/2, 200));
    node2.setParent(node);
    node2.setPosition(0, 100, 0);
    node3.setParent(node2);
    node3.setPosition(0, 0, 100);
    node4.setParent(node);
    node4.setPosition(100, 0, 200);
    node5.setParent(node4);
    node5.setPosition(100, 200 , 0);
    
    nodePtrs[0] = &node;
    nodePtrs[1] = &node2;
    nodePtrs[2] = &node3;
    nodePtrs[3] = &node4;
    nodePtrs[4] = &node5;
    
    //nodePtrs[4]->getGlobalPosition();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    node.setGlobalPosition( ofPoint(0, 0, 0));
    node.pan(1.0);
    node2.setPosition(50 + 50 * sin(ofGetElapsedTimef()),0,0);
    node2.tilt(1.7);
    node3.roll(4.0);
    
    for (int i = 0; i < 5; i++){
    
        line.addVertex(nodePtrs[i]->getGlobalPosition());
        if (line.size() > 1000){
            line.getVertices().erase(line.getVertices().begin());
        }
    
    }
    


}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    ofEnableDepthTest();
    node.draw();
    node2.draw();
    node3.draw();
    node4.draw();
    node5.draw();
    line.draw();
    cam.end();

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
