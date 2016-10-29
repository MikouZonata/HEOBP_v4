#include "ofApp.h"

ofApp::ofApp() {

}

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(ofColor(0, 0, 0, 255));
	spawner = Spawner::Instance();
}

//--------------------------------------------------------------
void ofApp::update(){
	spawner->Update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	spawner->Draw();
}

ofApp::~ofApp() {

}
