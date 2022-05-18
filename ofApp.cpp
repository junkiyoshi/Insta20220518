#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofSetColor(255);
	ofNoFill();
	ofSetLineWidth(2);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);

}

//--------------------------------------------------------------
void ofApp::update() {
	
	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	auto max_loop = 5;
	auto max_scale = 35;
	for (int deg_start = 0; deg_start < 360; deg_start += 1) {

		auto loop = ofMap(ofNoise(cos(deg_start * DEG_TO_RAD) * 0.25, sin(deg_start * DEG_TO_RAD) * 0.25, ofGetFrameNum() * 0.01), 0, 1, -1.5, max_loop);

		ofBeginShape();
		for (int deg = deg_start; deg <= deg_start + 360 * loop; deg++) {

			auto scale = ofMap(deg, deg_start, deg_start + 360 * max_loop, 3, max_scale);
			auto location = make_point(deg * DEG_TO_RAD) * scale;

			ofVertex(location);
		}
		ofEndShape();
	}
}

//--------------------------------------------------------------
// Reference by https://twitter.com/shiffman/status/1095764239665512453
glm::vec2 ofApp::make_point(float theta) {

	float x = 16 * (pow(sin(theta), 3));
	float y = 13 * cos(theta) - 5 * cos(2 * theta) - 2 * cos(3 * theta) - cos(4 * theta);
	return glm::vec2(x, -y);
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}