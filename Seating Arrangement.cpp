class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &seats) {
        // code here
        int n = seats.size();
        seats.push_back(0);
        for(int i=0; i<n; i++){
            if(seats[i] == 0) {
                if(seats[i+1] == 0){
                    seats[i] = 1;
                    k--;
                    i++;
                }
            }
            else {
                if(seats[i+1] == 0)
                    i++;
                else
                    return false;
            }
        }
        return k <= 0;
    }
};