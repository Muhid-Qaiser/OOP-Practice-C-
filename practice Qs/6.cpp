#include <iostream>
using namespace std;
#include <ctime>
#include <cstring>

void PrintSticker(char *fileName)
{
    // Assume that this function is already written
    // and it prints GIF according to the filename.
    cout << "(Y)";
}
class DateTime
{
    int Day;
    int Month;
    int Year;
    int Hour;
    int Minutes;

public:
    DateTime(int day = 0, int month = 0, int year = 0, int hour = 0, int mins = 0)
    {
        Day = day;
        Month = month;
        Year = year;
        Hour = hour;
        Minutes = mins;
    }
    void PrintTime()
    {
        cout << Hour << ":" << Minutes << endl;
    }
    static DateTime GetCurrentDateTime()
    {
        // This function returns an object of Current DateTime
        // initialized with the values of Current System Date and Time
        time_t now = time(0);
        tm *ltm = localtime(&now);
        DateTime curr(ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year, ltm->tm_hour, ltm->tm_min);

        return curr;
    }
};
class Message
{
    DateTime RecievedDateTime;

public:
    Message()
    {
        RecievedDateTime = DateTime::GetCurrentDateTime();
    }
    virtual void Print()
    {
        cout << ".....";
        RecievedDateTime.PrintTime();
    }
    virtual ~Message()
    {
        // cout<<"~Message() Called.\n";
    }
};

class TextMessage : public Message
{
    char *Text;

public:
    TextMessage(char *text = "")
    {
        int str_len = strlen(text);
        Text = new char[str_len + 1];
        for (int i = 0; i < str_len; i++)
        {
            Text[i] = text[i];
        }
        Text[str_len] = '\0';
    }
    void Print()
    {
        cout << Text;
        Message::Print();
    }
    ~TextMessage()
    {
        // cout<<"~TextMessage() Called.\n";
        if (Text != 0)
            delete[] Text;
    }
};

class Sticker : public Message
{
    char *fileName;

public:
    Sticker(char *_fileName)
    {
        int str_len = strlen(_fileName);
        fileName = new char[str_len + 1];
        for (int i = 0; i < str_len; i++)
        {
            fileName[i] = _fileName[i];
        }
        fileName[str_len] = '\0';
    }

    void Print()
    {
        PrintSticker(fileName);
        Message::Print();
    }
    ~Sticker()
    {
        // cout<<"~Sticker() Called.\n";
        if (fileName != 0)
        {
            delete[] fileName;
        }
    }
};

class Chat
{
    Message **Messages;
    int NoOfMessages;
    int maxLimit;

public:
    Chat(int n)
    {
        maxLimit = n;
        Messages = new Message *[n];
        NoOfMessages = 0;
    }
    void AddMessage(Message *msg)
    {
        Messages[NoOfMessages++] = msg;
    }
    void PrintAllMessages()
    {
        for (int i = 0; i < NoOfMessages; i++)
            Messages[i]->Print();
    }
    ~Chat()
    {
        // cout<<"~Chat() Called.\n";
        for (int i = 0; i < NoOfMessages; i++)
            delete Messages[i];
        delete[] Messages;
    }
};

int main()
{
    Chat myChat(10); // We can have total 10 messages at max.
    myChat.AddMessage(new TextMessage("Hello"));
    myChat.AddMessage(new TextMessage("Best of Luck for your Exams"));
    myChat.AddMessage(new Sticker("ThumbsUp.gif"));
    myChat.PrintAllMessages();
}