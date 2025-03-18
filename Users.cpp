#include <iostream>
#include<string>
#include<vector>
using namespace std;
class User {
private:
    int id;
    string name;
    string date;
public:
    int getId() { return id; }
    string getName() { return name; }
    string getDate() { return date; }
    User(int id, string name, string date) {
        this->id = id;
        this->name = name;
        this->date = date;
    }
};
class Admin :User {
private:
    string rules;
public:
    string getRules() { return rules; }
    Admin(int id, string name, string date, string rules) :User(id,name,date) {
        this->rules = rules;
    }
};
class Likes {
private:
    User* user;
public:
    User* getUser() { return user; }
    Likes(User* user) {
        this->user = user;
    }
};
class Comments {
private:
    User* user;
    string text;
public:
    User* getUser() { return user; }
    string getText() { return text; }
    Comments(User* user,string text) {
        this->user = user;
        this->text = text;
    }
};
class Post {
private:
    vector<Likes> likes;
    vector<Comments> comments;
    vector<User> users;
public:
    Post(vector<Likes> likes, vector<Comments> comments, vector<User> users) {
        this->likes = likes;
        this->comments = comments;
        this->users = users;
    }

};
class Communities:public Post {
private:
    vector<Post> posts;
public:
    Communities(vector<Likes> likes, vector<Comments> comments, vector<User> users, vector<Post> posts):Post(likes,comments,users) {
        this->posts = posts;
        
    }
};
int main()
{
    std::cout << "Hello World!\n";
}
