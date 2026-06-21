class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indeg(numCourses,0);
        for(auto p:prerequisites){
            int course=p[0];
            int prereq=p[1];
            adj[course].push_back(prereq);
            indeg[prereq]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            count++;

            for(int neigh:adj[curr]){
                indeg[neigh]--;
                if(indeg[neigh]==0){
                    q.push(neigh);
                }
            }


        }
        return count==numCourses;
    }
};
