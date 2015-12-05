//
//  sense.cpp
//  smell_o_gram
//
//  Created by Sarah on 11/28/15.
//
//

#include "senses.h"

#define VERT_THRESH 320
//#define DEBUG

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
    
    // Setup sense 1
    
    gradCircle.loadImage("thinking.png");
    
    // Setup sense 2
    
    for (int i = 0; i < 24; i++){
        ofVec2f pos;
        pos.x = ofRandom(ofGetWidth());
        pos.y = ofRandom(ofGetHeight());
        ells.push_back(pos);
    }

    rectHeight = 0;
    rectY = 0;

    // Node setup sense 3
    node11.setPosition(0, 0, 0);
    node12.setParent(node11);
    node12.setPosition(0, -100, 100);
    node13.setParent(node12);
    node13.setPosition(ofGetWidth(), -ofGetHeight(), 50);
    node14.setParent(node11);
    node14.setPosition(-ofGetWidth()/2, ofGetHeight(), -20);
    node15.setParent(node14);
    node15.setPosition(-ofGetWidth()/4, ofGetHeight()/4, 0);
    
    nodePtrsThree[0] = &node11;
    nodePtrsThree[1] = &node12;
    nodePtrsThree[2] = &node13;
    nodePtrsThree[3] = &node14;
    nodePtrsThree[4] = &node15;
    
    // Node setup sense 4
    node16.setPosition(0, 0, 0);
    node17.setPosition(0, 0, 0);
    node18.setPosition(0, 0, 0);
    node19.setPosition(0, 0, 0);
    node20.setPosition(0, 0 , 0);
    
    nodePtrsFour[0] = &node16;
    nodePtrsFour[1] = &node17;
    nodePtrsFour[2] = &node18;
    nodePtrsFour[3] = &node19;
    nodePtrsFour[4] = &node20;
    
    disappear = 5;
    dirt.loadImage("dirt.png");
    
    
}

//--------------------------------------------------------------

void senses::update(){
    
    // Updates for sense 2

    int testTwo = artk->getMarkerIndex(markers[1]);
    
    if (testTwo >= 0){
        if(rectHeight < ofGetHeight() + 400){
            rectHeight++;
        } else if(rectY < ofGetHeight() + 200){
            rectY++;
        } else {
            rectHeight = 0;
            rectY = 0;
        }
    }
    
    
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
    node16.setPosition(300 * sin(ofGetElapsedTimef()/2),-300,100);
    node17.setPosition(300 * sin(ofGetElapsedTimef()/2),-100,300);
    node18.setPosition(300 * sin(ofGetElapsedTimef()/2),0,0);
    node19.setPosition(300 * sin(ofGetElapsedTimef()/2),300,-300);
    node20.setPosition(300 * sin(ofGetElapsedTimef()/2),100,-100);

    
    for (int i = 0; i < 5; i++){
        
        line4.addVertex(nodePtrsFour[i]->getGlobalPosition());
        if (line4.size() > 3000){
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
            ofSetColor(255, 255, 255, 100);
            ofFill();
            ofRect(0, 0, ofGetWidth(), ofGetHeight());
            
            ofSetColor(255, 0, 47);
            for (int i = 0; i < 400; i++){
                ofRect(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0, 3, 3 );
            }
            
            ofSetColor(255, 255, 255, 255);
            
            #ifdef DEBUG
            int baseCenter = ofGetWidth()/4;
            # else
            int baseCenter = ofGetWidth()/2;
            # endif
            
            gradCircle.draw(baseCenter - 150, VERT_THRESH - 200);
            
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
        
        int breath = ofMap(sin(ofGetElapsedTimef()), -1, 1, 12, 40);
        
        if (corners2[2].y < VERT_THRESH || corners2[3].y < VERT_THRESH){
            ofSetColor(15, 231, 255, 170);
            ofFill();
            ofRect(0, rectY, ofGetWidth(), rectHeight);
            
            
            if (rectHeight > 0){
                for (int i = 0; i < ells.size(); i++){
                    if ((rectY == 0 && ells[i].y < rectHeight) || (rectY > 0 && ells[i].y > rectY)){
                        if(i % 2 == 0){
                            ofSetColor(255, 133, 177, 178);
                            ofEllipse(ells[i].x, ells[i].y, breath, breath);
                        } else if(i % 3 == 0){
                            ofSetColor(255, 255, 255, 178);
                            ofEllipse(ells[i].x, ells[i].y, breath + 20, breath + 20);
                        } else {
                            ofSetColor(240, 255, 153);
                            ofEllipse(ells[i].x, ells[i].y, breath - 10, breath - 10);
                        }
                        
                    }
                }
            }
            
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
            ofSetColor(240, 255, 153);
            ofFill();
            for (int i = 0; i < 20; i++){
                int randRad = ofRandom(2, 60);
                ofEllipse(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(-100, 100), randRad, randRad);
            }
            
            ofSetColor(255, 21, 0);
            artk->applyProjectionMatrix();
            artk->applyModelMatrix(markerIndexThree);
            line3.draw();
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
            dirt.draw(0, -100);
            dirt.draw(0, 0);
            dirt.draw(0, 200);
            dirt.draw(0, 600);
            dirt.draw(0, 800);
            dirt.draw(0, 1200);
            dirt.draw(0, 1400);
            
            ofSetColor(41, 12, 0);
            artk->applyProjectionMatrix();
            artk->applyModelMatrix(markerIndexFour);
            line4.draw();
            
            ofSetColor(0, 182, 39);
            ofFill();
            ofEllipse(0, 0, disappear, disappear);
            
            disappear > 0 && ofGetElapsedTimeMillis() % 200 == 0 && --disappear;
            
        }
        
        //ofLog() << "four called" << endl;
    }
    

    
}