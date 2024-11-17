#include<iostream>
#include<cstdlib>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

struct stRoundInfo {

	short RoundNumber = 0;
	enGameChoice Player1Choice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName;

};
struct stGameResults {

	short GameRounds = 0;
	short Player1WinTimes = 0;
	short Computer2WinTimes = 0;
	short DrawTimes = 0;
	enWinner GameWinner;
	string WinnerName = "";

};
int RandomNumber(int From, int To) {
	//Function to generate a random number 
	int randNum = rand() % (To - From + 1) + From;

	return randNum;
}
string WinnerName(enWinner Winner) {

	string arrWinnerName[3] = { "Player1","Computer","No Winner" };

	return arrWinnerName[Winner - 1];

}
enWinner WhoWonTheRound(stRoundInfo RoundInfo) {

	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice) {
		return enWinner::Draw;
	}

	switch (RoundInfo.Player1Choice) {
	case enGameChoice::Stone:
		if (RoundInfo.ComputerChoice == enGameChoice::Paper) {
			return enWinner::Computer;
		}
		break;
	case enGameChoice::Paper:
		if (RoundInfo.ComputerChoice == enGameChoice::Scissors) {
			return enWinner::Computer;
		}
		break;
	case enGameChoice::Scissors:
		if (RoundInfo.ComputerChoice == enGameChoice::Stone) {
			return enWinner::Computer;
		}
		break;
	}

	return enWinner::Player1;
}
string ChoiceName(enGameChoice Choice) {

	string arrGameChoices[3] = { "Stone","Paper","Scissors" };

	return arrGameChoices[Choice - 1];

}

void SetWinnerScreenColor(enWinner Winner) {

	switch (Winner) {
	case enWinner::Player1:
		system("color 2F"); //turn screen to Green
		break;
	case enWinner::Computer:
		system("color 4F"); //turn screen to Red        
		cout << "\a";
		break;
	default:
		system("color 6F"); //turn screen to Yellow
		break;
	}
}
void PrintRoundResults(stRoundInfo RoundInfo) {

	cout << "\n____________Round [" << RoundInfo.RoundNumber << "] ____________\n\n";
	cout << "Player1  Choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;
	cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner   : [" << RoundInfo.WinnerName << "] \n";
	cout << "__________________________________\n" << endl;

	SetWinnerScreenColor(RoundInfo.Winner);

}
enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes) {

	if (Player1WinTimes > ComputerWinTimes)
		return enWinner::Player1;

	else if (ComputerWinTimes > Player1WinTimes)
		return enWinner::Computer;

	else
		return enWinner::Draw;
}
stGameResults FillGameResults(int GameRounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes) {

	stGameResults GameResults;

	GameResults.GameRounds = GameRounds;
	GameResults.Player1WinTimes = Player1WinTimes;
	GameResults.Computer2WinTimes = ComputerWinTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);
	GameResults.WinnerName = WinnerName(GameResults.GameWinner);

	return GameResults;

}
enGameChoice ReadPlayer1Choice() {

	short Choice = 1;

	do {

		cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
		cin >> Choice;
	}

	while (Choice < 1 || Choice >3);

	return (enGameChoice)Choice;

}

