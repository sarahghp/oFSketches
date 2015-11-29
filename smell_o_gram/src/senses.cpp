//
//  sense.cpp
//  smell_o_gram
//
//  Created by Sarah on 11/28/15.
//
//

#include "senses.h"

#define VERT_THRESH 150

//--------------------------------------------------------------

senses::senses(vector<int> markers, vector<string> imageFiles, ofxARToolkitPlus * artk):
    markers(markers), imageFiles(imageFiles), artk(artk) {}


//--------------------------------------------------------------

void senses::setup(){
    
    // Load image points
    for (int i = 0; i < 4; i++){
        ofImage displayImage;
        vector<ofPoint> displayImageCorners;
        // Load the image we are going to distort
        displayImage.loadImage(imageFiles[i]);
        // Load the corners of the image into the vector
        displayImageCorners.push_back(ofPoint(0, 0));
        displayImageCorners.push_back(ofPoint(displayImage.width, 0));
        displayImageCorners.push_back(ofPoint(displayImage.width, displayImage.height));
        displayImageCorners.push_back(ofPoint(0, displayImage.height));
        
        imagePoints.push_back(displayImageCorners);
        
    }
    
    // Node setup sense 1
    node1.setPosition(0, 0, 0);
    node2.setParent(node1);
    node2.setPosition(0, 10, 0);
    node3.setParent(node2);
    node3.setPosition(0, 0, 10);
    node4.setParent(node1);
    node4.setPosition(-10, 0, 20);
    node5.setParent(node4);
    node5.setPosition(-20, 20 , 0);
    
    nodePtrsOne[0] = &node1;
    nodePtrsOne[1] = &node2;
    nodePtrsOne[2] = &node3;
    nodePtrsOne[3] = &node4;
    nodePtrsOne[4] = &node5;
    
    // Node setup sense 2
    node6.setPosition(0, 0, 0);
    node7.setParent(node6);
    node7.setPosition(0, 10, 0);
    node8.setParent(node7);
    node8.setPosition(0, 0, 10);
    node9.setParent(node6);
    node9.setPosition(-10, 0, 20);
    node10.setParent(node9);
    node10.setPosition(-20, 20 , 0);
    
    nodePtrsTwo[0] = &node6;
    nodePtrsTwo[1] = &node7;
    nodePtrsTwo[2] = &node8;
    nodePtrsTwo[3] = &node9;
    nodePtrsTwo[4] = &node10;
    
    rectHeight = 0;
    rectY = 0;

    // Node setup sense 3
    node11.setPosition(0, 0, 0);
    node12.setParent(node11);
    node12.setPosition(0, -100, 100);
    node13.setParent(node12);
    node13.setPosition(400, -300, 50);
    node14.setParent(node11);
    node14.setPosition(-200, 400, -20);
    node15.setParent(node14);
    node15.setPosition(-100, 100 , 0);
    
    nodePtrsThree[0] = &node11;
    nodePtrsThree[1] = &node12;
    nodePtrsThree[2] = &node13;
    nodePtrsThree[3] = &node14;
    nodePtrsThree[4] = &node15;
    
    // Node setup sense 4
    node16.setPosition(0, 0, 0);
    //node17.setParent(node11);
    node17.setPosition(0, 0, 0);
    //node18.setParent(node12);
    node18.setPosition(0, 0, 0);
    //node19.setParent(node11);
    node19.setPosition(0, 0, 0);
    //node20.setParent(node14);
    node20.setPosition(0, 0 , 0);
    
    nodePtrsFour[0] = &node16;
    nodePtrsFour[1] = &node17;
    nodePtrsFour[2] = &node18;
    nodePtrsFour[3] = &node19;
    nodePtrsFour[4] = &node20;
    
    disappear = 10;
    
    
}

//--------------------------------------------------------------

void senses::update(){
 
    // Node updates 1
    node1.pan(1.0);
    node2.setPosition(15 + 5 * sin(ofGetElapsedTimef()),0,0);
    node2.tilt(1.7);
    node3.roll(4.0);
    node4.pan(5.0);
    
    for (int i = 0; i < 5; i++){
        
        line1.addVertex(nodePtrsOne[i]->getGlobalPosition());
        if (line1.size() > 1000){
            line1.getVertices().erase(line1.getVertices().begin());
        }
        
    }
    
    // Node updates 2
    node6.pan(1.0);
    node7.setPosition(15 + 5 * sin(ofGetElapsedTimef()),0,0);
    node7.tilt(1.7);
    node8.roll(4.0);
    node9.pan(5.0);
    
    for (int i = 0; i < 5; i++){
        
        line2.addVertex(nodePtrsTwo[i]->getGlobalPosition());
        if (line2.size() > 1000){
            line2.getVertices().erase(line2.getVertices().begin());
        }
        
    }
    
    if(rectHeight < ofGetHeight() + 400){
        rectHeight++;
    } else if(rectY < ofGetHeight() + 400){
        rectY++;
    } else {
        rectHeight = 0;
        rectY = 0;
    }
    
//    rectHeight = rectHeight < ofGetHeight() ? rectHeight + 1 : 0;
    
    // Node updates 3
    node11.pan(1.0);
    node12.setPosition(15 + 5 * sin(ofGetElapsedTimef()),0,0);
    node12.tilt(1.7);
    node13.roll(4.0);
    node14.pan(5.0);
    
    for (int i = 0; i < 5; i++){
        
        line3.addVertex(nodePtrsThree[i]->getGlobalPosition());
        if (line3.size() > 1000){
            line3.getVertices().erase(line3.getVertices().begin());
        }
        
    }
    
    // Node updates 4
    //node16.pan(1.0);
    node16.setPosition(300 * sin(ofGetElapsedTimef()/2),-300,100);
    node17.setPosition(300 * sin(ofGetElapsedTimef()/2),-100,300);
    node18.setPosition(300 * sin(ofGetElapsedTimef()/2),0,0);
    node19.setPosition(300 * sin(ofGetElapsedTimef()/2),300,-300);
    node20.setPosition(300 * sin(ofGetElapsedTimef()/2),100,-100);

    
    for (int i = 0; i < 5; i++){
        
        line4.addVertex(nodePtrsFour[i]->getGlobalPosition());
        if (line4.size() > 5000){
            line4.getVertices().erase(line4.getVertices().begin());
        }
    }

}

//--------------------------------------------------------------

void senses::draw(){
    
    // Draw images
    int markerIndexOne = artk->getMarkerIndex(markers[0]);
    int markerIndexTwo = artk->getMarkerIndex(markers[1]);
    int markerIndexThree = artk->getMarkerIndex(markers[2]);
    int markerIndexFour = artk->getMarkerIndex(markers[3]);

    
    displayImageOne.loadImage(imageFiles[0]);
    displayImageTwo.loadImage(imageFiles[1]);
    displayImageThree.loadImage(imageFiles[2]);
    displayImageFour.loadImage(imageFiles[3]);
    
    if (markerIndexOne >= 0){
        // Get the corners
        vector<ofPoint> corners1;
        artk->getDetectedMarkerBorderCorners(markerIndexOne, corners1);
        
        // Homography
        // Here we feed in the corners of an image and get back a homography matrix
        ofMatrix4x4 homo1 = artk->getHomography(markerIndexOne, imagePoints[0]);
        
        // We apply the matrix and then can draw the image distorted on to the marker
        ofPushMatrix();
        glMultMatrixf(homo1.getPtr());
        ofSetHexColor(0xffffff);
        displayImageOne.draw(0, 0);
        ofPopMatrix();
        
        if (corners1[2].y < VERT_THRESH || corners1[3].y < VERT_THRESH){
            ofSetColor(162, 0, 255);
            artk->applyProjectionMatrix();
            artk->applyModelMatrix(markerIndexOne);
            line1.draw();
        }
        
        //ofLog() << "one called" << endl;
    }
    
    if (markerIndexTwo >= 0){
        // Get the corners
        vector<ofPoint> corners2;
        artk->getDetectedMarkerBorderCorners(markerIndexTwo, corners2);
        
        // Homography
        // Here we feed in the corners of an image and get back a homography matrix
        ofMatrix4x4 homo2 = artk->getHomography(markerIndexTwo, imagePoints[1]);
        // We apply the matrix and then can draw the image distorted on to the marker
        ofPushMatrix();
        glMultMatrixf(homo2.getPtr());
        ofSetHexColor(0xffffff);
        displayImageTwo.draw(0, 0);
        ofPopMatrix();
        
        
        
        if (corners2[2].y < VERT_THRESH || corners2[3].y < VERT_THRESH){
//            ofSetColor(0, 204, 255);
//            artk->applyProjectionMatrix();
//            artk->applyModelMatrix(markerIndexTwo);
//            line2.draw();
            ofSetColor(15, 231, 255, 127);
            ofFill();
            ofRect(0, rectY, ofGetWidth(), rectHeight);
        }
        
        //ofLog() << "two called" << endl;
    }
    
    if (markerIndexThree >= 0){
        // Get the corners
        vector<ofPoint> corners3;
        artk->getDetectedMarkerBorderCorners(markerIndexThree, corners3);
        
        // Homography
        // Here we feed in the corners of an image and get back a homography matrix
        ofMatrix4x4 homo3 = artk->getHomography(markerIndexThree, imagePoints[2]);
        // We apply the matrix and then can draw the image distorted on to the marker
        ofPushMatrix();
        glMultMatrixf(homo3.getPtr());
        ofSetHexColor(0xffffff);
        displayImageThree.draw(0, 0);
        ofPopMatrix();
        
        if (corners3[2].y < VERT_THRESH || corners3[3].y < VERT_THRESH){
            ofSetColor(255, 21, 0);
            artk->applyProjectionMatrix();
            artk->applyModelMatrix(markerIndexThree);
            line3.draw();
            
            ofSetColor(240, 255, 153);
            ofFill();
            for (int i = 0; i < 20; i++){
                int randRad = ofRandom(2, 60);
                ofEllipse(ofRandom(-320, 320), ofRandom(-240, 240), ofRandom(-100, 100), randRad, randRad);
            }
        }
        

        
        //ofLog() << "three called" << endl;
    }
    
    if (markerIndexFour >= 0){
        // Get the corners
        vector<ofPoint> corners4;
        artk->getDetectedMarkerBorderCorners(markerIndexFour, corners4);
        
        // Homography
        // Here we feed in the corners of an image and get back a homography matrix
        ofMatrix4x4 homo4 = artk->getHomography(markerIndexFour, imagePoints[3]);
        // We apply the matrix and then can draw the image distorted on to the marker
        ofPushMatrix();
        glMultMatrixf(homo4.getPtr());
        ofSetHexColor(0xffffff);
        displayImageFour.draw(0, 0);
        ofPopMatrix();
        
        if (corners4[2].y < VERT_THRESH || corners4[3].y < VERT_THRESH){
            ofSetColor(82, 45, 0);
            artk->applyProjectionMatrix();
            artk->applyModelMatrix(markerIndexFour);
            line4.draw();
            
            ofSetColor(39, 179, 0);
            ofFill();
            ofEllipse(0, 0, disappear, disappear);
            
            disappear > 0 && ofGetElapsedTimeMillis() % 300 == 0 && --disappear;
            
        }
        
        //ofLog() << "four called" << endl;
    }
    

    
}