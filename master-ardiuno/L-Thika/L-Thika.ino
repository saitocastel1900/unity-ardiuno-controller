//Arduino本体付属のLEDを点滅させる

const int LED_PIN=13;

void setup() {
    pinMode( LED_PIN, OUTPUT );
}
void loop() {
    digitalWrite( LED_PIN, HIGH );
    delay(100);
    digitalWrite( LED_PIN, LOW );
    delay(500);
}
