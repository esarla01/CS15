/*
 *  unit_tests.h
 *  Tansu Erin Sarlak
 *  Ayse Idil Kolabas
 *  4/22/2022
 *
 *  COMP 15 PROJ 3 GERP
 *
 *  unit testing file:
 *  tests individual classes 
 *  and their functions
 *
 */

#include "stringProcessing.h"
#include "HashElement.h"
#include "HashVector.h"
#include "HashTable.h"
#include "gerp.h"

#include <cstring>
#include <iostream>
#include <cassert>


using namespace std;

// tests: string processing
void stringprocess_test()
{
    // long complex mixed
    assert(stripNonAlphaNum("?!)(#*R)@onal172837!@!#&^%$#d.*&^%$ogr") == "R)@onal172837!@!#&^%$#d.*&^%$ogr");

    // empty
    assert(stripNonAlphaNum("") == "");

    // no alphanumeric
    assert(stripNonAlphaNum("!)&@$^") == "");

    // everything is alphanumeric
    assert(stripNonAlphaNum("everythingisalphanumeric") == "everythingisalphanumeric");

    // lowercase
    assert(stripNonAlphaNum("lowercase_") == "lowercase");
    assert(stripNonAlphaNum("_lowercase") == "lowercase");
    assert(stripNonAlphaNum("low_er_case") == "low_er_case");
    
    // numerals
    assert(stripNonAlphaNum("1numerals1") == "1numerals1");
    assert(stripNonAlphaNum("1numerals") == "1numerals");
    assert(stripNonAlphaNum("numerals1") == "numerals1");
    assert(stripNonAlphaNum("Numerals1") == "Numerals1");
    assert(stripNonAlphaNum("1NumeralS") == "1NumeralS");

    // uppercase 
    assert(stripNonAlphaNum("U_ppercas_E") == "U_ppercas_E");
    assert(stripNonAlphaNum("uppercasE") == "uppercasE");
    assert(stripNonAlphaNum("Uppercase") == "Uppercase");

    // single result
    assert(stripNonAlphaNum("a") == "a");
    assert(stripNonAlphaNum("A") == "A");
    assert(stripNonAlphaNum("1") == "1");
    assert(stripNonAlphaNum("!") == "");
}

// tests: hash key value pair
void hashelement_test_general()
{
    HashElement trial("Erin", 1, "/h/akolab01/cs15");
    trial.print(std::cerr);
    std::cerr << std::endl;
    trial.addLinePath(5, "/h/tsarla02/cs15");
    trial.print(std::cerr);
}

// tests: hash vector forinsert element
void hashvector_test_insert()
{
    HashVector test;
    HashElement trial1("Erin", 1, "/h/tsarla01/cs15");
    HashElement trial2("Cansu", 1, "/h/tsarla02/cs160");
    HashElement trial3("Idil", 1, "/h/akolab01/cs15");
    HashElement trial4("Doga", 1, "/h/akolab01/cs15");
    test.insert_element(trial1);
    test.insert_element(trial2);
    test.insert_element(trial3);
    test.insert_element(trial4);
    test.print(std::cerr);
}

// tests: hash vector elementAt
void hashvector_test_elementAt()
{
    HashVector test;
    HashElement trial1("Erin", 1, "/h/tsarla01/cs15");
    HashElement trial2("Doga", 3, "/h/akolab01/cs15");
    test.insert_element(trial1);
    test.insert_element(trial2);
    HashElement trial;
    trial = test.elementAt(1);
    trial.print(std::cerr);
}


// tests: hash vector for clear
void hashvector_test_clear()
{
    HashVector test;
    HashElement trial1("Erin", 1, "/h/tsarla01/cs15");
    HashElement trial2("Doga", 3, "/h/akolab01/cs15");
    test.insert_element(trial1);
    test.insert_element(trial2);
    test.clear();
    test.print(std::cerr);
}

// tests: hash table  for inserttotable and expandss
// Makes sure that words with the same key are stored in the same hash index.
// Makes sure that when the table size is surpassed the table expands itself.
void table_test_insertotable()
{
    HashTable test;

    HashElement element1("idil", 1, "desktop");
    HashElement element2("idil", 2, "desktop");
    HashElement element3("Idil", 3, "documents");
    HashElement element4("erin", 4, "documents");
    HashElement element5("cansu", 5, "documents");
    HashElement element6("doga", 6, "desktop");
    HashElement element7("doGa", 7, "documents");
    HashElement element8("canSu", 8, "desktop");
    HashElement element9("zoya", 678, "desktop");
    HashElement element10("nurican", 8, "desktop");
    HashElement element11("kennedy", 8, "desktop");
    HashElement element12("sara", 8, "desktop");

    test.inserttotable(element1);
    test.inserttotable(element2);
    test.inserttotable(element4);
    test.inserttotable(element5);
    test.inserttotable(element2);
    test.inserttotable(element3);
    test.inserttotable(element4);
    test.inserttotable(element5);
    test.inserttotable(element6);
    test.inserttotable(element7);
    test.inserttotable(element8);
    test.inserttotable(element9);
    test.inserttotable(element10);
    test.inserttotable(element11);
    test.inserttotable(element12);
   
    test.print(std::cerr);
}


// tests: hash table for clear
void table_test_clear()
{
    HashTable test;

    HashElement element1("idil", 1, "desktop");
    HashElement element2("idil", 2, "desktop");
    HashElement element3("Idil", 3, "documents");
   
    test.inserttotable(element1);
    test.inserttotable(element2);
    test.inserttotable(element3);

    test.clear();
    test.print(std::cerr);
}




