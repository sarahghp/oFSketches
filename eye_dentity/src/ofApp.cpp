#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    float frameRate = 60.0;
    
    // Face buddies
    // FaceOSC sends to port 8338 by default
    receiver.setup(8338);
    ofBackground(255);
    
    // Video
    ofSetVerticalSync(true);
    ofSetFrameRate(frameRate);
    
    // Uncomment to debug device selection
    // ofSetLogLevel(OF_LOG_VERBOSE);
    // vidGrabber.listDevices();
    vidGrabber.setDeviceID(1);
    vidGrabber.initGrabber(320,240);
    
    // Eyeball bodies
    box2d.init();
    box2d.setGravity(0, 10);
    box2d.createBounds();
    box2d.setFPS(frameRate);
    box2d.registerGrabbing();

    
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
        
        // Uncmoment to debug mouth opening
        // cout << "---mh------" << endl
        // << face.mouthHeight <<   endl;
        
        if (face.mouthHeight > 7) {
            // Adding particles
            for (int i = 0; i < 10; i++){
                particle littleBuddy;
                littleBuddy.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
                particles.push_back(littleBuddy);
            }
        }
    }
    
    // Video
    vidGrabber.update();
    vid.setFromPixels(vidGrabber.getPixels(), 320,240);
    
    // Eyeball bodies
    box2d.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    // Make video show
    vid.draw(0,0,ofGetWidth(), ofGetHeight());
    
    // Make particles show
    for (int i = 0; i < particles.size(); i++){
        particles[i].draw();
    }
    
    // Add eyeball bodies
    for(int i=0; i<circles.size(); i++) {
        ofFill();
        ofSetHexColor(0xf6c738);
        circles[i].get()->draw();
    }
    
    // draw the ground
    box2d.drawGround();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'c') {
        float r = 20;
        float xOffset = ofRandom(ofGetWidth()/2 - 1, ofGetWidth()/2 + 1);
        circles.push_back(shared_ptr<ofxBox2dCircle>(new ofxBox2dCircle));
        circles.back().get()->setPhysics(3.0, 0.53, 0.1);
        circles.back().get()->setup(box2d.getWorld(), xOffset, ofGetHeight()/2, r);
        
    }
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
