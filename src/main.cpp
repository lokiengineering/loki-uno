///////////////////////////////////////////////////////////
//  midi_output.ino                                      //
//  Example: MIDI Output                                 //
//  https://github.com/ddiakopoulos/hiduino              //
//  Last Updated: 17 December 2015                       //
///////////////////////////////////////////////////////////

#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

const int buttonPinC = 2;     // the number of the pushbutton pin
const int buttonPinD = 3;     // the number of the pushbutton pin
const int buttonPinE = 4;     // the number of the pushbutton pin
const int buttonPinF = 5;     // the number of the pushbutton pin
const int buttonPinG = 6;     // the number of the pushbutton pin
const int buttonPinA = 7;     // the number of the pushbutton pin
const int buttonPinB = 8;     // the number of the pushbutton pin
const int buttonPinC2 = 9;     // the number of the pushbutton pin

const int buttonPinDownOctave = 10;     // the number of the pushbutton pin
const int buttonPinUpOctave = 11;     // the number of the pushbutton pin

// variables will change:
int buttonStateC = 0;         // variable for reading the pushbutton status
int buttonStateD = 0;         // variable for reading the pushbutton status
int buttonStateE = 0;         // variable for reading the pushbutton status
int buttonStateF = 0;         // variable for reading the pushbutton status
int buttonStateG = 0;         // variable for reading the pushbutton status
int buttonStateA = 0;         // variable for reading the pushbutton status
int buttonStateB = 0;         // variable for reading the pushbutton status
int buttonStateC2 = 0;

int buttonStateDownOctave = 0;         // variable for reading the pushbutton status
int buttonStateUpOctave = 0;

int midiStateC = 0;
int midiStateD = 0;
int midiStateE = 0;
int midiStateF = 0;
int midiStateG = 0;
int midiStateA = 0;
int midiStateB = 0;
int midiStateC2 = 0;

int midiStateDownOctave = 0;
int midiStateUpOctave = 0;
int midiOctaveLevel = 0;

void setup()
{
  MIDI.begin(MIDI_CHANNEL_OMNI);
  pinMode(buttonPinC, INPUT_PULLUP);
  pinMode(buttonPinD, INPUT_PULLUP);
  pinMode(buttonPinE, INPUT_PULLUP);
  pinMode(buttonPinF, INPUT_PULLUP);
  pinMode(buttonPinG, INPUT_PULLUP);
  pinMode(buttonPinA, INPUT_PULLUP);
  pinMode(buttonPinB, INPUT_PULLUP);
  pinMode(buttonPinC2, INPUT_PULLUP);
  pinMode(buttonPinDownOctave, INPUT_PULLUP);
  pinMode(buttonPinUpOctave, INPUT_PULLUP);
}

void loop()
{
  buttonStateC = digitalRead(buttonPinC);
  buttonStateD = digitalRead(buttonPinD);
  buttonStateE = digitalRead(buttonPinE);
  buttonStateF = digitalRead(buttonPinF);
  buttonStateG = digitalRead(buttonPinG);
  buttonStateA = digitalRead(buttonPinA);
  buttonStateB = digitalRead(buttonPinB);
  buttonStateC2 = digitalRead(buttonPinC2);
  buttonStateDownOctave = digitalRead(buttonPinDownOctave);
  buttonStateUpOctave = digitalRead(buttonPinUpOctave);

  if (buttonStateC == HIGH) {
    if(midiStateC == 1) {
      midiStateC = 0;
      MIDI.sendNoteOff(60 + (12 * midiOctaveLevel), 127, 1);
    }
  } else {
    if(midiStateC == 0) {
      midiStateC = 1;
      MIDI.sendNoteOn(60 + (12 * midiOctaveLevel), 127, 1);
    }
  }
  if (buttonStateD == HIGH) {
    if(midiStateD == 1) {
      midiStateD = 0;
      MIDI.sendNoteOff(62 + (12 * midiOctaveLevel), 127, 1);
    }
  } else {
    if(midiStateD == 0) {
      midiStateD = 1;
      MIDI.sendNoteOn(62 + (12 * midiOctaveLevel), 127, 1);
    }
  }
  if (buttonStateE == HIGH) {
    if(midiStateE == 1) {
      midiStateE = 0;
      MIDI.sendNoteOff(64 + (12 * midiOctaveLevel), 127, 1);
    }
  } else {
    if(midiStateE == 0) {
      midiStateE = 1;
      MIDI.sendNoteOn(64 + (12 * midiOctaveLevel), 127, 1);
    }
  }
  if (buttonStateF == HIGH) {
    if(midiStateF == 1) {
      midiStateF = 0;
      MIDI.sendNoteOff(65 + (12 * midiOctaveLevel), 127, 1);
    }
  } else {
    if(midiStateF == 0) {
      midiStateF = 1;
      MIDI.sendNoteOn(65 + (12 * midiOctaveLevel), 127, 1);
    }
  }
  if (buttonStateG == HIGH) {
    if(midiStateG == 1) {
      midiStateG = 0;
      MIDI.sendNoteOff(67 + (12 * midiOctaveLevel), 127, 1);
    }
  } else {
    if(midiStateG == 0) {
      midiStateG = 1;
      MIDI.sendNoteOn(67 + (12 * midiOctaveLevel), 127, 1);
    }
  }
  if (buttonStateA == HIGH) {
    if(midiStateA == 1) {
      midiStateA = 0;
      MIDI.sendNoteOff(69 + (12 * midiOctaveLevel), 127, 1);
    }
  } else {
    if(midiStateA == 0) {
      midiStateA = 1;
      MIDI.sendNoteOn(69 + (12 * midiOctaveLevel), 127, 1);
    }
  }
  if (buttonStateB == HIGH) {
    if(midiStateB == 1) {
      midiStateB = 0;
      MIDI.sendNoteOff(71 + (12 * midiOctaveLevel), 127, 1);
    }
  } else {
    if(midiStateB == 0) {
      midiStateB = 1;
      MIDI.sendNoteOn(71 + (12 * midiOctaveLevel), 127, 1);
    }
  }
  if (buttonStateC2 == HIGH) {
    if(midiStateC2 == 1) {
      midiStateC2 = 0;
      MIDI.sendNoteOff(72 + (12 * midiOctaveLevel), 127, 1);
    }
  } else {
    if(midiStateC2 == 0) {
      midiStateC2 = 1;
      MIDI.sendNoteOn(72 + (12 * midiOctaveLevel), 127, 1);
    }
  }

  if (buttonStateDownOctave == HIGH) {
    if(midiStateDownOctave == 1) {
      midiStateDownOctave = 0;
    }
  } else {
    if(midiStateDownOctave == 0) {
      midiStateDownOctave = 1;
      midiOctaveLevel = midiOctaveLevel - 1;
    }
  }
  if (buttonStateUpOctave == HIGH) {
    if(midiStateUpOctave == 1) {
      midiStateUpOctave = 0;
    }
  } else {
    if(midiStateUpOctave == 0) {
      midiStateUpOctave = 1;
      midiOctaveLevel = midiOctaveLevel + 1;
    }
  }
  delay(50);
}
