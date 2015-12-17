#pragma once

#include "ofMain.h"
#include <kinect.h>

template<class Interface>
inline void SafeRelease(Interface *& pInterfaceToRelease)
{
	if (pInterfaceToRelease != NULL){
		pInterfaceToRelease->Release();
		pInterfaceToRelease = NULL;
	}
}

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		bool initKinect();

		ofImage irimage;

		IKinectSensor *sensor;

		IInfraredFrameSource *infraredSource;
		IInfraredFrameReader *infraredReader;
		IFrameDescription *infraredDescription;
		int irWidth,irHeight;
		unsigned int irBytesPerPixels;


};
