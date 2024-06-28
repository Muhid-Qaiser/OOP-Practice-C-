#include <iostream>
#include <string.h>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

// ! Classes and functions

class Profile
{
    int user_id;
    string username;
    int num_posts;
    string email;
    int followers;
    int likes;
    int comments;
    string password;
    string profilePic;
    struct userActivity
    {
        int posts_num;
        int likes_num;
        int comments_num;
        int followers_num;
    } user1;

public:
    Profile()
    {
        user_id = 0;
        username = "";
        num_posts = 0;
        email = "";
        followers = 0;
        likes = 0;
        comments = 0;
        password = "";
        profilePic = "picture1.jpg";

        user1.comments_num = 0;
        user1.posts_num = 0;
        user1.likes_num = 0;
        user1.followers_num = 0;
    }

    ~Profile()
    {
        cout << "\n\nProfile Has Been Created/Deleted Successfully!" << endl
             << endl
             << "=============================================================" << endl
             << endl;
    }

    Profile(int user_id, string username, string email, string password)
    {
        this->user_id = user_id;
        this->username = username;
        this->email = email;
        this->password = password;
        profilePic = "picture1.jpg";
        comments = 0;
        num_posts = 0;
        followers = 0;
        likes = 0;

        user1.comments_num = 0;
        user1.posts_num = 0;
        user1.likes_num = 0;
        user1.followers_num = 0;
    }

    bool validateEmail() const
    {
        int size = 0;

        bool check = false;

        string check_domain = "";

        for (; email[size] != '\0'; size++)
        {
            if (email[size] == '@')
            {
                check = true;
            }

            else if (check == true)
            {
                check_domain += email[size];
            }
        }

        if (check == true)
        {
            if (check_domain == "gmail.com")
                return true;
            else if (check_domain == "nu.edu.pk")
                return true;
            else if (check_domain == "yahoo.com")
                return true;
            else if (check_domain == "hotmail.com")
                return true;
            else
                return false;
        }

        return false;
    }

    string getPasswordStrength() const
    {
        int uc = 0, lc = 0, digits = 0, special = 0, size = 0, num_chars = 0;

        for (; password[size] != '\0'; size++)
        {
            if (password[size] >= '0' && password[size] <= '9')
                digits++;
            else if (password[size] >= 'a' && password[size] <= 'z')
                lc++;
            else if (password[size] >= 'A' && password[size] <= 'Z')
                uc++;
            else
                special++;
        }

        /*
                cout << "uc : " << uc << endl
                     << "lc : " << lc << endl
                     << "special : " << special << endl
                     << "digits : " << digits << endl
                     << "size : " << size << endl;
        */

        if (uc > 0 && lc > 0 && digits > 2 && special > 0 && size >= 10 && lc + uc >= 5)
            return "Strong";

        else if (lc > 0 && digits > 0 && size >= 8 && lc + uc >= 4)
            return "Medium";

        else
            return "Weak";
    }

    double getProfileCompletionPercentage()
    {
        double percentage = 0.0;

        if (getPasswordStrength() == "Strong")
        {
            //  cout << "inp\n";
            percentage += 20.0;
        }
        else if (getPasswordStrength() == "Medium")
            percentage += 10.0;
        else if (getPasswordStrength() == "Weak")
            percentage += 5.0;

        if (followers > 1000)
        {
            //  cout << "inFOL\n";
            percentage += 20.0;
        }
        else if (followers > 500)
            percentage += 10.0;
        else if (followers > 100)
            percentage += 5.0;

        if (validateEmail() == true)
        {
            //  cout << "inem\n";
            percentage += 5.0;
        }

        if (likes > 100000)
        {
            //  cout << "inlik\n";
            percentage += 15.0;
        }
        else if (likes > 10000)
            percentage += 10.0;
        else if (likes > 1000)
            percentage += 5.0;

        if (comments > 1000)
        {
            //  cout << "incom\n";
            percentage += 15.0;
        }
        else if (comments > 500)
            percentage += 10.0;
        else if (comments > 100)
            percentage += 5.0;

        if (num_posts > 100)
        {
            //  cout << "inpos\n";
            percentage += 10.0;
        }
        else if (num_posts > 50)
            percentage += 5.0;
        else if (num_posts > 10)
            percentage += 0;

        if (user_id >= 0)
        {
            //  cout << "inid\n";
            percentage += 2.5;
        }

        if (username != "" || username != "\0")
        {
            // cout << "inusnam\n";
            percentage += 2.5;
        }

        if (validateProfilePicPath())
            percentage += 10;

        return percentage;
    }

    userActivity getUserActivity()
    {
        // ? Method 1
        /*
        cout << "Number of Posts : " << num_posts << endl
             << " Number of Followers : " << followers << endl
             << " Number of Likes : " << likes << endl
             << " Number of Comments : " << comments << endl;
        */

        // ? Method 2
        user1.comments_num = comments;
        user1.posts_num = num_posts;
        user1.likes_num = likes;
        user1.followers_num = followers;

        return user1;
    }

    void displayUserActivity()
    {
        cout << "\nUser Activity\n----------------------------\n"
             << "Number of Posts : " << user1.posts_num << endl
             << "Number of Followers : " << user1.followers_num << endl
             << "Number of Likes : " << user1.likes_num << endl
             << "Number of Comments : " << user1.comments_num << endl;
    }

    int getPostNum() { return num_posts; }

    int getuserID() { return user_id; }

    string getuserName() { return username; }

    string getEmail() { return email; }

    int getFollowers() { return followers; }

    int getLikes() { return likes; }

    int getComments() { return comments; }

    string getPassword() { return password; }

    string getProfilePicPath() { return profilePic; }

    void setUserName()
    {
        cout << "Enter User Name :";
        cin.ignore();
        if (getline(cin, username))
            cout << "\nUser Name Successfully Updated" << endl;
        else
            cout << "\nUser Name Was Not Successfully Updated" << endl;
    }

    void setUserID()
    {
        cout << "Enter User ID :";

        if ((cin >> user_id))
            cout << "\nUser ID Successfully Updated" << endl;
        else
            cout << "\nUser ID Was Not Successfully Updated" << endl;
    }

    void setEmail()
    {
        cout << "Enter Email Address :";

        cin.ignore();

        getline(cin, email);

        while (!validateEmail())
        {
            cout << "\nInCorrect Email Address!" << endl
                 << "Try again" << endl
                 << "Enter : ";
            getline(cin, email);
        }

        cout << "\nEmail Address Successfully Updated" << endl;
        /*
                if (getline(cin, email))
                else
                    cout << "\nEmail Address Was Not Successfully Updated" << endl;
        */
    }

    void setPassword()
    {
        cout << "Enter Password :";

        cin.ignore();

        if (getline(cin, password))
            cout << "\nPassword Successfully Updated" << endl;
        else
            cout << "\nPassword Was Not Successfully Updated" << endl;
    }

    void setComments()
    {
        cout << "Enter Number of Comments :";

        if ((cin >> comments))
            cout << "\nNumber of Comments Successfully Updated" << endl;
        else
            cout << "\nNumber of Comments Was Not Successfully Updated" << endl;
    }

    void setFollowers()
    {
        cout << "Enter Number of Followers :";

        if ((cin >> followers))
            cout << "\nNumber of Followers Successfully Updated" << endl;
        else
            cout << "\nNumber of Followers Was Not Successfully Updated" << endl;
    }

    void setLikes()
    {
        cout << "Enter Number of Likes :";

        if ((cin >> likes))
            cout << "\nNumber of Likes Successfully Updated" << endl;
        else
            cout << "\nNumber of Likes Was Not Successfully Updated" << endl;
    }

    void setPostNum()
    {
        cout << "Enter Number of Posts :";

        if ((cin >> num_posts))
            cout << "\nNumber of Posts Successfully Updated" << endl;
        else
            cout << "\nNumber of Posts Was Not Successfully Updated" << endl;
    }

    bool validateProfilePicPath()
    {

        ifstream file(profilePic);

        if (file.good())
            return true;
        else
            return false;
    }

    void setProfilePic()
    {
        char choice = '\0';
        bool checker = 0;

        do
        {
            cin.ignore();

            if (checker == 1)
                cout << "\nInvalid Entry!" << endl
                     << "Try Again!" << endl
                     << endl;
            do
            {
                cout << "\n1. Picture 1 " << endl
                     << "2. Picture 2 " << endl
                     << "3. Picture 3 " << endl
                     << "4. New Picture" << endl
                     << endl
                     << "Enter choice : ";
                cin >> choice;
            } while (!(choice >= '1' && choice <= '4'));

            switch (choice)
            {
            case '1':
                profilePic = "picture1.jpg";
                cout << "\nNew Profile Picture has been Updated Successfully" << endl;
                break;
            case '2':
                profilePic = "picture2.png";
                cout << "\nNew Profile Picture has been Updated Successfully" << endl;
                break;
            case '3':
                profilePic = "picture3.png";
                cout << "\nNew Profile Picture has been Updated Successfully" << endl;
                break;
            case '4':
                cout << "Enter New Profile Picture Path : ";
                cin >> profilePic;
                break;

            default:
                break;
            }

            checker = 1;
            cout << "\nChecking Validity of Path..." << endl;

        } while (!validateProfilePicPath());

        cout << "\nNew Profile Picture has been Updated Successfully" << endl;
    }

    void editProfile()
    {
        int choice = 0;

        do
        {

            cout << "Edit Profile" << endl
                 << "-------------------------------" << endl
                 << endl
                 << "1. User Name" << endl
                 << "2. User ID" << endl
                 << "3. Email Address" << endl
                 << "4. Password" << endl
                 << "5. Posts" << endl
                 << "6. Likes" << endl
                 << "7. Comments" << endl
                 << "8. Followers" << endl
                 << "9. Profile Picture" << endl
                 << "0. Exit" << endl
                 << endl
                 << "Enter Choice : ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                setUserName();
                break;
            case 2:
                setUserID();
                break;
            case 3:
                setEmail();
                break;
            case 4:
                setPassword();
                break;
            case 5:
                setPostNum();
                break;
            case 6:
                setLikes();
                break;
            case 7:
                setComments();
                break;
            case 8:
                setFollowers();
                break;
            case 9:
                setProfilePic();
            case 0:
                cout << "\nExiting..." << endl;
                break;

            default:
                cout
                    << "\nError 404\n";
                break;
            }

        } while (choice);
    }
};

// ! Main

int main()
{
    cout << "\nProfile Managing System" << endl
         << "=============================================================" << endl
         << endl;

    Profile p1(101, "joe", "mommy@nu.edu.pk", "werDFfxc@2453");

    if (p1.validateProfilePicPath())
        cout << "Profile Picture path is Valid\n";
    else
        cout << "Profile Picture path is Invalid\n";

    if (p1.validateEmail())
        cout << "\nEmail is Valid\n\n";
    else
        cout << "\nEmail is Invalid\n\n";

    p1.editProfile();
    p1.getUserActivity();
    p1.displayUserActivity();

    cout << "\nEmail : " << p1.getEmail()
         << "\nUser ID : " << p1.getuserID()
         << "\nPassword : " << p1.getPassword()
         << "\nProfile Pic Path : " << p1.getProfilePicPath()
         << endl;

    cout << "\nPassword : " << p1.getPasswordStrength() << endl
         << "Profile Completetion : " << p1.getProfileCompletionPercentage() << "%\n";

    return 0;
}