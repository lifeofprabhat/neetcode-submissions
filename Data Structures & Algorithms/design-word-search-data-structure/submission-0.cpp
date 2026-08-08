class WordDictionary {
public:

    struct Node{
        bool eow;
        Node* child[26];
        Node(){
            eow = false;
            for(int i=0;i<26;i++)
               child[i] = NULL;
        }
    };

    Node* root = NULL;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* tmp = root;
        for(char c : word){
            if(!tmp->child[c-'a'])
              tmp->child[c-'a'] = new Node();

            tmp = tmp->child[c-'a']; 
        }
        tmp->eow = true;
    }
    bool recurSearch(Node* tmp, string remStr){
          if(!tmp) return false;

          if(remStr.size() == 0)
             return tmp->eow;

         
            if(remStr[0] == '.'){
                for(int i =0;i<26;i++){
                    if(tmp->child[i] && recurSearch(tmp->child[i], remStr.substr(1)))
                    return true;
                }
                return false;
            }
            
         char c = 'a' + (remStr[0]-'a');
         if(!tmp->child[c-'a'])
           return false;
              
          

       return recurSearch(tmp->child[c-'a'], remStr.substr(1));
    }
    bool search(string word) {

        Node* tmp = root;
        return recurSearch(root, word);
        
    }
};
