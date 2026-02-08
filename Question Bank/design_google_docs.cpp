#include <bits/stdc++.h>
using namespace std;

class Element {
public:
    virtual void render() = 0;
    virtual ~Element() = default;
};

class Text : public Element {
    string content;
public:
    Text(const string &content) {
        this->content = content;
    }
    void render() {
        cout << "Rendering Text: " << content << endl;
    }
};

class Image : public Element {
    string url;
public:
    Image(const string &url) {
        this->url = url;
    }
    void render() {
        cout << "Rendering Image: url = " << url << endl;
    }
};

class Document {
    vector<Element*> elements;
public: 
    void addElement(Element *element) {
        elements.push_back(element);
    }

    void render() {
        for (auto element: elements) {
            element->render();
        }
    }

    ~Document() {
        // Clean up dynamically allocated elements
        for (auto e : elements) delete e;
    }
};

class Persistence {
public: 
    virtual void save() = 0;
    virtual ~Persistence() = default;
};

class saveToDb : public Persistence {
public:
    void save() {
        cout << "Saving to database" << endl;
    }
}; 

class saveToFile : public Persistence {
public:
    void save() {
        cout << "Saving to file" << endl;
    }
}; 

class DocumentEditor {
    Document *doc;
    Persistence *p;
public:
    DocumentEditor(Document* doc, Persistence* persistence) {
        this->doc = doc;
        this->p = persistence;
    }

    void addText(const string& text) {
        doc->addElement(new Text(text));
    }

    void render() {
        cout << "Rendering document..." << endl;
        doc->render();
    }

    void save() {
        p->save();
    }
};

int main() {
    Document doc;
    saveToFile file;

    DocumentEditor editor(&doc, &file);

    editor.addText("Hello World");
    editor.addText("This is a document editor");
    editor.addText("Text only version");

    editor.render();
    editor.save();

    return 0;
}
