#pragma once
#include "ofMain.h"

class particle
{
    public:
        ofVec2f pos;
        ofVec2f vel;
        ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
        ofVec2f origin;
			
        particle();
		virtual ~particle(){};

        void resetForce();
        void addForce(float x, float y);
        void addForce(const ofVec2f& frc);
        void addDampingForce();
        void setInitialCondition(float px, float py, float vx, float vy);
        void update();
        void draw();
	
		void bounceOffWalls();
	
	
		float damping;

    protected:
    private:
};

