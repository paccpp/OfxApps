// Copyright (c) 2017 Eliott Paris.
// For information on usage and redistribution, and for a DISCLAIMER OF ALL
// WARRANTIES, see the file, "LICENSE.txt," in this distribution.

#pragma once

#include "ofMain.h"

#include "ofxGui.h"

//! @brief Control the size of a circle with a slider
//! @details from : http://openframeworks.cc/learning/01_basics/how_to_create_slider/
class ofApp : public ofBaseApp
{
public: // methods
    
    void setup() override;
    void update() override;
    void draw() override;
    
    void keyPressed(int key) override;
    void keyReleased(int key) override;
    void mouseMoved(int x, int y) override;
    void mouseDragged(int x, int y, int button) override;
    void mousePressed(int x, int y, int button) override;
    void mouseReleased(int x, int y, int button) override;
    void mouseEntered(int x, int y) override;
    void mouseExited(int x, int y) override;
    void windowResized(int w, int h) override;
    void dragEvent(ofDragInfo dragInfo) override;
    void gotMessage(ofMessage msg) override;
    
private: // variables
    
    ofxFloatSlider 	m_radius;
    ofxPanel        m_gui;
};
