#include<bits/stdc++.h> //include eveything(libraries)
// // do not use it while interview onlly use in cp
using namespace std;
// int main(){
//     int val=30;
//     double val=10.0;
//     cout<<val<<endl; //throws error ,multiple definiton
// }



// #include<bits/stdc++.h>
// using namespace std; //C++ taken all function and put in this
// namespace raj{   //scope type thing
//    int val=30;
//    int getVal(){
//     return val*10;
//    }
// }
// int main(){
//     double val=10.0;
//     cout<<val<<endl; //No error
//     cout<<raj::val<<endl; //No error
//     cout<<raj::getVal()<<endl; //No error
// }



// #include<bits/stdc++.h>
// using namespace std; //C++ taken all function and put in this
// struct node{
//     int num;
//     double doub;
//     char x;

//     node(int num_,double doub_,char x_){
//         num=num_;
//         doub=doub_;
//         x=x_;
//     }
// };
// int main(){
//   node raj(79, 91.0, 'a');  //OR
//   node *raj=new node(79, 91.0, 'a'); //OR
//   node raj=node(79, 91.0, 'a');
//   return 0;

// }




// // max size of 10^7 -> int, double, char 
// int arr[10000000];

// // max size of 10^8 -> bool
// 	bool arr[100000000];

// int main() {

// 	// max size of 10^6 -> int, double, char 
// 	int arr[1000000];

// 	// max size of 10^7 -> bool
// 	bool arr[10000000]; 
// }



// //Array Container
// #include<bits/stdc++.h>
// using namespace std;
// array<int,3>arr; //arrays of size 3 containing all value 0
// int main(){
//     array<int,3>arr;  //array of size 3 containing all value garbage value
//     array<int,5>arr={1,5,6};  //rest value are 0 in arr
//     array<int,5>arr={1}; // rest value are 0 in array
//     array<int,5>arr={0}; //Initialising 0th index and Makinhg all elements as 0
    
//     array<int,5>arr;
//     arr.fill(5); //fill every elements with 5 in arr
    
//     array<int,5>arr;
//     //arr.at(index); <=> arr[i]
//     for(int i=0;i<5;i++){
//         cout<<arr.at(i)<<" ";
//     }
    
//     //Iterators - begin(),end(),rbegin(),rend()  r-reverse
//     //end() always point to address right after the last element
//     //rend always point to address right before the first element
//     //begin() always point to first element
//     //rbegin() always point to last element

//     array<int,5>arr={1,3,4,5,6};
//     //going address by address
//     for (auto it = arr.begin();it!=arr.end();it++){
//        cout<<*it<<" ";
//     }

//     for (auto it= arr.rbegin();it!=arr.rend();it++){
//        cout<<*it<<" ";
//     }   //(1)
    
//      for (auto it= arr.end()-1;it>=arr.begin();it--){
//        cout<<*it<<" ";
//     }  //(2)   both 1 and 2 will print in reverse order
    
//     //for each loop,going character by character
//     for(auto it: arr){
//         cout<<it<<" ";
//     }
    
//     string s="xjkwkf";
//     for(auto c: s){
//         cout<<c<<" ";
//     }


//     // to find size 
// 	cout << arr.size(); 
 
// 	// first element
// 	cout << arr.front(); // arr.at(0); 
 
// 	// last element
// 	cout << arr.back(); // arr.at(arr.size() - 1); 
// }    

// VECTOR Container
int main(){
    //int arr[50]; //in array we have to predefine the size,we cannot modify while executing
    //max size, same rules of array are applicable
	// segmentation fault if you push_back 10^7 times
 
	// vector<int>arr={}; // -> {} empty vector created
	// cout << arr.size() << endl; // -> print 0 
	// arr.push_back(0); // {0}
	// arr.push_back(2); // {0,2}
 	// cout << arr.size() << endl; // -> print 2
	// arr.pop_back(); // {0} pop out the last element
 	// cout << arr.size() << endl; // print 1  
 
 	// arr.push_back(0); // {0,0}
 	// arr.push_back(2); // {0,0,2}
 
 
 	// arr.clear(); // --> erase all elements at once and makes empty vector{}
 
 
	// vector<int> vec1(4, 0); // -> {0,0,0,0}
	// vector<int> vec2(4, 10); // -> {10,10,10,10}
 
	// // copy the entire vec2 into vec3
	// vector<int> vec3(vec2.begin(), vec2.end()); //Method-1 // -> [included,not included)  begin to end-1
	// vector<int> vec3(vec2); //Method-2
 
 
 
	// vector<int> raj;
	// raj.push_back(1); // raj.emplace_back(1); // emplace_back takes lesser time than push back 
	// raj.push_back(3); 
	// raj.push_back(2); 
	// raj.push_back(5); // -> {1, 3, 2, 5} 
 
 	// vector<int> raj1(raj.begin(), raj.begin() + 2);  // -> {1, 3}  
    // vector<int> raj1(raj.begin(), raj.end() - 2);   // -> {1, 3}
 
// 	// lower bound , upper bound in algorithm video
 
//  swap(v1, v2) //swapping the vectors
// 	// begin(), end(), rbegin(), rend()  //same function as in array container
 
 
//To defining 2d vectors 

// vector<vector<int>> vec;   //storing vector in vector container
 
// 	vector<int> raj1;
// 	raj1.push_back(1);  // {1}
// 	raj1.push_back(2);  // {1,2}
 
// 	vector<int> raj2;
// 	raj2.push_back(10);   // {10}
// 	raj2.push_back(20);   // {10,20}

// 	vector<int> raj3;
// 	raj3.push_back(19);   // {19}
// 	raj3.push_back(24);   // {19,24}
// 	raj3.push_back(27);   // {19,24,27}
 
// 	vec.push_back(raj1);  //storing vector raj1 in vector container vec 
// 	vec.push_back(raj2);  //storing vector raj2 in vector container vec
// 	vec.push_back(raj3);  //storing vector raj3 in vector container vec
 
// It is vector itself (Method-1)
// 	for(auto vctr: vec) {    //outer vector {0,1,2}
// 		for(auto it: vctr) {    //inner vector {0(0,1),1(0,1),2(0,1,2)}
// 			cout << it << " ";  
// 		}
// 		cout << endl; 
// 	}
 
//(Method-2)
// 	for(int i = 0;i<vec.size();i++) {
// 		for(int j = 0;j<vec[i].size();j++) {
// 			cout <<  vec[i][j] << " "; 
// 		}
// 		cout << endl; 
// 	}
 
 
//Define 10 x 20 (2d vector)
// 	vector<vector<int>> vec(10, vector<int> (20, 0)); //Dynamic(Rows)->Dynamic(Columns) //for adding different value,we have to use FOR loop
// 	vec.push_back(vector<int>(20, 0)); 
// 	cout << vec.size() << endl; // 11 size prints
// 	vec[2].push_back(1); 
  
 
// 	vector<int> arr[4]; //Static(Rows)->Dynamic(Columns)   //array of size-4 is created which is static contains datatype-vector(empty vector),in index what we are storing is dynamic
// 	arr[1].push_back(0); //at position-1 in arr we push back {0}
 
 
//Define 10 x 20 x 30 (3d vector)
// int arr[10][20][30] 
// vector<vector<vector<int>>> vec(10, vector<vector<int>> vec(20, vector<int> (30, 0));)
}


//array(static) and vector(dynamic)
// |    Code                        |  Meaning             |
// | ------------------------------ | ---------------------- |
// | `vector<vector<int>> matrix[]` | array(static) of 2D vectors(dynamic)    |
// | `vector<vector<int>> matrix`   | 2D vector              |
// | `vector<int> arr`              | 1D vector              |
// | `vector<int> arr[]`            | array of vectors       |
// | `vector<int> arr[] = {}`       | empty array of vectors |
   


// | Syntax                     | Meaning                                 |
// | -------------------------- | --------------------------------------- |
// | `T var;`                   | Single variable of type `T`             |
// | `T var[];`                 | Array of type `T` (size often required) |
// | `vector<T> var;`           | 1D dynamic array (vector)               |
// | `vector<T> var[];`         | Array of vectors                        |
// | `vector<vector<T>> var;`   | 2D vector                               |
// | `vector<vector<T>> var[];` | Array of 2D vectors                     |






