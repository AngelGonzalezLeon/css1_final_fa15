// Name Angel Gonzalez
// Date 12/16/15
// CSS-1 Fa15 Final Exam Prog 1
#include <fstream>
#include <iostream>
using namespace std;

void checkPass(string ary[], int length, ifstream& A_in, ofstream& A_out);

void checkWork(string ary[], int length);

int main()
{
	ifstream finn; //takes input from file

	ofstream jake; //outputs to a file

	finn.open("passwords.txt");

	jake.open("good_words.txt");
	
	jake << " Name : Angel Gonzalez" << endl;	

	const int SIZE = 6;

	
	string possible[SIZE] = {"zymogenic","aboral","Santa","password1","Password!", "ambystomidae"};

	checkPass(possible, SIZE, finn, jake);
	
	finn.close();
	jake.close();

	checkWork(possible, SIZE);

	return 0;
}

//**************************************************************************
void checkPass(string ary[], int length, ifstream& A_in, ofstream& A_out)
{
	int similar = 0; //checks if the arrray has a matching password, if so it'll change to 1
	string temp;
	while (A_in >> temp)
	{
		similar = 0;
		for (int i = 0; i < length - 1; i++)
		{
			if (ary[i] == temp)
			{
				similar = 1;
			}
		}
		if (similar == 0)
		{
			A_out << temp << endl;
		}

	}	
	return;
}
//end checkPass()
//**************************************************************************
void checkWork(string ary[], int length)
{
	ifstream A_in;

	A_in.open("good_words.txt");
	
	int similar = 0;
	string temp;
	while (A_in >> temp)
	{
		for (int i = 0; i < length - 1; i++)
		{
			if (ary[i] == temp)
			{
				similar = 1;
			}
		}

	}	
	if (similar == 1)
	{
		cout << "Function still has similar passowords" << endl;
	}
	A_in.close();

	return;

}//end checkWork()
 
