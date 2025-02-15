#include "../test.h"
#include "../../../Domain/Entities/Job/job.h"

void testJobDefaultConstructor() {
    Job job;

    if (job.getId() == EMPTY_DEFAULT_ID && job.getUserName() == EMPTY_DEFAULT_STRING) { cout << "testJobDefaultConstructor passed" << endl; }
    else { cout << "testJobDefaultConstructor failed" << endl; }
}

void testJobParameterizedConstructor() {
    size_t id = 1;
    string userName = "testUser";
    Job job(id, userName);

    if (job.getId() == id && job.getUserName() == userName) { cout << "testJobParameterizedConstructor passed" << endl; }
    else { cout << "testJobParameterizedConstructor failed" << endl; }
}

void testJobSettersAndGetters() {
    Job job;
    size_t id = 2;
    string userName = "newUser";

    job.setId(id);
    job.setUserName(userName);

    if (job.getId() == id && job.getUserName() == userName) { cout << "testJobSettersAndGetters passed" << endl; }
    else { cout << "testJobSettersAndGetters failed" << endl; }
}

void Test::jobTest() {
    testJobDefaultConstructor();
    testJobParameterizedConstructor();
    testJobSettersAndGetters();
}