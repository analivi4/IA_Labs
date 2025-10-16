#ifndef Estado_h
#define Estado_h

#include <iostream>
#include <string>

class Estado
{
private:
    std::string location; // "A" ou "B"
    bool isDirtyA;         // true se a sala A estiver suja
    bool isDirtyB;         // true se a sala B estiver suja
public:
    Estado(std::string loc, bool dirtyA, bool dirtyB);
    ~Estado();
};
Estado::Estado(std::string loc, bool dirtyA, bool dirtyB)
    : location(loc), isDirtyA(dirtyA), isDirtyB(dirtyB)
{
}
Estado::~Estado()
{
}
#endif