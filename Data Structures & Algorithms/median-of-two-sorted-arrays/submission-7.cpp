class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        int left_size =  n/2;

        int index1 = 0;
        int index2 = 0;

        vector<int> left;
        vector<int> right;

        while(left.size() < left_size){
            if(index1 < nums1.size() &&
            (index2 >= nums2.size() || nums1[index1] < nums2[index2])){
                left.push_back(nums1[index1]);
                index1++;
            } else{
                left.push_back(nums2[index2]);
                index2++;
            }
        }

        while(index1 < nums1.size() || index2 < nums2.size()){
             if (index1 < nums1.size() &&
                (index2 >= nums2.size() || nums1[index1] < nums2[index2])){
                right.push_back(nums1[index1]);
                index1++;
            } else{
                right.push_back(nums2[index2]);
                index2++;
            }
        }

        double median;

        if(left.size() == right.size()) return (left[left.size() - 1] + right[0]) / 2.0;
        else return median = right[0];
    }
};
