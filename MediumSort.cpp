#include <iostream>
#include <cstdlib>
#include <memory>
#include <ctime>

using namespace std;

class MediumSort
    {
        public:
        int * arr;
        int SIZE;
        private:
        int * end;
        public:
        MediumSort(const int & SIZE);
        MediumSort() : MediumSort(10) { /*cout<<"Call constructor(10)\n";*/ }
        ~MediumSort();
        void MergeSort(int* arr, int size); // сортировка слиянием
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

void MediumSort::MergeSort(int* arr, int size)
    {
        if(size > 1)
            {
                int mid = size / 2; 
                MergeSort(arr, mid);// левая часть
                MergeSort(&arr[mid], size - mid); // правая часть
                
                // индексы
                int li = 0, ri = mid, tmpi = 0;
                
                unique_ptr<int[]> tmp_arr(new int[size]);

                while((li < mid) || (ri < size))
                    {
                        if(arr[li] <= arr[ri]) 
                            {
                                tmp_arr[tmpi] = move(arr[li]);
                                tmpi++;
                                li++;
                            }
                        else 
                            {
                                tmp_arr[tmpi] = arr[ri];
                                tmpi++;
                                ri++;
                            };
                        // если левая и правая части разного размера.
                        if(li == mid)
                            {
                                for(ri;ri < size; ri++)
                                    tmp_arr[tmpi++] = arr[ri];
                            };
                        if(ri == size)
                            {
                                for(li;li < mid; li++)
                                    tmp_arr[tmpi++] = arr[li];
                            };
                    };
            copy(&tmp_arr[0],&tmp_arr[size],arr);
            };
        return;
    };

int main()
    {
        srand(time(0));
        MediumSort arr1(5);
        arr1.rand_fill(10);
        arr1.show();
        arr1.MergeSort(arr1.arr, arr1.SIZE);
        arr1.show();
        
        int tests = 30;
        for(int i = 0; i < tests; i++)
        {
            arr1.rand_fill(10);
            arr1.MergeSort(arr1.arr, arr1.SIZE);
            cout<<((arr1.is_sorted())? "collection is sorted":"collection is NOT sorted")<<endl;
         };
        return 0;
    };


// #include <iostream>
// #include <memory>
// #include <ctime>

// using namespace std;

// void show(int* arr, int size)
//     {
//        // Вывод
//         int* end = arr + size;
//         for(int* it = arr; it < end; it ++)
//             cout<<*it<<" ";
//         cout<<endl;
//     };

// void split(int* arr, int size)
//     {
//         if(size > 1)
//             {
//                 // cout<<"size = "<<size<<endl;
//                 show(arr,size);
//                 int mid = size / 2; 
//                 split(arr, mid);// левая часть
//                 split(&arr[mid], size - mid); // правая часть
                
//                 // индексы
//                 int li = 0, ri = mid, tmpi = 0;
                
//                 unique_ptr<int[]> tmp_arr(new int[size]); 
                
//                 while((li < mid) || (ri < size))
//                     {
//                         if(arr[li] <= arr[ri]) 
//                             {
//                                 tmp_arr[tmpi] = move(arr[li]);
//                                 tmpi++;
//                                 li++;
//                             }
//                         else 
//                             {
//                                 tmp_arr[tmpi] = arr[ri];
//                                 tmpi++;
//                                 ri++;
//                             };
//                         if(li == mid)
//                             {
//                                 for(ri;ri < size; ri++)
//                                     tmp_arr[tmpi++] = arr[ri];
//                             };
//                         if(ri == size)
//                             {
//                                 for(li;li < mid; li++)
//                                     tmp_arr[tmpi++] = arr[li];
//                             };
//                     };
//                 copy(&tmp_arr[0],&tmp_arr[size],arr);
//             }
//         else 
//             {
//                 cout<<"size !> 1\n";
//                 show(arr,size);
                
//             };
//         return;
//     };

// int main()
// {
//     srand(time(NULL));
//     const int SIZE = 8;
//     int arr[SIZE];
//     // Заполнение.
//     int * end = arr + SIZE;
//     for(int* it = arr; it < end; it ++)
//         *it = rand()%10;
//     // Вывод
//     show(arr, SIZE);
    
//     split(arr, SIZE);
    
//     show(arr, SIZE);
    
//     return 0;
// }
