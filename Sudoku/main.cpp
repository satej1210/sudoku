//
//  main.cpp
//  Sudoku
//
//  Created by Mudit Gupta on 6/20/15.
//  Copyright (c) 2015 Mudit Gupta. All rights reserved.
//

#include <iostream>

using namespace std;

class cell
{
    
    int state = 0;
    int box_number;
    
    
public:
    
    bool is_filled = false;
    bool possibilities[9];
    bool printed = false;
    
    void ChangeState(int x)
    {
        state = x;
        is_filled = true;
        for(int i=0; i<9; i++)
        {
            possibilities[i] = false;
        }
    }
    
    bool GetPossibilities()
    {
        return possibilities;
    }
    
    int GetState()
    {
        return state;
    }
    
    
}sudoku[9][9];

void DrawGrid()
{
    cout<<" --- --- --- --- --- --- --- --- ---\n";
    for(int i=0; i<9; i++)
    {
        for(int m=0; m<3; m++)
        {
            for(int j=0; j<9; j++)
            {
                cout<<"|";
                /*if (sudoku[j][i].is_filled == true)
                 cout<<" "<<sudoku[j][i].GetState()<<" ";
                 else
                 cout<<"   ";*/
                if(sudoku[i][j].is_filled && sudoku[i][j].printed==false)
                {
                    cout<<"\'"<<sudoku[i][j].GetState()<<"\'";
                    sudoku[i][j].printed=true;
                }
                
                
                    if(sudoku[i][j].possibilities[m*3+0]==true&&!sudoku[i][j].is_filled)
                        cout<<m*3+1;
                    else if(sudoku[i][j].is_filled==false||m!=0)
                        cout<<" ";
                    if(sudoku[i][j].possibilities[m*3+1]==true&&!sudoku[i][j].is_filled)
                        cout<<m*3+2;
                    else if(sudoku[i][j].is_filled==false||m!=0)
                        cout<<" ";
                    if(sudoku[i][j].possibilities[m*3+2]==true&&!sudoku[i][j].is_filled)
                        cout<<m*3+3;
                    else if(sudoku[i][j].is_filled==false||m!=0)
                        cout<<" ";
                
            }
            if(m==0)
                cout<<"\b\b\b|\n";
            else
                cout<<"|\n";
        }
        cout<<" --- --- --- --- --- --- --- --- ---\n";
    }
    
}



int main()
{
    sudoku[8][8].possibilities[1]=true;
    sudoku[7][8].possibilities[1]=true;
    sudoku[0][8].possibilities[1]=true;
    sudoku[7][8].possibilities[1]=true;
    sudoku[7][8].possibilities[8]=true;
    sudoku[0][4].possibilities[1]=true;
    sudoku[7][8].possibilities[1]=true;
    sudoku[1][4].possibilities[4]=true;
    
    sudoku[7][8].possibilities[1]=true;
    sudoku[7][8].ChangeState(5);
    sudoku[3][4].ChangeState(5);
    sudoku[7][8].possibilities[0]=true;
    sudoku[7][8].possibilities[2]=true;
    
    
    DrawGrid();
}

