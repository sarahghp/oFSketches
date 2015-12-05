//
//  sense.h
//  smell_o_gram
//
//  Created by Sarah on 11/28/15.
//
//

#pragma once
#include "ofMain.h"

#include "ofxOpenCv.h"
#include "ofxARToolkitPlus.h"


class senses {
public:
    
    vector<vector<ofPoint> > imagePoints;
    
    // image vars for sense 1
    /* Image to distort on to the marker */
    ofImage displayImageOne;
    /* The four corners of the image */
    vector<ofPoint> displayImageCornersOne;
    
    int rectHeight;
    int rectY;
    vector<ofVec2f> ells;
    ofImage gradCircle;
    
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
    
    ofNode * nodePtrsThree[5];
    
    // image vars for sense 3
    /* Image to distort on to the marker */
    ofImage displayImageThree;
    /* The four corners of the image */
    vector<ofPoint> displayImageCornersThree;
    
    // nodes, pointers and drawing element for sense 4
    ofNode node16;
    ofNode node17;
    ofNode node18;
    ofNode node19;
    ofNode node20;
    
    ofPolyline line4;
    
    ofNode * nodePtrsFour[5];
    int disappear;
    
    // image vars for sense 3
    /* Image to distort on to the marker */
    ofImage displayImageFour;
    /* The four corners of the image */
    vector<ofPoint> displayImageCornersFour;
    
    ofImage dirt;
    
    
    // Actual class functions
    
    vector<int> markers;
    vector<string> imageFiles;
    ofxARToolkitPlus * artk;
    
    
    senses(vector<int> markers, vector<string> imageFiles, ofxARToolkitPlus * artk);
    virtual ~senses(){};
    
    void setup();
    void update();
    void draw();
    
};