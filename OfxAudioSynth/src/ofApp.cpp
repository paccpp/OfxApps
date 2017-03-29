// Copyright (c) 2017 Eliott Paris.
// For information on usage and redistribution, and for a DISCLAIMER OF ALL
// WARRANTIES, see the file, "LICENSE.txt," in this distribution.

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetWindowTitle("OfxAudioSynth");
    ofSetBackgroundColor(44, 44, 44);
    
    // IO setup : 2 output channels (stereo), 0 input channels
    ofSoundStreamSetup(2, 0);
    
    m_bands = 64;
    
    m_oscbank.reserve(m_bands);
    
    size_t min = 100;
    size_t max = 5000;
    
    size_t band_width = (max - min) / m_bands;
    
    for(size_t i = 0; i < m_bands; ++i)
    {
        m_oscbank.push_back(new Osc<float>());
        m_oscbank[i]->setFrequency(i * (float)band_width + min);
        m_oscbank[i]->setVolume(0.);
    }
}

//--------------------------------------------------------------
void ofApp::exit()
{
    // free the memory allocated for each Osc objects of the vector
    for(Osc<float>* osc : m_oscbank)
    {
        delete osc;
    }
    
    // then clear the vector
    m_oscbank.clear();
}

//--------------------------------------------------------------
void ofApp::update()
{
    
}

//--------------------------------------------------------------
void ofApp::audioOut(ofSoundBuffer& buffer)
{
    const size_t osc_count = (!m_oscbank.empty()) ? m_oscbank.size() : 1ul;
    
    for(int i = 0; i < buffer.getNumFrames() * buffer.getNumChannels(); i += 2)
    {
        double out = 0.f;
        
        for(Osc<float>* osc : m_oscbank)
        {
            osc->setSampleRate(buffer.getSampleRate());
            out += osc->process();
        }
        
        out /= (float)osc_count;
        
        buffer[i] = out;    // writing to the left channel
        buffer[i+1] = out;  // writing to the right channel
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    const float width = ofGetWidth();
    const float height = ofGetHeight();
    
    const float band_width = width / m_bands;
    
    for(int i = 0; i < m_bands; i++)
    {
        const int band_height = m_oscbank[i]->getVolume() * height;
        
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
    const float width = ofGetWidth();
    const float height = ofGetHeight();
    
    int band_index = 0;
    
    float volume = ofMap(y, 0., height, 1., 0., true);
    float mapped_x = ofMap(x, 0., width, 0., 1., false);
    
    if(mapped_x > 0. && mapped_x <= 1.)
    {
        band_index = mapped_x * (m_bands - 1);
        m_oscbank[band_index]->setVolume(volume);
        
        std::cout << "freq: " << m_oscbank[band_index]->getFrequency() << "\n";
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
