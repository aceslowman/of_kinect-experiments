#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    kinect.init(false,false);
    
    kinect.open();
    kinect.setRegistration();
    
    depth_image.allocate(ofGetWidth(),ofGetHeight(),OF_IMAGE_GRAYSCALE);
    
    band_group.add(band_speed.set("Speed",10,1,100));
    band_group.add(band_width.set("Width",10,1,100));
    
    kinect_group.add(kinect_smooth.set("Smoothing",5,0,50));
    
    gui.setup();
    gui.add(band_group);
    gui.add(kinect_group);
    
    output_type = OF_IMAGE_GRAYSCALE;
    input_type = OF_IMAGE_GRAYSCALE;
}

//--------------------------------------------------------------
void ofApp::update(){
    int driver = band_speed * ofGetElapsedTimef();
    
    /*---------------------
     KINECT UPDATING
     ---------------------*/
    kinect.update();
    depth_image.setFromPixels(kinect.getDepthPixels());
    depth_image.resize(ofGetWidth(),ofGetHeight());//fix aspect ratio issues
    depth_image.setImageType(input_type);
    
    /* SMOOTHING */
    Mat dest;
    Mat src = toCv(depth_image.getPixels());
    
    ofPixels cvOut;
    
    blur(src,dest,kinect_smooth);
    
    toOf(dest, cvOut);
    
    depth_image.setFromPixels(cvOut.getData(),ofGetWidth(),ofGetHeight(),output_type);
    depth_image.update();
    
    ofPixels & pix = depth_image.getPixels();
    
    for(int i = 0; i < pix.size(); i++){
        if(((pix[i] + driver) % 255 / band_width) % 2 && pix[i] > 5){
            pix[i] = 255;
        }else{
            pix[i] = 0;
        }
    }
    
    depth_image.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(0);
    depth_image.draw(0,0);
    
    syphon.publishScreen();
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'c'){
        capture_frames = !capture_frames;
    }
    if(key == '1'){
        output_type = OF_IMAGE_COLOR_ALPHA;
    }
    if(key == '2'){
        output_type = OF_IMAGE_COLOR;
    }
    if(key == '3'){
        output_type = OF_IMAGE_GRAYSCALE;
    }
    if(key == '!'){
        input_type = OF_IMAGE_COLOR_ALPHA;
    }
    if(key == '@'){
        input_type = OF_IMAGE_COLOR;
    }
    if(key == '#'){
        input_type = OF_IMAGE_GRAYSCALE;
    }
    
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
