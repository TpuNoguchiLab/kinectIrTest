#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(1920, 1080);
	ofSetFrameRate(30);

	if (!initKinect()) exit();

	irImage.allocate(512, 424, OF_IMAGE_GRAYSCALE);
}

//--------------------------------------------------------------
void ofApp::update(){
	IInfraredFrame *infraredFrame = nullptr;
	HRESULT hResult = infraredReader -> AcquireLatestFrame(&infraredFrame);

	if (SUCCEEDED(hResult)) {
		//hResult = infraredFrame ->CopyFrameDataToArray(irWidth*irHeight*irBytesPerPixels, irimage.getPixels(),ColorImageFormat_Rgba);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

}

bool ofApp::initKinect() {
	//senspr
	HRESULT hResult = S_OK;
	hResult = GetDefaultKinectSensor(&sensor);
	if (FAILED(hResult)) {
		std::cerr << "Error : GetDefaultKinectSensor" << std::endl;
		return -1;
	}

	hResult = sensor->Open();
	if (FAILED(hResult)){
		std::cerr << "Error : IKinectSensor::Open()" << std::endl;
		return -1;
	}

	//ir
	hResult = sensor->get_InfraredFrameSource(&infraredSource);
	if (FAILED(hResult)){
		std::cerr << "Error : get_InfraredFrameSource" << std::endl;
		return -1;
	}
	hResult = infraredSource->OpenReader(&infraredReader);
	if (FAILED(hResult)){
		std::cerr << "Error : OpenReader" << std::endl;
		return -1;
	}
	hResult = infraredSource->OpenReader(&infraredReader);
	if (FAILED(hResult)){
		std::cerr << "Error : OpenReader" << std::endl;
		return -1;
	}

	hResult = infraredSource->get_FrameDescription(&infraredDescription);
	if (FAILED(hResult)){
		std::cerr << "Error : IColorFrameSource::get_FrameDescription()" << std::endl;
		return -1;
	}


	infraredDescription -> get_Width(&irWidth);
	infraredDescription -> get_Height(&irHeight);
	infraredDescription -> get_BytesPerPixel(&irBytesPerPixels);

	return 1;

};

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
