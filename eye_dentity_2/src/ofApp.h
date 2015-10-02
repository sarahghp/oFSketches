// Face-tracking code adapted from FaceOSC-Templates by Dan Wilcox
// https://github.com/CreativeInquiry/FaceOSC-Templates

#pragma once

#include "ofMain.h"

#include "ofxOsc.h"
#include "ofxOpenCv.h"

#include "Face.h"
#include "particle.h"

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
    
    // Face tracking buddies
    ofxOscReceiver	receiver;
    Face face;
    
    // For the video
    ofVideoGrabber 		vidGrabber;
    ofxCvColorImage     vid;
    
    // PARTICLES!!
    vector <particle> particles;
};
