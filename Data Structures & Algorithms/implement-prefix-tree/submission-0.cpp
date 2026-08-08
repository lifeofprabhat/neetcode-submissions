class PrefixTree {
public:
   
    struct Node{
        Node* child[26];
        bool eow;
        Node(){
            eow = false;
            for(int i=0;i<26;i++)
               child[i] = NULL;
        }
    };

    Node* root;
    PrefixTree() {

        root = new Node();
        
    }
    
    void insert(string word) {
 
    Node* tmp = root;
    for(char c : word){
        if(tmp->child[c -'a'] == nullptr)
           tmp->child[c-'a'] = new Node();

        tmp = tmp->child[c-'a'];
    }
     
     tmp->eow = true;
        
    }
    
    bool search(string word) {

    Node* tmp = root;
    for(char c : word){
        if(tmp->child[c -'a'] == nullptr)
           return false;

        tmp = tmp->child[c-'a'];
    }

    return tmp->eow;
        
    }
    
    bool startsWith(string word) {
      Node* tmp = root;
    for(char c : word){
        if(tmp->child[c -'a'] == nullptr)
           return false;

         tmp = tmp->child[c-'a'];
    }

    return true;    
    }
};
