#include "List.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::fstream file_input;

    file_input.open( "input.txt" , std::fstream::in );

    List * circ_list = new List;

    if( file_input.good() )
    {
        std::string input;
        std::getline( file_input, input);

        int input_length = input.length();

        for( int i = 0 ; i < input_length ; i++ )
            circ_list->Add( input[i] - '0' );
    }

    int sum = circ_list->Calculate();

    std::cout<<"Sum: "<<sum<<std::endl;

    delete circ_list;

	return 0;
}
