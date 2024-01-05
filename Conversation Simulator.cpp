#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <istream>
#include <string>

using namespace std;

class character {
public:
	string name;
	bool angry;
	character(string name, bool angry) {
		this->name = name;
		this->angry = angry;
	}
	character() {}
	string getName() { return this->name; }
	bool getAngry() { return this->angry; }
	void setAngry(bool angry) { this->angry = angry; }
};

bool wordIn(string line, string word) {
	if (line.find(word) != -1)
		return true;
	return false;
}

int arrayOccurence(int num, int list[], int length) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (num == list[i])
			count++;
	}
	return count;
}

void arrayAdd(int num, int list[], int length) {
	for (int i = 0; i < length; i++) {
		if (list[i] == -1) {
			list[i] = num;
			i = length;
		}
	}
}

string identifyInsult(string line) {
	if (wordIn(line, "stupid"))
		return "stupid";
	if (wordIn(line, "dumb"))
		return "dumb";
	if (wordIn(line, "fat"))
		return "fat";
	if (wordIn(line, "old"))
		return "old";
	if (wordIn(line, "ugly"))
		return "ugly";
	return "";
}

string WilsonPhase() {
	string answer = "";
	cout << "You arrive at the high school were you work as a janitor. You see Wilson, your supervisor. \n \t \"Get to work Marlin, you lazy oaf. " <<
		"You need to sweep the floor!\" \n \n What do you say in response?" << endl;
	std::getline(cin, answer);
	if (wordIn(answer, "!")) {
		cout << "Wilson does not like what you say. \n \t \"What?\" he says, \"You spoiled, arrogant brat! Back in my day, we "
			<< " didn't treat young'ins like you with such kindness!\"\nHe growls at you, but lets you continue with"
			<< " your day." << endl;
		return "angry";
	}
	else if (identifyInsult(answer) != "") {
		cout << "\t \" Did you just call me " << identifyInsult(answer) << "? Get out of my sight!\", he shouts at you as you run "
			<< "away. \nYou realize that you probably shouldn't anger people unnecessarily.";
		return "angry";
	}
	else if (wordIn(answer, "?")) {
		cout << "Wilson responds. \n \t \"You aren't paid to ask questions! In fact, you're not paid at all! Quit yer yapping"
			<< " and get back to work!\"" << endl;
	}
	else {
		cout << "Wilson smiles. \n \t \"I agree,\" he says. You suspect this odd response as a consequence of Wilson's poor hearing" << endl;
	}
	return "normal";
}

string JamesPhase() {
	string answer = "";
	cout << "\nAfter diligantly sweeping the floor, you head over to James's room. He's a teacher at the school \nYou open the door. \n \t" <<
		"\"Marlin, you're late!\", James says as you enter the room. \"Go to the cafeteria and get me a bagel.\" \nWhat do you say to him?" << endl;
	std::getline(cin, answer);
	if (wordIn(answer, "!")) {
		cout << "\"I'm a teacher,\" he says, \"You can't address me like that. Get going or I'll have you working on weekends!\""
			<< " You walk away, dejected. \nYou arrive at the cafeteria and get in the line." << endl;
		return "angry";
	}
	else if (identifyInsult(answer) != "") {
		cout << "\"For the last time Marlin, I am not " << identifyInsult(answer) << "!\" James yells. You turn and run to the cafeteria.";
		return "angry";
	}
	else if (wordIn(answer, "?")) {
		cout << "\n \t \"Marlin, stop asking questions and do your job,\" he says. You're a bit disappointed." <<
			"\nYou head on over to the cafeteria." << endl;
	}
	else {
		cout << "\n \t \"Whatever, Marlin,\" he says. You walk to the cafeteria to do your job." << endl;
	}
	return "normal";
}

string WillPhase() {
	string answer = "";
	cout << "\nSitting on a bench is everyone's least favourite teacher Lance. He looks up and smiles. \n \t \"Oh, hey Marlin,\" he says. " <<
		"\nWhat do you say to him?" << endl;
	std::getline(cin, answer);
	cout << "Before he can respond, your good friend Will walks in." << endl;
	if (wordIn(answer, "!")) {
		cout << "\"Hah, good one Marlin!\" he says. He punches Lance in the arm and walks away. You feel good knowing that you just " <<
			"made Will's day." << endl;
		return "normal";
	}
	else if (identifyInsult(answer) != "") {
		cout << "Will bursts out laughing. \n \t \"Amazing! That's what you get for changing the curriculum!\" he says to Lance, who runs out " <<
			"\nof the room, ashamed.";
		return "normal";
	}
	else if (wordIn(answer, "?")) {
		cout << "\n \t \"Marlin, don't talk to this wimp,\" he says. He walks away. You feel bad for disapointing Will." << endl;
		return "angry";
	}
	else {
		cout << "\n \t \"Marlin, how can you talk to this man?\" he says. \nYou feel ashamed of fraternizing "
			<< "with the school's most hated teacher. Will storms off." << endl;
		return "angry";
	}
	return "normal";
}


void trialPhase(bool angry1, bool angry2, bool angry3) {
	int angryCounter = 0;
	cout << "\n Hours later, you are ordered to see Principal Luthor at once. You arrive at his office. \n \t \"You are summoned because of numerous " <<
		"complaints from the people of this school. Wilson, how has this man wronged you?\" Luthor asks." << endl;
	if (angry1) {
		angryCounter++;
		cout << "\n \t \"This insolent boy has disrespected the very man who raised him!\"" <<
			" Wilson replies." << endl;
	}
	else
		cout << "\n \t \"Actually, this boy has done nothing wrong in my eyes,\" Wilson says." << endl;

	cout << "\n \t \"Of course. James, my man, how has this man wronged you?\" Luthor asks." << endl;

	if (angry2) {
		angryCounter++;
		cout << "\n \t \"This stupid, pathetic excuse for a janitor has insulted my very name. Get rid of him,\" James replies." << endl;
	}
	else
		cout << "\n \t \"Marlin, for once, has actually done his job for once. He hasn't wronged me in any way,\" James replies." << endl;

	cout << "\n \t \"Hmmm. Will, how has this man wronged you?\" Luthor asks." << endl;

	if (angry3) {
		angryCounter++;
		cout << "\n \t \"Marlin, my former friend, has betrayed me and everyone else in this school. I caught him talking to Lance, of all people,\""
			<< "Will replies. There is a collective gasp throughout the room. Someone shouts \"He couldn't!\"." << endl;
	}
	else
		cout << "\n \t \"He hasn't. Marlin is a good man. He deserves a raise,\" Will replies." << endl;

	if (angryCounter >= 2) {
		cout << "\n \t \"Hmmm, it seems to me that you are not fulfillng your duties as a janitor.\" Luthor says." << endl;
		cout << "\n \t \"You are fired. Perhaps you should be more polite. THE END" << endl;
	}
	else {
		cout << "\n \t \"Well, it seems to me that you are doing your job well, Marlin,\" Luthor says." << endl;
		cout << "\n \t \"Due to the loyalty of your friends, you get a raise. Well done! THE END" << endl;
	}
}

int main() {
	string answer = "";
	bool WilsonAngry = false;
	bool JamesAngry = false;
	bool WillAngry = false;
	cout << "Welcome to Conversation Simulator!\n" << endl;
	// characterPhase prints the scenario and returns if the character gets mad from your interaction
	if (WilsonPhase() == "angry")
		WilsonAngry = true;
	if (JamesPhase() == "angry")
		JamesAngry = true;
	if (WillPhase() == "angry")
		WillAngry = true;
	trialPhase(WilsonAngry, JamesAngry, WillAngry);
	return 0;
}