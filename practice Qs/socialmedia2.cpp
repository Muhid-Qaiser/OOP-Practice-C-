#include <iostream>
#include <string>
using namespace std;

class Posts
{
protected:
    string comment;
    int likes;
    int id;
    string caption;

public:
    Posts(string caption, int id) : caption(caption), id(id), likes(0) {}
    Posts(string comment, int likes, int id, string caption) : comment(comment), likes(likes), id(id), caption(caption) {}
    virtual ~Posts() {}
    virtual void display() = 0;
    void addLike()
    {
        likes++;
    }
    void addComment(string com)
    {
        comment = com;
    }
};

class Picture : public Posts
{
    string picture;

public:
    Picture(string caption, int id, string picture) : Posts(caption, id), picture(picture) {}
    Picture(string comment, int likes, int id, string caption, string picture) : Posts(comment, likes, id, caption), picture(picture) {}
    void display()
    {
        cout << "\nPost Type : Picture " << endl
             << "Picture ID : " << id << endl
             << "Picture : " << picture << endl
             << "Caption : " << caption << endl
             << "Likes : " << likes << endl
             << "Comment : " << comment << endl;
    }
};

class Video : public Posts
{
    float time;

public:
    Video(string caption, int id, float time) : Posts(caption, id), time(time) {}
    Video(string comment, int likes, int id, string caption, float time) : Posts(comment, likes, id, caption), time(time) {}
    void display()
    {
        cout << "\nPost Type : Video " << endl
             << "Video ID : " << id << endl
             << "Video length: " << time << " seconds" << endl
             << "Caption : " << caption << endl
             << "Likes : " << likes << endl
             << "Comment : " << comment << endl;
    }
};

class UserProfile
{
private:
    string name;
    string password;
    Posts **posts;
    int postCount;

public:
    UserProfile() {}
    UserProfile(const string &name, const string &password) : name(name), password(password), posts(nullptr), postCount(0) {}

    void createPost(Posts *post)
    {
        // Add the post to the user's profile
        Posts **newPosts = new Posts *[postCount + 1];
        for (int i = 0; i < postCount; i++)
        {
            newPosts[i] = posts[i];
        }
        newPosts[postCount] = post;
        postCount++;
        // Deallocate the previous posts array
        delete[] posts;
        // Assign the new posts array
        posts = newPosts;
    }

    void displayPosts()
    {
        if (postCount == 0)
        {
            cout << "No posts found." << endl;
            return;
        }

        cout << "Posts by " << name << ":" << endl;
        for (int i = 0; i < postCount; i++)
        {
            cout << "\nPost " << i + 1 << "\n";
            posts[i]->display();
        }
    }

    bool authenticate(const string &check) const
    {
        if (password == check)
        {
            cout << "\n"
                 << name << " has been successfully authenticated.\n";
            return true;
        }
        else
        {
            cout << "\nIncorrect password!\n";
            return false;
        }
    }

    void likePost(UserProfile **users, int index, int count)
    {
        int choice = 0, choice2 = 0;

        for (int i = 0; i < count; i++)
        {
            if (i == index)
                continue;

            cout << "User Page : " << i << endl;

            users[i]->display();
        }
        cout << "\nChoose User Page : ";
        cin >> choice;

        for (int i = 0; i < users[choice]->postCount; i++)
        {
            cout << "\nPost : " << i + 1 << endl;
            users[choice]->posts[i]->display();
        }
        cout << "\nChoose Post to Like : ";
        cin >> choice2;
        choice2--;

        users[choice]->posts[choice2]->addLike();
    }

    void commentPost(UserProfile **users, int index, int count)
    {
        int choice = 0, choice2 = 0;
        string com;

        for (int i = 0; i < count; i++)
        {
            if (i == index)
                continue;

            cout << "User Page : " << i << endl;

            users[i]->display();
        }
        cout << "\nChoose User Page : ";
        cin >> choice;

        for (int i = 0; i < users[choice]->postCount; i++)
        {
            cout << "\nPost : " << i + 1 << endl;
            users[choice]->posts[i]->display();
        }
        cout << "\nChoose Post to Like : ";
        cin >> choice2;
        choice2--;

        cout << "\nEnter Comment : ";
        cin.ignore();
        getline(cin, com);

        users[choice]->posts[choice2]->addComment(com);
    }

    void display()
    {
        cout << "\nName : " << name << endl;
        cout << "Number of Posts : " << postCount << endl;
    }

    void deletePost(int index)
    {
        for (int i = index; i < postCount; i++)
        {
            posts[i] = posts[i + 1];
        }
        postCount--;
    }

    int getPosts()
    {
        return postCount;
    }
};

class Admin
{
    string name;
    string password;

public:
    Admin(string name, string password) : name(name), password(password) {}
    void viewUsers(UserProfile **users, int count)
    {
        for (int i = 0; i < count; i++)
        {
            cout << "\nUser" << i + 1 << " : \n";
            users[i]->display();
        }
    }
    void deleteUsers(UserProfile **users, int &count)
    {
        int choice = 0;
        for (int i = 0; i < count; i++)
        {
            cout << "\nUser" << i + 1 << " : \n";
            users[i]->display();
        }
        cout << "\nChoose user to delete : ";
        cin >> choice;
        choice--;

        for (int i = 0; i < count; i++)
        {
            if (i == choice)
            {
                delete users[choice];
                users[choice] = NULL;
                for (int j = i; j < count; j++)
                {
                    users[j] = users[j + 1];
                }
                count--;
                break;
            }
        }
    }
    void viewPosts(UserProfile **users, int count)
    {
        for (int i = 0; i < count; i++)
        {
            cout << "\nUser" << i + 1 << " : \n";
            users[i]->displayPosts();
        }
    }
    void deletePosts(UserProfile **users, int count)
    {
        int choice = 0, choice2 = 0;

        viewUsers(users, count);
        cout << "\nEnter User whose Post to Delete : ";
        cin >> choice2;
        choice2--;

        users[choice2]->displayPosts();

        cout << "\nEnter Post to delete : ";
        cin >> choice;
        choice--;

        for (int i = 0; i < users[choice2]->getPosts(); i++)
        {
            if (i == choice)
            {
                users[choice2]->deletePost(choice);
                break;
            }
        }
    }
    ~Admin() {}
};

int main()
{
    int count = 2;
    UserProfile user("John Doe", "password");

    Posts *post1 = new Picture("I am John", 101, "images/pictures.jpg");
    Posts *post2 = new Video("I am John", 101, 5.25);
    Posts *post3 = new Video("I am Johnny", 108, 5.25);
    Posts *post4 = new Video("I am Johnner", 11, 5.25);
    Posts *post5 = new Video("I am Johnson", 3401, 5.25);

    UserProfile **users = new UserProfile *[2];
    users[0] = new UserProfile("John Doe", "password");
    users[1] = new UserProfile("Ligma bro", "kekeke");
    users[0]->createPost(post1);
    users[1]->createPost(post2);
    users[1]->createPost(post3);
    users[1]->createPost(post4);
    users[1]->createPost(post5);

    // users[0]->likePost(users, 0, count);
    // users[0]->commentPost(users, 0, count);
    // users[0]->displayPosts();
    // cout << endl;
    // users[1]->displayPosts();

    Admin admin("Joe", "Drake");

    // admin.deleteUsers(users, count);
    // admin.viewUsers(users, count);
    admin.deletePosts(users, count);
    cout << "\nDeleted Post\n";
    admin.viewPosts(users, count);
    delete post1;
    delete post2;

    return 0;
}
