#include <iostream>
using namespace std;
// composition과 aggregation 표현

/*
class Warrior {
public:
    void attack() { cout << "Warrior attacks!" << endl; }
};
class Mage {
public:
    void castSpell() { cout << "Mage casts a spell!" << endl; }
};
// 다중 상속
class BattleMage {
private:
    Warrior warrior;
    Mage mage;
public:
    void attack() { warrior.attack(); }
    void castSpell() { mage.castSpell(); }
};
int main() {
    BattleMage bm;
    bm.attack();
    bm.castSpell();
}
*/

class Warrior {
public:
    void attack() { cout << "Warrior attacks!" << endl; }
};
class Mage {
public:
    void castSpell() { cout << "Mage casts a spell!" << endl; }
};
class BattleMage {
private:
    Warrior& warrior;
    Mage& mage;
public:
    BattleMage(Warrior& w, Mage& m) : warrior(w), mage(m) {};
    void attack() { warrior.attack(); };
    void castSpell() { mage.castSpell(); };
};
int main() {
    Warrior w;
    Mage m;
    BattleMage bm(w, m);
    bm.attack();
    bm.castSpell();