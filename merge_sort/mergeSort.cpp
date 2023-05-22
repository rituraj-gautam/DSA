class Solution {
public:


    void merge(vector<int>& arr, int s,int mid,int e)
    {
        int len1=mid-s+1;
        int len2=e-mid;

        int arr1[len1],arr2[len2];

        int originalarrayindex=s;

        for(int i=0;i<len1;i++)
        {
            arr1[i]=arr[originalarrayindex++];

        }


        originalarrayindex=mid+1;

        for(int i=0;i<len2;i++)
        {
            arr2[i]=arr[originalarrayindex++];

        }




        originalarrayindex=s;



        int i=0;
        int j=0;



        while(i<len1 && j<len2)
        {
            
            
            if(arr1[i]<arr2[j])
            {
                arr[originalarrayindex++]=arr1[i++];
            }
            else
            {
                arr[originalarrayindex++]=arr2[j++];
            }
            
        }

        while(i<len1)
        {
            arr[originalarrayindex++]=arr1[i++];
        }

        while(j<len2)
        {
            arr[originalarrayindex++]=arr2[j++];
        }
        


    }


    void mergesort(vector<int>& arr,int s,int e)
    {
        
        int size = (e-s)+1;

      //base case
        if( s>=e )
        {
            return;
        }

      
      
        int mid=(e+s)/2;

        mergesort(arr,s,mid);
        mergesort(arr,mid+1,e);
        

        merge(arr,s,mid,e);
    }



    vector<int> sortArray(vector<int>& nums) {
        

        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};
