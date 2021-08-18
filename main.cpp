#include <iostream>
#include <conio.h>
#include <string.h>
#include <process.h>

using namespace std;

struct emp
{
    int empno;
    char name[20];
    int sal;
    struct emp *next;
};

typedef struct emp emp;

struct company
{
    emp *head;
    emp *tail;
    char job[20];
    struct company *nptr;
};

typedef struct company comp;
comp *chead, *ctail;


void input(emp *p)
{
    cout << "\n Enter EmpNo. : ";
    cin >> p->empno;
    cout << "\n Enter Name : ";
    cin >> p->name;
    cout << "\n Enter Salary : ";
    cin >> p->sal;

    p->next = NULL;
}

void myadd()
{
    emp *t;
    t = new emp;
    input(t);
    char j[20];
    cout << "\nEnter job: ";
    cin >> j;

    if (chead == NULL)
    {
        comp *tmp;
        tmp = new comp;
        strcpy(tmp->job, j);
        tmp->head = tmp->tail = t;
        tmp->nptr = NULL;
        chead = ctail = tmp;
        return;
    }

    comp *tmp;
    for (tmp = chead; tmp != NULL; tmp = tmp->nptr)
    {
        if (strcmp(j, tmp->job) == 0)
        {
            tmp->tail->next = t;
            tmp->tail = t;
            break;
        }
    }

    if (tmp == NULL)
    {
        comp *tmp;
        tmp = new comp;
        tmp->head = tmp->tail = t;
        strcpy(tmp->job, j);
        tmp->nptr = NULL;
        ctail->nptr = tmp;
        ctail = tmp;
    }
}
                                        /*--------------PRINT-------------*/
void print(emp *p)
{
    cout << "\n Emp no : " << p->empno
         << "\n Name : " << p->name
         << "\n Salary : " << p->sal
         <<"\n";
}

void mylist()
{
    int p;
    emp *t;
    char j[20];

                                        /*--------------LIST EMPTY-------------*/
    if (chead == NULL)
    {
        cout << "\n List is Empty\n";
        return;
    }

    cout << "\n 1. Print one job list\n 2. Print all jobs List \n Enter choice: ";
    cin >> p;

                                        /*---------------PRINT ALL JOBS---------------*/
    if (p == 2)
    {
        comp *tmp;
        for (tmp = chead; tmp != NULL; tmp = tmp->nptr)
        {
            cout << "\n job: " << tmp->job;
            for (t = tmp->head; t != NULL; t = t->next)
                print(t);
        }
    }

                                        /*---------------PRINT ALL JOBS OF A PARTICULAR POSITION-----------*/

    else
    {
        cout << "\nEnter job : ";
        cin >> j;
        comp *tmp;
        for (tmp = chead; tmp != NULL; tmp = tmp->nptr)
        {
            if (strcmp(j, tmp->job) == 0)
            {
                cout << "\n Job : " << tmp->job<<"\n";
                for (t = tmp->head; t != NULL; t = t->next)
                {
                    print(t);

                }
            }

    //--------------INVALID JOB ENTERED----------
            if (tmp == NULL)
                cout << "\nJob not found\n";
        }
    }
}

                                        /*------------DELETE ALL-------------*/
void alldel()
{
    comp *tmp, *t;
    for (tmp = chead; tmp != NULL;)
    {
        cout << "\n Delete job : " << tmp->job;
        t = tmp;
        tmp = tmp->nptr;
        delete t;
    }
}

                                        /*------------DELETE ONE JOB-------------*/
void onejob()
{
    comp *tmp, *m;
    emp *t;
    if (chead == NULL)
    {
        m = chead->nptr;
        delete chead;
        chead = m;
        cout << "\n one job deleted";
        return;
    }
    for (tmp = chead; tmp->nptr != NULL; tmp = tmp->nptr)
    {
        if (tmp->nptr->head == NULL)
        {
            m = tmp->nptr->nptr;
            delete tmp->nptr;
            tmp->nptr = m;
            cout << "\n One element Deleted";
            if (tmp->nptr == NULL)
                ctail = tmp;
            return;
        }
    }
}

                                        /*------------DELETE EMPLOYEE-------------*/

void delemp()
{
    int e;
    comp *tmp;
    emp *t, *m;
    char j[20];
    cout << "\n ENter job for Deletion : ";
    cin >> j;

    for (tmp = chead; tmp != NULL; tmp = tmp->nptr)
    {
        if (strcmp(j, tmp->job) == 0)
        {
            cout << "\n Enter the empno to delete ";
            cin >> e;
            //IF EMPNO OF HEAD IS ENTERED
            if (e == tmp->head->empno)
            {
                t = tmp->head->next;
                delete tmp->head;
                tmp->head=t;
                cout << "\n One Employee Deleted";

            }

            else
            {
                for (t = tmp->head; t->next != NULL; t = t->next)
                {
                    if (e == t->next->empno)
                    {
                    m = t->next->next;
                    delete t->next;
                    t->next = m;
                    cout << "\n One Employee deleted";

                    if (t->next == NULL)
                        tmp->tail = t;
                    break;
                    }
                }
            }
            //EMPLOYEE NO. DOESNOT EXIST
            if (t->next == NULL)
            cout << "\nThis Employee No doesnot exist";
        }
        if (tmp->head == NULL)
        onejob();
    }
    if (tmp->nptr == NULL)
    cout << "\n Entered job is not present";
}



void mydel()
{
    int p;
    if (chead == NULL)
    {
        cout << "\n LIst id empty";
        return;
    }
    cout << "\n 1 Delete for all jobs \n 2 delete Employee No \n Enter choice";
    cin >> p;

    switch (p)
    {
    case 1:
        alldel();
        break;
    case 2:
        delemp();
        break;
    }
}

                                        /* ***************************************************** */
void myins()
{
    char j[20];
    comp *tmp;
    emp *t, *m;
    int f, p;

    if (chead == NULL)
    {
        cout << "\nList is empty";
        return;
    }
    cout << "\n Enter job: ";
    cin >> j;
    for (tmp = chead; tmp != NULL; tmp = tmp->nptr)
    {
        if (strcmp(j, tmp->job) == 0)
        {
            cout << "\nEnter Employee No. to find: ";
            cin >> f;
            if (f == tmp->head->empno)
            {
                cout << "\nEnter Employee to insert: ";
                m = new emp;
                input(m);
                cout << "\n 1 Insert Before \n 2 Insert After \n Enter choice:  ";
                cin >> p;
                if (p == 1)
                {
                    m->next = tmp->head;
                    tmp->head = m;
                }
                else
                {
                    m->next = tmp->head->next;
                    tmp->head->next = m;
                }
                return;
            }

            for (t = tmp->head; t->next != NULL; t = t->next)
            {
                if (f == t->next->empno)
                {
                    cout << "\n Enter Employee to insert : ";
                    m = new emp();
                    input(m);
                    cout << "\n 1 Insert Before \n Insert After \n Enter choice : ";
                    cin >> p;

                    if (p == 1)
                    {
                        m->next = t->next;
                        t->next = m;
                    }
                    else
                    {
                        m->next = t->next->next;
                        t->next->next = m;
                    }

                    if (m->next == NULL)
                        tmp->tail = m;
                    break;
                }
            }

            //EMPLOYEE NOT PRESENT
            if (t->next == NULL)
                cout << "\n Employee No. is not present ";
        }
    }
    //JOB NOT PRESENT
    if (tmp->nptr == NULL)
        cout << "\n Job is not present in the list";
}



int main()
{
    int ch;
    chead =ctail= NULL;

    while (1)
    {
        cout << "\nPress: \n    1> add \n    2> list \n    3> Delete \n    4> insert \n    5> exit \n Enter choice:";
        cin >> ch;
        cout <<"\n";

        switch (ch)
        {
        case 1:
            myadd();
            break;
        case 2:
            mylist();
            break;
        case 3:
            mydel();
            break;
        case 4:
            myins();
            break;
        case 5:
            exit(1);
        default :
            cout<<"INVALID INPUT";
        }
    }
    return 0;
}
