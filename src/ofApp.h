#pragma once
#include "ofMain.h"
#include "Spawner.h"

class ofApp : public ofBaseApp{

	public:
		Spawner* spawner;

		ofApp();

		void setup();
		void update();
		void draw();

		~ofApp();
};
