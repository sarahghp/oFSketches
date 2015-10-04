//
//  Eyeball.h
//  eye_dentity
//
//  Created by Sarah on 10/4/15.
//
//

#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"

class Eyeball : public ofxBox2dCircle {
    
public:
    
    Eyeball(ofImage* pic);

    virtual ~Eyeball();
    
    virtual void draw();
    
private:
    
    ofImage* pic;
    
};


