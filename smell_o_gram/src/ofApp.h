#pragma once

#include "ofxOpenCv.h"
#include "ofxARToolkitPlus.h"

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
    
    /* Image to distort on to the marker */
    ofImage displayImage;
    /* The four corners of the image */
    vector<ofPoint> displayImageCorners;
    
    /* Node things */
    ofNode node;
    ofNode node2;
    ofNode node3;
    ofNode node4;
    ofNode node5;
    
    ofPolyline line;
    
    ofNode * nodePtrs[5];

		
};
