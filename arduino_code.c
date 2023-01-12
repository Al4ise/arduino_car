int trigPin = 9;
int echoPin = 10;

int en1 = 2;
int in1 = 3;
int in2 = 4;

int en2 = 7;
int in3 = 5;
int in4 = 6;

int stop = 0;

void setup(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(en1, OUTPUT);
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(en2, OUTPUT);
  pinMode(in3, INPUT);
  pinMode(in4, INPUT);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  long echoPinReading;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  double duration = pulseIn(echoPin, HIGH);
  double distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
  Forward(255);
  
  if (stop>1){
    Stop();
  }
  
  if(distance<40){
    if(stop<2){
      stop++;
    }
  }
  else{
    if(stop>-2){
      stop--;
    }
  }
}

void Forward(int speedval){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW); 
  analogWrite(en1, speedval);
}

void Backward(int speedval){
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);
  analogWrite(en2, speedval);
}

void Stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW); 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW); 
}
