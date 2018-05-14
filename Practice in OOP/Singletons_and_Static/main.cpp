#include <iostream>
#include "Counter.h"

using namespace std;

int SimpleCounter::i;

int main()
{
    cout << "PE 5\n--------" << endl;

    cout<<"\n< Static >\n";
    SimpleCounter * obj1 = new SimpleCounter();
    cout<<"\nFirst object was created\n";
    cout<<" Object 1 counter = "<<obj1->get_i()<<endl;

    SimpleCounter * obj2 = new SimpleCounter();
    cout<<"\nAnother object was created\n";
    cout<<" Object 1 counter = "<<obj1->get_i()<<"\n Object 2 counter = "<<obj2->get_i()<<endl;

    SimpleCounter * obj3 = new SimpleCounter();
    cout<<"\nAnother object was created\n";
    cout<<" Object 1 counter = "<<obj1->get_i()<<"\n Object 2 counter = "<<obj2->get_i()<<"\n Object 3 counter = "<<obj3->get_i()<<endl;


    //SingleCounter
    cout<<"\n< Singleton >\n";
    SingleCounter& S_Obj = SingleCounter::GetInstance();
    SingleCounter& S_Obj1 = SingleCounter::GetInstance();

    cout<<"object 1: \n";
    S_Obj.IncrementCounter();
    cout << S_Obj.getCount() << endl;
    S_Obj.IncrementCounter();
    cout << S_Obj.getCount() << endl;

    cout<<"object 2: \n";
    S_Obj1.IncrementCounter();
    cout << S_Obj1.getCount() << endl;
    S_Obj1.IncrementCounter();
    cout << S_Obj1.getCount() << endl;
    return 0;
}
