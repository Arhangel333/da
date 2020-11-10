#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

typedef int T;
const int VECTOR_EXTRA_SIZE = 5;
typedef double T1;

namespace NTabl
{
    class TTabl
    {
    public:
        T1 Key;
        char *Val;
        TTabl()
        {
            this->Key = 0;
            this->Val = 0;
        }
        TTabl(T1 k, char *v)
        {
            this->Key = k;
            this->Val = v;
        }
        void operator=(TTabl &other)
        {
            this->Key = other.Key;
            this->Val = other.Val;
        }
        void Show()
        {
            cout << this->Key << " -------------------------- " << this->Val << endl;
        }
        ~TTabl(){};
    };
} // namespace NTabl

using namespace NTabl;
template<class TT>
class vector
{
public:
    int size;
    int capacity;
    TT *data;

    vector()
    {
        size = 0;
        capacity = 3;
        data = new TT[3];
    }
    vector(int x)
    {
        size = 0;
        capacity = x;

        data = new TT[x];
    }
    void findKey(T1 x)
    {
        for (int i = 0; i < this->size; i++)
        {
            if (this->data[i].Key == x)
            {
                printf("%lf %s \n", this->data[i].Key, this->data[i].Val);
                //printf("%lf\t%s \n", this->data[i].Key, this->data[i].Val);
                //printf("\t%lf\t%s \n", this->data[i].Key, this->data[i].Val);
            }
        }
    }
    void Push(TT x)
    {
        if (this->size >= this->capacity)
        {
            TT *nov = new TT[this->capacity + VECTOR_EXTRA_SIZE];
            for (int i = 0; i < this->capacity; i++)
            {
                nov[i] = this->data[i];
            }

            this->capacity += VECTOR_EXTRA_SIZE;

            delete[] this->data;

            this->data = nov;
        }
        this->data[this->size] = x;
        this->size++;
    }
    void Pop()
    {
        if (this->size <= 0)
        {
            printf("Vector is empty.\n");
        }
        else
        {

            
            this->size--;
            
        }
    }
    void Printing()
    {
        printf(">>>>>>>>\n");
        for (int i = 0; i < this->capacity; i++)
        {
            printf("%lf  %s\n", this->data[i].Key, this->data[i].Val);
        }
        printf(">>>>>>>>size %d | cap %d\n", this->size, this->capacity);
    }
    ~vector()
    {
        this->size = 0;
        this->capacity = 0;
        delete[] data;
    }
};
void nulling(int a[], int size, int predel)
{
    for (int j = 0; j < size; j++)
    {
        a[j] = predel;
        //printf("[%d]%d ", j, a[j]);
    }
}
int sign(int x)
{
    if (x < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void pocketsort(vector<TTabl> x, int predel)
{
    int max = 0, min = 0/*, m[x.size] */;
    int *m = new int[x.size];
    for (int i = 0; i < x.size; i++)
    {

        m[i] = x.data[i].Key; //дальше сортируем m

        if (max < x.data[i].Key)
        {
            max = x.data[i].Key;
        }

        if (min > x.data[i].Key)
        {
            min = x.data[i].Key;
        }
    }
    int *sizer = new int[((max - min) / 10) + 1];
    /* T **b = new T *[((max - min) / 10) + 1];
 
    for (int i = 0; i < ((max - min) / 10) + 1; i++) {
        b[i] = new T [x.size];
    } */

    T **b = new T*[x.size];
 
    for (int i = 0; i < x.size; i++) {
        b[i] = new T[((max - min) / 10) + 1];
    }


    
    for (int i = 0; i < ((max - min) / 10) + 1; i++)
    {
        for (int j = 0; j < x.size; j++)
        {

            b[i][j] = predel;
        }
    }
    for (int i = 0; i < x.size; i++)
    {

        b[(m[i] - sign(m[i]) + (10 - abs(min % 10)) - min) / 10][sizer[(m[i] + (10 - abs(min % 10)) - min) / 10]] = m[i];
        sizer[(m[i] + (10 - abs(min % 10)) - min) / 10]++;
    }
    for (int i = 0; i < ((max - min) / 10) + 1; i++) //сортировка строк в b aka сортировка подмассивов
    {
        int minus = 1;
        if (b[i][0] < 0)
        {
            minus = -1;
        }
        int mu[10];
        nulling(mu, 10, 0);
        int f = 0;
        while (b[i][f] != predel)
        { //подсчёт значений в подмассивах для сортировки
            mu[abs(b[i][f] % 10)]++;

            f++;
        }

        if (sizer[i] != 0)
        {
            int ure = 0;
            for (int j = 0; j < sizer[i]; j++)
            {

                while ((mu[ure] == 0) && (ure < 10))
                {
                    ure++;
                }
                if (ure < 10)
                {
                    if (minus < 0)
                    {
                        b[i][sizer[i] - j - 1] = (ure * minus + ((i - 1) - minus + (min / 10)) * 10);
                        mu[ure]--;
                    }
                    else
                    {
                        b[i][j] = (ure * minus + ((i - 1) + (min / 10)) * 10);
                        mu[ure]--;
                    }
                }
            }
        }
    }

    int prev = predel;
    for (int st = 0; st <= ((max - min) / 10) + 1; st++)
    {
        if (sizer[st] != 0)
        {
            for (int ty = 0; ty < sizer[st]; ty++)
            {
                if (b[st][ty] == prev)
                {
                }
                else
                {
                    x.findKey(b[st][ty]);
                    prev = b[st][ty];
                }
            }
        }
    }

    delete[] m;
    delete[] sizer;
    for (int i = 0; i < ((max - min) / 10) + 1; i++) {
  delete []b[i];
}
delete []b;
}

int main()
{
    double j = 0;
    vector<TTabl> v;
    //freopen("output.txt", "w", stdout);
    FILE *fl = fopen("in.txt", "r");
    while (1)
    {
        char *s = new char[2048];
        fscanf(fl, "%lf\t%s", &j, s);
        if (feof(fl))
        {
            break;
        }
        //printf("%lf %s %d\n", j, s, feof(fl));
        TTabl e(j, s);
        v.Push(e);

        s = 0;
        delete[] s;
    }

    //v.Printing();

    pocketsort(v, -1000);
}
