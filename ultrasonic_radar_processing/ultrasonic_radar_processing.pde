import processing.serial.*;

Serial port;
float line_max_size = 10000.0;
int half_size = 500;
int angle = 0;
  
void setup() {
  //printArray(Serial.list());

  size(1000, 1000);
  background(255);
  
  port = new Serial(this, "/dev/cu.usbserial-1420", 9600);
  port.write(angle);
}

void draw() {
  
  if(port.available() > 0){
    float line_length;
    int distance = port.read();
    println("distance: " + distance);
    
    //if(0 < distance){
    //  dist_x = (float)(line_max_size / distance);
    //}else{
    //  dist_x = line_max_size;
    //}
    
    line_length = map(distance, 0, 100, 0, line_max_size);
    println("line_length: " + line_length);
    
    // white line
    //stroke(255);
    //line(half_size, 0, 4000 * cos(radian(angle)) + half_size, 4000 * sin(radian(angle)));
    
    // balck line
    stroke(0);
    line(
      half_size, 
      0, 
      half_size + line_length * cos(radian(angle)),
      line_length * sin(radian(angle))
    );
    
    angle = angle + 1;
    
    if (120 <= angle) {
      angle = 0;
      background(255);
    }
    
    println("angle: " + angle);
    port.write(angle);
    delay(100);
  }
}

float radian(int angle){
  return (angle + 30) / 180.0 * PI;
}

void mousePressed(){
  angle = 0;
  port.write(angle);
}
