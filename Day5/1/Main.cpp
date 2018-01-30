#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::fstream file_input;
    std::vector <int> offset_instructions;

    int steps = 0;

    file_input.open( "input.txt", std::fstream::in );

    if( file_input.good() )
    {
        int cur_position = 0;
        int offset;

        while( file_input >> offset)
            offset_instructions.push_back( offset );

        int instructions_size = offset_instructions.size();

        while( cur_position >= 0 && cur_position < instructions_size )
        {
            offset = offset_instructions[cur_position];
            offset_instructions[cur_position]++;
            cur_position += offset;

            steps++;
        }
    }

    std::cout<<steps<<std::endl;
}
