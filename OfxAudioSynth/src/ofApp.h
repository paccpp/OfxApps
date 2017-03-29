// Copyright (c) 2017 Eliott Paris.
// For information on usage and redistribution, and for a DISCLAIMER OF ALL
// WARRANTIES, see the file, "LICENSE.txt," in this distribution.

#pragma once

#include "ofMain.h"
#include "Osc.hpp"
using paccpp::Osc;

//! @brief Play sound
//! @see http://openframeworks.cc/learning/04_sound/play_a_sound/
class ofApp : public ofBaseApp
{
public: // methods
    
    using timepoint_t = std::chrono::system_clock::time_point;
    
    void setup() override;
    void update() override;
    void draw() override;
    void exit() override;
    
    void audioOut(ofSoundBuffer& buffer) override;
    
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
    
    std::vector<Osc<float>*> m_oscbank {};
    size_t                   m_bands = 0;
};
