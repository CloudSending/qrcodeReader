#include "testApp.h"
#include "QrScanner.h"

void testApp::setup() {
	// setup shared data
	stateMachine.getSharedData().counter = 0;
	stateMachine.getSharedData().lastUpdate = ofGetElapsedTimeMillis();
	stateMachine.getSharedData().font.loadFont("font/avenir-next-medium-sc-latin-1.ttf", 50);
	
	// initialise state machine
	stateMachine.addState<QrScanner>();

	stateMachine.changeState("QrScanner");
}

void testApp::update() {
}

void testApp::draw() {
}
