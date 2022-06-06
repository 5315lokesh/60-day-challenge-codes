bool placekarnasafehai(vector<vector<int>>board,int i,int j,int n){
    //check for rows and columns
    for(int k=0;k<n;k++){
        if(board[i][k] || board[k][j]){
            return false;
        }
    }
    //checking right diagonal
    int x=i,y=j;
    //kho jayenge agar store nahi karenge to
    while(i>=0 and j<n){
        if(board[i--][j++]){
            return false;
        }
    }
    //checking left diagonal
    i=x,j=y;
    while(i>=0 and j>=0){
        if(board[i][j]){
            return false;
        }
        i--;
        j--;
    }
    return true;
}
bool nqueen(vector<vector<int>>&ans,vector<vector<int>>&board,int i,int n){
    //base case
    vector<int>temp;
    if(i==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
              temp.push_back(board[i][j]);
            } // j wale ka loop
            //cout<<endl; kar deta agar next line me print karna hotq
        }// i wale ka loop
        ans.push_back(temp);
        return false;
    }
    //recursive case
    for(int j=0;j<n;j++){
        if(placekarnasafehai(board,i,j,n)==true){
            //if place karna safe hai than place the queen
            board[i][j]=1;
            bool kyabakibaatbani=nqueen(ans,board,i+1,n);
            if(kyabakibaatbani==true){
                return true;
            }
            // if baatnahi bani, toh (i,j) se queen hatao and next cell parrakh             //kar dekho
            //backtracking
            board[i][j]=0;
        }
    }
    return false;
}
vector<vector<int>> solveNQueens(int n) {
    //hamne ek board create kara h usko hmne initialize kara h
    //hamne ek 2 d vector craete kara h 2 d board store karne ke liye
    vector<vector<int>>board(n, vector<int>(n,0));
    //ek 2d vector ans store karne ke liye
    vector<vector<int>>ans;
    nqueen(ans,board,0,n);
    return ans;
}
