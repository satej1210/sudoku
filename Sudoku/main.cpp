//
//  main.cpp
//  Sudoku
//
//  Created by Mudit Gupta on 6/20/15.
//  Copyright (c) 2015 Mudit Gupta. All rights reserved.
//

#include <iostream>
#include <fstream>
#define i(a,b,c) sudoku[a-1][b-1].ChangeState(c)
using namespace std;
void DrawGrid();
class cell
{
    int state = 0;
    int box_number;

public:
    bool is_filled = false;
    bool possibilities[9] = {true, true, true, true, true, true, true, true, true};
    bool printed = false;

    void ChangeState(int x) //changes the state of the cell and deletes all possibilities
    {
        state = x;
        is_filled = true;
        for(int i=0; i<9; i++)
        {
            possibilities[i] = false;
        }
    }

    int GetState() //gets the private variable state
    {
        return state;
    }

}sudoku[9][9];

void GetPuz()//Reads the sudoku from a file
{
    fstream file("puzzle.txt");
    char temp[10];
    int CurRow=0;
    while(!file.eof())
    {
        file.getline(temp, 10);
        for (int i=0; i<9; i++)
        {
            if (temp[i]!=48)
            {
                sudoku[CurRow][i].ChangeState(int(temp[i]-48));
            }
            else
                sudoku[CurRow][i].is_filled=false;
        }
        CurRow++;
    }
}
void RowHiddenSingles(int i)
{
    int no=0;

    int flag=0;
    for (int j=1; j<=9; j++)
    {
        flag=0;
        //if(!(sudoku[i][k].is_filled))
        // {
            for (int k=0; k<9; k++)
            {
                if (sudoku[i][k].possibilities[j-1]==true)
                {

                    flag++;
                    no=k;

                }

            }
        //  }
        if (flag==1)
        {
            sudoku[i][no].ChangeState(j);

        }
    }


}
void HiddenSingles()
{
    for (int i=0; i<9; i++)
    {
        RowHiddenSingles(i);
    }

    // ColumnHiddenSingles();
    // BoxHiddenSingles();
}
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
                if(sudoku[i][j].is_filled && m==0)
                {
                    cout<<"\'"<<sudoku[i][j].GetState()<<"\'";
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

void CheckRow(int r) //actual row number. NOT INDEX.
{

    for(int i=1; i<=9; i++)
    {
        for(int j=1; j<=9; j++)
        {
            if(sudoku[r-1][j-1].GetState()==i)
            {
                for(int k=0; k<9; k++)
                    sudoku[r-1][k].possibilities[i-1]=false;
                break;
            }
        }

    }
}

void CheckColumn(int c) //actual column number. NOT INDEX.
{

    for(int i=1; i<=9; i++)
    {
        for(int j=1; j<=9; j++)
        {
            if(sudoku[j-1][c-1].GetState()==i)
            {
                for(int k=0; k<9; k++)
                    sudoku[k][c-1].possibilities[i-1]=false;
                break;
            }
        }

    }
}

void CheckBox(int x, int y) //super optimal. x and y are index numbers
{
    int a, b;
    a=x/3 * 3;
    b=y/3 * 3;
    if(sudoku[x][y].is_filled==true)
    {
        for(int i=a; i<=a+2; i++)
        {
            for(int j=b; j<=b+2; j++)
            {
                sudoku[i][j].possibilities[sudoku[x][y].GetState()-1] = false;
            }
        }
    }
}

void CheckAllSingles() //checks for any singles and marks them off!
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            int flag = -1;
            int store = -1;
            for(int k=0; k<9; k++)
            {
                if(sudoku[i][j].possibilities[k]==true) //to get flag and store
                {
                    flag++;
                    store = k;
                }
            }
            if(flag==0)             //if it is a single, change the state and check the row, column and boxes off.
            {
                sudoku[i][j].ChangeState(store+1);
                CheckRow(i);
                CheckColumn(j);
                CheckBox(i, j);
            }
        }
    }
}

void CheckAll() //checks all rows, columns and boxes off. used once in the beginning. Ideally not reqd again.
{
    DrawGrid();


    {
        //i(1,2,8);

        /* {i(1,2,8);
         >>>>>>> 45db928a32f7d2abe44a65a10fd7dbc31d4194fc
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

         i(9,8,4);
         i(1,8,7);
         } //creating a sample puzzle

         =======
         i(9,8,4);} //creating a sample puzzle

         >>>>>>> 45db928a32f7d2abe44a65a10fd7dbc31d4194fc
         DrawGrid();
         */ //Commented out cause getting from file
        GetPuz();
        CheckRow(1);
        DrawGrid();

        CheckColumn(1);
        DrawGrid();

        for(int i=1; i<=9; i++)
        {
            CheckRow(i);
            CheckColumn(i);
        }

        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                CheckBox(i, j);
            }
        }


        CheckAllSingles();



    }
}
int main()
{
    DrawGrid();
    GetPuz();
    {
        CheckAll();
        DrawGrid();

        // for(int i=0; i<10; i++)
        //{
        //   CheckAllSingles();
        //   DrawGrid();
        //}
    }
    HiddenSingles();
    DrawGrid();
}
