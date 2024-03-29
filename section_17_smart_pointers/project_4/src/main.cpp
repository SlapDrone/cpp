#include <iostream>
#include <vector>
#include <memory>


using namespace std;

class Test {
    private:
        int data;
    public:
        Test(): data{0} {
             cout << "\ttest constructor (" << data << ")" << endl; 
        }
        Test(int data) : data {data} {
            cout << "\tTest constructor (" << data << ")" << endl;
        }
        int get_data() const {return data;}
        ~Test() {cout << "\tTest destructor (" << data << ")" << endl;}
};

void my_deleter(Test *ptr) {
    cout << "\tUsing my custom function deleter" << endl;
    delete ptr;
}


int main() {

    {
        // using a function
        std::shared_ptr<Test> ptr1 {new Test{100}, my_deleter};
    }

    cout << "=========" << endl;

    {
        // using a lambda expression
        std::shared_ptr<Test> ptr2 {new Test{1000}, 
            // lambda expression creates closure object
            [] (Test *ptr) {
                std::cout << "\tcustom lambda deleter" << endl;
                delete ptr;
            }
        };
    }
    return 0;
}