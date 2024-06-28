#include <iostream>
using namespace std;

class Player
{
protected:
    char *name;
    int score;
    int ballsPLayed;
    int matchesPLayed;

public:
    Player() {}
    Player(char *name, int s, int bp, int mp) : name(name), score(s), ballsPLayed(bp), matchesPLayed(mp)
    {
    }
    virtual ~Player() {}

    virtual int CalAvg() = 0;
    virtual void display()
    {
        cout << "\nName : " << name << "\n"
             << "Score : " << score << "\n"
             << "Balls Played : " << ballsPLayed << "\n"
             << "MatchesPLayed : " << matchesPLayed << "\n";
    }
};

class Batsman : public Player
{
    char *style;
    int totalscore;
    int noOfTimesBowled;

public:
    Batsman() {}
    Batsman(char *name, int score, int ballsplayed, int matchesplayed, char *style, int ts, int tb) : Player(name, score, ballsplayed, matchesplayed), style(style), totalscore(ts), noOfTimesBowled(tb) {}
    ~Batsman()
    {
    }

    int CalAvg()
    {
        return (totalscore / noOfTimesBowled);
    }
    void display()
    {
        Player::display();
        cout << "Type : Batsman" << endl
             << "Style : " << style << endl
             << "Total Score : " << totalscore << endl
             << "No of Times Bowled : " << noOfTimesBowled << endl;
    }
};

class Bowler : public Player
{
    char *style;
    int totalWickets;
    int totalRunsConceded;

public:
    Bowler() {}
    Bowler(char *name, int score, int ballsplayed, int matchesplayed, char *style, int tw, int tr) : Player(name, score, ballsplayed, matchesplayed), style(style), totalWickets(tw), totalRunsConceded(tr)
    {
    }
    ~Bowler() {}

    int CalAvg()
    {
        return (totalRunsConceded / totalWickets);
    }
    void display()
    {
        Player::display();
        cout << "Type : Bowler" << endl
             << "Style : " << style << endl
             << "Total Wickets : " << totalWickets << endl
             << "Total runs Conceded : " << totalRunsConceded << endl;
    }
};

int main()
{
    Batsman b1("Ali", 23, 160, 5, "Right-Hand", 180, 2);
    b1.display();
    cout << b1.CalAvg() << endl;

    Bowler b2("Sam", 10, 170, 7, "Fast-Bowler", 10, 210);
    b2.display();
    cout << b2.CalAvg() << endl;

    Player **player = new Player *[2];
    player[0] = &b1;
    player[1] = &b2;

    for (int i = 0; i < 2; i++)
    {
        player[i]->display();
        player[i]->CalAvg();
        cout << endl;
    }

    return 0;
}