#include <iostream>
#include <string>
using namespace std;

#include "a3_tests.hpp"
#include "a3_binary_search_tree.hpp"

string get_status_str(bool status)
{
    return status ? "Pass" : "Fail";
}

int main()
{
    // PriorityQueueTest pqueue_test;
    BinarySearchTreeTest btree_test;

    // bool pqueue_test1_passed = pqueue_test.test1();
    // bool pqueue_test2_passed = pqueue_test.test2();
    // bool pqueue_test3_passed = pqueue_test.test3();

     bool btree_test1_passed = btree_test.test1();
     bool btree_test2_passed = btree_test.test2();
     bool btree_test3_passed = btree_test.test3();

    // cout << "---Priority Queue Tests---" << endl;
    // cout << "Test1: " << get_status_str(pqueue_test1_passed) << endl;
    // cout << "Test2: " << get_status_str(pqueue_test2_passed) << endl;
    // cout << "Test3: " << get_status_str(pqueue_test3_passed) << endl;
    // cout << endl;
    
     cout << "---Binary Search Tree Tests---" << endl;
     cout << "Test1: " << get_status_str(btree_test1_passed) << endl;
     cout << "Test2: " << get_status_str(btree_test2_passed) << endl;
     cout << "Test3: " << get_status_str(btree_test3_passed) << endl;

    cout << " ------- ========== ----------" << endl;

    BinarySearchTree bst;
    bst.insert(10);
    bst.print();
    cout << endl;
    bst.insert(6);
    bst.print();
    cout << endl;
    bst.insert(12);
    bst.print();
    cout << endl;
    bst.insert(3);
    bst.print();
    cout << endl;
    bst.insert(1);
    bst.print();
    cout << endl;
    bst.insert(7);
    bst.print();
    cout << endl;
    bst.remove(7);
    bst.print();
    cout << endl;
    bst.insert(15);
    bst.print();
    cout << endl;
    bst.insert(13);
    bst.print();
    cout << endl;
    bst.insert(8);
    bst.print();
    cout << endl;
    bst.remove(10);
    bst.print();
    cout << endl;
    bst.remove(8);
    bst.print();
    cout << endl;
    bst.remove(12);
    bst.print();
    cout << endl;
    bst.remove(3);
    bst.print();
    cout << endl;
    bst.remove(13);
    bst.print();
    cout << endl;
    bst.remove(6);
    bst.print();
    cout << endl;
    bst.remove(15);
    bst.print();
    cout << endl;
    system("pause");
}
