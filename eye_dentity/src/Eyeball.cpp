//
//  Eyeball.cpp
//  eye_dentity
//
//  Created by Sarah on 10/4/15.
//
//

#include "Eyeball.h"
// #define DEBUG_DRAW

//--------------------------------------------------------------

Eyeball::Eyeball(ofImage* pic) : ofxBox2dCircle(), pic(pic) {}


//--------------------------------------------------------------

Eyeball::~Eyeball(){

}

//--------------------------------------------------------------

void Eyeball::draw(){

    if(!isBody()) return;
    
    // debug draw physics circles
    
    #ifdef DEBUG_DRAW
    ofPushMatrix();
    ofTranslate(getPosition().x, getPosition().y, 0);
    ofRotate(getRotation(), 0, 0, 1);
    ofCircle(0, 0, getRadius());
    
    ofPushStyle();
    ofEnableAlphaBlending();
    ofSetColor(0);
    ofLine(0, 0, getRadius(), 0);
    if(isSleeping()) {
        ofSetColor(255, 100);
        ofCircle(0, 0, getRadius());
    }
    ofPopStyle();
    
    ofPopMatrix();
    #endif
    
    ofVec2f position(getPosition());
    float radius = getRadius();
    
    ofPushMatrix();
    
    ofTranslate(position.x, position.y, 0);
    ofRotate(getRotation(), 0, 0, 1);
    pic->draw(-radius, -radius, radius * 2, radius * 2);
    
    
    ofPopMatrix();
}