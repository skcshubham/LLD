#include <bits/stdc++.h>
using namespace std;

class ISubscriber;

// Channel Interface
class IChannel {
    public:
        virtual void subscribe (ISubscriber *s) = 0;
        virtual void unsubscribe (ISubscriber *s) = 0;
        virtual void notify () = 0;
};

// subscriber interface
class ISubscriber {
    public:
        virtual void update(const string& videoName) = 0;
};


// concrete class
class Channel : public IChannel {
    public: 
        string name, latestVideo;
        unordered_set <ISubscriber*> subscribers;
        
        Channel(string channelName) : name(channelName) {}
        
        void subscribe (ISubscriber *s) {
            subscribers.insert(s);
        }
        
        void unsubscribe (ISubscriber *s) {
            subscribers.erase(s);
        }
        
        void uploadVideo (string videoName) {
            latestVideo = videoName;
            notify();
        }
        
        void notify () {
            for (auto subscriber : subscribers) {
                subscriber->update(latestVideo);
            }
        }
};

// concrete class
class Subscriber : public ISubscriber {
    public:
        string name;
        
        Subscriber(string subsName) : name(subsName) {};
        
        void update(const string& videoName) {
            cout<<"Hello "<<name<<", Video uploaded : "<<videoName<<endl;
        }
};



int main() {
    Channel* mrBeast = new Channel("MrBeast");
    
    Subscriber* s1 = new Subscriber("Shubham");
    mrBeast->subscribe(s1); 
    
    Subscriber* s2 = new Subscriber("Elon");
    mrBeast->subscribe(s2); 
    
    mrBeast->uploadVideo("Video 1");
    
    return 0;
}
