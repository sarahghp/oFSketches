#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    width = 640;
    height = 480;
    
    // Print the markers from the "AllBchThinMarkers.png" file in the data folder
    #ifdef CAMERA_CONNECTED
    vidGrabber.initGrabber(width, height);
    #else
    vidPlayer.loadMovie("marker.mov");
    vidPlayer.play();
    vidPlayer.setLoopState(OF_LOOP_NORMAL);
    #endif
    
    colorImage.allocate(width, height);
    grayImage.allocate(width, height);
    grayThres.allocate(width, height);
    
    // Load the image we are going to distort
    displayImage.loadImage("of.jpg");
    // Load the corners of the image into the vector
    int displayImageHalfWidth = displayImage.width / 2;
    int displayImageHalfHeight = displayImage.height / 2;
    displayImageCorners.push_back(ofPoint(0, 0));
    displayImageCorners.push_back(ofPoint(displayImage.width, 0));
    displayImageCorners.push_back(ofPoint(displayImage.width, displayImage.height));
    displayImageCorners.push_back(ofPoint(0, displayImage.height));
    
    // This uses the default camera calibration and marker file
    artk.setup(width, height);
    
    // The camera calibration file can be created using GML:
    // http://graphics.cs.msu.ru/en/science/research/calibration/cpp
    // and these instructions:
    // http://studierstube.icg.tu-graz.ac.at/doc/pdf/Stb_CamCal.pdf
    // This only needs to be done once and will aid with detection
    // for the specific camera you are using
    // Put that file in the data folder and then call setup like so:
    // artk.setup(width, height, "myCamParamFile.cal", "markerboard_480-499.cfg");
    
    // Set the threshold
    // ARTK+ does the thresholding for us
    // We also do it in OpenCV so we can see what it looks like for debugging
    threshold = 85;
    artk.setThreshold(threshold);
    
    ofBackground(127,127,127);
    
    // Node setup
    node2.setParent(node);
    node2.setPosition(0, 10, 0);
    node3.setParent(node2);
    node3.setPosition(0, 0, 10);
    node4.setParent(node);
    node4.setPosition(-10, 0, 20);
    node5.setParent(node4);
    node5.setPosition(-20, 20 , 0);
    
    nodePtrs[0] = &node;
    nodePtrs[1] = &node2;
    nodePtrs[2] = &node3;
    nodePtrs[3] = &node4;
    nodePtrs[4] = &node5;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    #ifdef CAMERA_CONNECTED
        vidGrabber.update();
        bool bNewFrame = vidGrabber.isFrameNew();
    #else
        vidPlayer.update();
        bool bNewFrame = vidPlayer.isFrameNew();
    #endif
    
    if(bNewFrame) {
        
    #ifdef CAMERA_CONNECTED
        colorImage.setFromPixels(vidGrabber.getPixels(), width, height);
    #else
        colorImage.setFromPixels(vidPlayer.getPixels(), width, height);
    #endif
        
    #ifdef DEBUG
        // apply a threshold so we can see what is going on
        grayThres = grayImage;
        grayThres.threshold(threshold);
    #endif
        
        // convert our camera image to grayscale
        grayImage = colorImage;
        
        // Pass in the new image pixels to artk
        artk.update(grayImage.getPixels());
        
    }
    
    // Node updates
    // node.setGlobalPosition(ofPoint(0, 0, 0));
    node.pan(1.0);
    node2.setPosition(15 + 5 * sin(ofGetElapsedTimef()),0,0);
    node2.tilt(1.7);
    node3.roll(4.0);
    node4.pan(5.0);
    
    for (int i = 0; i < 5; i++){
        
        line.addVertex(nodePtrs[i]->getGlobalPosition());
        if (line.size() > 1000){
            line.getVertices().erase(line.getVertices().begin());
        }
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // Main image
    ofSetHexColor(0xffffff);
    grayImage.draw(0, 0);
    
    #ifdef DEBUG
        ofSetHexColor(0x666666);
        ofDrawBitmapString(ofToString(artk.getMatrix(0)) + " marker(s) found", 10, 20);
        // Threshold image
        ofSetHexColor(0xffffff);
        grayThres.draw(640, 0);
        ofSetHexColor(0x666666);
        ofDrawBitmapString("Threshold: " + ofToString(threshold), 650, 20);
        ofDrawBitmapString("Use the Up/Down keys to adjust the threshold", 650, 40);
    
    // ARTK draw
    // An easy was to see what is going on
    // Draws the marker location and id number
        artk.draw(640, 0);
    
    // ARTK 2D stuff
    // See if marker ID '0' was detected
    // and draw blue corners on that marker only
        int myIndex = artk.getMarkerIndex(0);
        if(myIndex >= 0) {
        // Get the corners
            vector<ofPoint> corners;
            artk.getDetectedMarkerBorderCorners(myIndex, corners);
            // Can also get the center like this:
            // ofPoint center = artk.getDetectedMarkerCenter(myIndex);
            ofSetHexColor(0x0000ff);
            for(int i=0;i<corners.size();i++) {
                ofCircle(corners[i].x, corners[i].y, 10);
            }
            
        // Homography
        // Here we feed in the corners of an image and get back a homography matrix
            ofMatrix4x4 homo = artk.getHomography(myIndex, displayImageCorners);
            // We apply the matrix and then can draw the image distorted on to the marker
            ofPushMatrix();
            glMultMatrixf(homo.getPtr());
            ofSetHexColor(0xffffff);
            displayImage.draw(0, 0);
            ofPopMatrix();
        
    }
    #endif
    
    
    
    // ARTK 3D stuff
    // This is another way of drawing objects aligned with the marker
    // First apply the projection matrix once
    artk.applyProjectionMatrix();
    // Find out how many markers have been detected
    int numDetected = artk.getNumDetectedMarkers();
    ofEnableAlphaBlending();
    
    // Draw node buddy
    int otherIndex = artk.getMarkerIndex(37);
    if(otherIndex >= 0){
        ofSetColor(162, 0, 255);
        artk.applyModelMatrix(otherIndex);
        line.draw();
    }
    
    #ifdef DEBUG
    // Draw for each marker discovered
    for(int i=0; i<numDetected; i++) {
        
        // Set the matrix to the perspective of this marker
        // The origin is in the middle of the marker
        artk.applyModelMatrix(i);
        
        // Draw a stack of rectangles by offseting on the z axis
        ofNoFill();
        ofEnableSmoothing();
        ofSetColor(255, 255, 0, 50);	
        for(int i=0; i<10; i++) {		
            ofRect(-25, -25, 50, 50);
            ofTranslate(0, 0, i*1);
        }
    }
    #endif


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
