#include <bits/stdc++.h>
using namespace std;

class User {
    private:
        string name;
        int age;
        long long phone;
        string address;
        
        // private constructor
        User() {}
        
        friend class UserBuilder;
    
    public:
        void show() const {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Phone: " << phone << endl;
            cout << "Address: " << address << endl;
        }
};

class UserBuilder {
    private:
        User user;
    
    public:
        UserBuilder& setName(const string& name) {
            user.name = name;
            return *this;
        }
        
        UserBuilder& setAge(const int& age) {
            user.age = age;
            return *this;
        }
        
        UserBuilder& setPhone(const long long& phone) {
            user.phone = phone;
            return *this;
        }
        
        UserBuilder& setAddress(const string& address) {
            user.address = address;
            return *this;
        }
        
        User build() {
            // run validation
            if (user.name.empty()) {
                throw runtime_error("Name is mandatory!");
            }
            // after validation return user
            return user;
        }
};

int main() {
    User shubham = UserBuilder()
                    .setName("Shubham")
                    .setAge(26)
                    .setPhone(9999999999)
                    .setAddress("Bangalore")
                    .build();
    
    shubham.show();
    return 0;
}
