#include <iostream>
#include <string>


class Estado
{
private:
    std::string location; // "A" ou "B"
    bool isDirtyA;         // 
    bool isDirtyB;         // 

public:
    Estado(std::string loc, bool dirtyA, bool dirtyB)
        : location(loc), isDirtyA(dirtyA), isDirtyB(dirtyB) {};
    ~Estado();
};

Estado::Estado(std::string loc, bool dirtyA, bool dirtyB)
    : location(loc), isDirtyA(dirtyA), isDirtyB(dirtyB)
{
}

Estado::~Estado()
{
}
