//SWITCH CASE

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <fstream>

using namespace std;

const int MAX_ROW=40;
const int MAX_COL=80;

void displayMenu(void);
void setZeroArray(char currentArray[MAX_ROW][MAX_COL], char tempArray[MAX_ROW][MAX_COL]);
void setInitialPatternArray(char currentArray[MAX_ROW][MAX_COL], char tempArray[MAX_ROW][MAX_COL]);
void copyArray(char currentArray[MAX_ROW][MAX_COL], char tempArray[MAX_ROW][MAX_COL]);
void displayArray(char currentArray[MAX_ROW][MAX_COL], char tempArray[MAX_ROW][MAX_COL]);
void setNextGenArray( char currentArry[MAX_ROW][MAX_COL], char tempArray[MAX_ROW][MAX_COL]);
void loadPatternArray( char currentArray[MAX_ROW][MAX_COL], char tempArray[MAX_ROW][MAX_COL]);
void customPatternArray( char currentArray[MAX_ROW][MAX_COL], char tempArray[MAX_ROW][MAX_COL]);
void arrowPatternArray (string arrowFile, char currentArray[MAX_ROW][MAX_COL], char tempArray[MAX_ROW][MAX_COL]);
void pyeongPatternArray (string pyeongFile, char currentArray[MAX_ROW][MAX_COL], char tempArray[MAX_ROW][MAX_COL]);
void changPatternArray (string changFile, char currentArray[MAX_ROW][MAX_COL], char tempArray[MAX_ROW][MAX_COL]);


int main ()
{
    char currentArray[MAX_ROW][MAX_COL];
    char tempArray[MAX_ROW][MAX_COL];
    char dead=',';
    char live='O';
    char choice;
    bool repeat;

    system("cls");
    displayMenu();
    setZeroArray(currentArray, tempArray);
    copyArray(currentArray, tempArray);
    displayArray(currentArray, tempArray);
    cout << ">>";

    do
	{
        if (kbhit())
        choice=getch();
        switch (choice)
        {
            case 'p':
            case 'P':
            {
                system("cls");
                displayMenu();
                setNextGenArray(currentArray, tempArray);
                copyArray(currentArray, tempArray);
                displayArray(currentArray, tempArray);
                Sleep(1000);
                continue;
            }
            case 'i':
            case 'I':
            {
                system("cls");
                displayMenu();
                setZeroArray(currentArray, tempArray);
                setInitialPatternArray(currentArray, tempArray);
                copyArray(currentArray, tempArray);
                displayArray(currentArray, tempArray);
                choice=0;
                continue;
            }
            case 'q':
            case 'Q':
            {
                repeat=false;
                break;
            }
            case 's':
            case 'S':
            {
                choice=0;
                continue;
            }
            case 'c':
            case 'C':
            {
                system ("cls");
                displayMenu();
                setZeroArray(currentArray, tempArray);
                copyArray(currentArray, tempArray);
                displayArray(currentArray, tempArray);
                choice=0;
                continue;
            }
            case 'l':
            case 'L':
            {
                setZeroArray(currentArray, tempArray);
                loadPatternArray(currentArray, tempArray);
                system("cls");
                displayMenu();
                copyArray(currentArray, tempArray);
                displayArray(currentArray, tempArray);
                choice=0;
                continue;
            }
            case 't':
            case 'T':
            {
                setZeroArray(currentArray, tempArray);
                customPatternArray(currentArray, tempArray);
                system("cls");
                displayMenu();
                copyArray(currentArray, tempArray);
                displayArray(currentArray, tempArray);
                choice=0;
                continue;
            }
            case 'a':
            case 'A':
            {
                int row;
                int col;
                string newFileName;
                ofstream out_data;
                cout << "Please enter the name of your new file." << endl;
                getline(cin, newFileName);
                out_data.open (newFileName.c_str());
                for (row=0; row<MAX_ROW; row++)
                {
                    for (col=0; col<MAX_COL; col++)
                    {
                        out_data << currentArray[row][col];
                    }
                }
                out_data.close();
                choice=0;
                continue;
            }
            case 'x':
            case 'X':
            {
                string arrowFile="arrow.txt";
                system("cls");
                setZeroArray(currentArray, tempArray);
                arrowPatternArray(arrowFile, currentArray, tempArray);
                displayMenu();
                copyArray(currentArray, tempArray);
                displayArray(currentArray, tempArray);
                choice=0;
                continue;
            }
            case 'y':
            case 'Y':
            {
                string pyeongFile="pyeong.txt";
                system("cls");
                setZeroArray(currentArray, tempArray);
                pyeongPatternArray(pyeongFile, currentArray, tempArray);
                displayMenu();
                copyArray(currentArray, tempArray);
                displayArray(currentArray, tempArray);
                choice=0;
                continue;
            }
            case 'z':
            case 'Z':
            {
                string changFile="chang.txt";
                system("cls");
                setZeroArray(currentArray, tempArray);
                changPatternArray(changFile, currentArray, tempArray);
                displayMenu();
                copyArray(currentArray, tempArray);
                displayArray(currentArray, tempArray);
                choice=0;
                continue;
            }
        }
	}while (choice != 'q');
    return 0;
}

void displayMenu(void)
{
    cout << "[Initial] - Press 'I' to load initial pattern" << '\t'<< '\t';
    cout << "[Play] - Press 'P' to play the game" << endl;
    cout << "[Stop] - Press 'S' to stop the game" << '\t'<< '\t'<< '\t';
    cout << "[Clear] - Press 'C' to reset display" << endl;
    cout << "[Quit] - Press 'Q' to exit the program" << '\t'<< '\t'<< '\t';
    cout << "[Load] - Press 'L' to load a pattern" << endl;
    cout << "[Custom] - Press 'T' to create custom pattern" <<'\t'<< '\t';
    cout << "[Save] - Press'A' to save current array" << endl;
    cout << "[Arrow] - Press 'X' to load arrow pattern" << '\t'<< '\t';
    cout << "[Pyeong] - Press 'Y' to load pyeong pattern"<<endl;
    cout << "[Chang] - Press 'Z' to load chang pattern" << endl << endl;
}

void setZeroArray(char currentArray[MAX_ROW][MAX_COL], char tempArray[MAX_ROW][MAX_COL])
{
    for (int row=0; row<MAX_ROW; row++)
    {
        for (int column=0; column<MAX_COL; column++)
        {
            tempArray[row][column]=44;
        }
    }
}

void setInitialPatternArray(char currentArray[MAX_ROW][MAX_COL], char tempArray[MAX_ROW][MAX_COL])
{
    srand(time(0));
    int randomRow=rand()%(MAX_ROW-6);
    int randomCol=rand()%(MAX_COL-6);

    for (int startRow=randomRow; startRow<(randomRow+5); startRow++)
    {
        tempArray[startRow][randomCol]=79;
        tempArray[startRow][randomCol+6]=79;
    }
    for (int lastrow=randomRow+5; lastrow< randomRow+6; lastrow++)
    {
        for (int startCol=randomCol; startCol< randomCol+7; startCol++)
        {
            tempArray[lastrow][startCol]=79;
        }
    }
}


void copyArray(char currentArray[MAX_ROW][MAX_COL], char tempArray[MAX_ROW][MAX_COL])
{
    for (int row=0; row<MAX_ROW; row++)
    {
        for (int column=0; column<MAX_COL; column++)
        {
            currentArray[row][column]=tempArray[row][column];
        }
    }
}

void displayArray(char currentArray[MAX_ROW][MAX_COL], char tempArray[MAX_ROW][MAX_COL])
{
    for (int row=0; row< MAX_ROW; row++)
    {
        for (int column=0; column<MAX_COL; column++)
        {
            cout << currentArray[row][column];
            if ((column+1)%MAX_COL==0)
            {
                cout << endl;
            }
        }
    }
}

void setNextGenArray(char currentArray[MAX_ROW][MAX_COL], char tempArray[MAX_ROW][MAX_COL])
{
    char live='O';
    char dead=',';
    for (int row=0; row<MAX_ROW; row++)
    {
        for (int col=0; col<MAX_COL; col++)
        {
            int counter=0;

            if(row==0 && col==0)
            {
                if (currentArray[row][col+1]==live)
                    counter++;
                if (currentArray[row+1][col+1]==live)
                    counter++;
                if (currentArray[row+1][col]==live)
                    counter++;
            }
            if (row==0 && col>0 && col<MAX_COL)
            {
                if(currentArray[row][col-1]==live)
                    counter++;
                if (currentArray[row+1][col-1]==live)
                    counter++;
                if (currentArray[row+1][col]==live)
                    counter++;
                if (currentArray[row+1][col+1]==live)
                    counter++;
                if (currentArray[row][col+1]==live)
                    counter++;
            }
            if (row==0 && col==MAX_COL)
            {
                if(currentArray[row][col-1]==live)
                    counter++;
                if(currentArray[row+1][col-1]==live)
                    counter++;
                if (currentArray[row+1][col]==live)
                    counter++;
            }
            if (row>0 && row<MAX_ROW && col==0)
            {
                if (currentArray[row-1][col]==live)
                    counter++;
                if (currentArray[row-1][col+1]==live)
                    counter++;
                if (currentArray[row][col+1]==live)
                    counter++;
                if (currentArray[row+1][col+1]==live)
                    counter++;
                if (currentArray[row+1][col]==live)
                    counter++;
            }
            if (row>0 && row<MAX_ROW &&col==MAX_COL)
            {
                if (currentArray[row-1][col]==live)
                    counter++;
                if (currentArray[row-1][col-1]==live)
                    counter++;
                if (currentArray[row][col-1]==live)
                    counter++;
                if (currentArray[row+1][col-1]==live)
                    counter++;
                if (currentArray[row+1][col]==live)
                    counter++;
            }
            if (row==MAX_ROW && col==0)
            {
                if (currentArray[row-1][col]==live)
                    counter++;
                if (currentArray[row-1][col+1]==live)
                    counter++;
                if (currentArray[row][col+1]==live)
                    counter++;
            }
            if (row==MAX_ROW && col>0 && col<MAX_COL)
            {
                if (currentArray[row][col-1]==live)
                    counter++;
                if (currentArray[row-1][col-1]==live)
                    counter++;
                if (currentArray[row-1][col]==live)
                    counter++;
                if (currentArray[row-1][col+1]==live)
                    counter++;
                if (currentArray[row][col+1]==live)
                    counter++;
            }
            if (row==MAX_ROW && col==MAX_COL)
            {
                if (currentArray[row][col-1]==live)
                    counter++;
                if (currentArray[row-1][col-1]==live)
                    counter++;
                if (currentArray[row-1][col]==live)
                    counter++;
            }
            if (row>0 && row<MAX_ROW && col>0 && col<MAX_COL)
            {
                if (currentArray[row-1][col-1]==live)
                    counter++;
                if (currentArray[row-1][col]==live)
                    counter++;
                if (currentArray[row-1][col+1]==live)
                    counter++;
                if (currentArray[row][col-1]==live)
                    counter++;
                if (currentArray[row][col+1]==live)
                    counter++;
                if (currentArray[row+1][col-1]==live)
                    counter++;
                if (currentArray[row+1][col]==live)
                    counter++;
                if (currentArray[row+1][col+1]==live)
                    counter++;
            }

            if (currentArray[row][col]==live)
            {
                if (counter<2)
                {
                    tempArray[row][col]=dead;
                }
                if (counter==2||counter==3)
                {
                    tempArray[row][col]=live;
                }
                    if (counter>3)
                {
                    tempArray[row][col]=dead;
                }
            }
            if (currentArray[row][col]==dead)
            {
                if (counter==3)
                {
                    tempArray[row][col]=live;
                }
                else
                {
                    tempArray[row][col]=dead;
                }
            }
        }
    }
}


void loadPatternArray( char currentArry[MAX_ROW][MAX_COL], char tempArray[MAX_ROW][MAX_COL])
{
    char live='O';
    char dead=',';
    int row;
    int col;
    char fileName[51]={};
    srand(time(0));
    int randomRow=rand()%(MAX_ROW-6);
    int randomCol=rand()%(MAX_COL-6);
    ifstream in_stream;
    cout << "Please enter a filename you wish to open." << endl;
    cout << "> ";
    cin >> fileName;
    in_stream.open(fileName);
    cout << endl;
    if (in_stream.fail())
    {
        cout << "Input file opening failed." << endl;
    }
    else
    {
        while (! in_stream.eof())
        {
            in_stream >> row >> col;
            tempArray[row+randomRow][col+randomCol]=live;
        }
    }
    in_stream.close();
}

void customPatternArray( char currentArray[MAX_ROW][MAX_COL], char tempArray[MAX_ROW][MAX_COL])
{
    int row, col;
    char live='O';
    char dead=',';
    bool resume=true;
    char choice;
    cout << "Enter a custom pattern (numbers indicating row and column)press 'd' and 'enter' when done." << endl;
    cout << "> ";
    cin >> row >> col;

    while (resume==true)
    {
        tempArray[row][col]=live;
        cin >> row >> col;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            resume=false;
        }
    }
    cout << tempArray[row][col];
    if ((col+1)%MAX_COL==0)
    {
        cout << endl;
    }
}

void arrowPatternArray (string arrowFile, char currentArry[MAX_ROW][MAX_COL], char tempArray[MAX_ROW][MAX_COL])
{
    int row;
    int col;
    char live='O';
    char dead=',';
    int randomRow=rand()%(MAX_ROW-6);
    int randomCol=rand()%(MAX_COL-6);
    ifstream openFile;
    openFile.open(arrowFile.c_str());
    if (openFile.fail())
    {
        cout << "Input file opening failed." << endl;
    }
    else
    {
        while (! openFile.eof())
        {
            openFile >> row >> col;
            tempArray[row+randomRow][col+randomCol]=live;
        }
    }
    openFile.close();
}

void pyeongPatternArray (string pyeongFile, char currentArray[MAX_ROW][MAX_COL], char tempArray[MAX_ROW][MAX_COL])
{
    int row;
    int col;
    char live='O';
    char dead=',';
    int randomRow=rand()%(MAX_ROW-6);
    int randomCol=rand()%(MAX_COL-6);
    ifstream in_stream;
    ifstream openFile;
    openFile.open(pyeongFile.c_str());
    if (openFile.fail())
    {
        cout << "Input file opening failed." << endl;
    }
    else
    {
        while (! openFile.eof())
        {
            openFile >> row >> col;
            tempArray[row+randomRow][col+randomCol]=live;
        }
    }
    in_stream.close();
}


void changPatternArray (string changFile, char currentArray[MAX_ROW][MAX_COL], char tempArray[MAX_ROW][MAX_COL])
{
    int row;
    int col;
    char live='O';
    char dead=',';
    int randomRow=rand()%(MAX_ROW-6);
    int randomCol=rand()%(MAX_COL-6);
    ifstream in_stream;
    ifstream openFile;
    openFile.open(changFile.c_str());
    if (openFile.fail())
    {
        cout << "Input file opening failed." << endl;
    }
    else
    {
        while (! openFile.eof())
        {
            openFile >> row >> col;
            tempArray[row+randomRow][col+randomCol]=live;
        }
    }
    in_stream.close();
}

