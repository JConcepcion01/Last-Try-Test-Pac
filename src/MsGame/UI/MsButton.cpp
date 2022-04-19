#include "MsButton.h"
MsButton::MsButton(){
   this->xPos = ofGetWidth()/2;
    this->yPos = ofGetHeight()/2;
    this->width = 64;
    this->height = 20; 
}
MsButton::MsButton(int xPos, int yPos, int width, int height, string buttonText){
    this->xPos = xPos;
    this->yPos = yPos;
    this->width = width;
    this->height = height;
    this->buttonText = buttonText;
}

void MsButton::reset(){
    pressedCounter = -1;
    pressed = false;
}
void MsButton::tick(){
    pressedCounter--;
    if(pressedCounter == 0){
        pressed = false;
        pressedCounter = -1;
    }

}

void MsButton::mousePressed(int x, int y){
    if(xPos + width >= x && x >= xPos &&  yPos + height >= y && y >= yPos){
        pressed = true;
        pressedCounter = 10;
    }
}

void MsButton::render(){
    ofSetColor(102, 255, 255);
    ofDrawBitmapString(buttonText, xPos+width/2-4*buttonText.size(), yPos+height/2);
}

bool MsButton::wasPressed(){
    return pressed;
}