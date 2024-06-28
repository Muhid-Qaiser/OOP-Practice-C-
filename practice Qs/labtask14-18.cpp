#include <iostream>
using namespace std;

// Represents a user's account
class User
{
public:
    string username;
    string password;
    int numPosts;
    Post **posts;
    int maxPosts;
    User(string username, string password, int maxPosts) {}
    ~User() {}

    string getUsername() const {}
    bool authenticate(string password) const {}
    void addPost(Post *post) {}
    Post **getPosts() const {}
    int getNumPosts() const {}
};

// Represents a post on the social media platform
class Post
{
public:
    string text;
    User *author;
    Post(string text, User *author) {}
    string getText() const {}
    User *getAuthor() const {}
};

// Represents the social media platform
class SocialMediaPlatform
{
public:
    User **users;
    int numUsers;
    int maxUsers;
    SocialMediaPlatform(int maxUsers) {}
    ~SocialMediaPlatform() {}
    bool addUser(string username, string password, int maxPosts) {} // check and add if user can be added
    User *findUser(string username) const {}                        // check if user exists, null otherwise
    bool authenticateUser(string username, string password) const {}
    void addPost(string text, string authorUsername) {}      // add post
    Post **getPosts(string username, int &numPosts) const {} // get posts of username
};
int main()
{
    // Create a social media platform with maximum capacity of 10 users
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