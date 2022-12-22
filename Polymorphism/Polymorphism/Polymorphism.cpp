#include <iostream>
#include <vector>
#include <ctime>

//Assessed workshop week 11 

using namespace std;

class Animal
{
    public:
        virtual void speak(void) = 0;
};

class Sheep : public Animal
{
    public:
        void speak(void)
        {
            cout << "Sheep says: \t\tbaa!" << endl;
        }
};

class Cow : public Animal
{
public:
    void speak(void)
    {
        cout << "Cow says: \t\tmoo!" << endl;
    }
};

class Frisian : public Cow
{
    public:
        void speak(void)
        {
            cout << "Frisian Cow says: \tmoo (in black and white)!" << endl; 
        }
};

int main()
{

    vector <Animal*> container; 

    cout << "Welcome to the Animal farm" << endl; 
    cout << "How many animals would you like on your farm?" << endl; 
    int numb;
    cin >> numb;

    int i = 0;
    srand(time(0));

    while (i++ < numb)
    {
        int numbgen = rand() % 3; 
        if (numbgen == 0)
        {
            container.push_back(new Sheep());
        }
        if (numbgen == 1)
        {
            container.push_back(new Cow());
        }
        if (numbgen == 2)
        {
            container.push_back(new Frisian());
        }   
    }

    for (int a = 0; a < container.size(); a++)
    {
        container[a]->speak();
        delete container[a];
    }

    return 0;
}

