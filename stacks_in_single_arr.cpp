#include <iostream>
#include <vector>

using namespace std;

size_t n;     // data array size
size_t m;     // number of stacks

class Stack {
private:
    vector<int> data;   // data[i] = -1 : free    data[i] > 0 : occupied
    vector<int> prev;
    vector<int> topIndex;   // top of each stack;
public:
    Stack(size_t size, size_t top) {
        data.resize(size, -1);
        prev.resize(size);
        topIndex.resize(top, -1);
    }
    
    int findFreeIndex() {
        for(int i = 0; i < data.size(); i++) {
            if(data[i] == -1)
                return i;
        }
        return -1;  //no free index;
    }
    
    void push(int val, int num) {
        int index = findFreeIndex();
        if(index == -1) {
            cout << "stack overflow : increase the size" << endl;
            index = data.size();
            data.push_back(-1);
            prev.push_back(-1);
        }
        data[index] = val;
        prev[index] = topIndex[num];
        topIndex[num] = index;
    }
    
    void pop(int num) {
        int index  = topIndex[num];
        if(index == -1) {
            cout << "stack underflow" << endl;
            return;
        }
        int val = data[index];
        data[index] = -1;
        topIndex[num] = prev[index];
        
        cout << "pop " << val << " from stack #" << num << endl;
        //        free[index] = true;
    }
};

int main() {
    n = 5;
    m = 3;
    // number of stacks to implement int a single data array
    Stack pstack(n , m);
    
    pstack.push(15, 2);
    pstack.push(17, 1);
    pstack.push(11, 0);
    pstack.push(49, 1);
    pstack.push(45, 2);
    pstack.pop(2);
    pstack.push(39, 1);
    pstack.pop(1);
    pstack.pop(1);
    pstack.pop(1);
    pstack.push(9, 0);
    pstack.push(7, 0);
    pstack.pop(2);
    pstack.pop(2);
    
    
    pstack.pop(1);
    pstack.pop(1);
    pstack.pop(1);
    
    pstack.pop(0);
    pstack.pop(0);
}
