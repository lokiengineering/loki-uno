#include <MIDI.h>

class Note {
    int pin, pinState, midiState, midiNote, cc, AnalogValue, lastAnalogValue, midiCC;
    char name, type;
  public:
    void setNote (char, char, int, int, int);
    void initializePin (int);
    void checkAndSendNote (int);
    // int area() {return width*height;}
};

void Note::setNote (char type, char name, int midiNote, int pin, int midiCC) {
  name = name;
  pin = pin;
  midiCC = midiCC;
  type = type;
  midiNote = midiNote;
  pinState = 0;
  midiState = 0;
  cc = 0;
  AnalogValue = 0;
  lastAnalogValue = 0;
}

void Note::initializePin (int mode) {
  pinMode(pin, mode);
}

void Note::checkAndSendNote (int midiOctaveLevel) {
  if (type == "digital") {
    pinState = digitalRead(pin);
    if (pinState == HIGH) {
      if(midiState == 1) {
        midiState = 0;
        MIDI.sendNoteOff(65 + (12 * midiOctaveLevel), 127, 1);
      }
    } else {
      if(midiState == 0) {
        midiState = 1;
        MIDI.sendNoteOn(65 + (12 * midiOctaveLevel), 127, 1);
      }
    }
  } else {
    if (cc > 0) {
      if (lastAnalogValue != cc) {
        MIDI.sendControlChange(midiCC, cc, 1);
        // update lastAnalogValue variable
        lastAnalogValue = cc;
      }  //  endif
      if(midiState == 0) {
        midiState = 1;
        MIDI.sendNoteOn(60 + (12 * midiOctaveLevel), 127, 1);
      }
    } else {
      if(midiState == 1) {
        midiState = 0;
        MIDI.sendNoteOff(60 + (12 * midiOctaveLevel), 127, 1);
      }
    }
  }
}

namespace Notes {       // representation
  Note A, B, C, D, E, F, G, As, Cs, Ds, Fs, Gs;
  A.setNote ("digital", "A", 69, 7);
  B.setNote ("digital", "B", 71, 8);
  C.setNote ("analog", "C", 60, 2, 12);
  D.setNote ("digital", "D", 62, 3);
  E.setNote ("digital", "E", 64, 4);
  F.setNote ("digital", "F", 65, 5);
  G.setNote ("digital", "G", 67, 6);
}
