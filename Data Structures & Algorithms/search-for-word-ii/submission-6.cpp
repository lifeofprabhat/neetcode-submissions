class Solution {
public:

  struct Node{
    string wd;
    bool eow;
    Node* child[26];

    Node(){
        wd = "";
        eow = 0;
        for(int i=0;i<26;i++)
         child[i] = NULL;
    }

  };

  Node* root = nullptr; 

  void insert(string word){
     Node* tmp = root;
     for(char c: word){
        if(!tmp->child[c-'a'])
           tmp->child[c-'a'] = new Node();

        tmp = tmp->child[c-'a'];
     }
     tmp->wd = word;
     tmp->eow = 1;
  }
  
  vector<vector<bool>>vis;
  int dx[4] = {0,0,1,-1};
  int dy[4] = {1,-1,0,0};
  int n, m;

  void dfs(vector<vector<char>>& board,int x, int y, Node* ptr, vector<string>& ans)
  {
 
     char c = board[x][y];
     if(!ptr->child[c-'a']) 
        return;

     vis[x][y] = 1;

    
  ptr = ptr->child[c-'a'];
  if(ptr->eow){
    ans.push_back(ptr->wd);
    ptr->eow = 0;
  }
     
  for(int i=0;i<4;i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny]){
        dfs(board,nx,ny,ptr,ans);
      }
    }
     

    vis[x][y] = 0;

  }
  
 
  
  
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

    root = new Node();

    for(string word : words)
      insert(word);


     n = board.size();
     m = board[0].size();
    vector<string> ans;
    vis.resize(n, vector<bool>(m,0));

    for(int i =0;i<n;i++)
      for(int j=0;j<m;j++){
        dfs(board,i,j,root,ans);
      }
 
    return ans;

    }
};
