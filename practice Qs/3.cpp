#include <iostream>

// Forward declaration of OOPMP class
class OOPMP;

// Base class for songs
class Song
{
protected:
    std::string name;
    std::string lyrics;

public:
    Song(const std::string &name, const std::string &lyrics)
        : name(name), lyrics(lyrics) {}

    virtual ~Song() {}

    virtual void play(bool fromPlaylist = false) const
    {
        std::cout << "Currently Playing: " << name << std::endl;
        if (!fromPlaylist)
        {
            std::cout << "LYRICS:" << std::endl;
            std::cout << lyrics << std::endl;
        }
        else
        {
            std::cout << "LYRICS:" << std::endl;
            std::cout << lyrics << std::endl;
        }
        std::cout << std::endl;
    }

    friend class OOPMP;
};

// Derived class for MP3 songs
class MP3 : public Song
{
private:
    std::string type;

public:
    MP3(const std::string &name, const std::string &lyrics, const std::string &type)
        : Song(name, lyrics), type(type) {}

    void play(bool fromPlaylist = false) const override
    {
        std::cout << "Currently Playing: " << name << std::endl;
        if (!fromPlaylist)
        {
            std::cout << "TYPE: " << type << std::endl;
            std::cout << "LYRICS:" << std::endl;
            std::cout << lyrics << std::endl;
        }
        else
        {
            std::cout << "TYPE: " << type << std::endl;
            std::cout << "LYRICS:" << std::endl;
            std::cout << lyrics << std::endl;
        }
        std::cout << std::endl;
    }
};

// Derived class for MP4 songs
class MP4 : public Song
{
protected:
    std::string videoDescription;

public:
    MP4(const std::string &name, const std::string &lyrics, const std::string &videoDescription)
        : Song(name, lyrics), videoDescription(videoDescription) {}

    void play(bool fromPlaylist = false) const override
    {
        std::cout << "Currently Playing: " << name << std::endl;

        // if (fromPlaylist)
        {
            std::cout << "LYRICS:" << std::endl;
            std::cout << lyrics << std::endl;
            std::cout << "VIDEO:" << std::endl;
            std::cout << videoDescription << std::endl;
        }
        std::cout << std::endl;
    }
};

// Derived class for secret MP4 songs
class sMP4 : public MP4
{
public:
    sMP4(const std::string &name, const std::string &lyrics, const std::string &videoDescription)
        : MP4(name, lyrics, videoDescription) {}

    void play(bool fromPlaylist = false) const override
    {
        if (!fromPlaylist)
        {
            std::cout << "Currently Playing: " << name << std::endl;
            std::cout << "LYRICS:" << std::endl;
            std::cout << "bleeeeeeep" << std::endl;
            std::cout << "Video:\nGlitch " << std::endl;
        }
        else
        {
            MP4::play(fromPlaylist);
        }
    }
};

// OOP Music Player class
class OOPMP
{
private:
    Song **playlist;
    int playlistSize;
    int currentSongIndex;

public:
    OOPMP(int size) : playlistSize(size), currentSongIndex(0)
    {
        playlist = new Song *[size];
        for (int i = 0; i < size; ++i)
        {
            playlist[i] = nullptr;
        }
    }

    ~OOPMP()
    {
        for (int i = 0; i < currentSongIndex; ++i)
        {
            delete playlist[i];
        }
        delete[] playlist;
    }

    void addToPlaylist(Song *song)
    {
        if (currentSongIndex < playlistSize)
        {
            playlist[currentSongIndex] = song;
            currentSongIndex++;
        }
    }

    void playAll() const
    {
        for (int i = 0; i < currentSongIndex; ++i)
        {
            playlist[i]->play(true);
        }
    }
};

int main()
{
    MP3 *s1 = new MP3("Happy", "Because I'm happy...", "pop");
    s1->play();

    MP4 *s2 = new MP4("Happy", "Because I'm happy...", "A man walking..");
    s2->play();

    sMP4 *s3 = new sMP4("Born Free", "Born free...", "Different pictures\nappearing on screen...");
    s3->play();

    std::cout << "\nplaylist\n";

    OOPMP myPlayer(3);
    myPlayer.addToPlaylist(s1);
    myPlayer.addToPlaylist(s2);
    myPlayer.addToPlaylist(s3);
    myPlayer.playAll();

    delete s1;
    delete s2;
    delete s3;

    return 0;
}
