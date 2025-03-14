#include <iostream>
#include <cstdlib>


using namespace std;

const int BREIT = 7;
const int HOCH = 5;


void FIELDTETRISANDRE(char field[HOCH][BREIT]) {
    for (int i = 0; i < HOCH; i++) {
        for (int j = 0; j < BREIT; j++) {
            field[i][j] = ' ';
        }
    }
}

void printField(char field[HOCH][BREIT], int score)
{
    system("cls");
    cout << "Score: " << score << endl;
    for (int i = 0; i < HOCH; i++)
    {
            cout << "|";

        for (int j = 0; j < BREIT; j++)
        {

            cout << field[i][j];

        }

        cout << "|" << endl;
    }

    for (int i = 0; i < BREIT + 2; i++)
    {

        cout << "-";
    }
    cout << endl;
}

void addpiece(char field[HOCH][BREIT], int posX, int posY)

{
    const char PIECE = '#';

    if (posY < HOCH && posX < BREIT)
    {
        field[posY][posX] = PIECE;
    }
}

bool movedown(char field[HOCH][BREIT], int &posX, int &posY)
{
    if (posY + 1 >= HOCH || field[posY + 1][posX] != ' ')
    {
        return false;
    }

    // Clear current position
    field[posY][posX] = ' ';
    posY++;
    addpiece(field, posX, posY);
    return true;
}

void moveleft(char field[HOCH][BREIT], int &posX, int posY)
{
    if (posX > 0 && field[posY][posX - 1] == ' ')
    {
        // Clear current position
        field[posY][posX] = ' ';
        posX--;
        addpiece(field, posX, posY);
    }
}

void moveright(char field[HOCH][BREIT], int &posX, int posY) {
    if (posX + 1 < BREIT && field[posY][posX + 1] == ' ') {

        field[posY][posX] = ' ';
        posX++;
        addpiece(field, posX, posY);
    }
}

bool checkTopRow(char field[HOCH][BREIT])
{
    for (int j = 0; j < BREIT; j++)
    {
        if (field[0][j] == '#')
        {
            return true;
        }
    }
    return false;
}

int clearRows(char field[HOCH][BREIT])
{
    int clearedRows = 0;

    for (int i = HOCH - 1; i >= 0; i--)
    {
        bool fullRow = true;

        // Check full
        for (int j = 0; j < BREIT; j++)
        {
            if (field[i][j] == ' ')
            {
                fullRow = false;
                break;
            }
        }

        // If the row is full, clear it and shift rows above down
        if (fullRow) {
            clearedRows++;

            // Shift rows above down
            for (int k = i; k > 0; k--)
            {
                for (int j = 0; j < BREIT; j++)
                {
                    field[k][j] = field[k - 1][j];
                }
            }

            // Clear the top row
            for (int j = 0; j < BREIT; j++)
            {
                field[0][j] = ' ';
            }

            // Recheck the same row since it now contains the row above
            i++;
        }
    }

    return clearedRows;
}

int calculateScore(int clearedRows)
{
    switch (clearedRows)
    {
        case 1: return 10;
        default: return 0;
    }
}

int main()
{
    int eing;
        cout << "_____ERSTELLT VON ANDRE________" << endl;
        cout << "_______________________________" << endl;
        cout << "_______________________________" << endl;
        cout << "_______________________________" << endl;
        cout << "___________TETRIS______________" << endl;
        cout << "_______________________________" << endl;
        cout << "_______________________________" << endl;
        cout << "_______________________________" << endl;
        cout << "_______________________________" << endl;
        cout << "Herzlich Willkommen zum TETRIS "<<endl << endl;
        cout << "Drueck 1 zum Starten und 2 Beenden"<< endl << endl;
        cout << "-------------------------------" << endl;
        cin >> eing;

    if (eing == 1)
    {
            system("cls");
            char field[HOCH][BREIT];
            FIELDTETRISANDRE(field);

            int score = 0;
            int posX = 2;
            int posY = 0;
            addpiece(field, posX, posY);

            while (true)
            {
                printField(field, score);
                cout << "Waehle Aktion (a: links, d: rechts, s: runter): ";
                char action;
                cin >> action;

                if (action == 'a')
                {
                    moveleft(field, posX, posY);
                }
                else if (action == 'd')
                     {
                         moveright(field, posX, posY);
                     }
                     else if (action == '\n' || action == 's')
                     {
                        if (!movedown(field, posX, posY))
                        {
                            if (checkTopRow(field))
                            {
                                system("cls");
                                cout << "----------Projekt HBFIT 24-----------" << endl;
                                cout << "-------------------------------------" << endl;
                                cout << "-------------------------------------" << endl;
                                cout << "-------------------------------------" << endl;
                                cout << "---------GAME OVER!!!!!!!!!!!--------" << endl;
                                cout << "-------------------------------------" << endl;
                                cout << "-------------------------------------" << endl;
                                cout << "-------------------------------------" << endl;
                                cout << "-------------------------------------" << endl;
                                cout << "-------------------------------------" << endl;
                                cout << "--------Erstellt by Andre :P---------" << endl;

                                break;
                            }


                            int clearedRows = clearRows(field);
                            score += calculateScore(clearedRows);
                            posX = 2;
                            posY = 0;
                            addpiece(field, posX, posY);
                        }
                    }
            }

            cout << "Endpunktzahl: " << score << endl;
    }

    if (eing == 2) {
        system("cls"); // Optional

        cout << "----------Projekt HBFIT 24-----------" << endl;
        cout << "-------------------------------------" << endl;
        cout << "-------------------------------------" << endl;
        cout << "-------------------------------------" << endl;
        cout << "---------GAME OVER!!!!!!!!!!!--------" << endl;
        cout << "-------------------------------------" << endl;
        cout << "-------------------------------------" << endl;
        cout << "-------------------------------------" << endl;
        cout << "-------------------------------------" << endl;
        cout << "-------------------------------------" << endl;
        cout << "--------Erstellt by Andre :P---------" << endl;
        cout << "------Drueck enter zu beenden--------" << endl;
    }

    return 0;
}


