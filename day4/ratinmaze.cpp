class Solution{
    public:
    bool issafe(int newx,int newy,vector<vector<bool>>&visited,vector<vector<int>>&m, int n){
        if((newx>=0 and newx<n) and (newy>=0 and newy<n) and visited[newx][newy]!=1 and m[newx][newy]==1)
        {
            return true;
        }
        else{
            return false;
        }
    }
    void solve(int x,int y,vector<vector<int>> &m,int n, vector<string>&ans,vector<vector<bool>>&visited,string path){
        //base case
        
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        
        // 4 movement==>d,l,r,u
        //down movement
        visited[x][y]=1;
        if(issafe(x+1,y,visited,m,n)){
            //visited[x][y]=1;
            solve(x+1,y,m,n,ans,visited,path+'D');
            //visited[x][y]=0;
            
        }
        //left movement
        if(issafe(x,y-1,visited,m,n)){
            //visited[x][y]=1;
            solve(x,y-1,m,n,ans,visited,path+'L');
            //visited[x][y]=0;
        }
        //right movement
        if(issafe(x,y+1,visited,m,n)){
            //visited[x][y]=1;
            solve(x,y+1,m,n,ans,visited,path+'R');
            //visited[x][y]=0;
        }
        //up movement
        if(issafe(x-1,y,visited,m,n)){
            //visited[x][y]=1;
            solve(x-1,y,m,n,ans,visited,path+'U');
            //visited[x][y]=0;
        }
        
        visited[x][y]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        // answer store karne ke liye
        vector<string>ans;
        //ye 2 d array visited naam ka , ye dtore karega ki (i,j)th element visited h ya nahi
        vector<vector<bool>>visited(n, vector<bool>(n,0));
        
        string path="";
        //edge case
        if(m[0][0]==0){
            return ans;
        }
        
        solve(0,0,m,n,ans,visited,path);
        return ans;
        
    }
};
