class Solution {
    public:
      stack<int> st;
      int mini;
      Solution() {
          // code here
          mini = INT_MAX;
      }
  
      // Add an element to the top of Stack
      void push(int x) {
          // code here
          if(st.empty())
              mini = x;
          else{
              if(x <= mini){
                  st.push(mini);
                  mini = x;
              }
          }
          st.push(x);
      }
  
      // Remove the top element from the Stack
      void pop() {
          // code here
          if(!st.empty()){
              int temp = st.top();
              st.pop();
              if(mini == temp && !st.empty()){
                  mini = st.top();
                  st.pop();
              }
          }
      }
  
      // Returns top element of the Stack
      int peek() {
          // code here
          if(st.empty())
              return -1;
          return st.top();
      }
  
      // Finds minimum element of Stack
      int getMin() {
          // code here
          if(st.empty())
              return -1;
          return mini;
      }
  };
  