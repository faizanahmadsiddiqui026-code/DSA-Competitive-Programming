#include<bits/stdc++.h>
using namespace std;
int main(){ 
 
// set // We must know the implementation of set
 
// given n elements, tell me the number of unique elements 
// 	arr[] = {2, 5, 2, 1, 5} // 3 unique elements -> {1. 2. 5}
 
// 	set<int> st; 
// 	int n;
// 	cin >> n;
// 	for(int i = 0;i<n;i++) {
// 		int x;
// 		cin >> x; 
// 		st.insert(x);  //just like pushback in vectors
// 	}

//Set arranges and stores data in ascending order(linearly order)

//For Accessing element,We cannot do st[0] just like arrays


//We have to use pointer concept    *st.begin()=1    *st.begin()+1=2  *st.begin()+2=5 
//for INSERT function ,Time complexity- log n ,where n is size of set


// 	cout << st.size(); 
 
// 	// st -> {1, 2, 5}
// 	// ERASE functionality 


//3 Types of Erase
//To delete first element
// 	// T.C.- log n
// 	st.erase(st.begin()); // st.erase(iterator) that we want to delete // output st -> {2, 5}
  

//To delete range of element
// 	// T.C.- log n
// 	st.erase(st.begin(), st.begin() + 2);  //output-> {5}
// 	// st.erase(startIterator, endIterator) 


//To delete particular element(key)
//  //T.C.-log n
// 	st.erase(5); // st.erase(key) // delete the 5 from st -> {1, 2}
 

//whatever initialization is used vector is applicable in set 
// 	set<int> st = {1, 5, 7, 8}; 
//  set<int> s1(st.begin(),st.end());  //copying  st in st1
 

// T.C.- log n
// 	auto it = st.find(7);  // it will be, iterator to 7
 
// 	auto it = st.find(9); // it = st.end(); 
 
// 	st.emplace(6); // st.insert(6) // emplace is faster than insert
 
// 	cout << st.size() << endl;  //print the size
 
 
// 	set<int> st; 
// 	st.insert(5); // -> {5}
// 	st.insert(5); // -> {5}
 
// 	for(auto it=st.begin(); it!=st.end();it++) {
// 		cout << *it << " "; 
// 	}
 
// 	for(auto it : st) {
// 		cout << it << endl; 
// 	}
 
// 	// delete the entire set 
// 	st.erase(st.begin(), st.end()); // makes sure the entire set is deleted 
 
//All operations of ordered_set(set) takes T.C- logn
 
 



// 	unordered_set<int> st; 
//Doesn't sort in any order 
//Doesn't know the position of insertion
// 	st.insert(2);  
// 	st.insert(3);
// 	st.insert(1); 
 
// 	// average time complexity is O(1) 
// 	// If facing tle -> switch to set 
// 	// but the worst case is linear in nature,T.C.- O(set size)
 
//In Competitive Programming,if we don't need to store in ascending order,always used unordered_set






// 	multiset<int> ms; 
//instead of unique,all elements are stored
//Helps to store all element in sorted order(ascending order)
// 	ms.insert(1); 
// 	ms.insert(1); 
// 	ms.insert(2); 
// 	ms.insert(2); 
// 	ms.insert(3); // ms.emplace(3) 
// 	// st -> {1, 1, 2, 2, 3}
 

// 	// T.C.- log n
// 	ms.erase(2); // all the instances will be erased 
 
// 	auto it = ms.find(2); // returns an iterator pointing to the first element of 2 
// 	ms.clear(); // deleted the entire set 
// 	ms.erase(ms.begin(), ms.end()); // deletes the entire set 

 
 
// 	for(auto it=st.begin(); it!=st.end();it++) {
// 		cout << *it << " "; 
// 	}
 
// 	for(auto it : st) {
// 		cout << it << endl; 
// 	}
// 	// Finds how many times 2 occurs 
// 	st.count(2); 
 
 
// 	ms.erase(ms.find(2));  //erase first instance of 2
// 	ms.erase(ms.find(2), ms.find(2) + 2);  //range erase from first instance to 2nd instance of 2
 
 
 
//Map

// 	// Key Value concept
// 	// raj -> 27 
// 	// hima -> 31 
// 	// sandeep -> 67 
// 	// tank -> 89 
// 	// map only stores unique keys and in sorted(ascending or linearly) way
// 	// T.C.-log n of map

// 	map<string, int> mpp; 
// 	mpp["raj"] = 27; 
// 	mpp["hima"] = 31; 
// 	mpp["praveer"] = 31; //this is ok
// 	mpp["sandeep"] = 67; 
// 	mpp["tank"] = 89; 
// 	mpp["raj"] = 29;  // overwrite the previous value
// 	mpp.emplace("raj", 45); 
// 	mpp.erase("raj"); // mpp.erase(key) // delete the key and value
// 	mpp.erase(mpp.begin()); // mpp.erase(iterator)  /delete the first element
// 	mpp.clear(); // entire map is cleaned up
// 	mpp.erase(mpp.begin(), mpp.begin()+2); // cleans up a given range
// 	auto it = mpp.find("raj"); // points to where raj lies at first time,if not present in map thenit will point to mpp.end() 
// 	auto it = mpp.find("simran"); // points to end since she does not exists 
 
// 	if(mpp.empty()) {
// 		cout << "Yes it is empty"; 
// 	}
// 	mpp.count("raj"); // always returns 1 as it stores only 1 
// 	// instance of raj 
 
// 	pair<int,int> pr;
// 	pr.first = 1; 
// 	pr.second = 10; 
 
// 	// printing map 

//for each loop,going character by character
//Reason- auto makes it a pair so we can use dot
// 	for(auto it: mpp) {
// 		cout << it.first << " " << it.second << endl; 
// 	}
 
//going address by address
//here it is an iterator
// 	for(auto it = mpp.begin(); it!=mpp.end();it++) {
// 		cout << it->first << " " << it->second << endl;
       // cout << *(it).first << " " << *(it).second << endl;  //we can also do this
// 	}
 
//unordered_map
// 	// does not stores in any order but unique keys
// 	unordered_map<int,int> mpp;
//pairs are not allowed in unordered map 
// 	// unordered_map<pair<int,int>,int> mpp; xxxxxx- Not Allowed
// 	// o(1) in almost all cases
// 	// o(n) in the worst case, where n is the container size 
 
 
// 	// Pair class 
// 	pair<int,int> pr = {1,2}; //pr.first=1  pr.second=2
// 	pair< pair<int,int>, int> pr = {{1,2}, 2};  //pr.first={1,2}  pr.second=2
// 	cout << pr.first.second << endl;  // 2
// 	pair<pair<int,int>, pair<int,int>> pr = {{1,2},{2, 4}};
// 	cout << pr.first.first;  //-> 1 
// 	cout << pr.second.second;  // -> 4 
 

// 	vector<pair<int,int>> vec; 
// 	set<pair<int,int>> st; 
// 	map<pair<int,int>, int> mpp; 
 
 
//Multimap
//Sorted and no unique key[Multiple keys]
// 	multimap<string, int> mpp;
// 	mpp.emplace("raj", 2); 
// 	mpp.emplace("raj", 5); 
//Stores both value unlike map 
 
 
 
// 	// Stack and Queue 
// 	stack<int> st; // lifo data structure //stack implementation using array and linked list
// 	// pop 
// 	// top 
// 	// size 
// 	// empty 
// 	// push and emplace 
 
// 	st.push(2); // stack first entererd element
// 	st.push(4); //  |
// 	st.push(3); //  |
// 	st.push(1); // stack last entered element
 
 
// 	cout << st.top() // prints 1
// 	st.pop(); // deletes the last entered element means 1
// 	cout << st.top(); // prints 3 
// 	st.pop(); 
// 	cout << st.top();  //print 4
 
//doesn't exist clear function in stack
// 	bool flag = st.empty(); // returns true if stack is empty, or false
 
// 	// deleted the entire stack 
// 	while(!st.empty()) {
// 		st.pop(); 
// 	}
 
// 	cout << st.size() << endl; // number of elements in the stack 
 
// 	stack<int> st; 
//cout << st.top() << endl; // throw error 

//Always use this to check, before implementing st.top()
// 	if(!st.empty()) {
// 		cout << st.top() << endl; // no error 
// 	}
 
 
// 	// queue // fifo operation data structure
//T.C-O(1) for all given function
// 	// push 
// 	// front
// 	// pop 
// 	// size 
// 	// empty 
 
// 	queue<int> q; 
// 	q.push(1); //queue first entered element
// 	q.push(5); // |
// 	q.push(3); // |
// 	q.push(6); //queue last entered element
 
// 	cout << q.front(); // prints 1 
// 	q.pop(); 
// 	cout << q.front(); // prints 5 
 
//Doesn't exist clear function in queue

// 	// linear time, T.C-O(n)  Reason-doing deletion manually
//deleted the entire queue  
// 	while(!q.empty()) {
// 		q.pop(); 
// 	}

//Inserting Elements
// 	queue<int> q;
// 	for(int i = 0;i<10;i++) q.push(i); 

//no iterator in stack and queue,everything should be done manually

 
//Most imp DS used in CP 
// 	// priority_queue  //duplicates are allowed //contain elements in descending order(top-> bottom)  //uses the concept of heap sort(heapify) //stores all elements in sorted order
// 	// push            
// 	// size 
// 	// top 
//     //pop 
//     //empty 
// 	priority_queue<int> pq;
// 	pq.push(1); 
// 	pq.push(5); 
// 	pq.push(2); 
// 	pq.push(6); 
 
// 	cout << pq.top(); // print 6 
// 	pq.pop(); 
// 	cout << pq.top(); // print 5 
 
// 	priority_queue<pair<int,int>> pq;
// 	pq.push(1, 5);  //takes order by checking first element if same then checks by second elements then descending order
// 	pq.push(1, 6); 
// 	pq.push(1, 7); 
 

//Using min_priority_queue from priority queue
// 	priority_queue<int> pq;
// 	pq.push(-1); // pq.push(-1 * el); 
// 	pq.push(-5); 
// 	pq.push(-2); 
// 	pq.push(-6); 
 
// 	cout << -1 * pq.top() << endl; // prints 1
 
// // Min priority queue 
//if negative element then we have to use min priority queue
// 	priority_queue<int, vector<int>, greater<int>> pq;  //here greater int means ulta
// 	pq.push(1); 
// 	pq.push(5); 
// 	pq.push(2); 
// 	pq.push(6); 
 
// 	cout << pq.top() << endl; // prints 1 
 
 
 
// 	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
 
 
// Dequeue<int> dq;  //Doubly ended queue
// 	// push_front() 
// 	// push_back() 
// 	// pop_front() 
// 	// pop_back()
// 	// begin, end, rbegin, rend 
// 	// size 
// 	// clear
// 	// empty 
// 	// at 

//*begin return elements but begin return iterator
 
 
// 	list<int> ls;  //implements Doubly Linked List
// 	// push_front() 
// 	// push_back() 
// 	// pop_front() 
// 	// pop_back()
// 	// begin, end, rbegin, rend 
// 	// size 
// 	// clear
// 	// empty 
// 	// at 
// 	// remove ->   T.C-> O(1) 
// 	ls.push_front(1); 
// 	ls.push_front(2); 
// 	ls.push_front(3);
// 	ls.remove(2); -> // o(1) operation 
 
  //D.S which work from every side(front,back)--we use List
  //D.S ,work which can be done by push_back ,is vector
  //but vector is more effecient


 
// 	// given N elements, print the elements that occurs maximum 
// 	// number of times 
// 	// input 
// 	// 5 
// 	// 1 3 3 3 2 
 
// 	// output 
// 	// 3
 
 
// 	int n;
// 	cin >> n; 
// 	map<int,int> mpp; 
// 	int maxi = 0; 
// 	for(int i = 0;i<n;i++) {
// 		int x;
// 		cin >> x;
// 		mpp[x]++; 
// 		if(mpp[x] > mpp[maxi]) {
// 			maxi = x; 
// 		}
// 	}
// 	cout << maxi<< endl; 
 
 
 
// 	// given N elements, print all elements in sorted order 
// 	// input 
// 	// n = 6 
// 	/// 6 6 3 2 3 5 
 
// 	// output 
// 	// 2 3 3 5 6 6 
 
// 	int n;
// 	cin >> n;
// 	multiset<int> ms; 
// 	for(int i=0;i<n;i++) {
// 		int x;
// 		cin >> x; 
// 		ms.insert(x); 
// 	}
 
// 	for(auto it : ms) {
// 		cout << it << endl; 
// 	}
 






// Container	    Think of it as
// vector	      Array 📦
// list	        Chain of nodes 🔗
// deque	        Double-ended array


}

