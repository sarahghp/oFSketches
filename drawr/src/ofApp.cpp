#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0,0,40);
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    VF.setupField(60,40,ofGetWidth(), ofGetHeight());

    for (int i = 0; i < 10000; i++){
        particle myParticle;
        myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
        particles.push_back(myParticle);
    }
    
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(320,240);
    
    synthImg.allocate(320, 240);
    unsigned char * pixel = synthImg.getPixels();
    
    for (int i = 0; i < synthImg.getWidth() * synthImg.getHeight(); i++) {
        pixel[i] = 0;
    }


    colorImg.allocate(320,240);
    grayImage.allocate(320,240);
    grayBg.allocate(320,240);
    grayDiff.allocate(320,240);
    grayDiffSmall.allocate(60,40);
    
    
    bLearnBakground = true;
    threshold = 30;
    bDrawDiagnostic = false;
    bForceInward	= true; // do we push the particles away...
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    bool bNewFrame = false;
    
    vidGrabber.update();
    bNewFrame = vidGrabber.isFrameNew();
    
    
    if (bNewFrame){
        colorImg.setFromPixels(vidGrabber.getPixels(), 320,240);
        
        grayImage = colorImg;
        if (bLearnBakground == true){
            grayBg = synthImg;		// the = sign copys the pixels from grayImage into grayBg (operator overloading)
            bLearnBakground = false;
        }
        
        // take the abs value of the difference between background and incoming and then threshold:
        grayDiff.absDiff(grayBg, grayImage);
        grayDiff.threshold(threshold);
        grayDiffSmall.scaleIntoMe(grayDiff);
        grayDiffSmall.blur(3); // really blur the image alot!
        VF.setFromPixels(grayDiffSmall.getPixels(), bForceInward, 0.05f);
    }

    
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        // get the force from the vector field:
        ofVec2f frc;
        frc = VF.getForceFromPos(particles[i].pos.x, particles[i].pos.y);
        particles[i].addForce(frc);
        
        ofVec2f center(ofGetWidth()/2, ofGetHeight()/2);
        ofVec2f centroidFrc(center.x-particles[i].pos.x, center.y-particles[i].pos.y);
        centroidFrc.normalize();
        particles[i].addForce(centroidFrc * .001f);
        
        
        particles[i].addDampingForce();
        particles[i].update();
        particles[i].bounceOffWalls();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    for (int i = 0; i < particles.size(); i++){
//        particles[i].draw();
//    }
    
    
    if (bDrawDiagnostic == true){
        
        // draw the incoming, the grayscale, the bg and the thresholded difference
        ofSetColor(0xffffff);
        colorImg.draw(20,20);
        grayImage.draw(360,20);
        grayBg.draw(20,280);
        grayDiff.draw(360,280);
        // draw the blurry image
        grayDiffSmall.draw(360, 540, 320, 240);
        
        ofSetColor(0,130,130, 200);
        ofRect(10,550,330,130);
        ofSetColor(0,0,0);
        ofDrawBitmapString("press ' ' (space) to snap background\npress 'd' to toggle diagnostic\ndrag mouse to add particles\npress 'r' to reset particles\npress 't' to toggle force direction", 20, 600);
        
    } else {
        
        ofEnableAlphaBlending();
        ofSetColor(255,255,255, 20);
        colorImg.draw(0,0,ofGetWidth(), ofGetHeight());
        ofSetColor(0,130,130, 200);
        // VF.draw();
        ofSetColor(0xffffff);
        for (int i = 0; i < particles.size(); i++){
            particles[i].draw();
        }
        
    }
    
    


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' ' ){
        bLearnBakground = true;
    } else if (key == 'd'){
        bDrawDiagnostic = !bDrawDiagnostic;
    } else if (key == 'r'){
        for (int i = 0; i < particles.size(); i++){
            particles[i].setInitialCondition(ofRandom(0,ofGetWidth()), ofRandom(0,ofGetHeight()), 0,0);
        }
    } else if (key == 't'){
        bForceInward = !bForceInward;
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
    particles.erase(particles.begin());
    particle pt;
    pt.setInitialCondition(x, y, 0, 0);
    particles.push_back(pt);
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
