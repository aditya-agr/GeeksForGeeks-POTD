class Solution {
  public:
    double maxVolume(double perimeter, double area) {
        // code here/
        double l = (perimeter - sqrt(pow(perimeter,2) - 24*area))/12;
        double maxV = l*l*(perimeter/4 - 2*l);
        return maxV;
    }
};