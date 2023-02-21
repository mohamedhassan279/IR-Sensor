#include <IRremote.h>

int LED_pIN = 9;
int RECV_PIN = 11;
int led_state = 1;
int blink_delay = 0;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(LED_pIN,OUTPUT);//Pin For Led
  digitalWrite(LED_pIN, led_state);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value,DEC);
    if(results.value==3772811383)
    {
      Serial.println("0 Pressed");
      blink_delay = 0;
    }
    if(results.value==3772784863)
    {
      Serial.println("1 Pressed");
      blink_delay = 100;
    }
    if(results.value==3772817503)
    {
      Serial.println("2 Pressed");
      blink_delay = 200;
    }
    if(results.value==3772801183)
    {
      Serial.println("3 Pressed");
      blink_delay = 300;
    }
    if(results.value==3772780783)
    {
      Serial.println("4 Pressed");
      blink_delay = 400;
    }
    if(results.value==3772813423)
    {
      Serial.println("5 Pressed");
      blink_delay = 500;
    }
    if(results.value==3772797103)
    {
      Serial.println("6 Pressed");
      blink_delay = 600;
    }
    if(results.value==3772788943)
    {
      Serial.println("7 Pressed");
      blink_delay = 700;
    }
    if(results.value==3772821583)
    {
      Serial.println("8 Pressed");
      blink_delay = 800;
    }
    if(results.value==3772805263)
    {
      Serial.println("9 Pressed");
      blink_delay = 900;
    }
    irrecv.resume();
  }
  // toggle the state of the led
  led_state = !led_state;
  digitalWrite(LED_pIN, led_state);
  delay(blink_delay);
}
