#include <bits/stdc++.h>
using namespace std;

class Singleton {
    public: 
        inline static Singleton* instance = nullptr;
        inline static mutex mtx;
        
        static Singleton* getInstance() {
            lock_guard<mutex>lock(mtx);
            if (instance == nullptr) {
                instance = new Singleton();
            }
            return instance;
        }
    private: 
        Singleton() {
            cout<<"Object created"<<endl; 
        }
        ~Singleton() {
            cout<<"object destroyed"<<endl;
        }
};


int main() {
    Singleton *obj1 = Singleton::getInstance();
    Singleton *obj2 = Singleton::getInstance();

    cout<< "Equality " << (obj1==obj2)<< endl;

    return 0;
}
