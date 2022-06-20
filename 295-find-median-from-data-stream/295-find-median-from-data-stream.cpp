class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>, greater<int>> min_heap;
    vector<int> ds;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
       
        if(ds.size()==0){ // first time
            ds.push_back(num);
             max_heap.push(num);
            return;
        }
        else{
            
            double med=findMedian(); 
          //  cout<<med;
            if(num<=med){
    
            if(max_heap.size()>min_heap.size()){
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }
            else if(max_heap.size()<=min_heap.size()){
                max_heap.push(num);
            }
           
            
                
            }
            
            
            else if(num>med){
                
             if(max_heap.size()<min_heap.size()){
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
            }
            else if(max_heap.size()>=min_heap.size()){
                cout<<"hey there";
                min_heap.push(num);
            } 
                
                
            }
            
            
        }
        
      
        
        
        
        
    }
    
    double findMedian() {
        
        if(max_heap.size()==1 && min_heap.size()==0) // max_heap has 1 element
            return (double)max_heap.top();
         
        
        if(min_heap.size()==max_heap.size()){
           double first=min_heap.top();
            double second=max_heap.top();
            return (first+second)/2;
        }
        if(max_heap.size()>min_heap.size()){ // left has the median at top
            return max_heap.top();
            
        }
   //     if(max_heap.size()<min_heap.size()){
            return min_heap.top();
     //   }
        
            
        
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */