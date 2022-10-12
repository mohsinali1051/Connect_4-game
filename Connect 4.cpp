#include<iostream>
#include<string>

using namespace std;


struct connect4{

    connect4(string Names[]){
        re_init(Names);
    }
    connect4(){
        string N[2] = {"P1", "P2"};
        re_init(N);
    }
    void re_init(string Names[]){

        for(int i = 0; i< 7; i++){
            ColumnMoves[i] = 5;
            for(int j = 0; j< 6; j++)
                Data[j][i] = 32; // 32 is code of space character
        }
        Result = 0;
        GameOver = 0;
        PlayerNames[0] = Names[0];
        PlayerNames[1] = Names[1];
        PlayerChar[0] = 'o';
        PlayerChar[1] = 'x';
        PlayerWinningChar[0] = 'O';
        PlayerWinningChar[1] = 'X';
    }

    int MakeMove(int Column){
    /*
        This Function must make a move in the Column given as a parameter
        The function will use the function GameOver() to mark is the game
        is completed and set the value of variables GameOver and Result.
        The function must also update the array ColumnMoves.

        The function must return 0 if the move has been made, 1 if the move
        is invalid (can not be done as the column is already filled) and 2
        if the game is already over.

        This function must also change the value of TurningPlayer if the move
        was successful;
    */
        TC=Column-1;
        TR=ColumnMoves[TC];
        if(GameOver==true)
        {
            //the game is already over
            Result =1;
            return 2;
        }
        if(TR<0)
        {
            //if the move is invalid (can not be done as the column is already filled)
            return 1;
        }
        int TP=WhosTurn();
        if(TP==0)
        {
            Data[TR][TC]=PlayerChar[0];
        }
        else
        {
            Data[TR][TC]=PlayerChar[1];
        }
        ColumnMoves[TC]=TR-1;

        return 0;
    }

    void ShowGame(){
    /*
        Function to display the game status on screen;
    */
        cout << "   1   " << "  2    " << " 3    " << " 4    " << " 5    " << " 6    " << " 7     " << endl;
        cout << "------------------------------------------"<<endl;
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<7;j++)
            {
                cout<<"|";
                cout<<" "<<Data[i][j]<<"   ";
            }
            cout<<endl<<"|-----|-----|-----|-----|-----|-----|-----"<<endl;
        }
    }

    bool isGameOver(){
        if(CheckIfGameOver(TR,TC))
        {
            GameOver=true;
        }
        else
        {
            GameOver=false;
        }
        return GameOver;
    }

    int WhosTurn()
    {
        //TurningPlayer=1 is initialized in private
        TurningPlayer++;
        if(TurningPlayer%2==0)
        {
            TurningPlayer=0;
        }
        else
        {
            TurningPlayer=1;
        }

        return TurningPlayer;
    }

    string getPlayerName(int id){
        if(id< 0 || id > 1 )
            return "";
        return PlayerNames[id];
    }
private:
    bool CheckIfGameOver(int r, int c){
    /*
        This function will check if the game is finished and set the values
        of variables GameOver and Result
        The parameters r and c specify the position of last move last
    */

        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r][c-1]==PlayerChar[TurningPlayer] && Data[r][c-2]==PlayerChar[TurningPlayer] && Data[r][c-3]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r][c-1]=PlayerWinningChar[TurningPlayer];
            Data[r][c-2]=PlayerWinningChar[TurningPlayer];
            Data[r][c-3]=PlayerWinningChar[TurningPlayer];
            return true;
        }
        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r][c-1]==PlayerChar[TurningPlayer] && Data[r][c-2]==PlayerChar[TurningPlayer] && Data[r][c+1]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r][c-1]=PlayerWinningChar[TurningPlayer];
            Data[r][c-2]=PlayerWinningChar[TurningPlayer];
            Data[r][c+1]=PlayerWinningChar[TurningPlayer];
            return true;
        }
        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r][c-1]==PlayerChar[TurningPlayer] && Data[r][c+2]==PlayerChar[TurningPlayer] && Data[r][c+1]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r][c-1]=PlayerWinningChar[TurningPlayer];
            Data[r][c+2]=PlayerWinningChar[TurningPlayer];
            Data[r][c+1]=PlayerWinningChar[TurningPlayer];
            return true;
        }
        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r][c+3]==PlayerChar[TurningPlayer] && Data[r][c+2]==PlayerChar[TurningPlayer] && Data[r][c+1]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r][c+1]=PlayerWinningChar[TurningPlayer];
            Data[r][c+2]=PlayerWinningChar[TurningPlayer];
            Data[r][c+3]=PlayerWinningChar[TurningPlayer];
            return true;
        }
        //Vertically
        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r+3][c]==PlayerChar[TurningPlayer] && Data[r+2][c]==PlayerChar[TurningPlayer] && Data[r+1][c]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r+1][c]=PlayerWinningChar[TurningPlayer];
            Data[r+2][c]=PlayerWinningChar[TurningPlayer];
            Data[r+3][c]=PlayerWinningChar[TurningPlayer];
            return true;
        }
        //Diagonally
        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r+1][c+1]==PlayerChar[TurningPlayer] && Data[r+2][c+2]==PlayerChar[TurningPlayer] && Data[r+3][c+3]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r+1][c+1]=PlayerWinningChar[TurningPlayer];
            Data[r+2][c+2]=PlayerWinningChar[TurningPlayer];
            Data[r+3][c+3]=PlayerWinningChar[TurningPlayer];
            return true;
        }
        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r+1][c+1]==PlayerChar[TurningPlayer] && Data[r+2][c+2]==PlayerChar[TurningPlayer] && Data[r-1][c-1]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r+1][c+1]=PlayerWinningChar[TurningPlayer];
            Data[r+2][c+2]=PlayerWinningChar[TurningPlayer];
            Data[r-3][c-3]=PlayerWinningChar[TurningPlayer];
            return true;
        }
        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r+1][c+1]==PlayerChar[TurningPlayer] && Data[r-2][c-2]==PlayerChar[TurningPlayer] && Data[r-1][c-1]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r+1][c+1]=PlayerWinningChar[TurningPlayer];
            Data[r-2][c-2]=PlayerWinningChar[TurningPlayer];
            Data[r-3][c-3]=PlayerWinningChar[TurningPlayer];
            return true;
        }
        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r-3][c-3]==PlayerChar[TurningPlayer] && Data[r-2][c-2]==PlayerChar[TurningPlayer] && Data[r-1][c-1]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r-1][c-1]=PlayerWinningChar[TurningPlayer];
            Data[r-2][c-2]=PlayerWinningChar[TurningPlayer];
            Data[r-3][c-3]=PlayerWinningChar[TurningPlayer];
            return true;
        }
        //Right Diagonal
        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r+1][c-1]==PlayerChar[TurningPlayer] && Data[r+2][c-2]==PlayerChar[TurningPlayer] && Data[r+3][c-3]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r+1][c-1]=PlayerWinningChar[TurningPlayer];
            Data[r+2][c-2]=PlayerWinningChar[TurningPlayer];
            Data[r+3][c-3]=PlayerWinningChar[TurningPlayer];
            return true;
        }
        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r+1][c-1]==PlayerChar[TurningPlayer] && Data[r+2][c-2]==PlayerChar[TurningPlayer] && Data[r-1][c+1]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r+1][c-1]=PlayerWinningChar[TurningPlayer];
            Data[r+2][c-2]=PlayerWinningChar[TurningPlayer];
            Data[r-1][c+1]=PlayerWinningChar[TurningPlayer];
            return true;
        }
        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r+1][c-1]==PlayerChar[TurningPlayer] && Data[r-2][c+2]==PlayerChar[TurningPlayer] && Data[r-1][c+1]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r+1][c-1]=PlayerWinningChar[TurningPlayer];
            Data[r-2][c+2]=PlayerWinningChar[TurningPlayer];
            Data[r-1][c+1]=PlayerWinningChar[TurningPlayer];
            return true;
        }
        if(Data[r][c]==PlayerChar[TurningPlayer] && Data[r-3][c+3]==PlayerChar[TurningPlayer] && Data[r-2][c+2]==PlayerChar[TurningPlayer] && Data[r-1][c+1]==PlayerChar[TurningPlayer])
        {
            Data[r][c]=PlayerWinningChar[TurningPlayer];
            Data[r-1][c+1]=PlayerWinningChar[TurningPlayer];
            Data[r-2][c+2]=PlayerWinningChar[TurningPlayer];
            Data[r-3][c+3]=PlayerWinningChar[TurningPlayer];
            return true;
        }

        return false;

    }

    string PlayerNames[2]; // To Hold Name of Players Who are playing
    int TurningPlayer=1; // To save the players ID who is making a move; 0: First Player, 1: Second Player
    char PlayerChar[2]; // Characters to be shown for move
    char PlayerWinningChar[2]; // Character to be shown if player wins.
    int  ColumnMoves[7]; // An array to keep record of first empty cell in a column
    char Data[6][7]; // Array to hold game data.
    bool GameOver; // If true it means the game is over.
    int Result;// Variable to hold result of game {0: Drawn, -1: First Player Lost, 1: First Player Won}
    int TR,TC;
};


int main(){
    /*
        This function use a single variable of type connect4
        and use it's functions to play the game
    */
    connect4 Game;
    cout<<"              ----------------------------WELCOME TO CONNECT 4 (the game of minds)--------------------------- "<<endl;
    string N[2];
    cout<<"Enter First Player Name: ";
    getline(cin,N[0]);
    cout<<"Enter Second Player Name: ";
    getline(cin,N[1]);
    Restart:
    Game.re_init(N);
    int TurningPlayer=1;
    int n,y,p=0;
    do
    {
        Game.ShowGame();
        ink:
        TurningPlayer++;
        if(TurningPlayer%2==0)
        {
            TurningPlayer=0;
        }
        else
        {
            TurningPlayer=1;
        }
        cout<<endl<<Game.getPlayerName(TurningPlayer)<<" Now it's your Turn "<<endl;
        cout<<"Enter the Column from 1 to 7 Number: ";
        cin>>n;
        if(n<1 || n>7)
        {
            cout<<"Error "<<endl<<"If you again Enter the wrong Entry then turn will automatically shift to the other player ";
            cout<<endl<<"Enter the column number: ";
            cin>>n;
            if(n<1 || n>7)
            {
                cout<<"Error "<<endl<<"Next player please continue ";
                goto ink;
            }
        }
        Game.MakeMove(n);
        p++;
        if(p>41)
        {
            cout<<"Game Draw,Both players played very well ";
            Game.ShowGame();
            cout<<endl;
            goto King;
        }

    }while(!Game.isGameOver());
    Game.ShowGame();
    cout<<"Congratulations!!!"<<endl<<Game.getPlayerName(TurningPlayer)<<" Won "<<endl;
    King:
    cout<<endl;
    cout<<"WOULD YOU LIKE TO PLAY ANOTHER GAME? ";
    cout<<endl<<"1.YES "<<endl<<"2.NO "<<endl;
    cout<<"Enter your choice: ";
    cin>>y;
    if(y==1)
    {
        goto Restart;
    }

    cout<<"Allah Hafiz ";
    return 0;
}



