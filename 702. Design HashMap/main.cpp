#include <iostream>
#include <vector>

using namespace std;


class MyHashMap {
private:
    vector<int> data;
public:
    MyHashMap() {
        data = vector<int>(1000001, -1);
    }

    void put(int key, int value) {
        data[key] = value;
    }
    
    int get(int key) {
        return data[key];
    }
    
    void remove(int key) {
        data[key] = -1;  
    }
};

int main()
{
    return 0;
}