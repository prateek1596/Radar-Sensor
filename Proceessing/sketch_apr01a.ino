import processing.serial.*;
import java.awt.event.KeyEvent;
import java.io.IOException;

Serial myPort;
String angleStr = "", distanceStr = "", data = "", statusMsg;
float pixelDistance;
int angle = 0, distance = 0;
PFont orcFont;

void setup() {
    size(1200, 700);
    smooth();
    myPort = new Serial(this, "COM3", 9600);
    myPort.bufferUntil('.');
}

void draw() {
    background(0);
    fill(98, 245, 31);
    
    drawRadar();
    drawScannerLine();
    drawDetectedObject();
    drawHUD();
}

void serialEvent(Serial myPort) {
    try {
        data = myPort.readStringUntil('.');
        if (data != null) {
            data = data.trim();
            String[] values = data.split(",");
            if (values.length == 2) {
                angle = int(values[0].trim());
                distance = int(values[1].trim());
            }
        }
    } catch (Exception e) {
        println("Error reading serial data: " + e.getMessage());
    }
}

void drawRadar() {
    pushMatrix();
    translate(width / 2, height - height * 0.074);
    noFill();
    strokeWeight(2);
    stroke(98, 245, 31);
    
    for (int i = 1; i <= 4; i++) {
        arc(0, 0, width * (0.8 - i * 0.2), width * (0.8 - i * 0.2), PI, TWO_PI);
    }
    
    for (int i = 0; i <= 5; i++) {
        float rad = radians(i * 30);
        line(0, 0, (-width / 2) * cos(rad), (-width / 2) * sin(rad));
    }
    popMatrix();
}

void drawDetectedObject() {
    pushMatrix();
    translate(width / 2, height - height * 0.074);
    strokeWeight(9);
    stroke(255, 10, 10);
    
    if (distance < 40) {
        pixelDistance = distance * ((height - height * 0.1666) * 0.025);
        line(pixelDistance * cos(radians(angle)), -pixelDistance * sin(radians(angle)),
             (width - width * 0.505) * cos(radians(angle)), -(width - width * 0.505) * sin(radians(angle)));
    }
    popMatrix();
}

void drawScannerLine() {
    pushMatrix();
    strokeWeight(9);
    stroke(30, 250, 60);
    translate(width / 2, height - height * 0.074);
    line(0, 0, (height - height * 0.12) * cos(radians(angle)), -(height - height * 0.12) * sin(radians(angle)));
    popMatrix();
}

void drawHUD() {
    pushMatrix();
    fill(0);
    rect(0, height - height * 0.0648, width, height);
    fill(98, 245, 31);
    textSize(25);
    text("10cm", width * 0.615, height - height * 0.0833);
    text("20cm", width * 0.719, height - height * 0.0833);
    text("30cm", width * 0.823, height - height * 0.0833);
    text("40cm", width * 0.927, height - height * 0.0833);
    textSize(40);
    text("Angle: " + angle + "°", width * 0.52, height - height * 0.0277);
    text("Distance: " + (distance < 40 ? distance + " cm" : "Out of Range"), width * 0.74, height - height * 0.0277);
    popMatrix();
}
