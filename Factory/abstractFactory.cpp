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

// interface
class GarlicBread {
    public:
        virtual void prepare() = 0;
};

// concrete classes
class VegGarlicBread : public GarlicBread {
    public:
        void prepare() {
            cout<<"Made Veg Garlic bread"<<endl;
        }
};

// concrete classes
class ChickenGarlicBread : public GarlicBread {
    public:
        void prepare() {
            cout<<"Made Chicken Garlic Bread"<<endl;
        }
};

// concrete classes
class VegWheatGarlicBread : public GarlicBread {
    public:
        void prepare() {
            cout<<"Made Veg Garlic bread with wheat base"<<endl;
        }
};

// concrete classes
class ChickenWheatGarlicBread : public GarlicBread {
    public:
        void prepare() {
            cout<<"Made Chicken Garlic Bread with wheat base"<<endl;
        }
};

// abstract factory
class BurgerFactory {
    public:
        virtual Burger* createBurger(string type) = 0;
        virtual GarlicBread* createGarlicBread(string type) = 0;
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
        
        GarlicBread* createGarlicBread(string type) {
            if (type == "veg") {
                return new VegGarlicBread();
            } else if (type == "chicken") {
                return new ChickenGarlicBread();
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
        
        GarlicBread* createGarlicBread(string type) {
            if (type == "veg") {
                return new VegWheatGarlicBread();
            } else if (type == "chicken") {
                return new ChickenWheatGarlicBread();
            } else {
                cout << "Wrong burger type" << endl;
                return nullptr;
            }
        }
};

int main() {
    BurgerFactory* factory = new SinghBurger();
    Burger* burger = factory->createBurger("veg");
    GarlicBread* garlicbread = factory->createGarlicBread("veg");

    if (burger && garlicbread) {
        burger->prepare();
        garlicbread->prepare();
        delete burger;
        delete garlicbread;
    }

    return 0;
}
