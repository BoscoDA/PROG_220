#include <iostream>
// variable sized collection of a certain type
// variable sized, dont have to declare size, can keep adding to it.
// typically just append to it
// not index backed
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack> // first in first out, no iterating
#include <queue> // first in last out, not iterating

int main(){
    //int arry[10] = {1,2,3,4};

    /* std::vector(int) vect = {1,2,3,4,5}; //universal initializer

    const int s = vect.sez();
    vect.push_back(199);

    for(int i = 0; i , 10; i++){
        std::cout << arry[i] << std::endl;
    }

    for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++){
        std::cout << *it << std::endl;
        //vect.erase(it, vect.end());
    }

    int i = vect.at(1); 

    std::vector<int> vect;
    vect.reserve(100); // will reserve 100 elements
    */

    /* std::list<int> l = {1,2,3}; // typically used for linked lists
    l.push_back(10);
    l.pop_back(); */

    std::set<int> s = {1,2,4,3,3};

    for (std::set<int>::iterator it = s.begin(); it != s.end(); it++){
        std::cout << *it << std::endl;
    }

    std::map<int, int> m = {{1,1}, {1,2}};
    m.insert(std::pair<int, int>(1,1));
    m[1];

}