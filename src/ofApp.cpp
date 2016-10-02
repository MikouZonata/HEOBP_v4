#include "ofApp.h"

ofApp::ofApp() {
	ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(ofColor(0, 0, 0, 255));
	spawner1 = Spawner();
	spawner2 = Spawner();
	spawner3 = Spawner();
}

//--------------------------------------------------------------
void ofApp::update(){
	spawner1.Update();
	spawner2.Update();
	spawner3.Update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	spawner1.Draw();
	spawner2.Draw();
	spawner3.Draw();
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

ofApp::~ofApp() {

}
