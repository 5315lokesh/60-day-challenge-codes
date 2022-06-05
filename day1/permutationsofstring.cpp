void solve(vector<string>&ans , string &s, int i){
    //base case
    if(s[i]=='\0'){
        ans.push_back(s);
        return;
    }
    //recursive case
    for(int j=i;s[j]!='\0';j++){
        swap(s[i],s[j]);
        solve(ans,s,i+1);
        swap(s[i],s[j]);
    }
    
}
vector<string> findPermutations(string &s) {
    vector<string> ans;
    int i=0;
    
    solve(ans,s,i);
    return ans;
}
