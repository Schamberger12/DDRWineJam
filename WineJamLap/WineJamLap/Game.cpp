class DDRGame
{
private:
	
	Metronome metro;
	int input;
	bool songRunning;
	milliseconds gameLength;

public:

	DDRGame() 
	{
		
	}

	~DDRGame()
	{

	}

	void startGame(milliseconds realBPM)
	{
		time_point<system_clock> start, end;
		start = system_clock::now();

		metro.setBPM(realBPM);

	}

	void gameLoop(milliseconds gameLength, milliseconds realBPM)
	{
		//will hold both the metronome loop as well as the DDR loop
	}
};