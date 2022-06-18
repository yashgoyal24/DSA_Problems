class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // BELLMAN FORD ALGORITHM
	    
	    vector<int> distance(n+1,1000000);
        distance[0]=0;
	    distance[k]=0;
	    
	    for(int i=1;i<=n-1;i++){
	        
	        // relax all edges for (n-1) times
	        
	        for(auto it:times){
	            
	            if(distance[it[0]]+it[2]<distance[it[1]]){
	                // relax karenge
	                
	               distance[it[1]]= distance[it[0]]+it[2];
	                
	            }
	            
	        }
	        
	        
	    }
	 
	    // traverse in distance matrix
        
        int maxi=-1;
        for(auto it:distance){
        
            if(it==1000000)
                return -1;
            maxi=max(maxi,it);
            
        }
	    
	  return maxi;
        
        
        
        
    }
};