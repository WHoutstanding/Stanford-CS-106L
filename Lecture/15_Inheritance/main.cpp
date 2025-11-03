#include <iostream>
#include <string>

using std::cout; using std::endl;

class Drink {
public:
    Drink() = default;
    Drink(std::string flavor) : flavor(flavor) {};

    virtual void make() = 0;
    virtual ~Drink() = default;
    
private:
    std::string flavor;
};

class Tea : public Drink {
public:
    Tea() = default;
    Tea(std::string flavor) : Drink(flavor) {};
    virtual ~Tea() = default;

    void make() {
        cout << "Made tea from the Tea class!" << endl;
    }
};

int main() {
    Tea tea("red");
    tea.make();

    return 0;
}
