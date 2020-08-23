import processing.serial.*;

import processing.serial.*;
Serial port;
int angle;

void setup() {
  size(255, 255);
  port = new Serial(this, "/dev/cu.usbserial-1420", 9600);
  
  background(255);
  angle = 60;
  port.write(angle);
}

void draw() {
  int c;
  
  if(port.available() > 0){
    float a;
    c = port.read();
    if(c > 0){
      a = (float)(4000.0 / c);
    }else{
      a = 4000;
    }
    
    line(128, 0, 4000 * cos((angle + 30) / 180.0 * PI) + 128, 4000 * sin((angle + 30) / 180.0 * PI));
    
    stroke(0);
    
    line(128, 0, a * cos((angle + 30) / 180.0 * PI) + 128, a * sin((angle + 30) / 180.0 * PI));
    
    angle++;
    
    if (angle > 120) angle = 0;
    
    port.write(120 - angle);
  }
}

void mousePressed(){
  angle = 60;
  port.write(angle);
}
