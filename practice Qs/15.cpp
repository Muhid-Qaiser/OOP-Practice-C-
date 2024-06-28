#include <iostream>
#include <string>
using namespace std;

// Forward declaration
class Post;

// Represents a user's account
class User
{
private:
    string username;
    string password;
    int numPosts;
    Post **posts;
    int maxPosts;

public:
    User(string username, string password, int maxPosts) : username(username), password(password), maxPosts(maxPosts)
    {
        numPosts = 0;
        posts = new Post *[maxPosts];
    }

    ~User()
    {
        delete[] posts;
    }

    string getUsername() const
    {
        return username;
    }

    bool authenticate(string password) const
    {
        return this->password == password;
    }

    void addPost(Post *post)
    {
        if (numPosts < maxPosts)
        {
            posts[numPosts++] = post;
        }
    }

    Post **getPosts() const
    {
        return posts;
    }

    int getNumPosts() const
    {
        return numPosts;
    }
};

// Represents a post on the social media platform
class Post
{
private:
    string text;
    User *author;

public:
    Post(string text, User *author) : text(text), author(author) {}

    string getText() const
    {
        return text;
    }

    User *getAuthor() const
    {
        return author;
    }
};

// Represents the social media platform
class SocialMediaPlatform
{
private:
    User **users;
    int numUsers;
    int maxUsers;

public:
    SocialMediaPlatform(int maxUsers) : maxUsers(maxUsers)
    {
        numUsers = 0;
        users = new User *[maxUsers];
    }

    ~SocialMediaPlatform()
    {
        for (int i = 0; i < numUsers; i++)
        {
            delete users[i];
        }
        delete[] users;
    }

    bool addUser(string username, string password, int maxPosts)
    {
        if (numUsers < maxUsers)
        {
            users[numUsers++] = new User(username, password, maxPosts);
            return true;
        }
        return false;
    }

    User *findUser(string username) const
    {
        for (int i = 0; i < numUsers; i++)
        {
            if (users[i]->getUsername() == username)
            {
                return users[i];
            }
        }
        return nullptr;
    }

    bool authenticateUser(string username, string password) const
    {
        User *user = findUser(username);
        if (user)
        {
            return user->authenticate(password);
        }
        return false;
    }

    void addPost(string text, string authorUsername)
    {
        User *author = findUser(authorUsername);
        if (author)
        {
            Post *post = new Post(text, author);
            author->addPost(post);
        }
    }

    Post **getPosts(string username, int &numPosts) const
    {
        User *user = findUser(username);
        if (user)
        {
            numPosts = user->getNumPosts();
            return user->getPosts();
        }
        numPosts = 0;
        return nullptr;
    }
};

int main()
{
    // Create a social media platform with a maximum capacity of 10 users
    SocialMediaPlatform platform(10);

    // Add some users
    platform.addUser("alice", "password123", 10);
    platform.addUser("bob", "qwerty", 5);
    platform.addUser("charlie", "abc123", 20);

    // Authenticate users
    cout << platform.authenticateUser("alice", "password123") << endl; // should output 1 (true)
    cout << platform.authenticateUser("bob", "wrongpassword") << endl; // should output 0 (false)

    // Add some posts
    platform.addPost("Hello, world!", "alice");
    platform.addPost("I love C++!", "alice");
    platform.addPost("Check out my cool project", "bob");
    platform.addPost("I'm learning to code", "charlie");
    platform.addPost("Just finished my first program!", "charlie");

    // Get posts for a user
    int numPosts = 0;
    Post **posts = platform.getPosts("alice", numPosts);
    cout << "Posts for alice:" << endl;
    for (int i = 0; i < numPosts; i++)
    {
        cout << posts[i]->getText() << endl;
    }

    return 0;
}
