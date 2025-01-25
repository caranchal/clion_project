#include <iostream>
using namespace std;

struct item {
    int d = 0;
    item* p = nullptr;
    item* n = nullptr;
};

struct mlist {
    item* s = nullptr;
    item* e = nullptr;
    item* c = nullptr;

};

void ToStart(mlist& list) 
{
    list.c = list.s;
}
void ToEnd(mlist& list) 
{
    list.c = list.e;
}
bool ToNext(mlist& list) 
{
    
    return (list.c && list.c->n)? list.c = list.c->n:false;
    
}
bool ToPrev(mlist& list) 
{

    return (list.c && list.c->p) ? list.c = list.c->p : false;

}
void InsertAfter(mlist& list, int d)
{
    item* n = new item;
    n->d = d;
    if (!list.c)
        ToStart(list);
    if (!list.c)
        ToEnd(list);
    if (!list.c) 
        list.s = list.e = list.c = n;
    else {
        if (list.c->n)
            list.c->n->p = n;
        n->n = list.c->n;
        list.c->n = n;
        n->p = list.c; 
        if (!n->n)
            list.e = n;
    }
    
}

void ShowList(mlist& list) 
{
    system("cls");
    cout << "LIST:\n";
    item* t = list.s;
    cout << "null->";
    while (t) 
    {
        if (t == list.c)
            cout << "[";
        cout << t->d;
        if (t == list.c)
            cout << "]";
        cout << "->";
        t = t->n;
    }
    cout << "null\n";
}

void Delete(mlist& list) 
{
    item* t = list.c;
    if (t)
    {
        if (t->n)
        {
            list.c = t->n;
            t->n->p = t->p;
            if (t->p)
                t->p->n = t->n;
            if (!list.c->p)
                list.s = list.c;
        }
        else if (t->p) {
            list.c = t->p;
            t->p->n = nullptr;
            list.e = list.c;
        }
        else
            list.s = list.e = list.c = nullptr;
        
        delete t;
    }
}
int main()
{
    mlist list;
    int s = 0;
    do 
    {
        ShowList(list);
        cout << "\nMENU";
        cout << "\n1. START";
        cout << "\n2. END";
        cout << "\n3. NEXT";
        cout << "\n4. PREV";
        cout << "\n5. InsertAfter";
        cout << "\n6. Delete";
        cout << "\nyour turn";
        cin >> s;
        switch (s) {
        case 0:break;
         
        case 1:
            ToStart(list);
            break;
        case 2:
            ToEnd(list);
            break;
           
        case 3:
            ToNext(list);
            break;
        case 4:
            ToPrev(list);
            break;
        case 5:
            cout << "\ninput digit";
            cin >> s;
            InsertAfter(list,s);
            break;

        case 6:
            Delete(list);
            break;
        default:
            break;

        }

    } while (s);
    
}

