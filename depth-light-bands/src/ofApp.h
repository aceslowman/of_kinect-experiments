#pragma once

#include "ofMain.h"
#include "ofxKinect.h"
#include "ofxGui.h"
#include "ofxCv.h"
#include "ofxSyphon.h"


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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    ofxKinect kinect;
    
    ofImage depth_image;
    
    ofxPanel gui;
    
    ofParameterGroup band_group;
    ofParameter<int> band_speed;
    ofParameter<int> band_width;

    ofParameterGroup kinect_group;
    ofParameter<int> kinect_smooth;
    
    bool capture_frames;
    ofImageType output_type, input_type;
    
    ofxSyphonServer syphon;
};
