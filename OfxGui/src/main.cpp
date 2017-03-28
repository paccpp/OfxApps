// Copyright (c) 2017 Eliott Paris.
// For information on usage and redistribution, and for a DISCLAIMER OF ALL
// WARRANTIES, see the file, "LICENSE.txt," in this distribution.

#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main()
{
    // Set the application's width, height and screen mode
    ofSetupOpenGL(600, 400, OF_WINDOW);
    
    // Run the App
    ofRunApp(new ofApp());
}
