

#include "produs.h"
#include "monezi.h"
#include "repo.h"
#include "repo_file.h"
#include <cassert>

void test_produs() {
    Produs p1("1", "Cafea", 10);
    Produs p2("2", "Ceai", 50);
    Produs p3("3", "Apa Plata", 5);
    Produs p4("4", "Apa Minerala", 100);
    assert(p1.getCod() == "1");
    assert(p2.getNume() == "Ceai");
    assert(p3.getPret() == 5);
    p4 = p1;
    assert(p4 == p1);

}

void test_repo() {
    Produs p1("1", "Cafea", 10);
    Produs p2("2", "Ceai", 50);
    Produs p3("3", "Apa Plata", 5);
    Produs p4("4", "Apa Minerala", 100);
    Monezi m;
    m.add_moneda(100);
    m.add_moneda(100);
    m.add_moneda(100);
    m.add_moneda(100);
    m.add_moneda(100);
    m.add_moneda(50);
    m.add_moneda(50);
    m.add_moneda(50);
    m.add_moneda(50);
    m.add_moneda(50);
    m.add_moneda(20);
    m.add_moneda(20);
    m.add_moneda(20);
    m.add_moneda(20);
    m.add_moneda(20);
    m.add_moneda(10);
    m.add_moneda(10);
    m.add_moneda(10);
    m.add_moneda(10);
    m.add_moneda(10);
    m.add_moneda(5);
    m.add_moneda(5);
    m.add_moneda(5);
    m.add_moneda(5);
    m.add_moneda(5);
    m.add_moneda(1);
    m.add_moneda(1);
    m.add_moneda(1);
    m.add_moneda(1);
    m.add_moneda(1);
    Repo r;
    r.add_produs(p1);
    r.add_produs(p2);
    r.add_produs(p3);
    r.add_produs(p4);
    r.add_monezi(m);
    assert(r.getsize_monezi()==6);
    assert(r.getsize_produse()==4);


}



void test_monezi() {
    Monezi m;
    m.add_moneda(100);
    m.add_moneda(100);
    m.add_moneda(100);
    m.add_moneda(100);
    m.add_moneda(100);
    m.add_moneda(100);
    m.add_moneda(100);
    m.add_moneda(100);
    m.add_moneda(100);
    m.add_moneda(100);
    m.add_moneda(50);
    m.add_moneda(50);
    m.add_moneda(50);
    m.add_moneda(50);
    m.add_moneda(50);
    m.add_moneda(20);
    m.add_moneda(20);
    m.add_moneda(20);
    m.add_moneda(20);
    m.add_moneda(20);
    m.add_moneda(20);
    m.add_moneda(20);
    m.add_moneda(20);
    m.add_moneda(20);
    m.add_moneda(20);
    m.add_moneda(20);
    m.add_moneda(20);
    m.add_moneda(20);
    m.add_moneda(20);
    m.add_moneda(20);
    m.add_moneda(10);
    m.add_moneda(10);
    m.add_moneda(10);
    m.add_moneda(10);
    m.add_moneda(10);
    m.add_moneda(5);
    m.add_moneda(5);
    m.add_moneda(5);
    m.add_moneda(5);
    m.add_moneda(5);
    m.add_moneda(5);
    m.add_moneda(5);
    m.add_moneda(5);
    m.add_moneda(5);
    m.add_moneda(5);
    m.add_moneda(5);
    m.add_moneda(5);
    m.add_moneda(5);
    m.add_moneda(5);
    m.add_moneda(5);
    m.add_moneda(1);
    m.add_moneda(1);
    m.add_moneda(1);
    m.add_moneda(1);
    m.add_moneda(1);
    m.add_moneda(1);
    m.add_moneda(1);
    m.add_moneda(1);
    m.add_moneda(1);
    m.add_moneda(1);
    m.add_moneda(1);
    m.add_moneda(1);
    m.add_moneda(1);
    m.add_moneda(1);
    m.add_moneda(1);
    assert(m.cap()==6);
    assert(m.getap(100)==10);
    assert(m.getvalue(0)==100);
}

void test_repofile(){

    Repo_File rmonezi("C:\\Users\\silag\\OneDrive\\Documents\\C++ Projects\\Laborator 10 OOP ALA BUN\\monezi.txt","C:\\Users\\silag\\OneDrive\\Documents\\C++ Projects\\Laborator 10 OOP ALA BUN\\cout.txt");
    Repo_File rproduse("C:\\Users\\silag\\OneDrive\\Documents\\C++ Projects\\Laborator 10 OOP ALA BUN\\produse.txt","C:\\Users\\silag\\OneDrive\\Documents\\C++ Projects\\Laborator 10 OOP ALA BUN\\cout.txt");
    assert(rproduse.file_prodsize()==3);
    assert(rmonezi.file_monezisize()==3);
    assert(rmonezi.suma_monezi()==850);

}


void tests() {
    test_produs();
    test_repo();
    test_monezi();
    test_repofile();

}
