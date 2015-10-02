#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Face buddies
    // FaceOSC sends to port 8338 by default
    receiver.setup(8338);
    ofBackground(255);
    
    // Video
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    vidGrabber.initGrabber(320,240);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    // Face buddies
    // check for waiting osc messages
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        
        // if (m.getAddress() == "/raw"){
        //    cout << "-----raw----" << endl
        //    << m.getArgAsFloat(60) << endl;
        // }
        
        // cout << "-----msg----" << endl
        // << m.getAddress() << endl;
        
        // load face from any FaceOSC messages
        face.parseOSC(m);
    }
    
    // found face?
    if(face.found > 0) {
        cout << "---mh------" << endl
        << face.mouthHeight <<   endl;
        
        if (face.mouthHeight > 7) {
            // Adding particles
            for (int i = 0; i < 100; i++){
                particle littleBuddy;
                littleBuddy.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
                particles.push_back(littleBuddy);
            }

        }
    }
    
    // Video
    vidGrabber.update();
    vid.setFromPixels(vidGrabber.getPixels(), 320,240);
}

//--------------------------------------------------------------
void ofApp::draw(){
    // Make video show
    vid.draw(0,0,ofGetWidth(), ofGetHeight());
    
    // Make particles show
    for (int i = 0; i < particles.size(); i++){
        particles[i].draw();
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
