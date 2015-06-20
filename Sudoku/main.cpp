//
//  main.cpp
//  Sudoku
//
//  Created by Mudit Gupta on 6/20/15.
//  Copyright (c) 2015 Mudit Gupta. All rights reserved.
//

#include <iostream>
#define i(a,b,c) sudoku[a-1][b-1].ChangeState(c)
using namespace std;

class cell
{
    
    int state = 0;
    int box_number;
    
    
public:
    
    bool is_filled = false;
    bool possibilities[9] = {true, true, true, true, true, true, true, true, true};
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

void DrawGrid()         //only to draw the grid
{
    cout<<" --- --- --- --- --- --- --- --- ---\n";
    for(int i=0; i<9; i++)
    {
        for(int m=0; m<3; m++)
        {
            for(int j=0; j<9; j++)
            {
                cout<<"|";
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
    
    cout<<"\n\n\n\n\n\n\n\n\n\n\n";
    
}



int main()
{
    DrawGrid();
    
    
    {i(1,2,8);
        i(1,7,2);
        i(2,5,8);
        i(2,6,4);
        i(2,8,9);
        i(3,3,6);
        i(3,4,3);
        i(3,5,2);
        i(3,8,1);
        i(4,2,9);
        i(4,3,7);
        i(4,8,8);
        i(5,1,8);
        i(5,4,9);
        i(5,6,3);
        i(5,9,2);
        i(6,2,1);
        i(6,7,9);
        i(6,8,5);
        i(7,2,7);
        i(7,5,4);
        i(7,6,5);
        i(7,7,8);
        i(8,2,3);
        i(8,4,7);
        i(8,5,1);
        i(9,3,8);
        i(9,8,4);} //creating a sample puzzle
    
    DrawGrid();
}

