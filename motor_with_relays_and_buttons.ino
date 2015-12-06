// test use of three relays for turning on and 
// controlling polarity of power to a motor

// also have two buttons
//   one controls power to motor: when pressed, motor turns
//   other is a "toggle" switch: each time it's pressed, the motor direction is changed

const int power_pin = A1;
const int dir_pin = A0;
const int power_button = 9;
const int dir_button = 10;
const int led = 13;

int prev_button_state = 1;
int dir_state = 1;

void setup() {
  pinMode(power_pin, OUTPUT);
  pinMode(dir_pin, OUTPUT);
  pinMode(power_button, INPUT);
  pinMode(dir_button, INPUT);
  digitalWrite(power_pin, HIGH);
  digitalWrite(dir_pin, HIGH);
  digitalWrite(power_button, HIGH);
  digitalWrite(dir_button, HIGH);

  pinMode(led, OUTPUT);
  flash(2, 100);
}

void loop() {
  digitalWrite(power_pin, digitalRead(power_button));

  int button_state = digitalRead(dir_button);
  if(!button_state && prev_button_state) {
    dir_state = 1 - dir_state;
    digitalWrite(dir_pin, dir_state);
    flash(2, 100);
  }
  prev_button_state = button_state;  
}

void flash(const int n, const int delay_amt)
{
  for(int i=0; i<n; i++) {
    if(i>0) delay(delay_amt);
    digitalWrite(led, HIGH);
    delay(delay_amt);
    digitalWrite(led, LOW);
  }
  
}

