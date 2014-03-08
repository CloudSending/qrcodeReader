#ifndef __qrcodeReader__QrScanner__
#define __qrcodeReader__QrScanner__

#pragma once

#include "ofxState.h"
#include "shareData.h"
#include "ofxZxing.h"


class QrScanner : public itg::ofxState<SharedData> {
public:
	void setup();
	void update();
	void draw();
	
	ofxZxing::Result result;
	ofImage logo_ana;
	ofImage logo_jal;
	ofVideoGrabber cam;
	float lastFound;
    
    string ticketData;
    
    string getName();
        
};

#endif