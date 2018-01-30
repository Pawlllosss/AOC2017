#include "SpiralMem.h"
#include <cmath>
#include <iostream>
#include <iomanip>

SpiralMem::SpiralMem( const int NumberToCount ) : _array_size( ceil(sqrt(NumberToCount)) ), _number_to_count( NumberToCount )
{
    _tab = new double * [ _array_size ];

    for( int i = 0 ; i < _array_size ; i++ )
        _tab[i] = new double [ _array_size ];

    for(int i = 0 ; i < _array_size ; i++)
        for(int j = 0 ; j < _array_size ; j++)
            _tab[i][j] = -1;

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
    int row = _array_size/2;
    int column = row - (_array_size + 1)%2;

    int steps = 2;
    int flag = 1;
    int begining_of_filling = 1;

    _tab[row][column] = 1;

    column++;
    row++;

    while( flag )
    {

        for( int move_value = UP ; move_value <= RIGHT ; move_value++ )
        {
            if ( _tab[row][column] > _number_to_count )
            {
                flag = 0;
                break;
            }

            if( flag )
            {
                switch( move_value )
                {
                    case UP:

                        for( int i = 0 ; i < steps ; i++ )
                        {
                            row--;

                            _tab[row][column] = Adjacent_sum( row, column );
                        }
                        if (_tab[row][column - 1] != -1)
                            flag = 0;

                    break;

                    case LEFT:

                            if(begining_of_filling)
                                begining_of_filling = 0;
                            else
                                steps++;

                        for( int i = 0 ; i < steps ; i++ )
                        {
                            column--;

                            _tab[row][column] = Adjacent_sum( row, column );
                        }

                        if( _tab[row + 1][column] != -1 )
                            flag = 0;

                    break;

                    case DOWN:

                        for( int i = 0 ; i < steps ; i++ )
                        {
                            row++;

                            _tab[row][column] = Adjacent_sum( row, column );
                        }


                        if( _tab[row][column + 1] != -1 )
                                flag = 0;

                    break;

                    case RIGHT:

                        steps++;

                        for( int i = 0 ; i < steps ; i++ )
                        {
                            column++;

                            _tab[row][column] = Adjacent_sum( row, column );
                        }
                        if (_tab[row - 1][column] != -1)
                                flag = 0;

                    break;
                }
            }

        }



    }
}

double SpiralMem::Adjacent_sum( const int row, const int column )
{
    double sum = 0;
    static int flag = 1;

    if( row - 1 >= 0 && _tab[row - 1][column] != -1 ) //UP
        sum +=_tab[row - 1][column];

    if( row + 1 < _array_size && _tab[row + 1][column] != -1 ) //DOWN
        sum +=_tab[row + 1][column];

    if( row - 1 >= 0 && column - 1 >= 0 && _tab[row - 1][column - 1] != -1 ) //UP LEFT
        sum +=_tab[row - 1][column -1];

    if( column - 1 >= 0 && _tab[row][column - 1] != -1 ) // LEFT
        sum +=_tab[row][column - 1];

    if( row + 1 < _array_size && column - 1 >= 0 && _tab[row + 1][column -1] != -1 ) //DOWN LEFT
        sum +=_tab[row + 1][column - 1];

    if( row - 1 >= 0 && column + 1 < _array_size && _tab[row - 1][column + 1] != -1 ) //UP RIGHT
        sum +=_tab[row - 1][column + 1];

    if( column + 1 < _array_size && _tab[row][column + 1] != -1 ) //RIGHT
        sum +=_tab[row][column + 1];

    if( row + 1 < _array_size && column + 1 < _array_size && _tab[row + 1][column + 1] != -1 ) //DOWN RIGHT
        sum +=_tab[row + 1][column + 1];

    if ( flag && _number_to_count < sum)
    {
        _first_bigger_number = sum;
        flag = 0;
    }

    return sum;
}


double SpiralMem::GetBiggerThanNumber()
{
    return _first_bigger_number;
}
