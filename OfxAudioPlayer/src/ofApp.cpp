// Copyright (c) 2017 Eliott Paris.
// For information on usage and redistribution, and for a DISCLAIMER OF ALL
// WARRANTIES, see the file, "LICENSE.txt," in this distribution.

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetWindowTitle("OfxAudioPlayer");
    ofSetBackgroundColor(44, 44, 44);
    
    m_player.load("audio/guitar.wav");
    
    // set to multiplay after loading
    m_player.setMultiPlay(true);
}

//--------------------------------------------------------------
void ofApp::update()
{
    
}

//--------------------------------------------------------------
void ofApp::draw()
{
    int nbands = 64;
    float* spectrum = ofSoundGetSpectrum(nbands);
    
    const float width = ofGetWidth();
    const float height = ofGetHeight();
    
    const float band_width = width / nbands;
    
    for(int i = 0; i < nbands; i++)
    {
        const int band_height = spectrum[i] * height;
        
        int shift = i * band_width;
        
        ofSetColor(i * 20 % 256, i * 50 % 256, i * 100 % 256);
        ofDrawRectangle(shift, height - band_height, band_width, band_height);
        
        ofSetColor(100, 100, 100);
        ofDrawLine(shift, 0, shift, height);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
    timepoint_t now = std::chrono::system_clock::now();
    auto time_limit = std::chrono::milliseconds(60);
    
    if(now > m_last_played_time + time_limit)
    {
        //std::cout << "xy: {" << x << ", " << y << "}\n";
        
        float speed = ofMap(x, 0., ofGetWidth(), 1, 10, false);
        speed = speed - std::fmod(speed, 0.25);
        
        if(speed != m_last_speed)
        {
            float volume = ofMap(y, 0., ofGetHeight(), 1.2, 0.2, false);
            
            std::cout << "speed: " << speed << '\n';
            std::cout << "volume: " << volume << '\n';
            
            m_player.setSpeed(speed);
            m_player.setVolume(volume);
            m_player.play();
            
            m_last_played_time = now;
            m_last_speed = speed;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
    
}
