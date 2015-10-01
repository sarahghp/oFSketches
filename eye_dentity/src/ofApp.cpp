#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // FaceOSC sends to port 8338 by default
    receiver.setup(8338);
    ofBackground(255);

}

//--------------------------------------------------------------
void ofApp::update(){
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
        
        // cout << "---------" << endl
        // << face.poseScale << endl;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

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
