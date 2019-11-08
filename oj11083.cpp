#include<stdio.h>
class A
{   public:
    A() : x(0), y(0){}
    void func(const int p) const
    {   x = p;
        y = p;
    }
    int getY()
    {   return y;
    }
    int x;
private:
    int y;
};

int main(int argc, char* argv[])
{
    A a;
    printf("x:%d y:%d\n", a.x, a.getY());
    a.func(2);
    printf("x:%d y:%d\n", a.x, a.getY());
    return 0;
}
