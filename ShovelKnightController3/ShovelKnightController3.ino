#include <Bounce.h>

Bounce* buttons[24];

void setup() {
  Keyboard.begin();
  for (int n=0; n<24; ++n) {
    buttons[n] = new Bounce(n, 10);
    pinMode(n, INPUT_PULLUP);
  }
}

int keymap[24] = {
  KEY_UP_ARROW,     // 0
  KEY_DOWN_ARROW,   // 1
  KEY_LEFT_ARROW,   // 2
  KEY_RIGHT_ARROW,  // 3
  KEY_RETURN,       // 4
  ' ',              // 5
  'a',              // 6
  'b',              // 7
  'c',              // 8
  'd',              // 9
  'e',              // 10
  'f',              // 11
  'g',              // 12
  'h',              // 13
  'i',              // 14
  'j',              // 15
  'k',              // 16
  'l',              // 17
  'm',              // 18
  'n',              // 19
  'o',              // 20
  'p',              // 21
  'q',              // 22
  KEY_ESC           // 23  
};

void loop() {
  for (int n=0; n<24; ++n) {
    buttons[n]->update();
    if (buttons[n]->fallingEdge()) {
      Keyboard.press(keymap[n]);
    }
    if (buttons[n]->risingEdge()) {
      Keyboard.release(keymap[n]);
    }
  }
}

