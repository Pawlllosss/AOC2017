#ifndef ListH
#define ListH

class List
{
public:
    void Add(const int value);
    void Print() const;
    int Calculate();
    ~List();
private:
	static int _items_count;
	static List * _root;
	int _number;
	List * _next;
};
#endif
