#pragma once

#include "ofMain.h"
#include "ofxStateMachine.h"
#include "shareData.h"


class testApp : public ofBaseApp {

    public:
        void setup();
        void update();
        void draw();
        
    private:
        itg::ofxStateMachine<SharedData> stateMachine;

};
