//
//  sense.h
//  smell_o_gram
//
//  Created by Sarah on 11/28/15.
//
//

#pragma once
#include "ofMain.h"

#include "ofApp.h"
#include "ofxOpenCv.h"
#include "ofxARToolkitPlus.h"


class senses {
    public:
    
    vector<vector<ofPoint> > imagePoints;
    
//    // nodes, pointers and drawing element for sense 1
//    ofNode node1;
//    ofNode node2;
//    ofNode node3;
//    ofNode node4;
//    ofNode node5;
//    
//    ofPolyline line1;
//    
//    ofNode * nodePtrsOne[5];
//    
    // image vars for sense 1
    /* Image to distort on to the marker */
    ofImage displayImageOne;
//    /* The four corners of the image */
//    vector<ofPoint> displayImageCornersOne;

    
    // nodes, pointers and drawing element for sense 2
    ofNode node6;
    ofNode node7;
    ofNode node8;
    ofNode node9;
    ofNode node10;
    
    ofPolyline line2;
    
    ofNode * nodePtrsTwo[5];
    
    // image vars for sense 2
    /* Image to distort on to the marker */
    ofImage displayImageTwo;
    /* The four corners of the image */
    vector<ofPoint> displayImageCornersTwo;
    
    // nodes, pointers and drawing element for sense 3
    ofNode node11;
    ofNode node12;
    ofNode node13;
    ofNode node14;
    ofNode node15;
    
    ofPolyline line3;
    
    ofNode * nodePtrsOne[5];
    
    // image vars for sense 3
    /* Image to distort on to the marker */
    ofImage displayImageThree;
    /* The four corners of the image */
    vector<ofPoint> displayImageCornersThree;

    
    // Actual class functions
    
    vector<int> markers;
    vector<string> imageFiles;
    ofxARToolkitPlus artk;
    
    
    senses(vector<int> markers, vector<string> imageFiles, ofxARToolkitPlus artk);
    virtual ~senses(){};
    
    void setup();
    void update();
    void draw();
    
};