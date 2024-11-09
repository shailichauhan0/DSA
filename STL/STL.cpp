#include<bits/stdc++.h>
using namespace std;


//Pairs
void cpp_pairs()
{
    pair<int,int>p={1,3};
    cout<<p.first<<" "<<p.second<<endl; //1 3

    //for storing more than 2 values in a variable
    pair<int,pair<int,int>>s={1,{2,3}};
    cout<<s.first<<" "<<s.second.first<<" "<<s.second.second<<endl; //1 2 3 

    // to create an array of pairs
    pair<int,int>a[]={{1,2},{3,4},{5,6}};
    cout<<a[0].first<<" "<<a[0].second<<endl; //1 2
    cout<<a[1].first<<" "<<a[1].second<<endl; //3 4
    cout<<a[2].first<<" "<<a[2].second<<endl; //5 6
}


//Vectors
void cpp_vectors(){
    vector<int> v1; //{1,2,3}
    v1.push_back(4); //v1={1,2,3,4}
    v1.emplace_back(2); //v1={1,2,3,4,2}

    //Vector as Pair Data Type
    vector<pair<int, int>> v2 = {{1, 2}, {2, 3}};
    v2.push_back({3, 4});   // here we have to specify the data as a pair using {}
    v2.emplace_back(4, 5);  // here emplace_back() itself assumes the values to be a pair

    //Create a Container with lots of elements which is already filled
    vector<int>v3(5,100); //v3={100,100,100,100,100}
    vector<int>v3(5); //v3={0,0,0,0,0} or any garbage value.
    
    //to copy one vector to another
    vector<int>v3(5,20); //v3={20,20,20,20,20}
    vector<int>v4(v3);  //v4={20,20,20,20,20}

    //Accessing of Element in Vector
    vector<int> v5={20,10,15,5,7};
    cout<<v5[0]<<" "<<v5.at(0); //20 20
    
    //Iterators:-Points to memory where elements is lying
    vector<int>::iterator it = v1.begin();
     cout<<*(it)<<endl;   // 1
     it++;
     cout<<*(it)<<endl;   // 2
     it=it+2;
     cout<<*(it)<<endl;   //4
      for(vector<int>:: iterator it= v1.begin(); it!=v1.end(); it++)
      {  
        cout<<*(it)<<" ";
      }  
      //OR
      for(auto it= v1.begin(); it!=v1.end(); it++)
      {
        cout<<*(it);
      } 
      //OR
      for(auto it:v1)
      {
        cout<<it<<" ";
      }

    //Deletion in vector
     vector<int> v6= {1, 2, 3, 4, 5};
     v6.erase(v6.begin()+1); //delete 2 from v6

    //Delete a portion
    vector<int>v7= {10,20,12,23,35};
    v7.erase(v7.begin()+2, v7.begin()+4); 
    for(auto it= v7.begin(); it!=v7.end(); it++) //v7= {10,20,35}  , delete like [start, end)
    cout<<*(it)<<" ";

    //Insert Function
    vector<int> v(2,100); //{100,100}
    v.insert(v.begin(),300); //{300,100,100}
    v.insert(v.begin()+1,2,10); //{300,10,10,100,100}

    //Insert One vector into another vector 
    vector<int>copy(2,50); //{50,50}
    v.insert(v.begin(),copy.begin(),copy.end()); //{50,50,300,10,10,100,100}

    //{10,20}
    //Size: count the size of a vector
    cout<<v.size(); //2
    //Pop: (Removes Element from last)
    v.pop_back(); //{10}

    //v -> {10,20}
    //v1 -> {30,40}
    v.swap(v1); // v->{30,40} , v1->{10,20}

    //erase the entire vector
    v.clear();
    cout<<v.empty();
}


//List
void cpp_list()
{
    list<int> ls;
    ls.push_back(2); //{2}
    ls.emplace_back(4); //{2,4}
    ls.push_front(5); //{5,2,4}
    ls.emplace_front(3); //{3,5,2,4}
    for(auto it= ls.begin(); it!=ls.end(); it++)
    cout<<*(it)<<" ";
    cout<<endl;
    // rest all functions are same as vectors
}



//Deque
void cpp_deque()
{
  deque<int>dq;
  dq.push_back(1); //{1}
  dq.emplace_back(2); //{1,2}
  dq.push_front(4); //{4,1,2}
  dq.emplace_front(3); //{3,4,1,2}

  dq.pop_back(); //{3,4,1}
  dq.pop_front(); //{4,1}

  dq.back();

  dq.front();

  // rest all functions are same as vectors
}



//Stack
void cpp_stack()
{
  stack<int>st;
  st.push(1); //{1}
  st.push(2); //{2,1}
  st.push(3); //{3,2,1}
  st.push(3); //{3,3,2,1}
  st.emplace(5); //{5,3,3,2,1}

  cout<<st.top(); //Prints 5 'indexing is not allowed here'

  st.pop(); //{3,3,2,1}

  cout<<st.top(); //3
  cout<<st.size(); //4
  cout<<st.empty();  //Boolean Function return false

  stack<int>st1,st2;
  st1.swap(st2);

   //All Operations of Stack is of o(n);
}



//Queue
void cpp_queue()
{
  queue<int>q;
  q.push(1); //{1}
  q.push(2); //{1,2}
  q.emplace(4); //{1,2,4}

  q.back() +=5;
  cout<<q.back(); //Prints 9

  //Q={1,2,9}
  cout<<q.front(); //Prints 1

  q.pop(); //{2,9}

  cout<<q.front(); //Prints 2

  //Other Functions(size,swap,empty) are same as stack
  //All Operations are happening in constant time [O(n)] 
}



//Priority Queue
void cpp_priorityqueue(){
  //Max Heap
  priority_queue<int>pq;

  pq.push(5); //{5}
  pq.push(2); //{5,2}
  pq.push(8); //{8,5,2}
  pq.push(10); //{10,8,5,2}

  cout<<pq.top(); //prints 10

  pq.pop(); //{8,5,2}

  cout<<pq.top(); //print 8

  //Minimum Heap
  //(Minimum Elements at the Top)
  priority_queue<int,vector<int>,greater<int>> pq;
  pq.push(5); //{5}
  pq.push(2); //{2,5}
  pq.push(8); //{2,5,8}
  pq.emplace(10); //{2,5,8,10}

  cout<<pq.top(); //prints 2

  //push: log n
  //pop : log n
  //top : o(1) 
}



//Set
void cpp_set()
{
  //Stores everthing in a sorted order and unique elements.
  set<int>st;
  st.insert(1); //{1}
  st.emplace(2); //{1,2}
  st.insert(2); //{1,2} 
  st.insert(4); //{1,2,4}
  st.insert(3); //{1,2,3,4}

  //{1,2,3,4,5}
  auto it=st.find(3); //return iterator which locate at that index
  auto it=st.find(6); //iterator points at end if element is not found

  st.erase(5); //erase 5//take logarithmic time

  int cnt=st.count(1); //Always 1 if it exits or 0 if it doesnt exits
   
   auto it=st.find(3);
   st.erase(it); 

  //{1,2,3,4,5}
   auto it1=st.find(2);
    auto it2=st.find(4);
    st.erase(it1,it2); //after erase {1,4,5} [first,last)
}



//MultiSet
void cpp_multiset()
{
  //Everything is same as set
  //Only stores duplicate elemnts also
  multiset<int>ms;
  ms.insert(1); //{1}
  ms.insert(1); //{1,1}
  ms.insert(1); //{1,1,1}

  ms.erase(1); //All 1's erased
  
  int cnt=ms.count(1);

  //Only single one erased
  ms.erase(ms.find(1));

  //rest all functions are same as set
}



//Unordered Set
void cpp_unordered_set()
{
  unordered_set<int> st;
  //All functions are same but only stores unique element not sorted order
}



//Map
void cpp_map()
{
  //In form of (keys,values) where keys are always unique in sorted order but values can be duplicate 
  map<int,int> mpp;
  map<int,pair<int,int>>mpp;
  map<pair<int,int>,int>mpp;

  mpp[1]=2;
  mpp.emplace(3,1);
  mpp.insert({2,4});
  // mpp[{2, 3}] = 10; 

  for(auto it: mpp)
  {
    cout<<it.first<<" "<<it.second<<endl;
  }

  cout<<mpp[1]; //2
  cout<<mpp[5]; //NULL or 0

  // auto it=mpp.find(3);
  // cout<<*it.second; //1

  auto it=mpp.find(5); //mpp.end()

}



//MultiMap
void cpp_multimap(){
  //everything same as map,only it can store multiple keys
  //only mpp[key] cannot be used here
}


//Unordered Map
void cpp_unorderedmap(){
  //have unique keys but not in sorted form
}



int main()
{
    // cpp_pairs();
    //cpp_vectors();
    //cpp_list();
    //cpp_deque();
    //cpp_stack();
    //cpp_queue();
    //cpp_priorityqueue();
    //cpp_set();
    //cpp_multiset();
    //cpp_unordered_set;
    //cpp_map();
    //cpp_multimap();
    //cpp_unorderedmap();
    return 0;
}

