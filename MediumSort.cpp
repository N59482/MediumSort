#include <iostream>
#include <cstdlib>

using namespace std;

class MediumSort
    {
        private:
        int * arr;
        int SIZE;
        int * end;
        public:
        MediumSort(const int & SIZE);
        MediumSort() : MediumSort(10) { /*cout<<"Call constructor(10)\n";*/ }
        ~MediumSort();
        void MergeSort();
        void Split(int * a, int left, int right);
        void Merge();
        void rand_fill(const int & up_border); // заполнение массива случайными элементами
        void show();
        bool is_sorted(); // проверка на сортировку.
    };

MediumSort::MediumSort(const int & SIZE)
    {
        this->SIZE = SIZE;
        arr = new int[SIZE];
        end = arr + SIZE;
    };

MediumSort::~MediumSort()
    {
        delete [] arr;
    };

void MediumSort::rand_fill(const int & up_border)
    {
        if(up_border == 0) return;
        for(int * ptr = arr; ptr < end; ptr++)
            *ptr = (rand() % up_border);
    };

void MediumSort::show()
    {
        for(int *ptr = arr; ptr < end; ptr++) 
            cout<<*ptr<<" ";
        cout<<endl;
    }

bool MediumSort::is_sorted()
    {
        for(int *ptr = arr+1; ptr < end; ptr++) 
            if(*ptr < *(ptr-1)) return false;
        return true;
    }

void MediumSort::Split(int * a, int left, int right)
    {
        cout<<"Вызвана функция Split от "<<left<<" до "<<right<<endl; 
        if(left == right){ cout<<"Выход\n"; return;};
        int mid = left + (right - left) / 2;
        cout<<"Центр - "<<mid<<endl;
        Split(a,left,mid);
        Split(a,mid+1,right);
        return;
    };

void MediumSort::MergeSort()
    {
        int left = 0;
        int right = SIZE-1;
        Split(arr, left, right);
    };

int main()
    {
        srand(time(0));
        MediumSort arr1(5);
        int tests = 3;
        for(int i = 0; i < tests; i++)
        // {
        //     arr1.rand_fill(10);
        //     arr1.show();
        //     cout<<((arr1.is_sorted())? "collection is sorted":"collection is NOT sorted")<<endl;
        // };

        arr1.rand_fill(10);
        arr1.show();
        arr1.MergeSort();
        return 0;
    }