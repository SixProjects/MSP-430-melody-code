/*
  Melody
 
 Plays a melody 
 
 circuit:
 * 8-ohm speaker on digital pin 8
 
 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe 

This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/Tone
 
 */
 #include "pitches.h"

// notes in the melody:
int melody[] = {
   NOTE_D5, NOTE_D5, NOTE_C5, NOTE_D5, 0, NOTE_A4, 
   0, NOTE_A4, NOTE_D4, NOTE_G5, NOTE_G4, NOTE_D5, 0,
   NOTE_D5, NOTE_D5, NOTE_C5, NOTE_D5, 0, NOTE_A4, 
   0, NOTE_A4, NOTE_D4, NOTE_G5, NOTE_G4, NOTE_D5, 0,
   NOTE_D5, 0, NOTE_D5, NOTE_D5,    //bridge
   NOTE_FS5, 0, NOTE_FS5, NOTE_FS5,
   NOTE_A4, 0, NOTE_A4, NOTE_A4,
   NOTE_FS6, NOTE_E6, NOTE_D6, 0,
   NOTE_D5, NOTE_D5, NOTE_C5, NOTE_D5, 0, NOTE_A4, 
   0, NOTE_A4, NOTE_D4, NOTE_G5, NOTE_G4, NOTE_D5, 0, 
   NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_D5,     //Bridge2
   NOTE_D5, NOTE_D5, NOTE_D5, NOTE_CS5,  
   NOTE_CS5, NOTE_CS5, NOTE_CS5, NOTE_B5,
   NOTE_B4, NOTE_B4, NOTE_B4, 0, }; // end with zero
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  6, 6, 6, 6, 6, 6, 
  6, 6, 6, 6, 6, 6, 2,
  6, 6, 6, 6, 6, 6, 
  6, 6, 6, 6, 6, 6, 2,
  4, 12, 6, 6,
  4, 12, 6, 6,
  4, 12, 6, 6,
  6, 6, 4, 2.7,
  6, 6, 6, 6, 6, 6, 
  6, 6, 6, 6, 6, 6, 2,
  6, 6, 6, 6, 6, 
  6, 6, 6, 6, 
  6, 6, 6, 6, 
  6, 6, 2, 16, 
  };

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 74; thisNote++) {     //counts notes

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(P1_2, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.60;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(P1_2);
  }
}

void loop() {
  // no need to repeat the melody.
}
