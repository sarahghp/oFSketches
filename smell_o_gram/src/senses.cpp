//
//  sense.cpp
//  smell_o_gram
//
//  Created by Sarah on 11/28/15.
//
//

#include "senses.h"


//--------------------------------------------------------------

senses::senses(vector<int> markers, vector<string> imageFiles, ofxARToolkitPlus artk):
    markers(markers), imageFiles(imageFiles), artk(artk) {}


//--------------------------------------------------------------

void senses::setup(){
    
    // Load image points
    for (int i = 0; i < 3; i++){
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
    
}

//--------------------------------------------------------------

void senses::update(){
    
}

//--------------------------------------------------------------

void senses::draw(){
    
    int markerIndexOne = artk.getMarkerIndex(markers[0]);
    int markerIndexTwo = artk.getMarkerIndex(markers[1]);
    int markerIndexThree = artk.getMarkerIndex(markers[2]);
    
    displayImageOne.loadImage(imageFiles[0]);
    displayImageTwo.loadImage(imageFiles[1]);
    displayImageThree.loadImage(imageFiles[2]);
    
    if (markerIndexOne >= 0){
        // Get the corners
        vector<ofPoint> corners1;
        artk.getDetectedMarkerBorderCorners(markerIndexOne, corners1);
        
        // Homography
        // Here we feed in the corners of an image and get back a homography matrix
        ofMatrix4x4 homo = artk.getHomography(markerIndexOne, imagePoints[0]);
        // We apply the matrix and then can draw the image distorted on to the marker
        ofPushMatrix();
        glMultMatrixf(homo.getPtr());
        ofSetHexColor(0xffffff);
        displayImageOne.draw(0, 0);
        ofPopMatrix();

    }

    if (markerIndexTwo >= 0){
        // Get the corners
        vector<ofPoint> corners2;
        artk.getDetectedMarkerBorderCorners(markerIndexTwo, corners2);
        
        // Homography
        // Here we feed in the corners of an image and get back a homography matrix
        ofMatrix4x4 homo = artk.getHomography(markerIndexTwo, imagePoints[1]);
        // We apply the matrix and then can draw the image distorted on to the marker
        ofPushMatrix();
        glMultMatrixf(homo.getPtr());
        ofSetHexColor(0xffffff);
        displayImageTwo.draw(0, 0);
        ofPopMatrix();
    }
    
    if (markerIndexThree >= 0){
        // Get the corners
        vector<ofPoint> corners3;
        artk.getDetectedMarkerBorderCorners(markerIndexThree, corners3);
        
        // Homography
        // Here we feed in the corners of an image and get back a homography matrix
        ofMatrix4x4 homo = artk.getHomography(markerIndexThree, imagePoints[2]);
        // We apply the matrix and then can draw the image distorted on to the marker
        ofPushMatrix();
        glMultMatrixf(homo.getPtr());
        ofSetHexColor(0xffffff);
        displayImageThree.draw(0, 0);
        ofPopMatrix();
    }
    
    
}