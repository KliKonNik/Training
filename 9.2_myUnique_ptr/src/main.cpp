#include <iostream>
#include <format>
#include <memory>

#include "myUnique_ptr.h"

using namespace myUniquePtr;
using std::cout;
using std::endl;
using std::format;

int main()
{
    cout << "#Test of the constructor and destructor without object:" << endl;
    {
        myUnique_ptr<int> up;
    }

    cout << "\n#Test of the constructor and destructor with object:" << endl;
    {
        myUnique_ptr<int> up(new int(5));
    }

    cout << "\n#Test of the move constructor:" << endl;
    {
        myUnique_ptr<int> up0(new int(5));
        myUnique_ptr<int> up1(std::move(up0));
    }

    cout << "\n#Test of the move assign:" << endl;
    {
        myUnique_ptr<int> up0(new int(5));
        myUnique_ptr<int> up1;

        up1 = std::move(up0);
    }

    cout << "\n#Test of the self move assign:" << endl;
    {
        myUnique_ptr<int> up0(new int(5));

        up0 = std::move(up0);
    }

    cout << "\n#Test of the swap:" << endl;
    {
        myUnique_ptr<int> up0(new int(5));
        myUnique_ptr<int> up1(new int(6));

        up1.swap(up0);
    }

    cout << "\n#Test of the self swap:" << endl;
    {
        myUnique_ptr<int> up0(new int(5));
        up0.swap(up0);
    }

    cout << "\n#Test of the get, reset, release:" << endl;
    {
        myUnique_ptr<int> up0(new int(5));

        const int* ptr = up0.get();
        //(*ptr) = 6; // ERROR!!!
        //cout << format("[{}]: ptr[{}] = up.get(), *ptr = {}\n", to_string(up0), to_string(ptr), *ptr);
        cout << '[' << &up0 << "]: ptr[" << ptr << "] = up.get(), *ptr = " << *ptr << '\n';
        
        cout << "\nAfter reset(new int(6)):\n";
        up0.reset(new int(6)); 
        //cout << format("[{}]: up.get(), *up.get() = {}\n", to_string(up0), *up0.get());
        cout << '[' << &up0 << "]: *up.get()[" << up0.get() << "] = " << *up0.get() << '\n';

        ptr = up0.realease();
        cout << "\nAfter ptr = up.realease():\n";
        //cout << format("[{}]: up.get(), *ptr[{}] = {}, \n", to_string(up0), to_string(ptr), *ptr);
        cout << '[' << &up0 << "]: up.get() = [" << up0.get() << "], *ptr[" << ptr << "] = " << *ptr << '\n';
    }

    cout << "\n#Test of the operator bool():" << endl;
    {
        myUnique_ptr<int> up0(new int(5));
        myUnique_ptr<int> up1;

        if (up0) cout << "up0[" << &up0 << "] has an object." << endl;
        if (up1) cout << "up1[" << &up1 << "] has an object." << endl;
        else cout << "up1[" << &up1 << "] doesn't have an object." << endl;
    }

    cout << "\n#Test of the operator*:" << endl;
    {
        myUnique_ptr<int> up0(new int(5));

        cout << "Now:" << endl;
        cout << "up0[" << &up0 << "] = " << *up0 << endl;
        *up0 = 100;
        cout << "After *up0 = 100:" << endl;
        cout << "up0[" << &up0 << "] = " << *up0 << endl;
    }

    cout << "\n#Test of the operator->:" << endl;
    {
        struct foo
        {
            int i;
            void bar() { cout << "\nfoo::bar(" << i << ")\n"; }
        };

        myUnique_ptr<foo> up0(new foo);
        
        up0->i = 100;
        up0->bar();
    }

    cout << endl;
    return 0;
}