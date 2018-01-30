#ifndef SpiralMemH
#define SpiralMemH

class SpiralMem
{
public:
    SpiralMem( int MemSize );
    ~SpiralMem();
    int LookForPath( int number );
private:
    enum moves{ LEFT, UP, RIGHT, DOWN };
    void FillMem();
    int _array_size;
    int ** _tab;
    int _value_to_look;
};
#endif
