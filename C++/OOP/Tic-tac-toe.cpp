#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
char square[9] = {'0','1','2','3','4','5','6','7','8'};
// function to check hortizontal,vertically and diagonal win
int checkwin()
{
		if (square[0] == square [1]  && square[1] == square[2] )
		{	if ( square [0] == 'X' )			
			return 1;
			else
			return 2; 
		}		
		else
		if (square[3] == square [4]  && square[4] == square[5] )
			{	if ( square [3] == 'X' )			
			return 1;
			else
			return 2; 
		}
		else
		if (square[6] == square [7]  && square[7] == square[8] )
			{	if ( square [6] == 'X' )			
			return 1;
			else
			return 2; 
		}
		else
		if (square[0] == square [3]  && square[3] == square[6] )
			{	if ( square [0] == 'X' )			
			return 1;
			else
			return 2; 
		}
		else
		if (square[1] == square [4]  && square[4] == square[7] )
			{	if ( square [1] == 'X' )			
			return 1;
			else
			return 2; 
		}
		else
		if (square[2] == square [5]  && square[5] == square[8] )
			{	if ( square [2] == 'X' )			
			return 1;
			else
			return 2; 
		}
		else
		if (square[0] == square [4]  && square[4] == square[8] )
			{	if ( square [0] == 'X' )			
			return 1;
			else
			return 2; 
		}
		else
		if (square[2] == square [4]  && square[4] == square[6] )
			{	if ( square [2] == 'X' )			
			return 1;
			else
			return 2; 
		}
		else
		if (square[0] == square [3]  && square[3] == square[6] )
			{	if ( square [0] == 'X' )			
			return 1;
			else
			return 2; 
		}
		else 
		return 0;
}
// function to mark the square box by either 'x' or 'o' as per user input
void mark(int player, int box)
{
	if (player == 1 )
	{

		square[box] = 'X';
	}
	else{
		square[box] = 'O';
    }
}
//function to show the square board for playing
void display()
{
	cout << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[0] << "  |  " << square[1] << "  |  " << square[2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[3] << "  |  " << square[4] << "  |  " << square[5] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[6] << "  |  " << square[7] << "  |  " << square[8] << endl;
	cout << "     |     |     " << endl << endl;
}
int main()
{		
		ofstream fout; 
		int player1 = 1, player2 =2 ;
		int box, result = 0, flag = 0;
        string p1,p2,line;
        cout<<"Player 1 Name : ";
        cin>>p1;
        cout<<"Player 2 Name : ";
        cin>>p2;
        cout<<"\n============TIC TAC TOE GAME==============="<<endl;
        cout << endl;
	 	display();
		for(int i=1;i<5;i++){
		cout<< "\n Player " << player1 <<" Enter the Box - ";
		cin>> box;
		mark( player1, box);
		display();
		result =checkwin();	
		if (result == 1 )
		{	cout<<"\n Congratualtions! player " << p1 << " has Won ";
			line=p1;
			while (fout) { 
				fout.open("Winner.txt",ios::app);
				if (line == "-1") 
            		break; 
				fout << line << endl;
		}
			fout.close();
			flag = 1;		
			break;
		}
		else
		if (result == 2 )
		{	cout<<"\n Congratualtions! player " << p2 << " has Won ";
			line=p2;
			while (fout) { 
			fout.open("Winner.txt",ios::app);
			if (line == "-1") 
            		break; 
			fout << line<< endl;
			}
			fout.close();
			flag = 1;	
			break;
		}
		cout<< "\n Player " <<player2 <<" Enter the Box - ";
		cin>> box;
		mark ( player2, box);
		display();
		
		result =checkwin();	
		if (result == 1 )
		{	cout<<"\n Congratualtions! player "<< p1<<" has Won ";
			line=p1;
			while (fout) { 
			fout.open("Winner.txt",ios::app);
			if (line == "-1") 
            	break; 
			fout << line << endl;
			}
			fout.close();
			flag = 1;
			break;
		}
		else
		if (result == 2 )
		{	cout<<"\n Congratualtions! player " << p2 << " has Won ";
			line=p2;
			while (fout) { 
			fout.open("Winner.txt",ios::app);
			if (line == "-1") 
           		 break; 
			fout << line << endl;
			}
			fout.close();
			flag = 1;
            break;
		}
}
		if (flag == 0 )
		cout<<" \n Sorry, The game is a draw ";
		char ch;
		cout<<"CHeck the winners list?(Y/n) ";
		cin>>ch;
		if(ch == 'y' ||ch == 'Y')
		{
			ifstream fin; 
			fin.open("Winner.txt",ios::in); 
			while (getline(fin, line)) { 
			cout << line << endl;
			}
			fin.close();
		}
		else
			exit(0);
	return 0;
}