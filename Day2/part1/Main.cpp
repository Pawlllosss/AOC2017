#include <iostream>
#include <fstream>

int main()
{
    std::fstream file_input;
    file_input.open( "input.txt" , std::fstream::in );

    int smallest_row, biggest_row;

    int checksum = 0;

    if( file_input.good() )
    {
        while( !file_input.eof() )
        {
            int flag = 1;

            for( int i = 0 ; i < 16 ; i++ )
            {
                int value;

                file_input >> value;

                if( flag )
                {
                    smallest_row = value;
                    biggest_row = value;
                    flag = 0;
                }
                else if ( value < smallest_row )
                    smallest_row = value;
                else if ( value > biggest_row )
                    biggest_row = value;

            }

            checksum += biggest_row - smallest_row;


        }
    }

    std::cout<<"Checksum: "<<checksum<<std::endl;

    return 0;
}
