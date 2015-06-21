#include "Arduino.h"

class AsciiToString {
public:
	String message;
	String word;

	AsciiToString();
	
	void getString(int ascii);
	void clear();

};