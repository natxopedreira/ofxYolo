#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    string config = ofToDataPath("yolov3.cfg", true);
    string weights = ofToDataPath("yolov3.weights", true);
    string names = ofToDataPath("coco.names", true);

    darkhelp.init(config, weights, names);

    darkhelp.threshold                      = 0.3;
    darkhelp.include_all_names              = false;
    darkhelp.names_include_percentage       = true;
    darkhelp.annotation_include_duration    = false;
    darkhelp.annotation_include_timestamp   = false;
    darkhelp.sort_predictions               = DarkHelp::ESort::kAscending;


    video.load("test.mp4");
    video.play();
}

//--------------------------------------------------------------
void ofApp::update(){

    video.update();

    if(video.isFrameNew()){

        resultados = darkhelp.predict(ofxCv::toCv(video));

    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    video.draw(0,0);

    for( auto resultado : resultados){
        ofNoFill();
        ofDrawRectangle(ofxCv::toOf(resultado.rect));

        ofFill();
        string info = resultado.name;
        ofDrawBitmapString(info, glm::vec2(resultado.rect.x, resultado.rect.y - 10));
    }

}

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
