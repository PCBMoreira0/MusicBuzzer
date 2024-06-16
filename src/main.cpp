#include <Arduino.h>

#define BPM 120

note_t notes[] = {
	NOTE_G,
	NOTE_G,
	NOTE_C,
	NOTE_E,
	NOTE_Eb,
	NOTE_G,
	NOTE_B,
	NOTE_B,
	NOTE_A,
	NOTE_C,
	NOTE_E,
	NOTE_A,
	NOTE_G,
	NOTE_C,
	NOTE_D,
	NOTE_E,
	NOTE_A,
	NOTE_C,
	NOTE_F,
	NOTE_A,
	NOTE_Gs,
	NOTE_C,
	NOTE_D,
	NOTE_F,
	NOTE_E,
	NOTE_G,
	NOTE_C,
	NOTE_E,
	NOTE_D,
	NOTE_A,
	NOTE_B,
	NOTE_D
};

int8_t rithmFigures[] = {
	1, 
	1, 
	1, 
	1, 
 	1,
	1, 
	1, 
	1, 
	1, 
	1, 
	1, 
	1, 
	1, 
	1, 
	1, 
	1, 
	1, 
	1, 
	1, 
	1, 
 	1,
	1, 
	1, 
	1, 
	1, 
	1, 
	1, 
	1, 
	1, 
	1, 
	1, 
	1
};

uint8_t octaves[] = {
	5,
	4,
	5,
	5,
	5,
	4,
	5,
	4,
	5,
	5,
	5,
	5,
	5,
	5,
	5,
	5,
	5,
	5,
	5,
	5,
	5,
	5,
	5,
	5,
	5,
	4,
	5,
	5,
	5,
	4,
	4,
	5
};

uint32_t BPMtoBPS(u_int32_t bpm){
	return bpm / 60;
}

void playNote(note_t note, int32_t duration, uint8_t octave){
	if(duration > 0){
		ledcWriteNote(0, note, octave);
	}

	int dura = 1000000 / abs(duration) / BPMtoBPS(BPM);
	delayMicroseconds(0.7 * dura);
	ledcWriteTone(0, 0);
	delayMicroseconds(0.3 * dura);
}

void setup(){
	ledcAttachPin(27, 0);
}

void loop(){
	for(int i = 0; i < 32; i++){
		playNote(notes[i], rithmFigures[i], octaves[i]);
	}

	delay(2000);

}