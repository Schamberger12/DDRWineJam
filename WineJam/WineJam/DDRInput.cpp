#include "Functions.h"
#include <iostream>
#include <conio.h>

using namespace std;


int DDRInput()
{
	int c = 0;
	while (1)
	{

		c = 0;					//resets c to 0 every time

		switch (c = _getch()) {	//switch statement takes in _getch()
		case 224:				//_getch() takes in 224/0 as a buffer before
			continue;			//the next key input. 224 for arrow keys, 0 for 
		case 0:					//numpad/number input
			continue;			//making a case for both 224 and 0 bypasses that
		case KEY_UP:			//buffer. Otherwise it outputs null [output]
			cout << "UP" << endl;
			c = 0;
			break;
		case KEY_DOWN:
			cout << "DOWN" << endl;
			c = 0;
			break;
		case KEY_RIGHT:
			cout << "Right" << endl;
			c = 0;
			break;
		case KEY_LEFT:
			cout << "Left" << endl;
			c = 0;
			break;
		default:
			cout << "null " << endl;

		}
	}
	return 0;
}