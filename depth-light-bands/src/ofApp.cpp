#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    kinect.init(false,false);
    
    kinect.open();
    kinect.setRegistration();
    
    depth_image.allocate(kinect.width,kinect.height, OF_IMAGE_GRAYSCALE);
    
    band_group.add(band_speed.set("Speed",10,1,100));
    band_group.add(band_width.set("Width",10,1,100));
    
    band_gui.setup();
    band_gui.add(band_group);
}

//--------------------------------------------------------------
void ofApp::update(){
    int driver = band_speed * ofGetElapsedTimef();

    /*---------------------
     KINECT UPDATING
     ---------------------*/
    kinect.update();
    depth_image.setFromPixels(kinect.getDepthPixels());
    
    ofPixels & pix = depth_image.getPixels();
    
    for(int i = 0; i < pix.size(); i++){
        if(((pix[i] + driver) % 255 / band_width) % 2 && pix[i] > 5){
            pix[i] = 255;
        }else{
            pix[i] = 0;
        }
    }
    
    //    depth_image.resize(1280,800);
    depth_image.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    depth_image.draw(0,0);
    band_gui.draw();
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
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
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
