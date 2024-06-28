#include <iostream>
#include <string>

// Abstract base class for users
class User
{
protected:
    std::string username;
    std::string password;

public:
    User(const std::string &username, const std::string &password)
        : username(username), password(password) {}

    virtual void authenticate(const std::string &passwordAttempt) const = 0;
};

// Concrete class representing regular users
class RegularUser : public User
{
public:
    RegularUser(const std::string &username, const std::string &password)
        : User(username, password) {}

    void authenticate(const std::string &passwordAttempt) const override
    {
        if (password == passwordAttempt)
        {
            std::cout << "User '" << username << "' successfully authenticated." << std::endl;
        }
        else
        {
            std::cout << "Authentication failed for user '" << username << "'." << std::endl;
        }
    }

    void postContent(const std::string &content) const
    {
        std::cout << "Regular user '" << username << "' posted content: " << content << std::endl;
    }

    void likePost(const std::string &postId) const
    {
        std::cout << "Regular user '" << username << "' liked post with ID: " << postId << std::endl;
    }

    void commentOnPost(const std::string &postId, const std::string &comment) const
    {
        std::cout << "Regular user '" << username << "' commented on post with ID: " << postId << std::endl;
        std::cout << "Comment: " << comment << std::endl;
    }
};

// Concrete class representing admins
class Admin : public User
{
public:
    Admin(const std::string &username, const std::string &password) : User(username, password) {}

    void authenticate(const std::string &passwordAttempt) const override
    {
        if (password == passwordAttempt)
        {
            std::cout << "Admin '" << username << "' successfully authenticated." << std::endl;
        }
        else
        {
            std::cout << "Authentication failed for admin '" << username << "'." << std::endl;
        }
    }

    void deletePost(const std::string &postId) const
    {
        std::cout << "Admin '" << username << "' deleted post with ID: " << postId << std::endl;
    }
};

int main()
{
    RegularUser regularUser("johnDoe", "password123");
    Admin admin("adminUser", "adminPassword");

    regularUser.authenticate("password123");
    regularUser.postContent("Hello, everyone!");
    regularUser.likePost("123456");
    regularUser.commentOnPost("123456", "Great post!");

    std::cout << std::endl;

    admin.authenticate("adminPassword");
    admin.deletePost("987654");

    return 0;
}
