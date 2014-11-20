#include "ofApp.h"

bool compare( ofVec2f a, ofVec2f b) {
    return a.y < b.y;
}

//--------------------------------------------------------------
void ofApp::setup(){
    initImg.loadImage("25.jpg");
    initImg.setImageType(OF_IMAGE_GRAYSCALE);
    threshImg.allocate(initImg.getWidth(), initImg.getHeight(), OF_IMAGE_GRAYSCALE);
    
    unsigned char * pixinit = initImg.getPixels();
    unsigned char * pixthresh = threshImg.getPixels();
    
    blackCount = 0;
    totalCount = 0;
    pixpos.set(0,0);
    
    
    int xTotal = 0;
    int yTotal = 0;
    xAvg = 0;
    yAvg = 0;
  
    
    
    
//    for (int i = 0; i < initImg.getWidth() * initImg.getHeight(); i++){
//        
//        totalCount++;
//        
//        if (pixinit[i] > 200){
//            pixthresh[i] = 255;
//        } else {
//            blackCount++;
//            pixthresh[i] = 0;
//        }
//        
//    }
    
    
    for (int i = 0; i < initImg.getWidth(); i++){
        for (int j = 0; j < initImg.getHeight(); j++){
            
            pixpos.x = i;
            pixpos.y = j;
            
            pos = j * initImg.getWidth() + i;
            
            if (pixinit[pos] > 200){
                pixthresh[pos] = 255;
            } else {
                posvec.push_back(pixpos);
                pixthresh[pos] = 0;
                cout << pixpos << endl;
            }
            
            

        }
    }
    
    int pvSize = posvec.size();
    
    for (int k = 0; k < pvSize; k++) {
        xTotal += posvec[k].x;
        yTotal += posvec[k].y;
    }
    
    yAvg = yTotal/pvSize;
    xAvg = xTotal/pvSize;
    
    minX = posvec[0].x;
    maxX = posvec[pvSize-1].x;
    
    ofSort(posvec, compare);
    
    minY = posvec[0].y;
    maxY = posvec[pvSize-1].y;
    
    
    cout << "xMin: " << minX << " xMax: " << maxX << " yMin: " << minY << " yMax: " <<  maxY << endl;
    cout << initImg.getWidth() + 20 + minX << " " <<  minY << " " << maxX - minX << " " << maxY - minY << endl;
    
    threshImg.update();
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,255,255);
    initImg.draw(0,0);
    
    threshImg.draw(initImg.getWidth()+20, 0);
    ofSetColor(0,0,255);
    ofCircle(xAvg + initImg.getWidth(), yAvg, 14);

    ofNoFill();
    ofSetColor(255, 0, 0);//stroke color
    ofRect(initImg.getWidth() + 20 + minX, minY, maxX - minX, maxY - minY);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
