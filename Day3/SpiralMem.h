#ifndef SpiralMemH
#define SpiralMemH

class SpiralMem
{
public:
    SpiralMem( const int MemSize );
    ~SpiralMem();
    double GetBiggerThanNumber();
private:
    enum moves{ UP, LEFT, DOWN, RIGHT };
    double FillMem();
    double Adjacent_sum( const int row, const int column );
    int _array_size;
    double _number_to_count;
    double _first_bigger_number;
    double ** _tab;
};
#endif
