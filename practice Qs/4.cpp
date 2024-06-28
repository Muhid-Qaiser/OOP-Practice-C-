#include <iostream>
using namespace std;

class OOPmp;

class song
{
protected:
    string name;
    string lyrics;
    char *str;

public:
    song(string n, string l) : name(n), lyrics(l)
    {
    }
    virtual void display(bool checker = false)
    {
        cout << "\nName : " << name << "\nLyrics : " << lyrics << endl;
    }
};

class mp3 : virtual public song
{
protected:
    string type;

public:
    mp3(string n, string l, string t) : song(n, l), type(t) {}
    void display(bool checker = false)
    {
        cout << "\nName : " << name << "\nLyrics : " << lyrics << "\nType : " << type << endl;
    }
};

class mp4 : virtual public song
{
protected:
    string video;

public:
    mp4() : song("", "")
    {
    }
    mp4(string n, string l, string t) : song(n, l), video(t) {}
    void display(bool checker = false)
    {
        cout << "\nName : " << name << "\nLyrics : " << lyrics << "\nVideo : " << video << endl;
    }
};

class smp4 : virtual public mp4
{
protected:
    string video;

public:
    smp4(string n, string l, string t) : song(n, l), video(t) {}
    void display(bool checker = false)
    {
        if (checker)
        {
            cout << "\nName : " << name << "\nLyrics : " << lyrics << "\nVideo : " << video << endl;
        }
        else
        {
            cout << "\nName : " << name << "\nLyrics : Beep Boop\nVideo : Glitched" << endl;
        }
    }
};

class OOPmp
{
protected:
    song **s;
    int count;
    int total;

public:
    OOPmp(int x) : total(x)
    {
        s = new song *[x];
        count = 0;
    }
    ~OOPmp()
    {
        for (int i = 0; i < count; i++)
        {
            delete s[i];
        }
        delete[] s;
    }
    void add(song *s)
    {
        if (count < total)
        {
            this->s[count++] = s;
        }
    }
    void displayAll()
    {
        for (int i = 0; i < count; i++)
        {
            s[i]->display();
        }
    }
};

int main()
{
    mp3 *s1 = new mp3("Happy", "Because I'm happy...", "pop");
    s1->display();

    mp4 *s2 = new mp4("Not Happy", "No, Because I'm happy...", "A man walking..");
    s2->display();

    smp4 *s3 = new smp4("Born Free", "Born free...", "Different pictures\nappearing on screen...");
    s3->display();

    std::cout << "\nplaylist\n";

    OOPmp myPlayer(3);
    myPlayer.add(s1);
    myPlayer.add(s2);
    myPlayer.add(s3);
    myPlayer.displayAll();

    delete s1;
    delete s2;
    delete s3;

    return 0;
}
