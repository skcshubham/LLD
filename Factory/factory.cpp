#include <bits/stdc++.h>
using namespace std;

// interface
class Burger {
    public:
        virtual void prepare() = 0;
};

// concrete classes
class VegBurger : public Burger {
    public:
        void prepare() {
            cout<<"Made Veg Burger"<<endl;
        }
};

// concrete classes
class VegWheatBurger : public Burger {
    public:
        void prepare() {
            cout<<"Made Veg Burger with wheat bun"<<endl;
        }
};

// concrete classes
class ChickenBurger : public Burger {
    public:
        void prepare() {
            cout<<"Made Chicken Burger"<<endl;
        }
};

// concrete classes
class ChickenWheatBurger : public Burger {
    public:
        void prepare() {
            cout<<"Made Chicken Burger with wheat bun"<<endl;
        }
};

// abstract factory
class BurgerFactory {
    public:
        virtual Burger* createBurger(string type) = 0;
};

class SinghBurger : public BurgerFactory {
    public:
        Burger* createBurger(string type) {
            if (type == "veg") {
                return new VegBurger();
            } else if (type == "chicken") {
                return new ChickenBurger();
            } else {
                cout << "Wrong burger type" << endl;
                return nullptr;
            }
        }
};

class KingBurger : public BurgerFactory {
    public:
        Burger* createBurger(string type) {
            if (type == "veg") {
                return new VegWheatBurger();
            } else if (type == "chicken") {
                return new ChickenWheatBurger();
            } else {
                cout << "Wrong burger type" << endl;
                return nullptr;
            }
        }
};



int main() {
    BurgerFactory* factory = new SinghBurger();
    Burger* burger = factory->createBurger("veg");

    if (burger) {
        burger->prepare();
        delete burger;
    }

    return 0;
}
