///////////////////////////////////////////////////////////
//      TODO: Test this new implementation               //
///////////////////////////////////////////////////////////

#include <MIDI.h>
#include <note.h>

MIDI_CREATE_DEFAULT_INSTANCE();

const int buttonPinDownOctave = 10;     // the number of the pushbutton pin
const int buttonPinUpOctave = 11;     // the number of the pushbutton pin

// variables will change:

int buttonStateDownOctave = 0;         // variable for reading the pushbutton status
int buttonStateUpOctave = 0;

int midiStateDownOctave = 0;
int midiStateUpOctave = 0;
int midiOctaveLevel = 0;


void setup()
{
  MIDI.begin(MIDI_CHANNEL_OMNI);
  Notes::C.initializePin(INPUT);
  Notes::D.initializePin(INPUT_PULLUP);
  Notes::E.initializePin(INPUT_PULLUP);
  Notes::F.initializePin(INPUT_PULLUP);
  Notes::G.initializePin(INPUT_PULLUP);
  Notes::A.initializePin(INPUT_PULLUP);
  Notes::B.initializePin(INPUT_PULLUP);
  pinMode(buttonPinDownOctave, INPUT_PULLUP);
  pinMode(buttonPinUpOctave, INPUT_PULLUP);
}

void loop()
{
  Notes::C.checkAndSendNote(midiOctaveLevel);
  Notes::D.checkAndSendNote(midiOctaveLevel);
  Notes::E.checkAndSendNote(midiOctaveLevel);
  Notes::F.checkAndSendNote(midiOctaveLevel);
  Notes::G.checkAndSendNote(midiOctaveLevel);
  Notes::A.checkAndSendNote(midiOctaveLevel);
  Notes::B.checkAndSendNote(midiOctaveLevel);

  buttonStateDownOctave = digitalRead(buttonPinDownOctave);
  buttonStateUpOctave = digitalRead(buttonPinUpOctave);

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
