/*
 * assignment1.cpp
 *
 * <add comments to describe the purpose of this application>
 *
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

enum direction {LEFT_RIGHT, RIGHT_LEFT, DOWN, UP, RIGHT_DOWN, RIGHT_UP, LEFT_DOWN, LEFT_UP};

const int MAX = 50;

struct wordGame
{
    int version =2;
    int numberRows;
    int numberColumns;
    char puzzle[MAX][MAX];
    wordGame(){
      numberRows=0;
      numberColumns =0;
    };
    wordGame(int r, int c){
        numberRows = r;
        numberColumns = c;
    };
};
struct wordFind
{
    string word;
    bool found;
    int row;
    int column;
    direction where;
    wordFind(){
        found = false;
    };
    wordFind(bool f, int r, int c, direction wh){
      found = f;
      row =r;
      column =c;
      where = wh;
    };
};
string getDirection(direction x){
  switch(x){
      case LEFT_RIGHT: return "right";
      case RIGHT_LEFT: return "left";
      case DOWN: return "down";
      case UP: return "up";
      case RIGHT_DOWN: return "right/down";
      case RIGHT_UP: return "right/up";
      case LEFT_DOWN: return "left/down";
      case LEFT_UP: return "left/up";
  };
  return "";
}
// find the word that is part of the wordFind structure inside the wordGame structure.
// If the word is found the wordFind structure will be updated.
void findWord(wordGame &game, wordFind &theFind){
    for(int i = 0; i < game.numberRows; i++){
        for(int j = 0; j < game.numberColumns; j++){
            int num=0;
            int r=0;
            int c=0;
            if(game.puzzle[i][j] == theFind.word.at(num)){
                //test LEFT_RIGHT
                r=i; c=j; num=0;
                while(game.puzzle[r][++c]== theFind.word.at(++num)&& r>=0&& c>=0){
                    if(num==theFind.word.length()-1){
                        theFind.row = i+1;
                        theFind.column = j+1;
                        theFind.found = true;
                        theFind.where = LEFT_RIGHT;
                     break;
                    };
                };
                //test RIGHT_LEFT
                r=i; c=j; num=0;
                while(game.puzzle[r][--c]== theFind.word.at(++num)&& r>=0&& c>=0&&c<game.numberColumns){
                    if(num==theFind.word.length()-1){
                        theFind.row = i+1;
                        theFind.column = j+1;
                        theFind.found = true;
                        theFind.where = RIGHT_LEFT;
                        break;
                    };
                };
                //test DOWN
                r=i; c=j; num=0;
                while(++r>=0 && c>=0 && r<=game.numberRows-1 && game.puzzle[r][c]== theFind.word.at(++num)){
                    if(num==theFind.word.length()-1){
                        theFind.row = i+1;
                        theFind.column = j+1;
                        theFind.found = true;
                        theFind.where = DOWN;
                        break;
                    };
                };
                //test UP
                r=i; c=j; num=0;
                while(--r>=0 && c>=0 && r<=game.numberRows-1 && game.puzzle[r][c]== theFind.word.at(++num)){
                    if(num==theFind.word.length()-1){
                        theFind.row = i+1;
                        theFind.column = j+1;
                        theFind.found = true;
                        theFind.where = UP;
                        break;
                    };
                };
                //test RIGHT_UP
                r=i; c=j; num =0;
                while(--r>=0 && ++c>=0 && r<=game.numberRows-1 && c<=game.numberColumns-1&& game.puzzle[r][c]== theFind.word.at(++num)){
                    if(num==theFind.word.length()-1){
                        theFind.row = i+1;
                        theFind.column = j+1;
                        theFind.found = true;
                        theFind.where = RIGHT_UP;
                        break;
                    };
                };
                //test RIGHT_DOWN
                r=i; c=j; num=0;
                while(++r>=0 && ++c>=0 && r<=game.numberRows-1 && c<=game.numberColumns-1&& game.puzzle[r][c]== theFind.word.at(++num)){
                    if(num==theFind.word.length()-1){
                        theFind.row = i+1;
                        theFind.column = j+1;
                        theFind.found = true;
                        theFind.where = RIGHT_DOWN;
                        break;
                    };
                };
                //test LEFT_DOWN
                r=i; c=j; num=0;
                while(++r>=0 && --c>=0 && r<=game.numberRows-1 && c<=game.numberColumns-1&& game.puzzle[r][c]== theFind.word.at(++num)){
                    if(num==theFind.word.length()-1){
                        theFind.row = i+1;
                        theFind.column = j+1;
                        theFind.found = true;
                        theFind.where = LEFT_DOWN;
                        break;
                    };
                };
                //test LEFT_UP
                r=i; c=j; num=0;
                while(--r>=0 && --c>=0 && r<=game.numberRows-1 && c<=game.numberColumns-1&& game.puzzle[r][c]== theFind.word.at(++num)){
                    if(num==theFind.word.length()-1){
                        theFind.row = i+1;
                        theFind.column = j+1;
                        theFind.found = true;
                        theFind.where = LEFT_UP;
                        break;
                    }
                }
            }
        }
    }
}
// read the puzzle from the input file and update the wordGame structure.
bool readPuzzle(wordGame &game, string inputFileName){
    ifstream file(inputFileName);
    if(!file.is_open()){
        return false;
    }
    int r;
    int c;
    file>> r;
    file>> c;
    game.numberColumns = c;
    game.numberRows = r;

    char letter;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            file>> letter;
            game.puzzle[i][j] = letter;
        };
    };
    file.close();
    return true;
}
// display the contents of the puzzle
void displayPuzzle(wordGame &game){
    for(int i = 0; i < game.numberRows; ++i){
        for(int j = 0; j < game.numberColumns; ++j){
            //char letter = static_cast<char>(game.puzzle[i][j]);
            cout<<(char)game.puzzle[i][j];
        }
        cout<<endl;
    }
}
int main()
{
    wordGame game;
    string one;
    string two;
    cin>> one;
    cin>> two;
    if(!readPuzzle(game, one)){
        cout<< "The puzzle file \""<< one<<"\" could not be opened or is invalid\n";
        return 0;
    }
    cout<< "The puzzle from file \""<<one <<"\"\n";
    displayPuzzle(game);
    ifstream words(two);
    if(!words.is_open()){
        cout<< "The puzzle file \""<< two<<"\" could not be opened or is invalid\n";
        return 0;
    }
    string w, repeat;
    while(!words.eof()){
        wordFind wor;
        words>> w;
        if(repeat == w){return 0;}
        wor.word = w;
        findWord(game, wor);
        if(!wor.found){
            cout<< "The word "<< w<<" was not found\n";
        }else{
            cout<< "The word "<< w<<" was found at ("<<wor.row<<", "<< wor.column<<") - "<<getDirection(wor.where)<<"\n";
        }
        repeat =w;
    }
    words.close();
    return 0;
}