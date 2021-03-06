// Name Angel Gonzalez
// Date 12/16/15
// CSS-1 Fa15 Final Exam Prog 2
#include <iostream>
#include <fstream>
using namespace std;

const int R = 30;
const int C = 50;
 
void fillArray(ifstream& A_in, string S[][C]);
void checkElfs(string S[][C], ofstream& A_out);
int main()
{
	ifstream finn;

	ofstream jake;

	finn.open("northpole.txt");

	jake.open("status.txt");

	string map[R][C];

	fillArray(finn, map);	

	checkElfs(map, jake);

	finn.close();

	jake.close();

	return 0;
}

// ********************************
void fillArray(ifstream& A_in, string S[][C])
{
	string temp;
	for (int i = 0; i < R - 1; i++)
	{
		for (int ix = 0; ix < C - 1; ix++)
		{
			A_in >> temp;
			S[i][ix] = temp;
		}
	}
				
	return;
}//end fillArray()
// ********************************
void checkElfs(string S[][C], ofstream& A_out)
{
	int danger;

	A_out << "Name : Angel Gonzalez" << endl;

	for (int i = 1; i < R - 2; i++)
	{
		for (int ix = 1; ix < C - 2; ix++)
		{
			danger = 0;
			if (S[i][ix] == "@")
			{
				if (S[i + 1][ix] == "!")
				{
					danger++;
				}
				if (S[i - 1][ix] == "!")
				{
					danger++;
				}
				if (S[i][ix + 1] == "!")
				{
					danger++;
				}
				if (S[i][ix - 1] == "!")
				{
					danger++;
				}
				if (danger == 3)
				{
					A_out << "elf[" << i << "][" << ix << "]: Run!" << endl;
				}
				else if (danger == 4)
				{
					A_out << "elf[" << i << "][" << ix << "]: Munch!" << endl;
				}
			}
			
		}
	}
	A_out.close();
	return;
}//end checkElfs()




 
