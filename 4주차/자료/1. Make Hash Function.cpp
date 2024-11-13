#include <iostream>
#include <unordered_set>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Human
{
    string name;
    int age;
    double height;

    friend bool operator==(const Human& a, const Human& b)
    {
        return a.name == b.name
            && a.age == b.age
            && a.height == b.height;
    }
};

namespace std
{
    template<>
    struct hash<Human>
    {
        size_t operator()(const Human& human) const
        {
            size_t h1 = hash<string>{}(human.name);
            size_t h2 = hash<int>{}(human.age);
            size_t h3 = hash<double>{}(human.height);

            return h1 ^ ((h2 ^ h3 << 1) << 1);
        }
    };
}

struct Earphone
{
    string name;
    int price;

    friend bool operator==(const Earphone& a, const Earphone& b)
    {
        return a.name == b.name
            && a.price == b.price;
    }

    struct Hash
    {
        size_t operator()(const Earphone& earphone) const
        {
            size_t h1 = hash<string>{}(earphone.name);
            size_t h2 = hash<int>{}(earphone.price);

            return h1 ^ (h2 << 1);
        }
    };
};

struct Musician
{
    Human human;
    Earphone earphone;

    friend bool operator==(const Musician& a, const Musician& b)
    {
        return a.human == b.human
            && a.earphone == b.earphone;
    }
};

namespace std
{
    template<>
    struct hash<Musician>
    {
        size_t operator()(const Musician& musician) const
        {
            size_t h1 = hash<Human>{}(musician.human);
            size_t h2 = Earphone::Hash{}(musician.earphone);

            return h1 ^ (h2 << 1);
        }
    };
}

int main()
{
    FastIO;

    unordered_set<Human> humanSet;
    unordered_set<Earphone, Earphone::Hash> earphoneSet;
    unordered_set<Musician> musicianSet;
}