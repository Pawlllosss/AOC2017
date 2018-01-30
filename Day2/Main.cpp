#include <iostream>
#include <fstream>

int main()
{
    std::fstream file_input;
    file_input.open( "input.txt" , std::fstream::in );

    int smallest_row, biggest_row;

    int value[16];
    int result_int_row;

    int checksum = 0;

    if( file_input.good() )
    {
        while( true )
        {
            for( int i = 0 ; i < 16 ; i++ )
                file_input >> value[i];

            if ( file_input.eof() )
                break;

            for( int i = 0 ; i < 16 ; i++ )
                for( int j = 0 ; j < 16 ; j++)
                {
                    if( i == j )
                        continue;

                    if( value[i] % value[j] == 0 )
                    {
                        result_int_row = value[i] / value[j];

                        std::cout<<value[i]<<" "<< value[j]<<" "<<i<<" "<<j<<std::endl;
                        break;
                    }
                }

            checksum += result_int_row;


        }
    }

    std::cout<<"Checksum: "<<checksum<<std::endl;

    return 0;
}
