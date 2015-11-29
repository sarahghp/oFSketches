#pragma once

#include "ofxOpenCv.h"
#include "ofxARToolkitPlus.h"
#include "senses.h"

#include "ofMain.h"

// Uncomment this to use a camera instead of a video file
#define CAMERA_CONNECTED

// Uncomment this to turn on debug features
#define DEBUG

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    /* Size of the image */
    int width, height;
    
    /* Use either camera or a video file */
    #ifdef CAMERA_CONNECTED
    ofVideoGrabber vidGrabber;
    #else
    ofVideoPlayer vidPlayer;
    #endif
    
    /* ARToolKitPlus class */
    ofxARToolkitPlus artk;
    int threshold;
    
    /* OpenCV images */
    ofxCvColorImage colorImage;
    ofxCvGrayscaleImage grayImage;
    ofxCvGrayscaleImage	grayThres;
    
    #ifdef DEBUG
    /* Image to distort on to the marker */
    ofImage displayImage;
    /* The four corners of the image */
    vector<ofPoint> displayImageCorners;
    
    /* Node things */
    ofNode nodea;
    ofNode nodeb;
    ofNode nodec;
    ofNode noded;
    ofNode nodee;
    
    ofPolyline line;
    
    ofNode * nodePtrs[5];
    #endif
    
    /* Senses */
    senses * ss;

		
};
