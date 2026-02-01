#include <bits/stdc++.h>
using namespace std;

class Talkable;
class Walkable;
class Flyable;


// dumb main class of robot
class Robot {
    public: 
        Talkable* t;
        Walkable* w;
        Flyable* f;
    
        Robot(Talkable* t ,Walkable* w, Flyable* f) {
            this->t = t;
            this->w = w;
            this->f = f;
        }
        virtual void projection() = 0;
};

class AMR : public Robot {
    public: 
        AMR(Talkable* t, Walkable* w, Flyable* f) : Robot(t, w, f) {}
        void projection() {
            cout<<"I am AMR robot and this is my projection."<<endl;
        }
};

class Talkable {
    public: 
        virtual void talk() = 0;
};

class Walkable {
    public: 
        virtual void walk() = 0;
};

class Flyable {
    public: 
        virtual void fly() = 0;
};

class normalTalk : public Talkable {
    public: 
        void talk() {
            cout<<"I talk normally."<<endl;
        }
};

class noTalk : public Talkable {
    public: 
        void talk() {
            cout<<"I dont talk."<<endl;
        }
};

class normalWalk : public Walkable {
    public: 
        void walk() {
            cout<<"I walk normally."<<endl;
        }
};

class noWalk : public Walkable {
    public: 
        void walk() {
            cout<<"I dont walk."<<endl;
        }
};

class normalFly : public Flyable {
    public: 
        void fly() {
            cout<<"I fly normally."<<endl;
        }
};

class noFly : public Flyable {
    public: 
        void fly() {
            cout<<"I dont fly."<<endl;
        }
};

int main() {
    Robot* MAGAMR = new AMR(
        new normalTalk(),
        new normalWalk(),
        new noFly()
    );
    
    MAGAMR->projection();
    MAGAMR->t->talk();
    MAGAMR->w->walk();
    MAGAMR->f->fly();
    
    return 0;
}
