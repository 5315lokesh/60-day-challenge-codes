#include<algorithm>
bool isafetoput(int board[9][9],int i,int j,int n,int no){
    //1.cheeck for row and column
    for(int k=0;k<n;k++){
        if(board[i][k]==no || board[k][j]==no){
            return false;
        }
    }
    //2. check for box
    n=sqrt(n);
    int si=(i/n)*n;
    int sj=(j/n)*n;
    
    for(int k=si;k<si+n;k++){
        for(int l=sj;l<sj+n;l++){
            if(board[k][l]==no){
                return false;
            }
        }
    }
    return true;
    
}
bool sudukosolver(int matrix[9][9],int i,int j,int n){
    //base case
    if(i==n){
        //suduko is solved print it
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        */
        return true;
    }
    //recursive case
    if(j==n){
        return sudukosolver(matrix,i+1,0,n);
    }
    if(matrix[i][j]!=0){
        return sudukosolver(matrix,i,j+1,n);
    }
    
    for(int number=1;number<=n;number++){
        if(isafetoput(matrix,i,j,n,number)){
            //if it is safe to put the number then place it
            matrix[i][j]=number;
            
            //and ask the revision to solve the remaining suduko
            bool bakisolvehua=sudukosolver(matrix,i,j+1,n);
            if(bakisolvehua){
                return true;
            }
            matrix[i][j]=0;
        }
    }
    return false;
}
bool isItSudoku(int matrix[9][9]) {
    
       sudukosolver(matrix,0,0,9);
 
}
