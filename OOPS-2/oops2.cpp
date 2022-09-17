#include <iostream>

using namespace std;

class Human
{
public:
    int weight;
    void setWeight(int weight){
        this->weight=weight;
    }
    void sleep(){
        cout<<"Human sleeping"<<endl;
    }
};

class Male{ // : public Human
public:
    string color;
    void sleep(){
        cout<<"Male sleeping"<<endl;
    }
};

class Female: public Human, public Male{
public:
    void operator+(Female &obj){
        int val1=obj.weight;
        int val2=this->weight;
        cout<<val2+val1<<endl;
    }
};

int main()
{
    // cout<<"Single level Inheritence"<<endl<<endl;
    // Male boy;
    // boy.setWeight(50);
    // cout<<boy.weight;

    cout<<"Inheritence ambiguity tackled with scope resolution operator\n\n";
    Female moti,choti;
    // moti.sleep(); error: request for member 'sleep' is ambiguous moti.sleep();

    moti.Human::sleep();
    moti.Male::sleep();
    cout<<"\n\n";

    cout<<"operator + overloading\n";
    moti.setWeight(10);
    choti.setWeight(15);
    moti+choti;


    return 0;
}