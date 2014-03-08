#include "QrScanner.h"

void QrScanner::setup() {
	ofSetVerticalSync(true);
	cam.initGrabber(640, 480);
	logo_ana.loadImage("logo_ana.jpg");
	logo_jal.loadImage("logo_jal.jpg");
}

void QrScanner::update() {
	cam.update();
	if(cam.isFrameNew()) {
		ofxZxing::Result curResult = ofxZxing::decode(cam.getPixelsRef(), true);
		float curTime = ofGetElapsedTimef();
		if(curResult.getFound()) { // only update if we found something, avoid flickering
			result = curResult;
			lastFound = curTime;
		} else if(curTime - lastFound > 1) {  // if we haven't found anything after a second
			result = curResult; // then update anyway
		}
	}
}

void QrScanner::draw() {
	ofSetColor(255);
	if(result.getFound()) {
		cam.draw(0, 0);
		
		float rotation = result.getRotation();
		ofVec2f position = result.getScreenPosition();
		float size = result.getScreenSize() / logo_jal.getWidth();
		
        ticketData = result.getText();
        string from = ofSplitString(ticketData, ",")[0];
        string to = ofSplitString(ticketData, ",")[1];
        string flight = ofSplitString(ticketData, ",")[2];
        string company = ofSplitString(ticketData, ",")[3];
        string time = ofSplitString(ticketData, ",")[4];
        
		ofPushMatrix();
		ofTranslate(position);
		ofRotate(rotation);
		ofScale(size, size, size);
        cout << company << endl;
        if(company == "JAL"){
            logo_jal.draw(-logo_jal.getWidth() / 2, -logo_jal.getHeight() / 2 +200);
        }else if(company == "ANA"){
            logo_ana.draw(-logo_ana.getWidth() / 2, -logo_ana.getHeight() / 2 +200);
        }
		ofPopMatrix();
        
        //        ofLog(OF_LOG_NOTICE, "hi");
        //        printf("hi");
		result.draw();
	} else {
		cam.draw(0, 0);
	}
    
}


string QrScanner::getName()
{
	return "QrScanner";
}
