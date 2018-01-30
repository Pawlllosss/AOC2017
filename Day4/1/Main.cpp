#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void Print( const std::vector <std::string> & data )
{
    for( std::size_t i = 0 ; i < data.size() ; i++ )
        std::cout<<data.at(i)<<" ";
    std::cout<<std::endl;
}

int main()
{
    std::fstream file_input;

    int valid_pass = 0;
    int flag = 1;

    file_input.open( "input.txt", std::fstream::in );

    if( file_input.good() )
    {
        std::string line_input;
        std::vector <std::string> words;

        while( getline( file_input, line_input) )
        {
            std::size_t current_position = 0;

            std::size_t position;

            while ( (position = line_input.find(" ", current_position) ) != std::string::npos )
            {
                words.push_back( line_input.substr( current_position, position - current_position ));
                current_position = position + 1;
            }

            words.push_back( line_input.substr( current_position, line_input.length() - current_position ));

            //Print(words);

            for( int i = 0 ; i < words.size() - 1 ; i++ )
            {
                for( int j = i + 1 ; j < words.size() ; j++ )
                {
                    if( words.at(i) == words.at(j) )
                    {
                        flag = 0;
                        break;
                    }
                }

                if( !flag )
                    break;
            }

            if( flag )
                valid_pass++;

            flag = 1;

            words.clear();

        }
    }

    std::cout<<valid_pass<<std::endl;

    return 0;
}
