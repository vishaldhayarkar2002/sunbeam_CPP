//we cannot declare main as static / const 
//if we dont write main and compile then it will give linker error  
// Day1_9.cpp
 //emp.acceptRecord(); //message passing emp.acceptRecord(&emp);
    // emp.Employee::acceptRecord( );//message passing  
    // emp.acceptRecord(); //emp.acceptRecord(&emp);
    // const int *ptr → ptr is a pointer to an integer that is constant.
    // ::add(10,1.1f); 

// Test( void ) : num3(num2) , num2(num1) , num1(0)
//     {
//         /*
//             this->num3 = num2; 
//             this->num2 = num1; 
//             this->num1 = 0; 
//         */ 
//     }

    //local pointer and global pointer can be made const 
//data-member can be const 
//member funtion  can be const 

// class Array
// {
//     private: 
//     int size; 
//     int *arr; 
//     public: 
//     Array(int size)
//     {
//         this->size = size; 
//         this->arr = new int[this->size]; 
//         for(int index = 0 ; index < this->size ; index++)
//            this->arr[index] = 0; 
//     }

int *ptr2 = new int(); // by d
int *ptr3 = new int(10); // by default it contains 10 IMPefault 0 IMP