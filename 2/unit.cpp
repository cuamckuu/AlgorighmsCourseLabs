#include "include/unit.h"
#include "include/list.h"

void test_push_back_front() {
    List list;
    list.push_back(1);
    assert(list.size() == 1);

    list.push_front(2);
    assert(list.size() == 2);

    assert(list.at(0) == 2);
    assert(list.at(1) == 1);
}

void test_pop_back_front() {
    List list;
    list.push_back(1);
    list.push_front(1);

    list.pop_front();
    assert(list.size() == 1);

    list.pop_back();
    assert(list.size() == 0);
}

void test_is_empty() {
    List list;

    assert(list.size() == 0);
    assert(list.isEmpty());

    list.push_back(1);
    assert(list.size() == 1);
    assert(!list.isEmpty());
}

void test_remove_head_mid_tail() {
    List list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    assert(list.size() == 4);

    list.remove(0);
    assert(list.size() == 3);

    list.remove(1);
    assert(list.size() == 2);

    list.remove(1);
    assert(list.size() == 1);

    try {
        list.remove(20);
        assert(list.size() == 1);
    } catch (const std::out_of_range &e) {
        //std::cerr << e.what() << "\n";
        return ;
    }

    // Won't be executed because of excption
    assert(false);
}

void test_insert() {
    List list;

    list.insert_before(0, 5);
    assert(list.size() == 1);
    assert(list.at(0) == 5);

    list.insert_before(1, 6);
    assert(list.size() == 2);
    assert(list.at(1) == 6);

    list.insert_before(1, 7);
    assert(list.size() == 3);
    assert(list.at(1) == 7);

    try {
        list.insert_before(20, 8);
        assert(list.size() == 3);
        list.at(20);
    } catch(const std::out_of_range &e) {
        //std::cerr << e.what() << "\n";
        return ;
    }

    // Won't be executed because of excption
    assert(false);
}

void test_at() {
    List list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    assert(list.at(0) == 1);
    assert(list.at(1) == 2);
    assert(list.at(2) == 3);

    try {
        list.at(20);
    } catch (const std::out_of_range &e) {
        //std::cerr << e.what() << "\n";
        return ;
    }

    // Won't be executed because of exception
    assert(false);
}

void test_contains() {
    List a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    List b;
    b.push_back(1);
    b.push_back(2);

    assert(a.contains(b));
    assert(a.contains(a));
    assert(b.contains(b));
    assert(!b.contains(a));
}

void test_set() {
    List list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    assert(list.at(0) == 1);
    assert(list.at(1) == 2);
    assert(list.at(2) == 3);

    list.set(0, 10);
    list.set(1, 20);
    list.set(2, 30);

    assert(list.at(0) == 10);
    assert(list.at(1) == 20);
    assert(list.at(2) == 30);

    try {
        list.set(20, 1);
    } catch (const std::out_of_range &e) {
        //std::cerr << e.what() << "\n";
        return ;
    }

    // Won't be executed because of exception
    assert(false);
}

void test_all() {
    test_push_back_front();
    test_pop_back_front();
    test_is_empty();
    test_remove_head_mid_tail();
    test_insert();
    test_at();
    test_contains();
    test_set();
}
