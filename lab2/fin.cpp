#include <iostream>
#include <cstring>
#include <utility>
#include <cmath>
#include <bits/stdc++.h>


template<typename T>
T Step(T x, int s){
    //printf("step %d %d\n", x, s);
    T t = x;
    for (int i = 1; i < s; i++)
    {
        x = x * t;
    }
    return x;
}

////////////////////constructors.cpp


//#include "foo.cpp"
using namespace std;
//const int  PASTING_BALANCING = 0;
//#define  PASTING_BALANCING
//#define  DELETING_BALANCE

#define  VAL_TYPE long long int
#define  LETTER_CONST 32
#define  KEY_TYPE string

const int CONSTRUCTORS = 0, TREE_CONSTRUCTORS = 0;
//int SHOW_TREE_IN_BALANCE = 0;
int printhelp = 0;
//написать load и save
//и проверить интерфейс

template <typename T>
struct Node;


template <class T, class T2> 
class mypair{
public:
T first;
T2 second;
mypair(){

}

mypair(T f, T2 s){
    this->first = f;
    this->second = s;

}

mypair(const mypair<T, T2> &s){
    this->first = s.first;
    this->second = s.second;

}


~mypair(){

}


friend ostream& operator<<(ostream& cout, const mypair<T, T2>& p){
    cout<<p.first<<" "<<p.second;
    return cout;
}

bool operator>(const mypair<T, T2> p2){
    return this->first > p2.first;
}

bool operator<(const mypair<T, T2> p2){
    return this->first < p2.first;
}

bool operator==(const mypair<T, T2> p2){
    return (this->first == p2.first);
}

bool operator>=(const mypair<T, T2> p2){
    return this->first >= p2.first;
}

bool operator<=(const mypair<T, T2> p2){
    return this->first <= p2.first;
}

void operator=(mypair<T, T2> p2){
    this->first = p2.first;
    this->second = p2.second;
    return;
}

/* ostream& operator<<(mypair<T, T2> p){
    cout<<p.first<<" "<<p.second;
    return cout;
} */
};


Node<mypair<VAL_TYPE, std::KEY_TYPE>> *root1;

int countletter(std::string s){
    int l = 0;
    int left = 64, right = 123;
if(printhelp ==1)
printf("size = %d\n", s.size());
    for(int i = 0; i< s.size(); i++){
        if(printhelp ==1)
            cout<<"_"<<((int)s[i])<<"_"<<endl;
        if(((int)s[i] < right)&&((int)s[i] > left)){
            ++l;
        }else{
            if(printhelp ==1)
                std::cout<<"not letter \n";
        }
    }
    if(printhelp ==1)
     std::cout<<l<<std::endl;
    return l;
}

//отлаживаю сег фолт уже можно вводить что то
//походу осталось только подогнать вывод под задание чтобы чекер не ругался но я ещё задание на всякий прочту вдруг там ещё что-то

int eq(KEY_TYPE x, KEY_TYPE y){
    if(x.size() != y.size()){
        return 0;
    }
        for (int i = 0; i < x.size(); i++)
        {
            if((x[i] == y[i])||(tolower(x[i]) == y[i])||(tolower(y[i]) == x[i])){
            }else{
                return 0;
            }
        }
        return 1;
}

//////////////rbt.cpp

//#include "constructors.cpp"
//const int CONSTRUCTORS = 0, TREE_CONSTRUCTORS = 0, PASTING_BALANCING = 1, SHOW_TREE_IN_BALANCE = 1, DELETING_BALANCE = 1;
template <typename T>
struct Tree;

template <typename T>
struct Node
{

    Node<T> *l = 0;
    Node<T> *r = 0;
    Node<T> *p = 0;
    T data;
    T *ptr = &data;
    char color = 'b';

    Node()
    {
        this->ptr = new T;
        if (CONSTRUCTORS)
        {

            printf("EmptyConstructed node (%d)\n", this->data);
        }
    }
    Node(Node &n)
    {
        this->ptr = new T;
        this->data = n.data;
        this->l = n.l;
        this->r = n.r;
        this->p = n.p;
        this->color = n.color;
        if (CONSTRUCTORS)
        {
            printf("CopyConstructed node (%d)\n", this->data);
        }
    }
    Node(T t)
    {
        this->ptr = new T;
        this->data = t;
        if (CONSTRUCTORS)
        {
            printf("Constructed node (%d)\n", this->data);
        }
    }

    ~Node()
    {
        if (CONSTRUCTORS)
        {
            cout << p;
            printf("Deleted node (%d)\n", this->data);
        }
        delete this->ptr;
        if (CONSTRUCTORS)
        {
            printf("EndDel node (%d)\n", this->data);
        }
    }

    friend class Tree<T>;
};

template <typename T>
struct Tree
{
    friend class Node<T>;

    Node<T> *root = 0;
    Node<T> *now = this->root;
    int size = 0;
    int levels = 0;

    Tree()
    {
        if (TREE_CONSTRUCTORS)
        {
            printf("Constructed tree (%d)\n", this->size);
        }
    }
    Tree(Tree &tr)
    {
        this->root = tr.root;
        this->size = tr.size;
        this->now = tr.now;
    }

    void operator=(Tree<T> tr){
        this->levels = tr.levels;
        this->root = tr.root;
        this->size = tr.size;
        return;
    }

    void GoL()
    {
        this->now = this->now->l;
        return;
    }

    void GoR()
    {
        this->now = this->now->r;
        return;
    }

    void GoP()
    {
        this->now = this->now->p;
        return;
    }

    void PushTree(Node<T> &n)
    {
        if (printhelp == 1)
            std::cout << "Pushing" << std::endl;
        if (this->root == 0)
        {
            if (printhelp == 1)
                std::cout << "Pushing1" << std::endl;

            this->root = &n;
            if (printhelp == 1)
                std::cout << &n << std::endl;
            this->now = this->root;
            if (this->now != 0)
            {
                this->now->r = 0;
                this->now->l = 0;
                this->now->p = 0;
            }
            if (printhelp == 1)
                std::cout << "Pushing5" << std::endl;
            this->size++;
            if (printhelp == 1)
                printf("root pushed, size == %d\n", this->size);
        }
        else
        {
            this->now = this->root;
            this->Paste(n, this->root->p);
#ifdef PASTING_BALANCING
            this->ShowTree(this->root);
#endif
            this->Balance(this->now);
        }
        return;
    }

    void TLevel()
    {
        this->levels = 0;
        if (this->root != 0)
        {
            this->TreeLevel(this->root, 1);
        }
        return;
    }

    Node<T> *FindNode(T x, Node<T> *n)
    {
        if (n->data == x)
        {
            cout << "нашёл" << x << endl;
            return n;
        }
        else
        {
            if ((n->l != 0) && (n->data >= x))
            {
                cout << "ищу слева" << x << n->data << endl;
                this->FindNode(x, n->l);
            }
            else
            {
                if ((n->r != 0) && (n->data < x))
                {
                    cout << "ищу справа" << x << n->data << endl;
                    this->FindNode(x, n->r);
                }
                else
                {
                    return 0;
                }
            }
        }
    }

    Node<mypair<VAL_TYPE, std::KEY_TYPE>> *FindNode(std::KEY_TYPE x, Node<mypair<VAL_TYPE, std::KEY_TYPE>> *n)
    {
        if (printhelp == 1)
            cout << "find warking" << endl;
        if (n == 0)
        {
            if (printhelp == 1)
                printf("Empty now\n");
            return 0;
        }
        if (printhelp == 1)
            cout << "find warking with tree" << endl;
        if (eq(n->data.second, x))
        {
            if (printhelp == 1)
                cout << "нашёл" << x << endl;
            return n;
        }
        else
        {
            if (printhelp == 1)
                std::cout << "enter else" << std::endl;
            if ((n->l != 0) && (n->data.second >= x))
            {
                if (printhelp == 1)
                    std::cout << "enter el1" << std::endl;
                if (printhelp == 1)
                    cout << "ищу слева" << x << n->data.second << endl;
                n = this->FindNode(x, n->l);
                return n;
            }
            else
            {
                if ((n->r != 0) && (n->data.second < x))
                {
                    if (printhelp == 1)
                        std::cout << "enter el2" << std::endl;
                    if (printhelp == 1)
                        cout << "ищу справа" << x << n->data.second << endl;
                    n = this->FindNode(x, n->r);
                    return n;
                }
                else
                {
                    if (printhelp == 1)
                        std::cout << "enter ex" << std::endl;
                    return 0;
                }
            }
        }
    }

    void PrevNull(Node<T> *n)
    {
        if (n->p != 0)
        {
            if ((n->l != 0) || (n->r != 0))
            {
                if (n->l != 0)
                {
                    if (n->p->r == n) //у предыдущего зануляем
                    {
                        n->p->r = n->l;
                    }
                    else
                    {
                        n->p->l = n->l;
                    }
                    n->l->p = n->p;
                }
                else
                {
                    if (n->p->r == n) //у предыдущего зануляем
                    {
                        n->p->r = n->r;
                    }
                    else
                    {
                        n->p->l = n->r;
                    }
                    n->r->p = n->p;
                }
            }
            else
            {
                if (n->p->r == n) //у предыдущего зануляем
                {
                    n->p->r = 0;
                }
                else
                {
                    n->p->l = 0;
                }
                n->p = 0; //на предыдущий зануляем
            }
        }
        else
        {
#ifdef DELETING_BALANCE
            printf("Корень удаляем значит\n");
#endif
        }
    }

    Node<T> *LeftFall(Node<T> *n)
    { //проваливаемся в левое поддерево
        n = n->l;
        while (n->r != 0)
        {
            n = n->r;
        }
        return n;
    }
    Node<T> *RightFall(Node<T> *n)
    { //проваливаемся в правое поддерево
        n = n->r;
        while (n->l != 0)
        {
            n = n->l;
        }
        return n;
    }

    void RedBlack2(Node<T> *n, Node<T> *del)
    {
        if (n->l != 0)
        {
            n = this->LeftFall(n);
        }
        else
        {
            n = this->RightFall(n);
        }
        del->data = n->data;
        this->DelBalance(n, n);
    }

    void RightRot(Node<T> *dad, Node<T> *son)
    { //son слева от dad

        if (this->root == dad)
        {
#ifdef PASTING_BALANCING
            printf("Дед(%d) - корень(R)\n", dad->data);
#endif
            this->root = son; //если отец - корень
            son->p = dad->p;

            dad->p = son;
            dad->l = son->r;
            if (son->r != 0)
            {
                son->r->p = dad;
            }
            son->r = dad;
        }
        else
        {
            if (dad->p->l == dad)
            {
#ifdef PASTING_BALANCING
                printf("Дед%d - левый(R)\n", dad->data);
#endif
                dad->p->l = son;
            }
            else
            {
#ifdef PASTING_BALANCING
                printf("Дед%d - правый(R)\n", dad->data);
#endif
                dad->p->r = son;
            }
            son->p = dad->p;
            dad->p = son;
            dad->l = son->r;
            if (son->r != 0)
            {
                son->r->p = dad;
            }
            son->r = dad;
#ifdef PASTING_BALANCING
            this->PrintTree();
#endif
        }
    }

    void LeftRot(Node<T> *dad, Node<T> *son)
    { //son справа от dad
        if (this->root == dad)
        {
#ifdef PASTING_BALANCING
            printf("Дед(%d) - корень(L)\n", dad->data);
            cout << (son->data) << endl;
#endif
            this->root = son; //если отец - корень
            son->p = dad->p;

            dad->p = son;
            dad->r = son->l;
            if (son->l != 0)
            {
                son->l->p = dad;
            }
            son->l = dad;
        }
        else
        {
            if (dad->p->l == dad)
            {
#ifdef PASTING_BALANCING
                printf("Дед%d - левый(L)\n", dad->data);
#endif
                dad->p->l = son;
            }
            else
            {
#ifdef PASTING_BALANCING
                printf("Дед%d - правый(L)\n", dad->data);
#endif
                dad->p->r = son;
            }
            son->p = dad->p;
            dad->p = son;
            dad->r = son->l;
            if (son->l != 0)
            {
                son->l->p = dad;
            }
            son->l = dad;
#ifdef PASTING_BALANCING
            this->PrintTree();
#endif
        }
    }

    void Black1(Node<T> *n, Node<T> *del)
    {
        if (n->l != 0)
        {
            n = n->l;
        }
        else
        {
            n = n->r;
        }
        del->data = n->data;
        this->PrevNull(n);
    }

    void Red0(Node<T> *n, Node<T> *del)
    {
        this->PrevNull(n);
    }

    void RB1(Node<T> *dad, Node<T> *son, Node<T> *vnuk)
    {
        dad->color = 'b';
        son->color = 'r';
    }

    void RB2(Node<T> *dad, Node<T> *son, Node<T> *vnuk)
    {
        dad->color = 'b';
        son->color = 'r';
        this->RightRot(dad, son);
    }

    void BR3(Node<T> *dad, Node<T> *son)
    {
        son->r->color = 'r';
        son->color = 'b';
        this->RightRot(dad, son);
    }

    void BR4(Node<T> *dad, Node<T> *son)
    {
        son->r->l->color = 'b';
        this->LeftRot(son, son->r);
        this->RightRot(dad, son->p);
    }

    void BB5(Node<T> *dad, Node<T> *son)
    {
        son->r->color = 'b';
        this->LeftRot(son, son->r);
        this->RightRot(dad, son->p);
    }

    void BB6(Node<T> *dad, Node<T> *son)
    {
        son->color = 'r';
        this->DelBalance(dad->p, dad->p);
    }

    void RightRB1(Node<T> *dad, Node<T> *son, Node<T> *vnuk)
    {
        dad->color = 'b';
        son->color = 'r';
    }

    void RightRB2(Node<T> *dad, Node<T> *son, Node<T> *vnuk)
    {
        dad->color = 'b';
        son->color = 'r';
        this->LeftRot(dad, son);
    }

    void RightBR3(Node<T> *dad, Node<T> *son)
    {
        son->l->color = 'r';
        son->color = 'b';
        this->LeftRot(dad, son);
    }

    void RightBR4(Node<T> *dad, Node<T> *son)
    {
        son->l->r->color = 'b';
        this->RightRot(son, son->l);
        this->LeftRot(dad, son->p);
    }

    void RightBB5(Node<T> *dad, Node<T> *son)
    {
        son->l->color = 'b';
        this->RightRot(son, son->l);
        this->LeftRot(dad, son->p);
    }

    void RightBB6(Node<T> *dad, Node<T> *son)
    {
        son->color = 'r';
        this->DelBalance(dad->p, dad->p);
    }

    void Black0(Node<T> *n)
    {
        if (n->p != 0)
        {
            if (n->p->l == n)
            {
                this->Black0Left(n);
            }
            else
            {
                this->Black0Right(n);
            }
        }
        else
        {
            return;
        }
    }

    void Black0Left(Node<T> *n)
    {
#ifdef DELETING_BALANCE
        printf("Левый случай\n");
#endif
        Node<T> *dad = n->p, *son, *vnuk;
        Node<T> *min = this->RightFall(dad);
        if (min->color == 'r')
        {
#ifdef DELETING_BALANCE
            printf("min\n");
#endif
            n->data = dad->data;
            dad->data = min->data;
            this->PrevNull(min);
            return;
        }
        if (dad->color == 'r')
        {
#ifdef DELETING_BALANCE
            printf("Отец - красный\n");
#endif
            if (dad->r->r != 0)
            {
                n->data = dad->data;
                dad->data = dad->r->data;
                dad->r->data = dad->r->r->data;
                this->PrevNull(dad->r->r);
            }
            else
            {
                this->PrevNull(n);
                dad->color = 'b';
                dad->r->color = 'r';
            }
        }
        else
        {
#ifdef DELETING_BALANCE
            printf("Отец - чёрный\n");
#endif
            this->B0LBlackdad(n, dad);
        }
    }

    void Kill1HightL(Node<T> *dad)
    {
        dad->r->color = 'r';
        if (dad != this->root)
        {
            this->Kill1HightL(dad->p);
        }
        return;
    }

    void Kill1HightR(Node<T> *dad)
    {
        dad->l->color = 'r';
        if (dad != this->root)
        {
            this->Kill1HightR(dad->p);
        }
        return;
    }

    Node<T> *Findredl(Node<T> *node)
    { //найдёт самый нижний и левый красный узел
        if (node->l != 0)
        {
            this->Findredl(node->l);
        }
        if (node->r != 0)
        {
            this->Findredl(node->r);
        }
        if (node->color == 'r')
        {
            return node;
        }
        else
        {
            return 0;
        }
    }

    Node<T> *Findredr(Node<T> *node)
    {
        if (node->l != 0)
        {
            this->Findredr(node->r);
        }
        if (node->r != 0)
        {
            this->Findredr(node->l);
        }
        if (node->color == 'r')
        {
            return node;
        }
        else
        {
            return 0;
        }
    }

    void RecPrint(Node<T> *red, Node<T> *downred = 0)
    {
        if ((red->l == 0) || (red->r == 0))
        {
            if (downred == 0)
            {
                downred = red;
            }
        }
        else
        {
            red->color = 'b';
            red->l->color = 'r';
            red->r->color = 'r';
            this->RecPrint(red->l);
            this->RecPrint(red->r);
        }
        return;
    }

    bool SeeForRedInTreeRight()
    {
        Node<T> *nod = this->Findredr(this->root), *fnod = 0; //найти красный узел
        if (nod == 0)
        {
            return false;
        }
        this->RecPrint(nod, fnod);
#ifdef DELETING_BALANCE
        this->PrintTree();
#endif
        //переместить вниз пока у него не останется детей
        //удалить сохранив значение в дереве
    }

    bool SeeForRedInTreeLeft(Node<T> *redone)
    {
        Node<T> *nod = this->Findredl(this->root), *fnod = 0; //найти красный узел
        if (nod == 0)
        {
            return false;
        }
        this->RecPrint(nod, fnod);
        redone = fnod;
//переместить вниз пока у него не останется детей
#ifdef DELETING_BALANCE
        this->PrintTree();
#endif

        //удалить сохранив значение в дереве
    }

    void UnrealDeadr(Node<T> *fnod, Node<T> *main)
    { //main тот который мы удаляем из дерева в итоге
    }

    void UnrealDeadl(Node<T> *fnod, Node<T> *main)
    { //main тот который мы удаляем из дерева в итоге
        T prev, next;
        Node<T> *one, *two;
        one = fnod->p;
        two = fnod;

        next = one->data;
        one->data = two->data;
        prev = next;
        while (1)
        {
            if ((one->l != 0) && (one->r != 0))
            { //короче лучше через функции наверное
                while ((one->l != 0) && (one->r != 0))
                {
                    one = one->p; //вертикальный ход
                    Obmen(one, next, prev);
                }
            }
            else
            {
                Node<T> *dad = one;
                while (!((one->l != 0) && (one->r != 0)))
                {
                    one = one->l; //левый ход
                    Obmen(one, next, prev);
                }
            }
        }
        PrevNull(fnod);
        //дописать перемещение значений по дереву для обоих случаев
    }

    void Obmen(Node<T> *one, T next, T prev)
    {
        next = one->data;
        one->data = prev;
        prev = next;
    }

    void B0LBlackdad(Node<T> *n, Node<T> *dad)
    { //чёрный отец для левого случая
        Node<T> *son = dad->r;
        if (dad->r->color == 'b')
        {
            if (dad->r->r != 0)
            {
                n->data = dad->data;
                dad->data = dad->r->data;
                dad->r->data = dad->r->r->data;
                this->PrevNull(dad->r->r);
            }
            else
            {
                //Здесь не нужно проверять есть ли другой внук у dad потому что если бы он был
                //то он был бы красный и сработал бы min в начале
                Node<T> *red;
                if (!this->SeeForRedInTreeLeft(red))
                { //если не нашли во всём дереве красного элемента
                    this->Kill1HightL(dad);
                }
                else
                {
                    this->UnrealDeadl(red, 0);
                }
            }
        }
        else
        {
            Node<T> *ud;
            if ((son->l->l != 0) || (son->l->r != 0))
            {
#ifdef DELETING_BALANCE
                printf("У правого сына есть внуки\n");
#endif
                if (son->l->l != 0)
                {
#ifdef DELETING_BALANCE
                    printf("Используем правого правнука\n");
#endif
                    ud = son->l->l;
                }
                else
                {
#ifdef DELETING_BALANCE
                    printf("Используем левого правнука\n");
#endif
                    ud = son->l->r;
                }
                n->data = dad->data;
                dad->data = son->l->data;
                son->l->data = ud->data;
                this->PrevNull(ud);
                return;
            }
            if ((son->r->l != 0) || (son->r->r != 0))
            {
                if (son->r->l != 0)
                {
                    ud = son->r->l;
                }
                else
                {
                    ud = son->r->r;
                }
                n->data = dad->data;
                dad->data = son->l->data;
                son->l->data = son->data;
                son->data = ud->data;
                this->PrevNull(ud); //гарантировано красный ud
            }
            else
            {
                son->color = 'b';
                son->l->color = 'r';
                son->r->color = 'r';
                this->Black0(n);
            }
        }
    }

    void Black0Right(Node<T> *n)
    {
#ifdef DELETING_BALANCE
        printf("Правый случай\n");
#endif
        Node<T> *dad = n->p, *son, *vnuk;
        Node<T> *min = this->LeftFall(dad);
        if (min->color == 'r')
        {
#ifdef DELETING_BALANCE
            printf("min\n");
#endif
            n->data = dad->data;
            dad->data = min->data;
            this->PrevNull(min);
            return;
        }
        if (dad->color == 'r')
        {
#ifdef DELETING_BALANCE
            printf("Отец - красный\n");
#endif
            if (dad->l->l != 0)
            {
#ifdef DELETING_BALANCE
                printf("Внуки у другого сына есть\n");
#endif
                n->data = dad->data;
                dad->data = dad->l->data;
                dad->l->data = dad->l->l->data;
                this->PrevNull(dad->l->l);
            }
            else
            {
#ifdef DELETING_BALANCE
                printf("Внуков у другого сына нет\n");
#endif
                this->PrevNull(n);
                dad->color = 'b';
                dad->l->color = 'r';
            }
        }
        else
        {
#ifdef DELETING_BALANCE
            printf("Отец - чёрный\n");
#endif
            this->B0RBlackdad(n, dad);
        }
    }

    void B0RBlackdad(Node<T> *n, Node<T> *dad)
    {
        Node<T> *son = dad->l;
        if (dad->l->color == 'b')
        {
#ifdef DELETING_BALANCE
            printf("Левый сын - чёрный\n");
#endif
            if (dad->l->l != 0)
            {
                n->data = dad->data;
                dad->data = dad->l->data;
                dad->l->data = dad->l->l->data;
                this->PrevNull(dad->l->l);
            }
            else
            {
                //Hurdest case right
            }
        }
        else
        {
#ifdef DELETING_BALANCE
            printf("Левый сын - красный\n");
#endif
            Node<T> *ud;
            if ((son->r->r != 0) || (son->r->l != 0))
            {
#ifdef DELETING_BALANCE
                printf("У правого сына есть внуки\n");
#endif
                if (son->r->r != 0)
                {
#ifdef DELETING_BALANCE
                    printf("Используем правого правнука\n");
#endif
                    ud = son->r->r;
                }
                else
                {
#ifdef DELETING_BALANCE
                    printf("Используем левого правнука\n");
#endif
                    ud = son->r->l;
                }
                n->data = dad->data;
                dad->data = son->r->data;
                son->r->data = ud->data;
                this->PrevNull(ud);
                return;
            }
            if ((son->l->r != 0) || (son->l->l != 0))
            {
#ifdef DELETING_BALANCE
                printf("У левого сына есть внуки\n");
#endif

                if (son->l->r != 0)
                {
#ifdef DELETING_BALANCE
                    printf("Используем правого правнука\n");
#endif
                    ud = son->l->r;
                }
                else
                {
#ifdef DELETING_BALANCE
                    printf("Используем левого правнука\n");
#endif
                    ud = son->l->l;
                }
                n->data = dad->data;
                dad->data = son->r->data;
                son->r->data = son->data;
                son->data = ud->data;
                this->PrevNull(ud); //гарантировано красный ud
            }
            else
            {
#ifdef DELETING_BALANCE
                printf("У сына нет внуков\n");
#endif
                son->color = 'b';
                son->r->color = 'r';
                son->l->color = 'r';
                this->Black0(n);
            }
        }
    }

   
    void DelBalance(Node<T> *n, Node<T> *del)
    {
        if ((n->l != 0) && (n->r != 0))
        { //если 2 сына    //К2 или Ч2
            this->RedBlack2(n, del);
        }
        else
        {
            if ((n->l != 0) || (n->r != 0))
            { //если 1 сын  (Ч1)
                this->Black1(n, del);
            }
            else
            { //если 0 сыновей
                if (n->color == 'r')
                { //К0
                    this->Red0(n, del);
                }
                else
                { //Ч0
                    del->data = n->data;
                    this->Black0(n);
                }
            }
        }
        return;
    }

    Node<T> *PopTree(Node<T> *n) //типо удoляем del, но по факту удоляем n
    {

        if (n == 0)
        {
            
            return 0;
        }
        Node<T> *res = n;
        Node<T> *del = n; //запоминаем указатель удоляемого элемента

        this->DelBalance(n, del);
        
        return res;

}

    void DestroySubTree() {}

    void ShowTree(Node<T> *n, int count = 0)
    {
        for (int i = 0; i < count; i++)
        {
            printf("|");
        }
        if (n->p != 0)
        {
            if (n->p->l == n)
            {
                cout << "(l)";
            }
            else
            {
                cout << "(r)";
            }
        }
        printf("[%d]", count);
        cout << n->data << n->color << endl;
        count++;
        if (n->l != 0)
        {
            this->ShowTree(n->l, count);
        }
        if (n->r != 0)
        {
            this->ShowTree(n->r, count);
        }
    }

    void PrintTree()
    {
        if (this->size == 0)
        {
            if (printhelp == 1)
                printf("Tree is empty\n");
            return;
        }
        this->TLevel();
        int p = 1, levelcount = this->levels;
        Node<T> *arr[p];
        arr[0] = this->root;
        int y = Step(2, levelcount - 1);
        for (int i = 0; i < y; i++)
        {
            printf(" ");
        }
        cout << this->root->data << this->root->color << endl;
        this->Printic(arr, p * 2, levelcount);
    }

    ~Tree()
    {
        if (TREE_CONSTRUCTORS)
        {
            printf("Destructed tree (%d)\n", this->size);
        }
    }

private:
    void TreeLevel(Node<T> *node, int l)
    {
        if (node->l != 0)
        {
            this->TreeLevel(node->l, l + 1);
        }
        if (node->r != 0)
        {
            this->TreeLevel(node->r, l + 1);
        }
        if ((node->r == 0) && (node->l == 0) && (this->levels < l))
        {
            this->levels = l;
        }
    }

    void Printic(Node<T> **arr, int p, int levelcount)
    {
        

        if (levelcount == 0)
        {
            return;
        }
        Node<T> *arrc[p]; //p уже домножено на 2 и == потенц. кол-ву детей

        for (int i = 0; i < p; i++)
        {
            arrc[i] = 0;
        }

        int empty = 0;

        for (int i = 0; i < p / 2; i++)
        {
            if (arr[i] != 0)
            {

                if (arr[i]->l != 0)
                {
                    empty++;
                    arrc[i * 2] = arr[i]->l;
                     }
                else
                {
                    
                    arrc[i * 2] = 0;
                }
                if (arr[i]->r != 0)
                {
                    empty++;
                    
                    arrc[i * 2 + 1] = arr[i]->r;
                    
                }
                else
                {
                    
                    arrc[i * 2 + 1] = 0;
                }
            }
            else
            {
                arrc[i * 2] = 0;
                arrc[i * 2 + 1] = 0;
            }
        }

        if (empty == 0)
        {
            return;
        }

        printf("\n");
        for (int i = 0; i < Step(2, levelcount - 1) / 2; i++)
        {
            printf(" "); //пробел
        }

        for (int childs = 0; childs < p; childs++)
        {
            if (arrc[childs] != 0)
            {
                if (childs % 2 != 0)
                {
                    printf("п");
                }
                else
                {
                    printf("л");
                }
                cout << arrc[childs]->data << arrc[childs]->color;
            }
            else
            {
                printf(" "); //пустое место от символа
            }
            for (int i = 0; i < Step(2, levelcount - 1); i++)
            {
                printf(" "); //пробел
            }
        }
        printf("\n");
        this->Printic(arrc, p * 2, levelcount - 1);
    }

    void Paste(Node<T> &n, Node<T> *prev)
    {
        if (this->now == 0)
        {
            this->now = &n;
            n.color = 'r';
            this->now->p = prev;

            if (n.data <= this->now->p->data)
            {
                this->now->p->l = &n;
            }
            else
            {
                this->now->p->r = &n;
            }
            this->now->l = 0;
            this->now->r = 0;
            this->size++;

            if (printhelp == 1)
                printf("%d node pushed after %d\n", this->now->data, this->now->p->data);
        }
        else if (n.data <= this->now->data)
        {
            prev = this->now;
            this->GoL();
            this->Paste(n, prev);
        }
        else if (n.data > this->now->data)
        {
            prev = this->now;
            this->GoR();
            this->Paste(n, prev);
        }
    }

    void Balance(Node<T> *pasted)
    {
        if (pasted == this->root)
        { //Если вызвали для корня, то просто красим его в чёрный
            pasted->color = 'b';
            return;
        }

        if (pasted->p == this->root)
        { //Если нет деда, то выход
#ifdef PASTING_BALANCING
            printf("Для(%d):Мы у корня, так что балансировать нечего\n", pasted->data);
#endif
            return;
        }

        Node<T> *uncle = this->FindUncle(pasted);
#ifdef PASTING_BALANCING
        if (uncle != 0)
        {
            std::cout << pasted->data << " now uncle " << uncle->data << std::endl;
            std::cout << ((pasted->p->color == 'r') && (pasted->color == 'r')) << (uncle != 0) << (uncle->color == 'r') << std::endl;
        }
        else
        {
            std::cout << " UNCLE - ZERO " << endl;
        }
#endif
        if ((pasted->p->color == 'r') && (pasted->color == 'r'))
        { //если отец красный
            if (uncle != 0)
            { //если дядя ЕСТЬ
                if (uncle->color == 'r')
                { //если дядя КРАСНЫЙ
                    firstBalance(pasted, uncle);
                }
                else
                { //если дядя ЧЁРНЫЙ
                    secondBalance(pasted, uncle);
                }
            }
            else
            { //если дяди НЕТ
                thirdBalance(pasted);
            }
        }
        else
        {
#ifdef PASTING_BALANCING
            printf("Отец и сын разноцветные, баллансировка не нужна\n");
#endif
        }
#ifdef PASTING_BALANCING
        printf("%d Balanced \n", pasted->data);
        this->PrintTree();
#endif
    }

    void firstBalance(Node<T> *n, Node<T> *uncle)
    {
#ifdef PASTING_BALANCING
        printf("Это вставка ситуация 1\n");
#endif
        if (n->p->p != this->root)
        {
#ifdef PASTING_BALANCING
            printf("Дед - не корень\n");
#endif
            n->p->p->color = 'r';
            n->p->p->l->color = 'b'; //меняем цвета деда и его детей
            n->p->p->r->color = 'b';
            this->Balance(uncle->p); //рекурсия вверх
        }
        else
        {
#ifdef PASTING_BALANCING
            printf("Дед - корень\n");
#endif
            if (n->p->p->l != 0)
                n->p->p->l->color = 'b'; //меняем цвета деда и его детей
            if (n->p->p->r != 0)
                n->p->p->r->color = 'b';
        }
    }

    void secondBalance(Node<T> *n, Node<T> *uncle)
    {
#ifdef PASTING_BALANCING
        printf("Это вставка ситуация 2\n");
#endif
        n = this->OneSide(n, uncle); //с одной ли стороны мы и дядя если нет, то возвращается указатель на отца
        Node<T> *dad = n->p, *grand = dad->p;
        
#ifdef PASTING_BALANCING
        printf("Вращаем деда\n");
#endif
        if (grand->l == dad)
        {
            this->RightRot(grand, dad);
        }
        else
        {

            this->LeftRot(grand, dad);
        }

       
        uncle->p->color = 'r';
        dad->color = 'b';
#ifdef SHOW_TREE_IN_BALANCE
        this->ShowTree(this->root);
#endif
    }

    void thirdBalance(Node<T> *n)
    {
#ifdef PASTING_BALANCING
        printf("Это вставка ситуация 3\n");
#endif
        Node<T> *dad = n->p, *grand = dad->p;

#ifdef PASTING_BALANCING
        cout << grand->data << endl;
        cout << dad->data << endl;
        cout << n->data << endl;
#endif

        if ((grand->r == dad) && (dad->l == n))
        {
#ifdef PASTING_BALANCING
            printf("Ставим в линию\n");
#endif
            this->RightRot(n->p, n);
        }
        else
        {
            if ((grand->l == dad) && (dad->r == n))
            {
#ifdef PASTING_BALANCING
                printf("Ставим в линию\n");
#endif

                this->LeftRot(n->p, n);
            }
        }

        if (grand->l != 0)
        {
            this->RightRot(grand, grand->l);
        }
        else
        {
            this->LeftRot(grand, grand->r);
        }
        grand->p->color = 'b';
        grand->color = 'r';
#ifdef PASTING_BALANCING
        this->ShowTree(this->root);
#endif
    }

    Node<T> *OneSide(Node<T> *n, Node<T> *uncle)
    {
        if (((n->p->l == n) && (uncle->p->r == uncle)) || ((n->p->r == n) && (uncle->p->l == uncle)))
        {
#ifdef PASTING_BALANCING
            printf("Расположение удобное\n");
#endif
            return n; //если всё нормально расположено ничего не меняем
        }
        else
        {
#ifdef PASTING_BALANCING
            printf("Меняем расположение\n");
#endif
            Node<T> *dad = n->p, *grand = n->p->p;
            if (n->p->r == n) //если n справа и дядя справа
            {
                this->LeftRot(dad, n);
            }
            else
            { //если n слева и дядя слева
#ifdef PASTING_BALANCING
                printf("n слева и дядя слева\n");
#endif
                this->RightRot(dad, n);
            }
            return dad; //после поворота возвращаем указатель на отца
        }
    }

    Node<T> *FindUncle(Node<T> *n)
    {
        if (n->p->p->r == n->p)
        { //если отец справа
            if (n->p->p->l != 0)
            {
                return n->p->p->l;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if (n->p->p->r != 0)
            {
                return n->p->p->r;
            }
            else
            {
                return 0;
            }
        }
    }
};

    void Dictionary(Tree<mypair<VAL_TYPE, KEY_TYPE>> &tr);

int save(Tree<mypair<VAL_TYPE, KEY_TYPE>> tr, std::string file)
{
    Node<mypair<VAL_TYPE, KEY_TYPE>> *n;
    FILE *fl = fopen(file.c_str(), "w");
    if (fl == NULL)
    {
        printf("ERROR: Couldn't save file\n");
        return 0;
    }

    for (int i = 0; i < tr.size; i++)
    {
        n = tr.PopTree(tr.root);
        if (n == 0)
        {
            return 1;
        }
        fprintf(fl, "+ %s %d\n", n->data.second.c_str(), n->data.first);
    }
    fclose(fl);
    return 1;
}

int lo = 0;

void Creation(Tree<mypair<VAL_TYPE, KEY_TYPE>> &tr, FILE * fl){
    char str, str1[256];
    int val;
    std::string word;
    while(!feof(fl)){
    fscanf(fl,"%c %s %d\n", &str, &str1, &val);
    
    word = str1;
    mypair<VAL_TYPE, KEY_TYPE> p;
        p.first = val;
            p.second = word;
            Node<mypair<VAL_TYPE, KEY_TYPE>> *u = new Node<mypair<VAL_TYPE, KEY_TYPE>>(p);
                tr.PushTree(*u);
    }
                return;
}

int load(Tree<mypair<VAL_TYPE, KEY_TYPE>> &tr, std::string file)
{
    for (int i = 0; i < tr.size; i++)
    {
        tr.PopTree(tr.root);
    }
    Tree<mypair<VAL_TYPE, KEY_TYPE>> tr1;
    tr = tr1;
    FILE * fl = fopen(file.c_str(), "r");
    if (fl == 0)
    {
        cout << "ERROR: File doesn't exist" << endl;
        fclose(fl);
        return 0;
    }
    if (printhelp == 1)
        std::cout << "LOUDDICTIONARY"<<" "<<file << std::endl;
    Creation(tr, fl);
    fclose(fl);
    return 1;
}

void Dictionary(Tree<mypair<VAL_TYPE, KEY_TYPE>> &tr)
{
    using namespace std;

    char str[256];
    string cmd, word;
    VAL_TYPE val;
    mypair<VAL_TYPE, string> p;

    if (printhelp == 1)
        cout << "Enter the command" << endl;

        
    while (cin >> cmd)
    {

        if (printhelp == 1)
            cout << cmd << endl;

    
        if (cmd == "+")
        {
            
                cin >> word;
            
            if (printhelp == 1)
                cout << word << endl;
                cin >> val;
            
            if (printhelp == 1)
                cout << val << endl;

            if (!countletter(word))
            {
                printf("No letters incorrect key\n");
                exit(0);
            }
            p.first = val;
            p.second = word;
            Node<mypair<VAL_TYPE, KEY_TYPE>> *u = new Node<mypair<VAL_TYPE, KEY_TYPE>>(p);
            Node<mypair<VAL_TYPE, KEY_TYPE>> *n = 0;
            n = tr.FindNode(word, tr.root);
            if (n == 0)
            {
                tr.PushTree(*u);
                printf("OK\n");
            }
            else
            {
                printf("Exist\n");
            }
        }
        else if (cmd == "-")
        {
                cin >> word;
            
            p.second = word;
            Node<mypair<VAL_TYPE, KEY_TYPE>> *n;
            n = tr.FindNode(word, tr.root);
            if (n == 0)
            {
                printf("NoSuchWord\n");
            }
            else
            {
                tr.PopTree(n);
                printf("OK\n");
            }
        }
        else if (cmd == "!")
        {
                cin >> word;
            
            int res = 1;
            if ((word == "Save") || (word == "save"))
            {
                std::string file;
                if (printhelp == 1)
                    cout << "Enter the filename" << endl;
                 
                cin >> file;
                res = save(tr, file);
            }
            else if ((word == "Load") || (word == "load"))
            {
                std::string file;
                if (printhelp == 1)
                    cout << "Enter the filename" << endl;
                
                cin >> file;
                res = load(tr, file);
            }
            if (res == 1)
            {
                printf("OK\n");
            }
            else
            {
                //error code
            }
        }
        else
        {
            if (printhelp == 1)
                cout << "Enter to keysearch" << endl;
            Node<mypair<VAL_TYPE, KEY_TYPE>> nd;
            Node<mypair<VAL_TYPE, KEY_TYPE>> *nref = &nd;
            nref = tr.FindNode(cmd, tr.root);
            if (nref != 0)
            {
                cout << "OK:" << nref->data.first << endl;
            }
            else
            {
                printf("NoSuchWord\n");
            }
        }
    }
    return;
}

int main(int c, char *chr[])
{
    if (c > 1)
    {
        if (chr[1] == string("1"))
        {
            printhelp = 1;
        }
        cout << "hp " << printhelp << endl;
    }
    else
    {
        //printf("%d\n", c);
    }
    Tree<mypair<VAL_TYPE, KEY_TYPE>> tr;
    Dictionary(tr);
}
