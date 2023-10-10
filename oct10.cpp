
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
 Node * Traveral (Node* root, int target ,map<Node *,Node*> &parent){
         queue<Node*> q;
         Node* res;
         q.push(root);
         while(!q.empty()){
             Node* ram =q.front();
             q.pop();
             if(ram->data == target) res = ram;
             if(ram->left){
                 parent[ram->left] = ram;
                 q.push(ram->left);
             }
             if(ram->right){
                 parent[ram->right] = ram;
                 q.push(ram->right);
             }
         }
         return res;
     }

public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
         map<Node *,Node*> parent;
        Node * res = Traveral(root,target,parent);
        
         queue<Node*> q;
          map<Node *,int> visited;
          q.push(res);
         visited[res] = 1;
         int t = 0;
           while(!q.empty()){
              int flag = 0;
              int size = q.size();
              for(int i = 0; i < size; i++){
                  Node *front = q.front();
                  q.pop();
                  if(front -> left && !visited[front -> left]){
                      flag = 1;
                      q.push(front -> left);
                      visited[front -> left] = 1;
                  }
                  if(front -> right && !visited[front -> right]){
                      flag = 1;
                      q.push(front -> right);
                      visited[front -> right] = 1;
                  }
                  if(parent[front] && !visited[parent[front]]){
                      flag = 1;
                      q.push(parent[front]);
                      visited[parent[front]] = 1;
                  }
              }
              if(flag == 1)
                  t++;
              if(t == k) break;      
         }
         
        vector<int> result;
        while(!q.empty())
        {
            Node* curr = q.front();
            q.pop();
            result.push_back(curr->data);
        }
        sort(result.begin(),result.end());
        return result;
    }
};