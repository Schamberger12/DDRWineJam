#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>

using namespace std;
using namespace std::chrono;




class Metronome
{
	//this class will essentially 
	//be the 'rhythm' section of the game.
	//break down by bpm, then, as a test, will emit a click
	//upon every bpm requested.

	//same as DDR, will incorporate a perfect, good, and bad rating
	//upon each beat

	//Can be set to either Game Mode or Metronome Mode
	//Game mode will take in from a pre-recorded list of button prompts

private:

	milliseconds bpm;				//will always set to 1 second(divisor) by default.
	int realBPM;					//way to keep track of what the actual bpm will be
	//some sound!								//keeping in milliseconds to allow for 
	

public:
	Metronome() 
	{
		milliseconds bpm(1000);			//setting the initial bpm to 1000 ms, or 1 beat per second

		this->bpm = bpm;
		
		int realBPM = 60;				//real bpm will be 60 bpm or 1 beat per minute

		this->realBPM = realBPM;

	}
	
	~Metronome() {}

	void changeBPM(int realBPM) {

	}
								
	
	int returnRealBPM()
	{
		return this->realBPM;				//class will always keep a copy of the value for the real-life BPM stored
	}

	milliseconds returnSysBPM()
	{
		return this->bpm;					//to allow for getting the system bpm
	}

	void clickSound()
	{
		cout << '\a';						//placeholder for metronome click
	}

	void setBPM(int realBPM)
	{
		this->realBPM = realBPM;			//wooo
		milliseconds bpm(60000/realBPM);	//awkward assignment, but works.
		this->bpm = bpm;

			
	}

	//creates a class method for the loop
	void metroLoop() {

		int realBPM;
		
		cout << "Enter the desired BPM" << endl;
		cin >> realBPM;

		this->setBPM(realBPM);

		bool run = true;

		


		while (run == true) {

			this_thread::sleep_until(steady_clock::now() + this->bpm);	//using chrono's syntax, tells system to set a time point at the exact moment in time
																		//Once it has been __ milliseconds, the metronome will beep
			this->clickSound();

			if (_kbhit()) {				//still using conio.h library
				int c = _getch();		//kbhit() is a check to see if the keyboard was used 
										//then, if khbit() returns true, if the key pressed happens to be a c or a q
				if (c == 'q')			//one of the commands are used
					run = false;
				if (c == 'c') {
					cout << "What would you like to change the BPM to?" << endl;
					cin >> realBPM;
					this->setBPM(realBPM);
				}


			}
		}


	}
};

int main()
{
	Metronome metro;

	metro.metroLoop();


}