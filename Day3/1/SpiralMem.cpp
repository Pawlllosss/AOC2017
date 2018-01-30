#include "SpiralMem.h"
#include <cmath>
#include <iostream>
#include <iomanip>

SpiralMem::SpiralMem( int MemSize ) : _array_size( MemSize )
{
    _tab = new int * [ _array_size ];

    for( int i = 0 ; i < _array_size ; i++ )
        _tab[i] = new int [ _array_size ];

    FillMem();
}

SpiralMem::~SpiralMem()
{
    for( int i = 0 ; i < _array_size ; i++ )
        delete [] _tab[i];

    delete [] _tab;
}

void SpiralMem::FillMem()
{
int move_of_mem = LEFT;
    int column = _array_size-1;
    int row = column;

    int org_column = column;
    int org_row = row;

    int value = _array_size * _array_size;

    while( value != 0 )
    {
        int steps = sqrt(value);

        for( int move_value = LEFT ; move_value <= DOWN ; move_value++ )
        {
            //potem sprobowac z tablica wskaznikow
            switch( move_value )
            {
                case LEFT:
                    for( int i = 0 ; i < steps ; i++ )
                    {
                        _tab[row][column - i] =  value;//albo tutaj value__
                        value--;
                    }
                    column -= steps - 1;
                break;

                case UP:
                    for( int i = 1 ; i < steps ; i++ )
                    {
                        _tab[row - i][column] =  value;//albo tutaj value__
                        value--;
                    }
                    row -= steps - 1;
                break;

                case RIGHT:
                    for( int i = 1 ; i < steps ; i++ )
                    {
                        _tab[row][column + i] =  value;//albo tutaj value__
                        value--;
                    }
                    column += steps - 1;
                break;

                case DOWN:
                    for( int i = 1 ; i < steps - 1 ; i++ )
                    {
                        _tab[row + i][column] =  value;//albo tutaj value__
                        value--;
                    }
                    row += steps - 2;
                    column--;
                break;
            }

            //std::cout<<row<<" "<<column<<std::endl;

        }



    }
}


int SpiralMem::LookForPath( int number )
{
    int moves = 0;

    int flag = 0;//checks if the place of number in the array has been found

    int nmb_row, nmb_col;

    for( nmb_row = 0 ; nmb_row < _array_size ; nmb_row++ )
    {
        for( nmb_col = 0 ; nmb_col < _array_size ; nmb_col++ )
            if( _tab[nmb_row][nmb_col] == number)
            {
                flag = 1;
                break;
            }
        if(flag)
            break;
    }


    while( _tab[nmb_row][nmb_col] != 1 )
    {
        int difference = 0;
        int choosen_move;

        for( int move_value = LEFT ; move_value <= DOWN ; move_value++ )
        {
            switch( move_value )
            {
                case LEFT:
                    if( nmb_col - 1 >= 0 )
                        if( _tab[nmb_row][nmb_col] - _tab[nmb_row][nmb_col - 1] > difference)//sprawdzac tez czy po prostu sasiednia nie rowna sie jeden
                        {
                            difference = _tab[nmb_row][nmb_col] - _tab[nmb_row][nmb_col - 1];
                            choosen_move = LEFT;
                        }
                break;

                case UP:
                    if( nmb_row - 1 >= 0 )
                        if( _tab[nmb_row][nmb_col] - _tab[nmb_row - 1][nmb_col] > difference)//sprawdzac tez czy po prostu sasiednia nie rowna sie jeden
                        {
                            difference = _tab[nmb_row][nmb_col] - _tab[nmb_row - 1][nmb_col];
                            choosen_move = UP;
                        }

                break;

                case RIGHT:
                    if( nmb_col + 1 < _array_size )
                        if( _tab[nmb_row][nmb_col] - _tab[nmb_row][nmb_col + 1] > difference)//sprawdzac tez czy po prostu sasiednia nie rowna sie jeden
                        {
                            difference = _tab[nmb_row][nmb_col] - _tab[nmb_row][nmb_col + 1];
                            choosen_move = RIGHT;
                        }

                break;

                case DOWN:
                    if( nmb_row + 1 < _array_size )
                        if( _tab[nmb_row][nmb_col] - _tab[nmb_row + 1][nmb_col] > difference)//sprawdzac tez czy po prostu sasiednia nie rowna sie jeden
                        {
                            difference = _tab[nmb_row][nmb_col] - _tab[nmb_row + 1][nmb_col];
                            choosen_move = DOWN;
                        }

                break;

            }
        }

        switch( choosen_move )
        {
            case LEFT:
                nmb_col--;
            break;

            case UP:
                nmb_row--;
            break;

            case RIGHT:
                nmb_col++;
            break;

            case DOWN:
                nmb_row++;
            break;
        }

        moves++;
    }

    return moves;
}
