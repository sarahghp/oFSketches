//
//  nodes.cpp
//  smell_o_gram
//
//  Created by Sarah on 11/27/15.
//
//

#include "nodes.h"

class nodules {
    
    public:
    
        void setup();
        void update();
        void draw();
    
        ofNode node;
        ofNode node2;
        ofNode node3;
        ofNode node4;
        ofNode node5;
    
        ofEasyCam cam;
        ofPolyline line;
    
        ofNode * nodePtrs[5];
    
}