#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(512, 424);
	ofSetFrameRate(30);

	if (!initKinect()) exit();
	infraredBuffer.resize(irWidth*irHeight);
	irImage.allocate(irWidth, irHeight, OF_IMAGE_GRAYSCALE);
}

//--------------------------------------------------------------
void ofApp::update(){
	IInfraredFrame *infraredFrame = nullptr;
	HRESULT hResult = infraredReader -> AcquireLatestFrame(&infraredFrame);
	//if (infraredBuffer.size() != 0) infraredBuffer.clear();
	if (SUCCEEDED(hResult)) {
		hResult = infraredFrame ->CopyFrameDataToArray(infraredBuffer.size(),&infraredBuffer[0]);

		for (int i = 0; i < infraredBuffer.size(); i++){
			irImage.getPixels()[i] = infraredBuffer[i];
		}
		irImage.update();

	}

	SafeRelease(infraredFrame);
}

//--------------------------------------------------------------
void ofApp::draw(){
	irImage.draw(0,0,irWidth,irHeight);
}

bool ofApp::initKinect() {
	//sensor
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
